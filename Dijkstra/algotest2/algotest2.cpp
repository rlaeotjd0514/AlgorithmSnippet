#include "pch.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

//완전 그래프 기준으로  
//간선 많을 때 : 인행
//간선 적을 때 : 인리 

using namespace std;

int vis[20001];
int cost[20001];

const int MaxVal = 11;

vector< vector< pair<int, int> > > arr;

int main() {
	int i, j, k;
	int n, m;
	int s;
	int a, b, c;
	cin >> n >> m;
	cin >> s;
	arr.reserve(n + 1);
	arr.resize(n + 1);
		
	for (i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		int prev = arr[a].size();		
		arr[a].push_back({ b, c });
	}

	for (i = 1; i <= n; i++) {
		cost[i] = MaxVal;
	}

	cost[s] = 0;
	
	int mp, mn;

	for (i = 1; i < n; i++) {
		mn = MaxVal;
		for (j = 1; j <= n; j++) {
			if (vis[j] == 0 && mn > cost[j]) {
				mn = cost[j];
				mp = j;
			}
		}

		vis[mp] = 1;
		
		for (j = 1; j <= n; j++) {
			int move_value = -1;
			/*for_each(arr[mp].begin(), arr[mp].end(), [&move_value, j](pair<int, int> & n) {
				if (n.first == j) move_value = n.second;
				});*/
			for (k = 0; k < arr[mp].size(); k++) {
				if (arr[mp][k].first == j) {
					move_value = arr[mp][k].second;
					break;
				}
			}
			if (move_value > 0 && cost[j] > mn + move_value) {
				cost[j] = mn + move_value;
			}
		}		
	}	

	for (i = 1; i <= n; i++) {
		if (cost[i] == MaxVal) {
			cout << "INF\n";
		}
		else {
			cout << cost[i] << "\n";
		}
	}

	return 0;
}

