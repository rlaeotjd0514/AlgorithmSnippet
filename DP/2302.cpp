#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dp;
    vector<int> arr;
    arr.resize(m + 2);
    dp.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
    }
    int s = 2;
    int d = 1;
    for (int i = 0; i <= n; i++) {
        dp[i] = 1;
    }
    arr[m + 1] = n + 1;
    for (int i = 1; i <= m + 1; i++) {
        for (int j = s; j < arr[i]; j++) {
            dp[j] = dp[j - 1] + dp[j - 2];
        }
        d *= dp[arr[i] - 1];
        s = arr[i] + 2;
    }

    cout << d;
}