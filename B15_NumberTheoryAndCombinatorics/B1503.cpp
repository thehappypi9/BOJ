// 백준 2609번 문제 (정수론 및 조합론 - 3 : 최대공약수와 최소공배수)

// 문제:
// 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

// 출력:
// 첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.


#include <iostream>
using namespace std;

int main() {
    
// 입력
    int a, b;
    cin >> a >> b;

// 최대공약수 계산
    int GCD;
    for (int i = ( (a < b) ? a : b ); i >= 1; i--) {
        if (a%i == 0 && b%i == 0) {
            GCD = i;
            break;
        }
    }

// 최소공배수 계산
    int LCM;
    int tmp1 = a, tmp2 = b;
    while (true) {
        if (tmp1 == tmp2) {
            LCM = tmp1;
            break;
        }
        else {
            if (tmp1 < tmp2) {
                tmp1 += a;
            }
            else {
                tmp2 += b;
            }
        }
    }

// 출력
    cout << GCD << endl;
    cout << LCM << endl;

    return 0;
}