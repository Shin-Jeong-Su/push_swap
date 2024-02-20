/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:20:48 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/20 18:00:34 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pivot(t_idx_info *info, t_dq *dq, int rng)
{
	int		start;
	int		tmp;
	t_node	*here;

	start = rng;
	here = dq->head;
	while (start--)
	{
		if (start == rng / 3)
			info->sml_pivot = here->data;
		else if (start == rng / 3 * 2)
			info->lrg_pivot = here->data;
		here = here->next;
	}
	if (info->sml_pivot > info->lrg_pivot)
	{
		tmp = info->sml_pivot;
		info->sml_pivot = info->lrg_pivot;
		info->lrg_pivot = tmp;
	}
}

void	init_idx_info(t_idx_info *info, t_dq *here, t_dq *there, int rng)
{
	get_pivot(info, here, rng);
	info->already = there->size;
	info->pa_times = 0;
	info->pb_times = 0;
	info->ra_times = 0;
	info->rb_times = 0;
	info->data = front_dq(here);
	info->rng = rng;
}
