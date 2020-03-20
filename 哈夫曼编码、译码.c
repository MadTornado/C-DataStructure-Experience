#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2 -1
//----------�ṹ�嶨��---------- 
//�ڵ�ṹ�� 
typedef struct HNodeType{
    int weight;		//Ȩֵ 
    int parent;		//���ڵ� 
    int lchild;		//�������ڵ� 
    int rchild;		//�������ڵ� 
    char value;		//ʵ��ֵ 
}HNodeType;
 
//����ṹ�� 
typedef struct {		
    int bit[MAXBIT];	//�洢�ı��� 
    int start;			//ͷָ��λ�� 
}HCodeType;

//----------���������Ĺ���---------- 
void HuffmanTree(HNodeType HuffNode[MAXNODE], int n){ 	//��ڲ������ڵ�ṹ�塢�����ַ�������֮����Ҫ��������ڵ��Ȩֵ 
    int i, j;						//ѭ������ 
	int m1, m2;						//�������������ͬ������������СȨֵ�ڵ��Ȩֵ
	int x1, x2;						//�������������ͬ������������СȨֵ�ڵ��������е���� 
    for(i = 0; i<2*n-1; i++){		//��ʼ�������������еĽڵ� 
        HuffNode[i].weight = 0;		//Ȩֵ��ʼ��Ϊ0 
        HuffNode[i].parent = -1;	//���ڵ��ʼ��-1��-1����û��
        HuffNode[i].lchild = -1;	//��������ʼ��-1��-1����û��
        HuffNode[i].rchild = -1;	//��������ʼ��-1��-1����û��
    }  
    for(i = 0; i<n; i++){			//�����ַ��͸��ַ���Ҷ�ӽڵ㣩��Ȩֵ 
    	printf ("�������%d���ַ�:",i+1);
		scanf("%1s",&HuffNode[i].value);	//��¼�ַ� 
        printf("��������ַ���Ӧ��Ȩֵ��", i,HuffNode[i].value);	
        scanf("%d", &HuffNode[i].weight);	//��¼ÿ��Ҷ�ӽڵ��Ȩֵ 
    }
    printf ("\n");
    for(i = 0; i<n-1; i++){			//���������Ĺ��� 
        m1 = m2 = MAXVALUE;    		//��������޸�����ҽ��Ȩֵ��С��������� 
        x1 = x2 = 0;				//��ų�ʼΪ0 
        for(j = 0; j<n+i; j++){		//�ҳ����нڵ���Ȩֵ��С���޸��ڵ�������ڵ㣬���ϲ�֮Ϊһ�Ŷ�����
            if(HuffNode[j].weight<m1 && HuffNode[j].parent == -1){	//ȨֵС�ڼ�¼����û�и��ڵ� 
                m2 = m1; 			//��¼��С�ڵ� 
                x2 = x1; 			//��¼�ڵ� 
                m1 = HuffNode[j].weight;	//��¼��ǰ�ڵ� 
                x1 = j;						//��¼��ʱѭ��ֵ����Ϊ�ڵ� 
            }else if(HuffNode[j].weight<m2 && HuffNode[j].parent == -1){	//Ȩֵ��С����û�и��ڵ� 
                m2 = HuffNode[j].weight;	//��¼��ǰ�ڵ� 
                x2 = j;						//��¼��ǰѭ��ֵ����Ϊ�ڵ� 
            }
        }    
		//����Ϊ�����ҵ��������ӽڵ� x1��x2�ڵ���Ϣ */
        HuffNode[x1].parent  = n+i;		//���ڵ��¼ 
        HuffNode[x2].parent  = n+i;		//���ڵ��¼ 
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;	//�����ڵ��Ȩֵ��� 
        HuffNode[n+i].lchild = x1;		//���ӽڵ� 
        HuffNode[n+i].rchild = x2;		//�Һ��ӽڵ� 
        printf("%d.���ӽڵ�Ϊ: %d ,�Һ��ӽڵ�Ϊ %d �����ڵ�Ϊ %d\n", i+1, HuffNode[x1].weight, HuffNode[x2].weight,(HuffNode[x1].weight+HuffNode[x2].weight));
        //��ӡ�ڵ���Ϣ 
    }
    printf ("\n");
}							//���ڲ�������ʼ����ɺ�Ĺ������� 
 
//----------����---------- 
void decodeing(char string[], HNodeType Buf[], int Num){	//��ڲ�������Ҫ�����ַ������ڵ�ṹ�壬�����ַ��������� 
	int i;			//ѭ������ 
	int tmp = 0;	//��ʱ���� 
	int code[1024];			//�������飬�洢�����ַ���Ӧ������ 
	int m = 2*Num-1;		//��λһ�ֽ������� 
    char *nump;				//ָ�� 
	char num[1024];			//�����ַ����飬�洢������ַ��������ַ� 
	for(i = 0; i<strlen(string); i++){	//���ַ���ת��Ϊ�ַ����������ַ������� 
		if(string[i] == '0'){ 			//�����ǰ�ַ���Ԫ��Ϊ0 
			num[i] = 0;        			//ת��Ϊ�ַ���0 
		}else{ 							//�����ǰ�ַ���Ԫ��Ϊ1 
  			num[i] = 1;  				//ת��Ϊ�ַ���1 
		}                  
	} 
	i = 0;
	nump = &num[0];			//ָ��ָ�������ַ������ʼ 
	while(nump<(&num[strlen(string)])){	//�����ָ��ûָ����Ӧ�ַ����һλʱ 
		tmp = m-1;						//�ڵ�����1 
		while(Buf[tmp].lchild != -1 && Buf[tmp].rchild != -1){	//������ӽڵ���Һ��ӽڵ㶼���ڣ�����ѭ�� 
			if(*nump == 0){				 
    			tmp=Buf[tmp].lchild ;   //�洢���ӽڵ� 
			}else{
				tmp=Buf[tmp].rchild;	//�洢�Һ��ӽڵ� 
			} 
			nump++;    					//ָ����һ��λ�õ��ַ������ڼ�¼ 
		} 
		printf("%c",Buf[tmp].value);		//���ڲ������������ַ���                                 
	}
}
 
int main(){
    HNodeType HuffNode[MAXNODE];	//����ڵ�ṹ������
    HCodeType HuffCode[MAXLEAF];	//�������ṹ������
    HCodeType cd; 					//������ʱ���������������ʱ����Ϣ
	int n;							//�ַ����� 
    int i, j;						//ѭ������ 
	int c, p;						//��¼��ʱ����ṹ���ӽڵ�͸��ڵ� 	
    char pp[100];					//��¼������ַ��� 
    printf("�������ַ�������");
    scanf("%d", &n);				//��¼�ַ����� 
    HuffmanTree (HuffNode, n);		//������������ 
    for(i = 0; i<n; i++){			//cd���ں���������� 
        cd.start = n-1;				//����ṹ��ͷָ��ָ�����һλ 
        c = i;						//��¼�ӽڵ�
        p = HuffNode[c].parent;		//���ڼ�¼���ڵ� 
        while (p != -1){   			//���ڵ����ʱ������ѭ�� 
            if (HuffNode[p].lchild == c)	//����ӽڵ��뵱ǰѭ������ͬ 
                cd.bit[cd.start] = 0;		//��ǰλ����Ϊ0 
            else							//����ӽڵ��뵱ǰѭ������ͬ 
                cd.bit[cd.start] = 1;		//��ǰλ����Ϊ1 
            cd.start--;       				//�����ĵ�һλ
            c = p;                    		//����Ҷ�ӽڵ� 
            p = HuffNode[c].parent; 		//���¸��ڵ� 
        }
        for(j = cd.start+1; j<n; j++){	
        	HuffCode[i].bit[j] = cd.bit[j];	//��¼ÿ��Ҷ�ӽڵ�Ĺ��������� 
		}
        HuffCode[i].start = cd.start;		//��¼�������ʼλ 
    }
    /* ����ѱ���õ����д��ڱ���Ĺ��������� */
    for(i = 0; i<n; i++){		//��ӡ���������� 
        printf ("%c�Ĺ���������Ϊ: ", HuffNode[i].value);
        for (j = HuffCode[i].start+1; j<n; j++){
            printf ("%d", HuffCode[i].bit[j]);	//��ӡÿ���ַ��Ĺ��������� 
        }
        printf ("\n");
    }
    printf("\n�������������:\n");
    scanf("%s",&pp);			//��Ҫִ��������ַ��� 
	decodeing(pp,HuffNode,n);	//���� 
	return 0;
}
