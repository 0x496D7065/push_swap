/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:41:33 by lpetit            #+#    #+#             */
/*   Updated: 2024/02/06 13:41:08 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_str_valid(char **tab)
{
	size_t	i;
	size_t	n;

	i = 0;
	while (tab[i])
	{
		n = 0;
		if (tab[i][0] == '-' || tab[i][0] == '+')
			n = 1;
		if (!tab[i][n])
		{
			ft_free_tab(tab);
			exit_msg("Error\n");
		}
		while (tab[i][n])
		{
			if (!ft_isdigit(tab[i][n]))
			{
				ft_free_tab(tab);
				exit_msg("Error\n");
			}
			n++;
		}
		i++;
	}
}

void	str_check_int_max(int argc, char **tab)
{
	int		i;

	i = 0;
	is_str_valid(tab);
	while (i < argc)
	{
		if (ft_atoi(tab[i]) > INT_MAX || ft_atoi(tab[i]) < INT_MIN || 
			ft_strlen(tab[i]) >= 18)
		{
			ft_free_tab(tab);
			exit_msg("Error\n");
		}
		i++;
	}
	return ;
}

void	str_check_for_dup(int argc, char **tab)
{
	int	dup;
	int	i;

	i = 0;
	while (i < argc)
	{
		dup = 1;
		while (tab[i + dup])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[i + dup]))
			{
				ft_free_tab(tab);
				exit_msg("Error\n");
			}
			dup++;
		}
		i++;
	}
}

t_stack	*ft_create_stack_str(int argc, char **tab)
{
	t_stack	*tmp;
	t_stack	*a;
	int		i;

	i = 0;
	a = ft_stacknew(ft_atoi(tab[i]));
	if (!a)
	{
		ft_free_tab(tab);
		exit_msg("Error\n");
	}
	tmp = a;
	i++;
	while (i < argc)
	{
		a->next = ft_stacknew(ft_atoi(tab[i]));
		if (!a->next)
		{
			ft_free_tab(tab);
			ft_stackclear(&tmp);
		}
		a = a->next;
		i++;
	}
	return (tmp);
}

t_stack	*string_init(char *str)
{
	char	**tab;
	t_stack	*stack;
	int		i;

	i = 0;
	tab = ft_split(str, ' ');
	if (!tab)
		exit(1);
	while (tab[i])
		i++;
	if (i == 0)
	{
		ft_free_tab(tab);
		exit(0);
	}
	str_check_int_max(i, tab);
	str_check_for_dup(i, tab);
	stack = ft_create_stack_str(i, tab);
	ft_free_tab(tab);
	return (stack);
}
