// 백준 24416번 문제 (동적 계획법 1 - 1 : 알고리즘 수업 - 피보나치 수 1)
// https://www.acmicpc.net/problem/24416

#include <iostream>
#include <vector>
using namespace std;

// Recursion
int fib(int n, int* code1) {
    if (n == 1 || n == 2) {
        (*code1)++;
        return 1;
    }
    else { return (fib(n-1, code1) + fib(n-2, code1)); }
}

// Dynamic Programming
int fibonacci(int n, int* code2) {
    vector<int> f(n+1);
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
        (*code2)++;
    }
    return f[n];
}

int main() {

    int n; cin >> n;
    
    int code1 = 0;
    int code2 = 0;
    fib(n, &code1);
    fibonacci(n, &code2);

    cout << code1 << " " << code2;


    return 0;
}