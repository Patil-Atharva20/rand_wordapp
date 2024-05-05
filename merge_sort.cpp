#include <iostream>
using namespace std;

void merge(int array[], int l, int mid, int r);

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

void mergesort(int array[],  int l, int r)
{
    
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        mergesort(array,  l, mid);
        mergesort(array,  mid + 1, r);

        merge(array, l, mid, r);
    }
}

void merge(int array[], int l, int mid, int r)
{
    int n2 = r - mid;
    int n1 = mid - l + 1;

    int a[n1];// fine 
    int b[n2];// fine

    for (int i = 0; i < n1; i++)
    {
        a[i] = array[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        b[j] = array[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            array[k] = a[i];

            i++;
            k++;
        }

        else
        {
            array[k] = b[j];

            j++;
            k++;
        }
    }

    while (i < n1)
    {
        array[k] = a[i];

        i++;
        k++;
    }
    while (j < n2)
    {

        array[k] = b[j];

        j++;
        k++;
    }
}

int main()
{
    int array[] = {9, 8, 7, 6, 3, 2, 14, 16, 19, 24};
    int size = sizeof(array) / sizeof(array[0]);
    print(array, size);
    mergesort(array, 0, size - 1);
    print(array, size);
    return 0;
}
// done