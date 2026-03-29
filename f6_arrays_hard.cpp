#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;

// N Sum
vector<vector<int>> twoSum(vector<int> &nums, int target, int l, int r)
{
    if (r - l < 2)
        return {};
    vector<vector<int>> res;

    while (l < r)
    {
        if (nums[l] + nums[r] == target)
        {
            res.push_back({nums[l], nums[r]});
            do
                l++;
            while (l < r && nums[l] == nums[l - 1]);
            do
                r--;
            while (l < r && nums[r] == nums[r + 1]);
        }
        else if (nums[l] + nums[r] < target)
            l++;
        else
            r--;
    }
    return res;
}

vector<vector<int>> nSum(vector<int> &nums, int target, int l, int r, int n)
{
    if (n == 2)
        return twoSum(nums, target, l, r);
    vector<vector<int>> res;
    for (int i = l; i < r; i++)
    {
        if (i > l && nums[i] == nums[i - 1])
            continue;
        int remaining = target - nums[i];
        for (auto &it : nSum(nums, remaining, i + 1, r, n - 1))
        {
            it.push_back(nums[i]);
            res.push_back(it);
        }
    }
    return res;
}

void nSumHelper(vector<int> &nums, int target, int n)
{
    int size = nums.size();
    if (size < 3)
        return;
    sort(nums.begin(), nums.end());
    vector<vector<int>> res = nSum(nums, target, 0, size - 1, n);
    cout << n << "-Sum with sum " << target << " are:" << endl;
    for (const auto &combination : res)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

void three_sum(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n < 3)
        return;

    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int x = nums[i];
        int remaining = target - x;
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int y = nums[l], z = nums[r];
            if (y + z == remaining)
            {
                res.push_back({x, y, z});
                do
                    l++;
                while (l < r && nums[l] == nums[l - 1]);
                do
                    r--;
                while (l < r && nums[r] == nums[r + 1]);
            }
            else if (y + z > remaining)
                r--;
            else
                l++;
        }
    }
    cout << "Tripets with sum " << target << " are:" << endl;
    for (const auto &triplet : res)
    {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }
}

void len_of_longest_subarray_with_sum_zero(vector<int> &nums, int n)
{
    int max_len = 0;
    unordered_map<int, int> pos;
    pos[0] = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        int to_remove = sum;
        if (pos.find(to_remove) != pos.end())
            max_len = max(max_len, i + 1 - pos[to_remove]);
        else
            pos[sum] = i;
    }
    cout << "Length of longest subarray with sum zero is: " << max_len << endl;
}

void subarrays_with_xor_k(vector<int> &nums, int n, int target)
{
    int res = 0;
    int curr = 0;
    unordered_map<int, int> freq;
    freq[0] = 1;
    for (int i = 0; i < n; i++)
    {
        curr ^= nums[i];
        int req = target ^ curr;
        if (freq.find(req) != freq.end())
            res += freq[req];
        freq[curr]++;
    }
    cout << "Number of subarrays with XOR " << target << " is: " << res << endl;
}

vector<vector<int>> merge_overlapping_subintervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n < 2)
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    vector<int> curr = intervals.at(0);
    for (const auto &it : intervals)
    {

        int s = it.at(0);
        int e = it.at(1);

        if (curr[1] >= s)
        {
            curr[1] = max(curr[1], e);
        }
        else
        {
            res.push_back(curr);
            curr = it;
        }
    }
    res.push_back(curr);
    return res;
}

void merge_overlapping_subintervals_helper(vector<vector<int>> &intervals)
{
    vector<vector<int>> res = merge_overlapping_subintervals(intervals);
    cout << "Merged intervals are:" << endl;
    for (const auto &it : res)
    {
        cout << it[0] << " " << it[1] << endl;
    }
}

void find_missing_and_repeating_number(vector<int> &nums, int n)
{
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        val ^= nums[i];
        val ^= (i + 1);
    }

    int setBit = val & (~(val - 1));
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & setBit)
            x ^= nums[i];
        else
            y ^= nums[i];

        if (((i + 1) & setBit))
            x ^= (i + 1);
        else
            y ^= (i + 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == x)
        {
            cout << "Repeating number is: " << x << endl;
            cout << "Missing number is: " << y << endl;
            return;
        }
    }
    cout << "Repeating number is: " << y << endl;
    cout << "Missing number is: " << x << endl;
}


// This works but Siri this is like idk T-T ANYWAYYSSSS
void maximum_product_subarray_siri(vector<int> &nums)
{

    int n = nums.size();
    if (n == 0)
        return;
    int max_product = nums[0];
    int p = 1;
    int np = 1;
    int negs = 0;

    for (const auto &i : nums)
    {
        p = p * i;
        max_product = max(max_product, p);
        if (p == 0)
        {
            p = 1;
            np = 1;
            negs = 0;
            continue;
        }
        else if (p < 0)
        {
            negs++;
            if (np != 1)
            {
                p = (negs % 2) == 1 ? p / np : p * np;
            }
            else
            {
                np = p;
                p = 1;
                continue;
            }
        }
        max_product = max(max_product, p);
    }
    cout << "Maximum product subarray is: " << max_product << endl;

}


void maximum_product_subarray(vector<int> &nums){
    int max_product = nums[0];
    int px = 1, sx = 1;
    int n = nums.size();
    if(n == 0)return;

    for(int i = 0; i < n; i++){
        px = px * nums[i];
        sx = sx * nums[n-i-1];
        max_product = max(max_product, max(px,sx));
        if(px == 0)px = 1;
        if(sx == 0)sx = 1;
    }

    cout<< "Maximum product subarray is: " << max_product << endl;
}


void maximum_product_subarray_kadanes(vector<int> &nums){
    int max_product = nums[0];
    int curr_max = 1, curr_min = 1;
    for(const auto &i : nums){
        if(i == 0){
            curr_max = 1;
            curr_min = 1;
            continue;
        }

        curr_max = max(i, max(curr_max * i, curr_min * i));
        curr_min = max(i, min(curr_max * i, curr_min * i));
        max_product = max(curr_max, curr_min);
    }

    cout << "Maximum product subarray is: " << max_product << endl;
}

int mergeAndCountInversions(vector<int> &nums,int l, int mid, int r){

    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++)left[i] = nums[l + i];
    for(int i = 0; i < n2; i++)right[i] = nums[mid + 1 + i];
    int i = 0, j = 0, k = l, inversions = 0;
    //Count inversions
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            nums[k++] = left[i++];
        }else{
            nums[k++] = right[j++];
            inversions += (n1 - i);
        }
    }
    while(i < n1)nums[k++] = left[i++];
    while(j < n2)nums[k++] = right[j++];
    return inversions;
}


int mergeSortHelper(vector<int> &nums, int l, int r){
    if(l >=r)return 0;
    int mid = l + (r-l)/2;
    int t1 = mergeSortHelper(nums,l,mid);
    int t2 = mergeSortHelper(nums,mid+1,r);
    int t3 = mergeAndCountInversions(nums,l,mid,r);
    return t1 + t2 + t3;

}


void count_inversions(vector<int> &nums){
    int inversions = mergeSortHelper(nums,0,nums.size()-1);
    cout << "Number of inversions are: " << inversions << endl;
}

void merge(vector<int> &nums,int l, int mid, int r){

    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++)left[i] = nums[l + i];
    for(int i = 0; i < n2; i++)right[i] = nums[mid + 1 + i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            nums[k++] = left[i++];
        }else{
            nums[k++] = right[j++];         
        }
    }
    while(i < n1)nums[k++] = left[i++];
    while(j < n2)nums[k++] = right[j++];
}

int countReversePairs(vector<int> &nums,int l, int mid, int r){

    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++)left[i] = nums[l + i];
    for(int i = 0; i < n2; i++)right[i] = nums[mid + 1 + i];
    int i = 0, j = 0, k = l, reversePairs = 0;
    //Count reverse pairs
    while(i < n1 && j < n2){
        if((long long)left[i] > 2 * (long long)right[j]){
            reversePairs += (n1 - i);
            j++;
        }else{
            i++;
        }
    }
    return reversePairs;
}

int mergeSortHelperReversePairs(vector<int> &nums, int l, int r){
    if(l >=r)return 0;
    int mid = l + (r-l)/2;
    int t1 = mergeSortHelperReversePairs(nums,l,mid);
    int t2 = mergeSortHelperReversePairs(nums,mid+1,r);
    int t3 = countReversePairs(nums,l,mid,r);
    merge(nums,l,mid,r);
    return t1 + t2 + t3;

}
    

void count_reverse_pairs(vector<int> &nums){
    int reversePairs = mergeSortHelperReversePairs(nums,0,nums.size()-1);
    cout << "Number of reverse pairs are: " << reversePairs << endl;
}



int main()
{
    vector<int> nums = {1, 2, -3, 4, -2, -1, 0};
    int target = 0;
    three_sum(nums, target);

    vector<int> nums2 = {1, 2, -3, 4, -2, -1, 0};
    nSumHelper(nums2, target, 4);

    vector<int> nums3 = {2, -2, 3, 1, -3, 4, -1, 0, -2, 1, 2, -1, -4};
    len_of_longest_subarray_with_sum_zero(nums3, nums3.size());

    vector<int> nums4 = {1, 2, 3, 4, 5};
    int k = 3;
    subarrays_with_xor_k(nums4, nums4.size(), k);

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    merge_overlapping_subintervals_helper(intervals);

    vector<int> nums5 = {4, 3, 6, 2, 1, 1};
    find_missing_and_repeating_number(nums5, 6);

    cout << endl;
    cout << endl;
    vector<int> nums6 = {0, -2, -3, 0, -2, -3, -4};
    maximum_product_subarray(nums6);
    maximum_product_subarray_siri(nums6);
    maximum_product_subarray_kadanes(nums6);

    vector<int> nums7 = {5,3,2,1,4};
    count_inversions(nums7);

    vector<int> nums8 = {1,3,2,3,1};
    count_reverse_pairs(nums8);

}

// -3 -2 -1 0 1 2 4