// 백준 2941번 문제 (문자열 - 9 : 크로아티아 알파벳)

// 문제:
// 예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.
// 예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, š, nj, a, k)로 이루어져 있다. 
// 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
// dž는 무조건 하나의 알파벳으로 쓰이고, d와 ž가 분리된 것으로 보지 않는다. lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.

// 입력:
// 첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.
// 단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.

// 출력:
// 입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.

#include <iostream>
#include <string>

int main() {

    using namespace std;

    string str;
    cin >> str;

    unsigned long int check = 0;

    for (unsigned long int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'c' && str[i+1] == '=')    // i, i+1 번째가 c= 일때   -> check++
            check++;
        else if(str[i] == 'c' && str[i+1] == '-')  // i, i+1 번째가 c- 일때   -> check++
            check++;
        else if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=')  // i, i+1, i+2 번째가 dz= 일때  -> check++
            check++;
        else if(str[i] == 'd' && str[i+1] == '-')
            check++;
        else if(str[i] == 'l' && str[i+1] == 'j')
            check++;
        else if(str[i] == 'n' && str[i+1] == 'j')
            check++;
        else if(str[i] == 's' && str[i+1] == '=')
            check++;
        else if(str[i] == 'z' && str[i+1] == '=')
            check++;

        else{}  // 아무것도 아닐 때   -> 아무것도 하지 않고 넘긴다.
    }

    cout << str.length() - check;


    return 0;
}