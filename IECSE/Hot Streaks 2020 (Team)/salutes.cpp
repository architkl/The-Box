#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000000
#define vecop(n) vector <int> v(n,0); for(int i=0; i<n; i++) { cin>>v[i]; }

int main() {
    FAST
    ll t;
    cin>>t;

    while(t--) {
        ll ans = 0;
        string s;
        cin>>s;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '>') {
                for(int j=i+1; j<s.length(); j++) {
                    if(s[j] == '<') {
                        ans = ((ans%MOD) + (2%MOD))%MOD;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}
