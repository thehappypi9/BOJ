// 백준 1764번 문제 (집합과 맵 - 5 : 듣보잡)

// 문제:
// 김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다.
// 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다.
// 이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.
// 듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

// 출력:
// 듣보잡의 수와 그 명단을 사전순으로 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// B1301에서 가져온 함수들. 검사하는 변수의 자료형만 int에서 string으로 바꾸었다.
bool Tester(vector<string>* whatItHas, string testThis);
bool Test(vector<string>* whatItHas, string testThis, int left, int right);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    int N, M;
    cin >> N >> M;
    vector<string> NotHeard(N);
    for (int i = 0; i < N; i++) { cin >> NotHeard[i]; }
    vector<string> NotSeen(M);
    for (int j = 0; j < M; j++) { cin >> NotSeen[j]; }

// 정렬
    sort(NotHeard.begin(), NotHeard.end());
    sort(NotSeen.begin(), NotSeen.end());

// 계산 및 저장
    vector<string> Neither;
    if (N < M) {
        for (int i = 0; i < N; i++) {
            if (Tester(&NotSeen, NotHeard[i])) { Neither.push_back(NotHeard[i]); }
        }
    }
    else {
        for (int j = 0; j < M; j++) {
            if (Tester(&NotHeard, NotSeen[j])) { Neither.push_back(NotSeen[j]); }
        }
    }

// 저장된 답 사전 순 정렬
    sort(Neither.begin(), Neither.end());
    int size = Neither.size();
    cout << size << "\n";
    for (int k = 0; k < size; k++) {
        cout << Neither[k] << "\n";
    }

    return 0;
}


bool Tester(vector<string>* whatItHas, string testThis) {
    int size = int((*whatItHas).size());
    int left = 0; int right = size-1;
    return Test(whatItHas, testThis, left, right);
}

bool Test(vector<string>* whatItHas, string testThis, int left, int right) {
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