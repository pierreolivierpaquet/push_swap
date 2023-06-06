/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:07:25 by ppaquet           #+#    #+#             */
/*   Updated: 2023/02/13 12:07:27 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr_s;

	if (!s)
		return ;
	i = 0;
	ptr_s = s;
	if (n == 0)
		return ;
	while (i < n)
		ptr_s[i++] = 0;
}
