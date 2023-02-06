// 백준 1427번 문제 (정렬 - 7 : 소트인사이드)

// 문제:
// 배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

// 입력:
// 첫째 줄에 정렬하려고 하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

// 출력:
// 첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {

    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int length = str.length();

    vector<int> num(length);
    for (int i = 0; i < length; i++) {
        num[i] = str[i] - 48;
    }

    sort(num.begin(), num.end());  // 내장함수 이용하여 num 오름차순 정렬

    for (int i = length-1; i >= 0; i--) {  // 내림차순이기 때문에 오름차순으로 정렬한 num을 거꾸로 출력
        cout << num[i];
    }

    return 0;
}