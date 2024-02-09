/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:02:27 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/09 15:36:16 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_DEQUE_H
# define MY_DEQUE_H

# define TRUE 1
# define FALSE 0

# include <stdlib.h>

typedef int	DATA;

typedef struct s_node
{
	DATA	 		data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;
typedef struct s_dq
{
	t_node	*head;
	t_node	*tail;
}			t_dq;

void	init_dq(t_dq *dq);
int		is_empty_dq(t_dq *dq);
void	push_front_dq(t_dq *dq, DATA data);
void	push_back_dq(t_dq *dq, DATA data);
void	pop_front_dq(t_dq *dq);
void	pop_back_dq(t_dq *dq);
DATA	front_dq(t_dq *dq);
DATA	back_dq(t_dq *dq);
void	clear_dq(t_dq *dq);

#endif