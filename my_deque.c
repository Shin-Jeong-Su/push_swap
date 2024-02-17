/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:01:46 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/17 18:08:29 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_deque.h"

void	init_dq(t_dq *dq)
{
	dq->head = 0;
	dq->tail = 0;
	dq->size = 0;
}

int	is_empty_dq(t_dq *dq)
{
	if (dq->head == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	push_front_dq(t_dq *dq, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = data;
	new->next = dq->head;
	if (is_empty_dq(dq))
		dq->tail = new;
	else
		dq->head->prev = new;
	new->prev = 0;
	dq->head = new;
	dq->size++;
}

void	push_back_dq(t_dq *dq, int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = data;
	new->prev = dq->tail;
	if (is_empty_dq(dq))
		dq->head = new;
	else
		dq->tail->next = new;
	new->next = 0;
	dq->tail = new;
	dq->size++;
}

void	print_all_dq(t_dq *dq)
{
	t_node	*here;

	here = dq->head;
	while (here)
	{
		ft_putnbr_fd(here->data, 1);
		write(1,"\t",1);
		here = here->next;
	}
}
