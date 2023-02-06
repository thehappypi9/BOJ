// "맞았습니다!!"
// 거의 3일정도 (역대 최장 시간) 고민해서 풀어내서, 문제 난이도도 높을거라 예상했더니 문제 난이도가 낮다.
// 허무하다. DFS 방식으로, (일반적으로 재귀를 써서) 다시 풀어보자!

// 백준 15649번 문제 (백트래킹 - 1 : N과 M (1))

// 문제:
// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
    // 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

// 입력:
// 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

// 출력:
// 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
// 수열은 사전 순으로 증가하는 순서로 출력해야 한다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Num {
    int number;  // 무엇을 출력하는지, 그 숫자 자체
    int order;   // 출력하는 순서
};

bool compare (Num a, Num b) {
    return a.order < b.order;
}

bool comparenumber (Num a, Num b) {
    return a.number < b.number;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    int N, M;
    cin >> N >> M;

// 메모리 확보 및 초기화
    vector<Num> A(N);
    for (int i = 0; i < N; i++) {
        A[i].number = i+1;
        if (i < M) { A[i].order = i+1; }
        else { A[i].order = 0; }
    }

// 첫 줄 출력
    for (int i = 0; i < M; i++) { cout << i+1 << " "; }
    cout << "\n";

// 정렬
    sort(A.begin(), A.end(), compare);  // order의 오름차순으로 sort

// 반복 횟수 계산
    int n = 1;
    for (int i = 0; i < M; i++) {
        n *= N-i;
    }

// 반복문
    int stop = 1;
    while(--n) {

        for (int t = 1; t <= M; t++) {

            // 임시변수 지정    
                int tmp_number = A[N-t].number;  // order이 가장 늦는, 즉 직전에 출력한 number 중 가장 마지막에 나온 number.
                int tmp_order = A[N-t].order;    // 그 order. 사실 이건 언제나 M일 수밖에 없을 듯???
                
            // 숫자 바꾸기
                int checkifhere = 0;
                int checkthis = 1;
                int a = 1;

                // 바꾸고자하는 tmp_number+a가 더 빠른 order에 의해 점거되어있을때, 그 number를 건너뛰려고 a++를 계속 해준다. (비어있거나 더 늦은 order이 점거하는 number만 취하도록)
                while (checkthis) {
                    checkthis = 0;
                    for (int i = 0; i < N; i++) {
                        if (A[i].number == tmp_number+a && (A[i].order < tmp_order && A[i].order != 0)) {
                            a++;
                            checkthis++;
                            break;
                        }
                    }
                }

                // 해소된 후,
                for (int i = 0; i < N; i++) {
                    if (A[i].number == tmp_number+a && (A[i].order == 0 || A[i].order > tmp_order)) {
                        A[N-t].order = 0;
                        A[i].order = tmp_order;
                        checkifhere++;
                        break;
                    }
                }


            // 숫자가 안 바뀌었을 때.
                if (checkifhere == 0) {
                    if (t == N) { stop = 0; } // t를 끝까지 돌렸는데도, 그 어떤 order도 이 문제의 규칙에 따라 움직일 수 없을 때, while문 종료.
                    else {} // 그게 아니면 다음 t에 대해 다시 while 
                }
            // 숫자가 잘 바뀌었을 때.
                else {
                    // 가장 끝 order이 바뀐 것이 아닐 때, 후순서 숫자들을 배치해주어야.
                    if (t != 1) {   
                        for (int i = 0; i < N; i++) { // 각 order들에 대해,
                            if (A[i].order >= M+2-t && A[i].order <= M) {  // 그 order가 후순서 숫자면,
                                A[i].order = 0; // 후순서 숫자들의 order들을 0으로 만들기
                            }
                        }

                        sort(A.begin(), A.end(), comparenumber);  // 숫자 순서대로 오름차순 정렬
                        for (int c = M+2-t; c <= M; c++) { // c는 후순서 숫자들의 order.
                            for (int i = 0; i < N; i++) {
                                if (A[i].order == 0) { // 빈 곳을 찾아서 들어가자.
                                    A[i].order = c;
                                    break;
                                }
                            }
                        }
                    }


                    break;  // for t 문 탈출
                }


        }


    // 한 줄 출력
        sort(A.begin(), A.end(), compare);  // order의 오름차순으로 sort
        for (int i = N-M; i <= N-1; i++) { cout << A[i].number << " "; } // 출력해야하는 부분만 딱 출력. 전체를 for 돌리지 않아도 계산해보니 이 범위가 맞다.
        cout << "\n";


    }

    return 0;
}