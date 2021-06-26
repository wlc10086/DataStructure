# 1  定义
**树（Tree）**是n（n>=0）个结点的有限集（记为T），当n=0时称为空树，在任意一棵非空树中：

* 有且仅有一个结点没有前驱，称为根节点（Root）
* 当n>1时，其余结点可分为m（m>0）个**互不相交**的有限集T1、T2、.....、Tm，其中每一个集合本身又是一棵树，并且称为根的子树（SubTree）  
![错误树结构展示](..\images\ch08-01-01.jpg)  

**树的基本术语：**
(1)树中每一个元素（图中的圆点）称为**树的结点**。
**<font clolor=red>结点拥有的子树数目</font>**称为**结点的度**（Degree），**整棵树的度**取树内**各结点的度的最大值**。
--度为0的结点称为**叶子结点**（Leaf）或**终端结点**
--度不为0的结点称为**分支结点**或非终端结点，除根结点外，分支结点也称为**内部结点**。   
![](..\images\ch08-01-02.png)  


(2)孩子(Child)和双亲(Parent)
结点的子树的根称为结点的孩子（Child），相应的，该结点称为孩子的双亲（Parent），同一双亲的孩子之间互称为兄弟（Sibling），其双亲兄弟的孩子称为堂兄弟。

(3)**结点的层次和高度**
树中结点的最大层次称为树的深度（Depth）或高度。（含跟节点，上图中树的深度或高度为3）

(4)如果将树中结点的各子树看成从左至右是有次序的，不能互换的，则称该树为有序树，否则称为无序树。

(5)**森林**是m（m>=0）棵互不相交的树的集合。对树中每个结点而言，其子树的集合即为森林。



# 2 树的抽象数据类型
```c
ADT Tree{ 
Data：
    D是具有相同特性的数据元素的集合。  
数据关系R： 
    若D为空集，则称为空树； 
    若D仅含有一个数据元素，则R为空集，否则R={H}，H是如下二元关系： 
      (1) 在D中存在唯一的称为根的数据元素root，它在关系H下无前驱；  
      (2) 若D-{root}≠NULL，则存在D-{root}的一个划分D1，D2，D3， „，Dm(m>0)，对于任意j≠k(1≤j，k≤m)有Dj∩Dk=NULL，且对任意的i(1≤i≤m)，唯一存在数据元素xi∈Di有<root，xi>∈H; 
      (3) 对应于D-{root}的划分，H-{<root，xi>，„，<root，xm>}有唯一的一个划分H1，H2，„，Hm(m>0)，对任意j≠k(1≤j，k≤m)有Hj∩Hk=NULL，且对任意i(1≤i≤m)，Hi是Di上的二元关系，(Di，{Hi})是一棵符合本定义的树，称为根root的子树。 
    
基本操作P： 
  InitTree(&T); 
    操作结果：构造空树T。
  DestroyTree(&T); 
    初始条件：树T存在。 操作结果：销毁树T。 
  CreateTree(&T，definition); 
    初始条件：definition给出树T的定义。 操作结果：按definition构造树T。 
  ClearTree(&T); 
    初始条件：树T存在。 操作结果：将树T清为空树。 
  TreeEmpty(T); 
    初始条件：树T存在。 操作结果：若T为空树，则返回TRUE，否则返回FALSE。 
  TreeDepth(T); 
    初始条件：树T存在。 操作结果：返回Ｔ的深度。 
  Root(T); 
    初始条件：树T存在。 操作结果：返回T的根。 
  Value(T，cur_e); 
    初始条件：树T存在，cur_e是T中某个结点。 操作结果：返回cur_e的值。 
  Assign(T，cur_e，value); 
    初始条件：树T存在，cur_e是T中某个结点。 操作结果：结点cur_e赋值为value。 
  Parent(T，cur_e); 
    初始条件：树T存在，cur_e是T中某个结点。 
    操作结果：若cur_e是T的非根结点，则返回它的双亲，否则函数值为“空”。 
  LeftChild(T，cur_e); 
    初始条件：树T存在，cur_e是T中某个结点。 
    操作结果：若cur_e是T的非叶子结点，则返回它的最左孩子，否则返回“空”。 
  RightSibling(T，cur_e); 
    初始条件：树T存在，cur_e是T中某个结点。 
    操作结果：若cur_e有右兄弟，则返回它的右兄弟，否则返回“空”。 
  InsertChild(&T，&p，I，c); 
    初始条件：树Ｔ存在，ｐ指向Ｔ中某个结点，1≤i≤p指结点的度＋１，非空树ｃ与Ｔ不相交。 
    操作结果：插入c为Ｔ中ｐ指结点的第ｉ棵子树。 
  DeleteChild(&T，&p，i); 
    初始条件：树T存在，p指向T中某个结点，1≤i≤p指结点的度。
    操作结果：删除Ｔ中ｐ所指结点的第ｉ棵子树。 
  TraverseTree(T，visit()); 
    初始条件：树T存在，visit是对结点操作的应用函数。 
    操作结果：按某种次序对T的每个结点调用函数visit()一次且至多一次。一旦visit()失败，则操作失败。
}ADT Tree
```

在双亲表存储结构中添加以下基本抽象数据类型： 
`Status Print(PTree T);` 
附加函数：用于显示树的所有内容。 初始条件：树T存在； 
操作结果：将树T的所有结点显示出来。 
在双亲表存储结构中，`TraverseTree(T，visit())`函数是按层次次序对T的每个结点进行访问的。

# 3 树的表示 
树的逻辑表示方法有多种，常见以下4种：  
1）树形图表示法  
2）嵌套集合表示发（文氏图表示法）  
3）凹入表示法  
4）广义表表示法  
![树的表示方法](..\images\ch08-03-01.png)  

# 4 树的存储结构
  **树的顺序存储**适合**树中结点比较“满”的情况**，例如满二叉树或者完全二叉树或则其他比较满的树，**对于一般的树用顺序存储结构是非常浪费存储空间的**。在实际应用中，常用链式存储方式来表示树。
树的常用存储方法有：双亲存储方式、孩子链表表示法和孩子兄弟链表表示法。
<font color=red>（注意：存储结构的设计是不固定的，在不同实际应用情况使用不同存储结构，这里只是参考而已)</font>

## 4.1 双亲存储表示法
双亲存储表示法（parent tree）一般采用顺序存储结构实现。即用一组连续的存储空间来存储树的结点，每个结点包括数据元素的值本身和指向结点双亲位置的指针（伪指针）。双亲存储表示法的定义如下：  
![](..\images\ch08-04-01.png)  

```c
#define MAXTREESIZE 100
typedef char DataType;
typedef struct
{
   DataType  data;  //结点数据域
   int   parent; //双亲位置(伪指针)
}PTreeNode;

typedef struct
{
   PTreeNode   nodes[MAXTREESIZE];
   int   node_count;  //结点总数n 
   int  root; // 根结点的位置r
}PTree;
```
* 优点：容易计算出结点的双亲甚至祖先
* 缺点：难以获取结点的孩子结点(需遍历)

## 4.2 孩子链表表示法
孩子链表表示法（child tree）是把树中每个结点的孩子都排列起来，组成一个线性表，即孩子链表。  
![](..\images\ch08-04-02.png)  
```c
typedef struct CTNode  // 孩子链表节点
{ 
  int child; //孩子的下标
    Struct CTNode *next; // 下一个孩子
}* ChildPtr;

typdef struct    //表头结点
{
  ElemType data;      // 存放结点中的数据
  ChildPtr firstchild;// 指向第一个孩子的指针
}CTBox;

typedef struct
{
  CTBox nodes[MaxTreeSize];
int n，r;//树的结点数n和根结点的位置r
}CTree;
```
--优点：易于实现孩子以及后代的运算
--缺点：与双亲结点的运算非常麻烦（需从头遍历）


## 4.3 双亲孩子链表存储
解决上述孩子链表表示法的缺点，结合双亲存储表示法的特点，提出下面的存储方式—— 双亲孩子链表存储方式（parent child tree）。(仅供参考)   
![](..\images\ch08-04-03.png)  
```c
typdef struct 
{
  ElemType data; // 存放结点中的数据
  int   parent;  // 存放双亲结点索引
  ChildPtr firstchild;// 指向第一个孩子的指针
}PCTreeNode;

typedef struct PCNode{ 
    int child; //孩子的下标
    Struct PCNode *next; // 下一个孩子
}*ChildPtr;

typedef struct
{
  PCTreeNode nodes[MaxTreeSize];
  int n，r;//树的结点数n和根结点的位置r
}PCTree;
```

## 4.4 孩子兄弟表示法
孩子兄弟表示法（child Sibling tree）也是树的一种链式存储结构。这种方法是为了每个结点设计3个域：  
一个数据域，两个指针域。其中一个指针域指向该结点的第一个孩子结点，另一个指向该结点下一个兄弟结点。  
![](..\images\ch08-04-04.png)  

孩子兄弟链表存储结构定义如下：

```c
typedef struct CSNode
{
    ElemType data;
    Struct CSNode *firstchild; // 第一个孩子结点
    Struct CSNode *nextsibling; // 下一个兄弟结点
}CSNode, *CSTree;
```
* 优点：可以方便地实现树和二叉树的相互转换和树的各种操作  
* 缺点：查找当前结点的双亲结点比较麻烦，需要从树的跟结点逐个比较查找

