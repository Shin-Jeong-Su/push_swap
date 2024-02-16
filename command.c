/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:20:58 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/15 14:59:22 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_dq *stack)
{
	int		tmp;

	if (is_empty_dq(stack))
		return (0);
	tmp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = tmp;
	return (1);
}

static int	push(t_dq *from, t_dq *to)
{
	int	from_data;

	if (is_empty_dq(from))
		return (0);
	from_data = front_dq(from);
	pop_front_dq(from);
	push_front_dq(to, from_data);
	return (1);
}

static int	rotate(t_dq *stack, int reverse)
{
	int		tmp;

	if (is_empty_dq(stack))
		return (0);
	if (reverse)
	{
		tmp = back_dq(stack);
		pop_back_dq(stack);
		push_front_dq(stack, tmp);
	}
	else
	{
		tmp = front_dq(stack);
		pop_front_dq(stack);
		push_back_dq(stack, tmp);
	}
	return (1);
}

static int	cmds(t_dq *a, t_dq *b, char *input, int i)
{
	write(1, input, ft_strlen(input));
	write(1, "\n", 1);
	if (i == 0)
		return (push(b, a));
	else if (i == 1)
		return (push(a, b));
	else if (i == 2)
		return (swap(a));
	else if (i == 3)
		return (swap(b));
	else if (i == 4)
		return (swap(a) & swap(b));
	else if (i == 5)
		return (rotate(a, 0));
	else if (i == 6)
		return (rotate(b, 0));
	else if (i == 7)
		return (rotate(a, 0) & rotate(b, 0));
	else if (i == 8)
		return (rotate(a, 1));
	else if (i == 9)
		return (rotate(b, 1));
	else if (i == 10)
		return (rotate(a, 1) & rotate(b, 1));
	return (0);
}

int	go_cmds(t_dq *a, t_dq *b, char *input)
{
	if (!ft_strncmp(input, "pa", 3))
		return (cmds(a, b, input, 0));
	else if (!ft_strncmp(input, "pb", 3))
		return (cmds(a, b, input, 1));
	else if (!ft_strncmp(input, "sa", 3))
		return (cmds(a, b, input, 2));
	else if (!ft_strncmp(input, "sb", 3))
		return (cmds(a, b, input, 3));
	else if (!ft_strncmp(input, "ss", 3))
		return (cmds(a, b, input, 4));
	else if (!ft_strncmp(input, "ra", 3))
		return (cmds(a, b, input, 5));
	else if (!ft_strncmp(input, "rb", 3))
		return (cmds(a, b, input, 6));
	else if (!ft_strncmp(input, "rr", 3))
		return (cmds(a, b, input, 7));
	else if (!ft_strncmp(input, "rra", 4))
		return (cmds(a, b, input, 8));
	else if (!ft_strncmp(input, "rrb", 4))
		return (cmds(a, b, input, 9));
	else if (!ft_strncmp(input, "rrr", 4))
		return (cmds(a, b, input, 10));
	return (0);
}
