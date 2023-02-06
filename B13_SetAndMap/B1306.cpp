// A의 원소의 개수 + B의 원소의 개수 - 2*(A와 B의 합집합의 원소의 개수)

// 백준 1269번 문제 (집합과 맵 - 6 : 대칭 차집합)

// 문제:
// 자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다.
// 이때, 두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오.
// 두 집합 A와 B가 있을 때, (A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다.
// 예를 들어, A = { 1, 2, 4 } 이고, B = { 2, 3, 4, 5, 6 } 라고 할 때,  A-B = { 1 } 이고, B-A = { 3, 5, 6 } 이므로,
// 대칭 차집합의 원소의 개수는 1 + 3 = 4개이다.

// 입력:
// 첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다.
// 둘째 줄에는 집합 A의 모든 원소가, 셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 각각 주어진다.
// 각 집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.

// 출력:
// 첫째 줄에 대칭 차집합의 원소의 개수를 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Tester(vector<int>* whatItHas, int testThis);
bool Test(vector<int>* whatItHas, int testThis, int left, int right);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    vector<int> B(M);
    for (int j = 0; j < M; j++) { cin >> B[j]; }

// 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

// 합집합 계산 및 저장
    vector<int> Union;
    for (int i = 0; i < N; i++) {
        if (Tester(&B, A[i])) { Union.push_back(A[i]); }
    }

// 정답 계산 및 출력
    cout << N + M - 2*(Union.size());

    return 0;
}


bool Tester(vector<int>* whatItHas, int testThis) {
    int size = int((*whatItHas).size());
    int left = 0; int right = size-1;
    return Test(whatItHas, testThis, left, right);
}

bool Test(vector<int>* whatItHas, int testThis, int left, int right) {
    int mid = (left+right)/2;
    if (left == right) {
        if ((*whatItHas)[mid] == testThis) { return true; }
        else { return false; }
    }
    else {
        if ((*whatItHas)[mid] == testThis) { return true; }
        else if ((*whatItHas)[mid] < testThis) { return Test(whatItHas, testThis, mid+1, right); }
        else { return Test(whatItHas, testThis, left, mid); }
    }
    return 0;
}