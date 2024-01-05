/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:11:19 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/04 13:22:46 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_arg_digit(char **argv)
{
	size_t	i;
	size_t	n;

	i = 1;
	while (argv[i])
	{
		n = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			n = 1;
		while (argv[i][n])
		{
			if (!ft_isdigit(argv[i][n]))
				exit_msg("Error\n");
			n++;
		}
		i++;
	}
}

void	arg_check(int argc, char **argv)
{
	int		i;
	int		dup;

	i = 1;
	is_arg_digit(argv);
	while (i < argc)
	{
		dup = 1;
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			exit_msg("Error\n");
		while (argv[i + dup])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[i + dup]))
				exit_msg("Error\n");
			dup++;
		}
		i++;
	}
	return ;
}

t_stack	*ft_create_stack(int argc, char **argv)
{
	t_stack	*tmp;
	t_stack	*a;
	int		i;

	i = 1;
	a = ft_stacknew(ft_atoi(argv[i]));
	if (!a)
		exit_msg("Error\n");
	tmp = a;
	i++;
	while (i < argc)
	{
		a->next = ft_stacknew(ft_atoi(argv[i]));
		if (!a->next)
			ft_stackclear(&tmp);
		a = a->next;
		i++;
	}
	return (tmp);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->data);
		//ft_printf("cost = %d\n", tmp->cost);
		//if (tmp->target != NULL)
			//ft_printf("target = %d\n", tmp->target->data);
		//ft_printf("%s\n", "-------------------");
		tmp = tmp->next;
	}
	ft_stackclear(&stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	char	**tab;
	int	split_count;

	if (argc >= 2)
	{
		b = NULL;
		if (argc == 2)
		{
			tab = ft_split(argv[1], ' ');
			split_count = string_init(tab);
			a = ft_create_stack_str(split_count, tab);
			ft_free_tab(tab);
		}	
		else if (argc > 2)
		{
			arg_check(argc, argv);
			a = ft_create_stack(argc, argv);
		}
		if (check_sort(a))
			sort(&a, &b);
		ft_printf("%s\n", "stack a");
		print_stack(a);
		ft_printf("%s\n", "stack b");
		print_stack(b);
		return (0);
	}
	return (0);
}
