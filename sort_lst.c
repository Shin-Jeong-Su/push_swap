#include <stdio.h>
#include <stdlib.h>

typedef struct s_list{
	int 			data;
	struct s_list	*next;
}	t_list;

int asc(int fir, int sec){
	return (fir <= sec);
}

int dsc(int fir, int sec){
	return (fir >= sec);
}
void swap(t_list *fir, t_list *sec){
	int tmp = fir->data;
	fir->data = sec->data;
	sec->data = tmp;
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int)){
	t_list *here;
	t_list *there;
	t_list *tmp;

	here = lst;
	while (here){
		tmp = here;
		there = here->next;
		while (there){
			if(!cmp(tmp->data, there->data)){
				tmp = there;
			}
			there = there->next;
		}
		if (tmp != here)
			swap(here, tmp);
		here = here->next;
	}
	return (lst);
}

//////////////////////////test
#define size 5
#include <time.h>

int main(){

	t_list lst[size];
	srand(time(0));
	for(int i=0; i<size; i++){
		lst[i].data = rand()%9;
		if (i != size - 1)
			lst[i].next = &lst[i + 1];
		else
			lst[i].next = 0;
	}
//lst값  출력
	t_list *start = lst;
	while (start){
		printf("%d\t", start->data);
		start=start->next;
	}
	printf("\n");
	start = lst;
	printf("sorted! : \n");

//lst 정렬
	sort_list(lst,dsc);

//정렬된 lst확인
	while(start){
		printf("%d\t",start->data);
		start=start->next;
	}
}