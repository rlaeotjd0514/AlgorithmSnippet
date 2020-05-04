#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define maxn 30
using namespace std;

int arr[maxn][maxn];
int pdalist[maxn];
int pdac = 0;
int n;

void dfs(int x, int y) {	
	pdalist[pdac]++;
	arr[x][y] = 0;
	if (!(x + 1 >= n || x + 1 < 0 || y >= n || y < 0 || arr[x + 1][y] == 0)) {
		dfs(x + 1, y);
	}
	if (!(x - 1 >= n || x - 1 < 0 || y >= n || y < 0 || arr[x - 1][y] == 0)) {
		dfs(x - 1, y);
	}
	if (!(x >= n || x < 0 || y + 1 >= n || y + 1 < 0 || arr[x][y + 1] == 0)) {
		dfs(x, y + 1);
	}
	if (!(x >= n || x < 0 || y - 1 >= n || y - 1 < 0 || arr[x][y - 1] == 0)) {
		dfs(x, y - 1);
	}
}

int main() {
	cin >> n;
	char buf[maxn];
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < n; j++) {
			arr[i][j] = buf[j] - 48;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				padc++;
				dfs(i, j);
			}
		}
	}

	sort(pdalist + 1, pdalist + pdac + 1);

	cout << pdac << endl;

	for (int i = 1; i <= pdac; i++) {
		cout << pdalist[i];
	}
	cout << endl;
	return 0;
}