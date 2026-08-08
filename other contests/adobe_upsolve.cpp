#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353


//Problem Statement
/*John is working as a spy in an enemy’s territory. He recently got an input about an enemy’s attack on his country.
To warn his army, he would send a secret code of string S which contains digits from 0 to 9 and an integer X.
You received that string S and need to decode it to get the desired information.

To decode string S, you need to replace each and every digit i of the string by i + 1, and you should repeat this process exactly X times.

For example:
If S = 94 and X = 1, after decoding the string will become 105.

You need to find out the length of the decoded string.

Input Format
First line of input contains an integer T which is the number of the test cases.

Next T lines of input contain two space-separated entities:

String S (coded string)

Integer X (number of times operation should be applied to get decoded string).

Output Format
Each test case output contains an integer which is the length of the decoded string.
If the length is large, print the length modulo 998244353.

Constraints
1 ≤ T ≤ 10^5
1 ≤ |S| ≤ 9
1 ≤ X ≤ 10^5

//input       
3
98 1
99878 10
99876210885432109997234610999982301766483087683001664759081725638464563829109874626 30
// Output
3
12
799

//brute force approach
#include <bits/stdc++.h>
using namespace std;


int main(){
    cout << "Adobe Upsolve" << endl;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int x;
        cin>>x;
        int n=s.size();
        vector<int> v;
        
        for(int j=0;j<x;j++){
        string res="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int digit=ch-'0';
            digit++;
            res+=to_string(digit);
            
        }
        s=res;
    }
    int ans=s.size();
    cout << ans << endl;

    }
}  
    Time Complexity:
Worst case: Exponential growth in string size.

After each iteration, the string could grow like:

makefile
Copy
Edit
Length: L → ~2L (if most digits are 9)
So, total time = O(L * 2^x) in the absolute worst case.

If x = 30 and L = 80, your string could theoretically grow to billions of digits, although it stabilizes before that due to digits rolling over.

❌ Space Complexity:
You’re storing the entire string each time.

Worst-case space = same as the final string length → O(2^x * L).

⚠️ Bottom line: This approach will TLE or OOM (Out Of Memory) for big x or big initial strings.
*/
//dp approach

/*int main() {
    cout << "Adobe Upsolve" << endl;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int x;
        cin >> x;

        vector<long long> dp(x + 5, 0);  // Precompute new digits from each step
        for (int i = 0; i <= x; ++i) dp[i] = 1;

        for (int i = x; i >= 0; --i) {
            if (i + 1 <= x) dp[i] = (dp[i] + dp[i + 1]) % MOD;
            if (i + 2 <= x) dp[i] = (dp[i] + dp[i + 2]) % MOD;
        }

        long long ans = 0;
        for (char ch : s) {
            int digit = ch - '0';
            if (digit + x <= 9)
                ans = (ans + 1) % MOD;
            else
                ans = (ans + dp[digit + x - 9]) % MOD;
        }

        cout << ans % MOD << endl;
    }
}*/
/*
 DP Approach Time Complexity
Part	Complexity
Build the DP array for x operations	O(x)
Loop over each digit of the input string	O(N)
For each digit, apply precomputed results	O(1) per digit

➤ Total:
O(N + x)

🧠 DP Approach Space Complexity
Part	Space
DP array to store up to x steps	O(x)
Other variables (negligible)	O(1)
*/
int main(){
    cout << "Adobe Upsolve" << endl;
   bool flag=true;
    while(flag){
        string s;
        cin >> s;
        int x;
        cin>>x;
        int n=s.size();
        vector<int> v;
        
        for(int j=0;j<x;j++){
        string res="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int digit=ch-'0';
            digit++;
            res+=to_string(digit);


            
        }
        s=res;
        cout << "After iteration " << j + 1 << ": " << s << endl; // Debugging output
    }
    int ans=s.size();
    cout << ans << endl;
    cout << "do you want to end program? (yes/no): ";
    string response;
    cin >> response;
    if (response == "yes") {
        flag = false;
    }
    }  
}