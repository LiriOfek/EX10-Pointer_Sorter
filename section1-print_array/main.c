/********************************************************\
File Name: main.c
Author: Liri (10/4/2020)
Purpose: This file initiate array in size 10, that contain pointers to
		 addresses of 10 int variables, randomize the int variables,
		 print the index in array, the address, and the value	
\********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE (10)
#define INITIAL_INDEX (0)
#define INITIAL_NUMBER (0)
#define NOT_INDEX (-1)
#define ONE (1)
#define TWO (2)

bool number_in_array(int number, int array[SIZE]) {
	/********************************************************\
	* Function name - number_in_array
	*
	* Function Purpose - check if number in array
	*
	* Parameters - IN int number - the number that want to check if
	*								in array
	*			   IN int int array[SIZE] - array of numbers
	*
	* Return Value - true - if the number in array
	*				 false - otherwise
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function check if a given number
	*				is in a given array
	*
	* Author - Liri
	\********************************************************/
	int index = 0;
	for (index = 0; index < SIZE; ++index) {
		if (number == array[index])
		{
			return true;
		}
	}
	return false;
}

void initiate_int_array_and_pointer_array(int array[SIZE], int *pointer_array[SIZE]) {
	/********************************************************\
	* Function name - initiate_int_array_and_pointer_array
	*
	* Function Purpose - initiate array in size SIZE, that contain pointers to
	*					 addresses of int variables,
	*					 randomize the int variables,
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function changes array[] to contain random numbers,
	*				 and change *pointer_array[] to point on elements in
	*				 array in random order
	*
	* Semantics - initiate array in size SIZE, that contain pointers to
	*			  addresses of int variables,
	*			  randomize the int variables, and randomize the order
	*			  of the pointers
	*
	* Author - Liri
	\********************************************************/
	int index = 0;
	int index_in_array = 0;
	int array_of_indexes[SIZE];

	/*initiate array indexes*/
	for (index = 0; index < SIZE; ++index) {
		array[index] = NOT_INDEX;
	}

	/*random values to the elements, including negative numbers*/
	for (index = 0; index < SIZE; ++index) {
		array[index] = rand() % (RAND_MAX + ONE) - RAND_MAX / TWO;
	}

	/*pointers to the int variables in different from the order that
	the variables were defined*/
	for (index = 0; index < SIZE; ++index) {
		while (1) {

			/*randomize the order of the pointers*/
			index_in_array = rand() % SIZE;

			/*there won't be two pointers that point to the same int*/
			if (number_in_array(index_in_array, array_of_indexes) == false)
			{
				break;
			}
		}

		/*assigning the address of the integer*/
		pointer_array[index] = &array[index_in_array];

		/*add to array of indexes that have already been*/
		array_of_indexes[index] = index_in_array;
	}
}