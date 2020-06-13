#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> m >> n;
	vector<vector<int>> dp;
	vector<vector<int>> arr;
	dp.resize(m + 1);
	arr.resize(m + 1);
	for (int i = 0; i <= m; i++) {
		dp[i].resize(n + 1);
		arr[i].resize(n + 1);
	}
	for (int i = 1; i <= m; i++) {
		int temp;
		cin >> temp;
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> clist;
	clist.resize(m + 1);
	for (int i = 0; i <= m; i++) {
		clist[i].resize(n + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int mx = -1;
			for (int k = 0; k <= j; k++) {
				if (mx < dp[j - k][i - 1] + arr[k][i]) {
					mx = dp[j - k][i - 1] + arr[k][i];
					clist[j][i] = k;
					for (int l = 1; l < i; l++) {
						clist[j][l] = clist[j - k][l];
					}
				}
			}
			dp[j][i] = mx;
		}
	}
	cout << dp[m][n] << "\n";
	for (int i = 1; i <= n; i++) {
		cout << clist[m][i] << " ";
	}
	return 0;
}

