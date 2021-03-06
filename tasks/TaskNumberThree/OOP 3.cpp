#include "stdafx.h"
#include "OOP 3.h"
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool check(vector<bool> f)
{
	bool exists = false;
	double i = f.size()+1, c = 0;
	while (i > 1) 
	{
		i /= 2.;
		c++;
		if (i == 1) exists = true;
	}
	if (exists)
	{
		for (int k = 0; k < c; k++)
		{
			for (int j = pow(2, k); j + pow(2, k + 1)<f.size(); j += pow(2, k+1))
			{
				if (f[j-1] == f[j + pow(2, k + 1)-1])
				{
					exists = false;
					break;
				}
			}
		}
	}
	return exists;
}

Fold::Fold() {}

Fold::Fold(bool newDir) { dir = newDir; }

char Fold::getDir()
{
	if (dir) return 'К';
	return 'О';
}

Tape::Tape() { foldCount = 0; }

Tape::Tape(vector<bool> f)
{
	if (check(f))
	{
		int d;
		head = new Fold(f[0]);
		Fold *curr = head;
		for (int i = 1; i < f.size(); i++)
		{
			curr->next = new Fold(f[i]);
			curr = curr->next;
		}
		for (int i = 0; pow(2, i) < f.size(); i++)
		{
			d = pow(2, i)-1;
			if (d != f.size() / 2)
			{
				if (f[d]) bigFolds.push_back('П');
				else bigFolds.push_back('З');
			}
			else
			{
				if (f[d]) bigFolds.push_back('З');
				else bigFolds.push_back('П');
			}
		}
		reverse(bigFolds.begin(), bigFolds.end());
	}
	else cout << "Такого ряда не существует\n";
}

void Tape::insert(bool newDir, Fold *fold)
{
	if (!fold)
	{
		cout << "Ошибка: отсутствует элемент";
		return;
	}
	Fold* curr = new Fold(newDir);
	curr->next = fold->next;
	fold->next = curr;
}

void Tape::fold(bool newDir)
{
	if (newDir) bigFolds.push_back('П');
	else bigFolds.push_back('З');
	bool tmp = newDir;
	if (foldCount == 0) tmp = !tmp;
	foldCount++;
	Fold *curr = new Fold(tmp);
	curr->next = head;
	head = curr;
	while (curr->next) 
	{
		tmp = !tmp;
		curr = curr->next;
		insert(tmp, curr);
		curr = curr->next;
	}
}

void Tape::print()
{
	Fold *curr = head;
	while (curr)
	{
		cout << curr->getDir() << endl;
		curr = curr->next;
	}
}

void Tape::printBig()
{
	for (char c : bigFolds)
		cout << c << endl;
}