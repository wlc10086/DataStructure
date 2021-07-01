# 1 队列定义
队列也是一种首先的线性表，插入限定在表的一端进行，删除限定在表的另一端进行（具有先入先出特性FIFO）。允许插入的一端称为队尾，允许删除的一端称为队头。插入过程称为入队，删除的过程称为出队。

# 2 队列的抽象数据类型
```
ADT Queue{
数据对象：D={ai|ai∈ElemSet，i=1，2，…，n，n≥0}
数据关系：R1={<ai-1，ai>|ai-1，ai∈D，i=1，2，…，n } 约定a1为队列头，an为队列尾。

基本操作：
    InitQueue( &Q )
      操作结果：构造一个空队列Q。
    DestroyQueue ( &Q )
      初始条件：队列Q已存在。
      操作结果：销毁队列Q。
    ClearQueue ( &Q )
      初始条件：队列Q已存在。
      操作结果：将Q清为空队列。
    QueueEmpty( Q )
      初始条件：队列Q已存在。
      操作结果：若Q为空队列，则返回TRUE，否则返回FALSE。
    QueueLength( Q )
      初始条件：队列Q已存在。
      操作结果：返回Q的数据元素个数，即队列的长度。
    GetHead( Q，&e )
      初始条件：队列Q已存在且非空。
      操作结果：用e返回Q的队头元素。
    EnQueue( &Q，e )
      初始条件：队列Q已存在。
      操作结果：插入元素e为Q的新的队尾元素。
    DeQueue( &Q，&e )
      初始条件：队列Q已存在且非空。
      操作结果：删除Q的队头元素，并用e返回其值。
    QueueTraverse( Q，visit() )
      初始条件：队列Q已存在且非空。
      操作结果：从队头到队尾依次对Q的每个数据元素调用函数visit()。一旦visit()失败，则操作失败。
}ADT Queue
```

# 3 队列的顺序存储

在选用队列的顺序存储结构时，假设我们定义队头是第一个元素位置，那个某个元素出队后，后面的元素都要往前挪一位，这样时间复杂度为O(n)。

因此，我们决定不固定队头位置，但这样又容易造成假溢出，因此，在队列的顺序存储中常用**循环队列**解决问题（但还是存在上溢或存储空间利用率不高的问题）。

```c
#define MAXQSIZE 100
typedef char QElemType;
typedef struct {    
    QElemType *base;  // 数据域
	int front, rear;  // 队头和队尾
}SqQueue;
```


# 4 队列的链式存储    

```c
typedef char QElemType;

// 链队结点的类型
typedef struct QNode
{
    QElemType * data;  // 数据域
    struct QNode* next;// 指针域
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front; // 队头指针
    QueuePtr rear; // 队尾指针
}ListQueue;
```