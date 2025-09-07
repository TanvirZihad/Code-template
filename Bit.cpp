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

void update(int ind,int n,vector<int>&bit,int val){
    while(ind<=n){
        bit[ind]+=val;
        ind+=ind&(-ind);
    }
}
int res(int ind,vector<int>&bit){
    int ans=0;
    while(ind>0){
        ans+=bit[ind];
        ind-=ind&(-ind);
    }
    return ans;
}

//2D Bit
void update(int i,int j,int n,int m,vector<vector<int>>&bit,int val){
    while(i<=n){
        int y=j;
        while(y<=m){
            bit[i][y]+=val;
            y+=y&-y;
        }
        i+=i&-i;
    }
}
int res(int i,int j,vector<vector<int>>&bit){
    int ct=0;
    while(i>0){
        int y=j;
        while(y>0){
            ct+=bit[i][y];
            y-=y&-y;
        }
        i-=i&-i;
    }
    return ct;
}