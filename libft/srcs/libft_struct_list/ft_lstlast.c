/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:11:07 by ppaquet           #+#    #+#             */
/*   Updated: 2023/02/27 15:11:09 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p_lst;

	if (!lst)
		return (NULL);
	p_lst = lst;
	while ((*p_lst).next != NULL)
		p_lst = (*p_lst).next;
	return (p_lst);
}
