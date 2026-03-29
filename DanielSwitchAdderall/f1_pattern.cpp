#include <iostream>
#include <vector>
using namespace std;

void print_box(int w, int h)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print_rtl_stairs(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print_rtl_number_stair(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

void print_rtl_number_stair_2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

void print_reverse_rtl_stairs(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i + 1; j >= 1; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print_reverse_rtl_stairs_2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

void print_pyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * (i - 1) + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print_reverse_pyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * (n - i) + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print_diamond(int n)
{
    print_pyramid(n);
    print_reverse_pyramid(n - 1);
}

void print_half_diamond(int n)
{
    print_rtl_stairs(n);
    print_reverse_rtl_stairs(n);
}

void print_binary_number_triangle_pattern(int n)
{
    string s = "1";
    for (int i = 1; i <= n; i++)
    {
        cout << s << endl;
        if (s[0] == '1')
            s = "0" + s;
        else
            s = "1" + s;
    }
}

void print_binary_number_triangle_pattern_better(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int start = (i % 2 == 0) ? 0 : 1;
        for (int j = 1; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

void print_idk_what_this_is(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}

void print_increasing_number_staircase(int n)
{
    int v = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << v << " ";
            v++;
        }
        cout << endl;
    }
}

void print_alphabet_staircase_rtl(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (char)('A' + j - 1) << " ";
        }
        cout << endl;
    }
}

void print_alphabet_staircase_reverse_rtl(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << (char)('A' + j - 1) << " ";
        }
        cout << endl;
    }
}

void print_alphabet_pyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << (char)('A' + j - 1);
        }
        for (int j = i - 1; j >= 1; j--)
        {
            cout << (char)('A' + j - 1);
        }
        cout << endl;
    }
}

void print_idk_what_this_is_2(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << (char)('A' + n - j);
        }
        cout << endl;
    }
}

void print_hollow_diamond_top(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= 2 * (i - 1); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print_hollow_diamond_bottom(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print_hour_glass(int n)
{
    print_hollow_diamond_bottom(n);
    print_hollow_diamond_top(n);
}

void print_hollow_diamond(int n)
{
    print_hollow_diamond_top(n);
    print_hollow_diamond_bottom(n);
}

void print_box(int n)
{

    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == n)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << "*";
            }
        }
        else
        {
            cout << "*";
            for (int j = 1; j <= n - 2; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}

void add_in_range(vector<int> &nums, int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        nums[i] += val;
    }
}

void arr_to_string(vector<int> &nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void print_bullseye(int n)
{
    vector<int> nums(2 * n - 1, n);
    for (int i = 1; i <= n; i++)
    {
        arr_to_string(nums, 2 * n - 1);
        add_in_range(nums, i, 2 * (n - 1) - i, -1);
    }
    int mid = (2 * n - 1) / 2;
    for (int i = 1; i <= n - 1; i++)
    {
        add_in_range(nums, mid - i + 1, mid + i - 1, 1);
        arr_to_string(nums, 2 * n - 1);
    }
}

// n = 4
// size = 7

// 4 3 2 1 2 3 4
// 0 1 2 3 4 5 6

// (2 * (n - 1)) / 2 - i

int main()
{
    cout << "Hello, World!" << endl;
    print_box(3, 5);
    cout << "-----------------" << endl;
    print_rtl_stairs(4);
    cout << "-----------------" << endl;
    print_rtl_number_stair(5);
    cout << "-----------------" << endl;
    print_rtl_number_stair_2(5);
    cout << "-----------------" << endl;
    print_reverse_rtl_stairs(5);
    cout << "-----------------" << endl;
    print_reverse_rtl_stairs_2(5);
    cout << "-----------------" << endl;
    print_pyramid(5);
    cout << "-----------------" << endl;
    print_reverse_pyramid(5);
    cout << "-----------------" << endl;
    print_diamond(5);
    cout << "-----------------" << endl;
    print_half_diamond(5);
    cout << "-----------------" << endl;
    print_binary_number_triangle_pattern(5);
    cout << "-----------------" << endl;
    print_binary_number_triangle_pattern_better(5);
    cout << "-----------------" << endl;
    print_idk_what_this_is(4);
    cout << "-----------------" << endl;
    print_increasing_number_staircase(5);
    cout << "-----------------" << endl;
    print_alphabet_staircase_rtl(5);
    cout << "-----------------" << endl;
    print_alphabet_staircase_reverse_rtl(5);
    cout << "-----------------" << endl;
    print_alphabet_pyramid(5);
    cout << "-----------------" << endl;
    print_idk_what_this_is_2(5);
    cout << "-----------------" << endl;
    print_hollow_diamond(5);
    cout << "-----------------" << endl;
    print_hour_glass(5);
    cout << "-----------------" << endl;
    print_box(5);
    cout << "-----------------" << endl;
    print_bullseye(4);
    return 0;
}
