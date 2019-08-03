#include <bits/stdc++.h>

using namespace std;

bool mycomp(int a, int b)
{
	int l1 = floor(log10(a))+1, l2 = floor(log10(b))+1;

	long long int t1 = (long long)a*pow(10, l2) + b, t2 = (long long)b*pow(10, l1) + a;

	return (t1 > t2);
}

string largestNumber(const vector<int> &A) {
	vector <int> copy(A);
	sort(copy.begin(), copy.end(), mycomp);

	string temp = "", ans = "";
	for (auto i : copy)
		temp += to_string(i);

	int i = 0;
	while (i < temp.length() && temp[i] == '0')
		i++;

	while (i < temp.length())
	{
		ans += temp[i];
		i++;
	}

	if (ans.length() == 0)
		ans = "0";

	return ans;
}

int main()
{
	int n;
	cin >> n;

	vector <int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	cout << largestNumber(A) << "\n";

	return 0;
}