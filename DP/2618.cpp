#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct c {
	int x, y;
};

int rg(c c1, c c2) {
	return abs(c1.x - c2.x) + abs(c1.y - c2.y);
}

int n, w;
vector<vector<int>> dp;
vector<c> arr;

int case_engage(int x, int y) {
 	if (x >= w + 1 || y >= w + 1) return 0;//all case closed
	int nc = x > y ? x : y;
	nc += 1;//next case

	//memo::�̹� �� �������� ���� x, y��° ����� �湮 ������ �ִٸ� �ּڰ��� ���ŵȰ���
	if (dp[x][y] > -1) return dp[x][y];
	/*dp[x][y] = dp[x][y] < dp[nc][y] + rg(arr[nc], arr[x]) ? dp[x][y] : dp[nc][y] + rg(arr[nc], arr[x]);
	dp[x][y] = dp[x][y] < dp[x][nc] + rg(arr[nc], arr[y]) ? dp[x][y] : dp[x][nc] + rg(arr[nc], arr[y]);*/
	//�ּڰ� ����
	int nx = case_engage(nc, y) + rg(arr[nc], arr[x]); //���� ��Ǳ����� �Ÿ� + ���� ��ǿ����� �ּڰ�
	int ny = case_engage(x, nc) + rg(arr[nc], arr[y]);		

	return dp[x][y] = nx < ny ? nx : ny;
}

void case_track(int x, int y) {
	if (x >= w + 1 || y >= w + 1) return;//all case closed
	int nc = x > y ? x : y;
	nc += 1;//next case	
	int nx = rg(arr[nc], arr[x]); //���� ��Ǳ����� �Ÿ� + ���� ��ǿ����� �ּڰ�
	int ny = rg(arr[nc], arr[y]);

	if (dp[nc][y] + nx < dp[x][nc] + ny) {
		cout << 1 << "\n";
		case_track(nc, y);
	}
	else {
		cout << 2 << "\n";
		case_track(x, nc);
	}
	return;
}

int main() {
	cin >> n >> w;
	arr.resize(w + 2);
	dp.resize(w + 2);	
	arr[0] = { 1, 1 };
	arr[1] = { n, n };
	dp[0].resize(w + 2);
	dp[1].resize(w + 2);
	for (int i = 2; i <= w + 1; i++) {
		cin >> arr[i].x >> arr[i].y;
		dp[i].resize(w + 2);
	}

	for (int i = 0; i <= w + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			dp[i][j] = -1;
		}
	}

	//0, 1������ ������ ������ �⵿���� ����ְ� �����Ƿ� ��� ��ȣ�� 0~w+1������.
	cout << case_engage(0, 1) << endl;
	/*for (int i = 0; i <= w + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	case_track(0, 1);
	return 0;
}