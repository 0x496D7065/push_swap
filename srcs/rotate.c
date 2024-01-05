/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:11 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/04 13:43:33 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, int c)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || ft_stacksize(*stack) == 1)
		return ;
	last = ft_stacklast(*stack);
	tmp = (*stack);
	(*stack) = (*stack)->next;
	last->next = tmp;
	tmp->next = NULL;
	if (c == 'a')
		ft_printf("%s\n", "ra");
	if (c == 'b')
		ft_printf("%s\n", "rb");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'r');
	rotate(b, 'r');
	ft_printf("%s\n", "rr");
}

void	rev_rot(t_stack **stack, int c)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || ft_stacksize(*stack) == 1)
		return ;
	last = ft_stacklast(*stack);
	tmp = (*stack);
	while (tmp->next != last)
		tmp = tmp->next;
	last->next = (*stack);
	(*stack) = last;
	tmp->next = NULL;
	if (c == 'a')
		ft_printf("%s\n", "rra");
	if (c == 'b')
		ft_printf("%s\n", "rrb");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rot(a, 'r');
	rev_rot(b, 'r');
	ft_printf("%s\n", "rrr");
}
