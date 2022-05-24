#include<bits/stdc++.h>
using namespace std;
#define max 100
#define inf 10e5

void dijkstra(int g[max][max],int n,int x){
	int cost[max][max],parent[max],dist[max],visited[max];
	int i,j;
	int count=0,nextnode;
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		    if(g[i][j]==0)
			cost[i][j]=inf;
			else cost[i][j]=g[i][j];
		
	    }
    }
    
    for(i=0;i<n;i++){
    	dist[i]=cost[x][i];
    	parent[i]=x;
    	visited[i]=0;
	}
	
	visited[x]=1;
	dist[x]=0;
	count++;
	while(count<n-1){
		int temp=inf;
		for(i=0;i<n;i++){
			if(dist[i]<temp && !visited[i]){
				temp=dist[i];
				nextnode=i;
			}
		}
		
		visited[nextnode]=1;
		for(i=0;i<n;i++){
			if(!visited[i]){
				if(temp+cost[nextnode][i]<dist[i]){
					dist[i]=temp+cost[nextnode][i];
					parent[i]=nextnode;
				}
			}
		}
		
		count++;
		
	}
	for(i=0;i<n;i++){
		cout<<dist[i]<<" ";
	}
	
}

int main()
{int g[max][max],i,j,n,s;
cout<<"Enter the number of nodes:";
cin>>n;
cout<<"Enter the adjacency matrix:";
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		cin>>g[i][j];//inputs for adjacency matrix
		
	}
}
cout<<"Enter Starting node:";
cin>>s;//starting node
dijkstra(g,n,s);

	return 0;
}
