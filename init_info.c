/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:20:48 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/21 20:06:49 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}

static void	get_pivot(t_idx_info *info, t_dq *dq, int rng)
{
	int		start;
	t_node	*here;

	start = rng;
	here = dq->head;
	while (start--)
	{
		if (start == rng / 3)
		{
			info->sml_pivot = here->data;
		}
		else if (start == rng / 3 * 2)
			info->lrg_pivot = here->data;
		here = here->next;
	}
	if (info->sml_pivot > info->lrg_pivot)
		swap(&(info->sml_pivot), &(info->lrg_pivot));
}

void	init_idx_info(t_idx_info *info, t_dq *here, t_dq *there, int rng)
{
	info->lrg_pivot = 0;
	info->sml_pivot = 0;
	get_pivot(info, here, rng);
	info->has_size = there->size;
	info->pa_times = 0;
	info->pb_times = 0;
	info->ra_times = 0;
	info->rb_times = 0;
	info->data = front_dq(here);
	info->rng = rng;
}

void	init_3n(t_dq *dq, t_3n *cmps)
{
	cmps->fir = dq->head->data;
	cmps->sec = dq->head->next->data;
	cmps->thr = dq->head->next->next->data;
}
