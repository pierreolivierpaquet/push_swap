/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:42:50 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/26 12:42:51 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_sort_big_to_a(t_piles_list *p)
{
	int	pos;

	pos = 0;
	if (p->pile_b == NULL)
		return ;
	while (p->b_lenght > 0)
	{
		ps_is_index(p);
		pos = ps_min_max_index(p, BIGGEST, 'b');
		if (pos <= p->b_lenght / 2)
		{
			if (pos == 1)
				ps_move_master(p, PA);
			else
				ps_move_master(p, RB);
		}
		else
			ps_move_master(p, RRB);
	}
	return ;
}

void	ps_sort_big_init(t_piles_list *p)
{
	if (p == NULL)
		return ;
	while (p->a_lenght > 1)
	{
		if (p->pile_a->index == p->index_max)
			ps_move_master(p, RA);
		ps_is_seg(p);
		if (p->seg_data->seg_down_cnt == p->seg_data->seg_size
			|| p->seg_data->seg_up_cnt == p->seg_data->seg_size)
			ps_seg_switch(p);
		ps_move_master(p, RA);
	}
}

void	ps_sort_big(t_piles_list *piles)
{
	ps_sort_big_init(piles);
	ps_sort_big_to_a(piles);
	return ;
}
