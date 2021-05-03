/* C++ Program to check whether valid 
expression is redundant or not*/
#include <bits/stdc++.h> 
using namespace std; 
bool checkRedundancy(string& str) 
{ 
	// create a stack of characters 
	stack<char> st; 

	// Iterate through the given expression 
	for (auto& ch : str) { 

		// if current character is close parenthesis ')' 
		if (ch == ')') { 
			char top = st.top(); 
			st.pop(); 

			// If immediate pop have open parenthesis '(' 
			// duplicate brackets found 
			bool flag = true; 

			while (top != '(') { 

				// Check for operators in expression 
					flag = false; 

				// Fetch top element of stack 
				if(!st.empty())
				{	top = st.top(); 
				    st.pop(); 
				}
			} 

			// If operators not found 
			if (flag == true) 
				return true; 
		} 

		else
			st.push(ch); // push open parenthesis '(', 
				// operators and operands to stack 
	} 
	return false; 
} 

// Function to check redundant brackets 
void findRedundant(string& str) 
{ 
	bool ans = checkRedundancy(str); 
	if (ans == true) 
		cout << "Duplicate\n"; 
	else
		cout << "Not Duplicates\n"; 
} 

// Driver code 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		findRedundant(str);
	}

	return 0; 
} 
