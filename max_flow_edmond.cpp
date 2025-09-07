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
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int cap[501][501];
vector<int>adj[501];
int par[501];
int bfs(int n,int des){
  vector<int>vis(501,0);
  vis[n]=1;
  queue<int>q;
  q.push(n);
  int ans=1e18;
  while(q.size()){
    int u=q.front();
    q.pop();
    for(auto x:adj[u]){
      
      if(!vis[x]&&cap[u][x]){
        par[x]=u;
        vis[x]=1;
        ans=min(ans,cap[u][x]);
        if(x==des){
          return ans;
        }
        q.push(x);
      }
      
    }
  }
  return 0;
}
void solve(){
     int n,m;
     cin>>n>>m;
     for(int i=0;i<m;i++){
      int u,v,c;
      cin>>u>>v>>c;
      adj[u].pb(v);
      adj[v].pb(u);
      cap[u][v]+=c;
     }
     int ans=0;
     int cnt=0;
     while(cnt=bfs(1,n)){
         int f=n;
         while(f!=1){
          cap[par[f]][f]-=cnt;
          cap[f][par[f]]+=cnt;
          f=par[f];
         }
         ans+=cnt;
     }
     cout<<ans<<endl;
 
 }
 
signed main()
{
  noob int t = 1;
  //cin >> t;
  
  int cs = 1;
  while (t--)
  {
    solve();
  }
 
  return 0;
}