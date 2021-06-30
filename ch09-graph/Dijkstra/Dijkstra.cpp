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
    int flag[MAX_VERTEX_NUM];      // flag[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��

    // ��ʼ��
    for (i = 0; i < G.numOfVertex; i++)
    {
        flag[i] = 0;              // ����i�����·����û��ȡ����
        prev[i] = 0;              // ����i��ǰ������Ϊ0��
        dist[i] = G.edges[start_node][i];// ����i�����·��Ϊ"����vs"��"����i"��Ȩ��
    }

    // ��"����vs"������г�ʼ��
    flag[start_node] = 1;
    dist[start_node] = 0;

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
    printf("dijkstra(%c): \n", G.vertexs[start_node]);
    for (i = 0; i < G.numOfVertex; i++)
        printf("  shortest(%c, %c)=%d\n", G.vertexs[start_node], G.vertexs[i], dist[i]);
}

int main()
{
	return 0;
}