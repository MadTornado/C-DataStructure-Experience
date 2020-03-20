#include <stdio.h>
#include <stdlib.h>
#define parkmax 5
#define waitmax 10
#define queuemax 100
//----------定义两个栈和队列---------- 
//定义栈1作为停车场 
typedef struct Parkstack{	//定义一个结构体 
	int pdata[parkmax]; 	//存储停车元素的数组
	int parkpoint;			//栈顶指针 
}Parkstack;	
//定义栈2作为等候场 
typedef struct Waitstack{	//定义一个结构体 
	int wdata[waitmax];		//存储暂时等候车辆出停车场的数组
	int waitpoint;			//栈顶指针 
}Waitstack;
//定义队列作为便道 
typedef struct Queue{		//定义一个结构体作为队列 
	int data[queuemax];		//存储元素的数组
	int headpoint;			//队头指针
	int tailpoint;	 		//队尾指针 
}Queue;

//----------初始化两个栈和队列---------- 
//停车场栈1初始化 
Parkstack *parkcreate(){	//入口参数：无 
	Parkstack *p=(Parkstack*)malloc(sizeof(Parkstack));	//分配新空间 
	p->parkpoint=0;			//分配指针 
	return p;				//出口参数：初始化完成的结构体指针 
}
//等候场栈2初始化 
Waitstack *waitcreate(){	//入口参数：无 
	Waitstack *p=(Waitstack*)malloc(sizeof(Waitstack));//分配新空间 
	p->waitpoint=0;			//分配指针
	return p;				//出口参数：初始化完成的结构体指针 
}							
//便道队列初始化 
Queue *queuecreate(){		//入口参数：无 
	Queue *p=(Queue*)malloc(sizeof(Queue));//分配新空间 
	p->headpoint=p->tailpoint=0;	//分配指针
	return p;						//出口参数：初始化完成的结构体指针 
}

//----------入栈或入队列---------- 
//入停车场栈1操作 
int ppush(Parkstack *stack, int num){	//入口参数：栈，要入栈的数值 
	if(stack->parkpoint == parkmax){	//检测是否栈满
		return 0; 						//出口参数：栈满返回0 
	}else{
		stack->pdata[stack->parkpoint++] = num;	//将数值推入栈中 
		return 1;								//出口参数：成功返回1 		
	}
} 
//入等候场栈2操作 
int wpush(Waitstack *stack, int num){	//入口参数：栈，要入栈的数值 
	if(stack->waitpoint == waitmax){	//检测是否栈满
		return 0; 						//出口参数：栈满返回0 
	}else{
		stack->wdata[stack->waitpoint++] = num;	//将数值推入栈中 
		return 1;								//出口参数：成功返回1 		
	}
} 
//入便道队列
int qenter(Queue *queue, int num){		//入口参数：队列，要入队的数值 
	if(queue->tailpoint == queuemax){	//判断队列是否已满 
		return 0;						//已满返回0 
	}else{
		queue->data[queue->tailpoint++] = num;	//未满返回1 
	}
}

//----------出栈或出队列---------- 
//出停车场栈1操作 
int ppop(Parkstack *stack){ 		//入口参数：栈
	if(stack->parkpoint == 0){		//检测是否栈空 
		return 0; 					//出口参数：栈空返回0 
	}else{
		int num = stack->pdata[--stack->parkpoint];	//记录出栈的数值 
		return num;									//出口参数：成功出栈返回出栈的数值 	
	}
} 
//出等候场栈2操作 
int wpop(Waitstack *stack){ 		//入口参数：栈
	if(stack->waitpoint == 0){		//检测是否栈空 
		return 0; 					//出口参数：栈空返回0 
	}else{
		int num = stack->wdata[--stack->waitpoint];	//记录出栈的数值 
		return num;									//出口参数：成功出栈返回出栈的数值 	
	}
} 
//出便道队列
int qout(Queue *queue){					//入口参数：队列 
	if(queue->tailpoint-queue->headpoint == 0){		//判断队列是否为空，为空时队头指针和队尾指针为同一个 
		return 0;						//队列为空返回0 
	}else{
		int num = queue->data[queue->headpoint];	//记录即将出队列的值 
		queue->headpoint ++;			//队头指针向下移动 
		return num;						//返回出队列值 
	}
}

//----------判断栈或队列是否为空---------- 
//判断停车场栈1是否为空 
int pempty(Parkstack *stack){		//入口参数：栈 
	if(stack->parkpoint == 0){		//检测是否栈空 
		return 1;					//出口参数：栈空返回1
	}else{
		return 0;					//出口参数：栈不空返回0 
	}
}
//判断便道队列是否为空
int qempty(Queue *queue){			//入口参数：队列 
	if(queue->tailpoint-queue->headpoint == 0){		//判断队列是否为空，为空时队头指针和队尾指针为同一个 
		return 0;					//出口参数：队列为空返回0 
	}else{
		return 1;					//出口参数：队列不空返回1 
	}
}
//判断等候场栈2是否为空用不到

//----------判断栈或队列是否为满---------- 
//判断停车场栈1是否满 
int pfull(Parkstack *stack){				//入口参数：栈 
	if(stack->parkpoint == parkmax){	//检测是否栈满 
		return 1;						//出口参数：栈满返回1
	}else{
		return 0;						//出口参数：栈不满返回0 
	}
}
//判断等候场栈2和便道队列是否为满用不到 		

//----------打印停车情况---------- 
//打印停车场内停车状况 
void pdisp(Parkstack *stack){				//入口参数：栈 
	int i = 0;
	printf("现在停车场停车状况为：\n");
	for(i = 0; i<stack->parkpoint; i++){
		printf("%d号车：%d\n",i+1,stack->pdata[i]);	//出口参数：打印停车场停车状况 
	} 
} 
//打印便道内停车状况
void qdisp(Queue *queue){					//入口参数：队列 
	int i = 0;
	printf("现在便道上停车状况为：\n");
	for(i = queue->headpoint; i<queue->tailpoint;i ++){
		printf("%d\n",queue->data[i]);	//出口参数：打印便道停车状况 
	}
	printf("\n");
}

//----------主函数用于控制整个系统----------
int main(){
	int i = 0; 
	int ch = 0;				//ch用于记录用户停车或者出车状态 
	int t = 0;				//t用于记录用户车牌号或停车场出车编号或便道出车编号 
	int a = 0;				//a用于记录出停车场的车牌号和从便道进入或出停车场的车牌号 
	int t1 = 0;				//t1用于记录停车时间 
	int c = 0; 
	Parkstack *park;		//停车场 
	Waitstack *wait;		//等候场 
	Queue *road;			//便道
	park = parkcreate();	//停车场初始化 
	wait = waitcreate();	//等候场初始化 
	road = queuecreate();	//便道初始化 
	while(1){			//循环系统 
		ch = 0;			//ch用于记录用户停车或者出车 
		pdisp(park);	//打印停车场停车情况 
		qdisp(road);	//打印便道停车情况 
		printf("请用数字输入要执行的操作(1.停车 2.出车):");
		scanf("%d",&ch);	//记录用户停车情况 
		if(ch == 1){		//如果停车 
			printf("请输入车牌号码");
			scanf("%d",&t);	//记录用户停车号码 
			if(!pfull(park)){
				ppush(park,t);	//压入停车场栈1 
				printf("\n停车成功！您的车停在停车场内\n");
				c++;		//如果停车场内停车成功，则停车数+1 
			}else{
				qenter(road,t);	//进入便道队列 
				printf("停车成功！您的车停在便道上\n");
			}
		}else if(ch == 2){	//如果出车 
			printf("请输入停车场内对应的编号(1~5)：");
			scanf("%d",&t);	//记录用户停车场出车编号 
			for(i = 0; i<c-t; i++){
				wpush(wait,ppop(park));	//出停车场之后的车牌，压入等待场栈 
			}
			a = ppop(park);				//记录出停车场车牌号 
			printf("出停车场的车牌号为：%d\n",a);
			for(i =0; i<c-t; i++){	
				ppush(park,wpop(wait));	//将等待场栈车牌号，压入停车场栈 
			}
			if(qempty(road)){			//如果队列非空，则有车从便道进入停车场 
				a = qout(road);			//最先的出队列
				printf("从便道进入停车场的车牌号为：%d\n",a);
				ppush(park,a); 
			}
			printf("请输入停车时间(小时)，不满1小时按1小时收费，收费标准5元/小时:");
			scanf("%d",&t1);
			printf("共需付款%d元\n",t1*5);
		}else{				//如果不停车也不出车 
			printf("输入非法！请重新输入！\n");
		}
	} 
	return 0;
}
