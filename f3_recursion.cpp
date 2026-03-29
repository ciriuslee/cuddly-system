#include <iostream>

using namespace std;

void helper_print_1_to_n(int n)
{
    if (n < 1)return;
    helper_print_1_to_n(n - 1);
    cout << n << " ";
}

void print_1_to_n(int n)
{
    helper_print_1_to_n(n);
}

void helper_print_n_to_1(int n)
{
    if (n < 1)return;
    cout << n << " ";
    helper_print_n_to_1(n - 1);
}

void print_n_to_1(int n)
{
    helper_print_n_to_1(n);
}

void sum_of_n(int n,int &sum){
    if(n < 1)return;
    sum += n;
    sum_of_n(n-1,sum);
}

void factorial(int n,int &fact){
    if(n < 1)return;
    fact *= n;
    factorial(n-1,fact);
}

void helper_reverse_array(int arr[],int i,int n){
    if(i >= n/2)return;
    swap(arr[i],arr[n-i-1]);
    helper_reverse_array(arr,i+1,n);
}

void reverse_array(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    helper_reverse_array(arr,0,n);
    cout << "Reversed array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

bool helper_is_palindrome(string str,int i,int n){
    if(i >= n/2)return true;
    if(str[i] != str[n-i-1]){
        return false;
    }
    return helper_is_palindrome(str,i+1,n);
}

void is_palindrome(string str){
    int n = str.length();
    if(helper_is_palindrome(str,0,n)){
        cout << str << " is a palindrome." << endl;
    }else{
        cout << str << " is not a palindrome." << endl;
    }
}


void fibonacci(int n,int &a,int &b){
    if(n < 1)return;
    cout << a << " ";
    int next = a + b;
    a = b;
    b = next;
    fibonacci(n-1,a,b);
    
}
int main()
{
    cout << "------------------" << endl;
    print_1_to_n(10);
    cout << endl;
    cout << "------------------" << endl;
    print_n_to_1(10);
    cout << endl;
    cout << "------------------" << endl;
    int sum = 0;
    sum_of_n(10,sum);
    cout << "Sum of 1 to 10 is " << sum << endl;
    cout << "------------------" << endl;
    int fact = 1;
    factorial(10,fact);
    cout << "Factorial of 10 is " << fact << endl;
    cout << "------------------" << endl;
    reverse_array();
    cout << "------------------" << endl;
    is_palindrome("madam");
    is_palindrome("hello");
    cout << "------------------" << endl;
    int a = 0, b = 1;
    fibonacci(10,a,b);
    cout<<endl;
    cout << "------------------" << endl;
    return 0;
}