// 쉽다. 대표적인 dp문제일듯.
// 백준 1463번 문제 (동적 계획법 1 - 9 : 1로 만들기)
// https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>
using namespace std;

int main() {

// 입력
    int X;
    cin >> X;

// 계산
    vector<int> n(1000001); // [0]은 쓰지 않는다. [i]의 값은 i가 1이 되기 위해서 몇 번의 시도를 해야하는가이다.
    for (int i = 2; i <= 1000000; i++) {
        if (i%2>0 && i%3>0) { //  i가 2로도, 3으로도 나누어 떨어지지 않으면 어쩔 수 없이 1을 빼야한다.
            n[i] = n[i-1] + 1;
        }
        else if (i%2==0 && i%3>0) { // i가 2로만 나누어 떨어질 때.
            n[i] = std::min(n[i/2], n[i-1]) + 1;
        }
        else if (i%2>0 && i%3==0) { // i가 3으로만 나누어 떨어질 때.
            n[i] = std::min(n[i/3], n[i-1]) + 1;
        }
        else { // i가 2와 3 둘다로 나누어 떨어질 때.
            n[i] = std::min(std::min(n[i/2], n[i/3]), n[i-1]) + 1;
        }
    }
    
// 출력
    cout << n[X];


	return 0;
}