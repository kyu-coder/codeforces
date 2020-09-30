//https://codeforces.com/problemset/problem/363/C

#include<bits/stdc++.h>
using namespace std;

int main()
{
	// get rid of 3 consecutives -> only 1, 2 consec. left
	string s, str;
	cin >> s;

	int count = 0;
	char lastletter = s[0];
	
	if(s[1] == '\0')
	{
		cout << s;
		return 0;
	}

	for (int i = 0 ; s[i] != '\0' ; i++)
	{
		if (s[i] == lastletter && i != 0)
		{
			count++;
			if (count < 2)
			{
				str += s[i];
			}
		}
		else
		{
			lastletter = s[i];
			str += s[i];
			count = 0;
		}
	}

	if (str[1] == '\0' || str[2] == '\0' || str[3] == '\0')
	{
		cout << str;
		return 0;
	}

	for (int i = 2; str[i] != '\0' ; i++)
	{
		if (str[i-1] == str[i-2] && str[i] == str[i+1])
		{
			str[i] = 'R'; // 'R'emove
		}
	}

	for (int i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] != 'R')
		{
			cout << str[i];
		}
	}
}

