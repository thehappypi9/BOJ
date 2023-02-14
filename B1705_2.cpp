// https://mygumi.tistory.com/97 코드 참고 후 이해.
// 백준 1912번 문제 (동적 계획법 1 - 5 : 연속합)
// https://www.acmicpc.net/problem/1912

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
// 입력
    int n;
    cin >> n;
    
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        cin >> dp[i];
    }

// 계산
    int max = dp[0];
    for(int i = 1; i < n; i++) {
        if (dp[i-1] > 0 && dp[i] + dp[i-1] > 0) {  // 직전까지의 연속합의 값이 0보다 크고, 그것에다가 현재 인덱스의 값을 더해도 0보다 크면,
            dp[i] += dp[i-1];                      // 그대로 가져와서 현재 것을 또 더해준다. (이 값이 최댓값은 아닐지라도 뒤에 도움이 되는 수이기 때문에)
        }                                          // 만약 이 if문을 통과하지 못했다면, for문의 다음 스텝에서는 여태까지의 연속합을 버리고 새로 시작하게 된다.
        if (max < dp[i]) {
            max = dp[i];                           // 위 if문과는 별개로, 역대 최댓값은 알아서 잘 저장한다.
        }
    }

// 출력
    cout << max;

	return 0;
}