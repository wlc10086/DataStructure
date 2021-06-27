**图（Graph）**是由顶点的有穷非空集合和顶点之间边的集合组成，通常表示为：G（V，E），其中G表示一个图，V是图G中**顶点的集合**，E是图G中**边的集合**。

翻译：

边：Edge

弧：Arc

顶点：vertex

图：graph

需要注意的几个地方：

-- 线性表中我们把数据元素叫**元素**，树中叫**结点**，在图中数据元素我们称之为**顶点(Vertex)**

-- 线性表中，相邻的数据元素之间具有线性关系，树结构中，相邻两层的结点具有层次关系，而图结构中，任意两个顶点之间都可能有关系，顶点间的逻辑关系用边来表示，边集可以是空的。

1 图的定义和术语

**无向边(Edge)**：若顶点Vi到Vj之间的边没有方向，则称这条变为无向边，用无序偶（Vi，Vj）来表示。

**有向边(Arc)**：若从顶点Vi到Vj的边有方向，则称这条边为有向边，也称为**弧(Arc)**，用有序偶 <Vi，Vj> 来表示，Vi称为弧尾，Vj称为**弧头（箭头为头）**。 

**简单图：**不存在顶点到其自身的边，且同一条边不重复出现。

**无向完全图：**在无向图中，如果任意两个顶点之间都存在边。含有n个顶点的无向完全图有n*(n-1)/2条边。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1.png)

**有向完全图：**如果任意两个顶点之间都存在互为相反的两条弧。含有n个顶点的有向完全图有n*(n-1)条边。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_2.png)

**稀疏图和稠密图：**这里的稀疏和稠密是模糊概念，都是相对而言的，通常认为边或弧数小于n*logn(n是顶点的个数)的图称为稀疏图，反之称为稠密图。

有些图的边或弧带有与它相关的数字，这种与图的边或弧相关的数叫做**权(weight)**，这种带权的图通常称为**网(network)**

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_3.png)

**子图(subgraph)：**假设有两个图G1 =(V1，E1)和G2=(V2，E2)，如果V2≦V1且E2≦E1，则称G2是G1的子图。

**顶点的度**

无向图中，若有边(Vi，Vj)，则称Vi与Vj互为邻接点，(Vi，Vj)是与顶点Vi和Vj相关联的边。与顶点相关联边的条数，称为**顶点的度**。

有向图中，以顶点Vi为弧尾的弧个数，称为**顶点Vi的出度**，记为OD(Vi)，以顶点Vi为弧头的弧个数称为**顶点Vi的入度**，记为ID(Vi)。顶点Vi的度=OD(Vi)+ID(Vi)。

 

2 图的存储结构

2.1 **邻接矩阵(MGraph)**

**基本思想：对于有n个顶点的图，用一维数组vexs[n]存储顶点信息，用二维数组A[n][n]存储顶点之间关系的信息。该二维数组称为邻接矩阵。**在邻接矩阵中，以顶点在vexs数组中的下标代表顶点，邻接矩阵中的元素A[i][j]存放的是顶点i到顶点j之间关系的信息。

2.1.1 无向邻接矩阵

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/a059b039-bccd-443d-864b-23ecd72161c9.jpg)2.1.2 有向邻接矩阵![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/115b97d0-4011-4602-b637-acaef5709482.jpg)

 

```
#define MaxVertexNum 100 // 最大顶点数，应由用户定义 
typedef char VertexType; // 顶点类型
typedef int EdgeType;  // 边上的权值类型
 
typedef struct
{
    VertexType vexs[MaxVertexNum]; // 顶点表
    EdgeType edges[MaxVertexNum][MaxVertexNum];// 邻接矩阵，可看作边表
    int n,e; // 图中当前的顶点数和边数
}MGragh;
```

2.2 **邻接表**和**逆连接表**

**邻接表(Adjacency List)**是图的一种链式存储结构，它既可以存放有向图也可以存放无向图。

它关注的是点。结构定义如下：

 

```
#define MAX_VERITEX_NUM 20
typedef char VertexType;    // 顶点数据类型
// 弧结构
typedef struct ArcNode
{
    int adjVex;                // 该弧所指向的顶点位置
    struct ArcNode  *nextArc;  // 指向下一条弧的指针
    InfoType        *info;     // 该弧相关信息的指针（如权值等）
}ArcNode;
// 顶点结构
typedef struct VNode
{
    VertexType    data;             // 顶点信息
    ArcNode      *firstArc;         // 指向第一条依附该顶点的弧的指针
}VNode;
// 邻接表结构
typedef struct
{
    VNode    vetices[MAX_VERITEX_NUM];
    int      vexNum,arcNum;   // 当前顶点数和弧数
    int      kind;            // 图的种类标志
}ALGraph;
```

**2.2.1 无向邻接表**

图中顶点用一个一维数组存储，当然，顶点也可以用单链表来存储，不过数组可以较容易地读取顶点信息，更加方便。图中每个顶点Vi的所有邻接点构成一个线性表，由于邻接点的个数不确定，所以我们选择用单链表来存储。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_4.png)

**2.2.2 有向图的邻接表**

若是有向图，邻接表结构也是类似的，把定点当弧尾建立的邻接表，这样容易得到每个顶点的出度。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_5.png)

对于**带权值**的网图，可以在边表结点定义中再增加一个数据域来存储权值即可。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_7.png)

**2.2.3 有向图的逆邻接表**

有时为了确定顶点的入度或以顶点为弧头的弧，我们可以建立一个有向图的逆邻接表。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_6.png)

**2.3 十字链表（有向图）**

  **十字链表**是**有向图**的另一种存储结构。可以看成是将**有向图**的邻接表和逆链接表结合起来得到的一种链表。

  在十字链表中，对应于有向图中每一条弧有一个结点，对应于每个顶点也有一个结点。这些**顶点**的结构如下：

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_8.png)

边表结点结构：

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_9.png)

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_10.png)

 

```
#define MAX_VERITEX_NUM 20
typedef int InfoType;
typedef char VertexType;
typedef struct _ArcBox{
    int        tailVex,headVex;        // 该弧的尾和头顶点的位置（箭头为头）
    struct _ArcBox *hLink, *tLink;    // 分别为弧头相同和弧尾相同的弧的链域
    InfoType    *info;                // 该弧相关信息的指针
}ArcBox;
typdef struct _VexNode{
    VertexType     data;
    ArcBox         *firstIn, *firstOut; // 分别指向该顶点第一条入弧和出弧
}VexNode;
 
typedef struct{
    VexNode xList[MAX_VERITEX_NUM];    // 表头向量
    int        vexNum,arcNum；        // 顶点数和弧数
}OLGraph;
```

**2.4 邻接多重表（无向图）**

邻接多重表是**无向图**的另一种链式存储结构。和十字链表类似，每一条边用一个结点表示，它由6个域组成：

 

```
#define MAX_VERITEX_NUM 20
typedef enum {unvisited, visited} VisitIf;
typedef struct EBox{
    VisitIf        mark;            // 访问标记
    int            ivex,jvex;        // 该边依附的两个顶点的位置
    struct EBox *ilink,*jlink;    // 分别指向依附这两个顶点的下一条边
    InfoType    *info;            // 该边信息指针
}EBox;
 
typedef struct VexBox{
    VertexType data;
    EBox        *firstedge;        // 指向第一条依附该顶点的边
}VexBox;
 
typedef struct{
    VexBox    adjmulist[MAX_VERITEX_NUM];
    int        vexnum,edjenum;        // 无向图的当前顶点数和边数
}AMLGraph;
```

**3 图的遍历**

从图的某一个顶点出发访遍途中的其余顶点，且使每一个顶点仅被访问一次，这一过程叫做图的遍历。

**3.1 深度优先遍历（DFS）**

该方法类似于树的前序遍历，利用**栈**来实现。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_11.png)

**3.1.1 马踏棋盘算法**

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/41852218-51ef-4a9f-af30-daa9415481d3.jpg)

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/2ae7477f-7e5d-4274-9d36-79e4275461c7.jpg)

一个棋，在一个方格上，最多有8种走法，在整个64个放个的棋盘中，就有8^64次。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/c5619fa3-a9a2-473d-9114-8289312e6f99.jpg)

 

```
#include <stdio.h>
#include <time.h>
#define X 8
#define Y 8
// 棋盘
int chess[X][Y];
#define NEXT_XY_CHECK(a,b)    if(*x+a >=0 && *x+a <= X-1 && *y+b>=0 && *y+b<=Y-1 && chess[*x+a][*y+b] == 0){ \
                                 *x+= a ; *y+= b; \
                                 return 1; \
                              } \
// 找到基于(x,y)位置的下一个可走的位置
// 一个方格里面，最多有8种下一步的走法
int nextxy(int* x, int* y, int count)
{
    switch (count)
    {
    case 0: NEXT_XY_CHECK(-1, -2); break;
    case 1: NEXT_XY_CHECK(1, -2); break;
    case 2: NEXT_XY_CHECK(2, -1); break;
    case 3: NEXT_XY_CHECK(2, 1); break;
    case 4: NEXT_XY_CHECK(1, 2); break;
    case 5: NEXT_XY_CHECK(-1, 2); break;
    case 6: NEXT_XY_CHECK(-2, 1); break;
    case 7: NEXT_XY_CHECK(-2, -1); break;
    }
    return 0;
}
// 遍历棋盘（深度优先）
// (x,y) - 起始位置
// tag是标记变量，每走一步，tag+1
int TravelChessBoard(int x, int y, int tag)
{
    int x1 = x, y1 = y, flag = 0, count = 0;
    chess[x][y] = tag;
    if (X * Y == tag){  // 结束
        return 1;
    }
    flag = nextxy(&x1, &y1, count);
    while (0 == flag && count < 7) {
        count++;
        flag = nextxy(&x1, &y1, count);
    }
    // 找到马的下一个可走坐标(x1,y1),如果找到flag=1，否则为0
    while (flag) {
        // 先递归，深度优先
        if (TravelChessBoard(x1, y1, tag + 1)) {
            return 1;
        }
        // 继续找到马的下一步可走的坐标(x1,y1),如果找到flag=1，否则为0
        x1 = x;
        y1 = y;
        count++;
        flag = nextxy(&x1, &y1, count);
    }
    // 如果当前方式所有下一步都无效，当前方格的标签重置为0
    if (0 == flag) {
        chess[x][y] = 0;
    }
    return 0;
}
void print()
{
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            printf("%2d\t", chess[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    // 
    clock_t start, finish;
    start = clock();
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            chess[i][j] = 0;
        }
    }
    
    // 
    if ( TravelChessBoard(4, 4, 1) == 0) {
        printf("抱歉，就马踏棋盘失败了\n");
    }
    finish = clock();
    printf("耗时: %f\n", double(finish - start)/CLOCKS_PER_SEC);
    print();
    return 0;
}
```

**3.2 广度优先遍历（BFS）**

类似于树的层序遍历，要实现对图的广度遍历，可以利用**队列**来实现。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/e48c4c07-4a95-4d6d-a0e5-6ca74aee1184.jpg)

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_12.png)

![img]()

**4 最小生成树**

给定一个带权的无向连通图，如何选取一棵生成树，使树上所有边上权的总和为最小，这叫**最小生成树.**

**4.1 普里姆算法**

**4.2 克鲁斯卡尔算法**

**5 最短路径**

在网图和非网图中，最短路径的含义是不同的。

  \- 网图是两顶点经过的边上权值之和最小的路径。

  \- 非网图是两顶点之间经过的边数最少的路径。

把路径起始的第一个顶点称为源点，最后一个顶点称为终点。

**5.1 迪杰斯特拉算法** 

迪杰斯特拉算法求的是一个顶点到所有顶点的最短路径。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/a45e6582-ff0e-41da-9057-2dd9a41c818e/128/index_files/1_13.png)

该算法不是一下子就求出V0~V8的最短距离，而是一步步求出它们之间顶点的最短路径，过程中都是基于已经求出的最短路径的基础上，求得更远顶点的最短路径，最终得到需要的结果。

**5.2 弗洛伊德算法**

弗洛伊德算法是求所有顶点到所有顶点的最短路径。