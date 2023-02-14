// B1706과 비슷한 알고리즘. B1706을 하고 난 후라 쉬웠다.
// 백준 1932번 문제 (동적 계획법 1 - 7 : 정수 삼각형)
// https://www.acmicpc.net/problem/1932

#include <iostream>
#include <vector>
using namespace std;

int main() {

// 입력 및 계산
    int n;
    cin >> n;
    vector<int> results(n+1);   // 한 줄 한 줄 내려가면서 이전 줄까지의 총합은 버리고 새로새로 내려오며 가능한 최댓값 후보들을 저장해놓는 벡터.
    vector<int> n_results(n+1); // 임시 저장용.
    int tmp;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tmp;
            if (j == 1) {
                n_results[1] += tmp;
            }
            else if (j == i) {
                n_results[j] = results[j-1] + tmp;
            }
            else {
                n_results[j] = std::max(results[j-1], results[j]) + tmp;
            }
        }
        for (int j = 1; j <= i; j++) {
            results[j] = n_results[j];
            if (results[j] > max) {
                max = n_results[j];
            }
        }
    }


// 출력
    cout << max;


	return 0;
}