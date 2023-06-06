/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:11:26 by ppaquet           #+#    #+#             */
/*   Updated: 2023/02/27 15:11:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p_last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p_last = ft_lstlast(*lst);
	(*p_last).next = new;
	return ;
}
