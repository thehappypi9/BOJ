// "시간 초과"
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
    int max = numbers[0]; // 최댓값 초기화.
    vector<short> tmp(n);

    for (int i = 0; i < n; i++) {
        tmp[0] = numbers[i];
        for (int j = 0; j < n-1; j++) {
            if (j > 0 && i+j < n) {
                tmp[j] = tmp[j-1] + numbers[i+j];
            }
            if (tmp[j] > max) {
                max = tmp[j];
            }
        }
    }

// 출력
    cout << max << endl;

    return 0;
}
