// 백준 11653번 문제 (기본수학2 - 3 : 소인수분해)

// 문제:
// 정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

// 출력:
// N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다. N이 1인 경우 아무것도 출력하지 않는다.


#include <iostream>
#include <vector>

int Factorization(int* n, int* factor) {     // 포인터로 받아와서 main에 있는 값을 포인터를 통해 바꿀 것이다.
    for (int i = 2; i < *n; i++) {           // i는 2부터 *n 까지 (나누어 떨어지는 것이 있는지 검사한다)
        if ((*n)%i == 0) {                   // *n이 i로 나누어떨어지면,
            *n /= i;                         // *n을 i로 나누고,
            *factor = i;                     // *factor를 i로 한다. (따라서 처음 입력에 들어오는 *factor값은 상관없다.)
            return true;                     // 하나라도 나눠진다면 true를 반환 (소인수분해 성공)
        }
    }
    return false;                            // 나누어떨어지는것이 없이 for문이 끝났다면 false를 반환 (더 이상 소인수분해 할 것이 없음)
}

int main() {

    using namespace std;

    int N = 0;
    int* ptrN = &N;
    cin >> N;
    if (N == 1) {
        return 0;
    }
    int factor = 0;
    int* ptrfactor = &factor;

    vector<int> factors;

    while(true) {
        if (Factorization(ptrN, ptrfactor)) {   // 더 이상 소인수분해 할 것이 없을때까지 소인수분해.
            factors.push_back(factor);          // if문에서 실행한 함수에 따라 나온 factor를 factors 벡터의 마지막 원소로 집어넣는다.
        }
        else {
            break;                              // 더 이상 소인수분해 할 것이 없다면 while문 종료.
        }
    }
    factors.push_back(N);    // 마지막으로 소인수분해되지 않고 남은 수도 factors 벡터의 마지막 원소로 집어넣는다.

    for (unsigned long int i = 0; i < factors.size(); i++) {
        cout << factors[i] << endl;
    }

    return 0;
}