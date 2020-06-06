#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[4001][4001];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();
    int mx = 0;
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (mx < dp[i][j]) mx = dp[i][j];
            }
        }
    }
    cout << mx;
    return 0;
}