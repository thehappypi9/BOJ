// 백준 15652번 문제 (백트래킹 - 4 : N과 M (4))

// 문제:
// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
    // 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
    // 같은 수를 여러 번 골라도 된다.
    // 고른 수열은 비내림차순이어야 한다.
        // 길이가 K인 수열 A가 A_1 ≤ A_2 ≤ ... ≤ A_K-1 ≤ A_K를 만족하면, 비내림차순이라고 한다.

// 입력:
// 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

// 출력:
// 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
// 수열은 사전 순으로 증가하는 순서로 출력해야 한다.


#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    int N, M;
    cin >> N >> M;

// 계산 및 출력
    vector<int> number(M, 1);  // 자릿수같은 개념
    int go = 1;
    int change;
    while (go) {
        change = 0;
    // 출력
        for (int i = 0; i < M; i++) {
            cout << number[i] << " ";
        }
        cout << "\n";


    // 출력 후, 마지막부터 숫자 올려주기. 받아올림 개념 생각.
        for (int i = M-1; i >= 0; i--) {
            if (number[i] >= N) { // 받아올림.
                if (i == 0) {
                    go = 0;
                    break;
                }
                if (number[i-1] == N) { change++; }  // 앞 자리 숫자가 N이면 N보다 큰 숫자를 넣을 수 없으니, 따로 체크해놓는다.
                else { number[i] = number[i-1]+1; }  // 앞 자리 숫자 + 1 을 넣어준다.
            }
            else {  // 받아올림 필요X. 가장 마지막 숫자 + 1
                number[i]++;
                if (change) {     // change = 1이면, 뒷 자리 숫자들을 모두 똑같이 맞춰준다. (그게 가능한 가장 작은 수)
                    for (int j = i+1; j < M; j++) { number[j] = number[i]; }
                }
                break;
            }
        }
    }    

    return 0;
}