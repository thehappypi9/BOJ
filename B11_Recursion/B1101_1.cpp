// for 이용

// 백준 10872번 문제 (재귀 - 1 : 팩토리얼)

// 문제:
// 0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 정수 N(0 ≤ N ≤ 12)이 주어진다.

// 출력:
// 첫째 줄에 N!을 출력한다.


#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;

    int factorial = 1;
    for (int i = 1; i <= N; i++) {
        factorial *= i;
    }

    cout << factorial;

    return 0;
}