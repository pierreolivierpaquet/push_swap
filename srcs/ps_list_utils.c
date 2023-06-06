/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:37:42 by ppaquet           #+#    #+#             */
/*   Updated: 2023/04/17 12:37:43 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Allocates memory for a new node, adds a number to it, and returns
 * its address.
 * Sets the next and prev values of the node to NULL.
 */
t_stack_list	*ps_lst_new(long long number)
{
	t_stack_list	*new;

	new = NULL;
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->number = number;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	new->segment = 0;
	return (new);
}

/*
 * Finds the last node in the list and returns its address.
 */
t_stack_list	*ps_lst_last(t_stack_list *first)
{
	t_stack_list	*ret;

	if (!first)
		return (NULL);
	ret = NULL;
	ret = first;
	while (ret->next != NULL)
		ret = ret->next;
	return (ret);
}

/*
 * Finds the last node in the list and links a new node to the back of the list.
 */
t_stack_list	*ps_lstadd_back(t_stack_list **first, t_stack_list *new)
{
	t_stack_list	*ret;

	ret = NULL;
	if (!new)
		return (NULL);
	if (!*first)
	{
		*first = new;
		return (*first);
	}
	ret = ps_lst_last(*first);
	ret->next = new;
	ret->next->prev = ret;
	return (ret);
}

/*
 * Counts the number of nodes and returns the total size of the linked list.
 */
int	ps_lst_size(t_stack_list *first)
{
	int				l;
	t_stack_list	*temp;

	temp = NULL;
	if (!first)
		return (0);
	l = 0;
	temp = first;
	while (temp != NULL)
	{
		temp = temp->next;
		l++;
	}
	return (l);
}

/*
 * Creates a new pile by allocating memory for a single pile struct node;
 * Initializes it with starting values (0, NULL), then returns it's adress.
 * Returns NULL if memory allocation fails.
 */
t_piles_list	*ps_pile_new(void)
{
	t_piles_list	*new;

	new = NULL;
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->pile_a = NULL;
	new->pile_b = NULL;
	new->a_lenght = 0;
	new->b_lenght = 0;
	new->index_max = 0;
	new->seg_data = NULL;
	return (new);
}
