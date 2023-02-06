// "틀렸습니다"
// 다 맞게 나오는데 왜 틀렸다고 하는지 모르겠다...

// 백준 11051번 문제 (정수론 및 조합론 - 8 : 이항 계수 2)

// 문제:
// 자연수 N과 정수 K가 주어졌을 때 이항 계수 (N K) 를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1000, 0 ≤ K ≤ N)

// 출력:
// (N K)를 10,007로 나눈 나머지를 출력한다.


#include <iostream>
#include <vector>
using namespace std;

int Remainder(int n) {
    return (n % 10007);
}

int main() {

// 입력
    int N, K;
    cin >> N >> K;
    vector<int> num; // numerator
    vector<int> den; // denominator
    if (K > N-K) { K = N-K; } // nCk 보다 nCn-k 가 나으면 그렇게 하자.

// nCk의 분자, 분모의 각 항들을 일단 벡터의 원소로 각각 저장한다.
    for (int i = 0; i < K; i++) {
        num.push_back(N-i);
    }

    for (int i = 0; i < K; i++) {
        den.push_back(i+1);
    }

// 약분해주기
    for (int i = 0; i < K; i++) {        
        for (int j = 0; j < K; j++) {
            if (num[i] == 1) {break;}
            if (den[j] != 1) {
                if (num[i]%den[j]==0) {
                    num[i] /= den[j];
                    den[j] = 1;
                }
                else {
                    for (int k = 2; k < den[j]; k++) {
                        if (num[i]%k == 0 && den[j]%k == 0) {
                            num[i] /= k;
                            den[j] /= k;
                        }
                    }
                }
            }
        }
    }

//
    int multiple_num = 1;

    for (int i = 0; i < K; i++) {
        multiple_num *= num[i];
        multiple_num = Remainder(multiple_num);
    }

    cout << Remainder(multiple_num) << "\n";

    return 0;
}