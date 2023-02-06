// "시간초과"

// 백준 2004번 문제 (정수론 및 조합론 - 12 : 조합 0의 개수)

// 문제:
// (n m)의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 정수 n, m (0 <= m <= n <= 2,000,000,000, n != 0)이 들어온다.

// 출력:
// 첫째 줄에 (n m)의 끝자리 0의 개수를 출력한다.


#include <iostream>
#include <vector>
using namespace std;

int main() {

// 입력
    int n, r; cin >> n >> r;
    if (r > n-r) { r = n-r; }

// 소인수분해 해서 2의 개수, 5의 개수를 구할 것
    int count2 = 0;
    int count5 = 0;
    int tmp;
    // 분자에서 2의 개수, 5의 개수 구해서 그만큼 더해주기
    for (int i = 0; i < r; i++) {
        while (true) {
            tmp = n-i;
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
    // 분모에서 2의 개수, 5의 개수 구해서 그만큼 빼주기
    for (int i = 0; i < r; i++) {
        while (true) {
            tmp = 1+i;
            if (tmp % 2 == 0) {
                count2--;
                tmp /= 2;
            }
            else if (tmp % 5 == 0) {
                count5--;
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