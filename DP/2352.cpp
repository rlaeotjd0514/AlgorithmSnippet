#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> arr, dp, dpc;
    cin >> n;
    dp.resize(n + 1);
    dpc.resize(n + 1);
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
        dpc[i] = 2147483647;
    }
    dpc[0] = (-2147483647 - 1);
    dpc[1] = arr[1];
    int ml = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i] > dpc[ml]) {
            ml++;
            dpc[ml] = arr[i];
        }
        else {
            auto p = lower_bound(dpc.begin(), dpc.end(), arr[i]);
            *p = min(*p, arr[i]);
        }
    }

    for (int i = n; i >= 1; i--) {
        if (dpc[i] != 2147483647) {
            cout << i;
            return 0;
        }
    }

    cout << dp[n];
    return 0;
}