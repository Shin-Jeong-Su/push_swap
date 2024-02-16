#include <stdio.h>
#include "../libft/libft.h"
int main(int ac,char **av){
	char **tab = ft_split(av[1],' ');
	while(*tab){
		printf("%s\t",*tab);
		tab++;
	}

}