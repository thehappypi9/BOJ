// 벡터를 함수에 레퍼런스 인자로 넘기기

// 백준 2447번 문제 (재귀 - 5 : 별 찍기 - 10)

// 문제:
// 재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.
// 크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.
    // ***
    // * *
    // ***
// N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다. 예를 들어 크기 27의 패턴은 예제 출력 1과 같다.

// 입력:
// 첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3^k이며, 이때 1 ≤ k < 8이다.

// 출력:
// 첫째 줄부터 N번째 줄까지 별을 출력한다.

#include <iostream>
#include <vector>
using namespace std;

void Star(int, int, int, vector<vector<int>>&);

void Makestar(int N) {
    vector<vector<int>> papers(N, vector<int>(N));   // N*N짜리 행렬벡터(aka.대지)를 하나 만듦.

    Star(0, 0, N, papers);  // Star함수 실행

    // 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (papers[i][j]) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void Star (int x, int y, int length, vector<vector<int>>& papers) {
    if (length == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                (papers)[x+i][y+j] = 1;
            }
        }
        (papers)[x+1][y+1] = 0;
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {}
                else {
                    Star(x+i*(length/3), y+j*(length/3), length/3, papers);
                }
            }
        }
    }
}

int main() {

    int N;
    cin >> N;
    Makestar(N);

    return 0;
}



