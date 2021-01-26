// https://codeforces.com/problemset/problem/1468/C

#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int q, spent[500001], i = 1, m = 1, max = 0;
	
	cin >> q;

	while(q--)
	{
		int code; // 1 - customer, 2 - monocarp, 3 - polycarp
		int amount;
		cin >> code;

		if (code == 1)
		{
			cin >> amount;
			spent[i] = amount;
			i++;

			if (max < amount)
			{
				max = amount;
			}
			
		}
		else if (code == 2)
		{
			while(spent[m] == -1)
			{
				m++;
			}
			cout << m << " ";

			if (spent[m] == max)
			{
				max = 0;
				for(int k = m+1; k <= i; k++)
				{
					if (max < spent[k])
					{
						max = spent[k];
					}
				}
			}

			spent[m] = -1;
		}
		else // if (code == 3)
		{
			for(int p = m; p < i; p++)
			{
				if (spent[p] == max)
				{
					max = 0;

					
					cout << p << " ";
					spent[p] = -1;


					for(int k = m; k < i; k++)
					{
						if(max < spent[k])
						{
							max = spent[k];
						}
					}

					p = i+1; // break out of a for loop
										
				}
			}
		}
		/*
		for(int k = 1; k <= 4; k++)
		{
			cout << spent[k] << " ";
		}
		cout << "\n";
		cout << "i : " << i << ", m : " << m << ", max : " << max << "\n";
		*/
	}
	
	
}
/*
11
1 103913
3
1 399791
1 297150
3
1 138455
1 192143
3
3
1 39878
3

*/
