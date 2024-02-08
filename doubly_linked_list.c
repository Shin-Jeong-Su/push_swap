/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:55:33 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/07 17:46:19 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

void	dl_init(t_dlst *dl){
	dl->head = 0;
	dl->cur = 0;
	dl->node_size = 0;
}
void	dl_add_front(t_dlst *dl, void *data){
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->next = dl->head;
	if (dl->head != NULL)
		dl->head->prev = new;
	dl->head = new;
	new->prev = 0;
	(dl->node_size)++;
}
int		dl_delone(t_dl *dl, void *data, void (*func)(void)){

}
int		dl_clear(t_dl *dl, void (*func)(void));