/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:51:43 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/20 20:23:13 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "my_deque.h"

# define A 0
# define B 1

typedef struct s_idx_info
{
	int	lrg_pivot;
	int	sml_pivot;
	int	pa_times;
	int	pb_times;
	int	ra_times;
	int	rb_times;
	int	data;
	int	rng;
	int	already;
}	t_idx_info;

//utils.c
void	check_leaks(void);
void	free_tab(char **tab);
void	free_all(char ***tab);
void	take_error(void);
int		is_asc(t_dq *dq, int size);
//init.c
int		init(int ac, char **av, t_dq *a, t_dq *b);
//init_info.c
void	init_idx_info(t_idx_info *info, t_dq *here, t_dq *there, int rng);
//quick_sort.c
void	quick_sort(int *arr, int left, int right);
//command.c
int		go_cmds(t_dq *a, t_dq *b, char *input);
//push_swap.c
int		push_swap(t_dq *a, t_dq *b, int size);
//sort_3.c
int		sort_a_of_size_3(t_dq *a);
int		sort_size_lower_than_3(t_dq *a, t_dq *b, int which, int size);
//sort_4_n_5.c
int	sort_a_of_size_4(t_dq *a, t_dq *b, int min);
int	sort_a_of_size_5(t_dq *a, t_dq *b, int min);
#endif