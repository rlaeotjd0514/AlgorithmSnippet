#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[105][105][105];

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int l1 = s1.length();
	int l2 = s2.length();
	int l3 = s3.length();
	int mx = 0;
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			for (int k = 1; k <= l3; k++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i - 1][j - 1][k - 1] + 1 });
					if (mx < dp[i][j][k]) {
						mx = dp[i][j][k];
					}
				}
				else {
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });
				}
			}
		}
	}

	cout << mx;
	return 0;
}