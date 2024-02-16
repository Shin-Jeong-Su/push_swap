/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:59:50 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/16 20:23:10 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//push_swap {int set}이 들어옴. 중복안됨, 인트형 범위안. "" 공백또는 a 와 같은 문자 안됨.

//dq를 한다고 쳐. dq구조를 이용한 알고리즘은 어떤 알고리즘 사용?

//비교 알고리즘은 nlong이 한계. 그 예로는 병합과 퀵. 공통점은 divide-conquer사용.
//따라서 divide-conqure로 push_swap을 구현해보자.

//퀵솔트 구현하려면 partition하고 큰거 아래 재귀로 

//백트래킹?

//./a.out "1 3 4 1 4 1 "- > has leak

int		main(int argc, char *argv[])
{
	// argv print
	////////////////////
	printf("argv : \n");
	printf("\n");
	for (int i = 1 ; i < argc ; i++){
		printf("%s", argv[i]);
	}
	////////////////////

	// stack a init
	////////////////////
	t_dq a;
	t_dq b;
	init(argc, argv, &a, &b);
	////////////////////

	// a print
	////////////////////
	printf("\n");
	printf("\n");
	printf("a before sorted : \n");
	printf("\n");
	print_all_dq(&a);
	printf("\n");
	printf("\n");
	////////////////////

	//push_swap
	////////////////////
	printf("commands : \n");
	push_swap(&a, &b, a.size);
	printf("\n");
	////////////////////


	// sorted a print
	////////////////////
	printf("\n");
	printf("\n");
	printf("a after sorted : \n");
	printf("\n");
	print_all_dq(&a);

	printf("\n");
	printf("\n");
	////////////////////

	//check leaks
	////////////////////
	clear_dq(&a);
	clear_dq(&b);
	atexit(check_leaks);
	////////////////////
}