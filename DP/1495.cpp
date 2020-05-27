#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, s, m;
	cin >> n >> s >> m;
	vector<int> arr;
	vector<vector<int>> dp;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		dp[i].resize(m + 1);
	}
	dp[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j] == 1) {
				int p1 = j - arr[i];
				int p2 = j + arr[i];
				if (p1 >= 0) {
					dp[i][p1] = 1;
				}
				if (p2 <= m) {
					dp[i][p2] = 1;
				}
			}
		}
	}
	for (int i = m; i >= 0; i--) {
		if (dp[n][i] == 1) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}