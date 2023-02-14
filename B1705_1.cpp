// "메모리 초과"
// 이중 for문이라, 아마 시간초과도 날 것.
// 백준 1912번 문제 (동적 계획법 1 - 5 : 연속합)
// https://www.acmicpc.net/problem/1912

#include <iostream>
#include <vector>
using namespace std;


int main() {


// 입력
    int n;
    cin >> n;
    vector<short> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

// 계산
    vector<vector<short>> set(n, vector<short>(n-1));
    for (int i = 0; i < n; i++) {
        set[i][0] = numbers[i];
    }
    int max = set[0][0]; // 최댓값 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n-1; j++) {
            if (i+j < n) {
                set[i][j] = set[i][j-1] + numbers[i+j];
                if (set[i][j] > max) {
                    max = set[i][j];
                }
            }
        }
    }


    cout << max << endl;

    return 0;
}
