#pragma once

#define MAX_VERTEX_NUM 20
typedef char DataType;

// ������
typedef struct EdgeType {
	int	VertexIndex;
	struct EdgeType* nextEdge;
}EdgeType;

// ��������
typedef struct VertexType {
	DataType data;			// 
	EdgeType* firstEdge;
}VertexType;


typedef struct {
	VertexType vertexs[MAX_VERTEX_NUM];
}ALGraph;