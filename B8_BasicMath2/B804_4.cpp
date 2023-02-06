// ***** i <= sqrt(N) 을 i*i <= N 으로 바꾸니 "맞았습니다!!"


// 백준 1929번 문제 (기본수학2 - 4 : 소수 구하기)

// 문제:
// M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

// 출력:
// 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.


#include <iostream>
#include <vector>

int main() {
    using namespace std;

    int M = 0, N = 0;
    cin >> M >> N;

    vector<bool> v(N+1, true);   // 전부 소수라고 가정
    v[0] = false;                // 0과 1은 소수에서 제외
    v[1] = false;

    for (int i = 2; i*i <= N; i++) {
        if (v[i]) {                                           // i가 소수라면,
            for (int multiple = 2; i*multiple <= N; multiple++) {    // i의 2배 이상 배수를 모두
                v[i*multiple] = false;                        // 소수에서 제외
            }
        }
        else {
            // 그냥 넘어가기 (v[i]가 false이면 이미 v[i]의 약수에 의해 지워졌다는 뜻. v[i]의 배수들 또한 당연히 지워졌을 것.)
        }
    }

    for (int j = M; j <= N; j++) {
        if (v[j]) {                    // 소수(true)라면,
            cout << j << "\n";         // 출력.
        }
    }

    return 0;
}