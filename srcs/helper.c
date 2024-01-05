/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:55:56 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/04 13:34:42 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	max_value(t_stack *a)
{
	int	tmp;

	tmp = 0;
	while (a)
	{
		if (tmp < a->data)
			tmp = a->data;
		a = a->next;
	}
	return (tmp);
}

int	min_value(t_stack *a)
{
	int	tmp;

	tmp = 0;
	while (a)
	{
		if (tmp > a->data)
			tmp = a->data;
		a = a->next;
	}
	return (tmp);
}

int	above_median(t_stack *a, int value)
{
	int		median;
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	median = ft_stacksize(a) / 2;
	while (tmp != NULL && i <= median)
	{
		if (tmp->data == value)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
