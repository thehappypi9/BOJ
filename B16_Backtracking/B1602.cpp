// B1601_3.cpp 와는 34번째 줄만 다르다.  // if (!((*visited)[i]) && ((*arr)[depth-1] < i || depth == 1)) {

// 백준 15650번 문제 (백트래킹 - 2 : N과 M (2))

// 문제:
// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
    // 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
    // 고른 수열은 오름차순이어야 한다.

// 입력:
// 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

// 출력:
// 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
// 수열은 사전 순으로 증가하는 순서로 출력해야 한다.


#include <iostream>
#include <vector>
using namespace std;

void dfs (int depth, int N, int M, vector<int>* arr, vector<bool>* visited) {
    // depth가 가득차면, 한 줄 출력.
    if (depth > M) {
        for (int i = 1; i <= M; i++) {
            cout << (*arr)[i] << " ";
        }
        cout << "\n";
    }
    
    // 아직 depth가 덜 찼을 때, 더 깊이 들어간다.
    else {
        for (int i = 1; i <= N; i++) { // 작은 숫자부터 돌려보다가,
            if (!((*visited)[i]) && ((*arr)[depth-1] < i || depth == 1)) { // visited 되지 않은 곳을 찾아서, (근데 직전에 넣은 값보다 커야한다. depth = 1이면 직전에 넣은 값이 없으니 패스)
                (*visited)[i] = true;  // visited 되었다고 표시하고,
                (*arr)[depth] = i;     // arr[depth]에다가 이 숫자를 넣어놓는다.
                dfs(depth + 1, N, M, arr, visited);  // 그리고 다시 더 깊이 들어가보자.
                // dfs 끝까지 하고 나왔다는 뜻이니, visited를 다시 false로.
                (*visited)[i] = false;
            }
        }
    }
}

void dodfs (int N, int M) {
    vector<int> arr(M+1);
    vector<bool> visited(N+1);
    dfs (1, N, M, &arr, &visited);
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    dodfs(N, M);
    

    return 0;
}