// "맞았습니다!!"

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
    for (int i = 0; i < N; i++) {
        cin >> c[i];             //  ex) c = { 2, 4, -10, 4, -9 }
        s1[i] = c[i];            //  ex) s1 = { 2, 4, -10, 4, -9 }
    }

// 정렬
    sort(s1.begin(), s1.end());  //  ex) s1 = { -10, -9, 2, 4, 4 }
// 중복제거 (중복된 값들을 가장 크게 올린다.)
    vector<int> check(N, 0);
    for (int i = 1; i < N; i++) {
        if (s1[i] == s1[i-1]) {
            check[i]++;          // 중복된 값들의 index 따로 저장해놓음.
        }
    }
    for (int i = 0; i < N; i++) {
        if (check[i]) {          // 중복된 값이면,
            s1[i] = 1000000001;  // 그것을 입력최댓값+1 로 만든다.
        }
    }
// 다시 정렬 (가장 커진 중복값들은 이제 맨 뒤로 간다.)
    sort(s1.begin(), s1.end());
    
// 출력
    for (int i = 0; i < N; i++) {
        cout << lower_bound(s1.begin(), s1.end(), c[i])-s1.begin() << " ";
    }

    return 0;
}