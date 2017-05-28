

int dfs0(int u,int pv){
	dep[u]=0;
	int x,temp;
	for(auto v:T[u]){
		if(v==pu)continue;
		temp = dfs0(v,u);
		if(uax(dep[u],dep[v]+1))
			x=temp;
	}
	return x;
}




int main(int argc, char const *argv[])
{



	oneEnd = dfs0(i,-1);  
	otherEnd = dfs0(oneEnd,-1);  //  cout<<oneEnd<<' '<<otherEnd<<endl;
	d[i]=dep[otherEnd]; // d - diameter

	return 0;
}
