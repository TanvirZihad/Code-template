#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

const int N = 3e5 + 9;
const ll inf = -(1LL << 62);


/*

***This structure is written for maximum query,for minimum cht.add(-m,-c) should be called and ans=-query(x)
*/
struct line {
    ll m, b;
    mutable function<const line*()> succ;
    bool operator<(const line& rhs) const {
        if (rhs.b != inf) return m < rhs.m;
        const line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct CHT : public multiset<line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return 1.0 * (x->b - y->b) * (z->m - y->m) >= 1.0 * (y->b - z->b) * (y->m - x->m);
    }

    void add(ll m, ll b) {
        auto y = insert({m, b});
        y->succ = [=]() {
            auto it = next(y);
            return it == end() ? nullptr : &*it;
        };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }

    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound((line){x, inf});
        return l.m * x + l.b;
    }
};

CHT* cht;
ll a[N], b[N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    cht = new CHT();
    cht->add(-b[0], 0);

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans = -cht->query(a[i]);   //for min query
        cht->add(-b[i], -ans);     //for min query
    }
    cout << ans << nl;
    return 0;
}
