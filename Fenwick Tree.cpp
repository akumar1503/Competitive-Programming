int fen[MAX_N];
void update(int p,int val){
	for(int i = p;i <= n;i += i & -i)
		fen[i] += val;
}
int sum(int p){
	int ans = 0;
	for(int i = p;i;i -= i & -i)
		ans += fen[i];
	return ans;
}


/*   2D - Fenwick Tree   */
long long tree[2010][2010];
void add(int x,int y,int val)
{
    int i,j;
    for(i=x;i<=n;i+=i&(-i)) for(j=y;j<=m;j+=j&(-j)) tree[i][j] += val;
}
long long query(int x,int y)
{
    int i,j;
    long long ret = 0;
    for(i=x;i;i-=i&(-i)) for(j=y;j;j-=j&(-j)) ret += tree[i][j];
    return ret;
}