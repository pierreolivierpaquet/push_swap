/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:56:33 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/02 12:56:34 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
 * Adds the 'new' node to the front of the list specified as the first
 * parameter.
 */
void	ps_lst_addfront(t_stack_list **first, t_stack_list *new)
{
	if (new == NULL)
		return ;
	new->next = (*first);
	(*first) = new;
	if ((*first)->next != NULL)
		(*first)->next->prev = (*first);
	return ;
}

/*
 * Moves the first node of pile_b and brings it to the top of pile_a.
 */
void	ps_push_a(t_piles_list *piles)
{
	t_stack_list	*temp_b;
	t_stack_list	*temp_b_next;

	temp_b = NULL;
	temp_b_next = NULL;
	if (piles->pile_b == NULL)
		return ;
	temp_b_next = piles->pile_b->next;
	temp_b = piles->pile_b;
	ps_lst_addfront(&piles->pile_a, temp_b);
	piles->pile_b = temp_b_next;
	if (piles->pile_b != NULL)
		piles->pile_b->prev = NULL;
	temp_b = NULL;
	temp_b_next = NULL;
	piles->a_lenght++;
	piles->b_lenght--;
}

/*
 * Moves the first node of pile_a and brings it to the top of pile_b.
 */
void	ps_push_b(t_piles_list *piles)
{
	t_stack_list	*temp_a;
	t_stack_list	*temp_a_next;

	temp_a = NULL;
	temp_a_next = NULL;
	if (piles->pile_a == NULL)
		return ;
	temp_a_next = piles->pile_a->next;
	temp_a = piles->pile_a;
	ps_lst_addfront(&piles->pile_b, temp_a);
	piles->pile_a = temp_a_next;
	if (piles->pile_a != NULL)
		piles->pile_a->prev = NULL;
	temp_a = NULL;
	temp_a_next = NULL;
	piles->a_lenght--;
	piles->b_lenght++;
}

/*
 * Interchanges the first two nodes of pile_a.
 */
void	ps_swap_a(t_piles_list *piles)
{
	t_stack_list	*temp_a;
	t_stack_list	*temp_a_next;

	temp_a = NULL;
	temp_a_next = NULL;
	if (piles->pile_a == NULL || piles->pile_a->next == NULL)
		return ;
	temp_a = piles->pile_a;
	piles->pile_a = temp_a->next;
	piles->pile_a->prev = NULL;
	temp_a_next = piles->pile_a->next;
	if (temp_a_next != NULL)
		temp_a_next->prev = temp_a;
	temp_a->prev = piles->pile_a;
	piles->pile_a->next = temp_a;
	temp_a->next = temp_a_next;
	temp_a = NULL;
	temp_a_next = NULL;
}

/*
 * Interchanges the first two nodes of pile_b.
 */
void	ps_swap_b(t_piles_list *piles)
{
	t_stack_list	*temp_b;
	t_stack_list	*temp_b_next;

	temp_b = NULL;
	temp_b_next = NULL;
	if (piles->pile_b == NULL || piles->pile_b->next == NULL)
		return ;
	temp_b = piles->pile_b;
	piles->pile_b = temp_b->next;
	piles->pile_b->prev = NULL;
	temp_b_next = piles->pile_b->next;
	if (temp_b_next != NULL)
		temp_b_next->prev = temp_b;
	temp_b->prev = piles->pile_b;
	piles->pile_b->next = temp_b;
	temp_b->next = temp_b_next;
	temp_b = NULL;
	temp_b_next = NULL;
}
