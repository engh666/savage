#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int n, k;
	cout << "Enter N and K: ";
	cin >> n >> k;
	if (n % 5 == 0) cout << 1 << endl;
	else if (n % 5 == 1)
	{
		int d = -1, j = 0, r = (n-1)/5;
		while (j <= r) 
		{
			d++;
			j = pow(2, d);
		}
		for (int i = d; i >= 0; i--)
		{
			if (r % (int)pow(2, i) == 0)
			{
				if (k < 5 * (pow(2, i)))
				{
					cout << "loss\n";
					system("pause");
					return 0;
				}
				else 
				{
					cout << 5 * (pow(2, i)) << endl;
					system("pause");
					return 0;
				}
			}
		}
	}
	else if (n % 5 == 2) cout << 1 << endl;
	else if (n % 5 == 3)
	{
		if (k < 2) cout << "loss\n";
		else cout << 2 << endl;
	}
	else
	{
		if (k < 3) cout << "loss\n";
		else cout << 3 << endl;
	}
	system("pause");
}

