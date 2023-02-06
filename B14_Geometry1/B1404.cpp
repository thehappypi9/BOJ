// 백준 2477번 문제 (기하 1 - 4 : 참외밭)

// 문제:
// 시골에 있는 태양이의 삼촌 댁에는 커다란 참외밭이 있다. 문득 태양이는 이 밭에서 자라는 참외가 도대체 몇 개나 되는지 궁금해졌다.
// 어떻게 알아낼 수 있는지 골똘히 생각하다가 드디어 좋은 아이디어가 떠올랐다. 유레카!
// 1m^2의 넓이에 자라는 참외 개수를 헤아린 다음, 참외밭의 넓이를 구하면 비례식을 이용하여 참외의 총개수를 구할 수 있다.
// 1m^2의 넓이에 자라는 참외의 개수는 헤아렸고, 이제 참외밭의 넓이만 구하면 된다.
// 참외밭은 ㄱ-자 모양이거나 ㄱ-자를 90도, 180도, 270도 회전한 모양(┏, ┗, ┛ 모양)의 육각형이다.
// 다행히도 밭의 경계(육각형의 변)는 모두 동서 방향이거나 남북 방향이었다.
// 밭의 한 모퉁이에서 출발하여 밭의 둘레를 돌면서 밭경계 길이를 모두 측정하였다.

// 예를 들어 참외밭이 위 그림과 같은 모양이라고 하자. 그림에서 오른쪽은 동쪽, 왼쪽은 서쪽, 아래쪽은 남쪽, 위쪽은 북쪽이다.
// 이 그림의 왼쪽위 꼭짓점에서 출발하여,
// 반시계방향으로 남쪽으로 30m, 동쪽으로 60m, 남쪽으로 20m, 동쪽으로 100m, 북쪽으로 50m, 서쪽으로 160m 이동하면 다시 출발점으로 되돌아가게 된다.
// 위 그림의 참외밭  면적은 6800m^2이다. 만약 1m^2의 넓이에 자라는 참외의 개수가 7이라면, 이 밭에서 자라는 참외의 개수는 47600으로 계산된다.
// 1m^2의 넓이에 자라는 참외의 개수와,
// 참외밭을 이루는 육각형의 임의의 한 꼭짓점에서 출발하여 반시계방향으로 둘레를 돌면서 지나는 변의 방향과 길이가 순서대로 주어진다.
// 이 참외밭에서 자라는 참외의 수를 구하는 프로그램을 작성하시오.

// 입력:
// 첫 번째 줄에 1m^2의 넓이에 자라는 참외의 개수를 나타내는 양의 정수 K (1 ≤ K ≤ 20)가 주어진다.
// 참외밭을 나타내는 육각형의 임의의 한 꼭짓점에서 출발하여 반시계방향으로 둘레를 돌면서 지나는 변의 방향과 길이 (1 이상 500 이하의 정수)
// 가 둘째 줄부터 일곱 번째 줄까지 한 줄에 하나씩 순서대로 주어진다.
// 변의 방향에서 동쪽은 1, 서쪽은 2, 남쪽은 3, 북쪽은 4로 나타낸다.

// 출력:
// 첫째 줄에 입력으로 주어진 밭에서 자라는 참외의 수를 출력한다.


#include <iostream>
using namespace std;

enum Directions { EAST = 1, WEST, SOUTH, NORTH };

struct Coordinate {
    int x;
    int y;
};

int main() {

// 입력 (좌표로 저장)
    int K; cin >> K;
    Coordinate c[6];
    c[0] = {0, 0};
    int tmpD = 0, tmpW = 0;
    for (int i = 1; i < 6; i++) {
        cin >> tmpD >> tmpW;
        switch(tmpD) {
            case EAST:
                c[i] = { c[i-1].x + tmpW, c[i-1].y };
                break;
            case WEST:
                c[i] = { c[i-1].x - tmpW, c[i-1].y };
                break;
            case SOUTH:
                c[i] = { c[i-1].x, c[i-1].y - tmpW };
                break;
            case NORTH:
                c[i] = { c[i-1].x, c[i-1].y + tmpW };
                break;
            default:
                break;
        }
    }

// 점 찍어서 넓이 판별할 방법을 생각해보자.
// 큰 사각형 - 작은 사각형 하면 될 것 같다.

// 좌표들 중 동서남북 끝 좌표를 구한다.
    int max_x = c[0].x;  // 동쪽 끝 (x좌표가 가장 큰 곳)
    int min_x = c[0].x;  // 서쪽 끝
    int max_y = c[0].y;  // 북쪽 끝
    int min_y = c[0].y;  // 남쪽 끝
    for (int i = 0; i < 6; i++) {
        if (c[i].x > max_x) { max_x = c[i].x; }
        if (c[i].x < min_x) { min_x = c[i].x; }
        if (c[i].y > max_y) { max_y = c[i].y; }
        if (c[i].y < min_y) { min_y = c[i].y; }
    }

// 좌표들 중 가운데에 들어가 있는 점의 좌표를 구한다. (x좌표, y좌표 둘 다 어느 방위의 끝이 아닌 점)
    Coordinate center;
    for (int i = 0; i < 6; i++) {
        if (c[i].x != max_x && c[i].x != min_x) { center.x = c[i].x; }
        if (c[i].y != max_y && c[i].y != min_y) { center.y = c[i].y; }
    }

// 큰 사각형을 이루는 네 번째 점을 찾는다.
    Coordinate fourth;
    int check[4] = {};
    for (int i = 0; i < 6; i++) {
        if (c[i].x == max_x && c[i].y == max_y) { check[0]++; } // 큰 사각형의 세 점 중, 북동쪽 끝 점이 있으면 check[0] = 1
        if (c[i].x == max_x && c[i].y == min_y) { check[1]++; } // 큰 사각형의 세 점 중, 남동쪽 끝 점이 있으면 check[1] = 1
        if (c[i].x == min_x && c[i].y == max_y) { check[2]++; } // 큰 사각형의 세 점 중, 북서쪽 끝 점이 있으면 check[2] = 1
        if (c[i].x == min_x && c[i].y == min_y) { check[3]++; } // 큰 사각형의 세 점 중, 남동쪽 끝 점이 있으면 check[3] = 1
    }

    if (check[0] == 0) { fourth = {max_x, max_y}; }
    else if (check[1] == 0) { fourth = {max_x, min_y}; }
    else if (check[2] == 0) { fourth = {min_x, max_y}; }
    else { fourth = {min_x, min_y}; }

// 큰 사각형의 넓이와 작은 사각형의 넓이
    int big_rect = (max_x - min_x) * (max_y - min_y);
    int small_rect = abs(fourth.x - center.x) * abs(fourth.y - center.y);

// 출력
    cout << K * (big_rect - small_rect);



    return 0;
}