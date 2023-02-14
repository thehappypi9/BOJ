// 처음에는 '헉' 했으나, 알고리즘 생각하는 과정과 구현하는 과정이 크게 어렵지 않았고 재미있었음.
// 백준 2579번 문제 (동적 계획법 1 - 8 : 계단 오르기)
// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>
using namespace std;

int main() {

// 입력 및 계산
    int n;
    cin >> n;
    vector<vector<int>> history(3, vector<int>(2, 0));
    // history[i][j]에 든 값은 그때까지의 최댓값. i, j는 각각 history를 나타내는 index.
    // [0][0] : 2전 계단, 연속으로 한 칸 오른 계단 수 = 0 / [0][1] : 2전 계단, 연속으로 한 칸 오른 계단 수 = 1
    // [1][0] : 1전 계단, 연속으로 한 칸 오른 계단 수 = 0 / [1][1] : 1전 계단, 연속으로 한 칸 오른 계단 수 = 1
    // [2][0] : 현재 계단, 연속으로 한 칸 오른 계단 수 = 0 / [2][1] : 현재 계단, 연속으로 한 칸 오른 계단 수 = 1
    // [2][0]의 값은, [0][0]의 값과 [0][1]의 값 중 더 큰 값 + 현 계단의 value(tmp) 로 정해짐.
    // [2][1]의 값은, [1][0]의 값 + 현 계단의 value(tmp)로 정해짐.
    // 계단 한 칸 올라갈 때마다 [1], [2]의 값들은 각각 [0], [1]로 내려감.

    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp; // 현 계단의 value.
        if (i == 1) {
            history[2][0] = tmp;
        }
        else {
            history[2][0] = std::max(history[0][0], history[0][1]) + tmp;
            history[2][1] = history[1][0] + tmp;
        }

    // 계단 올라가는 과정
        history[0][0] = history[1][0];
        history[0][1] = history[1][1];
        history[1][0] = history[2][0];
        history[1][1] = history[2][1];
    }

// 출력
    cout << std::max(history[1][0], history[1][1]);


	return 0;
}