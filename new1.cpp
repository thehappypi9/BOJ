// 백준 24416번 문제 (동적 계획법 1 - 1 : 알고리즘 수업 - 피보나치 수 1)
// https://www.acmicpc.net/problem/24416

#include <iostream>
#include <vector>
using namespace std;


int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    else if (a < b && b < c) {
        return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else {
        return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
}



int main() {

    int a, b, c;
    while(true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) { break; }
        else { cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n"; }
    }

    return 0;
}