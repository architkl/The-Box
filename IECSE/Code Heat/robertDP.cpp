#include <iostream>

using namespace std;

int main()
{
	int L, N;
	cin >> L >> N;

	int W, H;
	for (int i = 0; i < N; i++)
	{
		cin >> W >> H;

		if (W < L || H < L)
			cout << "UPLOAD ANOTHER\n";

		else if (W != H)
			cout << "CROP IT\n";

		else
			cout << "ACCEPTED\n";
	}

	return 0;
}