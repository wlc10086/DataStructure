#pragma once

#define MaxVertexNum 100

typedef char VertexType;

typedef int EdgeType;

typedef struct {
	VertexType vertexs[MaxVertexNum];			// �㼯
	EdgeType edges[MaxVertexNum][MaxVertexNum]; // �߼�
	int numOfVertex; // ������
	int numOfEdge; // ����
}MGraph;

