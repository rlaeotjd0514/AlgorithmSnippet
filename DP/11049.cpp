#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct met {
	int x, y;
	unsigned int sum = 1;
};

met power(met a, met b) {
	if (a.y != b.x) return { -1, -1, (unsigned int)-1 };
	return { a.x, b.y, (unsigned int)(a.x * a.y * b.y) };
}

met dp[501][501];

int main()
{
	int n;
	cin >> n;
	vector<met> arr;
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].x >> arr[i].y;
		dp[n][i].x = arr[i].x;
		dp[n][i].y = arr[i].y;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			met sv = { 0, 0, 0xffffffffui32 };
			int x = -1, y = -1;
			for (int k = 1; k <= n - i; k++) {
				int x1 = i + k;
				int y1 = j;
				int x2 = n - k + 1;
				int y2 = j + (n - i) - k + 1;
				met s = power(dp[x1][y1], dp[x2][y2]);
				if (s.sum == -1) continue;
				if (sv.sum > s.sum) {
					sv = s;
				}
			}
			dp[i][j] = sv;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "{" << dp[i][j].x << "," << dp[i][j].y << ":" << dp[i][j].sum << "} ";
		}
		cout << "\n";
	}

	cout << dp[1][1].sum;

	return 0;
}