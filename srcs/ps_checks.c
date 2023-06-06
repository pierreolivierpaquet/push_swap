/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:52:39 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/12 13:52:40 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Prints an "Error" message, followed by a new line ('\n') to the standard
 * error stream (stderr).
 * Returns the value '-1'.
 */
int	ps_error(void)
{
	ft_putendl_fd("Error", 2);
	return (FAILURE);
}

/*
 * Checks if any value of '-1' is registered based on the previously sorted
 * indexes.
 * If a '-1' value is found, the function returns 'KO'.
 */
int	ps_check_dup(t_stack_list *pile)
{
	t_stack_list	*temp;

	temp = NULL;
	temp = pile;
	while (temp != NULL)
	{
		if (temp->index == FAILURE)
		{
			temp = NULL;
			return (KO);
		}
		temp = temp->next;
	}
	return (OK);
}

/*
 * Checks if any number registered in the list is either less than INT32_MIN, or
 * greater than INT32_MAX.
 * If either condition is true, the function returns 'KO'.
 */
int	ps_check_minmax(t_stack_list *pile)
{
	t_stack_list	*temp;

	temp = NULL;
	if (pile == NULL)
		return (OK);
	temp = pile;
	while (temp != NULL)
	{
		if (temp->number < INT32_MIN || temp->number > INT32_MAX)
			return (KO);
		temp = temp->next;
	}
	return (OK);
}

/*
 * Checks if the list is sorted from smallest to biggest.
 */
int	ps_check_sorted(t_stack_list *pile)
{
	t_stack_list	*temp;

	temp = NULL;
	if (pile == NULL || ps_lst_size(pile) == 1)
		return (OK);
	temp = pile;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			return (OK);
		if (temp->index != ((temp->next->index) - 1))
			return (KO);
		temp = temp->next;
	}
	return (OK);
}
