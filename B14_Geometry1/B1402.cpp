// 세 점들의 x좌표에는 겹치는 것이 2개 있고, 안 겹치는 것이 1개 있다. y좌표도 마찬가지.
// 안 겹치는 것이 바로 네 번째 점의 x, y좌표이다.

// 백준 3009번 문제 (기하 1 - 2 : 네 번째 점)

// 문제:
// 세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

// 입력:
// 세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

// 출력:
// 직사각형의 네 번째 점의 좌표를 출력한다.


#include <iostream>
#include <algorithm>
using namespace std;

int main() {

// 입력
    int x[3];
    int y[3];
    cin >> x[0] >> y[0];
    cin >> x[1] >> y[1];
    cin >> x[2] >> y[2];

// 정렬하면, 가운데 값인 x[1], y[1]은 무조건 겹치는 것이 된다.
    sort(x, x+3);
    sort(y, y+3);

// 안 겹치는 x, y좌표 찾기
    int fourth_x, fourth_y;
    if (x[0] == x[1]) { fourth_x = x[2]; }
    else { fourth_x = x[0]; }

    if (y[0] == y[1]) { fourth_y = y[2]; }
    else { fourth_y = y[0]; }

// 출력
    cout << fourth_x << " " << fourth_y;

    return 0;
}