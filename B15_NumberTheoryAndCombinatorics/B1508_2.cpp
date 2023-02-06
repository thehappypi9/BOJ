// "맞았습니다!!"
// 거의 모든 경우에서 약분이 제대로 되는데, 안 되는 경우가 있었다! (ex. 24 8)
// 53번째 줄에 k--; 한 줄 추가하여 해결

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
            if (num[i] == 1) {break;}  // num[i] == 1 이면 이제 더 약분할 게 없다.
            if (den[j] != 1) {         // den[i] == 1 이어도 약분할 수가 없으니 den[i] != 에 대해서만 보자.
                if (num[i]%den[j]==0) {   // num[i] / den[i] 가 나누어떨어지면 잘 됐다. 바로 약분해버리자.
                    num[i] /= den[j];
                    den[j] = 1;
                }
                else {                    // 바로 나누어떨어지지 않더라도 공약수로 약분할 수 있는지 보고 약분한다.
                    for (int k = 2; k < den[j]; k++) {
                        if (num[i]%k == 0 && den[j]%k == 0) {
                            num[i] /= k;     // 공약수 k로 약분
                            den[j] /= k;     // 공약수 k로 약분
                            k--;
                        }
                    }
                }
            }
        }
    }


// 약분 끝나고 분자에 남은 수들 곱하기 (단, 곱해주면서 계속 10007로 나누어준다.)
    int multiple_num = 1;

    for (int i = 0; i < K; i++) {
        multiple_num *= num[i];
        multiple_num = multiple_num % 10007;  // 곱해주면서 계속 10007로 나눠주면서 나머지만 취한다.
    }

    cout << multiple_num << "\n";

    return 0;
}