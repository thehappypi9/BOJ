// 백준 2581번 문제 (기본수학2 - 2 : 소수)

// 문제:
// 자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.
// 예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로,
// 이들 소수의 합은 620이고, 최솟값은 61이 된다.

// 입력:
// 입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.
// M과 N은 10,000이하의 자연수이며, M은 N보다 작거나 같다.

// 출력:
// M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다.
// 단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.


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

    int M = 0;
    int N = 0;
    cin >> M;
    cin >> N;

    int sum = 0;
    int min = 0;

    for (int i = N; i >= M; i--) {        // i는 N부터 M까지 (내림차순 검사)
        if (CheckingPrimeNumber(i)) {     // 만약 i가 소수이면
            sum += i;                     // sum에 i를 더하고
            min = i;                      // min을 i로 한다. => 가장 마지막에 min이 된 i가 가장 작은 소수이다. (내림차순으로 검사하기 때문)
        }
    }

    if (sum == 0) {
        cout << -1 << endl;
    }
    else {
        cout << sum << endl;
        cout << min << endl;
    }


    return 0;
}