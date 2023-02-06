// 카운팅 정렬 (https://wondytyahng.tistory.com/entry/%EC%B9%B4%EC%9A%B4%ED%8C%85%EC%A0%95%EB%A0%AC)
// "맞았습니다!!"

// 백준 10989번 문제 (정렬 - 5 : 수 정렬하기 3)

// 문제:
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

// 출력:
// 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.


#include <iostream>
#include <vector>

int main() {

    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;             // 입력의 개수 입력

    vector<int> counting(10001);
    int m = 0;
    for (int i = 0; i < N; i++) {
        cin >> m;
        counting[m]++;
    }


    for (int i = 0; i <= 10000; i++) {
        while (true) {
            if (counting[i] > 0) {
                cout << i << "\n";
                counting[i]--;
            }
            else {
                break;
            }
        }
    }

    return 0;
}