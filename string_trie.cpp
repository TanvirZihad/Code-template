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

struct Trienode
{
  Trienode *children[26];
  bool isend;
  int cntprefix,cntend;
  Trienode()
  {
    for (int i = 0; i < 26; i++)
      children[i] = NULL;
    isend = false;
    cntprefix=cntend=0;
  }
};

class Trie
{

  Trienode *root;

      bool isEmpty(Trienode* node) {
        for (int i = 0; i < 26; i++)
            if (node->children[i] != NULL)
                return false;
        return true;
    }

   
    Trienode* deleteWord(Trienode* node, string word, int depth) {
        if (!node) return NULL;

        // Base case: end of word
        if (depth == word.size()) {
            if (node->isend)
                node->isend = false;

            // If node has no children, free it
            if (isEmpty(node)) {
                delete node;
                node = NULL;
            }
            return node;
        }

        int index = word[depth] - 'a';
        node->children[index] = deleteWord(node->children[index], word, depth + 1);

  
        if (!node->isend && isEmpty(node)) {
            delete node;
            node = NULL;
        }
        return node;
    }

public:

  Trie(){
    root=new Trienode();
  }

  void insert(string &s){
    Trienode *cur=root;
    for(auto x:s){
      int id=x-'a';
      if(!cur->children[id]){
        cur->children[id]=new Trienode();
      }
      cur=cur->children[id];
      cur->cntprefix++;
    }
    cur->isend=true;
    cur->cntend++;
  }

  bool startswith(string &s){
    Trienode *cur=root;
    for(auto x:s){
      int id=x-'a';
      if(!cur->children[id])return false;
      cur=cur->children[id];
    }
    return true;
  }

  bool doeswordexist(string &s){
     Trienode *cur=root;
    for(auto x:s){
      int id=x-'a';
      if(!cur->children[id])return false;
      cur=cur->children[id];
    }
    return cur->isend;
  }

  int countprefix(string &s){

    Trienode *cur=root;
    for(auto x:s){
      int id=x-'a';
      if(!cur->children[id])return 0;
      cur=cur->children[id];
    }
    return cur->cntprefix;

  }


  int countword(string &s){

    Trienode *cur=root;
    for(auto x:s){
      int id=x-'a';
      if(!cur->children[id])return 0;
      cur=cur->children[id];
    }
    return cur->cntend;

  }

  void erase(string &s){
    root=deleteWord(root,s,0);
  }
};
