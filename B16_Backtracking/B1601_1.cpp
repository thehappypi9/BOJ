// "시간 초과"

// 백준 15649번 문제 (백트래킹 - 1 : N과 M (1))

// 문제:
// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
    // 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

// 입력:
// 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

// 출력:
// 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
// 수열은 사전 순으로 증가하는 순서로 출력해야 한다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    int N, M;
    cin >> N >> M;

// 한 줄 한 줄 출력할 것의 메모리 확보 및 초기화
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        A[i] = i+1;
    }
    vector<int> B(M);

// 반복문
    while (true) {
    // 판별 후 출력
        vector<int> B(A);
        sort(B.begin(), B.end());
        int go = 1;
        for (int i = 1; i < M; i++) {
            if (B[i-1] == B[i]) {
                go = 0;
                break;
            }
        }
        if (go) {
            for (int i = 0; i < M; i++) { cout << A[i] << " "; }
            cout << "\n";
        }

    // 다 된 건지 판별. 다 되었으면 while문 break
        int done = 1;
        for (int i = 0; i < M; i++) {
            if (A[i] != N) {
                done--;
                break;
            }
        }
        if (done) {
            break;
        }

    // 숫자 바꾸기
        for (int i = 1; i <= M; i++) {
            if (A[M-i] < N) {
                A[M-i]++;
                break;
            }
            else if (A[M-i] == N) {
                A[M-i] = 1;
            }
            else {
                cout << "WTF???\n";
            }
        }
    }

    
    return 0;
}