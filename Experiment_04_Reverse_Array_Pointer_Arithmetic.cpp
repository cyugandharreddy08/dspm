#include <iostream> 
using namespace std; 

int main() 
{ 
    int n; 
    cout << "Enter the number of elements: "; 
    cin >> n; 

    if (n <= 0) {
        cout << "Invalid number of elements." << endl;
        return 1;
    }

    int* arr = new int[n]; 
    cout << "Enter " << n << " integers:\n"; 

    // Input using pointer arithmetic 
    for (int i = 0; i < n; i++) 
    { 
        cin >> *(arr + i); 
    } 

    // Reverse the array using pointers 
    int *start = arr; 
    int *end = arr + n - 1; 

    while (start < end) 
    { 
        int temp = *start; 
        *start = *end; 
        *end = temp; 
        start++; 
        end--; 
    } 

    cout << "Reversed array:\n"; 
    // Display using pointer arithmetic 
    for (int i = 0; i < n; i++) 
    { 
        cout << *(arr + i) << " "; 
    } 
    cout << endl;

    delete[] arr;
    return 0; 
}
