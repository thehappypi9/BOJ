// 백준 2566번 문제 (2차원 배열 - 2 : 최댓값)

// 문제:
// <그림 1>과 같이 9×9 격자판에 쓰여진 81개의 자연수 또는 0이 주어질 때,
// 이들 중 최댓값을 찾고 그 최댓값이 몇 행 몇 열에 위치한 수인지 구하는 프로그램을 작성하시오.
// 예를 들어, 다음과 같이 81개의 수가 주어지면
// (사진 참조) https://www.acmicpc.net/problem/2566
// 이들 중 최댓값은 90이고, 이 값은 5행 7열에 위치한다.

// 입력:
// 첫째 줄부터 아홉 번째 줄까지 한 줄에 아홉 개씩 수가 주어진다. 주어지는 수는 100보다 작은 자연수 또는 0이다.

// 출력:
// 첫째 줄에 최댓값을 출력하고, 둘째 줄에 최댓값이 위치한 행 번호와 열 번호를 빈칸을 사이에 두고 차례로 출력한다.
// 최댓값이 두 개 이상인 경우 그 중 한 곳의 위치를 출력한다.


#include <iostream>
#include <vector>

int main() {

    using namespace std;

    int N = 9, M = 9;    // N : 행, M : 열

    vector<vector<int>> A(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int max = 0;
    int row = 1;
    int column = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
                row = i+1;
                column = j+1;
            }
        }
    }

    cout << max << endl;
    cout << row << " " << column << endl;

    return 0;
}