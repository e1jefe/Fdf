/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:14:21 by dsheptun          #+#    #+#             */
/*   Updated: 2017/12/15 09:55:03 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	temp[n];

	i = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	while (i < n)
	{
		temp[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		s2[i] = temp[i];
		i++;
	}
	return (dest);
}
