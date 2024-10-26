#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str[80];
	cin.getline(str, 80);
	bool check = 0;
	int i = 0;
	for (int i = 0; i < 78; i++)
	{
		if (str[i] == '\0' && str[i + 1] == '\0')
		{
			break;
		}
		else if (str[i] == str[i + 1])
		{
			check = 1;
			break;
		}
		continue;
	}
	if (check) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
