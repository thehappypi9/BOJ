// "시간초과", 내가 만든 함수 사용 -> 느림

// 백준 2108번 문제 (정렬 - 6 : 통계학)

// 문제:
// 수를 처리하는 것은 통계학에서 상당히 중요한 일이다.
// 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.
    // 산술평균 : N개의 수들의 합을 N으로 나눈 값
    // 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
    // 최빈값 : N개의 수들 중 가장 많이 나타나는 값
    // 범위 : N개의 수들 중 최댓값과 최솟값의 차이
// N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다.
// 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

// 출력:
// 첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
// 둘째 줄에는 중앙값을 출력한다.
// 셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
// 넷째 줄에는 범위를 출력한다.


#include <iostream>
#include <vector>

int main() {

    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N;
    cin >> N;
    vector<int> num(N);
    vector<int> counting(8001);  // counting[0] : -4000의 개수, counting[4000] : 0의 개수, counting[8000] : 4000의 개수
    double mean = 0; // 산술평균 선언 및 정의
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        mean += num[i];             // 산술평균 과정 1
        counting[num[i]+4000]++;
    }

// 산술평균
    mean /= N;                      // 산술평균 과정 2

    if (mean-int(mean) != 0) {   // 반올림 해야할때
        if (mean >= 0) {    // 양수일 때
            if (mean-int(mean) < 0.5) { mean = int(mean); } // 내림
            else { mean = int(mean) + 1;} // 올림
        }
        else {     // 음수일 때
            if (mean-(int(mean)-1) < 0.5) { mean = int(mean)-1; } // 내림
            else { mean = int(mean); } // 올림
        }
    }

    cout << mean << endl; // 반올림한 산술평균 출력.



// 중앙값
    int median = Ranking(&num[0], N, N/2+1);  // N/2+1 번째로 큰 수 == 중앙값
    cout << median << endl; // 중앙값 출력.



// 최빈값
    int mode;
    int RankC = Ranking(&counting[0], 8001, 1);  // RankC = counting 배열에서 가장 큰 값 (최빈값의 value의 "개수")
    vector<int> check;
    for (int i = 0; i < 8001; i++) {
        if (counting[i] == RankC) { // 이 if문을 통과한다는 것은, i가 최빈값을 나타낸단 것. counting[i]가 그 개수인데, 그 개수가 모든 개수 중 가장 크다.
            check.push_back(i-4000);
        }
    }
    if (check.size() == 1) {
        mode = check[0];
    }
    else {
        mode = check[1];
    }
    
    cout << mode << endl; // 최빈값 출력


// 범위
    int range = Ranking(&num[0], N, 1) - Ranking(&num[0], N, N); // 최댓값 - 최솟값 == 범위
    cout << range << endl; // 범위 출력.

    return 0;
}



// B1003에서 가져온 함수. 줄만 간단히 하였다. (-1을 -4001로 바꾸었다. : 입력할 수 있는 모든 수보다 작다.)
// 'N'개의 값 중 'rank'번째로 큰 값을 찾는 함수. 'x'는 N개의 값들의 배열.
int Ranking(int* x, int N, int rank) {
    using namespace std;
    vector<int> copy(N);
    for (int i = 0; i < N; i++) { copy[i] = *(x+i); }
    int max = copy[0];
    int check = 0;
    for (int r = 0; r < rank; r++) {
        max = -4001;
        for (int setmax = 0; setmax < N; setmax++) {
            if (copy[setmax] != -4001) {
                max = copy[setmax];
            }
        }
        for (int i = 0; i < int(copy.size()); i++) {
            if (copy[i] >= max) {
                max = copy[i];
                check = i;
            }
        }
        if (r == rank-1) { return max; }
        copy[check] = -4001;
    }
    return false;
}