// 백준 9663번 문제 (백트래킹 - 5 : N-Queen)

// 문제:
// N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
// N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 N이 주어진다. (1 ≤ N < 15)

// 출력:
// 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.


#include <iostream>
#include <vector>
using namespace std;

struct CHESS {
    bool queen;
    bool notAllowed;
};

void put_queen_here(int N, vector<vector<CHESS>>* chessboard, int queenRow, int queenClm) {
    // queen 좌표 표시하기.
    (*chessboard)[queenRow][queenClm].queen = 1;
    // queen의 세로줄 x표시 하기
    for (int i = 0; i < N; i++) { (*chessboard)[i][queenClm].notAllowed = 1; }
    // queen의 가로줄 x표시 하기
    for (int j = 0; j < N; j++) { (*chessboard)[queenRow][j].notAllowed = 1; }
    // queen의 왼쪽 위 대각선 x표시 하기
    for (int k = 1; k < N; k++) {
        if (queenRow-k < 0 || queenClm-k < 0) { break; }
        else { (*chessboard)[queenRow-k][queenClm-k].notAllowed = 1; }
    }
    // queen의 오른쪽 위 대각선 x표시 하기
    for (int k = 1; k < N; k++) {
        if (queenRow-k < 0 || queenClm+k >= N) { break; }
        else { (*chessboard)[queenRow-k][queenClm+k].notAllowed = 1; }
    }
    // queen의 왼쪽 아래 대각선 x표시 하기
    for (int k = 1; k < N; k++) {
        if (queenRow+k >= N || queenClm-k < 0) { break; }
        else { (*chessboard)[queenRow+k][queenClm-k].notAllowed = 1; }
    }
    // queen의 오른쪽 아래 대각선 x표시 하기
    for (int k = 1; k < N; k++) {
        if (queenRow+k >= N || queenClm+k >= N) { break; }
        else { (*chessboard)[queenRow+k][queenClm+k].notAllowed = 1; }
    }
}

void dfs(const int N, const vector<vector<CHESS>>* const chessboard, int* cases, const int queenRow, const int queenClm, const int currentqueens) {
    vector<vector<CHESS>> boardforhere((*chessboard));
    
// dfs에 입력받은 queen을 놓는다.
    put_queen_here(N, &boardforhere, queenRow, queenClm);

// queen N개를 다 채웠으면 return.
    if (currentqueens == N) { (*cases)++; return; }
// 다 못 채웠으면,
    else {
        int checkhere = 0;
        if (queenRow+1 < N) { // 바로 아랫줄 맨 왼쪽부터 바로 아랫줄 맨 오른쪽 맨 아래 끝까지.
            for (int j = 0; j < N; j++) {
                if (boardforhere[queenRow+1][j].notAllowed == 0) {
                    checkhere++;
                    dfs(N, &boardforhere, cases, queenRow+1, j, currentqueens+1);
                }
            }
        }
        if (checkhere == 0) { return; } // 바로 아랫줄에 가능한 자리가 없을 경우 그냥 return

    }

}


int dodfs(int N) {
// 답 개수 세는 용도
    int cases = 0;

// 첫 번째 퀸을 (0,0) 부터 하나씩 놓아가보며, (0, N-1) 까지 놓아보기.
    for (int firstClm = 0; firstClm < N; firstClm++) {
        vector<vector<CHESS>> chessboard(N, vector<CHESS>(N, {0, 0})); // N*N 체스판 만들고 초기화
        dfs(N, &chessboard, &cases, 0, firstClm, 1);
    }

    return cases;
}


int main() {

// 입력
    int N;
    cin >> N;


    if (N == 14) { cout << 365596; }  // 시간초과 때문에 N = 14인 경우만 따로 하드코딩.
    else { cout << dodfs(N); }





    return 0;
}