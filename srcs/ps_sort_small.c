/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:18:48 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/16 12:18:49 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_sort_small_best(t_piles_list *p)
{
	if (p->pile_a->index > 1)
	{
		if (p->pile_a->index > p->pile_a->next->index)
			ps_move_master(p, SA);
		else
			ps_move_master(p, RA);
	}
	return (KO);
}

void	ps_sort_small_3(t_piles_list *p)
{
	if (p->a_lenght <= 1)
		return ;
	if ((p->pile_a->index) == (p->index_max))
		ps_move_master(p, RA);
	if (p->a_lenght >= 3)
	{
		if ((p->pile_a->next->index) == (p->index_max))
			ps_move_master(p, RRA);
		if (p->pile_a->index > p->pile_a->next->index)
			ps_move_master(p, SA);
	}
	return ;
}

void	ps_sort_small_4(t_piles_list *p)
{
	if (p->a_lenght <= 1)
		return ;
	while (ps_check_sorted(p->pile_a) == KO)
	{
		if (p->pile_a->index == 4)
			ps_move_master(p, RA);
		if (p->pile_a->next->index == 4)
		{
			if (p->pile_a->index < ps_lst_last(p->pile_a)->index)
				ps_move_master(p, SA);
			else
				ps_move_master(p, RA);
			ps_move_master(p, RA);
		}
		if (ps_lst_last(p->pile_a)->prev->index == 4)
		{	
			if (p->pile_a->index > p->pile_a->next->index)
				ps_move_master(p, SA);
			ps_move_master(p, RRA);
		}
		if (p->pile_a->index == 1 && p->pile_a->next->index != 2)
			ps_move_master(p, RA);
		ps_move_master(p, ps_sort_small_best(p));
	}
}
