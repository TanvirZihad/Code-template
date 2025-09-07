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
int mx[N][20];
int logt[N];
void buildmx( int n,vector<int>&a)
{
    
    for (int i = 0; i < n; i++)
        mx[i][0] = a[i];
 

    for (int j = 1; (1 << j) <= n; j++) {
 
       
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            if (mx[i][j - 1] > mx[i + (1 << (j - 1))][j - 1])
                mx[i][j] = mx[i][j - 1];
            else
          mx[i][j] = mx[i + (1 << (j - 1))][j - 1];
        }
    }
}
int querymx(int l, int r)
{
    int j = logt[r-l+1];
 
    if (mx[l][j] >= mx[r - (1 << j) + 1][j])
        return mx[l][j];
 
    else
        return mx[r - (1 << j) + 1][j];
}
void calc_log(){
    logt[1]=0;
    for(int i=2;i<=N;i++){
        logt[i]=logt[i/2]+1;
    }
}