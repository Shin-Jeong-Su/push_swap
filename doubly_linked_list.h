/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:39:04 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/08 13:45:08 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

#include <stdlib.h>

typedef int	DATA;

typedef struct s_node
{
	DATA			data;
	struct s_node	*prev;
	struct s_node	*next;
}			t_node;

typedef struct s_dlst
{
	t_node *head;
	t_node *tail;
}		t_dlst;

#endif