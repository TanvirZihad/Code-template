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
#define noob  ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//big mod
int big(int n, int p, int mod)
{
   if (p == 0)
      return 1;
   int k = big(n, p / 2, mod);
   int z = (k % mod * k % mod) % mod;
   if (p & 1)
   {
      return (n % mod * z % mod) % mod;
   }
   else
      return z;
}
//sqauare root of a number
int sq(unsigned int n)
{
   int lo = 0, hi = 2e9, ans;
   while (lo <= hi)
   {
      int m = (lo + hi) >> 1;
      if (m * m == n)
         return m;
      if (m * m < n)
      {
         lo = m + 1;
         ans = m;
      }
      else
         hi = m - 1;
   }
   return ans;
}
// binary representation of a number
vector<int>bin(int a){
   vector<int>t(63,0);
   for(int i=62;i>=0;i--){
      if((a>>i)&1)t[i]=1;
   }
   return t;
}