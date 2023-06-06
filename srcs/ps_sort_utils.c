/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:35:15 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/17 12:35:16 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_smallest_index(t_stack_list *pile)
{
	t_stack_list	*temp;
	int				smallest;
	int				i;
	int				j;

	temp = NULL;
	if (pile == NULL)
		return (0);
	temp = pile;
	smallest = pile->number;
	j = 1;
	i = 1;
	while (temp != NULL)
	{
		if (temp->number < smallest)
		{
			smallest = temp->number;
			j = i;
			if (temp->index == 1)
				return (j);
		}
		temp = temp->next;
		i++;
	}
	return (j);
}

int	ps_biggest_index(t_stack_list *pile)
{
	t_stack_list	*temp;
	int				biggest;
	int				i;
	int				j;

	temp = NULL;
	if (pile == NULL)
		return (0);
	temp = pile;
	biggest = pile->number;
	j = 1;
	i = 1;
	while (temp != NULL)
	{
		if (temp->number > biggest)
		{
			biggest = temp->number;
			j = i;
		}
		temp = temp->next;
		i++;
	}
	return (j);
}

int	ps_min_max_index(t_piles_list *piles, int select, char p)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (piles == NULL)
		return (0);
	if (select == SMALLEST)
	{
		if (p == 'a' || p == 'A')
			j = ps_smallest_index(piles->pile_a);
		else if (p == 'b' || p == 'B')
			j = ps_smallest_index(piles->pile_b);
	}
	if (select == BIGGEST)
	{
		if (p == 'a' || p == 'A')
			j = ps_biggest_index(piles->pile_a);
		else if (p == 'b' || p == 'B')
			j = ps_biggest_index(piles->pile_b);
	}
	i = j;
	return (i);
}
