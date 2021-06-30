#pragma once

#define MAX_VERTEX_NUM 20
typedef char DataType;

// 边类型
typedef struct EdgeType {
	int	VertexIndex;
	struct EdgeType* nextEdge;
}EdgeType;

// 顶点类型
typedef struct VertexType {
	DataType data;
	EdgeType* firstEdge;
}VertexType;


typedef struct {
	VertexType vertexs[MAX_VERTEX_NUM];
}ALGraph;