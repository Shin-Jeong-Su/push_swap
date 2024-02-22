/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sml_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:54:53 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/22 13:23:00 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_b_of_rng_3(t_dq *a, t_dq *b)
{
	t_3n	cmps;

	init_3n(b, &cmps);
	if (cmps.fir > cmps.sec && cmps.sec > cmps.thr)
		return (go_cmds(a, b, "pa") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa"));
	if (cmps.fir > cmps.thr && cmps.sec < cmps.thr)
		return (go_cmds(a, b, "pa") & go_cmds(0, b, "sb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa"));
	if (cmps.fir > cmps.sec && cmps.fir < cmps.thr)
		return (go_cmds(0, b, "sb") & go_cmds(0, b, "rb") & go_cmds(0, b, "rb") \
		& go_cmds(a, b, "pa") & go_cmds(0, b, "rrb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "rrb") & go_cmds(a, b, "pa"));
	if (cmps.fir < cmps.sec && cmps.fir > cmps.thr)
		return (go_cmds(0, b, "sb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	if (cmps.fir < cmps.sec && cmps.sec < cmps.thr)
		return (go_cmds(0, b, "rb") & go_cmds(0, b, "rb") & go_cmds(a, b, "pa") \
		& go_cmds(0, b, "rrb") & go_cmds(a, b, "pa") & go_cmds(0, b, "rrb") \
		& go_cmds(a, b, "pa"));
	if (cmps.fir < cmps.thr && cmps.sec > cmps.thr)
		return (go_cmds(0, b, "sb") & go_cmds(a, b, "pa") & go_cmds(0, b, "sb") \
		& go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	return (0);
}

static int	sort_b_of_size_3(t_dq *a, t_dq *b)
{
	t_3n	cmps;

	init_3n(b, &cmps);
	if (cmps.fir > cmps.sec && cmps.sec > cmps.thr)
		return (go_cmds(a, b, "pa") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa"));
	if (cmps.fir > cmps.thr && cmps.sec < cmps.thr)
		return (go_cmds(a, b, "pa") & go_cmds(0, b, "sb") \
		& go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	if (cmps.fir > cmps.sec && cmps.fir < cmps.thr)
		return (go_cmds(0, b, "rrb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	if (cmps.fir < cmps.sec && cmps.fir > cmps.thr)
		return (go_cmds(0, b, "sb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	if (cmps.fir < cmps.sec && cmps.sec < cmps.thr)
		return (go_cmds(0, b, "rrb") & go_cmds(a, b, "pa") \
		& go_cmds(0, b, "rrb") & go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	if (cmps.fir < cmps.thr && cmps.sec > cmps.thr)
		return (go_cmds(0, b, "rb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	return (0);
}

int	sort_sml_b(t_dq *a, t_dq *b, int size)
{
	if (size == 0)
		return (1);
	if (size == 1)
		return (go_cmds(a, b, "pa"));
	if (size == 2)
	{
		if (b->head->data > b->head->next->data)
			return (go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
		return (go_cmds(0, b, "sb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa"));
	}
	if (size == 3 && b->size == 3)
		return (sort_b_of_size_3(a, b));
	if (size == 3)
		return (sort_b_of_rng_3(a, b));
	return (0);
}
