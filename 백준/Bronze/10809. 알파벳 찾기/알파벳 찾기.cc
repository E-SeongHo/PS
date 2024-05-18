#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	char str[100];
	cin >> str;
	bool on;

	for (char i = 'a'; i < 'z' + 1; i++)
	{
		on = false;
		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == i)
			{
				cout << j << ' ';
				on = true;
				break;
			}
		}
		if (on == false) cout << -1 << ' ';
	}

	return 0;
}