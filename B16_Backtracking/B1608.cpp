// 1시간 50분 가량 소요

// 백준 14889번 문제 (백트래킹 - 8 : 스타트와 링크)
// https://www.acmicpc.net/problem/14889


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// teamStart벡터와 teamLink벡터에는 각 팀의 팀원의 번호들이 들어있다. 정렬 필요없음.
// teamStart의 능력치와 teamLink의 능력치의 차를 return하는 함수.
int calculate_ability_gap (vector<vector<int>>* S, vector<int>* teamStart, vector<int>* teamLink) {
    int N = (*S).size();
    int ability_of_Start = 0;
    int ability_of_Link = 0;
    int i, j;
    for (int a = 0; a < N/2; a++) {
        for (int b = a+1; b < N/2; b++) {
            i = (*teamStart)[a]-1;
            j = (*teamStart)[b]-1;
            ability_of_Start += (*S)[i][j] + (*S)[j][i];
            i = (*teamLink)[a]-1;
            j = (*teamLink)[b]-1;
            ability_of_Link += (*S)[i][j] + (*S)[j][i];
        }
    }

    if (ability_of_Start > ability_of_Link) { return ability_of_Start - ability_of_Link; }
    else { return ability_of_Link - ability_of_Start; }
}


// dfs 알고리즘으로 가능한 모든 팀 조합의 능력치 차를 검사한다. (calculate_ability_gap 함수 이용)
void maketeams_dfs (vector<vector<int>>* S, vector<int>* teamStart, int teamsize, int* min) {
    int N = (*S).size();

// 다 채워졌으면.
    if (teamsize == N/2) {
    // teamLink의 멤버도 구해주고,
        vector<int> teamLink;
        bool already;
        for (int i = 1; i <= N; i++) { // 1번선수 ~ N번선수에 대해,
            already = 0;
            for (int j = 0; j < N/2; j++) { 
                if ((*teamStart)[j] == i) { already = 1; } // teamStart에 속해있는지 확인하고,
            }
            if (already == 0) { teamLink.push_back(i); }  // 속해있지 않으면 teamLink에 추가.
        }
    // ability gap을 구해준 뒤, 역대 min보다 더 작다면 min에 넣어준다.
        int gap = calculate_ability_gap(S, teamStart, &teamLink);
        if ( *min > gap ) {
            *min = gap;
        }
    // 할 일 다 했으니 return
        return;
    }

// 멤버가 아직 다 안 채워졌을 때.
    for (int i = (*teamStart)[teamsize-1]+1; i <= N/2+teamsize+1; i++) {
        (*teamStart)[teamsize] = i; // 다음 멤버를 i로 채우고,
        maketeams_dfs(S, teamStart, teamsize+1, min); // dfs
        (*teamStart)[teamsize] = 0; // dfs 끝나면 다시 원상복구.
    }
}

int dodfs (vector<vector<int>>* S) {
    int N = (*S).size();
    int min = INT_MAX;

// teamStart 멤버들 담을 벡터 만들기.
    vector<int> teamStart(N/2);

// (ex. N == 6) 1 2 3 / 4 5 6 이나 4 5 6 / 1 2 3 이나 같은 것이기도 하고, 어차피 maketeam_dfs 알고리즘 상, i == 5, i == 6 일때는 의미가 없다.
    for (int i = 1; i <= N/2; i++) {
        teamStart[0] = i;
        maketeams_dfs(S, &teamStart, 1, &min);
    }

// 반환
    return min;
}




int main() {

// 입력
    int N; cin >> N;
    vector<vector<int>> S(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

// 계산, 출력
    cout << dodfs(&S);


    return 0;
}