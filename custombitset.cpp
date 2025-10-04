#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4.2")
#pragma GCC target("popcnt")
#define ff first
#define ss second
#define pb push_back
//#define int long long
#define noob         ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct MyBitset
{
    int n;              // number of bits
    vector<uint64_t> b; // blocks

    MyBitset(int _n = 0) { init(_n); }

    void init(int _n)
    {
        n = _n;
        b.assign((n + 63) / 64, 0);
    }

    void set(int pos)
    {
        b[pos >> 6] |= (1ULL << (pos & 63));
    }

    void reset(int pos)
    {
        int idx = pos >> 6;       // divide by 64 to find which block
        int bit = pos & 63;       // position inside that block
        b[idx] &= ~(1ULL << bit); // clear that bit
    }

    bool test(int pos) const
    {
        return (b[pos >> 6] >> (pos & 63)) & 1ULL;
    }

    void reset()
    {
        fill(b.begin(), b.end(), 0);
    }

    MyBitset operator~() const
    {
        MyBitset res(n);
        for (size_t i = 0; i < b.size(); i++)
            res.b[i] = ~b[i];
        // clear extra bits beyond n
        if (n % 64)
            res.b.back() &= (1ULL << (n % 64)) - 1;
        return res;
    }

    // in-place OR
    MyBitset &operator|=(const MyBitset &other)
    {
        for (size_t i = 0; i < b.size(); i++)
            b[i] |= other.b[i];
        return *this;
    }

    // binary OR -> returns new MyBitset
    MyBitset operator|(const MyBitset &other) const
    {
        MyBitset res(n);
        for (size_t i = 0; i < b.size(); i++)
            res.b[i] = b[i] | other.b[i];
        return res;
    }

    // bitwise AND
    MyBitset &operator&=(const MyBitset &other)
    {
        for (size_t i = 0; i < b.size(); i++)
            b[i] &= other.b[i];
        return *this;
    }

    MyBitset operator&(const MyBitset &other) const
    {
        MyBitset res(n);
        for (size_t i = 0; i < b.size(); i++)
            res.b[i] = b[i] & other.b[i];
        return res;
    }

    // XOR
    MyBitset &operator^=(const MyBitset &other)
    {
        for (size_t i = 0; i < b.size(); i++)
            b[i] ^= other.b[i];
        return *this;
    }

    MyBitset operator^(const MyBitset &other) const
    {
        MyBitset res(n);
        for (size_t i = 0; i < b.size(); i++)
            res.b[i] = b[i] ^ other.b[i];
        return res;
    }

    // count set bits
    int count() const
    {
        int ans = 0;
        for (auto x : b)
            ans += __builtin_popcountll(x);
        return ans;
    }
};

int main()
{
    int N = 50001;
    MyBitset bs1(N), bs2(N);
    // advantage->compile time N can be used

    bs1.set(1);
    bs1.set(1000);
    bs1.set(50000);

    bs2.set(1);
    bs2.set(2);

    bs1 |= bs2; // union

    cout << "Count = " << bs1.count() << "\n";        // should be 4
    cout << "Bit 50000? " << bs1.test(50000) << "\n"; // 1
    MyBitset bs3 = bs1 ^ bs2;
    cout << bs3.count() << endl;
    bs3=~bs3;
    cout<<bs3.count()<<endl;
}
