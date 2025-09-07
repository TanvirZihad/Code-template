// [ ﷽ ] Bismillahir Rahmanir Raheem//
#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#pragma GCC target("sse4.2")
#define ff first
#define ss second
#define pb push_back
#define int long long
#define noob               \
  ios::sync_with_stdio(0); \
  cin.tie(0);
 #define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int extended_gcd(int a,int b,int &p,int &q){
   int xx = q = 0;
  int yy = p = 1;
  while (b) {
    int d = a / b;
    int t = b; b = a % b; a = t;
    t = xx; xx = p - d * xx; p = t;
    t = yy; yy = q - d * yy; q = t;
  }
  return a;
}
pair<long long, long long> crt( vector<long long>& rem,  vector<long long>& mod) {
    assert(rem.size() == mod.size());
    long long x = rem[0];
    long long M = mod[0];

    for (size_t i = 1; i < rem.size(); ++i) {
        long long a = M;
        long long b = mod[i];
        long long c = (rem[i] - x % b + b) % b;
        long long x1, y1;
        long long g = extended_gcd(a, b, x1, y1);
        if (c % g != 0) {
            // No solution exists if gcd(a, b) doesn't divide c
            return {-1, -1};
        }

        // Solve a/g * x = c/g mod (b/g)
        long long b_g = b / g;
        x = (x + a * ((c / g * x1 % b_g + b_g) % b_g)) % (M * b_g);
        M = M * b_g;
    }

    return {x < 0 ? x + M : x, M};
}