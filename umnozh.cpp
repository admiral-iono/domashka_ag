
#include <iostream>

using namespace std;

void strange_multiply(int &a, int&b, int& otvet)
{
	otvet = 0;
	if (a > b)
	{
		for (int i = 0; i < b; i++)
		{
			otvet += a;
		}
	}
	else
	{
		for (int i = 0; i < a; i++)
		{
			otvet += b;
		}
	}
}
int main()
{
	int a, b, otvet;
	cin >> a >> b;
	strange_multiply(a, b, otvet);

	cout << otvet;
}

