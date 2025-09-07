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
 const int N=100002;
class Segment_tree{
private:

    int seg[4*N],lazy[4*N];
public:
//Build
void build(int node, int s, int e,vector<int>&v)
{
   if (s == e)
   {
      seg[node] = v[s];
      return;
   }
   int m = (s + e) >> 1;
    build(2*node+1,s,m,v);
    build(2*node+2,m+1,e,v);
   seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}


//Point Update
void update(int node, int s, int e, int pos,int val)
{
   if (s == e)
   {
      seg[node] = val;
      return;
   }
   int m = (s + e) >> 1;
   if (pos <= m)
      update(2 * node + 1, s, m, pos, val);
   else
      update(2 * node + 2, m + 1, e, pos,val);
   seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

// Range update

void updateRange(int node, int s, int e, int l,
                     int r, int val)
{
    if (lazy[node] != 0)
    {
      
        seg[node] += (e-s+1)*lazy[node];
 

        if (s != e)
        {

            lazy[node*2 + 1]   += lazy[node];
            lazy[node*2 + 2]   += lazy[node];
        }

        lazy[node] = 0;
    }
 

    if (s>e || s>r || e<l)
        return ;

    if (s>=l && e<=r)
    {

        seg[node] += (e-s+1)*val;

        if (s != e)
        {

            lazy[node*2 + 1]   += val;
            lazy[node*2 + 2]   += val;
        }
        return;
    }
    int mid = (s+e)/2;
    updateRange(node*2+1, s, mid, l, r, val);
    updateRange(node*2+2, mid+1, e, l, r, val);
seg[node] = seg[node*2+1] + seg[node*2+2];
}


// point query
int point_query(int node, int s, int e, int l, int r)
{
   if (s > r || e < l)
      return 0;
   if (s >= l && e <= r)
      return seg[node];
   int m = (s + e) >> 1;
   return point_query(2 * node + 1, s, m, l, r) + point_query(2 * node + 2, m + 1, e, l, r);
}

//Range query
int range_query(int node, int s, int e, int l, int r)
{
  if(lazy[node]!=0)  {
        seg[node] += (e-s+1)*lazy[node];
        if (s != e)
        {

            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (s>e || s>r || e<l)
        return 0;
    if (s>=l && e<=r)
        return seg[node];
    int m = (s + e)/2;
    return range_query(2*node+1, s, m, l, r) + range_query(2*node+2, m+1, e, l, r);
}
};