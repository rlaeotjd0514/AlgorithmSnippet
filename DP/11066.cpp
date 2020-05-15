#include <iostream>
#include <vector>

/*
1 + 21 = 22, sum = 22
3 + 4 = 7, sum = 29
7 + 5 = 12, sum = 41
22 + 12 = 34, sum = 75
5 + 4 = 9, sum = 84
3 + 5 = 8, sum = 92
9 + 8 = 17, sum = 109
35 + 17 = 52, sum = 161
34 + 52 = 86, sum = 247
14 + 17 = 31, sum = 278
21 + 31 = 52, sum = 330
52 + 32 = 84, sum = 414
98 + 84 = 182, sum = 596
86 + 182 = 268, sum = 864
*/
using namespace std;
vector<int> arr;
struct p {
	int x1, y1;
	int x2, y2;
};
vector<vector<p>> path;
vector<vector<int>> dp;
vector<vector<int>> sp;
int n;

int sum = 0;

int r(int x, int y) {
	if (dp[x][y] > 0) return dp[x][y];//이미 해당 지점 합이 구해진 경우에는 그 합을 사용함
	if (x == n) return dp[x][y];
	if (x == n - 1) return dp[x][y] * 2;
	int min = -1;
	for (int k = 1; k <= n - x; k++) {
		int s1 = r(x + k, y);
		int s2 = r(n - k + 1, n - k + 1 - (x - y));
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

int c(int x, int y) {
	if (x == n) return sp[x][y];
	if (x == n - 1) return sp[x][y] * 2;
	if (sp[x][y] > 0) return sp[x][y];
	int min = -1;
	for (int k = 1; k <= n - x; k++) {
		int s1 = c(x + k, y);
		int s2 = c(n - k + 1, n - k + 1 - (x - y));
		int val = s1 + s2;
		if (x + k < n - 1) val += dp[x + k][y];
		if (n - k + 1 < n - 1) val += dp[n - k + 1][n - k + 1 - (x - y)];
		//cout << dp[n - k1 + 1][k] << " " << dp[i + k2 - 1][k2 + k - 1] << " : " << val << endl;
		if (min == -1 || min > val) {
			min = val;
		}
	}

	return sp[x][y] = min;
}

int main()
{
	int t;
	int cc;
	cin >> cc;
	for (int t = 1; t <= cc; t++) {
		cin >> n;
		path.resize(n + 1);
		arr.resize(n + 1);
		dp.resize(n + 1);
		sp.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			path[i].resize(n + 1);
			sp[i].resize(i + 1);
			dp[i].resize(i + 1);
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				sp[i][j] = 0;
				dp[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; i++) {
			dp[n][i] = arr[i];
			sp[n][i] = arr[i];
		}
		for (int i = 1; i < n; i++) {
			dp[n - 1][i] = arr[i] + arr[i + 1];
			sp[n - 1][i] = arr[i] + arr[i + 1];
		}


		r(1, 1);
		c(1, 1);
		/*
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
		*/
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - i; j++) {
				cout << "   ";
			}
			for (int j = 1; j <= i; j++) {
				cout << dp[i][j] << "   ";
			}
			cout << "\n";
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - i; j++) {
				cout << "   ";
			}
			for (int j = 1; j <= i; j++) {
				cout << sp[i][j] << "   ";
			}
			cout << "\n";
		}*/

		cout << sp[1][1] << endl;
	}
}
