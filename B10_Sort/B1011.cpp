// 백준 10814번 문제 (정렬 - 11 : 나이순 정렬)

// 문제:
// 온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다.
// 이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
// 둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다.
// 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다.
// 입력은 가입한 순서로 주어진다.

// 출력:
// 첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct User {
    int age;
    string name;   // char[] name; 과 비슷할듯.
};

bool compare (User a, User b) {  // a, b를 받아와서, 그 안에 든 "나이"를 비교해서 판단하여 sort하라는 것.
    return a.age < b.age;
}

int main() {

    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<User> u(N); // 유저 명 수 만큼의 크기를 가진 배열 (User를 담을 그릇)
    for (int i = 0; i < N; i++) {
        cin >> u[i].age >> u[i].name;
    }

    stable_sort(u.begin(), u.end(), compare);
    
    for (int i = 0; i < N; i++) {
        cout << u[i].age << " " << u[i].name << "\n";
    }

    return 0;
}