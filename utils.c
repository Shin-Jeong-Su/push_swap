/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:09:19 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/23 17:15:28 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_int_rng(char *str, int size)
{
	char		*cmp;

	cmp = ft_itoa(ft_atoi(str));
	if ((size_t)size != ft_strlen(cmp))
	{
		free(cmp);
		return (0);
	}
	free(cmp);
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_all(char ***tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free_tab(tab[i]);
	free(tab);
}

void	take_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_asc(t_dq *dq, int size)
{
	t_node	*pos;
	int		cmp;
	int		i;

	i = -1;
	pos = dq->head;
	cmp = dq->head->data;
	while (++i < size - 1 && pos->next)
	{
		if (cmp + 1 == pos->next->data)
		{
			cmp = pos->next->data;
			pos = pos->next;
		}
		else
			return (0);
	}
	return (1);
}
