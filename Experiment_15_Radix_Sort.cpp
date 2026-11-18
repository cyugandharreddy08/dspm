/*
 * ============================================================================
 * Experiment No. 15
 * Aim: To implement the Radix Sort algorithm for sorting integer data.
 * Course: Data Structures and Programming Methodology Laboratory (PCL03DSPM)
 * ============================================================================
 */

#include <iostream>
using namespace std;

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Function to find maximum element in array
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Stable counting sort according to digit represented by exp (1, 10, 100, ...)
void countingSort(int arr[], int n, int exp) {
    int* output = new int[n]; // Output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so that count[i] contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array (traverse in reverse to maintain stability)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

// Main Radix Sort function
void radixSort(int arr[], int n) {
    // Find the maximum number to know number of digits
    int maxVal = getMax(arr, n);

    // Do counting sort for every digit.
    // Note that instead of passing digit number, exp is passed (10^i)
    int pass = 1;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
        cout << "Pass " << pass << " (Digit place " << exp << "): ";
        printArray(arr, n);
        pass++;
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements.\n";
        return 1;
    }

    int* arr = new int[n];

    cout << "Enter " << n << " non-negative integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array:\n";
    printArray(arr, n);

    cout << "\nRadix Sort Passes:\n";
    radixSort(arr, n);

    cout << "\nSorted Array (Ascending Order):\n";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
