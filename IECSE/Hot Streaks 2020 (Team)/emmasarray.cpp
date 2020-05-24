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
        cin>>n;

        vecop(n);  
        int f = 1;      
        
        for(int i=0; i<n; i++) {
        	if(v[i] < i || v[i] < (n-i+1)) {
        		f = 0;
        		break;
        	}
        }

        if(f)
        	cout<<"Yes\n";
        else
        	cout<<"No\n";

    }
}
