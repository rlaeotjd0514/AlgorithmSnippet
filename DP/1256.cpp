#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;
int n, m;
unsigned long long k;
vector<string> arr[101][101];
unsigned long long st[101][101];

vector<string> r(int x, int y, unsigned long long s) {
    int xy = x + y;
    if (arr[x][y].size() != 0) return arr[x][y];
    if (x == 1) {
        vector<string> ret;
        string p(xy, '0');
        ret.assign(xy, p);
        int rs = ret.size();
        for (int i = 0; i < rs; i++) {
            ret[i][rs - i - 1] = '1';
        }
        return arr[x][y] = ret;
    }
    if (y == 1) {
        vector<string> ret;
        string p(xy, '1');
        ret.assign(xy, p);
        int rs = ret.size();
        for (int i = 0; i < rs; i++) {
            ret[i][i] = '0';
        }
        return arr[x][y] = ret;
    }
    unsigned long long standard = st[x - 1][y];
    vector<string> bs1;
    vector<string> bs2;
    vector<string> ret;
    if (standard <= s) {
        bs1 = r(x - 1, y, s - standard);
        int bc1 = bs1.size();
        for (int i = 0; i < bc1; i++) {
            arr[x][y].push_back("1" + bs1[i]);
        }
    }
    else {
        bs2 = r(x, y - 1, s);
        int bc2 = bs2.size();
        for (int i = 0; i < bc2; i++) {
            arr[x][y].push_back("0" + bs2[i]);
        }
    }
    return arr[x][y];
}


int main()
{
    cin >> m >> n >> k;
    vector<string> ret;
    for (int i = 1; i <= n; i++) {
        st[i][1] = i + 1;
    }
    for (int i = 1; i <= m; i++) {
        st[1][i] = i + 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            st[i][j] = st[i - 1][j] + st[i][j - 1];
        }
    }
    if (k > st[n][m]) {
        cout << -1;
        return 0;
    }
    ret = r(n, m, k);
    int rs = ret.size();
    for (char c : ret[k % rs]) {
        cout << (c == '0' ? 'a' : 'z');
    }
    return 0;
}
