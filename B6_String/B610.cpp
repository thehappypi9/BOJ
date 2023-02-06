// 백준 1316번 문제 (문자열 - 10 : 그룹 단어 체커)

// 문제:
// 그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다.
// 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만,
// aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
// 단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 단어의 개수 N이 들어온다. N은 100보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 단어가 들어온다.
// 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.

// 출력:
// 첫째 줄에 그룹 단어의 개수를 출력한다.

#include <iostream>
#include <string>
#include <vector>

int main() {

    using namespace std;

    int n = 0;
    cin >> n;                    // 입력받을 string 개수 정하기

    vector<string> v(n);
    
    int checker = 0;
    int NOTGW = 0;

    for (int i = 0; i < n; i++)  // n개만큼 string 받기
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        checker = 0;

        for (unsigned long int j = 1; j < v[i].length(); j++)
        {
            if(v[i][j] == v[i][j-1]) {}    // j번째 알파벳이 j-1번째 알파벳과 같으면 -> j++ (다음 알파벳 확인)
            else {                 // 다르면 -> 이후에 j-1번째 알파벳과 같은 알파벳을 가진 것이 있는지 전부 검사. 하나라도 나오면 checker > 0.
                for (unsigned long int k = j + 1; k < v[i].length(); k++)  
                {
                    if (v[i][k] == v[i][j-1]) {      // 검사했더니 하나라도 나오면
                        checker++;                   // checker가 1이 되고, 검사를 바로 중지(뒤의 검사는 할 필요가 없다)
                        break;
                    }
                }
            }
            if (checker > 0) {   // 검사가 끝나거나 중지된 다음에 checker가 1이 되었는지(0보다 큰지) 확인하고
                NOTGW++;         // checker가 0보다 크다면 NOTGW를 1만큼 올린다. (Group Word가 "아닌" 것 한 개 추가)              
                break;           // 이 단어에 대한 검사 중지 (이 단어에 대해서는 이제 더 볼 필요가 없다.)
            }
        }
    }

    cout << n - NOTGW;   // 출력

    return 0;
}