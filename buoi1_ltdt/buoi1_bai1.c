#include <stdio.h>

#define MAX_V 101
#define MAX_E 101

typedef struct{
	int n, m; // n: so dinh, m: so cung
	
	//Bang luu quan de lien thuoc dinh cung
	int A[MAX_V][MAX_E];
}Graph;

/*	Khai bao ham	*/
void init_graph(Graph*, int, int);
void add_edge(Graph*, int ,int, int);
int adjacent(Graph, int, int);
int degree(Graph, int);

int main(){
	Graph G;
	int n = 4, m = 5, v;
	init_graph(&G, n, m);
	add_edge(&G, 1, 1, 2);
	add_edge(&G, 2, 1, 3);
	add_edge(&G, 3, 1, 3);
	add_edge(&G, 4, 3, 4);
	add_edge(&G, 5, 1, 4);
	for (v = 1; v <= n; v++)
	printf("deg(%d) = %d\n", v, degree(G, v));
	return 0;
}

void init_graph(Graph* g, int n, int m){
	g->m = m; g->n= n;
	
	int i, j;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			g->A[i][j]= 0;
		}
	}
}

void add_edge(Graph* g, int e,int x, int y){
	g->A[x][e] = 1;
	g->A[y][e] = 1;
}

int adjacent(Graph g, int x, int y){
	int e;
	for(e=1;e<=g.m;++e){
		if(g.A[x][e] && g.A[y][e]) return 1;
	}
	return 0;
}

int degree(Graph g, int x){
	int e, deg= 0;
	for(e=1;e<=g.m;++e){
		if(g.A[x][e]) ++deg;
	}
	return deg;
}
