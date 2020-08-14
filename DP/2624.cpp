#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main()
{
	int n, m;
	vector<vector<int>> arr;
	vector<pair<int, int>> coin;
	scanf("%d %d", &m, &n);
	coin.resize(n + 1);
	int cmax = -1;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &coin[i].first, &coin[i].second);
		if (cmax < coin[i].second) cmax = coin[i].second;
	}

	arr.resize(cmax + 1);
	for (int i = 0; i <= cmax; i++) {
		arr[i].resize(m + 1);
		for (int j = 0; j <= m; j++) {
			arr[i][j] = 0;
		}
	}
	arr[0][0] = 1;

	sort(coin.begin(), coin.end(), compare);

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= coin[i].second; k++) {
			for (int j = 0; j < coin[i].first; j++) {
				arr[k][j] = arr[k - 1][j];
			}
			for (int j = coin[i].first; j <= m; j++) {
				if (arr[k - 1][j - coin[i].first] != 0 || arr[0][j] != 0) {
					arr[k][j] = arr[k - 1][j - coin[i].first] + arr[0][j];
				}
			}
			for (int j = 1; j <= m; j++) {
				printf("%d ", arr[k][j]);
			}
			printf("\n");
		}
		for (int j = 1; j <= m; j++) {
			arr[0][j] = arr[coin[i].second][j];
		}
	}

	printf("%d", arr[coin[n].second][m]);

	return 0;
}
