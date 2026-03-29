#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

void reverse(int arr[], int l, int r)
{
    while (l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void twoSum(int arr[], int n, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int rem = target - arr[i];
        if (map.find(rem) != map.end())
        {
            cout << "Pair found: " << rem << " and " << arr[i] << endl;
            return;
        }
        map[arr[i]] = i;
    }
    cout << "No pair found." << endl;
}

void sortZerosOnesTwos(int arr[], int n)
{
    int l = 0, r = 0;
    while (r < n)
    {
        if (arr[r] == 0)
        {
            swap(arr[l], arr[r]);
            l++;
        }
        r++;
    }
    r = l;
    while (r < n)
    {
        if (arr[r] == 1)
        {
            swap(arr[l], arr[r]);
            l++;
        }
        r++;
    }

    cout << "Sorted array: ";
    printArray(arr, n);
}

void majorityElement(int arr[], int n)
{
    int count = 0, candidate = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            candidate = arr[i];
        if (arr[i] == candidate)
            count++;
        else
            count--;
    }
    cout << "Majority element: " << candidate << endl;
}


void kadanes_max_subarray_sum(int arr[], int n){
    int max_sum = 0, sum = 0, l = 0, r = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0){
            sum = 0;
            l = i + 1;
        }
        if(sum > max_sum){
            max_sum = sum;
            r = i;
        }
    }
    cout << "Maximum subarray sum: " << max_sum << endl;
    cout << "Start index: " << l << ", End index: " << r << endl;
}


// Buy High Sell low club ayyy
void stock_buy_and_sell(int arr[],int n){
    int max_profit = 0;
    int buy = arr[0], sell = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] < buy)buy = arr[i];
        else{
            max_profit = max(max_profit, arr[i] - buy);
        }
    }
    cout << "Maximum profit: " << max_profit << endl;

}


void rearrange_array_by_sign_alternately(int arr[],int n){
    int l = 0, r = 0, expec = 1;
    while(r < n){
        if(arr[r] * expec > 0){
            swap(arr[l], arr[r]);
            l++;
            expec *= -1;
        }
        r++;
    }
    cout << "Rearranged array: ";
    printArray(arr, n);
}


void generate_permutations_helper(string str,int i,int n,vector<string> &permutations){
    if(i == n){
        permutations.push_back(str);
        return;
    }

    for(int j = i; j < n; j++){
        swap(str[i], str[j]);
        generate_permutations_helper(str, i + 1, n, permutations);
        swap(str[i], str[j]);
    }
}

void generate_permutations(string str,int i,int n,vector<string> &permutations){
    generate_permutations_helper(str, i, n, permutations);
    sort(permutations.begin(), permutations.end());
    cout << "Permutations: ";
    for(auto perm : permutations){
        cout << perm << " ";
    }
    cout << endl;
}

void generate_next_permutation(int arr[],int n){
    for(int i = n -2; i>= 0; i--){
        if(arr[i] < arr[i+1]){
            int j = n- 1;
            while(arr[j] <= arr[i])j--;
            swap(arr[i],arr[j]);
            reverse(arr,i+1,n-1);
            return;
        }
    }
}



void leaders_in_array(int arr[],int n){
    vector<int> leaders;


    int max_from_right = arr[n-1];
    leaders.push_back(max_from_right);

    for(int i = n-1; i >= 0; i--){
        if(arr[i] > max_from_right){
            max_from_right = arr[i];
            leaders.push_back(max_from_right);
        }
    }
    reverse(leaders.begin(), leaders.end());
    cout << "Leaders in the array: ";
    for(auto leader : leaders){
        cout << leader << " ";
    }
    cout << endl;

}

void get_next_permutation(int arr[],int n){
    generate_next_permutation(arr,n);
    cout << "Next permutation: ";
    printArray(arr, n);
    cout << endl;
}

void longest_consecutive_sequence(int arr[],int n){
    unordered_set<int> set(arr, arr + n);
    int longest_streak = 0;
    for(int i = 0; i < n; i++){
        set.insert(arr[i]);
        if(set.find(arr[i] - 1) == set.end()){
            int j = arr[i] + 1;
            while(set.find(j) != set.end())j++;
            longest_streak = max(longest_streak, j - arr[i]);
        }
    }
    cout << "Longest consecutive sequence: " << longest_streak << endl;
}

void set_matrix_zeroes(vector<vector<int>> &matrix){
    int rows = matrix.size() ;
    int cols = matrix[0].size();

    bool row_zero = false, col_zero = false;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == 0){
                if(i == 0)row_zero = true;
                if(j == 0)col_zero = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(row_zero){
        for(int j = 0; j < cols; j++){
            matrix[0][j] = 0;
        }
    }

    if(col_zero){
        for(int i = 0; i < rows; i++){
            matrix[i][0] = 0;
        }
    }

    cout << "Matrix after setting zeroes: " << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

void count_subarray_with_given_sum(int arr[],int n,int target){
    unordered_map<int,int> map;
    int count = 0, sum = 0;
    map[0] = 1;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        int remaining = sum - target;
        if(map.find(remaining) != map.end()){
            count += map[remaining];
        }
        map[sum]++;
    }
    cout << "Count of subarrays with sum " << target << ": " << count << endl;
}

void print_pascal_triangle(vector<int> &v,int i, int n){
    for(int j = 0; j < n-i; j++){
        cout << " ";
    }
    for(int j = 0; j < i; j++){
        cout << v[j] << " ";
    }
    cout << endl;
    if(i == n)return;
    vector<int> next_row(i + 1, 1);
    for(int j = 1;j < i; j++){
        next_row[j] = v[j - 1] + v[j];
    }
    print_pascal_triangle(next_row, i + 1, n);
}

void pascal_triangle(int n){
    vector<int> row(n, 1);
    print_pascal_triangle(row, 1, n);
}

void majority_element_2(int arr[],int n){
    int c1 = 0, c2 = 0, m1 = 0, m2 = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == m1)c1++;
        else if(arr[i] == m2)c2++;
        else if(c1 == 0){
            m1 = arr[i];
            c1 = 1;
        }else if(c2 == 0){
            m2 = arr[i];
            c2 = 1;
        }else{
            c1--;
            c2--;
        }
    }

    c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == m1)c1++;
        else if(arr[i] == m2)c2++;
    }

    cout << "Majority elements: ";
    if(c1 > n/3)cout << m1 << " ";
    if(c2 > n/3)cout << m2 << " ";
    cout << endl;
}

int main()
{
    int arr1[] = {2, 7, 11, 15};
    int target1 = 9;
    twoSum(arr1, 4, target1);

    int arr2[] = {0, 1, 2, 0, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sortZerosOnesTwos(arr2, n2);

    int arr3[] = {2, 2, 1, 1, 1, 1, 2, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    majorityElement(arr3, n3);

    int arr4[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    kadanes_max_subarray_sum(arr4, n4);

    int arr5[] = {7,1,5,3,6,4};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    stock_buy_and_sell(arr5, n5);
    int arr6[] = {-1,2,1,-4};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    rearrange_array_by_sign_alternately(arr6, n6);

    string str = "1234";
    vector<string> permutations;
    generate_permutations(str, 0, str.size(), permutations);

    int arr7[] = {1, 2, 3 , 5, 4};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    get_next_permutation(arr7, n7);

    int arr8[] = {16, 17, 4, 3, 5, 2};
    int n8 = sizeof(arr8) / sizeof(arr8[0]);
    leaders_in_array(arr8, n8);


    int arr9[] = {100, 4, 200, 1, 3, 2};
    int n9 = sizeof(arr9) / sizeof(arr9[0]);
    longest_consecutive_sequence(arr9, n9);

    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    set_matrix_zeroes(matrix);

    int arr10[] = {1, 1, 1};
    int n10 = sizeof(arr10) / sizeof(arr10[0]);
    int target10 = 2;
    count_subarray_with_given_sum(arr10, n10, target10);


    int n11 = 5;
    cout<< endl <<  "Pascal triangle: " <<endl;
    pascal_triangle(n11);

    int arr12[] = {1, 1, 1, 3, 2};
    int n12 = sizeof(arr12) / sizeof(arr12[0]);
    majority_element_2(arr12, n12);

    return 0;
    
}