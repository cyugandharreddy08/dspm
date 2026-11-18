/*
 * ============================================================================
 * Experiment No. 3
 * Aim: To implement the addition of two univariate polynomials using an array 
 *      of structures.
 * Course: Data Structures and Programming Methodology Laboratory (PCL03DSPM)
 * ============================================================================
 */

#include <iostream> 
using namespace std; 
 
struct Term 
{ 
    int coeff; 
    int exp; 
}; 
 
void readPolynomial(Term poly[], int n) 
{ 
    cout << "Enter Coefficient and Exponent in descending order:\n"; 
 
    for (int i = 0; i < n; i++) 
    { 
        cout << "Term " << i + 1 << " : "; 
        cin >> poly[i].coeff >> poly[i].exp; 
    } 
} 
 
void displayPolynomial(Term poly[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        if (poly[i].coeff == 0) 
            continue; 
 
        cout << poly[i].coeff << "x^" << poly[i].exp; 
 
        if (i != n - 1) 
            cout << " + "; 
    } 
 
    cout << endl; 
} 
 
int addPolynomial(Term poly1[], int n1, Term poly2[], int n2, Term result[]) 
{ 
    int i = 0; 
    int j = 0; 
    int k = 0; 

    while (i < n1 && j < n2) 
    { 
        if (poly1[i].exp == poly2[j].exp) 
        { 
            result[k].coeff = poly1[i].coeff + poly2[j].coeff; 
            result[k].exp = poly1[i].exp; 
 
            i++; 
            j++; 
            k++; 
        } 
        else if (poly1[i].exp > poly2[j].exp) 
        { 
            result[k] = poly1[i]; 
            i++; 
            k++; 
        } 
        else 
        { 
            result[k] = poly2[j]; 
            j++; 
            k++; 
        } 
    } 
 
    while (i < n1) 
    { 
        result[k] = poly1[i]; 
        i++; 
        k++; 
    } 
 
    while (j < n2) 
    { 
        result[k] = poly2[j]; 
        j++; 
        k++; 
    } 
 
    return k; 
} 
 
int main() 
{ 
    int n1, n2; 
 
    Term poly1[20], poly2[20], result[40]; 
 
    cout << "Enter number of terms in First Polynomial: "; 
    cin >> n1; 
 
    readPolynomial(poly1, n1); 
 
    cout << "\nEnter number of terms in Second Polynomial: "; 
    cin >> n2; 
 
    readPolynomial(poly2, n2); 
 
    int size = addPolynomial(poly1, n1, poly2, n2, result); 
 
    cout << "\nFirst Polynomial:\n"; 
    displayPolynomial(poly1, n1); 
 
    cout << "\nSecond Polynomial:\n"; 
    displayPolynomial(poly2, n2); 
 
    cout << "\nResultant Polynomial:\n"; 
    displayPolynomial(result, size); 
 
    return 0; 
}
