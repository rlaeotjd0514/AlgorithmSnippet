#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mvx[5] = { 0, -1, 0, 1, 0 };
int mvy[5] = { 0, 0, -1, 0, 1 };

vector<vector<unsigned long long>> arr, dp, dpr;
int n, m;

unsigned long long r(int x, int y) {
	//if (x == 1 && y == 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int i = 1; i <= 4; i++) {
		int mx = x + mvx[i];
		int my = y + mvy[i];
		if (mx < 1 || mx > n || my < 1 || my > m || arr[x][y] >= arr[mx][my]) continue;
		dp[x][y] += r(mx, my);
	}
	return dp[x][y];
}

int main() {
	struct node {
		int x, y, c;
	};
	cin >> n >> m;

	queue<node> q;

	arr.resize(n + 2);
	dp.resize(n + 2);
	dpr.resize(n + 2);
	for (int i = 1; i <= n; i++) {
		arr[i].resize(m + 2);
		dp[i].resize(m + 2);
		dpr[i].resize(m + 2);
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = -1;
		}
	}

	dp[1][1] = 1;

	cout << r(n, m) << endl;

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/

	return 0;
}