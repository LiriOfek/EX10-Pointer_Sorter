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
#include <time.h>

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

void initiate_pointer_array(int array[SIZE], int *pointer_array[SIZE]) {
	/********************************************************\
	* Function name - initiate_pointer_array
	*
	* Function Purpose - initiate *pointer_array, so the each pointer 
	*					 points to int in array[] in random order,
	*					 such that won't be two pointers that point to the 
	*					 same element
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function changes *pointer_array[] to point on elements 
	*				 in array in random order
	*
	* Semantics - initiate *pointer_array, so the each pointer 
	*					 points to int in array[] in random order,
	*					 such that won't be two pointers that point to the 
	*					 same element
	*
	* Author - Liri
	\********************************************************/
	int index = 0;
	int index_in_array = 0;
	int array_of_indexes[SIZE]; /*array of indexes that have mapping
								between pointer to element in array[]*/

	/*initiate array indexes*/
	for (index = 0; index < SIZE; ++index) {
		array_of_indexes[index] = NOT_INDEX;
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

void initiate_int_array(int array[SIZE]) {
	/********************************************************\
	* Function name - initiate_int_array
	*
	* Function Purpose - initiate array[] with random ints, 
	*					 including negative numbers
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function changes array[] to contain random numbers,
	*
	* Semantics - initiate array[] with random ints,
	*			  incuding negative numbers
	*
	* Author - Liri
	\********************************************************/
	int index = 0;

	/*random values to the elements, including negative numbers*/
	srand((unsigned int)time(NULL));
	for (index = 0; index < SIZE; ++index) {
		array[index] = rand() % (RAND_MAX + ONE) - RAND_MAX / TWO;
	}

}

void print_index_address_value_of_pointers(int *pointer_array[SIZE]) {
	/********************************************************\
	* Function name - print_index_address_value_of_pointers
	*
	* Function Purpose - print the index, address and value
	*					 of each pointer in *pointer_array[]
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function has no side effect
	*
	* Semantics - print the index, address and value 
	*			  of each pointer in *pointer_array[]
	*
	* Author - Liri
	\********************************************************/
	int index = 0;
	for (index = 0; index < SIZE; ++index) {
		printf("%d : %p : %d\n",
			index,
			pointer_array[index],
			*pointer_array[index]);
	}
}

void main() {
	/********************************************************\
	* Function name - main
	*
	* Function Purpose - initiate array in size SIZE, that contain pointers to
	*					 addresses of int variables,
	*					 randomize the int variables,
	*					 print the index in array, the address, and the value
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - initiate array in size SIZE, that contain pointers to
	*			  addresses of int variables,
	*			  randomize the int variables,
	*			  print the index in array, the address, and the value
	*
	* Author - Liri
	\********************************************************/
	int *pointer_array[SIZE];
	int array[SIZE];

	initiate_int_array(array);

	initiate_pointer_array(array, pointer_array);

	print_index_address_value_of_pointers(pointer_array);
}