#include <stdio.h>
#include <stdlib.h>
#define VertexType int
#define VRType int
#define MAX_VERtEX_NUM 20
#define InfoType char   
#define INFINITY 65535

//----------����----------
//��¼��Ϣ 
typedef struct{
    VRType adj;                            	//������Ȩͼ���� 1 �� 0 ��ʾ�Ƿ����ڣ����ڴ�Ȩͼ��ֱ��ΪȨֵ��
    InfoType *info;                       	//�����⺬�е���Ϣָ��
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
//ͼ���ݵĴ洢 
typedef struct{
    VertexType vexs[MAX_VERtEX_NUM];        //�洢ͼ�ж�������
    AdjMatrix arcs;                         //��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum,arcnum;                      //��¼ͼ�Ķ������ͻ����ߣ���
}MGraph;
//�������飬����ÿ��ɸѡ��Ȩֵ��С�ıߵ��ڽӵ�
typedef struct{
    VertexType adjvex;//��¼Ȩֵ��С�ıߵ���ʼ��
    VRType lowcost;//��¼�ñߵ�Ȩֵ
}closedge[MAX_VERtEX_NUM];
closedge theclose;							//����һ��ȫ�����飬��Ϊÿ�������ж���ʹ�õ� 

//----------�ж϶���λ��---------- 
int LocateVex(MGraph G,VertexType v){	//��ڲ���������ͨ����Ҫ�ҵ�����ֵ 
    int i = 0;							//���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ�� 
    for(; i<G.vexnum; i++){				//����һά���飬�ҵ�����v
        if (G.vexs[i] == v){			//����Ǳ���v 
            return i;					//���ڲ���������λ�� 
        }
    }
    return -1;							//���ڲ�����û�ҵ�����-1 
}

//----------������ͨ��---------- 
void CreateUDN(MGraph* G){				//�����������ͨ�� 
	int i, j;
	int v1, v2, w;
	int m, n;							//����  
	printf("������ͨ���Ķ�����:");
	scanf("%d", &(G->vexnum)); 	//���붥���� 
	printf("������ͨ���ı���:");
    scanf("%d",&(G->arcnum));	//������� 
    printf("������ͨ���Ķ��㣺\n");
    for(i = 0; i<G->vexnum; i++){		//ѭ�����붥��ֵ 
        scanf("%d",&(G->vexs[i]));		//������ͨ���Ķ��� 
    }
    for(i = 0; i<G->vexnum; i++){		
        for (j = 0; j<G->vexnum; j++){	//ѭ��ִ�� 
            G->arcs[i][j].adj=INFINITY;	//����� 
            G->arcs[i][j].info=NULL;	//����� 
        }
    }
    printf("������ߵ���ʼ����յ㼰Ȩ�أ��ո������\n");
    for(i = 0; i<G->arcnum; i++){		//ѭ��ִ�� 
        scanf("%d %d %d",&v1,&v2,&w);	//������ʼ�㡢�յ��Ȩ�� 
        m = LocateVex(*G, v1);			//��λ��ʼ�� 
        n = LocateVex(*G, v2);			//��λ�յ� 
        if (m == -1 ||n == -1) {		//�����û�ҵ� 
            printf("no this vertex\n");	//��������򱨴� 
            return;
        }
        G->arcs[n][m].adj = w;			//��ֵ 
        G->arcs[m][n].adj = w;			//��ֵ 
    }									//���ڲ�����������ɵ���ͨ�� 
}

//----------����С��������---------- 
int minimun(MGraph G,closedge close){	//��ڲ�������ͨ����ȫ������ 
    int min = INFINITY;					//��ʼ�� 
    int min_i=-1;						//��ʼ�� 
	int i;			
    for(i = 0; i<G.vexnum; i++){
        if (close[i].lowcost>0 && close[i].lowcost<min) {
            min = close[i].lowcost;		//��¼��Сֵ 
            min_i = i;					//��¼��Сֵλ�� 
        }
    }
    return min_i;						//���ڲ�������СȨֵ���ڵ������±�
}
//----------����ķ�㷨---------- 
void miniSpanTreePrim(MGraph G,VertexType u){		//��ڲ�������ͨ����������ѡ������ⶥ����Ϊ��ʼ�� 
	int i,j;
    int k = LocateVex(G, u);						//�ҵ�����ʼ���ڶ��������е�λ���±�
    for(i = 0; i<G.vexnum; i++){					//�洢�����Ϣ 
        if (i != k){								//���i������k������Ҫִ�к������� 
            theclose[i].adjvex = k;					//�ߵ���ʼ��洢 
            theclose[i].lowcost = G.arcs[k][i].adj;	//�ߵ�Ȩֵ�洢 
        }
    }
    theclose[k].lowcost=0;					//���������Ӧλ�õ�Ȩֵ����Ϊ0���������ᱻѡ�� 
    printf("\n���ɵ���·��Ϊ��\n"); 
    for(i = 1; i<G.vexnum; i++){			//ѡ����һ���㣬�����¸��������е���Ϣ
        k = minimun(G, theclose);			//�ҳ�Ȩֵ��С�ı����������±�
        printf("%d %d\n",G.vexs[theclose[k].adjvex],G.vexs[k]);	//���ѡ���·��
        theclose[k].lowcost = 0;			//������С�������Ķ���ĸ��������е�Ȩֵ��Ϊ0
        for(j = 0; j<G.vexnum; j++){		//ѭ���жϣ�ֱ��Ȩֵ��С 
            if (G.arcs[k][j].adj<theclose[j].lowcost){				//�ж��ɴ˶�����������������������Ȩֵ�Ƿ��֮ǰ��¼��Ȩֵ��ҪС
                theclose[j].adjvex = k;	
                theclose[j].lowcost = G.arcs[k][j].adj;				//�����С�͸��� 
            }
        }
    }
    printf("\n");							//���ڲ�������ӡ����ķ�㷨ִ�к�Ľ�� 
}

//----------main����---------- 
int main(){
	printf("����ķ�㷨��ʾ\n"); 
    MGraph G;				//������G
    CreateUDN(&G);			//������ͨ��
    miniSpanTreePrim(G, 1);	//����ķ�㷨
    return 0; 
}
