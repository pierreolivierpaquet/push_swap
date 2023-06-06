/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:17:13 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/30 13:17:14 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_move_pa_ra(t_piles_list *p)
{
	ps_move_master(p, PA);
	ps_move_master(p, RA);
	ps_is_index(p);
	return ;
}

void	ps_is_next(t_piles_list *p)
{
	if ((p->b_lenght > 1) && (p->pile_b->index == p->pile_a->index - 6)
		&& (ps_lst_last(p->pile_a))->index == p->index_max)
		ps_move_pa_ra(p);
	if ((p->b_lenght > 1) && (p->pile_b->index == p->pile_a->index - 5)
		&& (ps_lst_last(p->pile_a))->index == p->index_max)
		ps_move_pa_ra(p);
	if ((p->b_lenght > 1) && (p->pile_b->index == p->pile_a->index - 4)
		&& (ps_lst_last(p->pile_a))->index == p->index_max)
		ps_move_pa_ra(p);
	if (p->b_lenght > 1 && (p->pile_b->index == p->pile_a->index - 3)
		&& (ps_lst_last(p->pile_a))->index == p->index_max)
		ps_move_pa_ra(p);
	if (p->b_lenght > 1 && (p->pile_b->index == p->pile_a->index - 2))
		ps_move_pa_ra(p);
	return ;
}

void	ps_is_index(t_piles_list *p)
{
	if (p->b_lenght < 1)
		return ;
	if (p->pile_b->index == p->pile_a->index - 1)
	{
		ps_move_master(p, PA);
		ps_is_index(p);
	}
	if ((ps_lst_last(p->pile_a))->index + 1 == p->pile_a->index)
	{
		ps_move_master(p, RRA);
		ps_is_index(p);
	}
	ps_is_next(p);
}

void	ps_is_seg(t_piles_list	*p)
{
	if (p->pile_a->index == p->index_max)
		ps_move_master(p, RA);
	if (p->pile_a->segment == p->seg_data->seg_down)
	{
		ps_move_master(p, PB);
		p->seg_data->seg_down_cnt++;
		ps_move_master(p, RB);
	}
	else if (p->pile_a->segment == p->seg_data->seg_up)
	{
		ps_move_master(p, PB);
		p->seg_data->seg_up_cnt++;
	}
	if (p->a_lenght > 1 && (p->pile_a->segment == p->seg_data->seg_down
			|| p->pile_a->segment == p->seg_data->seg_up))
		ps_is_seg(p);
	return ;
}
