#pragma once

#define MAXTREESIZE 100
typedef char DataType;

typedef struct {
	DataType data;
	int parent;
}PTreeNode;

typedef struct {
	PTreeNode nodes[MAXTREESIZE];
	int nodeCount;
	int root;
}PTree;


typedef struct CTNode {
	int child;
	struct CTNode* next;
}*ChildPtr;

typedef struct {
	DataType data;
	ChildPtr firstChild;
}CTBox;

typedef struct {
	CTBox nodes[MAXTREESIZE];
	int n, r;
}CTree;