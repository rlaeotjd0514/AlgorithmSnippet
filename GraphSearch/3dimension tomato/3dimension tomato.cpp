// 3dimension tomato.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<vector<int>>> tomato_tower;

struct tomato {
	int z, x, y;
	int cnt = 0;
};

int mvz[6] = { 0,0,-1,0,0,1 };
int mvx[6] = { -1,0,0,1,0,0 };
int mvy[6] = { 0,-1,0,0,1,0 };

int main()
{
	int i, j, k;
	int n, m, h;
	queue<tomato> Q;
	cin >> m >> n >> h;
	tomato_tower.resize(h + 1);	
	for (k = 1; k <= h; k++) {
		tomato_tower[k].resize(n + 1);
		for (i = 1; i <= n; i++) {
			tomato_tower[k][i].resize(m + 1);
			for (j = 1; j <= m; j++) {
				cin >> tomato_tower[k][i][j];
				if (tomato_tower[k][i][j] == 1) {
					Q.push({ k, i, j, 0 });
				}
			}
		}
	}

	int d = 0;

	while (!Q.empty()) {
		tomato new_t = Q.front();
		Q.pop();
		for (i = 0; i < 6; i++) {
			int nz = new_t.z + mvz[i];
			int nx = new_t.x + mvx[i];
			int ny = new_t.y + mvy[i];
			int cnt = new_t.cnt + 1;
			if (nz >= 1 && nz <= h && nx >= 1 && nx <= n && ny >= 1 && ny <= m && tomato_tower[nz][nx][ny] == 0) {
				d = cnt;
				tomato_tower[nz][nx][ny] = cnt;
				Q.push({ nz, nx, ny, cnt });
			}
		}
	}
	
	for (k = 1; k <= h; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (tomato_tower[k][i][j] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}		
	}

	cout << d;

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
