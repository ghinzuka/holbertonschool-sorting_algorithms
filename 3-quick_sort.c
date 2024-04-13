#include "sort.h"
#include <stdio.h>

/**
 * quick_sort_divide - divide the array into two parts to organize it
 * around the pivot
 * @array: pointer of the array be sorted
 * @lower: the lower element of the array
 * @bigger: the bigger element of the array
 * @size: size of the array
 * Return: i
*/

int quick_sort_divide(int *array, int lower, int bigger, size_t size)
{
	int i = lower - 1;
	int j;
	int pivot = array[bigger];
	int swap;

	for (j = lower; j < bigger; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap = array[i];
			array[i] = array[j];
			array[j] = swap;

			if (i != j)
			{
				print_array(array, size);
			}
		}

	}
	swap = array[i + 1];
	array[i + 1] = array[bigger];
	array[bigger] = swap;

	if (bigger != (i + 1))
	{
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_pivot - select an element in the array for being
 * the pivot of your function
 * @array: pointer of the array be sorted
 * @lower: the lower element of the array
 * @bigger: the bigger element of the array
 * @size: size of the array
*/

void quick_sort_pivot(int *array, int lower, int bigger, size_t size)
{
	int pivot;

	if (lower < bigger)
	{
		pivot = quick_sort_divide(array, lower, bigger, size);
		quick_sort_pivot(array, lower, pivot - 1, size);
		quick_sort_pivot(array, pivot + 1, bigger, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: pointer of the array be sorted
 * @size: size of number of elements in the array
*/

void quick_sort(int *array, size_t size)
{
	if (array != NULL || size > 2)
	{
		quick_sort_pivot(array, 0, size - 1, size);
	}
}
