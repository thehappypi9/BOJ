// "맞았습니다!!"
// C++ 내장함수 upper_bound, lower_bound 사용

// 백준 10816번 문제 (집합과 맵 - 4 : 숫자 카드 2)

// 문제:
// 숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다.
// 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다.
// 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
// 셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다.
// 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다.
// 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

// 출력:
// 첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Tester(vector<int>* whatHeHas, int testThis);
bool Test(vector<int>* whatHeHas, int testThis, int left, int right);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    int N; cin >> N;
    vector<int> HeHas(N);
    for (int i = 0; i < N; i++) { cin >> HeHas[i]; }
    int M; cin >> M;
    vector<int> HowMany(M);
    for (int j = 0; j < M; j++) { cin >> HowMany[j]; }

// 정렬
    sort(HeHas.begin(), HeHas.end());

// 계산 및 출력
    for (int j = 0; j < M; j++) {
        if (Tester(&HeHas, HowMany[j])) {   // 있으면
            cout << upper_bound(HeHas.begin(), HeHas.end(), HowMany[j]) - lower_bound(HeHas.begin(), HeHas.end(), HowMany[j]) << " ";
        }
        else {  // 없으면
            cout << "0 ";
        }
    }

    return 0;
}

bool Tester(vector<int>* whatHeHas, int testThis) {
    int size = int((*whatHeHas).size());
    int left = 0; int right = size-1;
    return Test(whatHeHas, testThis, left, right);
}

bool Test(vector<int>* whatHeHas, int testThis, int left, int right) {
    int mid = (left+right)/2;
    if (left == right) {
        if ((*whatHeHas)[mid] == testThis) { return true; }
        else { return false; }
    }
    else {
        if ((*whatHeHas)[mid] == testThis) { return true; }
        else if ((*whatHeHas)[mid] < testThis) { return Test(whatHeHas, testThis, mid+1, right); }
        else { return Test(whatHeHas, testThis, left, mid); }
    }
    return 0;
}