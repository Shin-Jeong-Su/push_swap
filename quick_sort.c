/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:06:01 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/21 16:11:52 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}

static void	partition(int *arr, int *pivot, int left, int right)
{
	int	low;
	int	high;

	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && arr[low] <= arr[*pivot])
			low++;
		while (high >= left + 1 && arr[high] >= arr[*pivot])
			high--;
		if (low < high)
			swap(&arr[low], &arr[high]);
	}
	swap(&arr[*pivot], &arr[high]);
	*pivot = high;
}

void	quick_sort(int *arr, int left, int right)
{
	int	pivot;

	pivot = left;
	if (left >= right)
		return ;
	partition(arr, &pivot, left, right);
	quick_sort(arr, left, pivot - 1);
	quick_sort(arr, pivot + 1, right);
}
