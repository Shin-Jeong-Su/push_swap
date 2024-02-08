/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:01:46 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/08 14:45:28 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_deque.h"

void	init_dq(t_dq *dq)
{
	dq->head = 0;
	dq->tail = 0;
}

int	is_dq_empty(t_dq *dq)
{
	if (dq->head == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	push_front_dq(t_dq *dq, DATA data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = data;
	new->next = dq->head;
	if (is_dq_empty(dq))
		dq->tail = new;
	else
		dq->head->prev = new;
	new->prev = 0;
	dq->head = new;
}

void	push_back_dq(t_dq *dq, DATA data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = data;
	new->prev = dq->tail;
	if (is_dq_empty(dq))
		dq->head = new;
	else
		dq->tail->next = new;
	new->next = 0;
	dq->tail = new;
}

void	pop_front_dq(t_dq *dq)
{
	t_node	*tmp;
	if (is_dq_empty(dq))
		return ;
	tmp = dq->head;
	dq->head = dq->head->next;
	free(tmp);
	if (dq->head == NULL)
		dq->tail = NULL;
	else
		dq->head->prev = NULL;
}

void	pop_back_dq(t_dq *dq)
{
	t_node	*tmp;

	if (is_dq_empty(dq))
		return ;
	tmp = dq->tail;
	dq->tail = dq->tail->prev;
	free(tmp);
	if (dq->tail == NULL)
		dq->head = NULL;
	else
		dq->tail->next = 0;
}

void	clear_dq(t_dq *dq)
{
	while (dq->head != dq->tail)
		pop_back_dq(dq);
}

DATA	front_dq(t_dq *dq)
{
	if (is_dq_empty(dq))
		return (0);
	return (dq->head->data);
}

DATA	back_dq(t_dq *dq)
{
	if (is_dq_empty(dq))
		return (0);
	return (dq->tail->data);
}
