/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:33:49 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/17 12:33:50 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_sort_mid(t_piles_list *piles)
{
	int	pos;

	pos = 0;
	while (piles->a_lenght > 3)
	{
		pos = ps_min_max_index(piles, SMALLEST, 'a');
		if (pos <= (piles->a_lenght / 2))
		{
			if (pos == 1)
				ps_move_master(piles, PB);
			else
				ps_move_master(piles, RA);
		}
		else
			ps_move_master(piles, RRA);
	}
	ps_sort_small_3(piles);
	while (piles->b_lenght > 0)
		ps_move_master(piles, PA);
	return ;
}
