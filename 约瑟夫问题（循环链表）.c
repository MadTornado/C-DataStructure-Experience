#include <stdio.h>
#include <stdlib.h>

//�Զ������� 
typedef struct Link{
    int elem;									//ֵ 
    struct Link *next;							//ָ����һ���ڵ� 
}link;

//����ĳ�ʼ���ͽ��� 
link *init(int n){								//��ڲ����������� 
    int i;
    link *a; 
    link *p = (link*)malloc(sizeof(link));		//����һ��ͷ���
    link *temp = p;								//����һ��ָ��ָ��ͷ��㣬���ڱ�������
    for (i = 1; i <=n; i++){							//�������������½ڵ㲢��ʼ��
        a = (link*)malloc(sizeof(link));		//��a����ռ�,Ϊ������n 
        a->elem = i;							//��ʼ��a
        temp->next = a;							//ָ��ÿ�ζ�ָ����������һ���ڵ� 
        temp = a;								//��ʱaΪβ�ڵ㣬����ֵ����ʱ����temp 
    }
    a->next=p->next;							//ʹ���һ�����ָ���һ����㣬����һ��ѭ����
    return p;									//���ڣ������õı� 
}

link *baoshu(link *p,int n,int m){			//��ڲ����������������������� 
    int i,j;
    link *q;
    link *a = p;
    for(i = 1; i <n; i++){						//n����ѭ��n�ν�����ȫ������ 
        for(j = 1; j <m; j++){					//���� 
            a = a->next;						//a�ǵ�j-1����ɾ����
        }
        q = a->next;
        a->next = q->next;						//ʹɾ��������ڵ�ǰһ�����ָ������㣬����һ��ѭ����
        printf("%d ",q->elem);					//���ɾ���Ľڵ�ֵ����Ϊ���ֵ��� 
        free(q);								//�ͷ�q�洢�ռ䣬��ֹ�ڴ�й© 
        p = a;								
    }
    printf("���һ����%d",p->elem);			//������һ�� 
    return p;								//���ڣ��������� 
}

int main(){
	link *t;
    int n,m;
    do{ 
		printf("��������������");
    	scanf("%d",&n);								//����������n 
    }while(n <=0);
    do{
	    printf("�����뱨��������");
    	scanf("%d",&m);								//���뱨��m 
	}while(m <=0 || m >n);
    t = init(n);								//��ʼ���� 
    t = baoshu(t,n,m);							//�������� 
}
