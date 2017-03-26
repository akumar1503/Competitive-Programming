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

int binaryExp(int x,int n)
{
    long long result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=result * x;
        x=x*x;
        n=n/2;
    }
    return result;
}



int modularExp(int x,int n)
{
    long long result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%MOD;
        x=(x*x)%MOD;
        n=n/2;
    }
    return result;
}

void addMod(long long &a, long long b) {
	a += b;
	if(a >= MOD) a -= MOD;
	if(a < 0) a += MOD;
}


int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}




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
