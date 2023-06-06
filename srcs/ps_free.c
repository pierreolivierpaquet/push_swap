/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:09:23 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/03 10:09:25 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Frees memory for each character string pointed to in the tab,
 * assigns NULL value to each tab index, and returns 'tab' (NULL).
 */
char	**ps_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (tab == NULL)
		return (NULL);
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

/*
 * Frees every node of a stack list by taking the address of the head of
 * the list.
 */
t_stack_list	*ps_free_stack(t_stack_list **lst)
{
	t_stack_list	*temp;

	temp = NULL;
	if ((*lst) == NULL || lst == NULL)
		return (NULL);
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
		(*lst)->number = 0;
		(*lst)->index = 0;
		(*lst)->segment = 0;
		free(*lst);
		(*lst) = temp;
	}
	(*lst) = NULL;
	lst = NULL;
	return (NULL);
}

t_seg_list	*ps_free_seg(t_seg_list **segment)
{
	if (segment == NULL || (*segment == NULL))
		return (NULL);
	(*segment)->seg_size = 0;
	(*segment)->seg_total = 0;
	(*segment)->seg_up_cnt = 0;
	(*segment)->seg_down_cnt = 0;
	(*segment)->seg_down = 0;
	(*segment)->seg_up = 0;
	free(*segment);
	(*segment) = NULL;
	segment = NULL;
	return (NULL);
}

/*
 * Frees the node of the piles struct, which contains the data and the two
 * stacks (pile_a, pile_b).
 * Also ensures that the lists contained within the struct are freed.
 */
t_piles_list	*ps_free_piles(t_piles_list **piles)
{
	if (piles == NULL || (*piles == NULL))
		return (NULL);
	(*piles)->pile_a = ps_free_stack(&(*piles)->pile_a);
	(*piles)->pile_b = ps_free_stack(&(*piles)->pile_b);
	(*piles)->a_lenght = 0;
	(*piles)->b_lenght = 0;
	(*piles)->index_max = 0;
	(*piles)->seg_data = ps_free_seg(&(*piles)->seg_data);
	free(*piles);
	(*piles) = NULL;
	piles = NULL;
	return (NULL);
}
