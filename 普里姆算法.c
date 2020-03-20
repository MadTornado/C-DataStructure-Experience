#include <stdio.h>
#include <stdlib.h>
#define VertexType int
#define VRType int
#define MAX_VERtEX_NUM 20
#define InfoType char   
#define INFINITY 65535

//----------定义----------
//记录信息 
typedef struct{
    VRType adj;                            	//对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
    InfoType *info;                       	//弧额外含有的信息指针
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
//图数据的存储 
typedef struct{
    VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
    AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
    int vexnum,arcnum;                      //记录图的顶点数和弧（边）数
}MGraph;
//辅助数组，用于每次筛选出权值最小的边的邻接点
typedef struct{
    VertexType adjvex;//记录权值最小的边的起始点
    VRType lowcost;//记录该边的权值
}closedge[MAX_VERtEX_NUM];
closedge theclose;							//创建一个全局数组，因为每个函数中都会使用到 

//----------判断顶点位置---------- 
int LocateVex(MGraph G,VertexType v){	//入口参数：来连通网，要找到顶点值 
    int i = 0;							//根据顶点本身数据，判断出顶点在二维数组中的位置 
    for(; i<G.vexnum; i++){				//遍历一维数组，找到变量v
        if (G.vexs[i] == v){			//如果是变量v 
            return i;					//出口参数：返回位置 
        }
    }
    return -1;							//出口参数：没找到返回-1 
}

//----------构造连通网---------- 
void CreateUDN(MGraph* G){				//输入参数：连通网 
	int i, j;
	int v1, v2, w;
	int m, n;							//定义  
	printf("输入连通网的顶点数:");
	scanf("%d", &(G->vexnum)); 	//输入顶点数 
	printf("输入连通网的边数:");
    scanf("%d",&(G->arcnum));	//输入边数 
    printf("输入连通网的顶点：\n");
    for(i = 0; i<G->vexnum; i++){		//循环输入顶点值 
        scanf("%d",&(G->vexs[i]));		//输入连通网的顶点 
    }
    for(i = 0; i<G->vexnum; i++){		
        for (j = 0; j<G->vexnum; j++){	//循环执行 
            G->arcs[i][j].adj=INFINITY;	//插入边 
            G->arcs[i][j].info=NULL;	//插入边 
        }
    }
    printf("输入各边的起始点和终点及权重，空格隔开：\n");
    for(i = 0; i<G->arcnum; i++){		//循环执行 
        scanf("%d %d %d",&v1,&v2,&w);	//输入起始点、终点和权中 
        m = LocateVex(*G, v1);			//定位起始点 
        n = LocateVex(*G, v2);			//定位终点 
        if (m == -1 ||n == -1) {		//如果都没找到 
            printf("no this vertex\n");	//如果出错，则报错 
            return;
        }
        G->arcs[n][m].adj = w;			//赋值 
        G->arcs[m][n].adj = w;			//赋值 
    }									//出口参数：构造完成的连通网 
}

//----------找最小辅助函数---------- 
int minimun(MGraph G,closedge close){	//入口参数：连通网，全局数组 
    int min = INFINITY;					//初始化 
    int min_i=-1;						//初始化 
	int i;			
    for(i = 0; i<G.vexnum; i++){
        if (close[i].lowcost>0 && close[i].lowcost<min) {
            min = close[i].lowcost;		//记录最小值 
            min_i = i;					//记录最小值位置 
        }
    }
    return min_i;						//出口参数：最小权值所在的数组下标
}
//----------普里姆算法---------- 
void miniSpanTreePrim(MGraph G,VertexType u){		//入口参数：连通网、在网中选择的任意顶点作为起始点 
	int i,j;
    int k = LocateVex(G, u);						//找到该起始点在顶点数组中的位置下标
    for(i = 0; i<G.vexnum; i++){					//存储相关信息 
        if (i != k){								//如果i不等于k，则需要执行后续步骤 
            theclose[i].adjvex = k;					//边的起始点存储 
            theclose[i].lowcost = G.arcs[k][i].adj;	//边的权值存储 
        }
    }
    theclose[k].lowcost=0;					//辅助数组对应位置的权值设置为0，遍历不会被选中 
    printf("\n生成的树路径为：\n"); 
    for(i = 1; i<G.vexnum; i++){			//选择下一个点，并更新辅助数组中的信息
        k = minimun(G, theclose);			//找出权值最小的边所在数组下标
        printf("%d %d\n",G.vexs[theclose[k].adjvex],G.vexs[k]);	//输出选择的路径
        theclose[k].lowcost = 0;			//归入最小生成树的顶点的辅助数组中的权值设为0
        for(j = 0; j<G.vexnum; j++){		//循环判断，直到权值最小 
            if (G.arcs[k][j].adj<theclose[j].lowcost){				//判断由此顶点出发，到达其它各顶点的权值是否比之前记录的权值还要小
                theclose[j].adjvex = k;	
                theclose[j].lowcost = G.arcs[k][j].adj;				//如果还小就更新 
            }
        }
    }
    printf("\n");							//出口参数：打印普里姆算法执行后的结果 
}

//----------main函数---------- 
int main(){
	printf("普里姆算法演示\n"); 
    MGraph G;				//定义网G
    CreateUDN(&G);			//构造连通网
    miniSpanTreePrim(G, 1);	//普里姆算法
    return 0; 
}
