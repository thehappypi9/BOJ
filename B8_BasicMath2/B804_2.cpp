// ***** i <= sqrt(test) 를 i*i <= test 로 바꾸니 "맞았습니다!!"


// 백준 1929번 문제 (기본수학2 - 4 : 소수 구하기)

// 문제:
// M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

// 출력:
// 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

#include <iostream>

int tester(int test) {   // 1과 2는 검사하지 않는다.
    if (test % 2 == 0) {
        return false;
    }
    for (int i = 3; i*i <= test; i+=2) {
        if (test % i == 0) {
            return false;
        }
    }

    return true;
}


int main() {
    using namespace std;

    int M = 0, N = 0;
    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        if (i == 1) {}
        else if (i == 2) {
            cout << 2 << "\n";
        }
        else {
            if (tester(i)) {
                cout << i << "\n";
            }
        }
    }


    return 0;
}