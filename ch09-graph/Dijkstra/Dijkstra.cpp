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

void dijkstra(MGraph G, 
	int start_node, 
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
        dist[i] = G.edges[start_node][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }

    // 对"顶点vs"自身进行初始化
    flag[start_node] = 1;
    dist[start_node] = 0;

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
    printf("dijkstra(%c): \n", G.vertexs[start_node]);
    for (i = 0; i < G.numOfVertex; i++)
        printf("  shortest(%c, %c)=%d\n", G.vertexs[start_node], G.vertexs[i], dist[i]);
}

int main()
{
	return 0;
}