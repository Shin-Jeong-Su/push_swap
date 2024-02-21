/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:54:53 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/21 20:25:46 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_b_of_rng_3(t_dq *a, t_dq *b)
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

int	sort_b_of_size_3(t_dq *a, t_dq *b)
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

int	sort_a_of_rng_3(t_dq *a)
{
	t_3n	cmps;

	init_3n(a, &cmps);
	if (cmps.fir < cmps.sec && cmps.sec < cmps.thr)
		return (1);
	if (cmps.fir < cmps.thr && cmps.sec > cmps.thr)
		return (go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") \
		& go_cmds(a, 0, "rra"));
	if (cmps.fir > cmps.sec && cmps.fir < cmps.thr)
		return (go_cmds(a, 0, "sa"));
	if (cmps.fir < cmps.sec && cmps.fir > cmps.thr)
		return (go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") \
		& go_cmds(a, 0, "rra") & go_cmds(a, 0, "sa"));
	if (cmps.fir > cmps.thr && cmps.sec < cmps.thr)
		return (go_cmds(a, 0, "sa") & go_cmds(a, 0, "ra") \
		& go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
	if (cmps.fir > cmps.sec && cmps.sec > cmps.thr)
		return (go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") \
		& go_cmds(a, 0, "rra") & go_cmds(a, 0, "sa") \
		& go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
	return (0);
}

int	sort_a_of_size_3(t_dq *a)
{
	t_3n	cmps;

	init_3n(a, &cmps);
	if (cmps.fir < cmps.sec && cmps.sec < cmps.thr)
		return (1);
	if (cmps.fir < cmps.thr && cmps.sec > cmps.thr)
		return (go_cmds(a, 0, "sa") & go_cmds(a, 0, "ra"));
	if (cmps.fir > cmps.sec && cmps.fir < cmps.thr)
		return (go_cmds(a, 0, "sa"));
	if (cmps.fir < cmps.sec && cmps.fir > cmps.thr)
		return (go_cmds(a, 0, "rra"));
	if (cmps.fir > cmps.thr && cmps.sec < cmps.thr)
		return (go_cmds(a, 0, "ra"));
	if (cmps.fir > cmps.sec && cmps.sec > cmps.thr)
		return (go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
	return (0);
}

int	sort_sml_than_3(t_dq *a, t_dq *b, int which, int size)
{
	if (which == A)
		return (sort_sml_a(a, size));
	if (which == B)
		return (sort_sml_b(a, b, size));
	return (0);
}
