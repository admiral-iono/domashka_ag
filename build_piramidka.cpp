

#include <iostream>

using namespace std;
void build_ziggurat(int& size, int**(&array))
{
	int chisl=1;
	for (int i = 0; i < (size+1)/2; i++)
	{
		for (int j = i; j < size-i; j++)
		{
			array[i][j] = chisl;
		}
		for (int j = i; j < size - i; j++)
		{
			array[j][i] = chisl;
		}
		for (int j = i; j < size - i; j++)
		{
			array[j][size - 1 - i] = chisl;
		}
		for (int j = i; j < size - i; j++)
		{
			array[size - 1 - i][j] = chisl;
		}
		chisl++;
	}
}

int main()
{
	int n;
	cin >> n;
	int** array = new int*[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}

	build_ziggurat(n, array);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j];
		}
		cout << "\n";
	}
	return 0;
}

