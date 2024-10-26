#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	char a[100];
	int i, j, len;
	cin >> a;
	len = strlen(a);
	for (i = 1; i <= len; i++)
		if (len % i == 0)
		{
			int ok = 1;
			for (j = i; j < len; j++)
				if (a[j] != a[j % i]) {
					ok = 0;
					break;
				}
			if (ok) { cout << i << endl; break; }

		}
	return 0;
}