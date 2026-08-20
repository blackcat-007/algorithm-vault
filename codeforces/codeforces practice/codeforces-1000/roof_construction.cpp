#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long n;
		cin >> n; // Read the number of pillars
		n--; // Decrement n to work with zero-based index
		long long msb = log2(n); // Find the most significant bit position of n
		vector<long long> ans; // Vector to store the sequence of pillar heights
		long long num = pow(2, msb) - 1; // Calculate the largest number with all bits set below msb
		while (num >= 0) // Fill the vector with numbers from num to 0
		{
			ans.push_back(num);
			num--;
		}
		num = pow(2, msb); // Start from the next power of 2
		while (num <= n) // Fill the vector with numbers from num to n
		{
			ans.push_back(num);
			num++;
		}

		for (auto it : ans) // Output the sequence of pillar heights
			cout << it << " ";
		cout << endl;
	}
}

// Time Complexity (TC): O(n) = O(2*10^5)
// Space Complexity (SC): O(n) = O(2*10^5)
