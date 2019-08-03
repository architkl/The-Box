#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int m;
	cin >> m;

	vector <int> cnt(5001, 0);
	int t;
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		cnt[t]++;
	}

	int max = 0;
	for (int i = 5000; i >= 0; i--)
	{
		if (cnt[i])
		{
			max = i;
			break;
		}
	}

	vector <int> nums1, nums2;
	// for (int i = max-1; i >= 0; i--)
	// {
	// 	if (cnt[i] >= 2)
	// 	{
	// 		nums1.push_back(i);
	// 		nums2.push_back(i);
	// 	}

	// 	else if (cnt[i] == 1)
	// 		nums1.push_back(i);
	// }

	for (int i = max-1; i >= 0; i--)
	{
		if (cnt[i] >= 2)
		{
			nums1.push_back(i);
			nums2.push_back(i);
		}

		else if (cnt[i] == 1)
			nums2.push_back(i);
	}

	cout << nums1.size() + nums2.size() + 1 << "\n";

	for (int i = nums1.size()-1; i >= 0; i--)
		cout << nums1[i] << " ";

	cout << max << " ";

	for (int i = 0; i < nums2.size(); i++)
		cout << nums2[i] << " ";

	cout << "\n";

	return 0;
}