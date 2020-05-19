#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;
int n;
vector<int> arr;
vector<vector<int>> dp;

int is_phalindrom(int s, int e) {
    if (s == e) return 1;
    int tsize = e - s + 1;
    for (int i = 0; i < tsize; i++) {
        if (dp[s + i][e - i] == 1) return 1;
        if (arr[s + i] != arr[e - i]) return 0;
    }
    return 1;
}

int main()
{
    scanf("%d", &n);
    arr.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i].assign(n + 1, -1);
        scanf("%d", &arr[i]);
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int ret = is_phalindrom(x, y);
        dp[x][y] = ret;
        printf("%d\n", ret);
    }

    return 0;

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            int ret = is_phalindrom(j, i);
            dp[i][j] = ret;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;*/
}