// ***** i <= sqrt(number) 를 i*i <= number 로 바꾸니 "맞았습니다!!"


// 백준 1929번 문제 (기본수학2 - 4 : 소수 구하기)

// 문제:
// M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

// 출력:
// 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.


#include <iostream>
#include <vector>

int CheckingPrimeNumber(int number) {
    if (number == 1)
        return false;
    else if (number == 2)
        return true;
    else if (number % 2 == 0)
        return false;
    for (int i = 3; i*i <= number; i+=2) {    // 3부터 sqrt(number) 까지로 홀수만 나눠보고 딱 나누어 떨어지는게 하나라도 있으면 합성수이다.
        if (number % i == 0) {
            return false;
        }
    }
    return true;     // return 되지않고 for 문을 모두 통과하면 소수이다.
}


int main() {
    using namespace std;

    int M = 0, N = 0;
    cin >> M >> N;

    vector<int> v(N+1);                // 체를 거르기 전, 미리 M부터 N까지의 숫자를 담아놓을 곳을 만든다.
    for (int i = 0; i < M; i++) {      // 벡터의 0번째부터 M-1번째까지 원소는 모두 0으로 만든다. (사용할 부분은 아니지만 혹시 모르니)
        v[i] = 0;
    }
    for (int i = M; i <= N; i++) {     // 벡터의 M번째부터 N번째까지 원소는 각각의 순서가 곧 그 원소 값이다.
        v[i] = i;
    }
    v[1] = 0;


    vector<int> PrimeNumbers;   // 미리 뽑아놓을 PrimeNumbers
    PrimeNumbers.push_back(2);  // 2만 미리 넣어놓고,
    for (int i = 3; i*i <= N; i+=2) {  // 3부터 홀수만 검사해서 미리 뽑아놓는다.  ->  N의 제곱근까지만 미리 뽑아놓는다.
        if (CheckingPrimeNumber(i)) {
            PrimeNumbers.push_back(i);
        }
    }

    int multiple = 0;
    int size = int(PrimeNumbers.size());
    for (int i = 0; i < size; i++) {    // 미리 뽑아놓은 PrimeNumbers들의 배수를 제거해주어야한다.
        multiple = 2;
        while (true) {
            if (PrimeNumbers[i] * multiple >= M) {     // 소수의 배수가 M ~ N 사이에 들어올때까지 곱해주는 값을 올린다.
                break;
            }
            else {
                multiple++;
            }
        }
        while (true) {
            if (PrimeNumbers[i] * multiple <= N) {
                v[ PrimeNumbers[i] * multiple ] = 0;    // 소수의 배수를 걸러준다.
                multiple++;                             // 다음 배수로 반복.
            }
            else {       // 지금 거르는 중인 미리 뽑아놓은 소수의 배수들이 이제 M ~ N 범위를 벗어나면, 다음 소수로 넘어간다.
                break;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (v[i] != 0) {
            cout << v[i] << "\n";
        }
    }


    return 0;
}