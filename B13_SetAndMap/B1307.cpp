// 백준 11478번 문제 (집합과 맵 - 7 : 서로 다른 부분 문자열의 개수)

// 문제:
// 문자열 S가 주어졌을 때, S의 서로 다른 부분 문자열의 개수를 구하는 프로그램을 작성하시오.
// 부분 문자열은 S에서 연속된 일부분을 말하며, 길이가 1보다 크거나 같아야 한다.
// 예를 들어, ababc의 부분 문자열은 a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc가 있고, 서로 다른것의 개수는 12개이다.

// 입력:
// 첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000 이하이다.

// 출력:
// 첫째 줄에 S의 서로 다른 부분 문자열의 개수를 출력한다.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬된 Sub[i]에 대하여, Sub[i]의 원소들 중 서로 다른 원소의 개수를 세어 포인터를 통해 count로 나타내주는 함수.
void CheckSub (vector<vector<string>>* Sub, int i, int order, int* count);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    string S;
    cin >> S;
    
// 문자열의 부분문자열 생성
    int len = S.length();
    vector<vector<string>> Sub(len);   // Sub[i][j] 에서, i는 '부분문자열의 길이' - 1, j는 같은 길이를 갖는 부분문자열의 index이다.
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len-i; j++) {
            Sub[i].push_back(S.substr(j,i+1));
        }
    }

// 각 길이마다 정렬
    for (int i = 0; i < len; i++) { sort(Sub[i].begin(), Sub[i].end()); }

// 계산
    int count = 0;
    for (int i = 0; i < len; i++) {
        CheckSub(&Sub, i, 0, &count);
    }

// 출력
    cout << count;

    return 0;
}

// 사전순으로 정렬된 Sub[i]에서 Sub[i][order]의 값을 처음으로 초과하는 upper_bound를 다음 order로 지정하고 재귀. (동시에 count++)
// order이 Sub[i]의 마지막 원소 다음을 가리키게 될 때, 재귀 종료.
void CheckSub (vector<vector<string>>* Sub, int i, int order, int* count) {
    if ( order == (*Sub)[i].size() ) { return; }
    string temp;
    temp = (*Sub)[i][order];
    order = upper_bound((*Sub)[i].begin(), (*Sub)[i].end(), temp) - (*Sub)[i].begin();
    (*count)++;
    CheckSub(Sub, i, order, count);
}