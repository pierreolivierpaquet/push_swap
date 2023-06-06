/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_segmentation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:24:00 by ppaquet           #+#    #+#             */
/*   Updated: 2023/05/26 18:24:01 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_seg_switch(t_piles_list *p)
{
	if (p == NULL)
		return ;
	if (p->seg_data->seg_down_cnt == p->seg_data->seg_size)
	{
		p->seg_data->seg_down_cnt = 0;
		p->seg_data->seg_down--;
	}
	if (p->seg_data->seg_up_cnt == p->seg_data->seg_size)
	{
		p->seg_data->seg_up_cnt = 0;
		p->seg_data->seg_up++;
	}
	return ;
}

/*
 * Assigns a segment identification value, to each number of the list. 
 */
void	ps_segmenter(t_piles_list *pile, float qty, int seg)
{
	t_stack_list	*temp;
	int				seg_max;
	int				seg_min;
	int				ctr;

	temp = pile->pile_a;
	seg_max = pile->seg_data->seg_size;
	seg_min = seg;
	ctr = 1;
	while (((float)seg - 1) <= qty)
	{
		while (temp != NULL && ctr <= pile->seg_data->seg_size)
		{
			if (temp->segment == 0
				&& (temp->index >= seg_min && temp->index <= seg_max) && ++ctr)
				temp->segment = seg;
			temp = temp->next;
		}
		temp = pile->pile_a;
		seg++;
		seg_min += pile->seg_data->seg_size;
		seg_max += pile->seg_data->seg_size;
		ctr = 1;
	}
	return ;
}

/*
 * Initializes the segmentation values to identify each number of the list. 
 */
void	ps_segment_init(t_piles_list *p)
{
	t_stack_list	*temp;
	float			seg_quantity;
	int				seg_current;

	temp = NULL;
	if (p == NULL)
		return ;
	temp = p->pile_a;
	p->seg_data->seg_size = (0.045) * p->a_lenght + 4;
	if (p->seg_data->seg_size == 0)
		p->seg_data->seg_size++;
	seg_quantity = (float)(p->a_lenght) / (float)p->seg_data->seg_size;
	seg_current = 1;
	ps_segmenter(p, seg_quantity, seg_current);
	temp = p->pile_a;
	while (temp != NULL)
	{
		if (temp->segment > seg_current)
			seg_current = temp->segment;
		temp = temp->next;
	}
	p->seg_data->seg_total = seg_current;
	return ;
}

t_seg_list	*ps_segment_new(void)
{
	t_seg_list	*new;

	new = NULL;
	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->seg_size = 0;
	new->seg_total = 0;
	new->seg_up_cnt = 0;
	new->seg_down_cnt = 0;
	new->seg_down = 1;
	new->seg_up = 1;
	return (new);
}

void	ps_segment_data_init(t_piles_list *piles)
{
	int	count;

	if (piles == NULL)
		return ;
	count = (int)piles->seg_data->seg_total;
	if (count == 1)
	{
		piles->seg_data->seg_down = 1;
		piles->seg_data->seg_up = 1;
	}
	if (count > 1)
	{
		piles->seg_data->seg_down = count / 2;
		piles->seg_data->seg_up = (piles->seg_data->seg_down + 1);
	}
	return ;
}
