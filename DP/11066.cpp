#include <iostream>
#include <vector>

using namespace std;
vector<int> arr;
vector<vector<int>> dp;
int n;

int r(int x, int y) {
	if (dp[x][y] > 0) return dp[x][y];
	if (x == n) return dp[x][y];
	if (x == n - 1) return dp[x][y] * 2;
	int min = -1;
	for (int k = x + 1; k <= n; k++) {
		int s1 = r(k, y);
		int s2 = r(n - k + x + 1, y + 1);
		int val = s1 + s2;
		//if (n - k1 + 1 < n) val += dp[n - k1 + 1][k];
		//if (i + k2 - 1 < n) val += dp[i + k2 - 1][k2 + k - 1];
		//cout << dp[n - k1 + 1][k] << " " << dp[i + k2 - 1][k2 + k - 1] << " : " << val << endl;
		if (min == -1 || min > val) {
			min = val;
		}
	}
	return dp[x][y] = min;
}

int main()
{
	int t;
	int cc;
	cin >> cc;
	for (int t = 1; t <= cc; t++) {

		cin >> n;

		arr.resize(n + 1);
		dp.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			dp[i].resize(i + 1);
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			dp[n][i] = arr[i];
		}
		for (int i = 1; i < n; i++) {
			dp[n - 1][i] = arr[i] + arr[i + 1];
		}

		r(1, 1);

		for (int i = n - 2; i >= 1; i--) {
			for (int k = 1; k <= i; k++) {
				int min = -1;
				//int ccx, ccy;
				//for (int j = 1; j <= n - i; j++) {
				//	int k1 = j;
				//	int k2 = j + 1;
				//	int val = dp[n - k1 + 1][k] + dp[i + k2 - 1][k2 + k - 1];
				//	//if (n - k1 + 1 < n) val += dp[n - k1 + 1][k];
				//	//if (i + k2 - 1 < n) val += dp[i + k2 - 1][k2 + k - 1];
				//	//cout << dp[n - k1 + 1][k] << " " << dp[i + k2 - 1][k2 + k - 1] << " : " << val << endl;
				//	if (min == -1 || min > val) {
				//		ccx = dp[n - k1 + 1][k];
				//		ccy = dp[i + k2 - 1][k2 + k - 1];
				//		min = val;
				//	}
				//}
				//dp[i][k] = min;						
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - i; j++) {
				cout << "   ";
			}
			for (int j = 1; j <= i; j++) {
				cout << dp[i][j] << "   ";
			}
			cout << "\n";
		}
	}
}
