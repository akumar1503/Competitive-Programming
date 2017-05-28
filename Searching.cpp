ll bs(ll s,ll e){
	if(s==e)
		return s;
	ll mid=(s+e)/2;
	if((mid*(mid+1LL)>=n)){
		return bs(s,mid); 
	}
	return bs(mid+1,e);
}


long long l = m + 1;
    long long r = m + 2e9;
    while(l < r){
        long long mid = l + r >> 1;
        long long val = mid - m;
        long long tot = m;
        tot += (val * (val + 1LL)) / 2LL;
        if(tot < n){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }

//Ternary Search
int ternary_search(int l,int r){
    if(l == r) return l;
    int mid1 = l + (r - l)/3;
    int mid2 = r - (r - l)/3;
      
    LL m1 = go(mid1);
    LL m2 = go(mid2);

    if(m1 < m2)
        return ternary_search(l, mid2 - 1);
    else if(m1 > m2)
        return ternary_search(mid1 + 1, r);
    else {
        if(mid2 - mid1 < 2){
            return mid1;
        }

        return ternary_search(mid1 + 1, mid2 - 1);
    }
}

// Ternary Search for doubles
double func(double x)
{ 
return -1*1*x*x + 2*x +3; 
}

// add eps if needed
double ts(double start, double end)
{
    double l = start, r = end;

    for(int i=0; i<200; i++) {
      double l1 = (l*2+r)/3;
      double l2 = (l+2*r)/3;
      //cout<<l1<<" "<<l2<<endl;
      if(func(l1) > func(l2)) r = l2; else l = l1;
      }

     double x = l;
    return func(x);
}

// Ternary Search
 while( L < R )
        {
            int mid = (L + R) / 2;
            if(solve(mid) < solve(mid + 1))
                R = mid;
            else
                L = mid + 1;
        }