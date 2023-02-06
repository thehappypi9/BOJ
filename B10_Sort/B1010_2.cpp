// 2차원 벡터 안의 원소 : string
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
    vector<string> words (N);

    string str; // 임시로 쓸 str
    for (int i = 0; i < N; i++) {
        cin >> str;
        words[i] = str.length();
        words[i].append(str);   // words[i][0]에는 str의 길이가 들어가고, words[i][1] 부터 str이 복사되어 붙는다.
    }

    sort(words.begin(), words.end()); // 정렬

    for (int i = 0; i < N; i++) {   // 정렬된 N개의 원소를 갖는 words 배열의 각 원소에 대하여,
        if (i == 0 || words[i] != words[i-1]) { // 0번째 원소는 프리패스, 1번째부터는 직전 원소와 "다를때만" 패스
            for (int j = 1; j < int(words[i].length()); j++) {
                cout << char(words[i][j]); // 패스되었다면, 문자열 출력
            }
            cout << "\n";
        }
    }

    return 0;
}