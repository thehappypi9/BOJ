// "NULL 문자도 벡터의 size에 포함된다. NULL 문자를 출력하는 것도 눈에는 안 보이지만 컴퓨터는 감지한다."
// 2차원 벡터 안의 원소 : vector<int>
// 도움: https://www.acmicpc.net/board/view/106485

// 백준 1181번 문제 (정렬 - 10 : 단어 정렬)

// 문제:
// 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
    // 1. 길이가 짧은 것부터
    // 2. 길이가 같으면 사전 순으로

// 입력:
// 첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000)
// 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

// 출력:
// 조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> words (N); // N개의 2차원 배열 생성. N개의 각 원소는 1차원 백터로 이루어진다.

    string str; // 임시로 쓸 str
    for (int i = 0; i < N; i++) {  // 단어 입력을 N번 받는다.
        cin >> str;
        words[i].push_back(int(str.length()));    // 1차원 벡터의 원소 중 0번째 원소는 받은 문자열의 길이 (sort 시 우선적으로 고려됨)
        for (int j = 0; j < int(str.length()); j++) {
            words[i].push_back(str[j]);      // 1차원 벡터의 1번째부터 순서대로 문자열이 복사된다. 아스키코드에 따른 int 숫자가 들어간다.
        }
    }

    sort(words.begin(), words.end()); // 정렬

    for (int i = 0; i < N; i++) {   // 정렬된 N개의 원소를 갖는 words 배열의 각 원소에 대하여,
        if (i == 0 || words[i] != words[i-1]) {   // 0번째 원소는 프리패스, 1번째부터는 직전 원소와 "다를때만" 패스
            for (int j = 1; j < int(words[i].size()); j++) {
                cout << char(words[i][j]);    // 패스되었다면, 문자열 출력
            }
            cout << "\n";
        }
    }

    return 0;
}