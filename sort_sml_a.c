/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sml_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:01:53 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/22 17:11:06 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_a_of_size_4(t_dq *a, t_dq *b, int min);
static int	sort_a_of_size_3(t_dq *a);

static int	sort_a_of_size_5(t_dq *a, t_dq *b, int min)
{
	t_node	*here;
	int		cnt;

	here = a->head;
	cnt = 0;
	while (here && here->data != min)
	{
		cnt++;
		here = here->next;
	}
	if (cnt < 3)
	{
		while (cnt-- > 0)
			go_cmds(a, b, "ra");
		go_cmds(a, b, "pb");
	}
	if (cnt >= 3)
	{
		while (cnt++ < 5)
			go_cmds(a, b, "rra");
		go_cmds(a, b, "pb");
	}
	return (sort_a_of_size_4(a, b, 1) & go_cmds(a, b, "pa"));
}

static int	sort_a_of_size_4(t_dq *a, t_dq *b, int min)
{
	t_node	*here;
	int		cnt;

	here = a->head;
	cnt = 0;
	while (here && here->data != min)
	{
		cnt++;
		here = here->next;
	}
	if (cnt < 2)
	{
		while (cnt-- > 0)
			go_cmds(a, b, "ra");
		go_cmds(a, b, "pb");
	}
	if (cnt >= 2)
	{
		while (cnt++ < 4)
			go_cmds(a, b, "rra");
		go_cmds(a, b, "pb");
	}
	return (sort_a_of_size_3(a) & go_cmds(a, b, "pa"));
}

static int	sort_a_of_size_3(t_dq *a)
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

static int	sort_a_of_rng_3(t_dq *a)
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

int	sort_sml_a(t_dq *a, int rng)
{
	if (is_asc(a, rng) || a->size == 0 || a->size == 1)
		return (1);
	if (rng == 2)
		return (go_cmds(a, 0, "sa"));
	if (rng == 3 && a->size == 3)
		return (sort_a_of_size_3(a));
	if (rng == 3)
		return (sort_a_of_rng_3(a));
	return (0);
}
