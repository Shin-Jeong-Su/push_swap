#include <stdio.h>
# include "./libft/libft.h"
int main(){
	char *arr = "8 19 20 10 4 2 6 5 17 3 12 13 1 18 7 14 11 15 9 16";
	// char *arr = "30 52 79 0 6 16 24 86 59 72 95 80 65 4 18 98 37 67 33 54 73 26 56 90 58 23 40 84 29 75 61 13 1 8 35 48 11 20 39 89 3 41 68 85 71 92 87 28 32 93 91 55 2 27 66 22 34 21 44 62 82 17 31 78 9 50 49 53 7 94 47 60 97 25 63 14 76 5 36 57 19 88 77 70 83 69 51 81 10 46 45 74 12 43 15 99 38 64 96 42";
	int i=0;
	char **tab = ft_split(arr,' ');
	while(tab[i])
	{
		printf("\"%s\", " ,tab[i]);
		i++;
	}
}