/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:58:41 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/09 16:06:41 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	take_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static int	is_in_int(char *str)
{
	if ((long long)ft_atoi(str) != ft_atol(str))
		return (0);
	else
		return (1);
}

static int	get_int_tab(int argc, char *argv[], int **tab)
{
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == 0)
			return (0);
		j = -1;
		while (argv[i][++j] != 0)
		{
			if (j == 0 && argv[i][j] == '-')
				continue ;
			if (!ft_isdigit(argv[i][j]))
				return (0);
		}
		if (!is_in_int(argv[i]))
			return (0);
		(*tab)[i - 1] = ft_atoi(argv[i]);
	}
	return (1);
}

static int	is_no_same_int(int size, int *tab)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] == tab[j])
				return (0);
		}
	}
	return (1);
}

void	init(int argc, char *argv[], t_dq *dq)
{
	int		i;
	int		*tab;

	tab = (int *)malloc(sizeof(int) * (argc - 1));
	if (!get_int_tab(argc, argv, &tab))
	{
		free(tab);
		take_error();
	}
	if (!is_no_same_int(argc - 1, tab))
	{
		free(tab);
		take_error();
	}
	init_dq(dq);
	i = -1;
	while (++i < argc - 1)
		push_back_dq(dq, tab[i]);
	free(tab);
}
