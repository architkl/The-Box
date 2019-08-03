/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;
typedef long long ll;

unordered_map <int, string> word({
	{1, "One"},
	{2, "Two"},
	{3, "Three"},
	{4, "Four"},
	{5, "Five"},
	{6, "Six"},
	{7, "Seven"},
	{8, "Eight"},
	{9, "Nine"},
	{10, "Ten"},
	{11, "Eleven"},
	{12, "Twelve"},
	{13, "Thirteen"},
	{14, "Fourteen"},
	{15, "Fifteen"},
	{16, "Sixteen"},
	{17, "Seventeen"},
	{18, "Eighteen"},
	{19, "Nineteen"},
	{20, "Twenty"},
	{30, "Thirty"},
	{40, "Forty"},
	{50, "Fifty"},
	{60, "Sixty"},
	{70, "Seventy"},
	{80, "Eighty"},
	{90, "Ninety"},
	{100, "Hundred"}
});

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int T;
	cin >> T;

	ll N;

	while (T--)
	{
		cin >> N;

		string s = "";
		while (N)
		{
			s += to_string(N%10);
			N /= 10;
		}

		while (s.length() < 13)
			s += '0';

		reverse(s.begin(), s.end());

		int i = 0, cnt = 0;
		vector <string> suff({"Trillion", "Billion", "Million", "Thousand", ""});
		string ans = "";
		// cout << s << "\n";

		if (s[i] != '0')
			ans += word[s[i]-48] + " " + suff[cnt] + " ";

		i++;
		cnt++;

		while (i < 13)
		{
			// cout << suff[cnt] << " " << s[i]-48 << s[i+1]-48 << s[i+2]-48 << "\n";	
			if (s[i] != '0' || s[i+1] != '0' || s[i+2] != '0')
			{
				if (s[i] != '0')
				{
					ans += word[s[i]-48] + " Hundred ";

					if (s[i+1] == s[i+2] == '0')
						ans += "";

					else if (s[i+2] == '0')
						ans += word[(s[i+1]-48)*10] + " ";

					else if (s[i+1] == '0')
						ans += word[s[i+2]-48] + " ";

					else
					{
						if (s[i+1] == '1')
							ans += word[(s[i+1]-48)*10 + s[i+2]-48] + " ";

						else
							ans += word[(s[i+1]-48)*10] + " " + word[s[i+2]-48] + " ";
					}
				}

				else if (s[i+1] == '1')
					ans += word[(s[i+1]-48)*10 + s[i+2]-48] + " ";

				else if (s[i+1] == '0')
					ans += word[s[i+2]-48] + " ";

				else if (s[i+2] == '0')
					ans += word[(s[i+1]-48)*10] + " ";

				else
					ans += word[(s[i+1]-48)*10] + " " + word[s[i+2]-48] + " ";

				ans += suff[cnt] + " ";
			}
			
			i += 3;
			cnt++;
		}

		cout << ans << "\n";
	}

	return 0;
}