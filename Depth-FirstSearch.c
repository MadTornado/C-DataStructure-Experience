#include<stdio.h>	
#include<stdlib.h>
#define MaxVertexNum 10 
#define INFINITY 65535   

//---------定义---------- 
typedef enum {false, true} bool;
//图节点的定义 
typedef struct GNode *PtrToGNode;	
struct GNode{
    int Nv; 						//顶点数 
    int Ne; 						//边数 
    int G[MaxVertexNum][MaxVertexNum]; 	//邻接矩阵
};
typedef PtrToGNode MGraph; 		//以邻接矩阵存储的图类型
bool Visited[MaxVertexNum]; 	//顶点的访问标记

//----------图的创建---------- 
MGraph CreateGraph(){ 			//创建图并且将Visited初始化为false
    int i, VertexNum;			//入口参数：无 
    int v1, v2;
    int V, W ;
    MGraph Graph;				//定义各个变量 
    printf("请输入顶点个数：");
    scanf("%d", &VertexNum);	//顶点个数的记录 
    Graph = (MGraph)malloc(sizeof(struct GNode));		//分配存储空间 
    Graph->Nv = VertexNum;		//初始化顶点数 
    Graph->Ne = 0;				//初始化边数 
    for(V = 0; V<Graph->Nv; V++){
        for(W = 0; W<Graph->Nv; W++){
            Graph->G[V][W] = INFINITY;	//双字节无符号整数 
        }
    }
    printf("请输入边数：");
    scanf("%d", &Graph->Ne);			//输入边数 
    if(Graph->Ne) {
    	printf("请输入相互连接的边，用空格隔开，两个一组\n");
        for(i = 0; i < Graph->Ne; i ++){
            scanf("%d %d", &v1, &v2);	//获得边 
            Graph->G[v1][v2] = 1;		//插入边 
            Graph->G[v2][v1] = 1;		//插入边 
        }
    }
    return Graph;					//出口参数：建立好的图 
}

//----------深度优先遍历---------- 
void DFS(MGraph Graph, int V){		//输入参数：图、节点编号
    int i;								//从第V个顶点出发递归地深度优先遍历图G
    Visited[V] = true;					//标记为true，说明已经遍历过了
    printf(" %d", V); 					//打印出V这个结点
    for(i = 0; i < Graph->Nv; i++){ 	//遍历V的每个邻接点
        if(Graph->G[V][i] == 1 && !Visited[i]){		//=1说明有结点，!Visited[i]为真，说明未遍历过
           DFS(Graph, i);				//递归调用DFS
        }
    }
}

//----------main函数---------- 
int main(){
    MGraph G;					//定义图 
    int V;						//节点编号 
    printf("深度优先算法演示\n"); 
    G = CreateGraph();			//创建图 
    printf("请输入起始节点编号："); 
    scanf("%d", &V);			//输入起始节点编号 
    printf("从%d开始的深度遍历结果为:", V);
    DFS(G, V); 					//深度优先遍历，并打印结果 
    return 0;
}
