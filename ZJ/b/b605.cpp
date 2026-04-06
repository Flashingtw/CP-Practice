#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f, g;
    for (;;) {
        cin >> a;
        if (a == -1) break;
        cin >> b >> c >> d >> e >> f >> g;

        long long l = 0, r = 1000000;
        int ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;
            long long c1 = a, c2 = b, c4 = c, c8 = d, c16 = e, c32 = f, c64 = g;
            long long s = mid;

            auto fill = [&](long long size, long long &count, long long side) {
                long long can_fit = (size / side) * (size / side);
                long long take = min(count, can_fit);
                count -= take;
            };

            long long r64 = (s / 64) * (s / 64);
            long long u64 = min(c64, r64);
            c64 -= u64;

            long long r32 = (s / 32) * (s / 32) - (u64 * 4);
            long long u32 = min(c32, r32);
            c32 -= u32;

            long long r16 = (s / 16) * (s / 16) - (u64 * 16 + u32 * 4);
            long long u16 = min(c16, r16);
            c16 -= u16;

            long long r8 = (s / 8) * (s / 8) - (u64 * 64 + u32 * 16 + u16 * 4);
            long long u8 = min(c8, r8);
            c8 -= u8;

            long long r4 = (s / 4) * (s / 4) - (u64 * 256 + u32 * 64 + u16 * 16 + u8 * 4);
            long long u4 = min(c4, r4);
            c4 -= u4;

            long long r2 = (s / 2) * (s / 2) - (u64 * 1024 + u32 * 256 + u16 * 64 + u8 * 16 + u4 * 4);
            long long u2 = min(c2, r2);
            c2 -= u2;

            long long r1 = (s * s) - (u64 * 4096 + u32 * 1024 + u16 * 256 + u8 * 64 + u4 * 16 + u2 * 4);
            long long u1 = min(c1, r1);
            c1 -= u1;

            if (c1 == 0 && c2 == 0 && c4 == 0 && c8 == 0 && c16 == 0 && c32 == 0 && c64 == 0) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }
}