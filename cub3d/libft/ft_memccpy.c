/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:41:44 by hkheired          #+#    #+#             */
/*   Updated: 2025/01/16 08:41:45 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	while (n > 0)
	{
		*pdest = *psrc;
		if (*psrc == (unsigned char)c)
			return ((void *)pdest);
		pdest++;
		psrc++;
		n--;
	}
	return (NULL);
}
