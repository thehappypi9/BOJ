// 백준 9184번 문제 (동적 계획법 1 - 2 : 신나는 함수 실행)
// https://www.acmicpc.net/problem/9184

#include <iostream>
#include <vector>
using namespace std;


// 재귀를 썼을 때 (엄청 느리다)
/*
int w1(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20) {
        return w1(20, 20, 20);
    }
    else if (a < b && b < c) {
        return w1(a, b, c-1) + w1(a, b-1, c-1) - w1(a, b-1, c);
    }
    else {
        return w1(a-1, b, c) + w1(a-1, b-1, c) + w1(a-1, b, c-1) - w1(a-1, b-1, c-1);
    }
}
*/


int main() {


    vector<vector<vector<int>>> w(21, vector<vector<int>> (21, vector<int> (21, 1)));  // 3차원 벡터, 1로 초기화
    

    for (int a = 1; a <= 20; a++) {
        for (int b = 1; b <= 20; b++) {
            for (int c = 1; c <= 20; c++) {
                if (a <= 0 || b <= 0 || c <= 0) {
                    w[a][b][c] = 1;
                }
                else if (a < b && b < c) {
                    w[a][b][c] = w[a][b][c-1] + w[a][b-1][c-1] - w[a][b-1][c];
                }
                else {
                    w[a][b][c] = w[a-1][b][c] + w[a-1][b-1][c] + w[a-1][b][c-1] - w[a-1][b-1][c-1];
                }
            }
        }
    }

    int in_a, in_b, in_c;
    int out;
    while(true) {
        cin >> in_a >> in_b >> in_c;
        if (in_a == -1 && in_b == -1 && in_c == -1) { break; }
        else {
            if (in_a <= 0 || in_b <= 0 || in_c <= 0) { out = 1; }
            else if (in_a > 20 || in_b > 20 || in_c > 20) { out = w[20][20][20]; }
            else { out = w[in_a][in_b][in_c]; }
            cout << "w(" << in_a << ", " << in_b << ", " << in_c << ") = " << out << "\n";
        }
    }

    return 0;
}
