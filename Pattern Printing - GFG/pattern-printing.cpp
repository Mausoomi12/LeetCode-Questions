//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void printPattern(int N)
    {
        // Write Your Code here
        if(N<=0){
            return;
        }
        printPattern(N - 1);  // Recursive call to print stars for N-1
        for (int i = 0; i < N; i++) {
        cout << "*";
        }
        cout<<" ";
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.printPattern(N);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends