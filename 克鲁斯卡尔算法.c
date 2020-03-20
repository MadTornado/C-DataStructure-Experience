#include <stdio.h>
#include <stdlib.h>
#define MAX_VERtEX_NUM 20
#define VertexType int
//----------����---------- 
//���帨������
typedef struct edge{
    VertexType initial;		//��ʼ 
    VertexType end;			//��ֹ 
    VertexType weight;		//Ȩֵ 
}edge[MAX_VERtEX_NUM];
//�������飬����ÿ��ɸѡ��Ȩֵ��С�ıߵ��ڽӵ�
typedef struct{
    VertexType value;	//��������
    int sign;			//ÿ�����������ļ���
}assist[MAX_VERtEX_NUM];
assist assists;			//����һ��ȫ�����飬��Ϊÿ�������ж���ʹ�õ� 

//---------����---------  
int cmp(const void *a,const void*b){
    return ((struct edge*)a)->weight-((struct edge*)b)->weight;
}//qsort��������ʹ�ã�ʹedges�ṹ���еı߰���Ȩֵ��С��������

//----------��ʼ����ͨ��---------- 
void CreateUDN(edge *edges, int *vexnum, int *arcnum){
	int i;
    printf("������ͨ���Ķ�����:");
	scanf("%d", &(*vexnum)); 	//���붥���� 
	printf("������ͨ���ı���:");
    scanf("%d",&(*arcnum));		//������� 
    printf("������ͨ���Ķ��㣺\n");
    for(i=0; i<(*vexnum); i++){
        scanf("%d",&(assists[i].value));	//ѭ�����붥��ֵ
        assists[i].sign=i;					//������ͨ���Ķ��� 
    }
    printf("������ߵ���ʼ����յ㼰Ȩ�أ��ո������\n");
    for(i=0 ; i<(*arcnum); i++){
        scanf("%d %d %d",&(*edges)[i].initial,&(*edges)[i].end,&(*edges)[i].weight);
        //������ʼ�㡢�յ��Ȩ�� 
    }
}		

//----------�ж϶���λ��---------- 
int Locatevex(int vexnum,int point){	//��ڲ�������ͨ����Ҫ�ҵĶ���ֵ 
	int i;								//���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ�� 
    for(i = 0; i<vexnum; i++){			//����һά����
        if(assists[i].value == point){	//����Ǳ���point 
            return i;		//���ڲ���������λ�� 
        }
    }
    return -1;				//���ڲ�����û�ҵ�����-1 
}

//----------��³˹�����㷨��main����--------- 
int main(){
	printf("��³˹�����㷨��ʾ"); 
    int arcnum,vexnum;
	int i;
	int k;
    edge edges;			//����һ���յĽṹ�����飬���ڴ����С������
    edge minTree;		//����һ�����ڼ�¼��С�������бߵ������ĳ���
    int num = 0;		//��ʼ��num 
    CreateUDN(&edges,&vexnum,&arcnum);				//����ͨ���е����б߽����������򣬽���Ա�����edges������
    qsort(edges, arcnum, sizeof(edges[0]), cmp);	//�������еı�
    for(i = 0; i<arcnum; i++){
    //�ҵ��ߵ���ʼ����ͽ�������������assists�е�λ��
        int initial = Locatevex(vexnum, edges[i].initial);	//�ҵ��±� 
        int end = Locatevex(vexnum, edges[i].end);			//�ҵ��±� 
        if(initial != -1 && end != -1 && assists[initial].sign != assists[end].sign){
        //�������λ�ô����Ҷ���ı�ǲ�ͬ��˵������һ�������У����������·
            minTree[num] = edges[i];		//��¼�ñߣ���Ϊ��С����������ɲ���
            num++;							//����+1
            for(k = 0; k<vexnum; k++){		//���¼����������Ķ�����ȫ����Ϊһ����
                if(assists[k].sign == assists[end].sign){		//�������β��� 
                    assists[k].sign = assists[initial].sign;	//���������� 
                }
            }
            if(num == vexnum-1){	//��С�������Ѿ��γ� 
                break;				//�˳�ѭ�� 
            }
        }
    }
    printf("\n���ɵ���·��Ϊ��\n"); 	//������
    for(i = 0; i<vexnum-1; i++){		//ѭ����ӡ����·�� 
        printf("%d %d\n",minTree[i].initial,minTree[i].end);	//��ӡ��������·�� 
    }
    return 0;
}
