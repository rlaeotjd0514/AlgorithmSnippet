#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int x, y, z;
    int px = 0, py = 0, pz = 0;
    int spx = 0, spy = 0, spz = 0;
    cin >> n;
    int xx = 0, xy = 0, xz = 0;
    int nx = 0, ny = 0, nz = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;
        xx = x + (px > py ? px : py);
        xy = y + max({ px, py, pz });
        xz = z + (py > pz ? py : pz);
        px = xx;
        py = xy;
        pz = xz;

        nx = x + (spx < spy ? spx : spy);
        ny = y + min({ spx, spy, spz });
        nz = z + (spy < spz ? spy : spz);
        spx = nx;
        spy = ny;
        spz = nz;
    }
    int mx = max({ px, py, pz });
    int mn = min({ spx, spy, spz });
    cout << mx << " " << mn;
    return 0;
}
