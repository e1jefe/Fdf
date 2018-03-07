/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:02:48 by dsheptun          #+#    #+#             */
/*   Updated: 2017/12/15 09:45:42 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *s)
{
	int	semn;
	int	rez;
	int	i;

	semn = 1;
	rez = 0;
	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-')
	{
		semn = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		rez = rez * 10 + (s[i] - '0');
		i++;
	}
	return (rez * semn);
}
