/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:41:12 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/09 20:06:45 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_dest, t_stack **stack_src, int c)
{
	t_stack	*tmp;

	if (!*stack_src)
		return ;
	if (!*stack_dest)
		*stack_dest = NULL;
	tmp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = (*stack_src);
	*stack_src = tmp;
	if (c == 'a')
		ft_printf("%s\n", "push a");
	if (c == 'b')
		ft_printf("%s\n", "push b");
}
