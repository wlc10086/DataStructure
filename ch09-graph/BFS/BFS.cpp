#include "../GraphDefine/MGraph.h"

#include <algorithm>    // std::find
#include <vector>
#include <list>
using namespace std;

#define NUM_OF_VERTEX 8
VertexType g_vertex[NUM_OF_VERTEX] = { 'a','b','c','d','e','f','g','h' };

EdgeType g_graph[NUM_OF_VERTEX][NUM_OF_VERTEX] = {
	{0,1,0,1,1,0,0,0},// 0
	{1,0,1,0,1,0,0,0},// 1
	{0,1,0,0,0,1,0,0},// 2
	{1,0,0,0,0,0,1,0},// 3
	{1,1,0,0,0,0,1,0},// 4
	{0,0,1,0,0,0,0,0},// 5
	{0,0,0,1,1,0,0,1},// 6
	{0,0,0,0,0,0,1,0} // 7
};

vector<VertexType> g_vector;
list<VertexType> g_list;
// 广度优先遍历
// g： 图
// begin: 出发点的索引
void BFS(MGraph* g, int begin) {
	
	g_list.push_back(begin);
	
	// 出一个，然后对这个点直接关联的点进行遍历，并把没进过队列的点入队
	while (g_list.size() > 0) {
		
		int index = g_list.front();
		g_list.pop_front();
		g_vector.push_back(index);
		
		for (int i = 0; i < NUM_OF_VERTEX; i++) {
			// 不在队列和数组中点，入队
			if (g->edges[index][i] != 0) {
				auto it1 = find(g_list.begin(), g_list.end(), i);
				auto it2 = find(g_vector.begin(), g_vector.end(), i);

				if (it1 == g_list.end() && it2 == g_vector.end()) {
					g_list.push_back(i);
				}
			}
		}
	}

	// 顺序打印出来
	for (auto it = g_vector.begin(); it != g_vector.end(); ++it) {
		printf("%c ", g_vertex[*it]);
	}
}



int main()
{
	// 初始化一个图
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

	BFS(&g, 0);

}