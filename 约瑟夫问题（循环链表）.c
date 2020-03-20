#include <stdio.h>
#include <stdlib.h>

//自定义链表 
typedef struct Link{
    int elem;									//值 
    struct Link *next;							//指向下一个节点 
}link;

//链表的初始化和建立 
link *init(int n){								//入口参数：总人数 
    int i;
    link *a; 
    link *p = (link*)malloc(sizeof(link));		//创建一个头结点
    link *temp = p;								//声明一个指针指向头结点，用于遍历链表
    for (i = 1; i <=n; i++){							//生成链表，创建新节点并初始化
        a = (link*)malloc(sizeof(link));		//给a分配空间,为总人数n 
        a->elem = i;							//初始化a
        temp->next = a;							//指针每次都指向链表的最后一个节点 
        temp = a;								//此时a为尾节点，将赋值给临时变量temp 
    }
    a->next=p->next;							//使最后一个结点指向第一个结点，构成一个循环。
    return p;									//出口：建立好的表 
}

link *baoshu(link *p,int n,int m){			//入口参数：表，总人数，报数人数 
    int i,j;
    link *q;
    link *a = p;
    for(i = 1; i <n; i++){						//n代表循环n次结束，全部出局 
        for(j = 1; j <m; j++){					//报数 
            a = a->next;						//a是第j-1个待删除项
        }
        q = a->next;
        a->next = q->next;						//使删除的这个节点前一个结点指向后个结点，构成一个循环。
        printf("%d ",q->elem);					//输出删除的节点值，即为出局的人 
        free(q);								//释放q存储空间，防止内存泄漏 
        p = a;								
    }
    printf("最后一人是%d",p->elem);			//输出最后一人 
    return p;								//出口：返回链表 
}

int main(){
	link *t;
    int n,m;
    do{ 
		printf("请输入总人数：");
    	scanf("%d",&n);								//输入总人数n 
    }while(n <=0);
    do{
	    printf("请输入报数人数：");
    	scanf("%d",&m);								//输入报数m 
	}while(m <=0 || m >n);
    t = init(n);								//初始化表 
    t = baoshu(t,n,m);							//报数函数 
}
