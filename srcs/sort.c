/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:36:13 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/05 13:01:22 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	t_stack	*tmp;
	int		max;

	max = max_value(*a);
	while (a)
	{
		tmp = ft_stacklast(*a);
		if (tmp->data == max)
			swap(a, 'a');
		if ((*a)->next->data == max)
			rev_rot(a, 'a');
		if ((*a)->data == max)
			rotate(a, 'a');
		if (!check_sort(*a))
			break ;
	}
	return ;
}

void	bring_target_top(t_stack **a, t_stack **b, t_stack *target, int c)
{
	if (c == 'a')
		while (*a != target)
		{
			if (above_median(*a, target->data))
				rotate(a, 'a');
			else
				rev_rot(a, 'a');
		}
	else if (c == 'b')
		while (*b != target)
		{
			if (above_median(*b, target->data))
				rotate(b, 'b');
			else
				rev_rot(b, 'b');
		}
}

void	final_sort(t_stack **a)
{
	int		min;

	min = min_value(*a);
	if (above_median(*a, min))
		while (check_sort(*a))
			rotate(a, 'a');
	else
		while (check_sort(*a))
			rev_rot(a, 'a');
}

void	sort_push_b(t_stack **a, t_stack **b)
{
	t_stack	*topush;

	push(b, a, 'b');
	push(b, a, 'b');
	while (*a != NULL)
	{
		target_init(a, b);
		topush = cost_analysis(a, b);
		bring_target_top(a, b, topush, 'a');
		bring_target_top(a, b, topush->target, 'b');
		push(b, a, 'b');
	}
	while (*b != NULL)
		push(a, b, 'a');
	final_sort(a);
}

void	sort(t_stack **a, t_stack **b)
{
	if (ft_stacksize(*a) == 3)
	{
		sort_3(a);
		return ;
	}
	if (ft_stacksize(*a) == 4)
	{
		push(b, a, 'b');
		if (check_sort(*a))
			sort_3(a);
		target_init_rev(b, a);
		while (*a != (*b)->target)
		{
			if (above_median(*a, (*b)->target->data))
				rotate(a, 'a');
			else
				rev_rot(a, 'a');
		}
		push(a, b, 'a');
		while (check_sort(*a))
			rotate(a, 'a');
	}
	else
		sort_push_b(a, b);
}
