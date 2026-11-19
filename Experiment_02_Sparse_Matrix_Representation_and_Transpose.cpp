#include <iostream>
using namespace std;

int main()
{
    int row, col;
    int matrix[20][20];
    int compact[100][3];
    int transpose[100][3];
    int zero = 0, nonZero = 0;

    cout << "Enter number of rows: ";
    cin >> row;

    cout << "Enter number of columns: ";
    cin >> col;

    cout << "\nEnter matrix elements:\n";

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];

            if(matrix[i][j] == 0)
                zero++;
            else
                nonZero++;
        }
    }

    if(zero <= nonZero)
    {
        cout << "\nThe given matrix is NOT a Sparse Matrix.\n";
        return 0;
    }

    cout << "\nThe given matrix is a Sparse Matrix.\n";

    compact[0][0] = row;
    compact[0][1] = col;
    compact[0][2] = nonZero;

    int k = 1;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(matrix[i][j] != 0)
            {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    cout << "\nCompact Representation\n";
    cout << "Row\tColumn\tValue\n";

    for(int i = 0; i <= nonZero; i++)
    {
        cout << compact[i][0] << "\t"
             << compact[i][1] << "\t"
             << compact[i][2] << endl;
    }

    transpose[0][0] = compact[0][1];
    transpose[0][1] = compact[0][0];
    transpose[0][2] = compact[0][2];

    k = 1;

    for(int c = 0; c < col; c++)
    {
        for(int i = 1; i <= nonZero; i++)
        {
            if(compact[i][1] == c)
            {
                transpose[k][0] = compact[i][1];
                transpose[k][1] = compact[i][0];
                transpose[k][2] = compact[i][2];
                k++;
            }
        }
    }

    cout << "\nTranspose (Compact Representation)\n";
    cout << "Row\tColumn\tValue\n";

    for(int i = 0; i <= nonZero; i++)
    {
        cout << transpose[i][0] << "\t"
             << transpose[i][1] << "\t"
             << transpose[i][2] << endl;
    }

    return 0;
}
