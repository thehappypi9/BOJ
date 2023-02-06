// 백준 25305번 문제 (정렬 - 3 : 커트라인)

// 문제:
// 2022 연세대학교 미래캠퍼스 슬기로운 코딩생활에 N명의 학생들이 응시했다.
// 이들 중 점수가 가장 높은 k명은 상을 받을 것이다. 이 때, 상을 받는 커트라인이 몇 점인지 구하라.
// 커트라인이란 상을 받는 사람들 중 점수가 가장 가장 낮은 사람의 점수를 말한다.

// 입력:
// 첫째 줄에는 응시자의 수 N과 상을 받는 사람의 수 k가 공백을 사이에 두고 주어진다.
// 둘째 줄에는 각 학생의 점수 x가 공백을 사이에 두고 주어진다.

// 출력:
// 상을 받는 커트라인을 출력하라.

// 제한:
// 1 ≤ N ≤ 1,000
// 1 ≤ k ≤ N
// 0 ≤ x ≤ 10,000

#include <iostream>
#include <vector>

// 'N'개의 값 중 'rank'번째로 큰 값을 찾는 함수. 'x'는 N개의 값들의 배열.
// 이미 검사한 것을 -1로 설정하였다. (-1은 변경가능하며, 입력할 수 없는 값이어야 하고, 입력할 수 있는 모든 수보다 작아야한다.)
int Ranking(int* x, int N, int rank) {
    using namespace std;
    
    vector<int> copy(N);           // x의 원소들을 손상시키지 않기 위해 copy 벡터를 새로 만들고 원소 값들 복사.
    for (int i = 0; i < N; i++) {
        copy[i] = *(x+i);
    }

    int max = copy[0];
    int check = 0;
    for (int r = 0; r < rank; r++) {  // 앞의 (rank-1)번째까지는 최댓값을 찾아서 -1로 바꿔준다.
        max = -1;    // x의 원소로 입력할 수 없는 값. (가능한 모든 입력값보다 작아야 한다.)
        for (int setmax = 0; setmax < N; setmax++) {
            if (copy[setmax] != -1) {
                max = copy[setmax];
            }
        }
        for (int i = 0; i < int(copy.size()); i++) {  // 최댓값 찾기
            if (copy[i] >= max) {
                max = copy[i];
                check = i;
            }
        }
        if (r == rank-1) {    // 마지막 루프에서 찾은 max가 찾고자 하는 'rank'번째 값이다.
            return max;      // 반환
        }
        copy[check] = -1;  // 앞 루프에서 찾은 max에는 입력할 수 없는 값을 대입.
    }

    return false;  // 원래 이게 나오면 안 됨.
}


int main() {

    using namespace std;

    int N = 0; int k = 0;
    cin >> N >> k;

    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    cout << Ranking(&x[0], N, k);

    return 0;
}