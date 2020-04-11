/********************************************************\
File Name: main.c
Author: Liri (11/4/2020)
Purpose: This file initiate array in size 10, that contain pointers to
		 addresses of 10 int variables, randomize the int variables,
		 print the index in array, the address, and the value,
		 and sort the values of pointer array by swap values
\********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE (10)
#define INITIAL_INDEX (0)
#define INITIAL_NUMBER (0)
#define NOT_INDEX (-1)
#define ONE (1)
#define TWO (2)

void bubble_sort_by_swap_values(int *pointer_array[SIZE], int size_of_array)
{
	/********************************************************\
	* Function name - bubble_sort
	*
	* Function Purpose - sort given array in ascending order
	*
	* Parameters - IN *pointer_array[SIZE] - the pointer to the array
	*										that need to be sorted
	*			   IN int size_of_array - the size of the given array
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function change the given array
	*				 sort the given array, by swap the values
	*
	* Semantics - this function sort the given array
	*				in ascending order of the elements,
	*				by swap the values
	*
	* Author - Liri
	\********************************************************/
	int external_index = INITIAL_INDEX;
	int internal_index = INITIAL_INDEX;
	int swapping_element; /*value of element to swap*/

	for (external_index = 0; external_index < size_of_array - 1; ++external_index)
	{
		for (internal_index = 0; internal_index < size_of_array - external_index - 1; ++internal_index)
		{
			if (*pointer_array[internal_index] > *pointer_array[internal_index + 1])
			{
				/*value of next element is smaller than the current ->
				swapping values*/
				swapping_element = *pointer_array[internal_index];
				*pointer_array[internal_index] = *pointer_array[internal_index + 1];
				*pointer_array[internal_index + 1] = swapping_element;
			}
		}
	}
}