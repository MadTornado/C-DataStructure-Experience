#include <stdio.h>
#include <stdlib.h>

//�Զ��嵥���� 
typedef struct Link{
    int elem;								//ֵ 
    struct Link *next;						//ָ����һ���ڵ� 
}link;

//������ĳ�ʼ���ͽ����� 
link *init(){
	int i = 0,c; 
	link *p = (link*)malloc(sizeof(link));	//����һ��ͷ���
    link *temp = p;							//����һ��ָ��ָ��ͷ��㣬���ڱ�������
    printf("�������ݣ�����һ�������ûس�������ctrl+z���س�ֹͣ����\n"); 
    while((c = scanf("%d",&i) )!= EOF){		//�������������½ڵ㣬�����벻��ctrl+zʱ����¼���ݲ����� 
        link *a = (link*)malloc(sizeof(link));	//��a����ռ� 
        a->elem = i;						//��ʼ��a����ֵ 
        a->next = NULL;						//��temp�ڵ����½�����a�ڵ㽨���߼���ϵ
        temp->next = a;						//ָ��ÿ�ζ�ָ����������һ���ڵ� 
        temp = temp->next;					//����ͷָ��Ӷ��ҵ��������� 
    }
    return p;								//���ڣ��������� 
}

//������Ĵ�ӡ�� 
void display(link *p){
    link* temp = p;							//��tempָ������ָ��ͷ���
    while (temp->next){						//ֻҪtempָ��ָ��Ľ���next���գ���ִ�������䡣
        temp = temp->next;					//tempָ��ָ��Ľ�����һ���ڵ� 
        printf("%d ", temp->elem);			//˳����� 
    }
    printf("\n \n");
}

//������Ĳ��룺 
link *addin(link *p, int elem, int situ){		//��ڲ�����ִ�в���ı������Ԫ�أ������λ�� 
    int i = 0;
	link *temp = p;								//������ʱ���temp
    for (i = 1; i < situ; i++){					//�ҵ�Ҫ����λ�õ���һ�����
        temp = temp->next;						//tempָ��ָ��Ľ�����һ���ڵ� 
        if (temp == NULL){
            printf("����λ����Ч\n");
            return p;							//���ڣ��������� 
        }
    }
    link *c = (link*)malloc(sizeof(link));	//����������c
    c->elem = elem;
    c->next = temp->next;					//�������в�����
    temp->next = c;
    return p;								//���ڣ��������� 
}

//������Ĳ��ң� 
int find(link *p, int elem){				//��ڲ�����ִ�в��ҵı����ҵ�Ԫ�� 
    link *t = p;
    int i = 1;
    while (t->next){						//����ͷ�ڵ�Ĵ��ڣ����while�е��ж�Ϊt->next
        t = t->next;						//tempָ��ָ��Ľ�����һ���ڵ� 
        if (t->elem == elem){				//���ҵ���Ӧ���󣬷���Ԫ��λ�� 
            return i;						//���ڣ����ز���Ԫ�ص�λ�� 
        }
        i++;
    }										//����ʧ���򷵻�-1 
    return -1;								//���ڣ�����ʧ�ܣ�����-1 
}

//�������ɾ���� 
link * dele(link * p, int situ){		//��ڲ�����ִ��ɾ���ı�ɾ����Ԫ��λ�� 
    int i = 0; 
	link * temp = p;
    for (i = 1; i < situ; i++){			//��������ɾ��������һ�����
        temp = temp->next;				//tempָ��ָ��Ľ�����һ���ڵ� 
        if (temp->next == NULL){
            printf("û�иý��\n");
            return p;					//���ڣ��������� 
        }
    }
    link * del = temp->next;			//��������һ��ָ��ָ��ɾ�����
    temp->next = temp->next->next;		//����ǰһ������ָ����
    free(del);							//�ͷ�del�洢�ռ䣬��ֹ�ڴ�й©
    return p;							//���ڣ��������� 
}

int main() {
	int i = 0;
	int c1 = 0,c2 = 0;
	int f1 = 0,f2 = -1;
	int d1 = 0;
    link *t = init();					//��ʼ������������ 
    display(t);
	
 	printf("�������ĸ�λ�ò����ĸ�Ԫ��:������������");		//����Ԫ�� 
 	scanf("%d %d",&c1,&c2);
	t = addin(t, c2, c1);
	display(t);
	
	printf("��������ĸ�Ԫ��:");							//����Ԫ�� 
 	scanf("%d",&f1);	
 	f2 = find(t,f1);
 	if(f2 == -1){
		printf("û�и�Ԫ��\n"); 
	}else{
		printf("���Ҷ���λ��Ϊ%d\n\n",f2); 
	}
	
	printf("����Ҫɾ����Ԫ��λ�ã�");						//ɾ��Ԫ�� 
 	scanf("%d",&d1);
	t = dele(t, d1);
	display(t);
	
    return 0;
}

