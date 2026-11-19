#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        cout << "Pass " << i + 1 << ": ";
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
    selectionSort(arr, n);

    cout << "\nSorted Array (Ascending Order):\n";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
