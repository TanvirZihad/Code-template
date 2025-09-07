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
int n,q;
int a[30002];
int freq[1000002];
int blk[1002];
int blk_size;
int freq_blk=1001;
struct query
{
  int l,r,idx;
};
bool comp(query &q1,query &q2){
  int a=q1.l/blk_size;
  int b=q2.l/blk_size;
  if(a!=b)return a<b;
  return (a&1)? q1.r>q2.r: q1.r<q2.r;
}
void add(int ind){
  int b=a[ind]/freq_blk;
  freq[a[ind]]++;
 if(freq[a[ind]]==1) blk[b]++;
}
void remove(int ind){
  int b=a[ind]/freq_blk;
  freq[a[ind]]--;
 if(freq[a[ind]]==0) blk[b]--;
}
int queryans(){
  int ans=0;
  for(int i=0;i<1002;i++)ans+=blk[i];
  return ans;
}
void solve(){
  
   cin>>n;
   blk_size=sqrt(n)+1;
   for(int i=0;i<n;i++)cin>>a[i];
   int q;
   cin>>q;
   query qr[q];
   for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--,r--;
    qr[i]={l,r,i};
   }
   sort(qr,qr+q,comp);
   int ans[q];
   int cur_l=0,cur_r=-1;
    for(int i=0;i<q;i++){
     int l=qr[i].l,r=qr[i].r;
    while(cur_r<r){
      add(++cur_r);
    }
    while(cur_l>l){
      add(--cur_l);
    }
    while(cur_r>r){
      remove(cur_r--);
    }
    while(cur_l<l){
      remove(cur_l++);
    }
    ans[qr[i].idx]=queryans();

    }
   for(int i=0;i<q;i++)cout<<ans[i]<<endl;
   


}
 
signed main()
{
   noob 
   int t=1,cs=1;
 //  cin>>t;

   while(t--){
  //  cout<<"Case "<<cs++<<": ";
     solve();
   }

   return 0;
}