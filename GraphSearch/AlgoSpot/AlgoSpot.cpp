// AlgoSpot.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXVAL = 999;

vector< vector < bool > > arr;
vector< vector < int > > check;

struct man {
	int x;
	int y;
	int wallbreakcnt;
};

int mvx[4] = { 0, 1, 0, -1 };
int mvy[4] = { 1, 0, -1, 0 };

int main()
{
	string imsi;
	int n, m;
	int i, j;
	cin >> m >> n;
	arr.resize(n + 1);
	check.resize(n + 1);
	for (i = 1; i <= n; i++) {
		arr[i].resize(m + 1);
		check[i].resize(m + 1);
		cin >> imsi;
		for (j = 1; j <= m; j++) {
			arr[i][j] = (imsi[j - 1] - 48 == 1 ? true : false);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			check[i][j] = MAXVAL;
		}
	}

	check[1][1] = 0;

	queue<man> Q;

	Q.push({ 1,1,0 });

	while (!Q.empty()) {
		man coor = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++) {
			int mx = coor.x + mvx[i];
			int my = coor.y + mvy[i];
			int wbc = coor.wallbreakcnt;
			if (mx > n || mx < 1 || my > m || my < 1) continue;
			if (check[mx][my] <= wbc + (arr[mx][my] ? 1 : 0)) continue;
			check[mx][my] = wbc + (arr[mx][my] ? 1 : 0);
			Q.push({ mx, my, wbc + (arr[mx][my] ? 1 : 0) });
		}
	}

	cout << check[n][m];

	return 0;
}
