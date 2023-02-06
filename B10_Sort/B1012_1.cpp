// "시간초과"

// 백준 18870번 문제 (정렬 - 12 : 좌표 압축)

// 문제:
// 수직선 위에 N개의 좌표 X_1, X_2, ..., X_N이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.
// X_i를 좌표 압축한 결과 X'_i의 값은 X_i > X_j를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
// X_1, X_2, ..., X_N에 좌표 압축을 적용한 결과 X'_1, X'_2, ..., X'_N를 출력해보자.

// 입력:
// 첫째 줄에 N이 주어진다.
// 둘째 줄에는 공백 한 칸으로 구분된 X_1, X_2, ..., X_N이 주어진다.

// 출력:
// 첫째 줄에 X'_1, X'_2, ..., X'_N을 공백 한 칸으로 구분해서 출력한다.

// 제한:
// 1 ≤ N ≤ 1,000,000
// -10^9 ≤ X_i ≤ 10^9


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    int N;
    cin >> N;             //  ex) 5
    vector<int> c(N);
    vector<int> s1(N);
    vector<int> s2(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];             //  ex) c = { 2, 4, -10, 4, -9 }
        s1[i] = c[i];            //  ex) s1 = { 2, 4, -10, 4, -9 }
    }

// 정렬
    sort(s1.begin(), s1.end());  //  ex) s1 = { -10, -9, 2, 4, 4 }
    
    int count = -1;
    for (int i = 0; i < N; i++) {
        if (i == 0 || s1[i] != s1[i-1]) {   // 0번째는 프리패스, or 직전 원소와 다르면 패스
            s2[i] = ++count;
        }
        else {
            s2[i] = count;
        }
    }
    //  ex) s2 = { 0, 1, 2, 3, 3 }

// 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (c[i] == s1[j]) {
                cout << s2[j] << " ";
                break;
            }       
        }
    }

    return 0;
}