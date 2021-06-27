#pragma once

#define MAX_VERTEX_NUM 20
typedef char DataType;

typedef struct ArcType {
	int tailVertex, headVertex;
	struct ArcType* tailLink, * headLink;
	int Weight; 
}ArcType;

typedef struct VertexType {
	DataType data;
	ArcType* firstIn;
	ArcType* firstOut;
}VertexType;

typedef struct {
	VertexType vertexs[MAX_VERTEX_NUM];
	int numOfVertex;
	int numOfArc;
}OLGraph;