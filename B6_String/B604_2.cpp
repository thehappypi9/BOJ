// 백준 2627번 문제 (문자열 - 4 : 문자열 반복)
// 동적메모리할당(vector)을 이용

#include <iostream>
#include <string>
#include <vector>

int main() {

    using namespace std;

    int T = 0;
    cin >> T;
    //int R[T] = {0};
    vector<int> R;
    //string S[T];
    vector<string> S;
    R.reserve(T);
    S.reserve(T);
    int r;
    string s;



    for (int i = 0; i < T; i++)
    {
        cin >> r >> s;
        R.push_back(r);
        S.push_back(s);
    }



    for (int i = 0; i < T; i++)
    {
        for(int j = 0; j < int(S.size()); j++)
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