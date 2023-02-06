// 백준 9020번 문제 (기본수학2 - 6 : 골드바흐의 추측)

// 문제:
// 1보다 큰 자연수 중에서  1과 자기 자신을 제외한 약수가 없는 자연수를 소수라고 한다.
// 예를 들어, 5는 1과 5를 제외한 약수가 없기 때문에 소수이다. 하지만, 6은 6 = 2 × 3 이기 때문에 소수가 아니다.
// 골드바흐의 추측은 유명한 정수론의 미해결 문제로, 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 것이다.
// 이러한 수를 골드바흐 수라고 한다. 또, 짝수를 두 소수의 합으로 나타내는 표현을 그 수의 골드바흐 파티션이라고 한다.
// 예를 들면, 4 = 2 + 2, 6 = 3 + 3, 8 = 3 + 5, 10 = 5 + 5, 12 = 5 + 7, 14 = 3 + 11, 14 = 7 + 7이다.
// 10000보다 작거나 같은 모든 짝수 n에 대한 골드바흐 파티션은 존재한다.
// 2보다 큰 짝수 n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오.
// 만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.

// 입력:
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고 짝수 n이 주어진다.

// 출력:
// 각 테스트 케이스에 대해서 주어진 n의 골드바흐 파티션을 출력한다. 출력하는 소수는 작은 것부터 먼저 출력하며, 공백으로 구분한다.

// 제한:
// 4 ≤ n ≤ 10,000


#include <iostream>
#include <vector>

// B804_1에서 만든 함수 (int number를 받아서 그것이 소수인지 아닌지 판별하는 함수. true -> 소수O, false -> 소수X.
bool CheckingPrimeNumber(int);

int main() {

    using namespace std;

    int T = 0;
    cin >> T;

    vector<int> n(T);
    for (int i = 0; i < T; i++) {
        cin >> n[i];
    }

    int a = 0;
    int b = 0;
    int adder = 0;

    for (int j = 0; j < T; j++) {
        adder = 0;
        while (true) {
            if (n[j] == 4) {                      // 4만 예외처리 (2 + 2)
                cout << 2 << " " << 2 << endl;
                break;
            }
            if ((n[j]/2)%2 == 0) {                // n을 2로 나눈 수가 짝수일 때 a, b를 각각 이렇게 한다.
                a = n[j]/2 -1 - adder;
                b = n[j]/2 +1 + adder;
            }
            else {                                // n을 2로 나눈 수가 홀수일 때 a, b를 각각 이렇게 한다.
                a = n[j]/2 - adder;
                b = n[j]/2 + adder;
            }

            if (CheckingPrimeNumber(a) && CheckingPrimeNumber(b)) {    // 계산된 a, b가 모두 소수면
                cout << a << " " << b << endl;                         // 골드바흐 수!! -> 출력하고 while문 탈출, 다음 for로 넘어감.
                break;
            }
            else {                       // a, b 중 하나라도 소수가 아니면 a = a-2, b = b+2 해서 다시 돌려봄.
                adder += 2;
            }
        }
    }

    return 0;
}



bool CheckingPrimeNumber(int number) {
    if (number == 1)
        return false;
    else if (number == 2)
        return true;
    else if (number % 2 == 0)
        return false;
    for (int i = 3; i*i <= number; i+=2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;    // return 되지않고 for 문을 모두 통과하면 소수이다.
}