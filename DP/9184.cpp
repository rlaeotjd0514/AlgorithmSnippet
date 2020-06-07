#include <iostream>

using namespace std;

int dp[51][51][51];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (dp[a][b][c] != -9999) return dp[a][b][c];
    if (a > 20 || b > 20 || c > 20) return dp[a][b][c] = w(20, 20, 20);
    if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
    int a, b, c;
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            for (int k = 0; k < 51; k++) {
                dp[i][j][k] = -9999;
            }
        }
    }
    //memset(dp, -9999, 51 * 51 * 51);
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) return 0;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
    return 0;
}