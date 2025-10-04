#include<bits/stdc++.h>
using namespace std;

struct Line {
    long long m, c; // slope and intercept
    long long eval(long long x) const { return m * x + c; }
};

struct CHT {
    deque<Line> hull;

    // Check if middle line B is useless between A and C
    bool bad(const Line &A, const Line &B, const Line &C) {
        // cross multiplication to avoid floating point
        //can also use 1.0L instead of __int128
        return 1.0L*(A.c - C.c) * (B.m - A.m) <= 1.0L*(A.c - B.c) * (C.m - A.m);
    }

    // Add a new line to the hull
    void addLine(long long m, long long c) {
        Line L = {m, c};

        // Handle equal slope: keep only the better line
        while (!hull.empty() && hull.back().m == L.m) {
            if (hull.back().c <= L.c) return; // new line worse → discard
            else hull.pop_back();             // new line better → remove old
        }

        // Remove useless lines
        while (hull.size() >= 2 && bad(hull[hull.size()-2], hull.back(), L))
            hull.pop_back();

        hull.push_back(L);
    }

    // Query for x assuming queries are monotone increasing
    long long queryMono(long long x) {
        while (hull.size() >= 2 && hull[0].eval(x) >= hull[1].eval(x))
            hull.pop_front(); // pop front
        return hull[0].eval(x);
    }

    // Query for x with arbitrary order (binary search)
    long long query(long long x) {
        int l = 0, r = (int)hull.size() - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (hull[mid].eval(x) <= hull[mid + 1].eval(x)) r = mid;
            else l = mid;
        }
        return min(hull[l].eval(x), hull[r].eval(x));
    }
};