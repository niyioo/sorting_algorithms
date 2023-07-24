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
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int j, i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, high + 1);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, high + 1);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive Quick sort function
 *
 * @array: The array to be sorted
 * @low: Starting index of the array to be sorted
 * @high: Ending index of the array to be sorted
 */
void quick_sort_recursive(int *array, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high);

		quick_sort_recursive(array, low, pi - 1);
		quick_sort_recursive(array, pi + 1, high);
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

	quick_sort_recursive(array, 0, size - 1);
}

