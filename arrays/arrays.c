#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Array {
  int capacity;  // How many elements can this array hold?
  int count;  // How many states does the array currently hold?
  char **elements;  // The string elements contained in the array
} Array;


/************************************
 *
 *   CREATE, DESTROY, RESIZE FUNCTIONS
 *
 ************************************/

/*****
 * Allocate memory for a new array
 *****/
Array *create_array (int capacity) {
  // Allocate memory for the Array struct
  Array *arr = malloc(sizeof(Array));
  // Set initial values for capacity and count
  // arr->capacity is the same as (*arr).capacity (point to struct's things not arr's)

  // if pointer to struct = ->
  // if struct itself = . 
  arr->capacity = capacity;
  arr->count = 0;

  // Allocate memory for elements (the individual arrays)
  arr->elements = malloc(capacity * sizeof(char *));

  return arr;

}


/*****
 * Free memory for an array and all of its stored elements
 *****/
void destroy_array(Array *arr) {

  // Free all elements, first each item, then the element, then array
  // bc we allocate memory with strdup so we need to free that
  for (int i = 0; i < arr->count; i++) {
    if (arr->elements[i] != '/0') {
    free(arr->elements[i]);
    }
  }

  free(arr->elements);

  // Free array
  free(arr);

}

/*****
 * Create a new elements array with double capacity and copy elements
 * from old to new
 *****/
void resize_array(Array *arr) {

  // Create a new element storage with double capacity

  // Copy elements into the new storage

  // Free the old elements array (but NOT the strings they point to)

  // Update the elements and capacity to new values

}



/************************************
 *
 *   ARRAY FUNCTIONS
 *
 ************************************/

/*****
 * Return the element in the array at the given index.
 *
 * Throw an error if the index is out of range.
 *****/
char *arr_read(Array *arr, int index) {

  // Throw an error if the index is greater or equal to than the current count
  if (index >= arr->count) {
    printf("Error: index out of range");
    return NULL;
  }

  // Otherwise, return the element at the given index
  return arr->elements[index];
}


/*****
 * Insert an element to the array at the given index
 *****/
void arr_insert(Array *arr, char *element, int index) {

  // Throw an error if the index is greater than the current count

  // Resize the array if the number of elements is over capacity

  // Move every element after the insert index to the right one position

  // Copy the element and add it to the array

  // Increment count by 1

}

/*****
 * Append an element to the end of the array
 *****/
void arr_append(Array *arr, char *element) {

  // Resize the array if the number of elements is over capacity
  // or throw an error if resize isn't implemented yet.
  if (arr->capacity <= arr->count) {
    // resize_array(arr) 
    // Can add this when resize_array is implemented. 
    fprintf(stderr, "IndexError: Index is out of range");
    return;
  }

  // Copy the element and add it to the end of the array
  // strdup is the same as malloc/strcopy allocates new block of memory that is 
  // the same size as the string and copies all the bytes from one to the other
  char *new_element = strdup(element);
  arr->elements[arr->count] = new_element;

  // The following line would be incorrect because it that would just be pointing 
  // to the original element which would result in an invalid array if that element 
  // ever gets deleted/changed. Might be what you want but copying to be safe. 
  // char *new_element = element

  // Increment count by 1
  arr->count++;

}

/*****
 * Remove the first occurrence of the given element from the array,
 * then shift every element after that occurrence to the left one slot.
 *
 * Throw an error if the value is not found.
 *****/
void arr_remove(Array *arr, char *element) {

  // Search for the first occurence of the element and remove it.
  // Don't forget to free its memory!

  // Shift over every element after the removed element to the left one position

  // Decrement count by 1

}


/*****
 * Utility function to print an array.
 *****/
void arr_print(Array *arr) {
  printf("[");
  for (int i = 0 ; i < arr->count ; i++) {
    printf("%s", arr->elements[i]);
    if (i != arr->count - 1) {
      printf(",");
    }
  }
  printf("]\n");
}


#ifndef TESTING
int main(void)
{

  Array *arr = create_array(1);

  //Check if capacity & count are set correctly
  printf("%d, %d\n", arr->capacity, arr->count);

  arr_insert(arr, "STRING1", 0);
  arr_append(arr, "STRING4");
  arr_insert(arr, "STRING2", 0);
  arr_insert(arr, "STRING3", 1);
  arr_print(arr);
  arr_remove(arr, "STRING3");
  arr_print(arr);

  destroy_array(arr);

  return 0;
}
#endif
