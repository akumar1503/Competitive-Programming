void primeGen(int lim) {
	//prime<bool> is vector,primes<int>should be declared globally.
	int sq = sqrt(lim) + 1;  prime.assign(lim + 1, true);
	for(int i=0;i<lim;i++)prime[i] = true;  prime[0] = prime[1] = false;
	for (int i = 2; i <= lim; i++) {
		if (prime[i]) {
			primes.push_back(i);
		//	cout << i << endl;
			if (i > sq)continue;
			for (int j = i*i; j <= lim; j += i) prime[j] = false;					
		}
	}
}

int binE(int x,int n)
{
    long long result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result = result * x;
        x = 1ll * x * x;
        n = n / 2;
    }
    return result;
}



int modE(int x,int n)
{
    long long result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result = (result * x) % MOD;
        x = (1ll * x * x) % MOD;
        n=n/2;
    }
    return result;
}

void adMd(long long &a, long long b) {
	a += b;
	if(a >= MOD) a -= MOD;
	if(a < 0) a += MOD;
}


int gcd(int A, int B) { return B==0?A:gcd(B, A % B); }




int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}



int modInverse(int A,int M)
{   //By Fermat’s theorem i.e M must be prime
    return modularExponentiation(A,M-2,M);
}



int d,x,y;
int modInverse(int A, int M)
{   //By Extended Euclidean algorithm i.e M can be anything 
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
ll prime[1000002];
void primeFact() {
	ll lim = 1000000;
	ll sq = sqrt(lim) + 1;	 	
	for (ll i = 2; i <= lim; i++) {
		if (!prime[i]) {
			prime[i] = i;
			if (i > sq)continue;
			for (ll j = i*i; j <= lim; j += i) prime[j] = i;
		}
	}
}





Factorise in O(log N)
bool v[MAX];
int len, sp[MAX];
void Sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (lli i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (lli j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}
int main(){
	Sieve();
	for (int i = 0; i < 50; i++)	cout << sp[i] << endl;	
    return 0;
}


//Factorization in √N
vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}



//Factorization
int minPrime[n + 1];
for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) {         //If i is prime
        for (int j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
for (int i = 2; i <= n; ++i) {
    if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}
vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}//The required factors are in res

ll gcd(ll q,ll d,ll &x,ll &y) {
	if(d%q==0) {
		x=1;
		y=0;
		return q;
	}
	ll x1,y1;
	ll ans = gcd(d%q,q,x1,y1);
	y=x1;
	x=y1-(d/q)*x1;
	return ans;
}
ll Inv(ll n,ll m) {
	ll x,y;
	ll g= gcd(n,m,x,y);
	if(g==1) {
		return (x+m)%m;
	}
	assert(0);
	return -1;
}
//x%mi = ri
ll CRT(std::vector<ll> &m,std::vector<ll> &r,ll &M) {
	M=1;
	int n=m.size();
	for (int i = 0; i < n; ++i)
	{
		M*=m[i];
	}
	ll x=0;
	for (int i = 0; i < n; ++i)
	{
		ll p = M/m[i];
		ll pi = Inv(p,m[i]);
		x=(x+r[i]*p*pi)%M;
	}
	return x;
}
 
ll nCr(ll n,ll r,ll p,std::vector<ll> &fact){
	if(r>n)
		return 0;
	ll N=fact[n];
	ll D = (fact[r]*fact[n-r])%p;
	ll ans = (N*Pow(D,p-2,p))%p;
	return ans;
}
 
std::map<ll, std::vector<ll> > FACTMAP;
ll lucas(ll n,ll r,ll P) {
	if(FACTMAP.find(P)==FACTMAP.end()) {
		std::vector<ll> fact(P+1,1);
		for (int i = 1; i <= P; ++i)
		{
			fact[i]=(fact[i-1]*i)%P;
		}
		FACTMAP[P]=fact;
	}
 
	std::vector<ll> &fact=FACTMAP[P];
	ll prod=1;
 
	while(n>0 && r>0) {
		ll N=n%P;
		ll R=r%P;
		n/=P;
		r/=P;
		prod=(prod*nCr(N,R,P,fact))%P;
	}
	return prod;
}
map<pair<int,int>,std::vector<ll> > mapSpecialFac;
//n!! part which is gcd with p^power
// return n!! , power of p in n!
 
pair<ll,int> specialFac(ll n,ll p,ll power,ll m) {
	// m = p^power
	std::vector<ll> &fac=mapSpecialFac[mp((int)p,(int)m)];
	if(fac.size()==0) {
		fac.resize(m,1);
		for (int i = 2; i <m; ++i)
		{
			fac[i]=(fac[i-1]* ((i%p)?i:1)  )%m;
		}	
	}
	if(n<p) {
		return mp(fac[n],0);
	}
 
	ll ans = fac[m-1],part2=fac[n%m];
 
	ans=(Pow(ans,n/m,m)*part2)%m;
 
	int pc = 0;
	ll val = ans;//Pow(specialFac(p-1,p,power,m).first,n/p,m);
	// what_is(val);
	// val=(val*specialFac(n%p,p,power,m).first)%m;
	// what_is(val);
	pair<ll,int> sol = specialFac(n/p,p,power,m);
	// what_is(sol.first);
	val=(val*sol.first)%m;
	// cerr<<"SPFactorial "<<n<<"%"<<m<<" = "<<val<<"   cnt "<<(sol.second + n/p)<<endl;
	return mp(val,sol.second + n/p);	
} 
 
ll nCr_primepow(ll n,ll r,ll p,ll power,ll m) {
	// m = p^power
	pair<ll,int> solN = specialFac(n,p,power,m);
	pair<ll,int> solD1 = specialFac(r,p,power,m);
	pair<ll,int> solD2 = specialFac(n-r,p,power,m);
	pair<ll,int> solD = mp((solD1.first*solD2.first)%m,solD1.second+solD2.second);
 
	ll v2 = Inv(solD.first,m);
	// cout<<"Inverse of "<<(solD.first)<<" from "<<m<<" is "<<v2<<endl;
	solN.second-=solD.second;
	// cerr<<"p^"<<(solN.second)<<" left\n";
	assert(solN.second>=0);
	ll ans = ((solN.first*v2)%m);
	// ans=(ans*Pow(p,max(0LL,min((ll)solN.second,power-1)),m))%m;
	ans=(ans*Pow(p,solN.second,m))%m;
	// cout<<n<<"C"<<r<<"%"<<m<<" = "<<ans<<endl;
	return (m+ans)%m;
}
 
ll bestnCrM(ll N,ll R,ll M) {
	ll M1=M;
	if(M==1)
		return 0;
	//mod p^i
 
	std::vector<ll > mod;
	std::vector<int > p;
	std::vector<int > power;
 
	std::vector<ll> rem;
 
	for (int i = 2; i*i <= M; ++i)
	if(M%i==0) {
		ll x=1;
		int c=0;
		while(M%i==0) {
			M/=i;
			x*=i;
			c++;
		}
		mod.push_back(x);
		power.push_back(c);
		p.push_back(i);
 
	}
	if(M!=1) {
		mod.push_back(M);
		power.push_back(1);
		p.push_back(M);
 
	}
	for (int i = 0; i < (int)mod.size(); ++i)
	{
		rem.push_back(nCr_primepow(N,R,p[i],power[i],mod[i]));
		// cout<<">"<<(*rem.rbegin())<<" "<<mod[i]<<endl;
	}
	ll M2;
	ll ans = CRT(mod,rem,M2)%M1;
	assert(M2==M1);
	// ans%=M1;
	ans=(ans+M1)%M1;
	return ans;
}



//Lucas Theorem
const int mx = 4e5 + 10;
const int mxl = 20;
const uli mod = 1e9 + 7;
uli fa[mx], ffi[mx];
int maxi[mxl][mx];
int mini[mxl][mx];
uli cmb(int n, int k) { return fa[n] * ffi[k] % mod*ffi[n - k] % mod; }
uli fxp(uli b, uli x) {
	uli a = 1;
	for (; x != 0; b = b*b%mod, x >>= 1)
		if (x & 1ll)a = a*b%mod;
	return a;
}


int main(){
	//fio;  
	
	fa[0] = ffi[0] = 1;
	for (int i = 1; i<mx; i++) {
		fa[i] = fa[i - 1] * uli(i) % mod;
		ffi[i] = fxp(fa[i], mod - 2);
	}
	cout << cmb(7, 4) << " ";

	getchar();
	return 0;
}
//Lucas Theorem ends
