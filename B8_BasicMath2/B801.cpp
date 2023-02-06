// 백준 1978번 문제 (기본수학2 - 1 : 소수 찾기)

// 문제:
// 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

// 입력:
// 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

// 출력:
// 주어진 수들 중 소수의 개수를 출력한다.

#include <iostream>
#include <vector>

int CheckingPrimeNumber(int number) {
    if (number == 1) {
        return false;
    }
    for (int i = 2; i < number; i++) {    // 2부터 number-1 까지로 모두 나눠보고 딱 나누어 떨어지는게 하나라도 있으면 합성수이다.
        if (number % i == 0) {
            return false;
        }
    }
    return true;                          // return 되지않고 for 문을 모두 통과하면 소수이다.
}

int main() {

    using namespace std;

    int N = 0;
    cin >> N;

    vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int answer = 0;

    for (int i = 0; i < N; i++) {
        answer += CheckingPrimeNumber(numbers[i]);
    }

    cout << answer << endl;

    return 0;
}