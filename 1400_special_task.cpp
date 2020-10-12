// https://codeforces.com/problemset/problem/316/A2#

#include<bits/stdc++.h>
using namespace std;

int AtoJ[10] = {0};

int lcount = 0; // count distinct letters
int qmcount = 0; // count ?s

int main()
{
	string s;
	cin >> s;

	for(int i = 0; s[i] != '\0'; i++)
	{
		// we can ignore numbers
		if (isalpha(s[i]))
		{
			AtoJ[s[i] - 65] = 1;
		}

		else if (s[i] == '?')
		{
			qmcount ++;
		}
	}

	for(int i = 0 ; i < 10 ; i++)
	{
		lcount += AtoJ[i];
	}

	int ans = 1;

	if (s[0] == '?')
	{
		ans = 9;
		qmcount--;
	}

	for(int i = 0; i < lcount; i++)
	{
		ans *= (10 - i);
	}

	// no leading 0; gives us 9 options
	if (isalpha(s[0]))
	{
		ans = ans / 10 * 9;
	}

	cout << ans;

	// print trailing 0's
	for(int i = 0 ; i < qmcount; i++)
	{
		cout << 0;
	}
	
}
