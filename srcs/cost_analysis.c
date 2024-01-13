/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:15:26 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/11 13:38:29 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cost(t_stack *stack, int value)
{
	int		cost;
	t_stack	*tmp;

	cost = 0;
	tmp = stack;
	while (stack != NULL)
	{
		if (stack->data == value)
		{
			if (above_median(tmp, value))
				return (cost);
			else
				return (ft_stacksize(tmp) - cost);
		}
		cost++;
		stack = stack->next;
	}
	return (0);
}

void	setup_cost(t_stack **a, t_stack **b)
{
	int		cost_a;
	int		cost_b;
	t_stack	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		cost_a = find_cost (*a, tmp->data);
		cost_b = find_cost (*b, tmp->target->data);
		tmp->cost = cost_a + cost_b;
		tmp = tmp->next;
	}
}

t_stack	*cost_analysis(t_stack **a, t_stack **b)
{
	int		cost;
	t_stack	*tmp;
	t_stack	*ret;

	setup_cost(a, b);
	tmp = *a;
	cost = (*a)->cost;
	ret = *a;
	while (tmp != NULL)
	{
		if (cost > tmp->cost)
		{
			cost = tmp->cost;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}
