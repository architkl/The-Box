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
    #include <cmath>
     
    using namespace std;
     
    #define pb push_back
    #define mp make_pair
     
    typedef pair <int, int> pii;
    typedef pair <int, pii> piii;
    typedef unsigned long long ull;
    typedef long long ll;
     
    bool canSolve(vector <ll> q, ll mx, int m, ll t) {
    	if (t < mx) return false;
     
    	int days = 0, q_itr = 0;
    	ll t_left;
    	// cout << "\n\n";
     
    	while (q_itr < q.size()) {
    		days++;
    		t_left = t;
     
    		while (q_itr < q.size() && t_left - q[q_itr] >= 0) {
    			// cout << q_itr << " " << t_left << "\n";
    			t_left -= q[q_itr];
    			q_itr++;
    		}
    	}
     
    	return (days <= m);
    }
     
    int main() {
    	int N, M;
    	cin >> N >> M;
     
    	vector <ll> q(N);
    	for (int i = 0; i < N; i++) cin >> q[i];
     
    	ll mx = *max_element(q.begin(), q.end()), l = 0, h = LLONG_MAX, mid;
    	while (l <= h) {
    		mid = (l/2 + h/2) + (l%2 && h%2);
    		// cout << l << " " << mid << " " << h << "\n";
     
    		if (canSolve(q, mx, M, mid)) h = mid-1;
     
    		else l = mid+1;
    	}
     
    	cout << (canSolve(q, mx, M, h) ? h : l) << "\n";
     
    	return 0;
    }