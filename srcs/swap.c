/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:37:48 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/04 09:01:43 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int c)
{
	int	tmp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	if (c == 'a')
		ft_printf("%s\n", "sa");
	if (c == 'b')
		ft_printf("%s\n", "sb");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, 's');
	swap(b, 's');
	ft_printf("%s\n", "ss");
}
