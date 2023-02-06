// 백준 1157번 문제 (문자열 - 5 : 단어 공부)

// 문제:
// 알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 
// 단, 대문자와 소문자를 구분하지 않는다.

// 입력:
// 첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

// 출력:
// 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

#include <iostream>
#include <string>

int main() {

    using namespace std;

    string str = {0};
    cin >> str;

    int AtoZ[26] = {0}; // 0번째 원소는 A(a)의 개수, 1번째 원소는 B(b)의 개수, ... , 25번째 원소는 Z(z)의 개수를 나타낸다.

    for (int i = 0; i < int(str.length()); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            AtoZ[str[i]-65]++;
        }
        else if (str[i] >= 97 && str[i] <= 122)
        {
            AtoZ[str[i]-97]++;
        }
        else{
            cout << "WTF??";
        }
    }

    int max = 0;
    int max2 = 0;
    int answer = 0;
    int answer2 = 0;


    for (int i = 0; i < 26; i++)
    {
        if (AtoZ[i] > max)
        {
            max = AtoZ[i];
            answer = i;    
        }
        if (AtoZ[i] >= max2)
        {
            max2 = AtoZ[i];
            answer2 = i;
        }
    }

    if (answer == answer2) {
        cout << char(answer + 65);
    }
    else {
        cout << "?";
    }



    return 0;
}