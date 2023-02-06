// ***** 다른 질문글 참고함. https://www.acmicpc.net/board/view/95871


// 백준 1929번 문제 (기본수학2 - 4 : 소수 구하기)

// 문제:
// M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

// 출력:
// 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.


#include <iostream>

bool check[1000001];    // 처음엔 전부 false.  (false를 소수라고 생각한다. 모두 일단 소수라고 가정.)

int main() {
    using namespace std;

    int M, N;
    cin >> M >> N;

    for (int i = 2; i <= N; i++) {
        if (check[i] == false) {               // 소수가 감지되면,
            for (int j = 2*i; j <= N; j+=i) {  // 그 수의 2배부터 n배까지에 대해
                check[j] = true;               // 합성수라고 설정 (true)
            }
        }
    }
    check[0] = true;  // 0이랑 1은 따로 빼서 소수가 아니라고(true) 설정.
    check[1] = true;

    for (int i = M; i <= N; i++) {   // M 부터 N 까지의 i 에 대해,
        if(check[i] == false ) {    // 소수면
            cout << i <<'\n';       // 출력.
        }
    }

    return 0;

}