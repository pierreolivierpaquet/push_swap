/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:13:05 by ppaquet           #+#    #+#             */
/*   Updated: 2023/02/27 15:13:06 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p_lst;

	if (!lst)
		return ;
	while (lst != NULL)
	{
		p_lst = (*lst).next;
		(f)((*lst).content);
		lst = p_lst;
	}
	return ;
}
