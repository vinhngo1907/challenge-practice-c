#include <stdio.h>
#include "list.h"

#define INFINITE 999999
#define NONE -1234
#define grey 2
#define black 1
#define white 0

typedef struct{
	int x, y;
	int w;
}Edge;

typedef struct{
	int n,m;
	Edge edge[1000];
}Graph;

int pi[101], p[101], mark[101];

void init_graph(Graph *g, int n){
	g->m = 0;
	g->n = n;
}

void add_edge(Graph *g, int x, int y, int w){
	++(g->m);
	g->edge[g->m].x = x;
	g->edge[g->m].y = y;
	g->edge[g->m].w = w;
}

Graph readFromFile(char* filename){
	Graph g;
	int i, n, m, x, y, w;
	
	FILE* f= fopen(filename, "r");
	
	fscanf(f,"%d%d", &n, &m);
	init_graph(&g, n);
	
	for(i=1;i<=m;++i){
		fscanf(f,"%d%d%d", &x, &y, &w);
		add_edge(&g, x, y, w);
	}
	
	fclose(f);
	
	return g;
}

void bellman_ford(Graph g, int s){
	int i, j, x, y, w, n=g.n;
	
	for(i=1;i<=n;++i){
		pi[i]= INFINITE;
		p[i] = NONE;
	}
	
	pi[s]= 0;
	p[s] = -1;
	
	for(i=1;i<n;++i){
		//	xet lan luot qua CAC CUNG
		for(j=1;j<=g.m;++j){
			x= g.edge[j].x;
			y= g.edge[j].y;
			w= g.edge[j].w;
			
			if(pi[x] + w < pi[y]){
				pi[y]= pi[x] + w;
				p[y] = x;
			}
		}
	}
}

void minusCycle(Graph g){
	int i, j, x, y, w, cycle=0;
	for(i=1;i<g.n;++i){
		for(j=1;j<=g.m;++j){
			x= g.edge[j].x;
			y= g.edge[j].y;
			w= g.edge[j].w;
			if(pi[x]+w < pi[y]){
				cycle= x;
			}
		}
	}
	
	if(cycle){
		printf ("%d ", cycle);
		int temp= p[x];
		while(temp!=x){
			printf("%d ", temp);
			char c;
			temp= p[temp];
		}
	}
}

int main(){
	Graph g= readFromFile("dothicotrongso_bai6.txt");
	int i, start= 1, end= 8;
	
	bellman_ford(g, 1);
	
	minusCycle(g);
	
	return 0;
}
