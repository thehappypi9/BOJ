// 규칙 찾기 쉬움. 구현도 쉬움. 단, int로 했을 때 오버플로우만 조심.
// 백준 9461번 문제 (동적 계획법 1 - 4 : 파도반 수열)
// https://www.acmicpc.net/problem/9461

#include <iostream>
#include <vector>
using namespace std;


int main() {

    vector<unsigned long long> P(101);
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;
    P[4] = 2;
    P[5] = 2;
    for (int i = 6; i <= 100; i++) {
        P[i] = P[i-1] + P[i-5];
    }

    int T;
    cin >> T;
    int N;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << P[N] << "\n";
    }

    return 0;
}
