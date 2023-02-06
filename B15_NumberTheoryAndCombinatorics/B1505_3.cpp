// "맞았습니다!!"

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
    int tmp1, tmp2;
    cin >> tmp1;
    vector<int> gap;
    for (int i = 1; i < N; i++) {
        if (i % 2 == 1) {
            cin >> tmp2;
        }
        else {
            cin >> tmp1;
        }
        gap.push_back(abs(tmp1-tmp2));
    }

    sort(gap.begin(), gap.end());

// gap의 원소들의 최대공약수를 구하고, 그 최대공약수의 1이 아닌 약수들을 출력하면 될 것.
// gap의 원소(N-1개)들의 최대공약수(N-2개)를 구한다.
    vector<int> GCD;
    // N = 2일때. (gap에 원소가 1개밖에 없기에 두 수의 최대공약수를 구할 수 없다.)
    if (N == 2) {
        GCD.push_back(gap[0]);
    }
    // N > 2 일때.
    else {
        for (int i = 1; i < N-1; i++) {
            GCD.push_back( Euclidean(gap[i], gap[i-1]) );  // gap의 바로 인접한 두 원소 간의 최대공약수를 모은다.
        }
        sort(GCD.begin(), GCD.end());    
    }

// N-2개의 최대공약수들 중 가장 작은 값 -> gap의 모든 원소들의 최대공약수
// N-2개의 최대공약수들 중 가장 작은 값의 약수들 -> gap의 모든 원소들의 공약수
    vector<int> factors;
    int tmp3 = 0;
    for (int j = 2; j*j <= GCD[0]; j++) { // j가 GCD[0]의 약수인지 판별 후 가장 작은 것부터 GCD[0]의 양의 제곱근보다 작은 것 까지 factors 벡터에 담는다.
        if (j*j == GCD[0]) {              // GCD[0]의 제곱근이 정수라서 GCD[0]의 약수라고 하면, 임시로 저장해놓은 뒤 나중에 따로 넣어준다.
            tmp3 = j;
        }
        else if (GCD[0] % j == 0) {
            factors.push_back(j);         // GCD[0]의 약수들을 factors 벡터에 담는다.
        }
    }
    int size = factors.size();            // 이때의 약수의 개수를 size 변수에 저장해놓는다.
    if (tmp3 != 0) { factors.push_back(tmp3); }  // 아까 임시로 저장해놓았던 값이 있다면 지금 따로 넣어준다.
    for (int k = size-1; k >= 0; k--) {          // GCD[0]의 약수들 중 GCD[0]의 양의 제곱근보다 작은 값들에 대해서, GCD[0]을 그것들로 나눈 것 또한 GCD[0]의 약수이다.
        factors.push_back(GCD[0]/factors[k]);    // 작은 것부터 순서대로 담는다.
    }


// 출력
    size = int(factors.size());
    for (int k = 0; k < size; k++) {
        cout << factors[k] << " ";
    }
    cout << GCD[0];

    return 0;
}