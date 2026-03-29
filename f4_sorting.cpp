#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool didSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        if (!didSwap)
        {
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}



void recursiveBubbleSort(int arr[],int n){
    if(n==1)return;
    bool didSwap = false;
    for(int i = 0; i < n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            didSwap = true;
        }
    }
    if(!didSwap)return;
    recursiveBubbleSort(arr,n-1);
}


void recursiveInsertionSort(int arr[],int i,int n){
    if(i == n)return;
    int key = arr [i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
    return recursiveInsertionSort(arr,i+1,n);

}


// During the loop this is always true
// arr[low ... i]        <= pivot
// arr[i+1 ... j-1]      > pivot
// arr[j ... high-1]     unknown
// arr[high]             pivot
int partition(int arr[],int l,int h){
    int pivot = arr[h];
    int i = l - 1;

    for(int j =l; j < h; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

void quickSort(int arr[],int l,int h){

    if(l >= h)return;
    int p = partition(arr,l,h);
    quickSort(arr,l,p-1);
    quickSort(arr,p+1,h);
}

int main()
{
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    // Selection Sort
    selectionSort(arr1, n);
    cout << "Sorted array: ";
    printArray(arr1, n);

    // // Bubble Sort
    int arr2[] = {5, 2, 9, 1, 5, 6};
    bubbleSort(arr2, n);
    cout << "Sorted array: ";
    printArray(arr2, n);

    // //Insertion Sort
    int arr3[] = {5, 2, 9, 1, 5, 6};
    insertionSort(arr3, n);
    cout << "Sorted array: ";
    printArray(arr3, n);

    // //Merge Sort
    int arr4[] = {5, 2, 9, 1, 5, 6};
    mergeSort(arr4,0,n-1);
    cout << "Sorted array: ";
    printArray(arr4,n);

    // //Recursive Bubble Sort
    int arr5[] = {5, 2, 9, 1, 5, 6};
    recursiveBubbleSort(arr5,n);
    cout << "Sorted array: ";
    printArray(arr5,n);

    // //Recursive Insertion
    int arr6[] = {5, 2, 9, 1, 5, 6};
    recursiveInsertionSort(arr6,0,n);
    cout << "Recursive Insertion Sorted array: ";
    printArray(arr6,n);

    // // Quick sort
    int arr7[] = {5, 2, 9, 1, 5, 6};
    quickSort(arr7,0,n-1);
    cout << "Sorted array: ";
    printArray(arr7,n);
}