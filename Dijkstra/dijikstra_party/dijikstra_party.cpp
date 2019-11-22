// dijikstra_party.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> way_to_party;
vector<vector<pair<int, int>>> way_to_home;
const int MAXVAL = -1;
int vis[1005];
int way_to_party_cost[1005];
int way_to_home_cost[1005];


int main()
{
	int n, m;
	int s;

	int i, j;
	int a, b, c;
	int max = -1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> arr;

	cin >> n >> m >> s;

	way_to_party.resize(m + 1);
	way_to_home.resize(m + 1);
	
	for (i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		way_to_party[b].push_back({ a, c });
		way_to_home[a].push_back({ b, c });
	}

	for (i = 1; i <= n; i++) {
		vis[i] = MAXVAL;
	}

	
	arr.push({ 0, s }); // 파티장 가는 길 : 인접 리스트 시작/도착 바꾸기
	
	while (arr.size()) {
		int val = arr.top().first;
		int current = arr.top().second;
		arr.pop();
		if (vis[current] != MAXVAL) continue;
		vis[current] = 1;
		way_to_party_cost[current] = val;
		//if (max < val) max = val;
		for (auto nx : way_to_party[current]) {
			if (vis[nx.first] != MAXVAL) continue;
			arr.push({ nx.second + val, nx.first });
		}
	}

	for (i = 1; i <= n; i++) {
		vis[i] = MAXVAL;
	}

	arr.push({ 0, s });	

	while (arr.size()) {
		int val = arr.top().first;
		int current = arr.top().second;
		arr.pop();
		if (vis[current] != MAXVAL) continue;
		vis[current] = 1;
		way_to_home_cost[current] = val;
		//if (max < val) max = val;
		for (auto nx : way_to_home[current]) {
			if (vis[nx.first] != MAXVAL) continue;
			arr.push({ nx.second + val, nx.first });
		}
	}

	int w;
	int wp, wh;

	for (i = 1; i <= n; i++) {
		if (max < way_to_home_cost[i] + way_to_party_cost[i]) {
			max = way_to_home_cost[i] + way_to_party_cost[i]; 
			w = i;
			wh = way_to_home_cost[i];
			wp = way_to_party_cost[i];
		}
	}

	cout << max << "\n";
	/*cout << wp << "\n";
	cout << wh << "\n";*/
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
