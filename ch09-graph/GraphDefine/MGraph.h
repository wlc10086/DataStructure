#pragma once

#define MaxVertexNum 100

typedef char VertexType;

typedef int EdgeType;

typedef struct {
	VertexType vertexs[MaxVertexNum];			// 点集
	EdgeType edges[MaxVertexNum][MaxVertexNum]; // 边集
	int numOfVertex; // 顶点数
	int numOfEdge; // 边数
}MGraph;

