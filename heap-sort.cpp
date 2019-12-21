#include <iostream>
#include <fstream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest, l, r;
    largest = i;
    l = 2*i + 1;
    r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
       swap(arr[i], arr[largest]);
       heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = (n/2)-1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = { 8, 3, 2, 7, 9, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sort: " << endl;
    print_array(arr, n);

    heap_sort(arr, n);

    cout << "\nSorted array is: " << endl;
    print_array(arr, n);

    cout << endl;
    return 0;
}
