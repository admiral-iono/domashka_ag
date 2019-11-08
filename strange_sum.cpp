#include <iostream>

using namespace std;

int strange_sum(const int& f, const int& s, int* & arr)
{
	if (s - f == 1)
	{
		return arr[f];
	}
	return strange_sum(f, (f + s) / 2, arr) + strange_sum((f + s) / 2, s, arr);

}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << strange_sum(0, n, arr);
}