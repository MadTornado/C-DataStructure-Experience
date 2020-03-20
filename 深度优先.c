#include<stdio.h>	
#include<stdlib.h>
#define MaxVertexNum 10 
#define INFINITY 65535   

//---------����---------- 
typedef enum {false, true} bool;
//ͼ�ڵ�Ķ��� 
typedef struct GNode *PtrToGNode;	
struct GNode{
    int Nv; 						//������ 
    int Ne; 						//���� 
    int G[MaxVertexNum][MaxVertexNum]; 	//�ڽӾ���
};
typedef PtrToGNode MGraph; 		//���ڽӾ���洢��ͼ����
bool Visited[MaxVertexNum]; 	//����ķ��ʱ��

//----------ͼ�Ĵ���---------- 
MGraph CreateGraph(){ 			//����ͼ���ҽ�Visited��ʼ��Ϊfalse
    int i, VertexNum;			//��ڲ������� 
    int v1, v2;
    int V, W ;
    MGraph Graph;				//����������� 
    printf("�����붥�������");
    scanf("%d", &VertexNum);	//��������ļ�¼ 
    Graph = (MGraph)malloc(sizeof(struct GNode));		//����洢�ռ� 
    Graph->Nv = VertexNum;		//��ʼ�������� 
    Graph->Ne = 0;				//��ʼ������ 
    for(V = 0; V<Graph->Nv; V++){
        for(W = 0; W<Graph->Nv; W++){
            Graph->G[V][W] = INFINITY;	//˫�ֽ��޷������� 
        }
    }
    printf("�����������");
    scanf("%d", &Graph->Ne);			//������� 
    if(Graph->Ne) {
    	printf("�������໥���ӵıߣ��ÿո����������һ��\n");
        for(i = 0; i < Graph->Ne; i ++){
            scanf("%d %d", &v1, &v2);	//��ñ� 
            Graph->G[v1][v2] = 1;		//����� 
            Graph->G[v2][v1] = 1;		//����� 
        }
    }
    return Graph;					//���ڲ����������õ�ͼ 
}

//----------������ȱ���---------- 
void DFS(MGraph Graph, int V){		//���������ͼ���ڵ���
    int i;								//�ӵ�V����������ݹ��������ȱ���ͼG
    Visited[V] = true;					//���Ϊtrue��˵���Ѿ���������
    printf(" %d", V); 					//��ӡ��V������
    for(i = 0; i < Graph->Nv; i++){ 	//����V��ÿ���ڽӵ�
        if(Graph->G[V][i] == 1 && !Visited[i]){		//=1˵���н�㣬!Visited[i]Ϊ�棬˵��δ������
           DFS(Graph, i);				//�ݹ����DFS
        }
    }
}

//----------main����---------- 
int main(){
    MGraph G;					//����ͼ 
    int V;						//�ڵ��� 
    printf("��������㷨��ʾ\n"); 
    G = CreateGraph();			//����ͼ 
    printf("��������ʼ�ڵ��ţ�"); 
    scanf("%d", &V);			//������ʼ�ڵ��� 
    printf("��%d��ʼ����ȱ������Ϊ:", V);
    DFS(G, V); 					//������ȱ���������ӡ��� 
    return 0;
}
