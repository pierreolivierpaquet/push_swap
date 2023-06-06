/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:12:16 by ppaquet           #+#    #+#             */
/*   Updated: 2023/02/27 15:12:18 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p_next_lst;

	if (!*lst || !lst)
		return ;
	while (*lst != NULL)
	{
		p_next_lst = (**lst).next;
		ft_lstdelone(*lst, del);
		*lst = p_next_lst;
	}
	*lst = NULL;
	return ;
}
