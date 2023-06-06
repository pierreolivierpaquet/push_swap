/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:21:07 by ppaquet           #+#    #+#             */
/*   Updated: 2023/04/12 14:21:10 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Attributes the correct ordered index of the INTEGER in the provided
 * list, considering taht their order of appearance may not be sorted. 
 * The value of -1 is given in the case that the same INTEGER is located
 * elsewhere in the list.
 */
void	ps_indexer(t_piles_list	*piles)
{
	int				res;
	t_stack_list	*temp;
	t_stack_list	*checker;

	res = 1;
	temp = piles->pile_a;
	checker = piles->pile_a;
	while (checker != NULL)
	{
		while (temp != NULL)
		{
			if (checker->number > temp->number)
				res++;
			else if ((checker->number == temp->number) && (checker != temp))
			{
				res = -1;
				break ;
			}
			temp = temp->next;
		}
	checker->index = res;
	res = 1;
	checker = checker->next;
	temp = piles->pile_a;
	}
}

/*
 * Transfers the character strings pointed to by the pointers array
 * into the content of newly created nodes in a linked list, using ft_atoli().
 * If a memory allocation fails while creating a new node, 'KO' is returned.
 * This allows proper memory cleanup to be performed afterwards.
 */
int	ps_fill_pile(t_stack_list **lst, char **str)
{
	int				i;
	t_stack_list	*temp;

	i = 0;
	temp = NULL;
	while (str[i] != NULL)
	{
		if (ps_lstadd_back(lst, ps_lst_new(ps_atoll(str[i]))) == NULL)
			return (KO);
		temp = ps_lst_last(*lst);
		if (temp->prev == NULL)
			temp->index = (i + 1);
		else
			temp->index = (temp->prev->index + 1);
		i++;
	}
	return (OK);
}

/*
 * Full parsing of all the arguments provided. Each character string is
 * split, and all content is correctly distributed in a double linked list.
 * The pile_a is returned.
 */
int	ps_arg_parse(t_piles_list *piles, int ac, char **av)
{
	int				j;
	char			**argv_temp;

	j = 0;
	argv_temp = NULL;
	if (ac >= 2)
	{
		while (j++ < ac)
		{
			argv_temp = ft_split(av[j], ' ');
			if (argv_temp)
			{
				if (ps_fill_pile(&piles->pile_a, argv_temp) == KO)
				{
					argv_temp = ps_free_tab(argv_temp);
					return (KO);
				}
				argv_temp = ps_free_tab(argv_temp);
			}
		}
	}
	ps_indexer(piles);
	return (OK);
}

/*
 * Creates a new pile node and initializes the 'pile_a' by integrating the
 * values provided as program arguments.
 */
t_piles_list	*ps_pile_init(int ac, char **av)
{
	t_piles_list	*result;

	result = NULL;
	result = ps_pile_new();
	if (result == NULL || ac < 2)
		return (ps_free_piles(&result));
	if (ps_arg_parse(result, ac, av) == KO)
		return (ps_free_piles(&result));
	if (ps_check_dup(result->pile_a) == KO
		|| ps_check_minmax(result->pile_a) == KO)
		return (ps_free_piles(&result));
	result->a_lenght = ps_lst_size(result->pile_a);
	result->index_max = result->a_lenght;
	result->seg_data = ps_segment_new();
	if (result->seg_data == NULL)
		return (ps_free_piles(&result));
	ps_segment_init(result);
	if (result->a_lenght > 10)
		ps_segment_data_init(result);
	return (result);
}
