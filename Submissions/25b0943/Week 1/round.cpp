#include<iostream>
#include<cstring>
using namespace std;

int factors(int val, int p) {
    if (val == 0) return 0;
    int count = 0;
    while (val % p == 0) {
        count++;
        val /= p;
    }
    return count;
}

int main(){
    int n;
    cin >> n;

    int grid[n][n];
    int f2[n][n];
    int f5[n][n];
    int dp2[n][n];
    int dp5[n][n];

    int zero_r = -1, zero_c = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) {
                zero_r = i;
                zero_c = j;
                f2[i][j] = 1;
                f5[i][j] = 1;
            } else {
                f2[i][j] = factors(grid[i][j], 2);
                f5[i][j] = factors(grid[i][j], 5);
            }
        }
    }

    dp2[0][0] = f2[0][0];
    dp5[0][0] = f5[0][0];

    for (int i = 1; i < n; i++) {
        dp2[0][i] = dp2[0][i - 1] + f2[0][i];
        dp5[0][i] = dp5[0][i - 1] + f5[0][i];
    }
    for (int i = 1; i < n; i++) {
        dp2[i][0] = dp2[i - 1][0] + f2[i][0];
        dp5[i][0] = dp5[i - 1][0] + f5[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int min2;
            if (dp2[i - 1][j] < dp2[i][j - 1]) {
                min2 = dp2[i - 1][j];
            } else {
                min2 = dp2[i][j - 1];
            }

            int min5;
            if (dp5[i - 1][j] < dp5[i][j - 1]) {
                min5 = dp5[i - 1][j];
            } else {
                min5 = dp5[i][j - 1];
            }
            
            dp2[i][j] = min2 + f2[i][j];
            dp5[i][j] = min5 + f5[i][j];
        }
    }

    int ans;
    if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1]) {
        ans = dp2[n - 1][n - 1];
    } else {
        ans = dp5[n - 1][n - 1];
    }

    if (zero_r != -1 && ans > 1) {
        cout << 1 << "\n";
        for (int i = 0; i < zero_r; i++) cout << 'D';
        for (int j = 0; j < zero_c; j++) cout << 'R';
        for (int i = zero_r; i < n - 1; i++) cout << 'D';
        for (int j = zero_c; j < n - 1; j++) cout << 'R';
        cout << "\n";
        return 0;
    }

    cout << ans << "\n";
    string path = "";

    int r = n - 1, c = n - 1;
    while (r > 0 || c > 0) {
        if (r == 0) {
            path = 'R' + path;
            c--;
        } else if (c == 0) {
            path = 'D' + path;
            r--;
        } else {
            if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1]) {
                if (dp2[r - 1][c] < dp2[r][c - 1]) {
                    path = 'D' + path;
                    r--;
                } else {
                    path = 'R' + path;
                    c--;
                }
            } else {
                if (dp5[r - 1][c] < dp5[r][c - 1]) {
                    path = 'D' + path;
                    r--;
                } else {
                    path = 'R' + path;
                    c--;
                }
            }
        }
    }
    
    cout << path << "\n";

    return 0;
}