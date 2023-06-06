/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:07:43 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/10 12:07:44 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Moves that interchanges the first two nodes of pile_a and pile_b.
 */
void	ps_swap_s(t_piles_list *piles)
{
	ps_swap_a(piles);
	ps_swap_b(piles);
	return ;
}

/*
 * Move that rotates both pile_a and pile_b.
 */
void	ps_rotate_r(t_piles_list *piles)
{
	ps_rotate_a(piles);
	ps_rotate_b(piles);
	return ;
}

/*
 * Move that performs a reverse rotation on both pile_a and pile_b.
 */
void	ps_rrotate_r(t_piles_list *piles)
{
	ps_rrotate_a(piles);
	ps_rrotate_b(piles);
	return ;
}
