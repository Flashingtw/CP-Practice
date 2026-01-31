#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<char>> w;
int hx, hy;
int cx, cy;
int m, n;

bool isValid(int r, int c) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

void cursor() {
    char s;
    cin >> s;
    if (s == 'U') cx = max(cx - 1, 0);
    if (s == 'D') cx = min(cx + 1, m - 1);
    if (s == 'L') cy = max(cy - 1, 0);
    if (s == 'R') cy = min(cy + 1, n - 1);
}

void player() {
    char s;
    cin >> s;
    int tx = hx, ty = hy;
    if (s == 'W') tx--;
    if (s == 'S') tx++;
    if (s == 'A') ty--;
    if (s == 'D') ty++;

    if (isValid(tx, ty) && isValid(tx + 1, ty)) {
        w[hx][hy] = '.';
        w[hx + 1][hy] = '.';
        if (w[tx][ty] == '.' && w[tx + 1][ty] == '.') {
            hx = tx;
            hy = ty;
        }
        w[hx][hy] = '*';
        w[hx + 1][hy] = '#';
    }
}

bool checkLook() {
    int dist_dx = abs(cx - hx);
    int dist_dy = abs(cy - hy);
    if (dist_dx * dist_dx + dist_dy * dist_dy > 25) return false;

    int x0 = hx, y0 = hy;
    int x1 = cx, y1 = cy;
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        if ((x0 != hx || y0 != hy) && (x0 != cx || y0 != cy)) {
            if (w[x0][y0] != '.' && w[x0][y0] != '*' && w[x0][y0] != '#') {
                return false;
            }
        }

        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
    return true;
}

bool checkBlock() {
    if (w[cx][cy] != '.') return false;
    if ((cx == hx && cy == hy) || (cx == hx + 1 && cy == hy)) return false;
    if (cx + 1 < m && w[cx + 1][cy] != '.') return true;
    if (cy + 1 < n && w[cx][cy + 1] != '.') return true;
    if (cx - 1 >= 0 && w[cx - 1][cy] != '.') return true;
    if (cy - 1 >= 0 && w[cx][cy - 1] != '.') return true;

    return false;
}

void mine() {
    if (w[cx][cy] != '.' && w[cx][cy] != '*' && w[cx][cy] != '#') {
        if (checkLook()) {
            w[cx][cy] = '.';
        }
    }
}

void place(char c) {
    if (checkLook() && checkBlock()) {
        w[cx][cy] = c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> m >> n >> q)) return 0;

    w.resize(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
            if (w[i][j] == '*') {
                hx = i;
                hy = j;
            }
        }
    }
    if (hx + 1 < m) w[hx + 1][hy] = '#';

    cx = hx;
    cy = hy;
    char currentBlock = 'A';

    for (int i = 0; i < q; i++) {
        string in;
        cin >> in;
        if (in == "Cursor") cursor();
        else if (in == "Player") player();
        else if (in == "Switch") cin >> currentBlock;
        else if (in == "Place") place(currentBlock);
        else if (in == "Mine") mine();
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << w[i][j];
        }
        cout << "\n";
    }
    return 0;
}