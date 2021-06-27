#pragma once

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct {
	VertexType vertexs[MaxVertexNum];
	EdgeType edges[MaxVertexNum][MaxVertexNum];
	int numOfVertex; // ¶¥µãÊý
	int numOfEdge; // ±ßÊý
}MGraph;

