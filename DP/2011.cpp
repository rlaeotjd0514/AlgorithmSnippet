#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s[0] - 48 == 0) {
        cout << 0;
        return 0;
    }
    int ls = s.length();
    vector<int> arr, dp;
    arr.resize(ls + 1);
    dp.resize(ls + 1);
    arr[1] = s[0] - 48;
    int offset = 1;
    for (int i = 2; i <= ls; i++) {
        if (s[i - 1] - 48 == 0) {
            if (arr[i - offset] > 2) {
                cout << 0;
                return 0;
            }
            arr[i - offset] *= 10;
            offset += 1;
            continue;
        }
        arr[i - offset + 1] = s[i - 1] - 48;
    }
    ls -= offset;
    ls += 1;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= ls; i++) {
        if (arr[i] >= 10) {
            dp[i] = dp[i - 1];
            continue;
        }
        int prev = arr[i] + arr[i - 1] * 10;
        if (prev > 26) {
            dp[i] = dp[i - 1];
        }
        else {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        dp[i] %= 1000000;
    }

    cout << dp[ls];

    return 0;
}