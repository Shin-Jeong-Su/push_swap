/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:59:50 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/09 15:23:24 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//stack 에 담기
//dq를 한다고 쳐. dq구조를 이용한 알고리즘은 어떤 알고리즘 사용?
//정렬 시복 최대 nlogn 중복없음므로 퀵솔트.
//퀵솔트 구현하려면 나누고 
#include <stdio.h>
int main(int argc, char *argv[])
{
	printf("argv : \n");
	for(int i=1;i<argc;i++){
		printf("%s\t",argv[i]);
	}
	printf("\n");
	t_dq a;
	init(argc,argv,&a);
	printf("in dq : \n");
	while(!is_dq_empty(&a)){
		printf("%d\t",front_dq(&a));
		pop_front_dq(&a);
	}
	// system("leaks a.out");
}