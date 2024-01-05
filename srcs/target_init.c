/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:01:55 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/04 13:35:14 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_max(t_stack *node, t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	max = max_value(*stack);
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->data == max)
			node->target = tmp;
		tmp = tmp->next;
	}
}

void	assign_min(t_stack *node, t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	max = min_value(*stack);
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->data == max)
			node->target = tmp;
		tmp = tmp->next;
	}
}

void	target_init_rev(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		diff;
	int		tmpdiff;

	tmpa = *a;
	while (tmpa != NULL)
	{
		tmpb = *b;
		tmpdiff = -2147483648;
		while (tmpb != NULL)
		{
			diff = tmpa->data - tmpb->data;
			if (diff < 0 && diff >= tmpdiff)
			{
				tmpdiff = diff;
				tmpa->target = tmpb;
			}
			tmpb = tmpb->next;
		}
		if (!tmpa->target)
			assign_min(tmpa, b);
		tmpa = tmpa->next;
	}
}

void	target_init(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		diff;
	int		tmpdiff;

	tmpa = *a;
	while (tmpa != NULL)
	{
		tmpb = *b;
		tmpdiff = 2147483647;
		while (tmpb != NULL)
		{
			diff = tmpa->data - tmpb->data;
			if (diff > 0 && diff <= tmpdiff)
			{
				tmpdiff = diff;
				tmpa->target = tmpb;
			}
			tmpb = tmpb->next;
		}
		if (!tmpa->target)
			assign_max(tmpa, b);
		tmpa = tmpa->next;
	}
}
