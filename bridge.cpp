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
#define int long long
#define noob   ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=1e5+2;
vector<int>adj[N];
int n,m;
int low[N],disc[N];
int tme;
vector<pair<int,int>>bridge;
void dfs(int u,int p){
    low[u]=disc[u]=++tme;
    for(auto x:adj[u]){
        if(x==p)continue;
        if(!disc[x]){
            dfs(x,u);
            if(disc[u]<low[x])bridge.pb({u,x});
            low[u]=min(low[u],low[x]);
        }
        else{
            low[u]=min(low[u],disc[x]);
        }
    }
}
void solve()
{

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    tme=0;
    for(int i=1;i<=n;i++){
        if(disc[i])continue;
        dfs(i,-1);
    }

    cout<<bridge.size()<<endl;
    for(auto x:bridge)cout<<x.ff<<" "<<x.ss<<endl;

    
    


   
   
  
   
}
 
signed main()
{
  noob 
  int t = 1;
 
   // cin>>t;
  while (t--)
    solve();
}