/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:02:28 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/07 12:02:30 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Move that ROTATES pile_a, where the first node becomes the last one, and 
 * the second node becomes the first.
 */
void	ps_rotate_a(t_piles_list *piles)
{
	t_stack_list	*temp_prev;
	t_stack_list	*temp_last;

	temp_prev = NULL;
	temp_last = NULL;
	if (!piles || piles->pile_a == NULL || piles->pile_a->next == NULL)
		return ;
	temp_last = piles->pile_a;
	piles->pile_a = piles->pile_a->next;
	piles->pile_a->prev = NULL;
	temp_prev = ps_lst_last(piles->pile_a);
	temp_prev->next = temp_last;
	temp_last->prev = temp_prev;
	temp_last->next = NULL;
	temp_prev = NULL;
	temp_last = NULL;
	return ;
}

/*
 * Move that ROTATES pile_b, where the first node becomes the last one, and 
 * the second node becomes the first.
 */
void	ps_rotate_b(t_piles_list *piles)
{
	t_stack_list	*temp_prev;
	t_stack_list	*temp_last;

	temp_prev = NULL;
	temp_last = NULL;
	if (!piles || piles->pile_b == NULL || piles->pile_b->next == NULL)
		return ;
	temp_last = piles->pile_b;
	piles->pile_b = piles->pile_b->next;
	piles->pile_b->prev = NULL;
	temp_prev = ps_lst_last(piles->pile_b);
	temp_prev->next = temp_last;
	temp_last->prev = temp_prev;
	temp_last->next = NULL;
	temp_prev = NULL;
	temp_last = NULL;
	return ;
}

/*
 * Move that REVERSE ROTATES pile_a, where the first node becomes the second
 * one, and the last node becomes the first.
 */
void	ps_rrotate_a(t_piles_list *piles)
{
	t_stack_list	*temp_first;
	t_stack_list	*temp_prev;

	temp_prev = NULL;
	temp_first = NULL;
	if (!piles || piles->pile_a == NULL || piles->pile_a->next == NULL)
		return ;
	temp_first = piles->pile_a;
	temp_prev = ps_lst_last(piles->pile_a);
	piles->pile_a = temp_prev;
	temp_prev = piles->pile_a->prev;
	piles->pile_a->next = temp_first;
	temp_first->prev = piles->pile_a;
	piles->pile_a->prev = NULL;
	temp_prev->next = NULL;
	temp_prev = NULL;
	temp_first = NULL;
	return ;
}

/*
 * Move that REVERSE ROTATES pile_b, where the first node becomes the second
 * one, and the last node becomes the first.
 */
void	ps_rrotate_b(t_piles_list *piles)
{
	t_stack_list	*temp_first;
	t_stack_list	*temp_prev;

	temp_prev = NULL;
	temp_first = NULL;
	if (!piles || piles->pile_b == NULL || piles->pile_b->next == NULL)
		return ;
	temp_first = piles->pile_b;
	temp_prev = ps_lst_last(piles->pile_b);
	piles->pile_b = temp_prev;
	temp_prev = piles->pile_b->prev;
	piles->pile_b->next = temp_first;
	temp_first->prev = piles->pile_b;
	piles->pile_b->prev = NULL;
	temp_prev->next = NULL;
	temp_prev = NULL;
	temp_first = NULL;
	return ;
}
