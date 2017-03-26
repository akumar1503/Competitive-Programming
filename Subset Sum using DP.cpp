#include "bits/stdc++.h"
using namespace std;
#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define pub(x) push_back(x)
#define   MAX(a,b)     (a>b?a:b)
#define   MIN(a,b)     (a>b?b:a)
#define	INF 1000009999909999  
#define   mp(a,b)      pair<int,int>(a,b)
typedef long long int ll; 
 
bool solve(vector< pair<int,int> > &cycles, int k) {
	bitset<1000006>dp;	
	dp[0] = 1;
	for (int i = 0; i < cycles.size(); i++) {
		pair<int, int>p = cycles[i];
		for (int x = 0; (1 << x) <= p.second; x++) {
			dp |= (dp << (p.first * (1 << x)));
			p.second -= (1 << x);
		}
		dp |= (dp << (p.first * p.second));
	}
	return dp[k];
}
int main(){	
#ifdef home
	freopen("../../../../../Desktop/input.txt", "r", stdin);
	freopen("../../../../../Desktop/output.txt", "w", stdout);
#endif // home
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k, a[1000006], c[1000006];  cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i];
	int mx, mn;
	bool d[1000006]; memset(d, false, sizeof d); memset(c, 0, sizeof c);
	vector< pair<int,int> > cycles;
	
	for (int i = 0; i < n; i++) {
		if (d[i] == false) {
			int j = i, sz = 0;
			while (d[j] == false) {
				d[j] = true;
				sz++;
				j = a[j]-1;
			}
			c[sz]++;			
		}
	}
	for (int i = 1; i <= n; i++)if (c[i])cycles.push_back({ i,c[i] });
	int _k = k,odd=0;
	mx = 0;
	for(auto s:cycles){
		int k = s.second;
		while (k--) {
			if (s.first & 1) {
				mx += 2 * min(_k, (s.first - 1) / 2);
				_k -= min(_k, (s.first - 1) / 2);
				odd++;
			}
			else {
				mx += 2 * min(_k, s.first / 2);
				_k -= min(_k, s.first / 2);
			}
			if (_k == 0)break;
		}
	}
	if (_k)mx += min(_k, odd);	
	mn = solve(cycles, k) ? k : k + 1;
	cout << mn << ' ' << mx;
	return 0;
}