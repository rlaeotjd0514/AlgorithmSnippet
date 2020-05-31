#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 10) {
        cout << n;
        return 0;
    }
    if (n == 1022) {
        cout << 9876543210;
        return 0;
    }
    if (n > 1021) {
        cout << -1;
        return 0;
    }
    vector<vector<vector<int>>> dp;
    //[자릿수][시작하는수][숫자들(push)]    
    int cnt = 0;
    n -= 10;
    dp.resize(10);
    for (int i = 0; i <= 9; i++) {
        dp[0].resize(10);
        dp[0][i].push_back(i);
    }
    int mask = 1;
    for (int i = 1; ; i++) {
        mask *= 10;
        for (int j = 1; j <= 9; j++) {
            dp[i].resize(11);
            for (int k = 0; k < j; k++) {
                for (auto d : dp[i - 1][k]) {
                    dp[i][j].push_back(j * mask + d);
                    //cout << cnt << " " << j * mask + d << "\n";
                    if (cnt++ == n) {
                        cout << j * mask + d;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}