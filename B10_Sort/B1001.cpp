// 백준 2750번 문제 (정렬 - 1 : 수 정렬하기)

// 문제:
// N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다.
// 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

// 출력:
// 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.


#include <iostream>
#include <vector>

int main() {

    using namespace std;

    int N;
    cin >> N;             // 입력의 개수 입력

    vector<int> num(N);   // 입력을 받을 공간
    for (int i = 0; i < N; i++) {
        cin >> num[i];    // 입력
    }


    int min = num[0];
    int check = 0;

    for (int r = 0; r < N; r++) {    // 그냥 N번 반복할 것이라는 의미의 루프 (최솟값이 N개 생길테니)
        min = 1001;
        for (int setmin = 0; setmin < N; setmin++) {
            if (num[setmin] != 1001) {         // 남은 것들 중 유효한 것만 통과시켜주는 if 문
                min = num[setmin];             // 유효한 것들 중 가장 마지막 원소를 min으로 설정한다.
            }
        }
        if (min == 1001) {        // 바로 위 for문에서 if문을 통과한 것이 아무것도 없어서 min이 그대로 1001이라면
            break;                // 가장 상위의 for문 종료. -> 프로그램 끝.
        }

        for (int i = 0; i < N; i++) {  // 최솟값 찾기 (이미 출력한 값은 원소가 1001로 바뀌어서 어차피 검사해도 최솟값이 될 수 없다.)
            if (num[i] <= min) {   // 위 for문에서 통과된 min = num[setmin] 에서 시작해서 하나씩 검사해가며 더 작거나 같은 값으로 min을 대체.
                min = num[i];
                check = i;
            }
        }
        cout << min << endl;       // 나온 최솟값 출력
        num[check] = 1001;         // 출력시킨 원소자리에 1001 대입.
    }

    return 0;
}