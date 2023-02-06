// "맞았습니다!!"
// void Factorial25 함수 아이디어 백준 질문글 참고: https://www.acmicpc.net/board/view/84716#comment-137720

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

// n! 에 곱해져있는 2와 5의 개수를 각각 포인터 멤버변수를 통해 전달.
void Factorial25 (unsigned long long n, unsigned long long* count2, unsigned  long long* count5) {
    unsigned long long two = 2;
    unsigned long long five = 5;
    while (true) {
        if (n < two) {break;}
        else {
            *count2 += n/two;
            two *= 2;
        }
    }
    while (true) {
        if (n < five) {break;}
        else {
            *count5 += n/five;
            five *= 5;
        }
    }
    return;
}

int main() {

// 입력
    unsigned long long n;
    unsigned long long r;
    cin >> n >> r;

// 분자, 분모에 곱해져 있는 2의 개수, 5의 개수 각각 구하기
    unsigned long long count2_num = 0;
    unsigned long long count5_num = 0;
    unsigned long long count2_den = 0;
    unsigned long long count5_den = 0;

    Factorial25(n, &count2_num, &count5_num);
    Factorial25(r, &count2_den, &count5_den);
    Factorial25(n-r, &count2_den, &count5_den);

    unsigned long long count2 = count2_num - count2_den;
    unsigned long long count5 = count5_num - count5_den;

// 출력
    if (count2 < count5) { cout << count2; }
    else { cout << count5; }

    return 0;
}