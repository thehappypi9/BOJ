// 백준 1085번 문제 (기하 1 - 1 : 직사각형에서 탈출)

// 문제:
// 한수는 지금 (x, y)에 있다.
// 직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다.
// 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 x, y, w, h가 주어진다.

// 출력:
// 첫째 줄에 문제의 정답을 출력한다.

// 제한:
// 1 ≤ w, h ≤ 1,000
// 1 ≤ x ≤ w-1
// 1 ≤ y ≤ h-1
// x, y, w, h는 정수


#include <iostream>
using namespace std;

int main() {

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int candidate[4] = {x, y, w-x, h-y};

    int min = candidate[0];
    for (int i = 0; i < 4; i++) {
        if (candidate[i] < min) {
            min = candidate[i];
        }
    }
    cout << min;

    return 0;
}