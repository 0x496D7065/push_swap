/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:11:46 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/05 12:45:25 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

# define ERR_NOT_INT "Argument is not an int\n"
# define ERR_DUP "There are duplicate\n"
# define ERR_INT_MAX "Argument value is not within an int\n"
# define ERR_MALLOC "Error when allocating memory for the stack\n"

typedef struct s_stack
{
	int				data;
	int				cost;
	struct s_stack	*next;
	struct s_stack	*target;
}		t_stack;

void	exit_msg(char *msg);
void	ft_free_tab(char **tab);
void	ft_stackclear(t_stack **stack);
void	sort_3(t_stack **a);
void	sort(t_stack **a, t_stack **b);
void	target_init(t_stack **a, t_stack **b);
void	target_init_rev(t_stack **a, t_stack **b);

void	swap(t_stack **stack, int c);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **stack_dest, t_stack **stack_src, int c);
void	rotate(t_stack **stack, int c);
void	rev_rot(t_stack **stack, int c);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		ft_stacksize(t_stack *stack);
int		string_init(char **tab);
int		check_sort(t_stack *stack);
int		above_median(t_stack *a, int value);
int		max_value(t_stack *a);
int		min_value(t_stack *a);

t_stack	*cost_analysis(t_stack **a, t_stack **b);
t_stack	*ft_stacknew(int data);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_create_stack_str(int argc, char **tab);

#endif
