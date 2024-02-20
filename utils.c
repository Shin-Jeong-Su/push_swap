/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:09:19 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/20 17:58:09 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks push_swap");
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
	int		tmp;
	int		i;

	i = -1;
	pos = dq->head;
	tmp = dq->head->data;
	while (++i < size - 1 && pos->next)
	{
		if (tmp + 1 == pos->next->data)
		{
			tmp = pos->next->data;
			pos = pos->next;
		}
		else
			return (0);
	}
	return (1);
}
