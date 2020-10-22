#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	int a, b, c;
	while (t--)
	{
		a = 0; b = 0; c = 0;
		cin >> a >> b >> c;
		if (a + b + c == 180)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
