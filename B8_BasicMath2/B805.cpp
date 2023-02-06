// 백준 4948번 문제 (기본수학2 - 5 : 베르트랑 공준)

// 문제:
// 베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.
// 이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.
// 예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다.
// (11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)
// 자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오. 

// 입력:
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 케이스는 n을 포함하는 한 줄로 이루어져 있다.
// 입력의 마지막에는 0이 주어진다.

// 출력:
// 각 테스트 케이스에 대해서, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력한다.

// 제한:
// 1 ≤ n ≤ 123,456


#include <iostream>
#include <vector>

// B804_1에서 만든 함수 (int number를 받아서 그것이 소수인지 아닌지 판별하는 함수. true -> 소수O, false -> 소수X.
bool CheckingPrimeNumber(int);

int main() {

    using namespace std;

    int n = 0;
    int count = 0;
    vector<int> counts;

    while (true) {
        cin >> n;                 // 입력

        if (n == 0) {    // 0 이 입력되면 while문 탈출 -> 프로그램 종료.
            break;
        }

        count = 0;       // count 변수 초기화.
        for (int i = n+1; i <= 2*n; i++) {   // n+1부터 2n까지 소수인지 검사 후, 소수가 나올 때마다 count 1씩 추가.
            if (CheckingPrimeNumber(i)) {
                count++;
            }
        }
        counts.push_back(count);
    }

    for (int i = 0; i < int(counts.size()); i++) {
        cout << counts[i] << endl;
    }


    return 0;
}



bool CheckingPrimeNumber(int number) {  
    if (number == 1)
        return false;
    else if (number == 2)
        return true;
    else if (number % 2 == 0)
        return false;
    for (int i = 3; i*i <= number; i+=2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;  // return 되지않고 for 문을 모두 통과하면 소수이다.
}