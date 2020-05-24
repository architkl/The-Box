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
        ll n;
        cin>>n;

        string s;
        cin>>s;
        int ans = 0,c=0;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'U')
                c++;
            else
                c--;
            if(c == 0 && s[i] == 'U')
                ans++;
        }

        cout<<ans<<"\n";
    }
}
