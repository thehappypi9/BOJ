// 백준 11720번 문제 (문자열 - 2 : 숫자의 합)

#include <iostream>
#include <string>

int main() {

    using namespace std;

    int n = 0;
    cin >> n;

    string str;
    cin >> str;

    int sum = 0;    

    for (int i = 0; i < n; i++)
    {
        sum += (str[i] - 48);
    }

    cout << sum;


    return 0;
}