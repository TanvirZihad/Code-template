#include <iostream>
#include <vector>

using namespace std;
vector<int>v;
// Function to generate all permutations using backtracking
void generatePermutations(vector<int>& nums, vector<bool>& used, vector<int>& current, int n) {
    // Base case: if current permutation has n elements, print it
    if (current.size() == n) {
        int ct=0;
       for(int i=0;i<n;i++){
        int mn=1e9;
        for(int j=i;j<n;j++){
            mn=min(mn,current[j]);
            ct+=mn;
        }
       }
       v.push_back(ct);
    }

    // Try each number from 1 to n if not already used
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;          // Mark the number as used
            current.push_back(i);    // Add it to the current permutation

            generatePermutations(nums, used, current, n); // Recurse

            // Backtrack
            used[i] = false;
            current.pop_back();
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> nums(n);
    vector<bool> used(n + 1, false); // To track used numbers (1 to n)
    vector<int> current;             // Current permutation

    cout << "All permutations of length " << n << " are:\n";
    generatePermutations(nums, used, current, n);
    int mx=0;
     for(int i=0;i<v.size();i++)mx=max(mx,v[i]);
     int ct=0;
     for(auto x:v)if(x==mx)ct++;
     cout<<ct<<endl;

    return 0;
}
