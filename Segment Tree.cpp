// SUM
struct segtree{
	int s[N*4], lzy[N*4];
	int *a;
	void build(int id = 1,int l = 0,int r = n-1){
		if(r == l){	//	l + 1 == r
			s[id] = a[l];
			return ;
		}
		int mid = (l+r)>>1;
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);
		s[id] = s[id * 2] + s[id * 2 + 1];
	}
	void build(int *A,int l=0,int r=n-1){	a=A;	build(1,l,r);	}
	void upd(int p,int x,int id = 1,int l = 0,int r = n-1){
		if(r == l){	//	l = r - 1 = p
			a[p] += x;
			return ;
		}
		int mid = (l + r)>>1;
		if(p <= mid)
			upd(p, x, id * 2, l, mid);
		else
			upd(p, x, id * 2 + 1, mid+1, r);
	}
	int get(int x,int y,int id = 1,int l = 0,int r = n-1){
		if(x > r or l > y)	return 0;
		if(x <= l && r <= y)	return s[id];
		int mid = (l+r)>>1; 
		return get(x, y, id * 2, l, mid) +
		       get(x, y, id * 2 + 1, mid+1, r);
	}
	void updRange(int st, int end, int x, int id = 1, int l = 0, int r = n-1){
		
		if(lzy[id]!=0){
			s[id]+=(r-l+1)*lzy[id];
			if(l!=r){
				lzy[2*id]+=lzy[id];
				lzy[2*id+1]+=lzy[id];
			}
			lzy[id]=0;			
		}
		if(r<st || l>end)return;

		if(l>=st && r<=end){
			s[id] += (r - l + 1) * x;
			if(l!=r){
				lzy[2*id] += x;
				lzy[2*id+1] += x;
			}
			return;
		}
		int mid=(l+r)>>1;
		updRange(st, end, x, 2*id, l, mid);
		updRange(st, end, x, 2*id + 1, mid + 1, r);
		s[id]=s[2*id] + s[2*id + 1];

	}
	int getRange(int x,int y,int id = 1,int l = 0,int r = n-1){
		if(x > r or l > y)	return 0;
		if(lzy[id]!=0){
			s[id]+=(r-l+1)*lzy[id];
			if(l!=r){
				lzy[2*id] += lzy[id];
				lzy[2*id+1] += lzy[id];
			}
			lzy[id]=0;			
		}
		if(x <= l && r <= y)	return s[id];
		int mid = (l+r)>>1; 
		return get(x, y, id * 2, l, mid) +
		       get(x, y, id * 2 + 1, mid+1, r);
	}

}



//Product change a[i]=x
pii operator*(const pii &f,const pii &s){
        pii p;
        p.fi = (1ll * f.fi * s.fi) % MOD;
        p.se = (1ll * f.se * s.se) % MOD;
        return p;
}
pii operator%(const pii &f,const LL &m){
        pii p;
        p.fi = f.fi % MOD;
        p.se = f.se % MOD;
        return p;
}
struct segtree{
    pii s[N*4];
    LL *a, lzy[N*4];
    
    void build(LL id = 1,LL l = 0,LL r = n-1){
        if(r<l)return;
        if(r == l){ 
            s[id] = pii(a[l],a[l]-1);   
            return ;
        }
        LL mid = (l+r)>>1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        s[id] = ( s[id * 2] * s[id * 2 + 1] ) % MOD;
    }
    void build(LL *A,LL l=0,LL r=n-1){
        a=A;  build(1,l,r); 
        fill(&lzy[0], &lzy[0] + 4 * N, 0);
    }
    
    void updRange(LL st, LL end, LL x, LL id = 1, LL l = 0, LL r = n-1){
        if(lzy[id]){
            s[id] = pii(modularExp(lzy[id], r-l+1), modularExp(lzy[id]-1, r - l + 1));
            if(l!=r){
                lzy[2*id] = lzy[id];
                lzy[2*id+1] = lzy[id];
            }
            lzy[id]=0;          
        }
        if(r<st || l>end)return;
        if(l >= st && r <= end){
            s[id] = pii(modularExp(x, r - l +1), modularExp(x - 1, r - l + 1));
            if(l != r){
                lzy[2*id] = x;
                lzy[2*id+1] = x;
            }
            return;
        }
        LL mid=(l+r)>>1;
        updRange(st, end, x, 2*id, l, mid);
        updRange(st, end, x, 2*id + 1, mid + 1, r);
        s[id] = (s[2*id] * s[2*id + 1]) % MOD;
    }
    pii getRange(LL x,LL y,LL id = 1,LL l = 0,LL r = n-1){
        if(lzy[id]){
            s[id] = pii(modularExp(lzy[id], r - l +1), modularExp(lzy[id] - 1, r - l + 1));
            if(l != r){
                lzy[2*id] = lzy[id];
                lzy[2*id+1] = lzy[id];
            }
            lzy[id]=0;          
        }
        if(r < x || l > y)  return pii(1,1);
        if(l >= x && r <= y)    return s[id];
        
        LL mid = (l+r)>>1; 
        pii sd = (getRange(x, y, id * 2, l, mid) * getRange(x, y, id * 2 + 1, mid+1, r)) % MOD;
        return sd;    
    }    
} t;