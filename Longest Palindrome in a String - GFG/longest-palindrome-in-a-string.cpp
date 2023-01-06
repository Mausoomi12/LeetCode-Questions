//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n = S.length();
    if (n == 0) return "";
    string longest = S.substr(0, 1);  // a single character is always a palindrome
    for (int i = 0; i < n - 1; i++)
    {
        string p1 = expandAroundCenter(S, i, i);
        if (p1.length() > longest.length()) longest = p1;
        string p2 = expandAroundCenter(S, i, i + 1);
        if (p2.length() > longest.length()) longest = p2;
    }
    return longest;
}

string expandAroundCenter(string S, int c1, int c2)
{
    int l = c1, r = c2;
    int n = S.length();
    while (l >= 0 && r <= n - 1 && S[l] == S[r])
    {
        l--;
        r++;
    }
    return S.substr(l + 1, r - l - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends