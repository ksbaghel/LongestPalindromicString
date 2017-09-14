// LongestPalindromicString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
string longestPalindrome(string A) 
{
	int n = A.length();
	string s = "";
	if (n == 0) return s;
	if (n == 1) return A;

	vector<vector<bool> > PS(n, vector<bool>(n, false));
	int maxPS = 1;
	for (int i = 0; i<n; i++)
	{
		for (int j = i; j<n; j++)
		{
			if (j == i)
			{
				PS[i][j] = true;
			}
			else if (j == i + 1 && A[j] == A[i])
			{
				PS[i][j] = true;
				maxPS = 2;
			}
		}
	}

	for (int gap = 1; gap<n; gap++)
	{
		for (int i = 0; i<n - gap; i++)
		{
			int j = i + gap;
			if (!PS[i][j] && (A[i] == A[j] && PS[i + 1][j - 1]))
			{
				PS[i][j] = true;
				maxPS = max(maxPS, gap + 1);
			}
		}
	}

	string maxPSstring;
	for (int i = 0; i<n - maxPS+1; i++)
	{
		if (PS[i][i + maxPS - 1])
		{
			maxPSstring = A.substr(i, maxPS);
			break;
		}
	}

	return maxPSstring;
}


int main()
{
	string s;
	cin >> s;

	cout << longestPalindrome(s) << endl;
    return 0;
}

