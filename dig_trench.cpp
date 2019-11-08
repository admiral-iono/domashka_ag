#include <iostream>

using namespace std;
void dig_trench(int& size, int** (&array))
{
	int chisl = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-i; j++)
		{
			array[j+i][j] = chisl;
		}
		for (int j = 0; j < size - i; j++)
		{
			array[j][j+i] = chisl;
		}
		chisl++;
	}
	

}

int main()

{
	int n;
	cin >> n;
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}

	dig_trench(n, array);

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
