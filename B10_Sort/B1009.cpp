// 백준 11651번 문제 (정렬 - 9 : 좌표 정렬하기 2)

// 문제:
// 2차원 평면 위의 점 N개가 주어진다.
// 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000)
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
        cin >> c[i][1] >> c[i][0]; // 여기가 바로 앞 문제와 다르다. x좌표를 c[i][1]에 넣고, y좌표를 c[i][0]에 넣는다. -> 정렬할떄 y좌표가 더 우선.
    }

    sort(c.begin(), c.end()); 

    for (int i = 0; i < N; i++) {
        cout << c[i][1] << " " << c[i][0] << "\n";
    }

    return 0;
}