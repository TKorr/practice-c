// library of searching algorithms
#include <stdbool.h>
#include <math.h>

bool binary_search(int key, int array[], int min, int max);

// binary search
bool binary_search(int key, int array[], int min, int max) 
{
    // base case
    if (max < min) {
        return false;
    }
    else {
        // midpoint calculated this way to avoid arithmetic overflow for very large arrays
        int midpoint = round(min + (max - min) / 2);
        
        if (array[midpoint] < key) {
            return binary_search(key, array, midpoint + 1, max);
        }
        else if (array[midpoint] > key) {
            return binary_search(key, array, min, midpoint - 1);
        }
        else {
            return true;
        }
    }
} 
