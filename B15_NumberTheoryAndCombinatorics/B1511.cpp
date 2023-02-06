// 백준 1676번 문제 (정수론 및 조합론 - 11 : 팩토리얼 0의 개수)

// 문제:
// N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

// 출력:
// 첫째 줄에 구한 0의 개수를 출력한다.


#include <iostream>
using namespace std;

int main() {

// 입력
    int N; cin >> N;

// 소인수분해해서 2의 배수와 5의 배수 구하기
    int count2 = 0;
    int count5 = 0;
    int tmp;
    for (int i = 1; i <= N; i++) {
        tmp = i;
        while (true) {
            if (tmp % 2 == 0) {
                count2++;
                tmp /= 2;
            }
            else if (tmp % 5 == 0) {
                count5++;
                tmp /= 5;
            }
            else {
                break;
            }
        }
    }

// 출력
    if (count2 < count5) { cout << count2; }
    else { cout << count5; }

    return 0;
}