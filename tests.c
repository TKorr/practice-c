// sorting algorithms
#include <stdio.h>
#include "minunit.h"
#include "insertion_sort.c"
#include "selection_sort.c"
#include "binary_search.c"
#include "quicksort.c"
#include "merge_sort.c"


int tests_run = 0;

void insertion_sort(int input_array[], int length);
void insertion_sort_with_swap(int input_array[], int length);
void insertion_sort_recursive(int arr[], int length);
void selection_sort(int input_array[], int length);
void quicksort(int arr[], int p, int r);
void merge_sort(int arr[], int left_idx, int right_idx);

bool binary_search(int key, int array[], int min, int max);

//tests on sorts
static char * test_insertion_sort() 
{
  int test_data[5] = {6,2,1,3,8};
  insertion_sort(test_data, 5);

  printf("Test: quicksort...");
  mu_assert("\nerror: test_data[0] not sorted correctedly", test_data[0] == 1);
  mu_assert("\nerror: test_data[1] not sorted correctedly", test_data[1] == 2);
  mu_assert("\nerror: test_data[2] not sorted correctedly", test_data[2] == 3);
  mu_assert("\nerror: test_data[3] not sorted correctedly", test_data[3] == 6);
  mu_assert("\nerror: test_data[4] not sorted correctedly", test_data[4] == 8);
  printf("all Tests Passed\n");
  return 0;
}

static char * test_insertion_sort_with_swap() 
{
  int test_data[5] = {6,2,1,3,8};
  insertion_sort_with_swap(test_data, 5);

  printf("Test: insertion_sort_with_swap...");
  mu_assert("\nerror: test_data[0] not sorted correctedly", test_data[0] == 1);
  mu_assert("\nerror: test_data[1] not sorted correctedly", test_data[1] == 2);
  mu_assert("\nerror: test_data[2] not sorted correctedly", test_data[2] == 3);
  mu_assert("\nerror: test_data[3] not sorted correctedly", test_data[3] == 6);
  mu_assert("\nerror: test_data[4] not sorted correctedly", test_data[4] == 8);
  printf("all Tests Passed\n");
  return 0;
}

static char * test_insertion_sort_recursive() 
{
  int test_data[5] = {6,2,1,3,8};
  insertion_sort_recursive(test_data, 5);

  printf("Test: test_insertion_sort_recursive...");
  mu_assert("\nerror: test_data[0] not sorted correctedly", test_data[0] == 1);
  mu_assert("\nerror: test_data[1] not sorted correctedly", test_data[1] == 2);
  mu_assert("\nerror: test_data[2] not sorted correctedly", test_data[2] == 3);
  mu_assert("\nerror: test_data[3] not sorted correctedly", test_data[3] == 6);
  mu_assert("\nerror: test_data[4] not sorted correctedly", test_data[4] == 8);
  printf("all Tests Passed\n");
  return 0;
}

static char * test_selection_sort() 
{
  int test_data[5] = {6,2,1,3,8};
  selection_sort(test_data, 5);

  printf("Test: selection_sort...");
  mu_assert("\nerror: test_data[0] not sorted correctedly", test_data[0] == 1);
  mu_assert("\nerror: test_data[1] not sorted correctedly", test_data[1] == 2);
  mu_assert("\nerror: test_data[2] not sorted correctedly", test_data[2] == 3);
  mu_assert("\nerror: test_data[3] not sorted correctedly", test_data[3] == 6);
  mu_assert("\nerror: test_data[4] not sorted correctedly", test_data[4] == 8);
  printf("all Tests Passed\n");
  return 0;
}

static char * test_quicksort() 
{
  int test_data[5] = {6,2,1,3,8};
  quicksort(test_data, 0, 4);

  printf("Test: quicksort...");
  mu_assert("\nerror: test_data[0] not sorted correctedly", test_data[0] == 1);
  mu_assert("\nerror: test_data[1] not sorted correctedly", test_data[1] == 2);
  mu_assert("\nerror: test_data[2] not sorted correctedly", test_data[2] == 3);
  mu_assert("\nerror: test_data[3] not sorted correctedly", test_data[3] == 6);
  mu_assert("\nerror: test_data[4] not sorted correctedly", test_data[4] == 8);
  printf("all Tests Passed\n");
  return 0;
}

static char * test_merge_sort() 
{
  printf("Test: merge_sort...");
  
  int test_data[5] = {6,2,1,3,8};
  merge_sort(test_data, 0, 4);
  mu_assert("\nerror: test_data[0] not sorted correctedly", test_data[0] == 1);
  mu_assert("\nerror: test_data[1] not sorted correctedly", test_data[1] == 2);
  mu_assert("\nerror: test_data[2] not sorted correctedly", test_data[2] == 3);
  mu_assert("\nerror: test_data[3] not sorted correctedly", test_data[3] == 6);
  mu_assert("\nerror: test_data[4] not sorted correctedly", test_data[4] == 8);

  int test_data2[10] = {9,8,7,6,5,5,4,3,2,1};
  merge_sort(test_data2, 0, 9);
  mu_assert("\nerror: test_data2[0] not sorted correctedly", test_data2[0] == 1);
  mu_assert("\nerror: test_data2[5] not sorted correctedly", test_data2[5] == 5);
  mu_assert("\nerror: test_data2[9] not sorted correctedly", test_data2[9] == 9);
  
  printf("all Tests Passed\n");
  return 0;
}


static char * test_binary_search()
{
  int test_data[5] = {6,2,1,3,8};

  printf("Test: binary_search...");
  mu_assert("\nerror: binary_search", binary_search(8, test_data, 0, 4) == true);
  mu_assert("\nerror: binary_search, the number 7 is not present in array", binary_search(7, test_data, 0, 4) == false);
  printf("all Tests Passed\n");
  return 0;
}


static char * all_tests()
{
  printf("Starting...all tests\n\n");
  mu_run_test(test_insertion_sort);
  mu_run_test(test_insertion_sort_with_swap);
  //mu_run_test(test_insertion_sort_recursive);
  mu_run_test(test_selection_sort);
  mu_run_test(test_quicksort);
  mu_run_test(test_merge_sort);
  mu_run_test(test_binary_search);
  return 0;
}

int main(int argc, char **argv) {
     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("\nALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
}