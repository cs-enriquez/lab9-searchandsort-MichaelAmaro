#include <iostream>
#include <string>
using namespace std;

// write a function to print the contents of your array
// bonus! try to implement your function so that it can accept
// many types of data (int, char, string, etc.)
template <typename flexibleType> // ???
void printArray(flexibleType arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
// within the indices of "start" to "end"
// return true if target exists in the array within this range,
// return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

// Implement an iterative binary search
// Return true if target exists in the array with size n,
// return false otherwise
bool binSearch(float target, float arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

// Implement a recursive binary search
// Return true if target exists in the array with size n
// return false otherwise
bool binSearchR(char target, char charray[], int n) {
    // base case
    if (n == 0) {
        return false;
    }
    //general case
    int mid = n / 2;
    if (charray[mid] == target) {
        return true;
    } else if (charray[mid] < target) {
        return binSearchR(target, charray + mid + 1, n - mid - 1);
    } else {
        return binSearchR(target, charray, mid);
    }
}

// Implement a brand new sorting algorithm
// Don't use a reference for this!
// Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a "swap" function that will swap any two elements in an array,
// given their indices
// Step 2: implement a function that can find and return
// the smallest element in an array
/*
Step 3: Finally, use your functions to complete the following:
1 - search through the array to find the smallest value
2 - use your swap to bring this value to the start of the array
3 - the first element is now sorted. Redo your sort on the remaining
elements (from index 1 to end)
4 - continue iterating until you reach the end of the list
*** You can make this recursive, if you wish!
*/
void swap(double darray[], int i, int j) {
    double temp = darray[i];
    darray[i] = darray[j];
    darray[j] = temp;
}

int minFind(double darray[], int start, int end) {
    int min = start;
    for (int i = start + 1; i <= end; i++) {
        if (darray[i] < darray[min]) {
            min = i;
        }
    }
    return min;
}

void newSort(double darray[], int n) {
    for (int i = 0; i < n; i++) {
        int min = minFind(darray, i, n - 1);
        swap(darray, i, min);
    }
}
