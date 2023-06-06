/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_master.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:26:17 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/11 11:26:18 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Sends the piles node to the corresponding PUSH function.
 */
void	ps_push_master(t_piles_list *piles, int move)
{
	if (move == PA)
		ps_push_a(piles);
	if (move == PB)
		ps_push_b(piles);
	return ;
}

/*
 * Sends the piles node to the corresponding SWAP function.
 */
void	ps_swap_master(t_piles_list *piles, int move)
{
	if (move == SA)
		ps_swap_a(piles);
	if (move == SB)
		ps_swap_b(piles);
	if (move == SS)
		ps_swap_s(piles);
	return ;
}

/*
 * Sends the piles node to the corresponding ROTATE function.
 */
void	ps_rotate_master(t_piles_list *piles, int move)
{
	if (move == RA)
		ps_rotate_a(piles);
	if (move == RB)
		ps_rotate_b(piles);
	if (move == RR)
		ps_rotate_r(piles);
	if (move == RRA)
		ps_rrotate_a(piles);
	if (move == RRB)
		ps_rrotate_b(piles);
	if (move == RRR)
		ps_rrotate_r(piles);
	return ;
}

/*
 * Prints the corresponding move to the standard output (stdout).
 */
void	ps_print_move(int move)
{
	if (move == PA)
		write(1, "pa\n", 3);
	if (move == PB)
		write(1, "pb\n", 3);
	if (move == SA)
		write(1, "sa\n", 3);
	if (move == SB)
		write(1, "sb\n", 3);
	if (move == SS)
		write(1, "ss\n", 3);
	if (move == RA)
		write(1, "ra\n", 3);
	if (move == RB)
		write(1, "rb\n", 3);
	if (move == RR)
		write(1, "rr\n", 3);
	if (move == RRA)
		write(1, "rra\n", 4);
	if (move == RRB)
		write(1, "rrb\n", 4);
	if (move == RRR)
		write(1, "rrr\n", 4);
	return ;
}

/*
 * Sends the piles node to the appropriate master move category, whether it's
 * PUSH, ROTATE OR SWAP.
 * Also sends the move to be displayed on the standard output (stdout).
 */
void	ps_move_master(t_piles_list *piles, int move)
{
	if (piles == NULL || move < 0)
		return ;
	if (move >= PA && move <= PB)
		ps_push_master(piles, move);
	if (move >= SA && move <= SS)
		ps_swap_master(piles, move);
	if ((move >= RA && move <= RR) || (move >= RRA && move <= RRR))
		ps_rotate_master(piles, move);
	ps_print_move(move);
	return ;
}
