/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:54:53 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/20 19:57:14 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pa_rng_3(t_dq *a, t_dq *b)
{
	int	fir;
	int	sec;
	int	thr;

	fir = b->head->data;
	sec = b->head->next->data;
	thr = b->head->next->next->data;
	if (fir > sec && sec > thr)
		return (go_cmds(a, b, "pa")	& go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	if (fir > thr && sec < thr)
		return (go_cmds(a, b, "pa") & go_cmds(0, b, "sb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa"));
	if (fir > sec && fir < thr)
		return (go_cmds(0, b, "sb") & go_cmds(0, b, "rb") & go_cmds(0, b, "rb") \
		& go_cmds(a, b, "pa") & go_cmds(0, b, "rrb")& go_cmds(a, b, "pa") \
		& go_cmds(a, b, "rrb") & go_cmds(a, b, "pa"));
	if (fir < sec && fir > thr)
		return (go_cmds(0, b, "sb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	if (fir < sec && sec < thr)
		return (go_cmds(0, b, "rb") & go_cmds(0, b, "rb") & go_cmds(a, b, "pa") \
		& go_cmds(0, b, "rrb") & go_cmds(a, b, "pa") & go_cmds(0, b, "rrb") & go_cmds(a, b, "pa"));
	if (fir < thr && sec > thr)
		return (go_cmds(0, b, "sb") & go_cmds(a, b, "pa") & go_cmds(0, b, "sb") \
		& go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	return (0);
}

static int	pa_size_3(t_dq *a, t_dq *b)
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
		return (go_cmds(0, b, "rrb") & go_cmds(a, b, "pa")& go_cmds(a, b, "pa")& go_cmds(a, b, "pa"));
//231 : sb pa pa pa
	if (fir < sec && fir > thr)
		return (go_cmds(0, b , "sb") & go_cmds(a, b, "pa") & go_cmds(a, b , "pa") & go_cmds(a, b , "pa"));
//123 : rrb pa rrb pa pa
	if (fir < sec && sec < thr)
		return (go_cmds(0, b , "rrb") & go_cmds(a, b , "pa") & go_cmds(0, b, "rrb")\
		&go_cmds(a, b , "pa") &go_cmds(a, b , "pa"));
//132 : rb pa pa pa
	if (fir < thr && sec > thr)
		return (go_cmds(0, b , "rb") & go_cmds(a, b, "pa") & go_cmds(a, b , "pa") & go_cmds(a, b , "pa"));
	return (0);
}

static int	sort_a_of_rng_3(t_dq *a)
{
	int	fir;
	int	sec;
	int	thr;

	fir = a->head->data;
	sec = a->head->next->data;
	thr = a->head->next->next->data;
//123
	if (fir < sec && sec < thr)
		return (1);
//132 : ra sa rra
	if (fir < thr && sec > thr)
		return (go_cmds(a,0,"ra") &go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
//213 : sa
	if (fir > sec && fir < thr)
		return (go_cmds(a, 0, "sa"));
//231 : ra sa rra sa
	if (fir < sec && fir > thr)
		return (go_cmds(a, 0, "ra")&go_cmds(a, 0, "sa")&go_cmds(a, 0, "rra") &go_cmds(a, 0, "sa"));
//312 : sa ra sa rra
	if (fir > thr && sec < thr)
		return (go_cmds(a, 0, "sa") & go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
//321 : ra sa rra sa ra sa rra
	if (fir > sec && sec > thr)
		return (go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra") & go_cmds(a, 0, "sa") \
		& go_cmds(a, 0, "ra") & go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
	return (0);
}

int	sort_a_of_size_3(t_dq *a)
{
	int	fir;
	int	sec;
	int	thr;

	fir = a->head->data;
	sec = a->head->next->data;
	thr = a->head->next->next->data;
//123
	if (fir < sec && sec < thr)
		return (1);
//132 : sa rra
	if (fir < thr && sec > thr)
		return (go_cmds(a, 0, "sa") & go_cmds(a, 0, "ra"));
//213 : sa
	if (fir > sec && fir < thr)
		return (go_cmds(a, 0, "sa"));
//231 : rra
	if (fir < sec && fir > thr)
		return (go_cmds(a, 0, "rra"));
//312 : ra
	if (fir > thr && sec < thr)
		return (go_cmds(a, 0, "ra"));
//321 : sa rra
	if (fir > sec && sec > thr)
		return (go_cmds(a, 0, "sa") & go_cmds(a, 0, "rra"));
	return (0);

}

int	sort_size_lower_than_3(t_dq *a, t_dq *b, int which, int size)
{
	if (which == A)
	{
		if (is_asc(a, size) || size == 0 || size == 1)
			return (1);
		if (size == 2)
			return (go_cmds(a, 0, "sa"));
		if (size == 3 && a->size == 3)
			return (sort_a_of_size_3(a));
		return (sort_a_of_rng_3(a));
	}
	if (size == 0)
		return (1);
	if (size == 1)
		return (go_cmds(a, b , "pa"));
	if (size == 2)
	{
		if (b->head->data > b->head->next->data )
			return (go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
		else
			return (go_cmds(0, b, "sb") & go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
	}
	if (size == 3 && b->size == 3)
		return (pa_size_3(a, b));
	if (size == 3)
		return (pa_rng_3(a, b));
	return (0);
}