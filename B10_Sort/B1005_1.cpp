// 카운팅 정렬 (https://wondytyahng.tistory.com/entry/%EC%B9%B4%EC%9A%B4%ED%8C%85%EC%A0%95%EB%A0%AC)
// 이 코드를 백준에 제출하면 "메모리 초과"가 뜸.

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

    int N;
    cin >> N;             // 입력의 개수 입력

    vector<short> num(N);   // 입력을 받을 공간
    for (int i = 0; i < N; i++) {
        cin >> num[i];    // 입력
    }

    short max = 0;
    for (int i = 0; i < N; i++) {  // 배열의 최댓값 스캔
        if (num[i] > max) {
            max = num[i];
        }
    }

    vector<int> counting(max+1);        // Counting Array
    for (int i = 0; i <= max; i++) {    // 0부터 max까지 하나씩 세어본다.
        for (int j = 0; j < N; j++) {
            if (i == num[j]) {
                counting[i]++;
            }
        }
    }

    for (int i = 1; i <= max; i++) {    // Counting Array를 누적합으로 만들기.
        counting[i] += counting[i-1];
    }

    vector<short> sorted(N);
    for (int i = 0; i < N; i++) {
        sorted[counting[num[i]]-1] = num[i];
        counting[num[i]]--;
    }


// 출력
    for (int i = 0; i < N; i++) {
        cout << sorted[i] << endl;
    }

    return 0;
}