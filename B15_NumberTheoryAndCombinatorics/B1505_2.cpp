// "시간초과"

// 백준 2981번 문제 (정수론 및 조합론 - 5 : 검문)

// 문제:
// 트럭을 타고 이동하던 상근이는 경찰의 검문을 받게 되었다. 경찰은 상근이가 운반하던 화물을 하나하나 모두 확인할 것이기 때문에, 검문하는데 엄청나게 오랜 시간이 걸린다.
// 상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.
// 먼저 근처에 보이는 숫자 N개를 종이에 적는다. 그 다음, 종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야 한다.
// N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 종이에 적은 수의 개수 N이 주어진다. (2 ≤ N ≤ 100)
// 다음 줄부터 N개 줄에는 종이에 적은 수가 하나씩 주어진다. 이 수는 모두 1보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수이다. 같은 수가 두 번 이상 주어지지 않는다.
// 항상 M이 하나 이상 존재하는 경우만 입력으로 주어진다.

// 출력:
// 첫째 줄에 가능한 M을 공백으로 구분하여 모두 출력한다. 이때, M은 증가하는 순서이어야 한다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Euclidean(int a, int b)
{
    int r = a % b;
    if (r == 0) {
      return b;
    }
    return Euclidean(b, r);
}

int main() {


// 입력
    int N; cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) { cin >> numbers[i]; }

// gap: N개의 입력값들의 서로간의 차 N-1개를 모은 벡터
    vector<int> gap(N-1);
    for (int i = 1; i < N; i++) {
        gap[i-1] = abs(numbers[i]-numbers[i-1]);
    }
    sort(gap.begin(), gap.end());

// gap의 원소들의 최대공약수를 구하고, 그 최대공약수의 1이 아닌 약수들을 출력하면 될 것.
    // N = 2일때. Out of Bound 막기 위함
    if (N == 2) {
        for (int j = 2; j <= gap[0]; j++) {
            if (gap[0] % j == 0) { cout << j << " ";}
        }
        return 0;
    }
    // N > 2 일때.
    vector<int> GCD(N-2);
    for (int i = 1; i < N-1; i++) {
        GCD[i-1] = Euclidean(gap[i], gap[i-1]);  // gap의 바로 인접한 두 원소 간의 최대공약수를 모은다.
    }
    sort(GCD.begin(), GCD.end());
    for (int j = 2; j <= GCD[0]; j++) {          // 그 중 가장 작은 값이 gap의 모든 원소들의 최대공약수일 것이다.
        if (GCD[0] % j == 0) { cout << j << " "; }  // 최대공약수의 약수들 = 공약수들.
    }

    return 0;
}