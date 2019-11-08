#include <iostream>

using namespace std;

bool isPrime(const int& n)
{
	int d = 2;
	while (n % d != 0 && d * d <= n)
		++d;
	return d * d > n&& n;
}

void delete_annoying_primes(int& size, int* (&array))
{
	int nod;
	bool* arb = new bool[size];
	for (int i = 0; i < size; i++)
	{
		arb[i] = false;
	}
	for (int i = 0; i < size; i++)
	{
		nod = isPrime(array[i]);
		if (nod == true)
		{
			if (arb[i]==false) 
			{
				for (int j = i+1; j < size; j++)
				{
					if (array[i] == array[j])
					{
						arb[j] = true;
						arb[i] = true;
					}
				}
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

	
	array = new int[sum];
	for (int i = 0; i < sum; i++)
	{
		array[i] = tmp[i];
	}
	size = sum;
	
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

	delete_annoying_primes(n, array);

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}
