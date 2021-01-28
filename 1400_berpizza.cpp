// https://codeforces.com/problemset/problem/1468/C

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairs;

struct comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
		
        if (l.second == r.second)
            return l.first < r.first;
 
        return l.second > r.second;
    }
};

int main()
{

	int q;



	int query;
	int i_th_customer = 1, money_spent;

	/* monoset will automatically be sorted and the first of the pairs is
	 * guaranteed to be unique */
	set<pairs> monoset;

	/* but polyset needs to be sorted by the second element of the pairs
	 * - (how much customers will spend) so I used a customized comparator */
	set<pairs, comp> polyset;

	cin >> q;

	while(q--)
	{

		cin >> query;

		if (query == 1) // customer comes in
		{
			cin >> money_spent;
			pairs temp = make_pair(i_th_customer++, money_spent);
			monoset.insert(temp);
			polyset.insert(temp);
		}

		else if (query == 2) // monocarp serves a customer
		{
			auto it = monoset.begin(); // find the first element in monoset
			
			cout << it -> first << " ";

			pairs temp = make_pair(it -> first, it -> second);
			monoset.erase(temp); // erase the customer from monocarp's set
			polyset.erase(temp); // erase the customer from polycarp's set
		}

		else // if (query == 3) polycarp serves a customer
		{
			auto it = polyset.begin();

			cout << it -> first << " ";

			pairs temp = make_pair(it -> first, it -> second);
			polyset.erase(temp); // erase the customer from polycarp's set
			monoset.erase(temp);
		}
	}

}
