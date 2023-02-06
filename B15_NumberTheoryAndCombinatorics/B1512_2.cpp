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

// n을 소인수분해 했을 때 2와 5가 몇 개 나오는지 세어 포인터 멤버변수로 전달.
void Factor25 (int n, int* count2, int* count5) {
    int tmp = n;
    while (true) {
        if (tmp <= 1) { break; }
        else if (tmp % 2 == 0) {
            (*count2)++;
            tmp/=2;
        }
        else if (tmp % 5 == 0) {
            (*count5)++;
            tmp/=5; 
        }
        else { break; }
    }
    return;
}

int main() {

// 입력
    int n, r; cin >> n >> r;

// 소인수분해 해서 2의 개수, 5의 개수를 구할 것
    int count2_num = 0; // count2 for numerator
    int count5_num = 0; // count5 for numerator
    int count2_den = 0; // count2 for denominator
    int count5_den = 0; // count5 for denominator

    for (int i = 1; i <= n; i++) { Factor25(i, &count2_num, &count5_num); }
    for (int i = 1; i <= r; i++) { Factor25(i, &count2_den, &count5_den); }
    for (int i = 1; i < n-r; i++) { Factor25(i, &count2_den, &count5_den); }

// 출력
    int count2 = count2_num - count2_den;
    int count5 = count5_num - count5_den;
    if (count2 < count5) { cout << count2; }
    else { cout << count5; }

    return 0;
}