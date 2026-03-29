#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void count_digits_1(int n){
    int count = 0;
    while(n > 0){
        n /= 10;
        count++;
    }
    cout << count << endl;
}

void count_digits_2(int n){
    int no_of_digits = log10(n);
    cout << no_of_digits << endl;
}

void reverse_number(int n){
    int rev = 0;
    while(n > 0){
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    cout << rev << endl;
}

void check_palindrome(int n){
    if(n < 0 || (n % 10 == 0 && n != 0)){
        cout << "Not a palindrome" << endl;
        return;
    }

    int rev = 0;
    while( n > rev){
        rev = rev * 10 + n % 10;
        n /= 10;
        if(n == rev || n == rev/10){
            cout << "Palindrome" << endl;
            return;
        }
    }
}

int gcd(int a,int b){
    if( a > b)return gcd(b,a);
    if( a == 0)return b;
    return gcd(b%a,a);
}

bool is_armstrong(int n){
    int sum = 0;
    int temp = n;
    int digits = log10(n) + 1;
    while(temp > 0){
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == n;
}

void print_divisors(int n){
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            cout << i << " ";
            if(i != n/i)cout << n/i << " ";
        }
    }
    cout << endl;
}


bool is_prime(int n){
    if(n < 2)return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)return false;
    }
    return true;
}

int main(){
    cout << "GLHF <3" << endl;

    cout << "---------------" << endl;
    count_digits_1(123456789);
    cout << "---------------" << endl;
    count_digits_2(123456789);
    cout << "---------------" << endl;
    reverse_number(123456789);
    cout << "---------------" << endl;
    check_palindrome(12321);
    cout << "---------------" << endl;
    cout << "GCD: " << gcd(48,18) << endl;
    cout << "---------------" << endl;
    cout << "Is 153 an Armstrong number? " << (is_armstrong(153) ? "Yes" : "No") << endl;
    cout << "---------------" << endl;
    cout << "Divisors of 28: ";
    print_divisors(28);
    cout << "---------------" << endl;
    cout << "Is 30 a prime number? " << (is_prime(30) ? "Yes" : "No") << endl;
    cout << "---------------" << endl;
}