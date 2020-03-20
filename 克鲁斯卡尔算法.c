#include <stdio.h>
#include <stdlib.h>
#define MAX_VERtEX_NUM 20
#define VertexType int
//----------定义---------- 
//定义辅助数组
typedef struct edge{
    VertexType initial;		//起始 
    VertexType end;			//终止 
    VertexType weight;		//权值 
}edge[MAX_VERtEX_NUM];
//辅助数组，用于每次筛选出权值最小的边的邻接点
typedef struct{
    VertexType value;	//顶点数据
    int sign;			//每个顶点所属的集合
}assist[MAX_VERtEX_NUM];
assist assists;			//创建一个全局数组，因为每个函数中都会使用到 

//---------排序---------  
int cmp(const void *a,const void*b){
    return ((struct edge*)a)->weight-((struct edge*)b)->weight;
}//qsort排序函数中使用，使edges结构体中的边按照权值大小升序排序

//----------初始化连通网---------- 
void CreateUDN(edge *edges, int *vexnum, int *arcnum){
	int i;
    printf("输入连通网的顶点数:");
	scanf("%d", &(*vexnum)); 	//输入顶点数 
	printf("输入连通网的边数:");
    scanf("%d",&(*arcnum));		//输入边数 
    printf("输入连通网的顶点：\n");
    for(i=0; i<(*vexnum); i++){
        scanf("%d",&(assists[i].value));	//循环输入顶点值
        assists[i].sign=i;					//输入连通网的顶点 
    }
    printf("输入各边的起始点和终点及权重，空格隔开：\n");
    for(i=0 ; i<(*arcnum); i++){
        scanf("%d %d %d",&(*edges)[i].initial,&(*edges)[i].end,&(*edges)[i].weight);
        //输入起始点、终点和权中 
    }
}		

//----------判断顶点位置---------- 
int Locatevex(int vexnum,int point){	//入口参数：连通网、要找的定点值 
	int i;								//根据顶点本身数据，判断出顶点在二维数组中的位置 
    for(i = 0; i<vexnum; i++){			//遍历一维数组
        if(assists[i].value == point){	//如果是变量point 
            return i;		//出口参数：返回位置 
        }
    }
    return -1;				//出口参数：没找到返回-1 
}

//----------克鲁斯卡尔算法和main函数--------- 
int main(){
	printf("克鲁斯卡尔算法演示"); 
    int arcnum,vexnum;
	int i;
	int k;
    edge edges;			//创建一个空的结构体数组，用于存放最小生成树
    edge minTree;		//设置一个用于记录最小生成树中边的数量的常量
    int num = 0;		//初始化num 
    CreateUDN(&edges,&vexnum,&arcnum);				//对连通网中的所有边进行升序排序，结果仍保存在edges数组中
    qsort(edges, arcnum, sizeof(edges[0]), cmp);	//遍历所有的边
    for(i = 0; i<arcnum; i++){
    //找到边的起始顶点和结束顶点在数组assists中的位置
        int initial = Locatevex(vexnum, edges[i].initial);	//找到下标 
        int end = Locatevex(vexnum, edges[i].end);			//找到下标 
        if(initial != -1 && end != -1 && assists[initial].sign != assists[end].sign){
        //如果顶点位置存在且顶点的标记不同，说明不在一个集合中，不会产生回路
            minTree[num] = edges[i];		//记录该边，作为最小生成树的组成部分
            num++;							//计数+1
            for(k = 0; k<vexnum; k++){		//将新加入生成树的顶点标记全更改为一样的
                if(assists[k].sign == assists[end].sign){		//如果和最尾相等 
                    assists[k].sign = assists[initial].sign;	//更爱定点标记 
                }
            }
            if(num == vexnum-1){	//最小生成树已经形成 
                break;				//退出循环 
            }
        }
    }
    printf("\n生成的树路径为：\n"); 	//输出语句
    for(i = 0; i<vexnum-1; i++){		//循环打印树的路径 
        printf("%d %d\n",minTree[i].initial,minTree[i].end);	//打印生成树的路径 
    }
    return 0;
}
