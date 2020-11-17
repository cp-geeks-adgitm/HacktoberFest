// Author: Subhodeep Kundu
//Quick Sort
#include<iostream>
using namespace std;

int partition(int input[], int si, int ei)
{   int swap, temp;
    int i = si, j = ei;
    int smaller_count = 0;

    for (int m = si + 1; m <= ei; m++)
    {
        if (input[m] <= input[si])
        {
            smaller_count++ ;
        }
    }
    int  pivot = i + smaller_count ;
    temp = input[pivot];
    input[pivot] = input[si];
    input[si] = temp;



    while (i <= j)
    {
        if (input[i] <= input[pivot])
        {   i++;

        }
        else if (input[j] > input[pivot])
        {
            j--;
        }
        else {
            swap = input[i];
            input[i] = input[j];
            input[j] = swap;
            i++;
            j--;

        }
    }
    return pivot;
}
void helperquickSort(int input[], int si, int ei)
{
    if (si >= ei)
    {
        return ;
    }
    int pivot = partition(input, si, ei);
    helperquickSort(input, si, pivot - 1);
    helperquickSort(input, pivot + 1, ei);
}

void quickSort(int input[], int size) {
    int si = 0;
    int ei = size - 1;
    helperquickSort(input, si, ei);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    delete [] input;
}



