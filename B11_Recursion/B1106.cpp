// 백준 11729번 문제 (재귀 - 6 : 하노이 탑 이동 순서)

// 문제:
// 세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 큰 순서대로 쌓여있다.
// 이제 수도승들이 다음 규칙에 따라 첫 번째 장대에서 세 번째 장대로 옮기려 한다.
    // 1. 한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
    // 2. 쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
// 이 작업을 수행하는데 필요한 이동 순서를 출력하는 프로그램을 작성하라. 단, 이동 횟수는 최소가 되어야 한다.
//아래 그림은 원판이 5개인 경우의 예시이다.

// 입력:
// 첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.

// 출력:
// 첫째 줄에 옮긴 횟수 K를 출력한다.
// 두 번째 줄부터 수행 과정을 출력한다.
// 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데, 이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다.


#include <iostream>
#include <vector>
using namespace std;

void MakeHanoi(int);
void Hanoi(int, vector<int>&, int, vector<vector<int>>&);


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    MakeHanoi(N);

    return 0;
}


void MakeHanoi(int N) {
    vector<int> H(N, 1);    // 처음엔 N개의 원판이 모두 1번째 탑에 있다.
    int where = 3;          // N개의 원판을 3번째 탑으로 옮기라고 명령하기 위해 처음에는 where를 3으로 설정.
    vector<vector<int>> log; // 어디서 어디로 옮겼는지 기록할 2차원 벡터
    Hanoi(N, H, where, log);
//출력
    cout << log.size() << "\n";
    for (int i = 0; i < int(log.size()); i++) {
        cout << log[i][0] << " " << log[i][1] << "\n";
    }
}

void Hanoi(int n, vector<int>& H, int where, vector<vector<int>>& log) {   // H에 들어있는 n개를 where로 옮긴다.
    if (n == 1) {
        log.push_back({H[0], where});
        H[0] = where;
    }
    else {
        int elsewhere;  // elsewhere 라는 것을 만든다. elsewhere는 n-1개의 더미를 옮길 곳인데, where도 아니고, 현재 n개의 더미가 있는 곳도 아닌 곳이다.
        if (where != 1 && H[n-2] != 1) { elsewhere = 1; }
        else if (where != 2 && H[n-2] != 2) { elsewhere = 2; }
        else { elsewhere = 3; }

        Hanoi(n-1, H, elsewhere, log);  // n-1개의 더미를 elsewhere로 옮긴다.
        log.push_back({H[n-1], where});        // 옮기기 전 어디서 어디로 옮기는지 기록
        H[n-1] = where;                        // n번째 원판(이 함수에서 옮기고자 한 더미에서 맨 밑에 있던 원판)을 where로 옮긴다.
        Hanoi(n-1, H, where, log);
    }
}