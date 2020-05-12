#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<vector<int>> arr;

int main()
{
    cin >> n >> m;
    arr.resize(n + 1);
    int zs = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        arr[i].resize(m + 1);
        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j - 1] - 48;
            zs += arr[i][j];
        }
    }

    int mx = 0;

    if (zs == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int di = n - i;
            int dj = m - j;
            int tc = di < dj ? di : dj;
            int sign = 0;
            if (tc <= mx || arr[i][j] == 0) continue;
            for (int t = 1; t <= tc; t++) {
                for (int k = i; k <= i + t; k++) {
                    if (arr[k][j + t] == 0) {
                        sign = 1;
                        break;
                    }
                }
                if (sign == 1) break;
                for (int k = j; k <= j + t; k++) {
                    if (arr[i + t][k] == 0) {
                        sign = 1;
                        break;
                    }
                }
                if (sign == 1) break;
                if (sign == 0) {
                    if (mx < t) mx = t;
                }
            }
        }
    }

    cout << (mx + 1) * (mx + 1);

    return 0;
}
