/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

int k_moves[8][2] = { {-2, -1}, {-2, 1}, {-1, 2}, {1, 2},
					{2, 1}, {2, -1}, {1, -2}, {-1, -2} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> X(N), Y(N);
		int A, B;
		for (int j = 0; j < N; j++)
			cin >> X[j] >> Y[j];

		cin >> A >> B;

		// int unsafe[9][2] = { {A-1, B-1}, {A-1, B}, {A-1, B+1},
		// 					{A, B-1}, {A, B}, {A, B+1},
		// 					{A+1, B-1}, {A+1, B}, {A+1, B+1} };
		int check[3][3] = {}, f;

		for (int j = 0; j < N; j++)
		{
			// cout << "KNIGHT #" << j+1 << "\n";
			for (int k = 0; k < 8; k++)
			{
				// cout << "X: " << X[j] << "+" << k_moves[k][0] << "\n";	
				for (int l = -1; l <= 1; l++)
				{
					f = 0;

					if (X[j] + k_moves[k][0] == A + l)
					{
						// cout << "Y: " << Y[j] + k_moves[k][1] << "\n";
						for (int m = -1; m <= 1; m++)
						{
							if (Y[j] + k_moves[k][1] == B + m)
							{
								check[l+1][m+1] = -1;
								// cout << "NOT SAFE\n";
								f = 1;
								break;
							}
						}
					}

					// cout << "\n";

					if (f)
						break;
				}
			}
		}

		// for (int j = 0; j < 3; j++)
		// {
		// 	for (int k = 0; k < 3; k++)
		// 		cout << check[j][k] << " ";
		// 	cout << "\n";
		// }

		int safe = 0;
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (j == 1 && k == 1)
					continue;

				if (check[j][k] != -1)
				{
					safe = 1;
					break;
				}
			}

			if (safe)
				break;
		}

		safe == 0 ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}