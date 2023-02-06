// "맞았습니다!!"
// 해당 ClothesType을 안 입는 경우를, 해당 ClothesType 중 "NULL 옷" 이라고 생각하면,
// 그냥 모든 ClothesType들의 옷 개수를 1개씩 늘린 후, "모든 ClothesType들의 옷 개수를 다 곱한 것 - 1" 이 답이다. (1은 모두 NULL 옷을 입는 경우 == 아무것도 안 입는 경우)
// 너무 쉽게 풀린다...
// https://www.acmicpc.net/board/view/25919

// 백준 9375번 문제 (정수론 및 조합론 - 10 : 패션왕 신해빈)

// 문제:
// 해빈이는 패션에 매우 민감해서 한번 입었던 옷들의 조합을 절대 다시 입지 않는다.
// 예를 들어 오늘 해빈이가 안경, 코트, 상의, 신발을 입었다면, 다음날은 바지를 추가로 입거나 안경대신 렌즈를 착용하거나 해야한다.
// 해빈이가 가진 의상들이 주어졌을때 과연 해빈이는 알몸이 아닌 상태로 며칠동안 밖에 돌아다닐 수 있을까?

// 입력:
// 첫째 줄에 테스트 케이스가 주어진다. 테스트 케이스는 최대 100이다.
// 각 테스트 케이스의 첫째 줄에는 해빈이가 가진 의상의 수 n(0 ≤ n ≤ 30)이 주어진다.
// 다음 n개에는 해빈이가 가진 의상의 이름과 의상의 종류가 공백으로 구분되어 주어진다. 같은 종류의 의상은 하나만 입을 수 있다.
// 모든 문자열은 1이상 20이하의 알파벳 소문자로 이루어져있으며 같은 이름을 가진 의상은 존재하지 않는다.

// 출력:
// 각 테스트 케이스에 대해 해빈이가 알몸이 아닌 상태로 의상을 입을 수 있는 경우를 출력하시오.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ClothesType {
    string name;
    int quantity;
};

int main() {

    int T; cin >> T;  // Test Case
    for (int t = 0; t < T; t++) {

// 입력
        int n; cin >> n; // 해빈이가 가진 의상 수
        vector<ClothesType> type;
        string tmp1, tmp2;
        int check;
        for (int i = 0; i < n; i++) {
            cin >> tmp1 >> tmp2;
            check = 0;
            for (int j = 0; j < int(type.size()); j++) {
                if (tmp2 == type[j].name) {
                    type[j].quantity++;
                    check++;
                }
            }
            if (check == 0) {
                type.push_back({tmp2, 1});
            }
        }

// 계산
    int size = int(type.size());
    int sum = 1;
    for (int i = 0; i < size; i++) {
        sum *= type[i].quantity + 1;
    }
    sum -= 1;

// 출력
    cout << sum << "\n";

    }
    return 0;
}