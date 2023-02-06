// 3시간여만에 풀어서 좋아했는데 알고보니 실버1 ㅠㅠ

// 백준 14888번 문제 (백트래킹 - 7 : 연산자 끼워넣기)
// https://www.acmicpc.net/problem/14888


#include <iostream>
#include <vector>
using namespace std;

enum eOperators { Plus, Minus, Times, Divide }; // Plus = 0, Minus = 1, Times = 2, Divide = 3

void dfs(int n, vector<int>* numbers, vector<int>* operators, int* max, int* min) {

// 끝까지 다 계산했으면 max, min 계산해주고, return.
    int N = (*numbers).size();
    if (n == N-1) {
        if ((*numbers)[n] > *max) {
            *max = (*numbers)[n];
        }
        if ((*numbers)[n] < *min) {
            *min = (*numbers)[n];
        }
        return;
    }
   
// 계산할게 남았으면,
    int save = (*numbers)[n+1]; // 값 save.
    if ( (*operators)[Plus] > 0 ) {  // 덧셈기호가 남아있으면
        (*operators)[Plus]--; // 덧셈기호 하나 써서,
        (*numbers)[n+1] = (*numbers)[n] + (*numbers)[n+1]; // 덧셈 계산해준 걸로 바꿔주고
        dfs(n+1, numbers, operators, max, min); // 다음 연산으로.
        (*numbers)[n+1] = save; // dfs 다 돌리고 나서 전 단계로 돌아가기 전에 save 해놓은걸로 되돌려주기
        (*operators)[Plus]++; // 덧셈기호도 다시 원상복구
    }
    if ( (*operators)[Minus] > 0 ) {  // 뺄셈기호가 남아있으면
        (*operators)[Minus]--;
        (*numbers)[n+1] = (*numbers)[n] - (*numbers)[n+1];
        dfs(n+1, numbers, operators, max, min);
        (*numbers)[n+1] = save;
        (*operators)[Minus]++;
    }
    if ( (*operators)[Times] > 0 ) {  // 곱셈기호가 남아있으면
        (*operators)[Times]--;
        (*numbers)[n+1] = (*numbers)[n] * (*numbers)[n+1];
        dfs(n+1, numbers, operators, max, min);
        (*numbers)[n+1] = save;
        (*operators)[Times]++;
    }
    if ( (*operators)[Divide] > 0 ) {  // 나눗셈기호가 남아있으면
        (*operators)[Divide]--;
        (*numbers)[n+1] = (*numbers)[n] / (*numbers)[n+1];
        dfs(n+1, numbers, operators, max, min);
        (*numbers)[n+1] = save;
        (*operators)[Divide]++;
    }

}

int main() {

// 입력
    int N; cin >> N;
    vector<int> numbers(N); for(int i = 0; i < N; i++){cin >> numbers[i];}    
    vector<int> operators(4); for (int j = 0; j < 4; j++){cin >> operators[j];} // operators[Plus], operators[Minus], ... 처럼 쓸 수 있다!

// 계산
    int max = -1000000001; // 최솟값-1 로 설정. 모든 계산값들은 이것보다 클 것이다.
    int min = 1000000001; // 최댓값+1 로 설정. 모든 계산값들은 이것보다 작을 것이다.
    dfs(0, &numbers, &operators, &max, &min);

// 출력
    cout << max << "\n";
    cout << min << "\n";

    return 0;
}