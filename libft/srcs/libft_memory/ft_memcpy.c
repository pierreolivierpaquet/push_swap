/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:08:16 by ppaquet           #+#    #+#             */
/*   Updated: 2023/02/13 12:08:18 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (!src && !dst)
		return (NULL);
	i = 0;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
