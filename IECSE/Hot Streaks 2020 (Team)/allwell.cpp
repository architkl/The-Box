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
 
        vector <pair<int,int>> vec;
        for(int i=0; i<n; i++) {
            pair<int,int> temp;
            cin>>temp.first;
            temp.second = i;
            vec.push_back(temp);
        }

        ll k;
        cin>>k;
        k--;

        ll ans = 0;

        sort(vec.begin(), vec.end());
        for(int i=0; i<n; i++) {
            if(vec[i].second == k) {
                ans = i;
                break;
            }
        }
        ans++;
        cout<<ans<<"\n";

    }
}
