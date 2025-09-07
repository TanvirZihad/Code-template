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
#define noob   ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int cnt[26][1502];
int a[200002];
int n,k;
void solve()
{
  string s;
  cin>>s;
  int n=s.size();
  for(int i=0;i<n;i++){
    cnt[s[i]-'a'][i+1]++;
  }
  for(int i=0;i<26;i++){
    for(int j=1;j<=n;j++)cnt[i][j]+=cnt[i][j-1];
  }
  vector<int>bad;
  string t;
  cin>>t;
  for(int i=0;i<26;i++){
    if(t[i]=='0')bad.pb(i);
  }
  int k;
  cin>>k;
  int power1[n+1],power2[n+1];
  int p1=31,p2=37,m1=127657753,m2=987654319;
  int hash1[n+1],hash2[n+1];
  hash1[0]=hash2[0]=0;
  power1[0]=power2[0]=1;
  for(int i=1;i<=n;i++){
     power1[i]=power1[i-1]*p1;
     power1[i]%=m1;
      power2[i]=power2[i-1]*p2;
     power2[i]%=m2;
  }
  for(int i=1;i<=n;i++){
   hash1[i]=(hash1[i-1]+(s[i-1]-'a'+1)*power1[i-1])%m1;
   hash2[i]=(hash2[i-1]+(s[i-1]-'a'+1)*power2[i-1])%m2;
  }
  vector<pair<int,int>>st;
   for(int l=1;l<=n;l++){
    for(int i=1;i+l-1<=n;i++){
      int r=0;
      for(int j=0;j<bad.size();j++){
         r+=cnt[bad[j]][i+l-1]-cnt[bad[j]][i-1];
      }
      if(r>k)continue;
      int h1=(hash1[i+l-1]-hash1[i-1]+m1)%m1;
      int h2=(hash2[i+l-1]-hash2[i-1]+m2)%m2;
      h1=(h1*power1[n-i])%m1;
      h2=(h2*power2[n-i])%m2;
      st.pb({h1,h2});
    }
   }
   sort(st.begin(),st.end());
   if(st.empty()){
      cout<<0<<endl;
      return;
   }
   int ans=1;
   for(int i=1;i<st.size();i++){
      if(st[i]!=st[i-1])ans++;
   }
   cout<<ans<<endl;

}

signed main()
{
  noob 
  int t = 1, cs = 1;
// cin>>t;
  while (t--)
  {
    //  cout<<"Case "<<cs++<<": ";
     solve();

  }

  return 0;
}