// 백준 11650번 문제 (정렬 - 8 : 좌표 정렬하기)

// 문제:
// 2차원 평면 위의 점 N개가 주어진다.
// 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 i번점의 위치 x_i와 y_i가 주어진다. (-100,000 ≤ x_i, y_i ≤ 100,000)
// 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

// 출력:
// 첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> c(N, vector<int>(2,0));
    for (int i = 0; i < N; i++) {
        cin >> c[i][0] >> c[i][1];
    }
    
    // 그냥 이렇게 하니까 알아서 앞에 있는 원소(c[i][0], x좌표) 1순위로 정렬하고 두번째 원소(c[i][1], y좌표)를 2순위로 정렬해주네!
    sort(c.begin(), c.end()); 

    for (int i = 0; i < N; i++) {
        cout << c[i][0] << " " << c[i][1] << "\n";
    }

    return 0;
}