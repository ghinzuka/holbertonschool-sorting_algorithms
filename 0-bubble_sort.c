#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array of integer
 * @size: size of array
 *
*/
void bubble_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i = 0;
	size_t j = 0;

		while (array && i < size - 1)
		{
			j = 0;
				while (j < size - i - 1)
				{
				if (array[j] > array[j + 1])
				{
					temp = array[j + 1];
					array[j + 1] = array[j];
					array[j] = temp;
					print_array(array, size);
				}
				j++;
				}
		i++;
		}
}
