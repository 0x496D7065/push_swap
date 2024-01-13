/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:36:13 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/13 17:41:20 by lpetit           ###   ########.fr       */
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

void	bring_target_top(t_stack **stack, t_stack *target, int c)
{
	while (*stack != target)
	{
		if (c == 'a')
		{
			if (above_median(*stack, target->data))
				rotate(stack, 'a');
			else
				rev_rot(stack, 'a');
		}
		else if (c == 'b')
		{
			if (above_median(*stack, target->data))
				rotate(stack, 'b');
			else
				rev_rot(stack, 'b');
		}
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

void	sort_push(t_stack **st1, t_stack **st2, int src, int dest)
{
	t_stack	*topush;

	if (*st2 != NULL)
	{
		topush = cost_analysis(st1, st2);
		bring_target_top(st1, topush, src);
		bring_target_top(st2, topush->target, dest);
	}
	push(st2, st1, dest);
}

void	sort(t_stack **a, t_stack **b)
{
	if (ft_stacksize(*a) == 2)
	{
		swap(a, 'a');
		return ;
	}
	while (ft_stacksize(*a) != 3)
	{
		target_reset(a);
		target_init(a, b);
		sort_push(a, b, 'a', 'b');
	}
	if (check_sort(*a))
		sort_3(a);
	while (*b != NULL)
	{
		target_reset(b);
		target_init_rev(b, a);
		sort_push(b, a, 'b', 'a');
	}
	if (check_sort(*a))
		final_sort(a);
}
