// 백준 11050번 문제 (정수론 및 조합론 - 7 : 이항 계수 1)

// 문제:
// 자연수 N과 정수 K가 주어졌을 때 이항 계수 (N K) 를 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)

// 출력:
// (N K)를 출력한다.


#include <iostream>
#include <vector>
using namespace std;

int Factorial(int n) {
    if (n <= 1) { return 1; }
    return (n*Factorial(n-1));
}

int main() {

    int N, K;
    cin >> N >> K;
    cout << Factorial(N) / (Factorial(K) * Factorial(N-K));   // n! / (k!(n-k)!)

    return 0;
}