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

// �Ͻ�˹�����㷨
// G: ͼ
// vs: �Զ������ʼ������
// pre: ���·�������ÿһ�������·�������ǰһ���������
void dijkstra(MGraph G, 
	int vs, 
	int prev[], 
	int dist[])
{
    int i, j, k;
    int min;
    int tmp;
    int flag[MAX_VERTEX_NUM];      // flag[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��

    // ��ʼ��
    for (i = 0; i < G.numOfVertex; i++)
    {
        flag[i] = 0;              // ����i�����·����û��ȡ����
        prev[i] = 0;              // ����i��ǰ������Ϊ0��
        dist[i] = G.edges[vs][i];// ����i�����·��Ϊ"����vs"��"����i"��Ȩ��
    }

    // ��"����vs"������г�ʼ��
    flag[vs] = 1;
    dist[vs] = 0;

    // ����G.vexnum-1�Σ�ÿ���ҳ�һ����������·����
    for (i = 1; i < G.numOfVertex; i++)
    {
        // Ѱ�ҵ�ǰ��С��·����
        // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
        min = INF;
        for (j = 0; j < G.numOfVertex; j++)
        {
            if (flag[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                k = j;
            }
        }
        // ���"����k"Ϊ�Ѿ���ȡ�����·��
        flag[k] = 1;

        // ������ǰ���·����ǰ������
        // �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
        for (j = 0; j < G.numOfVertex; j++)
        {
            tmp = (G.edges[k][j] == INF ? INF : (min + G.edges[k][j])); // ��ֹ���
            if (flag[j] == 0 && (tmp < dist[j]))
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // ��ӡdijkstra���·���Ľ��
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
    // ��ʼ��ͼ
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