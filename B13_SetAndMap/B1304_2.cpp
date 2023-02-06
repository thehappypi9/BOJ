// "시간초과"

// 백준 10816번 문제 (집합과 맵 - 4 : 숫자 카드 2)

// 문제:
// 숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다.
// 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

// 입력:
// 첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다.
// 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
// 셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다.
// 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다.
// 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

// 출력:
// 첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Tester(vector<int>* whatHeHas, int testThis);
int Test(vector<int>* whatHeHas, int testThis, int left, int right);
void Counter(vector<int>* count, int i, int* c);
void HowManyLeft(vector<int>* whatHeHas, int testThis, int left, int mid, vector<int>* count, int* c);
void HowManyRight(vector<int>* whatHeHas, int testThis, int mid, int right, vector<int>* count, int* c);
bool CheckMid(vector<int>* whatHeHas, int testThis, int left, int right);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// 입력
    int N; cin >> N;
    vector<int> HeHas(N);
    for (int i = 0; i < N; i++) { cin >> HeHas[i]; }
    int M; cin >> M;
    vector<int> HowMany(M);
    for (int j = 0; j < M; j++) { cin >> HowMany[j]; }

// 정렬
    sort(HeHas.begin(), HeHas.end());

// 계산 및 출력
    for (int j = 0; j < M; j++) {
        cout << Tester(&HeHas, HowMany[j]) << " ";
        //cout << "j: " << j << endl;
        //Tester(&HeHas, HowMany[j]);
    }

    return 0;
}


int Tester(vector<int>* whatHeHas, int testThis) {
    int size = int((*whatHeHas).size());
    int left = 0; int right = size-1;
    int mid = Test(whatHeHas, testThis, left, right);
    vector<int> count(size, 0);
    int c = 0;
    if (mid == -1) { return 0; }
    else { 
        Counter(&count, mid, &c); //count[mid] = true;
        HowManyLeft(whatHeHas, testThis, 0, mid, &count, &c);
        HowManyRight(whatHeHas, testThis, mid, size-1, &count, &c);
    }

    return c;
}

int Test(vector<int>* whatHeHas, int testThis, int left, int right) {
    int mid = (left+right)/2;
    if (left == right) {
        if ((*whatHeHas)[mid] == testThis) { return mid; }
        else { return -1; }
    }
    else {
        if ((*whatHeHas)[mid] == testThis) { return mid; }
        else if ((*whatHeHas)[mid] < testThis) { return Test(whatHeHas, testThis, mid+1, right); }
        else { return Test(whatHeHas, testThis, left, mid); }
    }
    return 0;
}

void Counter(vector<int>* count, int i, int* c) {
    if ( (*count)[i] == 0 ) {
        (*count)[i] = 1;
        (*c)++;
    }
}

// 왼쪽:
void HowManyLeft(vector<int>* whatHeHas, int testThis, int left, int mid, vector<int>* count, int* c) {
    if (mid-left <= 2) {
        if ( (*whatHeHas)[mid]==testThis ) { Counter(count, mid, c); /*(*count)[mid] = true;*/ }
        if ( (mid-1)>=left && (*whatHeHas)[mid-1]==testThis ) { Counter(count, mid-1, c); /*(*count)[mid-1] = true;*/ }
        if ( (mid-2)>=left && (*whatHeHas)[mid-2]==testThis ) { Counter(count, mid-2, c); /*(*count)[mid-2] = true;*/ }
        return;
    }

    int newleft = left; int newright = mid-1;
    if ( CheckMid(whatHeHas, testThis, newleft, newright) ) {
        for (int i = (newleft+newright)/2; i <= newright; i++) {
            Counter(count, i, c);
            //(*count)[i] = true;
        }
        HowManyLeft(whatHeHas, testThis, left, (newleft+newright)/2, count, c);
    }
    else {
        HowManyRight(whatHeHas, testThis, (newleft+newright)/2, newright, count, c);
    }
}

// 오른쪽:
void HowManyRight(vector<int>* whatHeHas, int testThis, int mid, int right, vector<int>* count, int* c) {
    if (right-mid <= 2) {
        if ( (*whatHeHas)[mid]==testThis ) { Counter(count, mid, c); /*(*count)[mid] = true;*/ }
        if ( (mid+1)<=right && (*whatHeHas)[mid+1]==testThis ) { Counter(count, mid+1, c); /*(*count)[mid+1] = true;*/ }
        if ( (mid+2)<=right && (*whatHeHas)[mid+2]==testThis ) { Counter(count, mid+2, c); /*(*count)[mid+2] = true;*/ }
        return;
    }

    int newleft = mid+1, newright = right;
    if ( CheckMid(whatHeHas, testThis, newleft, newright) ) {
        for (int i = newleft; i <= (newleft+newright)/2; i++) {
            Counter(count, i, c);
            //(*count)[i] = true;
        }
        HowManyRight(whatHeHas, testThis, (newleft+newright)/2, newright, count, c);
    }
    else {
        HowManyLeft(whatHeHas, testThis, newleft, (newleft+newright)/2, count, c);
    }
}

bool CheckMid(vector<int>* whatHeHas, int testThis, int left, int right) {
    int mid = (left+right)/2;
    if ((*whatHeHas)[mid] == testThis) { return true; }
    else { return false; }
}