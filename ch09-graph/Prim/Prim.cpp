#include "../GraphDefine/MGraph.h"
#include <algorithm>
#define INF 65535

#include <vector>
using namespace std;

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

// 
void Prim(MGraph* G, int bn)
{
    vector<int> U;
    vector<int> VU;
    int sumOfWeight = 0;

    // 初始化赋值数组
    U.push_back(bn);
    for (int i = 0; i < G->numOfVertex; i++) {
        if (i != bn) {
            VU.push_back(i);
        }
    }

   

    while (VU.size() > 0) {
        
        int  min_i = 0;
        int  min_k = 0;
        int min_weight = INF;

        for (auto it_u = U.begin(); it_u != U.end(); ++it_u) {

            for (auto it_vu = VU.begin(); it_vu != VU.end(); ++it_vu) {

                if (min_weight > G->edges[*it_vu][*it_u]) {
                    min_weight = G->edges[*it_vu][*it_u];
                    
                    min_k = *it_vu;
                    min_i = *it_u;
                }
           }
        }

        sumOfWeight += min_weight;
        printf("(%c, %c)\n",  g_vertex[min_i], g_vertex[min_k]);
        

        auto it = find(VU.begin(), VU.end(), min_k);
        VU.erase(it);

        U.push_back(min_k);
    }
    printf("总权值为: %d\n", sumOfWeight);
}

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

    // 
    Prim(&G, 0);
    return 0;
}