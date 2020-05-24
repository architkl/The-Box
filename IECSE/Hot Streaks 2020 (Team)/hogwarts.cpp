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
        ll gals;
        cin>>gals;

        vector <ll> g(gals,0);
        for(int i=0; i<gals; i++)
            cin>>g[i];

        ll boys;
        cin>>boys;

        vector <ll> b(boys,0);
        for(int i=0; i<boys; i++)
            cin>>b[i];

        sort(g.begin(), g.end());
        sort(b.begin(), b.end());

        int i = gals - 1, j = boys - 1;
        ll ctr = 0;
        while(i >= 0 && j >= 0) {
            if(abs(g[i]-b[j]) <= 1) {
                i--;
                j--;
                ctr++;
            }
            else {
                if(g[i] < b[j]) {
                    j--;
                }
                else
                    i--;
            }
        }
        cout<<ctr<<"\n";

    }
}
