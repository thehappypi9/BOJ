// 백준 2587번 문제 (정렬 - 2 : 대푯값2)

// 문제:
// 어떤 수들이 있을 때, 그 수들을 대표하는 값으로 가장 흔하게 쓰이는 것은 평균이다. 평균은 주어진 모든 수의 합을 수의 개수로 나눈 것이다.
// 예를 들어 10, 40, 30, 60, 30의 평균은 (10 + 40 + 30 + 60 + 30) / 5 = 170 / 5 = 34가 된다.
// 평균 이외의 또 다른 대표값으로 중앙값이라는 것이 있다. 중앙값은 주어진 수를 크기 순서대로 늘어 놓았을 때 가장 중앙에 놓인 값이다.
// 예를 들어 10, 40, 30, 60, 30의 경우, 크기 순서대로 늘어 놓으면 10 30 30 40 60 이 되고 따라서 중앙값은 30이 된다.
// 다섯 개의 자연수가 주어질 때 이들의 평균과 중앙값을 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄부터 다섯 번째 줄까지 한 줄에 하나씩 자연수가 주어진다. 주어지는 자연수는 100 보다 작은 10의 배수이다.

// 출력:
// 첫째 줄에는 평균을 출력하고, 둘째 줄에는 중앙값을 출력한다. 평균과 중앙값은 모두 자연수이다.


#include <iostream>
#include <vector>

int main() {

    using namespace std;

// 입력
    int num[5] = {0};
    for (int i = 0; i < 5; i++) {
        cin >> num[i];
    }


// 평균
    int average = 0;            // 입력 조건에 의해 평균값은 항상 정수로 나올 수 있다.
    for (int i = 0; i < 5; i++) {
        average += num[i];
    }
    average /= 5;
    cout << average << endl;    // 평균 출력.


// 중앙값
    // B1001에서 가져온 최솟값 찾는 알고리즘
    int min = num[0];
    int check = 0;
    for (int r = 0; r < 3; r++) {  // 앞의 2번째까지는 최솟값을 찾아서 1001로 바꿔준다. // 마지막 3번째 루프에서 찾은 최솟값을 출력(중앙값)
        min = 1001;
        for (int setmin = 0; setmin < 5; setmin++) {
            if (num[setmin] != 1001) {
                min = num[setmin];
            }
        }
        for (int i = 0; i < 5; i++) {  // 최솟값 찾기
            if (num[i] <= min) {
                min = num[i];
                check = i;
            }
        }
        if (r == 2) {    // 마지막 루프에서 찾은 min이 중앙값이다.
            cout << min;    // 중앙값 출력
            break;
        }
        num[check] = 1001;  // 1, 2번째 루프에서 찾은 min에는 입력할 수 없는 값을 대입.
    }

    return 0;
}