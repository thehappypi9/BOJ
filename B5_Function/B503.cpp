// 백준 1065번 문제 (함수 - 3: 한수)


#include <iostream>

int IfHansu(int num) {
    int a = (num/1000)%10;
    int b = (num/100)%10;
    int c = (num/10)%10;
    int d = num%10;
    //std::cout << "\n\na = " << a << ", b = " << b << ", c = " << c << ", d = " << d << "\n";
    //std::cout << "a-b = " << a-b << ", b-c = " << b-c << ", c-d = " << c-d << "\n\n";
    if (0 == a) {
        if (0 == b) { return 1; } // 한자릿수 or 두자릿수

        else {    // 세자릿수
            if (b-c == c-d) { return 1;}
            else { return 0; }
        }
    }
    else {   // 네자릿수
        if (a-b == b-c && b-c == c-d) { return 1; }
        else { return 0; }
    }

}


int main() {

    using namespace std;

    int n = 0;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (IfHansu(i) == 1) {
            ans++;
        }
    }

    cout << ans << endl;

    //cout << n << " is " << IfHansu(n) << ", 1이면 한수" << endl;




    return 0;
}