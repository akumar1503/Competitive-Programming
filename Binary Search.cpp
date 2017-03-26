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