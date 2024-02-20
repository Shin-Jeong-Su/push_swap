/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:59:50 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/20 13:16:09 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
//-2147483648 경우  
int		main(int argc, char *argv[])
{
	// atexit(check_leaks);
	// argv print
	////////////////////
	
	// printf("argv : \n");
	// printf("\n");
	// for (int i = 1 ; i < argc ; i++){
	// 	printf("%s\t", argv[i]);
	// }
	////////////////////

	// stack a init
	////////////////////
	t_dq a;
	t_dq b;
	if (!init(argc, argv, &a, &b))
	{
		take_error();
		return (0);
	}
	////////////////////

	// a print
	////////////////////
	// printf("\n");
	// printf("\n");
	// printf("a before sorted : \n");
	// printf("\n");
	// print_all_dq(&a);
	// printf("\n");
	// printf("\n");
	////////////////////

	//push_swap ////////////////////
	// printf("commands : \n");
	push_swap(&a, &b, a.size);
	// printf("\n");
	////////////////////


	// sorted a print
	////////////////////
	// printf("\n");
	// printf("\n");
	// printf("a after sorted : \n");
	// printf("\n");
	// print_all_dq(&a);

	// printf("\n");
	// printf("\n");
	////////////////////

	//check leaks
	////////////////////
	clear_dq(&a);
	clear_dq(&b);
	////////////////////
}