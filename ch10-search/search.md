**查找表（****Search Table****）是由同一类型的数据元素构成的集合。由于“集合”中的数据元素之间存在着完全松散的关系，因此查找表是一种非常灵活的数据结构。**

---根据查过过程是否需要对标进行操作进行分类：

**静态查找：**数据集合稳定，不需要添加，删除元素的查找操作。

**动态查找：**数据集合在查找的过程中需要对表做修改操作（如添加或删除元素的查找操作）

# **一** **静态查找表**

**静态查找表**在查找的过程中不改变表的状态——不插不删。他适合用于不变动或不常变动的表的查找。如高考成绩表、本单位职工信息表等。下面分别介绍**顺序查找**，**有序表的折半查找**，**静态树表的查找**。

**1.1** **顺序表的查找**

从表的一端开始，逐个把每条记录的关键字值与给定值k进行比较。若某个记录关键字值与给定值k相等，则查找成功，返回找到的记录位置。反之，若已查找到表的另一端，仍未找到关键字值与给定值相等，则查找不成功，返回0.**算法复杂度：****O(n)****。**

 

```
//常规例子
// R - 表
// n - 表的大小
// key - 待对比的关键字
int SqSearch(ElemType R[],int n,ElemType key){
   for(int i=1;i<=n;i++){
      if(key == R[i]){
          return i;
      }
   }
   return 0;
}
```

**1.2** **有序表的查找**

**折半查找（二分查找）**

如果查找表已经按关键字（递增或递减）排好序，可以采用二分查找法进行查找（这是一种特殊的按比例查找）。注意：

1.只适用于已经排好的顺序表

2.二分查找只适用于顺序存储结构，不适用于线性链表结构。二分查找特别适用于那种一经建立就很少改动，而又经常需要查找的线性表。

算法复杂度：O(n)

 

```
// R - 已排序的顺序表
// n - 表的大小
// key - 待比较的关键字
int BinSearch(ElemType R[],int n,ElemType key){
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(R[mid] == key)
            return mid;
        else if(R[mid]>key)
            high = mid -1;
        else
            low = high +1;
    }
    return -1;
}
```

**1.3 按值查找（按比例查找）**

和折半查找算法类型，区别是折半查找是每次和中间值比较，折去一半，而按值查找则根据数在查找段可能的位置进行定位。**(还是基于有序序列的查找)**

**优点：**在数据分布均匀的线性表中查询，性能比折半查找高

**缺点：**当数据分布极端不均匀，性能会比折半查找低

 

```
int ValueSearch(ElemType R[],int n,ElemType key)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        // 计算比例
        mid = ((key - R[low])/(R[high] - R[low]))*(high-low) + low;
        if(R[mid] == key)
            return mid;
        else if(R[mid]>key)
            high = mid -1;
        else
            low = high +1;
    }
    return -1;
}
```

**1.4 斐波那契查找（黄金比例查找 0.618：1）**

**1.6 分块查找**

**分块查找**又称为**索引顺序查找，**或者**线性索引查找**，这是顺序查找的一种改进方法。

首先把表长为n的线性表分成b块，前b-1块记录个数为s=n/b，第b块的记录个数小于等于s。在每一块中，结点的存放不一定有序，但块与块之间必须分块有序（假定按结点的关键值递增有序），即指后一块中所有记录的关键字值有应比前一块中所有记录的关键字值大。

为实现分块检索，还需要建立一个索引表，索引表每个元素对应一个块，其中包括该块内最大关键字值和块中第一个记录位置的地址指针。显然这个索引顺序表是一个递增有序表。

 

```
//索引表结点的数据结构
# define MaxIndex n
typedef struct
{
    KeyType key;
    int link;
}IdxType;
//原顺序表A,索引表index,分块数b,查找关键字k,顺序表A大小n
int IndexSearch(SqList A[],IdxType index[],int b,int keyType k,int n)
{
    //分块查找关键字k的记录,索引表为index[0...b-1]
    //先对索引表进行二分查找
    int low=0,high=b-1,mid,i;
    int s = n/b;//每块记录数
    while(low<=high){
        mid=(low+high)/2;
        if(index(mid].key <k)
            low = mid+1;
        else
            high = mid-1;
    }
    if(low <b)
    {   //在顺序表中顺序查找
        for(i=index[low].link; i<=index[low].link +s-1 && i<n; i++)
        {
            if(A[i] ==k)
                return i;
        }
    }
    return -1;
}
```

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/9f28b733-bceb-476a-bcc3-98c059a2f1aa/128/index_files/2.jpg)

# 二 动态查找表

**2.1** **二叉排序树**
![img](file:///C:/Users/chen/Documents/My Knowledge/temp/9f28b733-bceb-476a-bcc3-98c059a2f1aa/128/index_files/bc6f567c-5cc3-42e1-bbc5-5335b1f4657b.jpg)

**二叉排序树（Binary Sort Tree**）又称**二叉查找树（Binary Search Tree****）**，它或者是空树，或者是满足如下性质的二叉树：

(1) 若他的左子树非空，则左子树上所有结点的值均小于根结点的值

(2) 若他的右子树非空，则右子树上所有结点的值均大于根结点的值

(3) 它的左右子树本身又各是一棵二叉排序树**(递归)**

**二叉排序树有一个特性：**数据集合本身是无序的，但二叉排序树的**中序序列(LDR)**是递增序列(有序的)

**2.1.1 二叉排序树的查找**

 

```
// 二叉树的二叉链表结点结构定义
typedef int ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BITNode, *BiTree;
```

 

```
// 递归查找二叉排序树T中是否存在key
// 指针f指向T的双亲，初始值未NULL
// 若查找成功，指针p指向该数据元素结点，并返回TRUE
// 否则指针p指向查找路径上访问的最后一个结点并返回FALSE
status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if(!T){ // 查找不成功
        *p = f;
        return FALSE;
    } else if(key == T->data){ // 查找成功
        *p = T;
        return TRUE;
    } else if(key < T->data){
        // 查找左子树
        return SearchBST(T->lchild, key, T, p); 
    }else{
        // 查找右子树
        return SearchBST(T->rchild, key, T, p); 
    }
}
```

**2.1.2 二叉排序树的插入**

基本思想：若二叉排序树为空，将插入的结点作为根节点；否则将待插入结点的关键字值和根结点关键字值进行标胶，若小于，则作为跟结点的左子树插入，否则作为右子树插入。

 

```
// 插入key并返回TRUE，否则返回FALSE
status InsertBST(BiTree *T, int key)
{
    BiTree p,s;
    if(!SearchBST(*T,key, NULL,&p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p){
            *T = s;         // 找不到，插入s为新的根结点
        }else if( key < p->data){
            p->lchild = s; // 插入s为左孩子
        }else{
            p->rchild = s; // 插入s为右孩子
        }
        return TRUE;
    }else{
        return FALSE;    // 找到相同，直接返回
    }
}
```

 

**2.1.3 二叉排序树的删除**

根据删除的结点又三种情况进行分析：

- 叶子结点
- 仅有左或右子树的结点
- 左右子树都有结点

 

```
// 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点并返回TRUE，否则返回FALSE
status DeleteBST(BiTree *T, int key)
{
    if(!*T){
        return FALSE;
    }else{
        if(key == (*T)->data) // 找到
            return Delete(T);
        else if(key < (*T)->data)
            return DeleteBST(&(*T)->lchild, key); // 查找左子树
        else
            return DeleteBST(&(*T)->rchild, key); // 查找右子树
    }
}
// 从二叉排序树中删除结点p，并重接它的左或右子树
status Delete(BiTree *p)
{
    BiTree q,s;
    if( (*p)->rchild == NULL) // 右子树为空则只需重接它的左子树
    {
        q = *p; *p = (*p)->lchild; free(q);
    }
    else if( (*p)->lchild == NULL) // 只需重接它的右子树
    {
        q = *p; *p = (*p)->rchild; free(q);
    }
    else // 左右子树都不为空
    {
        q = *p; s = (*p)->lchild;
        while( s->rchild)         // 转左，然后向右到尽头
        {
            q = s; s = s->rchild;
        }
        (*p)->data = s->data;     // s指向被删结点的直接前驱
        
        if(q !=*p)
            q->rchild = s->lchild; // 重接q的右子树
        else
            q->lchild = s->lchild; // 重接q的左子树
        free(s);
    }
    return TRUE;
}
```

**3.2 平衡二叉排序树**

 平衡二叉排序树（AVL树）或者是一棵空树，或者是具有下列性质的二叉树：

\1. **左子树**和**右子树**的**深度**之差的绝对值不超过1(可以为1)

\2. 它的左子树和右子树都是平衡二叉排序树

**重点：** 每插入一个节点，就要检查树的平衡是否被破坏。

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/9f28b733-bceb-476a-bcc3-98c059a2f1aa/128/index_files/a946d97b-d0cf-4f71-adc9-dbde8b3f092f.jpg)

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/9f28b733-bceb-476a-bcc3-98c059a2f1aa/128/index_files/303623fe-5f52-47ea-b300-6251d6c9e042.jpg)

 

**3.3 多路查找树**

**多路查找树**，其每一个结点的孩子树可以多于两个，且每一个结点处可以存储多个元素。多路查找树在降低磁盘IO上起了很大的作用。

为此，我们讲解它的4种特殊形式： 2-3树，2-3-4树，B树和B+树

**3.3.1 2-3树
3.3.2 B-树
3.3.3 B+树

3.3.4 2.3 键树
**

3 散列表(哈希表)

 构造散列函数的两个基本原则：

1）计算简单

2）计算出来的散列分布均匀

直接定址法：

数字分析法：

平方取中法：将关键字平方之后取中间若干位数字作为散列地址

折叠法：

除留余数法：

随机数法：

处理散列冲突的方法：

1）开放地址法

![img](file:///C:/Users/chen/Documents/My Knowledge/temp/9f28b733-bceb-476a-bcc3-98c059a2f1aa/128/index_files/22c6d4d2-eb80-4e0c-91b6-9f6d1dd21c93.jpg)

2）链地址法

3）公共溢出区法

 

 