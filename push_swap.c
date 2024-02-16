/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:20:00 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/16 19:56:10 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_a(t_dq *a, t_dq *b, int rng);
static int	sort_b(t_dq *a, t_dq *b, int rng);

static void	retape(t_dq *a, t_dq *b, t_idx_info *info)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < info->ra_times && j < info->rb_times)
	{
		go_cmds(a, b, "rrr");
		i++;
		j++;
	}
	while (i < info->ra_times)
	{
		go_cmds(a, 0, "rra");
		i++;
	}
	while (j < info->rb_times)
	{
		go_cmds(0, b, "rrb");
		j++;
	}
}

//등호, 이해, 
static int	sort_a(t_dq *a, t_dq *b, int rng)
{
	t_idx_info	info;

	if (rng <= 3)
		return (sort_size_lower_than_3(a, b, A, rng));
	init_idx_info(&info, a, rng);
	while (rng--)
	{
		info.data = front_dq(a);
		if (info.data >= info.lrg_pivot)
			info.ra_times += go_cmds(a, b, "ra");
		else
		{
			info.pb_times += go_cmds(a, b, "pb");
			if (info.data >= info.sml_pivot)
				info.rb_times += go_cmds(a, b, "rb");
		}
	}
	retape(a, b, &info);
	sort_a(a, b, info.ra_times);
	sort_b(a, b, info.rb_times);
	sort_b(a, b, info.pb_times - info.rb_times);
	return (1);
}

static int	sort_b(t_dq *a, t_dq *b, int rng)
{
	t_idx_info	info;

	if (rng <= 3)
		return (sort_size_lower_than_3(a, b, B, rng));
	init_idx_info(&info, b, rng);
	while (rng--)
	{
		info.data = front_dq(b);
		if (info.data < info.sml_pivot)
			info.rb_times += go_cmds(a, b, "rb");
		else
		{
			info.pa_times += go_cmds(a, b, "pa");
			if (info.data < info.lrg_pivot)
				info.rb_times += go_cmds(a, b, "ra");
		}
	}
	sort_a(a, b, info.pa_times - info.ra_times);
	retape(a, b, &info);
	sort_a(a, b, info.ra_times);
	sort_b(a, b, info.rb_times);
	return (1);
}

int	push_swap(t_dq *a, t_dq *b, int size)
{
	if (size <= 3)
		return (sort_size_lower_than_3(a, b, A, a->size));
	else
		return (sort_a(a, b, a->size));
	return (1);
}
