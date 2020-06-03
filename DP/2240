#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree {
    int t1, t2;
};

int main()
{
    vector<int> arr;
    int t = 1;
    int n;
    cin >> t >> n;
    int prev = 0;
    int cnt = 0;
    int sp;
    for (int i = 1; i <= t; i++) {
        int imsi;
        cin >> imsi;
        if (i == 1) {
            sp = imsi;
        }
        if (prev != imsi && prev != 0) {
            arr.push_back(cnt);
            cnt = 0;
        }
        cnt++;
        prev = imsi;
    }
    arr.push_back(cnt);
    
    vector<vector<int>> dp;
    int len = arr.size();
    n += 1;

    dp.resize(len + 1);

    for (int i = 1; i <= len; i++) {
        dp[i].resize(n + 1);
    }

    dp[1][sp] = arr[0];

    int dap = arr[0];

    for (int i = 2; i <= len; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > i + sp) continue;
            if (j % 2 != (i + sp) % 2) {
                int mx = max(dp[i - 1][j], dp[i - 1][j - 1]);
                dp[i][j] = mx + arr[i - 1];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
            if (dap < dp[i][j]) dap = dp[i][j];
        }
    }

    /*for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    } */   

    cout << dap;

    return 0;
}