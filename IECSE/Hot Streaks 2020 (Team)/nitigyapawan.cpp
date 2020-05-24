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
        ll n;
        char ch;
        cin>>n>>ch;

        if(n%2 == 0) {
            if(ch == 'N') 
                cout<<"Nitigya\n";
            else
                cout<<"Paawan\n";
        }
        else {
            if(ch == 'N')
                cout<<"Paawan\n";
            else
                cout<<"Nitigya\n";
        }

    }
}
