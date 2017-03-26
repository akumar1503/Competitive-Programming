/*

http://codeforces.com/blog/entry/44351 - First question
http://codeforces.com/problemset/problem/600/E

*/

#include "bits/stdc++.h"
using namespace std;
typedef long long int LL;
const int maxn = 1e5 + 5;
vector<int>G[maxn];
int c[maxn], sz[maxn];
LL ans[maxn];
int n;
unordered_map<int, int>* cnt[maxn];
void dfs(int u, int p) { sz[u] = 1; for (int x : G[u])if (x != p)dfs(x, u), sz[u] += sz[x];  }
pair<LL, LL> m[maxn];
void dsu(int u, int p) {
	int mx = -1, bigChild = -1;
	sz[u] = 1;
	for (auto v : G[u]) {
		if (v != p) {
			dsu(v, u);
			sz[u] += sz[v];
			if (mx < sz[v])mx = sz[v], bigChild = v;
		}
	}
	if (bigChild != -1)
		cnt[u] = cnt[bigChild], m[u].first = m[bigChild].first, m[u].second = m[bigChild].second;
	(*cnt[u])[c[u]]++; 
	if ((*cnt[u])[c[u]] == m[u].second) {
		m[u].first += c[u];
	}
	else if ((*cnt[u])[c[u]] > m[u].second) {
		m[u].first = c[u];
		m[u].second = (*cnt[u])[c[u]];
	}
	for (auto v : G[u]) {
		if (v != p && v != bigChild) {
			for (auto col : *cnt[v]) {
				(*cnt[u])[col.first] += col.second;
			
				if ((*cnt[u])[col.first] == m[u].second) {
					m[u].first += col.first;
				}
				else if ((*cnt[u])[col.first] > m[u].second) {
					m[u].first = col.first;
					m[u].second = (*cnt[u])[col.first];
				}
			
			}
		}	
	}
	ans[u] = m[u].first;
	
}

int main() {
#ifdef fi
	freopen("../../../../../Desktop/input.txt", "r", stdin);
	freopen("../../../../../Desktop/output.txt", "w", stdout);
#endif 
	scanf("%d", &n);// cin >> n;
	for (int i = 0; i < maxn; i++)m[i] = { -1,0 };
	for (int i = 0; i < n; i++) { scanf("%d",&c[i]); cnt[i] = new unordered_map<int, int>; }
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
//	dfs(0, -1);
	dsu(0, -1);
	for (int i = 0; i < n; i++)printf("%lli ", ans[i]);
	return 0;
} 