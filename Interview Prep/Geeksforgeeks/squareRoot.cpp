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

long long int floorSqrt(long long int x) 
{
    long long int l = 0, r = x, mid;
    
    while (l <= r)
    {
        mid = (l+r) / 2;

        cout << l << " " << mid << " " << r << "\n";
        
        if (mid*mid == x)
            return mid;
        
        if (mid*mid > x)
            r = mid-1;
        
        else
            l = mid+1;
    }
    
    return min(l, r);
}

int main()
{
	ll x;
	cin >> x;

	cout << floorSqrt(x) << "\n";

	return 0;
}