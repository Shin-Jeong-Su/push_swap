/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:20:48 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/16 20:22:43 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void get_pivot(t_idx_info *info, t_dq *dq, int rng)
{
	int		start;
	int		tmp;
	t_node *here;

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

static int	is_asc(t_dq *dq)
{
	t_node	*pos;
	int		tmp;

	pos = dq->head;
	tmp = dq->head->data;
	while (pos->next)
	{
		if (tmp < pos->next->data)
		{
			pos = pos->next;
			tmp = pos->data;
		}
		else
			return (0);
	}
	return (1);
}

//321, 312, 213, 231, 123, 132
static int	push_b_to_a(t_dq *a, t_dq *b)
{
	int	fir;
	int	sec;
	int	thr;
	
	fir = b->head->data;
	sec = b->head->next->data;
	thr = b->head->next->next->data;
//321 : pa pa pa;
	if (fir > sec && sec > thr)
		return (go_cmds(a, b , "pa") & go_cmds(a, b , "pa") & go_cmds(a, b , "pa"));
//312 : pa sb pa pa
	if (fir > thr && sec < thr)
		return (go_cmds(a, b , "pa") & go_cmds(0, b, "sb") & go_cmds(a, b , "pa") & go_cmds(a, b , "pa"));
//213 : rrb pa pa pa
	if (fir > sec && fir < thr)
		return (go_cmds(0, b, "rrb") & go_cmds(a, b, "pa") & go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
//231 : sb pa pa pa
	if (fir < sec && fir > thr)
		return (go_cmds(0, b , "sb") & go_cmds(a, b, "pa") & go_cmds(a, b , "pa") & go_cmds(a, b , "pa"));
//123 : rrb pa rrb pa pa
	if (fir < sec && sec < thr)
		return (go_cmds(0, b , "rrb") & go_cmds(a, b , "pa") & go_cmds(0, b, "rrb")\
		& go_cmds(a, b , "pa") &go_cmds(a, b , "pa"));
//132 : sb pa sb pa pa
	if (fir < sec && sec < thr)
		return (go_cmds(0, b , "sb") & go_cmds(a, b, "pa") & go_cmds(a, b , "sb") \
		& go_cmds(a, b , "pa"));
	return (0);
}

//123, 132 , 213, 231, 312, 321
static int	sort_a_of_size_3(t_dq *a)
{
	int	fir;
	int	sec;
	int	thr;

	fir = a->head->data;
	sec = a->head->next->data;
	thr = a->tail->data;
//123
	if (fir < sec && sec < thr)
		return (1);
//132 : ra sa rra
	else if (fir < thr && sec > thr)
		return (go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
//213 : sa
	else if (fir > sec && fir < thr)
		return (go_cmds(a, 0, "sa"));
//231 : ra sa rra sa
	else if (fir < sec && fir > thr)
		return (go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra") & go_cmds(a,0,"sa"));
//312 : sa ra sa rra
	else if (fir > thr && sec < thr)
		return (go_cmds(a, 0, "sa") & go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
//321 : ra sa rra sa ra sa rra
	else if (fir > sec && sec > thr)
		return (go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra") & go_cmds(a, 0, "sa") \
		& go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
	return (0);
}

int	sort_size_lower_than_3(t_dq *a, t_dq *b, int which, int size)
{
	//a일때
	if (which == A)
	{
		if (is_asc(a) || size == 0 || size == 1)
			return (1);
		else if (size == 2)
			return (go_cmds(a, 0, "sa"));
		return (sort_a_of_size_3(a));
	}
	//b일때
	if (size == 0)
		return (1);
	else if (size == 1)
		return (go_cmds(a, b , "pa"));
	else if (size == 2)
	{
		if (b->head->data > b->head->next->data)
			return (go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
		else
			return (go_cmds(0, b, "sb") & go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	}
	else if (size == 3)
		return (push_b_to_a(a, b));
	return (0);
}

void	init_idx_info(t_idx_info *info,t_dq *dq, int rng)
{
	get_pivot(info, dq, rng);
	info->pa_times=0;
	info->pb_times=0;
	info->ra_times=0;
	info->rb_times=0;
	info->data = front_dq(dq);
	info->rng = rng;
}