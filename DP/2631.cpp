#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> arr, dp;
	cin >> n;
	arr.resize(n + 1);
	dp.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	int mx = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
				if (mx < dp[i]) mx = dp[i];
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";*/
	cout << n - mx << endl;

	return 0;
}