#include <iostream>

using namespace std;
void put_snake(int& n, int& m, int** (&array))
{
	int num = 1;
	int k = 0;
	int numbers = n * m;
	int x_max = m, y_max = n;
	int x_min = 0, y_min = 0;
	int x = m-1, y = 0;


	while (k < numbers)
	{

		for (; x >= x_min && k < numbers; x--, k++) {
			array[y][x] = num++;
		}
		x++;
		y++;
		x_min++;

		for (; y < y_max && k < numbers; y++, k++) {
			array[y][x] = num++;
		}
		y--;
		x++;
		y_min++;

		for (; x < x_max && k < numbers; x++, k++) {
			array[y][x] = num++;
		}

		x--;
		y--;
		x_max--;

		for (; y >= y_min && k < numbers; y--, k++) {
			array[y][x] = num++;
		}

		y++;
		x--;
		y_max--;



	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	int** array = new int* [m];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[m];
	}

	put_snake(n,m, array);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "\t"  << array[i][j];
		}
		cout << endl;
	}
	return 0;
}
