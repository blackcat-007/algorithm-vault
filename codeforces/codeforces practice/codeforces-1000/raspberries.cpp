#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        long long n,k;
        cin >> n >> k;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        int mn=INT_MAX;
        bool pos=false;
        //case k is not 4
        if(k!=4){
            for(int i=0;i<n;i++){
                if(a[i]%k==0){
                    cout<<0<<"\n";
                    pos=true;
                    break;
                }
                else{
                    int diff = k - (a[i] % k);
                    if(diff<mn)
                        mn=diff;
                }
            }
            if(mn!=INT_MAX && !pos)
                cout<<mn<<"\n";
        }
        else{
            //case k is 4
            k=2;
            int count=0;
           bool pos=false;
           int mini=INT_MAX;
            for(int i=0;i<n;i++){
                if(count>=2){
                    cout<<0<<"\n";
                    pos=true;
                    break;
                }
                if(a[i]%k==0){
                    //cout<<0<<"\n";
                    if(a[i]%4==0){
                        cout<<0<<"\n";
                        pos=true;
                        break;
                    }
                    count++;
                }
                
                int diff = 4 - (a[i] % 4);
                if(diff<mini)
                        mini=diff;
                
                
                
            }
                if(!pos)
                cout<<std::min(2-count,mini)<<"\n";
        }
        
    }
    return 0;
}
/*
cleaner solution 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long n, k;
		cin >> n >> k; // Read the size of the array and the divisor k
		vector<long long> a(n);
		for (long long i = 0; i < n; i++) // Read the array elements
			cin >> a[i];

		long long ans = INT_MAX; // Initialize the minimum operations to a large value
		long long even_count = 0; // Count of even numbers in the array
		for (long long i = 0; i < n; i++)
		{
			if (a[i] % 2 == 0)
				even_count++; // Increment even_count if the element is even
			if (a[i] % k == 0)
				ans = 0; // If any element is divisible by k, no operations are needed
			ans = min(ans, (k - a[i] % k)); // Calculate the minimum operations needed
		}

		// Special handling for k = 4
		if (k == 4)
		{
			if (even_count >= 2)
				ans = min(ans, 0LL); // If there are at least two even numbers, no operations are needed
			else if (even_count == 1)
				ans = min(ans, 1LL); // If there is one even number, one operation is needed
			else if (even_count == 0)
				ans = min(ans, 2LL); // If there are no even numbers, two operations are needed
		}
		cout << ans << endl; // Output the minimum number of operations
	}
	return 0;
}

// Time Complexity (TC): O(n) = O(2*10^5)
// Space Complexity (SC): O(n) = O(2*10^5)
*/