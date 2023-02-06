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

int CheckingPrimeNumber(int number) {       // 일일이 검사하는 Logic. 하지만 B802의 것보다는 발전됨.
    if (number == 1)
        return false;
    else if (number == 2)
        return true;
    else if (number % 2 == 0)
        return false;
    for (int i = 3; i*i <= number; i+=2) {    // 3부터 (number-1(X)) (number/2(X)) (sqrt(number)(O)) 까지로 (모두(X)) (홀수만(O) 나눠보고 딱 나누어 떨어지는게 하나라도 있으면 합성수이다.
        if (number % i == 0) {
            return false;
        }
    }
    return true;                        // return 되지않고 for 문을 모두 통과하면 소수이다.
}


int CheckingPrimeNumber2(int number, int* Factors, int size) {    // 일일이 검사해서 뽑아놓은 소수들로만 나눠보는 Logic
    if (number == 1)
        return false;
    else if (number == 2)
        return true;
    else if (number % 2 == 0)
        return false;

    int i = *Factors;
    for (int j = 0; j < size; j++) {    // 미리 추려서 뽑아놓은 소수들로 나눠보기.
        if (number % i == 0) {
            return false;
        }
        else if (i*i > number) {    // 검사하는 수가 sqrt(number)보다 커지면 더 검사할 필요가 없다.
            return true;
        }
        else
            i = *(Factors + j);
    }

    return true;    // return 되지않고 for 문을 모두 통과하면 소수이다.
}



int main() {

    using namespace std;

    vector<int> PrimeNumbers;   // 미리 뽑아놓을 PrimeNumbers
    PrimeNumbers.push_back(2);  // 2만 미리 넣어놓고,
    for (int i = 3; i <= 1000; i+=2) {  // 3부터 홀수만 검사해서 미리 뽑아놓는다.  PrimeNumbers : 1부터 1000까지의 소수들만 모아놓은 집합
        if (CheckingPrimeNumber(i)) {                                       // 근데 얘는 일일이 나눠보고 소수인지 아닌지 판별해서 얻은 것들.
            PrimeNumbers.push_back(i);
        }
    }

    int size = PrimeNumbers.size();

    int M = 0, N = 0;
    cin >> M >> N;                   // 입력

    for (int i = M; i <= N; i++) {   // M부터 N까지 소수인지 검사할 것.
        if (i > PrimeNumbers.back()) {    // 미리 뽑아놓은 소수보다 크면,
            if (CheckingPrimeNumber2(i, &PrimeNumbers[0], size)) {    // 미리 뽑아놓은 소수로 나눠보는 logic 통과 후, 소수라면 출력
                cout << i << "\n";
            }
        }
        else {                            // 미리 뽑아놓은 소수보다 작으면
            if (CheckingPrimeNumber(i)) {  // 일일이 검사하는 logic 통과 후, 소수라면 출력
                cout << i << "\n";
            }
        }
    }

    return 0;
}