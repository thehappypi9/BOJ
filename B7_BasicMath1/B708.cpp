// 백준 10757번 문제 (기본수학1 - 8 : 큰 수 A+B)

// 문제:
// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)

// 출력:
// 첫째 줄에 A+B를 출력한다.

#include <iostream>
#include <string>
#include <vector>

int main() {

    using namespace std;

    string A;
    string B;

    cin >> A >> B;

    vector<int> iA(A.length());    // A를 거꾸로 받을 벡터
    vector<int> iB(B.length());    // B를 거꾸로 받을 벡터

    int length = 0;                // sum의 길이를 위한 간단한 코드
    if (A.length() > B.length()) {
        length = A.length();
    }
    else {
        length = B.length();
    }

    vector<int> iSum(length+1);       // A+B를 받을 벡터. iA, iB처럼 일의자리부터 시작한다.

    for (unsigned long int i = 0; i < A.length(); i++) {   // A를 뒤에서부터 iA에 넣는다.
        iA[i] = A[A.length()-i-1] - 48;
    }
    for (unsigned long int i = 0; i < B.length(); i++) {   // B를 뒤에서부터 iB에 넣는다.
        iB[i] = B[B.length()-i-1] - 48;
    }

    for (unsigned long int i = 0; i < iSum.size()-1; i++) {  // 덧셈을 직접 코드로 구현.
        if (i < iA.size() && i < iB.size()) {
            iSum[i] = iA[i] + iB[i];       // 더하기
        }
        else if (i < iA.size() && i >= iB.size()) {
            iSum[i] = iA[i];
        }
        else {
            iSum[i] = iB[i];
        }
    }

    for (unsigned long int i = 0; i < iSum.size()-1; i++) {     // 몰아서 하는 받아올림.
        if (iSum[i] >= 10) {
            iSum[i] = iSum[i] - 10;
            iSum[i+1]++;
        }
    }

    if (iSum.back() == 0) {
        iSum.pop_back();               // 맨 마지막 자리(실제로는 맨 첫 자리)가 0이면 없애버린다.
    }

    vector<int> Sum(iSum.size());

    for (unsigned long int i = 0; i < Sum.size(); i++) {
        Sum[i] = iSum[Sum.size()-i-1];
    }

    for (unsigned long int i = 0; i < Sum.size(); i++) {
        cout << Sum[i];
    }


    return 0;
}