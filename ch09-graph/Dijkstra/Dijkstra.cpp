#include <stdio.h>

#define INF 65535

#define MAX_VERTEX_NUM 100
typedef char VertexType;
typedef int EdgeType;

typedef struct {
	VertexType vertexs[MAX_VERTEX_NUM];
	EdgeType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int numOfVertex;
	int numOfEdge;
}MGraph;

typedef struct EdgeData {
	char start;
	char end;
	int weight;
}EdgeData;

// 迪杰斯特拉算法
// G: 图
// vs: 自定义的起始点索引
// pre: 最短路径情况，每一个点最短路径情况的前一个点的索引
void dijkstra(MGraph G, 
	int vs, 
	int prev[], 
	int dist[])
{
    int i, j, k;
    int min;
    int tmp;
    int flag[MAX_VERTEX_NUM];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。

    // 初始化
    for (i = 0; i < G.numOfVertex; i++)
    {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G.edges[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }

    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;

    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G.numOfVertex; i++)
    {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INF;
        for (j = 0; j < G.numOfVertex; j++)
        {
            if (flag[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G.numOfVertex; j++)
        {
            tmp = (G.edges[k][j] == INF ? INF : (min + G.edges[k][j])); // 防止溢出
            if (flag[j] == 0 && (tmp < dist[j]))
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    printf("dijkstra(%c): \n", G.vertexs[vs]);
    for (i = 0; i < G.numOfVertex; i++)
        printf("  shortest(%c, %c)=%d\n", G.vertexs[vs], G.vertexs[i], dist[i]);
}


#define NUM_OF_VERTEX 7
VertexType g_vertex[NUM_OF_VERTEX] = { 'A','B','C','D','E','F','G' };

EdgeType g_graph[NUM_OF_VERTEX][NUM_OF_VERTEX] = {
    {  0, 12,INF,INF,INF, 16, 14},// 0
    { 12,  0, 10,INF,INF,  7,INF},// 1
    {INF, 10,  0,  3,  5,  6,INF},// 2
    {INF,INF,  3,  0,  4,INF,INF},// 3
    {INF,INF,  5,  4,  0,  2,  8},// 4
    { 16,  7,  6,INF,  2,  0,  9},// 5
    { 14,INF,INF,INF,  8,  9,  0},// 6
};

int main()
{
    // 初始化图
    MGraph G;
    for (int i = 0; i < NUM_OF_VERTEX; i++) {
        for (int k = 0; k < NUM_OF_VERTEX; k++) {
            G.edges[i][k] = g_graph[i][k];
        }
    }
    G.numOfVertex = NUM_OF_VERTEX;
    G.numOfEdge = 12;
    for (int i = 0; i < NUM_OF_VERTEX; i++) {
        G.vertexs[i] = g_vertex[i];
    }

    int S[7] = { 0 };
    int U[7] = { 0 };
    dijkstra(G, 3, S, U);
    return 0;
}