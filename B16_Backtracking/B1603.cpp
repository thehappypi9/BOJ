// 0이 없는 N진수, M자릿수 숫자 오름차순으로 출력한다고 생각.
// 백트래킹을 굳이 쓰지는 않은 듯

// 백준 15651번 문제 (백트래킹 - 3 : N과 M (3))

// 문제:
// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
    // 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
    // 같은 수를 여러 번 골라도 된다.

// 입력:
// 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

// 출력:
// 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
// 수열은 사전 순으로 증가하는 순서로 출력해야 한다.


#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    int N, M;
    cin >> N >> M;

// 계산 및 출력
    vector<int> number(M, 1);  // 자릿수같은 개념
    int n = pow(N,M); // 반복횟수 계산
    for (int i = 0; i < n; i++) {

    // 출력
        for (int i = 0; i < M; i++) {
            cout << number[i] << " ";
        }
        cout << "\n";


    // 출력 후, 마지막부터 숫자 올려주기. 받아올림 개념 생각.
        for (int i = M-1; i >= 0; i--) {
            if (number[i] >= N) {
                number[i] = 1;
            }
            else {
                number[i]++;
                break;
            }
        }
    }    

    return 0;
}