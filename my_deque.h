/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:02:27 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/15 14:38:09 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_DEQUE_H
# define MY_DEQUE_H

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int			data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;
typedef struct s_dq
{
	t_node	*head;
	t_node	*tail;
	int		size;
}			t_dq;

//my_deque.c
void	init_dq(t_dq *dq);
int		is_empty_dq(t_dq *dq);
void	push_front_dq(t_dq *dq, int data);
void	push_back_dq(t_dq *dq, int data);
void	print_all_dq(t_dq *dq);

//my_deque2.c
void	pop_front_dq(t_dq *dq);
void	pop_back_dq(t_dq *dq);
int	front_dq(t_dq *dq);
int	back_dq(t_dq *dq);
void	clear_dq(t_dq *dq);

#endif