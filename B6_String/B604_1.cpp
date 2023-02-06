// 백준 2627번 문제 (문자열 - 4 : 문자열 반복)

#include <iostream>
#include <string>

int main() {

    using namespace std;

    int T = 0;
    cin >> T;
    int R[T] = {0};
    string S[T];


    for (int i = 0; i < T; i++)
    {
        cin >> R[i] >> S[i];
    }


    for (int i = 0; i < T; i++)
    {
        for(int j = 0; j < S[i].length(); j++)
        {
            for (int k = 0; k < R[i]; k++)
            {
                cout << S[i][j];
            }
        }
        cout << "\n";
    }


    return 0;
}