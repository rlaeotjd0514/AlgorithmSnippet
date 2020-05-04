#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> room;
vector<vector<int>> arr;
int v, e;

bool nf(int x) {//x 는 소번호
	for (int i = 1; i <= arr[x][0]; i++) {
		int current = arr[x][i];
		if (room[current] == 0 || nf(room[current])) {
			room[current] = x;
			return true;
		}		
	}
	return false;
}

int main() {
	cin >> v, e;
	arr.resize(v + 1);
	room.resize(e + 1);	
	for (int i = 1; i <= v; i++) {
		int a;
		cin >> a;
		arr[i].resize(a);
		arr[i][0] = a;
		for (int j = 1; j <= a; j++) {
			cin >> arr[i][j];
		}
	}

	int dc = 0;

	for (int i = 1; i <= v; i++) {
		nf(i);
	}
	for (int i = 1; i <= v; i++){
		if (room[i] != 0) dc++;
	}
	
	cout << dc << endl;

	return 0;
}