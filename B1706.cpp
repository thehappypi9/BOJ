// https://cryptosalamander.tistory.com/84 참고 및 이해 후 코드 작성.
// 백준 1149번 문제 (동적 계획법 1 - 6 : RGB거리)
// https://www.acmicpc.net/problem/1149

#include <iostream>
#include <vector>
using namespace std;

int main() {

// 입력 및 계산
    int N;
    cin >> N;
    int R_start = 0, G_start = 0, B_start = 0;       // 각각 첫 집을 Red로 시작할지, Green으로 시작할지, Blue로 시작할지에 따른 비용 합.
    int n_R_start = 0, n_G_start = 0, n_B_start = 0; // 값을 바로 R_start, G_start, B_start에 넣기 전, 잠시 보관해놓는곳. (min 함수에서 전 단계의 R_start, ... 들만 볼 수 있도록.)
    int tmp_R, tmp_G, tmp_B;                         // R G B 각각의 비용을 입력받는 변수. 저장되지 않는다.
    for (int i = 0; i < N; i++) {
        cin >> tmp_R;
        n_R_start = min(G_start, B_start) + tmp_R;
        cin >> tmp_G;
        n_G_start = min(R_start, B_start) + tmp_G;
        cin >> tmp_B;
        n_B_start = min(R_start, G_start) + tmp_B;
        R_start = n_R_start;
        G_start = n_G_start;
        B_start = n_B_start;
    }

// 출력
    cout << min(min(R_start, G_start), B_start);



	return 0;
}