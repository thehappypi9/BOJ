// "맞았습니다!!"
// 구조체 사용하여 각 이름별로 받은 순서에 index를 부여하고, index는 지키면서 이름 사전순 정렬 -> 이분탐색으로 시간을 절약하였다.

// 백준 1620번 문제 (집합과 맵 - 3 : 나는야 포켓몬 마스터 이다솜)

// 문제:
// (백준 사이트 참고: https://www.acmicpc.net/problem/1620)

// 입력:
// 첫째 줄에는 도감에 수록되어 있는 포켓몬의 개수 N이랑 내가 맞춰야 하는 문제의 개수 M이 주어져.
// N과 M은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수인데, 자연수가 뭔지는 알지? 모르면 물어봐도 괜찮아. 나는 언제든지 질문에 답해줄 준비가 되어있어.
// 둘째 줄부터 N개의 줄에 포켓몬의 번호가 1번인 포켓몬부터 N번에 해당하는 포켓몬까지 한 줄에 하나씩 입력으로 들어와.
// 포켓몬의 이름은 모두 영어로만 이루어져있고, 또, 음... 첫 글자만 대문자이고, 나머지 문자는 소문자로만 이루어져 있어.
// 아참! 일부 포켓몬은 마지막 문자만 대문자일 수도 있어. 포켓몬 이름의 최대 길이는 20, 최소 길이는 2야.
// 그 다음 줄부터 총 M개의 줄에 내가 맞춰야하는 문제가 입력으로 들어와.
// 문제가 알파벳으로만 들어오면 포켓몬 번호를 말해야 하고, 숫자로만 들어오면, 포켓몬 번호에 해당하는 문자를 출력해야해.
// 입력으로 들어오는 숫자는 반드시 1보다 크거나 같고, N보다 작거나 같고, 입력으로 들어오는 문자는 반드시 도감에 있는 포켓몬의 이름만 주어져. 그럼 화이팅!!!

// 출력:
// 첫째 줄부터 차례대로 M개의 줄에 각각의 문제에 대한 답을 말해줬으면 좋겠어!!!.
// 입력으로 숫자가 들어왔다면 그 숫자에 해당하는 포켓몬의 이름을, 문자가 들어왔으면 그 포켓몬의 이름에 해당하는 번호를 출력하면 돼. 그럼 땡큐~


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Pokemon {
    string name;
    int number;
};

bool compare (Pokemon a, Pokemon b) {
    return a.name < b.name;
}

int Tester(vector<Pokemon>* whatItHas, string testThis);
int Test(vector<Pokemon>* whatItHas, string testThis, int left, int right);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
// 입력
    int N, M;
    cin >> N >> M;
    vector<Pokemon> P(N);
    vector<string> PokemonNames(N);
    vector<string> TestMe(M);
    for(int i = 0; i < N; i++) { cin >> PokemonNames[i]; P[i].name = PokemonNames[i]; P[i].number = i; }
    for(int j = 0; j < M; j++) { cin >> TestMe[j]; }

// 정렬
    sort(P.begin(), P.end(), compare);   // P를 포켓몬 이름 사전순으로 정렬.


// 계산 및 출력
    int number;
    int length;
    for (int j = 0; j < M; j++) {
    // Test 해야하는 것(string)의 첫번째 문자가 숫자면,
        if ( int(TestMe[j][0]) >= 48 && int(TestMe[j][0]) <= 57 ) {
            number = 0;
            length = int(TestMe[j].length());
            for ( int L = 1; L <= length; L++ ) {                  // string을 int로 바꾸기 위한 것.
                number += (int(TestMe[j][length-L]) - 48)*pow(10,L-1);  // L=1면 일의 자리, L=2면 십의 자리, ... , L=6이면 십만자리 수다.
            }
            cout << PokemonNames[number-1] << "\n";
        }
    // Test 해야하는 것이 숫자가 아니면(문자이면),
        else {
            cout << Tester(&P, TestMe[j])+1 << "\n";
        }
    }

    return 0;
}

int Tester(vector<Pokemon>* whatItHas, string testThis) {
    int size = int((*whatItHas).size());
    int left = 0; int right = size-1;
    return Test(whatItHas, testThis, left, right);
}

int Test(vector<Pokemon>* whatItHas, string testThis, int left, int right) {
    int mid = (left+right)/2;
    if (left == right) {
        if ((*whatItHas)[mid].name == testThis) { return (*whatItHas)[mid].number; }
        else { return -1; }  // This won't be happened in this problem.
    }
    else {
        if ((*whatItHas)[mid].name == testThis) { return (*whatItHas)[mid].number; }
        else if ((*whatItHas)[mid].name < testThis) { return Test(whatItHas, testThis, mid+1, right); }
        else { return Test(whatItHas, testThis, left, mid); }
    }
    return 0;
}