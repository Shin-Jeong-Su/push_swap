/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:59:50 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/21 19:39:29 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//big nums ko
int	main(int argc, char *argv[])
{
	t_dq	a;
	t_dq	b;

	if (!init(argc, argv, &a, &b))
	{
		take_error();
		return (0);
	}
	push_swap(&a, &b, a.size);
	clear_dq(&a);
	clear_dq(&b);
	return (0);
}
