/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:21:15 by ppaquet           #+#    #+#             */
/*   Updated: 2023/04/12 14:21:17 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# ifndef INT32_MAX
#  define INT32_MAX 2147483647
# endif
# ifndef INT32_MIN
#  define INT32_MIN -2147483648
# endif

# define OK 1
# define KO 0
# define SMALLEST 0
# define BIGGEST 1
# define SUCCESS 0
# define FAILURE -1

// -----------------------------------------------------------< STRUCTURES >---

typedef struct s_seg_node
{
	int	seg_size;
	int	seg_total;
	int	seg_up_cnt;
	int	seg_down_cnt;
	int	seg_up;
	int	seg_down;
}	t_seg_list;

typedef struct s_stack_node
{
	long long				number;
	int						index;
	int						segment;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_list;

typedef struct s_piles_node
{
	t_stack_list		*pile_a;
	t_stack_list		*pile_b;
	int					a_lenght;
	int					b_lenght;
	int					index_max;
	t_seg_list			*seg_data;
}	t_piles_list;

// ------------------------------------------------------------< PUSH SWAP >---

int				push_swap(int ac, char **av);

// ------------------------------------------------------< CHECKS + ERRORS >---

char			**ps_free_tab(char **tab);
t_stack_list	*ps_free_stack(t_stack_list **lst);
t_seg_list		*ps_free_seg(t_seg_list **segment);
t_piles_list	*ps_free_piles(t_piles_list **piles);

int				ps_error(void);
int				ps_check_dup(t_stack_list *pile);
int				ps_check_minmax(t_stack_list *pile);
int				ps_check_sorted(t_stack_list *pile);

// --------------------------------------------------------------< PARSING >---

void			ps_indexer(t_piles_list	*piles);
int				ps_fill_pile(t_stack_list **lst, char **str);
int				ps_arg_parse(t_piles_list *piles, int ac, char **av);
t_piles_list	*ps_pile_init(int ac, char **av);

// ----------------------------------------------------------------< MOVES >---

# define PA 11
# define PB 12

# define SA 21
# define SB 22
# define SS 23

# define RA 31
# define RB 32
# define RR 33

# define RRA 41
# define RRB 42
# define RRR 43

void			ps_push_a(t_piles_list *piles);
void			ps_push_b(t_piles_list *piles);
void			ps_swap_a(t_piles_list *piles);
void			ps_swap_b(t_piles_list *piles);

void			ps_rotate_a(t_piles_list *piles);
void			ps_rotate_b(t_piles_list *piles);
void			ps_rrotate_a(t_piles_list *piles);
void			ps_rrotate_b(t_piles_list *piles);

void			ps_swap_s(t_piles_list *piles);
void			ps_rotate_r(t_piles_list *piles);
void			ps_rrotate_r(t_piles_list *piles);

void			ps_push_master(t_piles_list *piles, int move);
void			ps_swap_master(t_piles_list *piles, int move);
void			ps_rotate_master(t_piles_list *piles, int move);
void			ps_print_move(int move);
void			ps_move_master(t_piles_list *piles, int move);

// --------------------------------------------------------------< NUMERIC >---

long long		ps_atoll(char *str);

// ---------------------------------------------------------< SEGMENTATION >---

void			ps_seg_switch(t_piles_list *p);
void			ps_segmenter(t_piles_list *pile, float qty, int seg);
void			ps_segment_init(t_piles_list *piles);
t_seg_list		*ps_segment_new(void);
void			ps_segment_data_init(t_piles_list *piles);

// -----------------------------------------------------------< LIST UTILS >---

void			ps_lst_addfront(t_stack_list **first, t_stack_list *new);
t_stack_list	*ps_lst_new(long long number);
t_stack_list	*ps_lst_last(t_stack_list *first);
t_stack_list	*ps_lstadd_back(t_stack_list **first, t_stack_list *new);
int				ps_lst_size(t_stack_list *first);
t_piles_list	*ps_pile_new(void);

// -----------------------------------------------------------< SORT UTILS >---

int				ps_smallest_index(t_stack_list *pile);
int				ps_biggest_index(t_stack_list *pile);
int				ps_min_max_index(t_piles_list *piles, int select, char p);

void			ps_sort_big_init(t_piles_list *p);
void			ps_sort_big(t_piles_list *piles);

void			ps_move_pa_ra(t_piles_list *p);
void			ps_is_next(t_piles_list *p);
void			ps_is_index(t_piles_list *p);
void			ps_is_seg(t_piles_list	*p);

// ------------------------------------------------------------< ALGORITHM >---

int				ps_sort_small_best(t_piles_list *p);
void			ps_sort_small_3(t_piles_list *p);
void			ps_sort_small_4(t_piles_list *p);

void			ps_sort_mid(t_piles_list *piles);

void			ps_sort_big(t_piles_list *piles);

#endif
