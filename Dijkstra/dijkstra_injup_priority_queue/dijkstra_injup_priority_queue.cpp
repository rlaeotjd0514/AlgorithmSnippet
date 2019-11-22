#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <vector>

//우선순위 큐 : 
using namespace std;

int cost[20001];

const int MaxVal = -1;

vector< vector< pair<int, int> > > arr;

//bool operator < (pair<int, int> a, pair<int, int> b) {
//	return a.first > b.first;
//}

int main() {
	int i, j, k;
	int n, m;
	int s;
	int a, b, c;
	cin >> n >> m;
	cin >> s;
	//arr.reserve(n + 1);
	arr.resize(n + 1);

	for (i = 1; i <= m; i++) {
		cin >> a >> b >> c;		
		arr[a].push_back({ b, c });
	}

	for (i = 1; i <= n; i++) {
		cost[i] = MaxVal;
	}	

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh;
	mh.push({ 0, s });	
	while (mh.size() > 0) {
		int current = mh.top().second;
		int val = mh.top().first;//val, current는 현재 힙에 들어있는 값중에서 간선 가치가 가장 작은 정점이다.
		mh.pop();
		if (cost[current] != MaxVal) continue;//이미 방문된 정점이면 건너 뜀(힙에 있는 값들을 오름차순으로 정렬해서 뱉기 때문에 늦게 사용된 간선은 이미 들어있는 값보다 작을 수 없음
		cost[current] = val;		
		for (auto it : arr[current]) {			
			if (cost[it.first] != MaxVal) continue;
			mh.push({ it.second + val, it.first });
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
