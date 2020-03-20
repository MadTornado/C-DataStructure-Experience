#include <stdio.h>
#include <stdlib.h>

//�Զ���˳��� 
typedef struct ordtable{
    int *point;		//����һ�����Ȳ�ȷ���Ķ�̬���飬ͬʱ��Ҳ�Ǹ�ָ�� 
    int length;		//��¼��ǰ˳����� 
    int size;		//��¼˳������Ĵ洢���� 
}ordtable;

//˳����ʼ���� 
ordtable init(int j){								//��ڲ�����˳���ĳ��� 
    ordtable t;
    if(j <=0){
    	printf("���ܴ���һ����С�ڵ���0��˳���");
	}else{
    	t.point = (int*)malloc(j*sizeof(int));		//����ռ䣬����һ���յ�˳��� 
	}
    t.length = 0;								//��ʼ��˳����� 
    t.size = j;								//��ʼ���洢�ռ�Ϊ����ֵ
    return t;								//���ڣ�˳���
}

//˳���Ĵ�ӡ�� 
void display(ordtable t){					//��ڲ�������ӡ�ı� 
	int i = 0;
 	printf("˳����д洢��Ԫ�طֱ���:");
	for(i; i <t.length; i ++){				//��˳�����˳����е�Ԫ�� 
        printf("%d ",t.point[i]);			//���ڣ���ӡֵ 
    }
    printf("\n \n");
}

//˳���Ĳ��룺 
ordtable addin(ordtable t,int elem,int situ){	//��ڲ�����ִ�в���ı�elemΪ�����Ԫ�أ�situΪ�����λ�� 
    int i = 0; 
	if (situ>t.length+1||situ<1){				//�жϲ���λ���Ƿ������������С��0��Щ��������� 
        printf("����λ��������\n");
        return t;								//���ڣ�˳���
    }
    if (t.length==t.size){						//�ж��Ƿ��ж���λ�ù����� 
        t.point=(int *)realloc(t.point,(t.size+1)*sizeof(int));	//���ûλ���ˣ���Ҫ��������ռ� 
        if (!t.point){
            printf("�洢����ʧ��\n");			//�����̬�����ڴ�ʧ�ܣ��򱨴�
            return t;
        }
        t.size+=1;								
    } 
    for (i=t.length+1; i>=situ-1; i--){			//�Ӳ���λ�ÿ�ʼ�ĺ���Ԫ���������
        t.point[i+1]=t.point[i];					
    }
    t.point[situ-1]=elem;						//�ڲ���λ�ò���Ԫ�� 
    t.length++;									//���ϲ����Ԫ�أ����ȼ�1 
    return t;									//���ڣ�˳���
}

//˳���Ĳ���
int find(ordtable t,int elem){					//��ڲ�����ִ�в��ҵı�Ҫ���ҵĶ��� 
    int i = 0; 
	for (i; i <t.length; i++){					//�����ж��Ƿ��Ǹö��� 
       	if (t.point[i]==elem){
           	return i+1;							//���ڣ�����λ�� 
       	}
	}
    return -1;									//���ڣ��������ʧ�ܣ�����-1
} 

//˳����ɾ����
ordtable dele(ordtable t,int situ){				//��ڲ�����ִ��ɾ���ı�Ҫɾ���Ķ���λ�� 
    int i = 0;
	if (situ>t.length || situ<1){				//�жϲ���λ���Ƿ������������С��0��Щ���������
        printf("��ɾ��Ԫ�ص�λ������\n");		//���ڣ�û��Ԫ����Ϣ 
        return t;
    }
    for (i = situ; i <t.length; i++){			//֮���Ԫ����ǰ�� 
        t.point[i-1]=t.point[i];
    }
    t.length--;									//���ȼ�1 
    return t;									//���ڣ�˳���
}
 

int main(){
	int i = 0;
	int j = 0;
	int c1 = 0,c2 = 0;
	int f1 = 0,f2 = -1;
	int d1 = 0;
	printf("��������Ҫ�ı���") ;
	scanf("%d",&j);
    ordtable t=init(j);						//��ʼ��˳��� 
    
    if(j>=0){								//��j<=0ʱ������ʧ�ܣ������к������� 
		printf("������Ԥ���%d��������",j);		//��ʾ�������� 
		for(i; i <j; i ++){					
			scanf("%d",&t.point[i]);			//�������ݣ�����˳��� 
			t.length ++; 
		}
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
	}
    return 0;
}
