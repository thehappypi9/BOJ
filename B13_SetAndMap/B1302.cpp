// 바로 앞 문제와 굉장히 유사. 앞 문제의 벡터 원소 자료형을 int에서 string으로만 바꾸면 ok.

// 백준 14425번 문제 (집합과 맵 - 2 : 문자열 집합)

// 문제:
// 총 N개의 문자열로 이루어진 집합 S가 주어진다.
// 입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇 개인지 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 문자열의 개수 N과 M (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10,000)이 주어진다. 
// 다음 N개의 줄에는 집합 S에 포함되어 있는 문자열들이 주어진다.
// 다음 M개의 줄에는 검사해야 하는 문자열들이 주어진다.
// 입력으로 주어지는 문자열은 알파벳 소문자로만 이루어져 있으며, 길이는 500을 넘지 않는다. 집합 S에 같은 문자열이 여러 번 주어지는 경우는 없다.

// 출력:
// 첫째 줄에 M개의 문자열 중에 총 몇 개가 집합 S에 포함되어 있는지 출력한다.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Tester(vector<string>*, string);
bool Test(vector<string>*, string, int, int);

int main() {

// 입력
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    vector<string> TestMe(M);
    for (int i = 0; i < N; i++) { cin >> S[i]; }
    for (int j = 0; j < M; j++) { cin >> TestMe[j]; }

// 정렬
    sort(S.begin(), S.end());

// 확인 및 출력
    int count = 0;
    for (int j = 0; j < M; j++) {
        if(Tester(&S, TestMe[j])) { count++; }
    }
    cout << count;

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