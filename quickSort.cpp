#include <iostream>
#include <algorithm> // for std::swap
#include <vector>   // for std::vector

using namespace std;

// Function to choose a pivot using the median-of-three method
int medianOfThree(int arr[], int low, int mid, int high) {
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);
    // Place the pivot at the end
    swap(arr[mid], arr[high - 1]);
    return arr[high - 1]; // Return the pivot value
}

// A utility function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high - 1]; // Pivot is the element just before the high index
    int i = low; // Index of smaller element

    for (int j = low; j < high - 1; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high - 1]); // Move pivot to its final place
    return i; // Return the pivot index
}

// The main function that implements QuickSort
void quickSort(int arr[], int low, int high) {
    while (low < high) {
        // Calculate the middle index for median-of-three
        int mid = low + (high - low) / 2;
        int pivot = medianOfThree(arr, low, mid, high - 1);
        int pi = partition(arr, low, high);

        // Tail recursion optimization: Sort the smaller partition first
        if (pi - low < high - pi) {
            quickSort(arr, low, pi);
            low = pi + 1; // Iterative call for the right partition
        } else {
            quickSort(arr, pi + 1, high);
            high = pi; // Iterative call for the left partition
        }
    }
}

// Function to print an array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
