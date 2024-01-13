/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:01:55 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/13 17:40:28 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_reset(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!tmp)
		return ;
	while (tmp != NULL)
	{
		tmp->target = NULL;
		tmp = tmp->next;
	}
}

void	assign_max(t_stack **node, t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	max = max_value(*stack);
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->data == max)
			(*node)->target = tmp;
		tmp = tmp->next;
	}
}

void	assign_min(t_stack **node, t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	min = min_value(*stack);
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->data == min)
			(*node)->target = tmp;
		tmp = tmp->next;
	}
}

void	target_init_rev(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	long	tmpdiff;

	tmpa = *a;
	while (tmpa != NULL)
	{
		tmpb = *b;
		tmpdiff = LONG_MAX;
		while (tmpb != NULL)
		{
			if (tmpb->data > tmpa->data && tmpb->data < tmpdiff)
			{
				tmpdiff = tmpb->data;
				tmpa->target = tmpb;
			}
			tmpb = tmpb->next;
		}
		if (!tmpa->target)
			assign_min(&tmpa, b);
		tmpa = tmpa->next;
	}
}

void	target_init(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	long	tmpdiff;

	if (*b == NULL)
		return ;
	tmpa = *a;
	while (tmpa != NULL)
	{
		tmpb = *b;
		tmpdiff = LONG_MIN;
		while (tmpb != NULL)
		{
			if (tmpb->data < tmpa->data && tmpb->data > tmpdiff)
			{
				tmpdiff = tmpb->data;
				tmpa->target = tmpb;
			}
			tmpb = tmpb->next;
		}
		if (!tmpa->target)
			assign_max(&tmpa, b);
		tmpa = tmpa->next;
	}
}
