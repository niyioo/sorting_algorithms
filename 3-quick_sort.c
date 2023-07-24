#include "sort.h"

/**
 * swap - Swaps two elements in an array
 *
 * @a: Pointer to the first element to be swapped
 * @b: Pointer to the second element to be swapped
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme for Quick sort
 *
 * @array: The array to be partitioned
 * @size: The size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - Recursive Quick sort function
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: Starting index of the array to be sorted
 * @high: Ending index of the array to be sorted
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pi;

	if (high - low > 0)
	{
		pi = partition(array, size, low, high);

		quick_sort_recursive(array, size, low, pi - 1);
		quick_sort_recursive(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
