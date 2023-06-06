/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:07:21 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/15 14:07:22 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(int ac, char **av)
{
	t_piles_list	*push;

	push = NULL;
	push = ps_pile_init(ac, av);
	if (push == NULL)
		return (ps_error());
	if (ps_check_sorted(push->pile_a) == OK)
	{
		ps_free_piles(&push);
		return (SUCCESS);
	}
	if (push->a_lenght <= 3)
		ps_sort_small_3(push);
	else if (push->a_lenght == 4)
		ps_sort_small_4(push);
	else if (push->a_lenght > 4 && push->a_lenght <= 25)
		ps_sort_mid(push);
	else
		ps_sort_big(push);
	push = ps_free_piles(&push);
	return (SUCCESS);
}
