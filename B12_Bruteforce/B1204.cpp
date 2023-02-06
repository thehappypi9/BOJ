// 백준 1018번 문제 (브루트 포스 - 4 : 체스판 다시 칠하기)

// 문제:
// 지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다.
// 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.
// 체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다.
// 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다.
// 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.
// 보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8x8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다.
// 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
// 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

// 출력:
// 첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.


#include <iostream>
#include <vector>
using namespace std;

int main() {

// 입력
    int N;
    int M;
    cin >> N >> M;
    vector<vector<char>> board(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

// 계산
    int WhiteStartError = 0; // 맨 왼쪽 위 정사각형 is supposed to be White 일 때, 다시 칠해야하는 정사각형 수.(for 안에서 임시로 쓰인다.)
    int BlackStartError = 0; // 맨 왼쪽 위 정사각형 is supposed to be Black 일 때, 다시 칠해야하는 정사각형 수.(for 안에서 임시로 쓰인다.)
    int minW = 65;  // 다시 칠할 수 있는 정사각형의 "최대" 개수는 64개. 65는 무엇보다도 크다.
    int minB = 65;
    for (int i = 0; i <= N-8; i++) {    // 맨 왼쪽 위 정사각형(기준)은 board[0][0] ~ board[N-8][M-8] 까지만 된다.
        for (int j = 0; j <= M-8; j++) {
            // test starting point = board[i][j]. 테스트 기준점(board[i][j])에서 시작한 8x8 행렬에서 WhiteStartError, BlackStartError를 계산.
            WhiteStartError = 0; BlackStartError = 0;
            for (int m = i; m < i+8; m++) {
                for (int n = j; n < j+8; n++) {
                    if ((m+n)%2==0 && board[m][n]=='B') { WhiteStartError++; }
                    else if ((m+n)%2==0 && board[m][n]=='W') { BlackStartError++; }
                    else if ((m+n)%2==1 && board[m][n]=='B') { BlackStartError++; }
                    else if ((m+n)%2==1 && board[m][n]=='W') { WhiteStartError++; }
                    else { cout << "WTF"; }
                }
            }
            if (WhiteStartError < minW) { minW = WhiteStartError; } // 그렇게 나온 다시 칠해야 하는 정사각형 수가 여태 최솟값일땐 따로 빼놓는다.
            if (BlackStartError < minB) { minB = BlackStartError; }
        }
    }

// 출력
    if (minW < minB) { cout << minW; }
    else { cout << minB; }

    return 0;
}