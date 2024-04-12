#include "sort.h"

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
	int i = lower;
	int j = lower;
	int pivot = array[bigger];
	int swap = array[i];

	for (j = lower; j < bigger; j++)
	{
		if (array[j] < pivot)
		{
			array[swap] = array[j];
			array[j] = array[i];
			array[i] = array[swap];
			
			if (array[i] != array[swap])
			{
				print_array(array, size);
			}
			++i;
		}
	}

	array[swap] = array[i];
	array[i] = array[bigger];
	array[bigger] = array[swap];

	if (array[i] != array[swap])
	{
		print_array(array, size);
	}
	return (i);
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

	if (lower > bigger)
	{
		return;
	}
	if (lower < 0)
	{
		return;
	}

	pivot = quick_sort_divide(array, lower, bigger, size);
	quick_sort_pivot(array, lower, pivot - 1, size);
	quick_sort_pivot(array, pivot + 1, bigger, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: pointer of the array be sorted
 * @size: size of number of elements in the array
*/

void quick_sort(int *array, size_t size)
{
	quick_sort_pivot(array, 0, size - 1, size);
}
