// https://codeforces.com/problemset/problem/1468/C

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairs;

bool sortbysec(const pairs &a, 
              const pairs &b) 
{ 
    return (a.second < b.second); 
} 

int main()
{

	int q;



	int query;
	int i_th_customer = 1, money_spent;
	
	set<pairs> monoset, polyset;

	cin >> q;

	while(q--)
	{

		cin >> query;

		if (query == 1)
		{
			cin >> money_spent;
			pairs temp = make_pair(i_th_customer++, money_spent);
			monoset.insert(temp);
			polyset.insert(temp);
			sort(polyset.begin(), polyset.end(), sortbysec);
		}

		else if (query == 2)
		{
			
		}

		else // if (query == 3)
		{
			
		}
	}

	for (auto const &x : polyset)
	{
		cout << x.first << ", " << x.second << "\n";
	}
	for (auto const &x : monoset)
	{
		cout << x.first << ", " << x.second << "\n";
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
