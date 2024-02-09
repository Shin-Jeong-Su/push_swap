/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:20:00 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/09 16:06:36 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_dq *stack)
{
	int		tmp;

	if (is_empty_dq(stack))
		return (0);
	tmp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = tmp;
	return (1);
}

int	push(t_dq *from, t_dq *to)
{
	int	from_data;

	if (is_empty_dq(from))
		return (0);
	from_data = front_dq(from);
	pop_front_dq(from);
	push_front_dq(to, from_data);
	return (1);
}

int	rotate(t_dq *stack, int reverse)
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

int	command(t_dq *a, t_dq *b, char *input)
{
	if (!ft_strncmp(input, "pa\n", 4))
		return (push(b, a));
	else if (!ft_strncmp(input, "pb\n", 4))
		return (push(a, b));
	else if (!ft_strncmp(input, "sa\n", 4))
		return (swap(a));
	else if (!ft_strncmp(input, "sb\n", 4))
		retrun (swap(b));
	else if (!ft_strncmp(input, "ss\n", 4))
		return (swap(a) & swap(b));
	else if (!ft_strncmp(input, "ra\n", 4))
		return (rotate(a, 0));
	else if (!ft_strncmp(input, "rb\n", 4))
		return (rotate(b, 0));
	else if (!ft_strncmp(input, "rr\n", 4))
		return (rotate(a, 0) & rotate(b, 0));
	else if (!ft_strncmp(input, "rra\n", 5))
		return (rotate(a, 1));
	else if (!ft_strncmp(input, "rrb\n", 5))
		return (rotate(b, 1));
	else if (!ft_strncmp(input, "rrr\n", 5))
		return (rotate(a, 1) & rotate(b, 1));
	take_error();
	return (0);
}
