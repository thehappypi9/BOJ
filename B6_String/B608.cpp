// 백준 5622번 문제 (문자열 - 8 : 다이얼)

// 문제:
// 상근이의 할머니는 아래 그림과 같이 오래된 다이얼 전화기를 사용한다.
// 전화를 걸고 싶은 번호가 있다면, 숫자를 하나를 누른 다음에 금속 핀이 있는 곳 까지 시계방향으로 돌려야 한다.
// 숫자를 하나 누르면 다이얼이 처음 위치로 돌아가고, 다음 숫자를 누르려면 다이얼을 처음 위치에서 다시 돌려야 한다.
// 숫자 1을 걸려면 총 2초가 필요하다. 1보다 큰 수를 거는데 걸리는 시간은 이보다 더 걸리며, 한 칸 옆에 있는 숫자를 걸기 위해선 1초씩 더 걸린다.
// 상근이의 할머니는 전화 번호를 각 숫자에 해당하는 문자로 외운다. 즉, 어떤 단어를 걸 때, 각 알파벳에 해당하는 숫자를 걸면 된다.
// 예를 들어, UNUCIC는 868242와 같다.
// 할머니가 외운 단어가 주어졌을 때, 이 전화를 걸기 위해서 필요한 최소 시간을 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 알파벳 대문자로 이루어진 단어가 주어진다. 단어의 길이는 2보다 크거나 같고, 15보다 작거나 같다.

// 출력:
// 첫째 줄에 다이얼을 걸기 위해서 필요한 최소 시간을 출력한다.

#include <iostream>
#include <string>

int main() {

    using namespace std;

    string str;
    cin >> str;

    int time = 0;

    for (unsigned long int i = 0; i < str.length(); i++)
    {
        switch (str[i]) {
            case 65:
            case 66:
            case 67:
                time += 3;    // A, B, C
                break;
            case 68:
            case 69:
            case 70:
                time += 4;    // D, E, F
                break;
            case 71:
            case 72:
            case 73:
                time += 5;    // G, H, I
                break;
            case 74:
            case 75:
            case 76:
                time += 6;    // J, K, L
                break;
            case 77:
            case 78:
            case 79:
                time += 7;    // M, N, O
                break;
            case 80:
            case 81:
            case 82:
            case 83:
                time += 8;    // P, Q, R, S
                break;
            case 84:
            case 85:
            case 86:
                time += 9;    // T, U, V
                break;
            case 87:
            case 88:
            case 89:
            case 90:
                time += 10;    // W, Y, X, Z
                break;
        }
    }

    cout << time << endl;

    return 0;
}