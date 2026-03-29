#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void print_array(int arr[], int size)
{
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void largest_element(int arr[], int size)
{
    int largest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "Largest element in the array is: " << largest << endl;
}

void second_largest_element(int arr[], int n)
{
    int largest = arr[0];
    int second_largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }
    cout << "Second largest element in the array is: " << second_largest << endl;
}

// imagine a line graph with points (x, y) where x is the index of the array and y is the value of the element at that index.
// If the line graph is increasing or flat, then the array is sorted in non-decreasing order.
//  If there is any point where the line graph goes down, then the array is not sorted.
bool is_sorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void remove_duplicates(int arr[], int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
}

void left_rotate(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

void reverse(int arr[], int l, int r)
{
    while (l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void left_rotate_by_k(int arr[], int n, int k)
{
    k = k % n;
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

void move_zeroes(int arr[], int n)
{

    int l = 0;

    for (int r = 0; r < n; r++)
    {
        if (arr[r] != 0)
        {
            swap(arr[l], arr[r]);
            l++;
        }
    }
}

void find_missing_number(int arr[], int n)
{
    int missing_number = n;
    for (int i = 0; i < n; i++)
    {
        missing_number ^= i ^ arr[i];
    }
    cout << "Missing number in the array is: " << missing_number << endl;
}

void linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found in the array." << endl;
}

void union_of_two_sorted_arrays(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0;
    cout << "Union of the two sorted arrays is: ";
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            cout << arr2[j] << " ";
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    while (i < n1)
    {
        cout << arr1[i] << " ";
        i++;
    }
    while (j < n2)
    {
        cout << arr2[j] << " ";
        j++;
    }
    cout << endl;
}

void max_consecutive_ones(int arr[], int n)
{
    int max_count = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            max_count = max(max_count, count);
            count = 0;
        }
    }
    max_count = max(max_count, count);
    cout << "Maximum number of consecutive ones in the array is: " << max_count << endl;
}

void number_without_duplicate(int arr[], int n)
{
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        val ^= arr[i];
    }
    cout << "Number without duplicate in the array is: " << val << endl;
}

void longest_subarray_with_given_sum(int arr[], int n, int sum)
{
    int longest = 0;

    int curr_sum = 0;
    int l = 0;
    int r = 0;
    while (r < n)
    {
        curr_sum += arr[r];
        while (curr_sum > sum)
        {
            curr_sum -= arr[l];
            l++;
        }
        if (curr_sum == sum)
        {
            longest = max(longest, r - l + 1);
        }
        r++;
    }
    cout << "Length of the longest subarray with given sum is: " << longest << endl;
}

void longest_subarray_withsum_k(int arr[],int n,int k){

    int max_len = 0;
    int curr_sum = 0;
    unordered_map<int,int> prefix_sum;
    prefix_sum[0] = -1; // to handle the case when the subarray starts from index 0

    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        int rem = k - curr_sum;
        if(prefix_sum.find(rem) != prefix_sum.end()){
            max_len = max(max_len, i - prefix_sum[rem]);
        }
        if(prefix_sum.find(curr_sum) == prefix_sum.end()){
            prefix_sum[curr_sum] = i;
        }
    }
    cout << "Length of the longest subarray with sum k is: " << max_len << endl;
}

int main()
{
    int arr[] = {3, 5, 7, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    largest_element(arr, size);
    second_largest_element(arr, size);
    cout << "Is the array sorted? " << (is_sorted(arr, size) ? "Yes" : "No") << endl;
    left_rotate_by_k(arr, size, 4);
    print_array(arr, size);
    int arr2[] = {0, 1, 0, 3, 12};
    size = sizeof(arr2) / sizeof(arr2[0]);
    move_zeroes(arr2, size);
    print_array(arr2, size);
    linear_search(arr2, size, 3);
    sort(arr, arr + size);
    int arr3[] = {1, 2, 3, 4, 5};
    union_of_two_sorted_arrays(arr, size, arr3, sizeof(arr3) / sizeof(arr3[0]));
    int arr4[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    find_missing_number(arr4, sizeof(arr4) / sizeof(arr4[0]));
    int arr5[] = {1, 1, 0, 1, 1, 1};
    max_consecutive_ones(arr5, sizeof(arr5) / sizeof(arr5[0]));
    int arr6[] = {2, 3, 5, 4, 5, 2, 3};
    number_without_duplicate(arr6, sizeof(arr6) / sizeof(arr6[0]));
    int arr7[] = {1, 2, 3, 7, 5};
    longest_subarray_with_given_sum(arr7, sizeof(arr7) / sizeof(arr7[0]), 12);

    int arr8[] = {1, -1, 5, -2, 3};
    longest_subarray_withsum_k(arr8, sizeof(arr8) / sizeof(arr8[0]), 3);

    
    return 0;
}