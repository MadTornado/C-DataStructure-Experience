#include <stdio.h>
#include <stdlib.h>

//自定义顺序表： 
typedef struct ordtable{
    int *point;		//声明一个长度不确定的动态数组，同时它也是个指针 
    int length;		//记录当前顺序表长度 
    int size;		//记录顺序表分配的存储容量 
}ordtable;

//顺序表初始化： 
ordtable init(int j){								//入口参数：顺序表的长度 
    ordtable t;
    if(j <=0){
    	printf("不能创建一个表长小于等于0的顺序表");
	}else{
    	t.point = (int*)malloc(j*sizeof(int));		//分配空间，构造一个空的顺序表 
	}
    t.length = 0;								//初始化顺序表长度 
    t.size = j;								//初始化存储空间为输入值
    return t;								//出口：顺序表
}

//顺序表的打印： 
void display(ordtable t){					//入口参数：打印的表 
	int i = 0;
 	printf("顺序表中存储的元素分别是:");
	for(i; i <t.length; i ++){				//按顺序输出顺序表中的元素 
        printf("%d ",t.point[i]);			//出口：打印值 
    }
    printf("\n \n");
}

//顺序表的插入： 
ordtable addin(ordtable t,int elem,int situ){	//入口参数：执行插入的表，elem为插入的元素，situ为插入的位置 
    int i = 0; 
	if (situ>t.length+1||situ<1){				//判断插入位置是否比整个表大或者小于0这些不存在情况 
        printf("插入位置有问题\n");
        return t;								//出口：顺序表
    }
    if (t.length==t.size){						//判断是否有多余位置供插入 
        t.point=(int *)realloc(t.point,(t.size+1)*sizeof(int));	//如果没位置了，需要重新申请空间 
        if (!t.point){
            printf("存储分配失败\n");			//如果动态申请内存失败，则报错
            return t;
        }
        t.size+=1;								
    } 
    for (i=t.length+1; i>=situ-1; i--){			//从插入位置开始的后续元素逐个后移
        t.point[i+1]=t.point[i];					
    }
    t.point[situ-1]=elem;						//在插入位置插入元素 
    t.length++;									//加上插入的元素，长度加1 
    return t;									//出口：顺序表
}

//顺序表的查找
int find(ordtable t,int elem){					//入口参数：执行查找的表，要查找的对象 
    int i = 0; 
	for (i; i <t.length; i++){					//依次判断是否是该对象 
       	if (t.point[i]==elem){
           	return i+1;							//出口：查找位置 
       	}
	}
    return -1;									//出口：如果查找失败，返回-1
} 

//顺序表的删除：
ordtable dele(ordtable t,int situ){				//入口参数：执行删除的表，要删除的对象位置 
    int i = 0;
	if (situ>t.length || situ<1){				//判断插入位置是否比整个表大或者小于0这些不存在情况
        printf("被删除元素的位置有误\n");		//出口：没有元素信息 
        return t;
    }
    for (i = situ; i <t.length; i++){			//之后的元素往前补 
        t.point[i-1]=t.point[i];
    }
    t.length--;									//长度减1 
    return t;									//出口：顺序表
}
 

int main(){
	int i = 0;
	int j = 0;
	int c1 = 0,c2 = 0;
	int f1 = 0,f2 = -1;
	int d1 = 0;
	printf("请输入想要的表长：") ;
	scanf("%d",&j);
    ordtable t=init(j);						//初始化顺序表 
    
    if(j>=0){								//当j<=0时，表创建失败，不运行后续步骤 
		printf("请输入预设的%d个整数：",j);		//提示输入数据 
		for(i; i <j; i ++){					
			scanf("%d",&t.point[i]);			//输入数据，建立顺序表 
			t.length ++; 
		}
		display(t);
	
 		printf("输入在哪个位置插入哪个元素:（两个整数）");		//插入元素 
 		scanf("%d %d",&c1,&c2);
		t = addin(t, c2, c1);
		display(t);
	
		printf("输入查找哪个元素:");							//查找元素 
 		scanf("%d",&f1);	
 		f2 = find(t,f1);
 		if(f2 == -1){
			printf("没有该元素\n"); 
		}else{
			printf("查找对象位置为%d\n\n",f2); 
		}
	
		printf("输入要删除的元素位置：");						//删除元素 
	 	scanf("%d",&d1);
		t = dele(t, d1);
		display(t);
	}
    return 0;
}
