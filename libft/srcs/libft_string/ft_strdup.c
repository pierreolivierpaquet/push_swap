/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:14:57 by ppaquet           #+#    #+#             */
/*   Updated: 2023/02/13 12:14:58 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copie;
	size_t	l;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1) + 1;
	copie = (char *)malloc(l * sizeof(*copie));
	if (copie == NULL)
		return (NULL);
	else
		ft_memcpy(copie, s1, l);
	return (copie);
}
