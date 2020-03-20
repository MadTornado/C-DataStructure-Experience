#include <stdio.h>
#include <stdlib.h>
#define parkmax 5
#define waitmax 10
#define queuemax 100
//----------��������ջ�Ͷ���---------- 
//����ջ1��Ϊͣ���� 
typedef struct Parkstack{	//����һ���ṹ�� 
	int pdata[parkmax]; 	//�洢ͣ��Ԫ�ص�����
	int parkpoint;			//ջ��ָ�� 
}Parkstack;	
//����ջ2��Ϊ�Ⱥ� 
typedef struct Waitstack{	//����һ���ṹ�� 
	int wdata[waitmax];		//�洢��ʱ�Ⱥ�����ͣ����������
	int waitpoint;			//ջ��ָ�� 
}Waitstack;
//���������Ϊ��� 
typedef struct Queue{		//����һ���ṹ����Ϊ���� 
	int data[queuemax];		//�洢Ԫ�ص�����
	int headpoint;			//��ͷָ��
	int tailpoint;	 		//��βָ�� 
}Queue;

//----------��ʼ������ջ�Ͷ���---------- 
//ͣ����ջ1��ʼ�� 
Parkstack *parkcreate(){	//��ڲ������� 
	Parkstack *p=(Parkstack*)malloc(sizeof(Parkstack));	//�����¿ռ� 
	p->parkpoint=0;			//����ָ�� 
	return p;				//���ڲ�������ʼ����ɵĽṹ��ָ�� 
}
//�Ⱥ�ջ2��ʼ�� 
Waitstack *waitcreate(){	//��ڲ������� 
	Waitstack *p=(Waitstack*)malloc(sizeof(Waitstack));//�����¿ռ� 
	p->waitpoint=0;			//����ָ��
	return p;				//���ڲ�������ʼ����ɵĽṹ��ָ�� 
}							
//������г�ʼ�� 
Queue *queuecreate(){		//��ڲ������� 
	Queue *p=(Queue*)malloc(sizeof(Queue));//�����¿ռ� 
	p->headpoint=p->tailpoint=0;	//����ָ��
	return p;						//���ڲ�������ʼ����ɵĽṹ��ָ�� 
}

//----------��ջ�������---------- 
//��ͣ����ջ1���� 
int ppush(Parkstack *stack, int num){	//��ڲ�����ջ��Ҫ��ջ����ֵ 
	if(stack->parkpoint == parkmax){	//����Ƿ�ջ��
		return 0; 						//���ڲ�����ջ������0 
	}else{
		stack->pdata[stack->parkpoint++] = num;	//����ֵ����ջ�� 
		return 1;								//���ڲ������ɹ�����1 		
	}
} 
//��Ⱥ�ջ2���� 
int wpush(Waitstack *stack, int num){	//��ڲ�����ջ��Ҫ��ջ����ֵ 
	if(stack->waitpoint == waitmax){	//����Ƿ�ջ��
		return 0; 						//���ڲ�����ջ������0 
	}else{
		stack->wdata[stack->waitpoint++] = num;	//����ֵ����ջ�� 
		return 1;								//���ڲ������ɹ�����1 		
	}
} 
//��������
int qenter(Queue *queue, int num){		//��ڲ��������У�Ҫ��ӵ���ֵ 
	if(queue->tailpoint == queuemax){	//�ж϶����Ƿ����� 
		return 0;						//��������0 
	}else{
		queue->data[queue->tailpoint++] = num;	//δ������1 
	}
}

//----------��ջ�������---------- 
//��ͣ����ջ1���� 
int ppop(Parkstack *stack){ 		//��ڲ�����ջ
	if(stack->parkpoint == 0){		//����Ƿ�ջ�� 
		return 0; 					//���ڲ�����ջ�շ���0 
	}else{
		int num = stack->pdata[--stack->parkpoint];	//��¼��ջ����ֵ 
		return num;									//���ڲ������ɹ���ջ���س�ջ����ֵ 	
	}
} 
//���Ⱥ�ջ2���� 
int wpop(Waitstack *stack){ 		//��ڲ�����ջ
	if(stack->waitpoint == 0){		//����Ƿ�ջ�� 
		return 0; 					//���ڲ�����ջ�շ���0 
	}else{
		int num = stack->wdata[--stack->waitpoint];	//��¼��ջ����ֵ 
		return num;									//���ڲ������ɹ���ջ���س�ջ����ֵ 	
	}
} 
//���������
int qout(Queue *queue){					//��ڲ��������� 
	if(queue->tailpoint-queue->headpoint == 0){		//�ж϶����Ƿ�Ϊ�գ�Ϊ��ʱ��ͷָ��Ͷ�βָ��Ϊͬһ�� 
		return 0;						//����Ϊ�շ���0 
	}else{
		int num = queue->data[queue->headpoint];	//��¼���������е�ֵ 
		queue->headpoint ++;			//��ͷָ�������ƶ� 
		return num;						//���س�����ֵ 
	}
}

//----------�ж�ջ������Ƿ�Ϊ��---------- 
//�ж�ͣ����ջ1�Ƿ�Ϊ�� 
int pempty(Parkstack *stack){		//��ڲ�����ջ 
	if(stack->parkpoint == 0){		//����Ƿ�ջ�� 
		return 1;					//���ڲ�����ջ�շ���1
	}else{
		return 0;					//���ڲ�����ջ���շ���0 
	}
}
//�жϱ�������Ƿ�Ϊ��
int qempty(Queue *queue){			//��ڲ��������� 
	if(queue->tailpoint-queue->headpoint == 0){		//�ж϶����Ƿ�Ϊ�գ�Ϊ��ʱ��ͷָ��Ͷ�βָ��Ϊͬһ�� 
		return 0;					//���ڲ���������Ϊ�շ���0 
	}else{
		return 1;					//���ڲ��������в��շ���1 
	}
}
//�жϵȺ�ջ2�Ƿ�Ϊ���ò���

//----------�ж�ջ������Ƿ�Ϊ��---------- 
//�ж�ͣ����ջ1�Ƿ��� 
int pfull(Parkstack *stack){				//��ڲ�����ջ 
	if(stack->parkpoint == parkmax){	//����Ƿ�ջ�� 
		return 1;						//���ڲ�����ջ������1
	}else{
		return 0;						//���ڲ�����ջ��������0 
	}
}
//�жϵȺ�ջ2�ͱ�������Ƿ�Ϊ���ò��� 		

//----------��ӡͣ�����---------- 
//��ӡͣ������ͣ��״�� 
void pdisp(Parkstack *stack){				//��ڲ�����ջ 
	int i = 0;
	printf("����ͣ����ͣ��״��Ϊ��\n");
	for(i = 0; i<stack->parkpoint; i++){
		printf("%d�ų���%d\n",i+1,stack->pdata[i]);	//���ڲ�������ӡͣ����ͣ��״�� 
	} 
} 
//��ӡ�����ͣ��״��
void qdisp(Queue *queue){					//��ڲ��������� 
	int i = 0;
	printf("���ڱ����ͣ��״��Ϊ��\n");
	for(i = queue->headpoint; i<queue->tailpoint;i ++){
		printf("%d\n",queue->data[i]);	//���ڲ�������ӡ���ͣ��״�� 
	}
	printf("\n");
}

//----------���������ڿ�������ϵͳ----------
int main(){
	int i = 0; 
	int ch = 0;				//ch���ڼ�¼�û�ͣ�����߳���״̬ 
	int t = 0;				//t���ڼ�¼�û����ƺŻ�ͣ����������Ż���������� 
	int a = 0;				//a���ڼ�¼��ͣ�����ĳ��ƺźʹӱ��������ͣ�����ĳ��ƺ� 
	int t1 = 0;				//t1���ڼ�¼ͣ��ʱ�� 
	int c = 0; 
	Parkstack *park;		//ͣ���� 
	Waitstack *wait;		//�Ⱥ� 
	Queue *road;			//���
	park = parkcreate();	//ͣ������ʼ�� 
	wait = waitcreate();	//�Ⱥ򳡳�ʼ�� 
	road = queuecreate();	//�����ʼ�� 
	while(1){			//ѭ��ϵͳ 
		ch = 0;			//ch���ڼ�¼�û�ͣ�����߳��� 
		pdisp(park);	//��ӡͣ����ͣ����� 
		qdisp(road);	//��ӡ���ͣ����� 
		printf("������������Ҫִ�еĲ���(1.ͣ�� 2.����):");
		scanf("%d",&ch);	//��¼�û�ͣ����� 
		if(ch == 1){		//���ͣ�� 
			printf("�����복�ƺ���");
			scanf("%d",&t);	//��¼�û�ͣ������ 
			if(!pfull(park)){
				ppush(park,t);	//ѹ��ͣ����ջ1 
				printf("\nͣ���ɹ������ĳ�ͣ��ͣ������\n");
				c++;		//���ͣ������ͣ���ɹ�����ͣ����+1 
			}else{
				qenter(road,t);	//���������� 
				printf("ͣ���ɹ������ĳ�ͣ�ڱ����\n");
			}
		}else if(ch == 2){	//������� 
			printf("������ͣ�����ڶ�Ӧ�ı��(1~5)��");
			scanf("%d",&t);	//��¼�û�ͣ����������� 
			for(i = 0; i<c-t; i++){
				wpush(wait,ppop(park));	//��ͣ����֮��ĳ��ƣ�ѹ��ȴ���ջ 
			}
			a = ppop(park);				//��¼��ͣ�������ƺ� 
			printf("��ͣ�����ĳ��ƺ�Ϊ��%d\n",a);
			for(i =0; i<c-t; i++){	
				ppush(park,wpop(wait));	//���ȴ���ջ���ƺţ�ѹ��ͣ����ջ 
			}
			if(qempty(road)){			//������зǿգ����г��ӱ������ͣ���� 
				a = qout(road);			//���ȵĳ�����
				printf("�ӱ������ͣ�����ĳ��ƺ�Ϊ��%d\n",a);
				ppush(park,a); 
			}
			printf("������ͣ��ʱ��(Сʱ)������1Сʱ��1Сʱ�շѣ��շѱ�׼5Ԫ/Сʱ:");
			scanf("%d",&t1);
			printf("���踶��%dԪ\n",t1*5);
		}else{				//�����ͣ��Ҳ������ 
			printf("����Ƿ������������룡\n");
		}
	} 
	return 0;
}
