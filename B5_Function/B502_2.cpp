// 백준 4673번 문제 (함수 - 2: 셀프 넘버)
// 함수를 사용하고 풂.

// 알고리즘:
// 함수를 사용하지 않은 것과 사실상 동일.


#include <iostream>

int d(int i)
{
    return i + i/10000 + (i/1000)%10 + (i/100)%10 + (i/10)%10 + i%10; 
}

int main() {

    using namespace std;

    int a[10000] = {0};

    for (int i = 0; i < 10000; i++)
    {
        if(a[i] == 0) {                         // i + 1은 self number
            for (int j = i+1; j <= 10000; j = d(j)) {    // j = i + 1 = 1로 시작, j가 10000이 될때까지
                a[j-1] = j;                     // 배열에 j로부터 시작하는 숫자들 다 집어넣기
            }
            cout << i + 1 << endl;
        }
        else {}
    }




    return 0;
}