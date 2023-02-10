// 피보나치 수열과 같음을 이해하는 것이 중요한 문제.
// 백준 1904번 문제 (동적 계획법 1 - 3 : 01타일)
// https://www.acmicpc.net/problem/1904

#include <iostream>
#include <vector>
using namespace std;


int main() {

    vector<int> cases(1000001);
    cases[1] = 1;
    cases[2] = 2;
    for (int i = 3; i <= 1000000; i++) {
        cases[i] = (cases[i-1] + cases[i-2]) % 15746;
    }    
    
    int N;
    cin >> N;

    cout << cases[N];


    return 0;
}
