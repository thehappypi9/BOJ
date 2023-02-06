// "맞았습니다!!"
// hard copy 문제 해결. 기존의 스도쿠 판을 사용하되, 다음 빈 칸에 모든 경우를 넣어봤는데도 안 될 경우, 해당 빈 칸에 넣어놓았던 숫자를 다시 0으로 돌려놓는 작업 추가.

// 백준 2580번 문제 (백트래킹 - 6 : 스도쿠)

// 문제:
// (스도쿠에 대한 설명 참고: https://www.acmicpc.net/problem/2580)
// 게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

// 입력:
// 아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다.
// 스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.

// 출력:
// 모든 빈 칸이 채워진 스도쿠 판의 최종 모습을 아홉 줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력한다.
// 스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다.

// 제한:
// 12095번 문제에 있는 소스로 풀 수 있는 입력만 주어진다.
// C++14: 80ms
// Java: 292ms
// PyPy3: 1172ms


#include <iostream>
#include <vector>
using namespace std;

bool safe_checker(vector<vector<int>>* sudoku, int row, int col, int number) {
// 세로줄 확인
    for (int i = 0; i < 9; i++) {
        if ( (*sudoku)[i][col] == number) {
            return false;  // illegal. not safe.
        }
    }
// 가로줄 확인
    for (int j = 0; j < 9; j++) {
        if ( (*sudoku)[row][j] == number) {
            return false;  // illegal.
        }
    }
// 네모박스 확인
    int boxtop = (row/3)*3;
    int boxleft = (col/3)*3;
    for (int i = boxtop; i < boxtop+3; i++) {
        for (int j = boxleft; j < boxleft+3; j++) {
            if ( (*sudoku)[i][j] == number) {
                return false; // illegal.
            }
        }
    }
// 모두 확인했는데도 괜찮으면 legal.
    return true;
}

void dfs_sudoku(vector<vector<int>>* sudoku, int tmprow, int tmpcol, int number, int donerow, int* done) {

// 검사 후, illegal 하다면 return.
    //if (safe_checker(sudoku, tmprow, tmpcol, number) == false) { return; }

// 스도쿠 복제
    //vector<vector<int>> sudokuforhere(*sudoku);

// 복제한 스도쿠 업데이트
    (*sudoku)[tmprow][tmpcol] = number;

// 새로운 빈 칸을 찾아서 dfs.
    int newrow = -1;
    int newcol = -1;
    for (int i = donerow+1; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ( (*sudoku)[i][j] == 0 ) {
                newrow = i;
                newcol = j;
                for (int k = 1; k <= 9; k++) { // 1부터 9까지 중에서,
                    if (safe_checker(sudoku, newrow, newcol, k)) { // 넣어도 괜찮은 거면 넣어본다.
                        dfs_sudoku(sudoku, newrow, newcol, k, i-1, done);
                    }
                }
                i = 10;
                break;
            }
        }
    }
    
// 더 이상 빈 칸이 없을 때.
    if (newrow == -1) {
        (*done) = true;
        return;
    }

// (아직 다 못 풀었는데도) 다 해봤는데 다 안 될 때.
    if ((*done) == false) {
        (*sudoku)[tmprow][tmpcol] = 0; // 바꿔놓은 것 원위치.
        return;
    }
// 다 푼 상태일 때. - 원위치 안 하고 바로 return.
    else {
        return;
    }
}


void solve_sudoku(vector<vector<int>>* sudoku) {

    int done = false;
    int tmprow;
    int tmpcol;

// 가장 처음에 있는 빈칸 찾기.
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ( (*sudoku)[i][j] == 0 ) {
                tmprow = i;
                tmpcol = j;
                i = 10;
                break;
            }
        }
    }

// 가장 처음에 있는 빈칸에 넣어보기.
    for (int k = 1; k <= 9; k++) {
        if (safe_checker(sudoku, tmprow, tmpcol, k)) { // 1부터 9까지 중에서,
            dfs_sudoku(sudoku, tmprow, tmpcol, k, -1, &done); // 넣어도 괜찮은 거면 넣어본다.
        }
    }
}

int main() {

// 스도쿠 판 만들기
    vector<vector<int>> sudoku(9, vector<int>(9));

// 스도쿠 숫자 입력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }

// 풀이
    solve_sudoku(&sudoku);

// 출력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}