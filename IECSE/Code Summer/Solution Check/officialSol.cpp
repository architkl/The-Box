/*=======================
Author    : Shounak Dey
Filename  : stalls.cpp
=======================	*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define MK make_pair 
#define SZ(a) (int)(sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define read(n) scanf("%d",&n)
#define readl(n) scanf("%lld",&n)
#define readul(n) scanf("%llu",&n);


#define SORTV(a) sort(a.begin(),a.end())
#define TEST int Test;cin >> Test;while(Test--)
#define gcd(a,b) __gcd(a,b)
#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __ builtin_popcount(a) // count set bits
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

bool value_comparer(map<ull,ull>::value_type &i1, map<ull,ull>::value_type &i2){
	return i1.first<i2.first;
}

int main()
{
	ifstream fi("Input", ios::in);
	ofstream fo("offOutput.txt", ios::out);

	int T;
	fi >> T;
	//cin >> T;
	for(int i=0;i<T;i++){
		ull k,n;
		fi >> n >> k;
		//cin >> n >> k;
		map<ull,ull> c;
		c[n]=1;
		ull l,r;
		ull p=0;
		while(1){
			ull x = (*max_element(c.begin(),c.end(),value_comparer)).first;
			// cout << x << endl;
			l = x/2;
			r = x-1-x/2;
			p += c[x];
			// cout << l << " " << r << " " << p << endl;
			if(p>=k)
				break;
			if(c.find(l) == c.end())
				c[l] = c[x];
			else
				c[l] += c[x]; 
			if(c.find(r) == c.end())
				c[r] = c[x];
			else
				c[r] += c[x];
			c.erase(x);
		}
		fo << "Case #" << i+1 << ": "<< l << " " << r << "\n";
		//cout << "Case #" << i+1 << ": "<< l << " " << r << endl;
	}

	fi.close();
	fo.close();
	
	return 0;
}