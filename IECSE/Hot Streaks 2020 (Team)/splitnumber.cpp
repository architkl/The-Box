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
 
        string s;
        cin>>s;
 
        string a = "1", b = "1";
        
        for(int i = 1; i < n; i++) {
            if(s[i] == '1') {
                a = a + '1';
                b = b + '0';
                for(int j = i+1; j<n; j++) {
                    a = a + '0';
                    b = b + s[j];
                }
                break;
            }
            else if(s[i] == '0') {
                a = a + '0';
                b = b + '0';
            }
            else {
                a = a + '1';
                b = b + '1';
            }
        }
 
        cout<<a<<"\n";
        cout<<b<<"\n";

    }
}
