#include <iostream>
using namespace std;

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Insertion Sort Function with pass-by-pass tracing
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Display pass information
        cout << "Pass " << i << " (Inserted " << key << "): ";
        printArray(arr, n);
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

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array:\n";
    printArray(arr, n);

    cout << "\nSorting Process (Passes):\n";
    insertionSort(arr, n);

    cout << "\nSorted Array (Ascending Order):\n";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
