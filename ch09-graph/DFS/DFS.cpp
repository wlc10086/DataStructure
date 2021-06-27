#include "../GraphDefine/MGraph.h"
#include <stack>
#include <set>
#include <vector>
using std::stack;
using std::set;
using std::vector;

VertexType g_vertex[8] = {'a','b','c','d','e','f','g','h'};

EdgeType g_graph[8][8] = {
	{0,1,0,1,1,0,0,0},// 0
	{1,0,1,0,1,0,0,0},// 1
	{0,1,0,0,0,1,0,0},// 2
	{1,0,0,0,0,0,1,0},// 3
	{1,1,0,0,0,0,1,0},// 4
	{0,0,1,0,0,0,0,0},// 5
	{0,0,0,1,1,0,0,1},// 6
	{0,0,0,0,0,0,1,0} // 7
};


set<VertexType> gs_tag;
vector< VertexType> gs_vector;

void DFS_list(MGraph* g, int first, int second) {
	
	for (int i = second; i < g->numOfVertex; i++) {

		if (g->edges[first][i] == 0) {
			continue;
		}

		// 
		if (gs_tag.find(g->vertexs[i]) == gs_tag.end()) {
			gs_tag.insert(g->vertexs[i]);
			gs_vector.push_back(g_vertex[i]);

			// 深度优先
			DFS_list(g, i, 0);
		}

	}
}

void DFS_simple(MGraph *g) {

	// 需要一个标记符号，来标记该顶点是否访问过
	// 这里采用栈的方法来记录，
	// 如果采用其他结构存储，可以在顶点添加一个标记符作为访问标记

	gs_tag.insert(g->vertexs[0]);
	gs_vector.push_back(g_vertex[0]);

	DFS_list(g, 0, 1);

	// 顺序打印出来
	for (auto it = gs_vector.begin(); it != gs_vector.end(); ++it) {
		printf("%c ", *it);
	}
}


void BFS(MGraph* g) {

}

int main()
{
	MGraph g;
	g.numOfEdge = 9;
	g.numOfVertex = 8;
	for (int i = 0; i < g.numOfVertex; i++) {
		for (int j = 0; j < g.numOfVertex; j++) {
			g.edges[i][j] = g_graph[i][j];
		}
	}
	for (int i = 0; i < g.numOfVertex; i++) {
		g.vertexs[i] = g_vertex[i];
	}

	// 根据概念自己写的算法
	DFS_simple(&g);
}