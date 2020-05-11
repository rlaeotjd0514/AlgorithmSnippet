#include <iostream>
#include <vector>

using namespace std;

int mvx[5] = { 0, -1, 0, 1, 0 };
int mvy[5] = { 0, 0, -1, 0, 1 };
vector<vector<int>> arr, dp;
int n;

int maxx = -1;

int r(int x, int y, int c) {
    dp[x][y] = c;
    int ret = c;
    for (int i = 1; i <= 4; i++) {
        int mx = x + mvx[i];
        int my = y + mvy[i];
        if (mx > n || mx < 1 || my > n || my < 1 || arr[mx][my] <= arr[x][y]) continue;
        if (dp[mx][my] != -1) {
            ret = ret > dp[mx][my] + c + 1 ? ret : dp[mx][my] + c + 1;
            continue;
        }
        int res = r(mx, my, c + 1);
        ret = ret > res ? ret : res;
    }
    if (maxx < ret) maxx = ret;
    dp[x][y] = ret - c;
    return ret;
}

int main()
{
    cin >> n;
    arr.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i].resize(n + 1);
        arr[i].resize(n + 1);
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            r(i, j, 1);
        }
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << maxx << endl;

    return 0;
}