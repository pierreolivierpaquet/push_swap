/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:52:23 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/05 11:52:24 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	command(t_piles_list *p, char *op, int l)
{
	if (ft_strncmp(op, "pa", l - 1) == 0)
		ps_push_a(p);
	else if (ft_strncmp(op, "pb", l - 1) == 0)
		ps_push_b(p);
	else if (ft_strncmp(op, "sa", l - 1) == 0)
		ps_swap_a(p);
	else if (ft_strncmp(op, "sb", l - 1) == 0)
		ps_swap_b(p);
	else if (ft_strncmp(op, "ss", l - 1) == 0)
		ps_swap_s(p);
	else if (ft_strncmp(op, "ra", l - 1) == 0)
		ps_rotate_a(p);
	else if (ft_strncmp(op, "rb", l - 1) == 0)
		ps_rotate_b(p);
	else if (ft_strncmp(op, "rr", l - 1) == 0)
		ps_rotate_r(p);
	else if (ft_strncmp(op, "rra", l - 1) == 0)
		ps_rrotate_a(p);
	else if (ft_strncmp(op, "rrb", l - 1) == 0)
		ps_rrotate_b(p);
	else if (ft_strncmp(op, "rrr", l - 1) == 0)
		ps_rrotate_r(p);
	else
		ps_error();
	return ;
}

void	checker(t_piles_list *p, int fd)
{
	char	*operation;
	int		in_progress;

	operation = NULL;
	in_progress = OK;
	while (in_progress)
	{
		operation = get_next_line(fd);
		if (operation == NULL)
		{
			in_progress = KO;
			break ;
		}
		command(p, operation, (ft_strlen(operation)));
		free(operation);
		operation = NULL;
	}
	free(operation);
	if (ps_check_sorted(p->pile_a) == OK)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

int	main(int argc, char **argv)
{
	t_piles_list	*push;

	push = NULL;
	push = ps_pile_init(argc, argv);
	if (push == NULL)
		return (ps_error());
	checker(push, 0);
	ps_free_piles(&push);
	return (0);
}
