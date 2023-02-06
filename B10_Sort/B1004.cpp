// c++ 내장함수 'sort' 사용

// 백준 2751번 문제 (정렬 - 4 : 수 정렬하기 2)

// 문제:
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
// 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

// 출력:
// 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    using namespace std;

    int N;
    cin >> N;             // 입력의 개수 입력

    vector<int> num(N);   // 입력을 받을 공간
    for (int i = 0; i < N; i++) {
        cin >> num[i];    // 입력
    }

    sort(num.begin(), num.end());

    for (int i = 0; i < N; i++) {
        cout << num[i] << "\n";
    }

    return 0;
}