#include <bits/stdc++.h>
int qread()
{
	char c;
	int s = 0, t = 1;
	while ((c = getchar()) < '0' || c > '9')
		(c == '-' && (t = -1));
	do
		s = s * 10 + c - '0';
	while ((c = getchar()) >= '0' && c <= '9');
	return s * t;
}