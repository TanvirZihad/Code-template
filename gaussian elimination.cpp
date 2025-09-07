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
void gaussian(vector<vector<int>>&v,vector<vector<int>>&t,int n){
   for(int i=0;i<n;i++){
      int j=i;
      while(j<n){
         if(v[j][i]>0)break;
         j++;
      }
      if(j==n)continue;
      swap(v[i],v[j]);
      swap(t[i],t[j]);
      for(int j=i+1;j<n;j++){
         if(v[j][i]==0)continue;
         for(int k=0;k<n;k++){
            v[j][k]+=v[i][k];
            v[j][k]%=2;
         }
         t[j][0]+=t[i][0];
         t[j][0]%=2;
      }
   }
   for(int i=n-1;i>=0;i--){
      int j=i;
      while(j>=0){
         if(v[j][i]>0)break;
         j--;
      }
      if(j<0)continue;
      swap(v[i],v[j]);
      swap(t[i],t[j]);
      for(int j=i-1;j>=0;j--){
         if(v[j][i]==0)continue;
         for(int k=n-1;k>=0;k--){
            v[j][k]+=v[i][k];
            v[j][k]%=2;
         }
         t[j][0]+=t[i][0];
         t[j][0]%=2;
      }
   }
   }