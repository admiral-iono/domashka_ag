#include <iostream>

using namespace std;

void delete_duplicates(int& size, int* (&array))
{
	bool* arb = new bool[size];
	for (int i = 0; i < size; i++)
	{
		arb[i] = false;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
			{
				arb[j] = true;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (arb[i] == false)
		{
			sum++;
		}
	}

	int* tmp = new int[sum];

	for (int i = 0, j = 0; i < size; i++)
	{
		if (arb[i] == false)
		{
			tmp[j] = array[i];
			j++;
		}
	}

	//delete[]array;
	array = new int[sum];
	for (int i = 0; i < sum; i++)
	{
		//cout <<  tmp[i] << " ";
		array[i] = tmp[i];
	}
	size = sum;
	//return *tmp;
}

int main()
{
	int n;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	delete_duplicates(n, array);

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}
