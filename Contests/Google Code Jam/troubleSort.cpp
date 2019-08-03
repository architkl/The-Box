#include <iostream>
#include <vector>

using namespace std;

void trouble_sort(vector <int> &L)
{
	int n = L.size(), temp;
	bool done = false;

	while (!done)
	{
		done = true;

		for (int i = 0; i < n-2; i++)
		{
			if (L[i] > L[i+2])
			{
				done = false;

				temp = L[i];
				L[i] = L[i+2];
				L[i+2] = temp;
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	int n;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);

		vector <int> V(n);
		for (int j = 0; j < n; j++)
			scanf("%d", &V[j]);

		trouble_sort(V);

		int ind = -1;
		for (int i = 0; i < n-1; i++)
		{
			if (V[i] > V[i+1])
			{
				ind = i;
				break;
			}
		}

		if (ind == -1)
			printf("Case #%d: OK\n", i + 1);
			//cout << "Case #" << i + 1 << ": OK\n";

		else
			printf("Case #%d: %d\n", i + 1, ind);
			//cout << "Case #" << i + 1 << ": " << ind << "\n";
	}

	return 0;
}