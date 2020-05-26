#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> arr;
int dp[17][1 << 16 + 1];
int compt;
int sn;

int func(int now, int bitm) {
	if (compt == bitm) {//¸ðµç Å½»ö ¸¶Ä§
		return arr[now][1];
	}
	if (dp[now][bitm] != 0) {//ÀÌ¹Ì Å½»öµÊ
		return dp[now][bitm];
	}
	int mn = 999999999;
	for (int i = 2; i <= n; i++) {
		if ((bitm & (1 << (i - 1))) == 0 && (arr[now][i] != 0)) {
			int res = func(i, (bitm | (1 << (i - 1))));
			if (res == 0) continue;
			mn = min(mn, res + arr[now][i]);
		}
	}
	return dp[now][bitm] = mn;
}

int main() {
	cin >> n;
	compt = (1 << n) - 1;// 10000 = 16 1111 = 15
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		arr[i].resize(n + 1);
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	int res = func(1, 1);

	cout << res;

	return 0;
}