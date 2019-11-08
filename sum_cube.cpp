

#include <iostream>
using namespace std;
void push_back(const int& c, int& size, int* (&array))
{
	int* tmp = new int[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = array[i];
	}
	delete[] array;
	size++;
	array = new int[size];
	for (int i = 0; i < size-1; i++)
	{
		array[i] = tmp[i];
	}
	array[size-1] = c;
}

void suma_cuba(int& size,const int& n, int* (&array))
{
	if (n == 1) {
		push_back(1, size, array);
		return;
	}
	if (n == 0) {
		return;
	}

	int l = 0, r=n+1;
	while (r - l > 1)
	{
		int m = (r + l) / 2;
		if (m * m * m <= n)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	push_back(l, size, array);

	suma_cuba(size, n - l * l * l, array);
}
int main()
{
	int n, size=0;
	cin >> n;
	int* sum = new int[size];
	
	suma_cuba(size, n, sum);
	if (size > 8) 
	{
		cout << "Impossible";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << sum[i]<<" ";
		}
	}

}

