int x[MAX_NUMBER_OF_NODES][MAX_ASCII_CODE], next = 1; //initially all numbers in x are -1
//add a string to trie
void add(string s){
	int i = 0, v = 0;
	while(i < s.size()){
		if(x[v][s[i]] == -1)
			v = x[v][s[i++]] = next ++;
		else
			v = x[v][s[i++]];
	}
}
// maximize xor 
void del(int s){	
	int i = 0, v = 0, bit, vv;
	for(int i=29;i>=0;i--){
		bit=(s>>i)&1;
		v = x[v][bit];
		val[v]--;
	}
}
int query(int s){
	int i = 0, v = 0, ans = 0;
	for(int i=29;i>=0;i--){
		int bit=(s>>i)&1;
		if(bit == 1){
			if(x[v][0] && val[x[v][0]]){
				ans+=(1<<i);
				v=x[v][0];
			}
			else v=x[v][1];
		}else {
			if(x[v][1] && val[x[v][1]]){
				ans+=(1<<i);
				v=x[v][1];
			}
			else v=x[v][0];
		}
	}	
	return ans;
}

//in main
add(0)