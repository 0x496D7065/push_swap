/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:28 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/09 10:51:13 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>

long	ft_atoi(char const *nptr)
{
	int				sign;
	unsigned long	nbr;

	sign = 0;
	nbr = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			sign++;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		nbr = (nbr * 10) + (*nptr - 48);
		nptr++;
		if (nbr > LLONG_MAX && ((sign % 2) == 0))
			return (-1);
		if (nbr > LLONG_MAX && ((sign % 2) > 0))
			return (0);
	}
	if ((sign % 2) > 0)
		nbr = -nbr;
	return (nbr);
}
