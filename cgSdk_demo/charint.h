#pragma once

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

#define ll long long

ll chartoint(const char* a)
{
	ll result = 0;
	string b(a);
	int size = b.size();
	int t = 1;
	for (int i = size-1; i >= 0; i--)
	{
		result += (b[i] - '0') * t;
		t *= 10;
	}
	return result;
}


string inttostring(ll a)
{
	ll s = a;
	int size = 0;
	do
	{
		a /= 10;
		size++;
	} while (size != 0);
	string b;
	for (int i = size - 1; i >= 0; i--)
	{
		b[i] = (char)s % 10 + '0';
		s /= 10;
	}
	return b;
}

const char* inttochar(ll a)
{
	string result;
	result = inttostring(a);
	const char* b;
	b = result.c_str();
	return b;
}