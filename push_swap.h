/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:51:43 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/16 17:40:28 by jeshin           ###   ########.fr       */
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
}	t_idx_info;

//utils.c
void	check_leaks(void);
void	free_tab(char **tab);
void	free_all(char ***tab);
void	take_error(void);
//quick_sort.c
void	quick_sort(int *arr, int left, int right);
//init.c
int		init(int ac, char **av, t_dq *a, t_dq *b);
//command.c
int		go_cmds(t_dq *a, t_dq *b, char *input);
//push_swap.c
int		push_swap(t_dq *a, t_dq *b, int size);
//push_swap2.c
int		sort_size_lower_than_3(t_dq *dq, int which, int size);
void	init_idx_info(t_idx_info *info, t_dq *dq, int rng);

#endif