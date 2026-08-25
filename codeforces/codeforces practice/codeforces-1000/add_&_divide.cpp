#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t; // Read the number of test cases
	while (t--)
	{
		long long a, b;
		cin >> a >> b; // Read the values of a and b for each test case

		long long ans = INT_MAX; // Initialize the minimum operations to a large value
		for (int addition = 0; addition < 32; addition++) // Iterate over possible increments of b
		{
			long long operations = addition; // Start with the current increment as operations
			long long new_b = b + addition; // Calculate the new value of b
			if (new_b == 1) // If new_b is 1, skip this iteration as division by 1 is not useful
				continue;
			long long copy_a = a; // Make a copy of a to perform operations
			while (copy_a > 0) // Continue until a becomes 0
			{
				copy_a /= new_b; // Divide a by the current b
				operations++; // Count the division operation
			}
			ans = min(ans, operations); // Update the minimum operations
		}
		cout << ans << endl; // Output the minimum operations for this test case
	}
}

// Time Complexity (TC): O(log2(a)^2)
// Space Complexity (SC): O(1)
