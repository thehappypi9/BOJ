// 백준 10809번 문제 (문자열 - 3 : 알파벳 찾기)


#include <iostream>
#include <string>

int main() {

    using namespace std;


    string S;
    cin >> S;

    int found = 0;

    for (int i = 97; i <= 122; i++)
    {
        found = 0;

        for (int j = 0; j < int(S.length()); j++)
        {
            if (S[j] == i) {
                found = 1;
            }
            else {}
        }

        if (found == 1) {
            cout << S.find(i);
            cout << " ";
        }
        else {
            cout << "-1";
            cout << " ";
        }
    }



    return 0;
}