// 이항계수 구하는 함수.  B1508_2의 main함수에서 가져옴.
int ncr (int n, int r) {
    vector<int> num;
    vector<int> den;
    if (r > n-r) { r = n-r; }
    for (int i = 0; i < r; i++) { num.push_back(n-i); }
    for (int i = 0; i < r; i++) { den.push_back(i+1); }
    for (int i = 0; i < r; i++) {        
        for (int j = 0; j < r; j++) {
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
                            k--;
                        }
                    }
                }
            }
        }
    }
    int multiple_num = 1;
    for (int i = 0; i < r; i++) { multiple_num *= num[i]; }

    return multiple_num;
}