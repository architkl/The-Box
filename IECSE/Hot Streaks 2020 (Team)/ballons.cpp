#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define vecop(n) vector <int> v(n,0); for(int i=0; i<n; i++) { cin>>v[i]; }

int main() {
    FAST
    ll t;
    cin>>t;

    while(t--) {
        ll n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        map <char,ll> m;
        for(int i=0; i<s.length(); i++) {
            m[s[i]]++;
        }

        int f = 1;

        map <char,ll>::iterator it;
        for(it=m.begin(); it!=m.end(); it++) {
            if(it->second > k) {
                f = 0;
                break;
            }
        }

        if(f == 1) 
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
}
