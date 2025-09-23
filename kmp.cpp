/**
Knuth Morris Pratt String Matching
Complexity: build - O(n)
            match - O(n+m)
            prefix automaton - O(n*alphabet)

source: anachor, solaimanope (prefix automaton)
*/

#include <bits/stdc++.h>
using namespace std;

struct KMP
{
    string s;
    int n;
    vector<int> pi;

    KMP(const string &ss)
    {
        s = ss;
        n = s.size();
        pi.assign(n + 1, 0);

        pi[0] = pi[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            pi[i] = (s[i - 1] == s[0]);
            for (int j = pi[i - 1]; j > 0; j = pi[j])
                if (s[j] == s[i - 1])
                {
                    pi[i] = j + 1;
                    break;
                }
        }
    }

    int match(string t)
    { /// No of matches
        int cur = 0, ans = 0;
        for (int i = 0; i < t.size();)
        {
            if (t[i] == s[cur])
                cur++, i++;
            else if (cur == 0)
                i++;
            else
                cur = pi[cur];
            if (cur == n)
                ans++, cur = pi[cur];
        }
        return ans;
    }

    vector<vector<int>> prefixAutomaton()
    {
        vector<vector<int>> aut(n + 1, vector<int>(26, 0));
        s += '#';
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int c = 0; c < 26; c++)
            {
                int j = i;
                while (j > 0 && 'a' + c != s[j])
                    j = pi[j - 1];
                if ('a' + c == s[j])
                    j++;
                aut[i][c] = j;
            }
        }
        return aut;
    }
};

/// Solves LightOJ 1255 - substring frequency
/// Basically, given a text and a pattern find
/// how many times the pattern appears in text

const int N = 1e6 + 7;
char buffer[N];
int main()
{
    int t;
    scanf("%d", &t);

    for (int cs = 1; cs <= t; ++cs)
    {
        string a, b;
        scanf("%s", buffer);
        a = buffer;
        scanf("%s", buffer);
        b = buffer;
        KMP matcher(b);
        printf("Case %d: %d\n", cs, matcher.match(a));
    }
}



/*KMP and period for all substring

 int n=s.size();
    vector<vector<int>>pi(n+1,(vector<int>(n+1,0)));
    vector<vector<int>>period(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
       
      for(int j=i+1;j<=n;j++){

        pi[i][j]=(s[j-1]==s[i-1]);
        for(int k=pi[i][j-1];k>0;k=pi[i][k]){
          if(s[i+k-1]==s[j-1]){
            pi[i][j]=k+1;
            break;
          }
        }
       
        int l=j-i+1;
        int k=l-pi[i][j];
        if(l%k==0)period[i][j]=k;
        else period[i][j]=l;
      }
    }

*/