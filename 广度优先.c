#include <stdio.h>	
#include<stdlib.h>
#define MaxVertexNum 10   //最大顶点数设为10

//----------定义---------- 
typedef enum {false, true} bool;
//邻接点的定义 
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    int AdjV;        		//邻接点下标
    PtrToAdjVNode Next; 	//指向下一个邻接点的指针
};
//顶点表头结点的定义
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; 	//边表头指针
}AdjList[MaxVertexNum];     	//AdjList是邻接表类型 
//图结点的定义
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     			//顶点数
    int Ne;    				//边数
    AdjList G;  			//邻接表
};
typedef PtrToGNode LGraph;	//以邻接表方式存储的图类型

bool Visited[MaxVertexNum]; //顶点的访问标记

//----------图的创建---------- 
LGraph CreateGraph(){			//创建图并且将Visited初始化为false,裁判实现 
    int i, VertexNum;			//入口参数：无 
    int V, E1, E2;
    LGraph Graph;
    PtrToAdjVNode NewNode;
    printf("请输入顶点个数："); 
    scanf("%d", &VertexNum);	//用户输入顶点个数 
    Graph = (LGraph)malloc (sizeof(struct GNode));	//分配存储空间 
    Graph->Nv = VertexNum;			//初始化顶点数 
    Graph->Ne = 0;					//初始化边数 
    for(V = 0; V<Graph->Nv; V++){	//初始化 
        Graph->G[V].FirstEdge = NULL;
    }
    printf("请输入边数：");
    scanf("%d", &(Graph->Ne));				//输入边的个数 
    if(Graph->Ne){							//如果正常 
    	printf("请输入相互连接的边，用空格隔开，两个一组\n");
        for(i = 0; i<Graph->Ne; i++){
            scanf("%d %d", &E1, &E2);		//插入边<E1, E2> 
            NewNode = (PtrToAdjVNode)malloc (sizeof(struct AdjVNode));	//分配存储空间 
            NewNode->AdjV = E2;
            NewNode->Next = Graph->G[E1].FirstEdge;
            Graph->G[E1].FirstEdge = NewNode;	//无向图，所以还是插入边<E2, E1>  
            NewNode = (PtrToAdjVNode)malloc (sizeof(struct AdjVNode));	//分配存储空间 
            NewNode->AdjV = E1;
            NewNode->Next = Graph->G[E2].FirstEdge;
            Graph->G[E2].FirstEdge = NewNode;	//无向图，所以还是插入边<E2, E1> 
        }
    }
    return Graph;			//出口参数：创建好的图 
}

//----------广度优先---------- 
void BFS(LGraph Graph, int S){//输入参数：执行广度优先算法的图、节点编号

    int queue[11]; 					//定义一个队列
    int l = 0, r = 0;
    PtrToAdjVNode tmp;				//定义一个中间变量 
    queue[r++] = S;					//在队列中记录节点编号 
    printf(" %d", S);				//打印S这个节点 
    Visited[S] = true;				//标记为true，说明已经遍历过了
    while(l != r){ 					//队列不为空
        tmp = Graph->G[queue[l++]].FirstEdge;	//更新中间变量 
        while(tmp){								//如果中间变量不为0，则一直循环 
            int pos = tmp->AdjV;
            if(!Visited[pos]){					//如果没有被遍历 
                printf(" %d", pos);						//打印节点信息 
                Visited[pos] = true;			//访问节点 
                queue[r++] = pos;				//在队列中记录 
            }
            tmp = tmp->Next;					//为下一个数据域 
        }							//出口参数：遍历完成后的值 
    }
}

//----------main函数---------- 
int main(){
    LGraph G;					//定义图 
    int S;						//节点编号 
    printf("广度优先算法演示\n"); 
    G = CreateGraph();			//创建图 
    printf("请输入起始节点编号："); 
    scanf("%d", &S);			//起始节点编号 
    printf("从%d开始的广度遍历结果为:", S);
    BFS(G, S);			//广度优先遍历，并打印结果 
    return 0;
}


