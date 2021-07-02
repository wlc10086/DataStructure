#include "../GraphDefine/MGraph.h"
#include <stdio.h>

#define INF 65535

#define NUM_OF_VERTEX 6
VertexType g_vertex[NUM_OF_VERTEX] = { 'A','B','C','D','E','F' };

EdgeType g_graph[NUM_OF_VERTEX][NUM_OF_VERTEX] = {
    {  0,  7,INF,INF,  1,  6},// 0
    {  7,  0,  2,  4,  8, 13},// 1
    {INF,  2,  0,  9,  3,INF},// 2
    {INF,  4,  0,  9,INF,INF},// 3
    {  1,  8,  3,INF,  0,  3},// 4
    {  6, 13,INF,INF,  3,  0},// 5
};

int min(int a, int b) {
    return a < b ? a : b;
}

void Floyd(MGraph *G)
{
    for (int k = 0; k < G->numOfVertex; k++) {
        for (int i = 0; i < G->numOfVertex; i++) {
            for (int j = 0; j < G->numOfVertex; j++) {
                G->edges[i][j] = min(G->edges[i][j], G->edges[i][k] + G->edges[k][j]);
            }
        }
    }
}

int main()
{
    // ³õÊ¼»¯Í¼
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
    Floyd(&G);

    for (int i = 0; i < G.numOfVertex; i++) {
        for (int j = 0; j < G.numOfVertex; j++) {
            printf("%d\t", G.edges[i][j]);
        }
        printf("\n");
    }
    return 0;
}