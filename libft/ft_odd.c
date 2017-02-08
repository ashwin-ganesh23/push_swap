/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_odd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganesh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:36:36 by aganesh           #+#    #+#             */
/*   Updated: 2016/10/10 13:36:39 by aganesh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_odd(char *str)
{
	int		i;
	char	*s;

	i = 0;
	s = str;
	while (*s)
	{
		if (i % 2 == 0)
			ft_putchar(*s);
		s++;
	}
}
