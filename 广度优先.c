#include <stdio.h>	
#include<stdlib.h>
#define MaxVertexNum 10   //��󶥵�����Ϊ10

//----------����---------- 
typedef enum {false, true} bool;
//�ڽӵ�Ķ��� 
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    int AdjV;        		//�ڽӵ��±�
    PtrToAdjVNode Next; 	//ָ����һ���ڽӵ��ָ��
};
//�����ͷ���Ķ���
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; 	//�߱�ͷָ��
}AdjList[MaxVertexNum];     	//AdjList���ڽӱ����� 
//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     			//������
    int Ne;    				//����
    AdjList G;  			//�ڽӱ�
};
typedef PtrToGNode LGraph;	//���ڽӱ�ʽ�洢��ͼ����

bool Visited[MaxVertexNum]; //����ķ��ʱ��

//----------ͼ�Ĵ���---------- 
LGraph CreateGraph(){			//����ͼ���ҽ�Visited��ʼ��Ϊfalse,����ʵ�� 
    int i, VertexNum;			//��ڲ������� 
    int V, E1, E2;
    LGraph Graph;
    PtrToAdjVNode NewNode;
    printf("�����붥�������"); 
    scanf("%d", &VertexNum);	//�û����붥����� 
    Graph = (LGraph)malloc (sizeof(struct GNode));	//����洢�ռ� 
    Graph->Nv = VertexNum;			//��ʼ�������� 
    Graph->Ne = 0;					//��ʼ������ 
    for(V = 0; V<Graph->Nv; V++){	//��ʼ�� 
        Graph->G[V].FirstEdge = NULL;
    }
    printf("�����������");
    scanf("%d", &(Graph->Ne));				//����ߵĸ��� 
    if(Graph->Ne){							//������� 
    	printf("�������໥���ӵıߣ��ÿո����������һ��\n");
        for(i = 0; i<Graph->Ne; i++){
            scanf("%d %d", &E1, &E2);		//�����<E1, E2> 
            NewNode = (PtrToAdjVNode)malloc (sizeof(struct AdjVNode));	//����洢�ռ� 
            NewNode->AdjV = E2;
            NewNode->Next = Graph->G[E1].FirstEdge;
            Graph->G[E1].FirstEdge = NewNode;	//����ͼ�����Ի��ǲ����<E2, E1>  
            NewNode = (PtrToAdjVNode)malloc (sizeof(struct AdjVNode));	//����洢�ռ� 
            NewNode->AdjV = E1;
            NewNode->Next = Graph->G[E2].FirstEdge;
            Graph->G[E2].FirstEdge = NewNode;	//����ͼ�����Ի��ǲ����<E2, E1> 
        }
    }
    return Graph;			//���ڲ����������õ�ͼ 
}

//----------�������---------- 
void BFS(LGraph Graph, int S){//���������ִ�й�������㷨��ͼ���ڵ���

    int queue[11]; 					//����һ������
    int l = 0, r = 0;
    PtrToAdjVNode tmp;				//����һ���м���� 
    queue[r++] = S;					//�ڶ����м�¼�ڵ��� 
    printf(" %d", S);				//��ӡS����ڵ� 
    Visited[S] = true;				//���Ϊtrue��˵���Ѿ���������
    while(l != r){ 					//���в�Ϊ��
        tmp = Graph->G[queue[l++]].FirstEdge;	//�����м���� 
        while(tmp){								//����м������Ϊ0����һֱѭ�� 
            int pos = tmp->AdjV;
            if(!Visited[pos]){					//���û�б����� 
                printf(" %d", pos);						//��ӡ�ڵ���Ϣ 
                Visited[pos] = true;			//���ʽڵ� 
                queue[r++] = pos;				//�ڶ����м�¼ 
            }
            tmp = tmp->Next;					//Ϊ��һ�������� 
        }							//���ڲ�����������ɺ��ֵ 
    }
}

//----------main����---------- 
int main(){
    LGraph G;					//����ͼ 
    int S;						//�ڵ��� 
    printf("��������㷨��ʾ\n"); 
    G = CreateGraph();			//����ͼ 
    printf("��������ʼ�ڵ��ţ�"); 
    scanf("%d", &S);			//��ʼ�ڵ��� 
    printf("��%d��ʼ�Ĺ�ȱ������Ϊ:", S);
    BFS(G, S);			//������ȱ���������ӡ��� 
    return 0;
}


