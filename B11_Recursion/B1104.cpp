// 백준 24060번 문제 (재귀 - 4 : 알고리즘 수업 - 병합 정렬 1)

// 문제:
// 오늘도 서준이는 병합 정렬 수업 조교를 하고 있다. 아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.
// N개의 서로 다른 양의 정수가 저장된 배열 A가 있다.
// 병합 정렬로 배열 A를 오름차순 정렬할 경우 배열 A에 K 번째 저장되는 수를 구해서 우리 서준이를 도와주자.
// 크기가 N인 배열에 대한 병합 정렬 의사 코드는 다음과 같다.

// merge_sort(A[p..r]) { # A[p..r]을 오름차순 정렬한다.
//     if (p < r) then {
//         q <- ⌊(p + r) / 2⌋;       # q는 p, r의 중간 지점
//         merge_sort(A, p, q);      # 전반부 정렬
//         merge_sort(A, q + 1, r);  # 후반부 정렬
//         merge(A, p, q, r);        # 병합
//     }
// }

// # A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// # A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
// merge(A[], p, q, r) {
//     i <- p; j <- q + 1; t <- 1;
//     while (i ≤ q and j ≤ r) {
//         if (A[i] ≤ A[j])
//         then tmp[t++] <- A[i++]; # tmp[t] <- A[i]; t++; i++;
//         else tmp[t++] <- A[j++]; # tmp[t] <- A[j]; t++; j++;
//     }
//     while (i ≤ q)  # 왼쪽 배열 부분이 남은 경우
//         tmp[t++] <- A[i++];
//     while (j ≤ r)  # 오른쪽 배열 부분이 남은 경우
//         tmp[t++] <- A[j++];
//     i <- p; t <- 1;
//     while (i ≤ r)  # 결과를 A[p..r]에 저장
//         A[i++] <- tmp[t++]; 
// }

// 입력:
// 첫째 줄에 배열 A의 크기 N(5 ≤ N ≤ 500,000), 저장 횟수 K(1 ≤ K ≤ 10^8)가 주어진다.
// 다음 줄에 서로 다른 배열 A의 원소 A_1, A_2, ..., A_N이 주어진다. (1 ≤ A_i ≤ 10^9)

// 출력:
// 배열 A에 K 번째 저장 되는 수를 출력한다. 저장 횟수가 K 보다 작으면 -1을 출력한다.

#include <iostream>

void merge(int[], int, int, int, int[]);

void merge_sort(int A[], int p, int r, int K[]) { // A[p..r]을 오름차순 정렬한다.
    if (p < r) {
        int q = (p + r) / 2;      // q는 p, r의 중간 지점
        merge_sort(A, p, q, K);      // 전반부 정렬
        merge_sort(A, q + 1, r, K);  // 후반부 정렬
        merge(A, p, q, r, K);        // 병합
    }
}

// A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int A[], int p, int q, int r, int K[]) {
    int i = p;
    int j = q + 1;
    int t = 0;
    int tmp[r-p+1];
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        } // tmp[t] = A[i]; t++; i++; 
        else {
        tmp[t++] = A[j++];
        } // tmp[t] = A[j]; t++; j++;
    }
    while (i <= q)  // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = A[i++];
    while (j <= r)  // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = A[j++];
    i = p;
    t = 0;
    while (i <= r) {  // 결과를 A[p..r]에 저장
        A[i] = tmp[t];
        K[1]--;               // K[1]을 하나씩 줄여가며,
        if(K[1] == 0) {       // 그게 1이 되었을 때
            K[2] = A[i];      // 저장하는 값 A[i]를 K[2]에 따로 저장해둔다.
        }
        else if(r-p+1 == K[0] && K[2] == -10) {  // 만약 마지막 merge 때까지 K[2]가 여전히 -10이면,
            K[2] = -1;                           // K[2]를 -1로 한다.
        }
        i++;
        t++;
    }
}

int main() {

    using namespace std;

    // int N;
    // int K;
    // cin >> N >> K;
    int K[3];
    cin >> K[0] >> K[1];
    K[2] = -10;

    int A[K[0]];
    for (int i = 0; i < K[0]; i++) { cin >> A[i]; }

    merge_sort(A, 0, K[0]-1, K);

    cout << K[2];

    return 0;
}