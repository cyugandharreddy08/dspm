#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void displayArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, key;

    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int* arr = new int[n];

    srand(time(NULL));

    cout << "\nGenerated Array:\n";
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    cout << "\n";

    clock_t startBubble = clock();
    bubbleSort(arr, n);
    clock_t endBubble = clock();

    double bubbleTime = double(endBubble - startBubble) / CLOCKS_PER_SEC;

    cout << "\nSorted Array:\n";
    displayArray(arr, n);

    cout << "\nEnter the element to search: ";
    cin >> key;

    clock_t startLinear = clock();
    int linearResult = linearSearch(arr, n, key);
    clock_t endLinear = clock();

    double linearTime = double(endLinear - startLinear) / CLOCKS_PER_SEC;

    clock_t startBinary = clock();
    int binaryResult = binarySearch(arr, n, key);
    clock_t endBinary = clock();

    double binaryTime = double(endBinary - startBinary) / CLOCKS_PER_SEC;

    cout << "\n----- Linear Search -----\n";
    if(linearResult != -1)
        cout << "Element found at position " << linearResult + 1 << endl;
    else
        cout << "Element not found." << endl;

    cout << "\n----- Binary Search -----\n";
    if(binaryResult != -1)
        cout << "Element found at position " << binaryResult + 1 << endl;
    else
        cout << "Element not found." << endl;

    cout << "\nExecution Time\n";
    cout << "Bubble Sort  : " << bubbleTime << " seconds\n";
    cout << "Linear Search: " << linearTime << " seconds\n";
    cout << "Binary Search: " << binaryTime << " seconds\n";

    delete[] arr;
    return 0;
}
