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
#include <unordered_set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

class mycomp {
	public:
		bool operator() (pii a, pii b) {
			return (a.second > b.second);
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;

		vector <piii> edges(N);
		vector < vector <int> > G(N+1);
		vector <int> edgesRequired(N+1);
		
		// v_deg.resize(N+1);
		// edgesRequired.resize(N+1);
		// fill(v_deg.begin(), v_deg.end(), 0);
		// fill(edgesRequired.begin(), edgesRequired.end(), 0);

		vector <int> edgeWeights(N-1);
		int u, v, b;
		for (int i = 1; i < N; i++) {
			cin >> u >> v >> b;

			G[u].pb(v);
			G[v].pb(u);
			// edges[i] = mp(i, mp(u, v));

			// v_deg[u]++;
			// v_deg[v]++;

			edgesRequired[u]++;
			edgesRequired[v]++;

			edgeWeights[i-1] = b;
		}

		vector <int> vertWeights(N);
		priority_queue <pii, vector <pii>, mycomp> pq;
		vector <bool> done(N+1);
		// vector <int> verts(N+1);
		// int a;
		for (int i = 0; i < N; i++) {
			cin >> vertWeights[i];

			// verts[i+1] = i+1;
			pq.push(mp(i+1, edgesRequired[i+1]));
		}

		// sort(verts.begin()+1, verts.end(), comp);
		sort(edgeWeights.begin(), edgeWeights.end());
		sort(vertWeights.begin(), vertWeights.end());
		// sort(verts.begin()+1, verts.end(), comp2);

		int ew_idx = 0, vw_idx = 0, v_wt_cur, e_wt_mx, cur_v, cur_req, ans = 0;
		pii cur;
		while (!pq.empty()) {
			cur = pq.top();
			cur_v = cur.first;
			cur_req = cur.second;

			// cout << cur_v << " " << cur_req << "\n";

			if (cur_req == 0) done[cur_v] = 1;
			
			if (done[cur_v] || cur_req == 0) {
				pq.pop();
				continue;
			}
			
			v_wt_cur = vertWeights[vw_idx];
			e_wt_mx = edgeWeights[ew_idx+cur_req-1];
			// cout << cur_v << " requires " << cur_req << " edges\n";
			// cout << v_wt_cur << " " << ew_idx << " " << edgesRequired[cur_vert] << " " << e_wt_mx << "\n";

			if (v_wt_cur < e_wt_mx) {
				ans++;
				vw_idx++;
			}

			else {
				// cout << cur_v << " alloted " << e_wt_mx << "\n";
				pq.pop();
				for (auto j : G[cur_v]) {
					edgesRequired[j]--;
					// cout << j << " upd " << edgesRequired[j] << "\n";

					pq.push(mp(j, edgesRequired[j]));

					// cout << pq.top().first << " " << pq.top().second << "\n";
				}

				vw_idx++;
				ew_idx += cur_req;
				// edgesRequired[cur_vert] = -1;
				done[cur_v] = 1;
				// ans++;

				// sort(verts.begin()+1, verts.end(), comp2);
			}

			if (vw_idx == N) break;
		}

		cout << ans << "\n";
	}

	return 0;
}