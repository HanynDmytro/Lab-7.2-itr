#include <iostream>
#include <iomanip>
#include <time.h>
#include <climits> // для INT_MIN
using namespace std;

void Create(int** a, const int n, const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
bool SearchMaxSum(int** a, const int n, const int k, int& maxSum);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n, k;
    cout << "n = "; cin >> n;
    cout << "k = "; cin >> k;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[k];

    Create(a, n, k, Low, High);
    Print(a, n, k);

    int maxSum = 0;
    if (SearchMaxSum(a, n, k, maxSum))
        cout << "max sum = " << maxSum << endl;
    else
        cout << "there are no max elements" << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int k, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n, const int k)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool SearchMaxSum(int** a, const int n, const int k, int& maxSum)
{
    bool found = false; // для перевірки наявності парних рядків
    maxSum = 0;

    for (int i = 1; i < n; i += 2) { // обходимо тільки парні рядки
        int maxInRow = INT_MIN;
        for (int j = 0; j < k; j++) {
            if (a[i][j] > maxInRow) {
                maxInRow = a[i][j];
            }
        }
        maxSum += maxInRow;
        found = true;
    }

    return found;
}
