#include <stdio.h>
#include <stdlib.h>

//自定义单链表： 
typedef struct Link{
    int elem;								//值 
    struct Link *next;						//指向下一个节点 
}link;

//单链表的初始化和建立： 
link *init(){
	int i = 0,c; 
	link *p = (link*)malloc(sizeof(link));	//创建一个头结点
    link *temp = p;							//声明一个指针指向头结点，用于遍历链表
    printf("输入数据（至少一个），用回车隔开，ctrl+z并回车停止输入\n"); 
    while((c = scanf("%d",&i) )!= EOF){		//生成链表，创建新节点，当输入不是ctrl+z时，记录数据并运行 
        link *a = (link*)malloc(sizeof(link));	//给a分配空间 
        a->elem = i;						//初始化a并赋值 
        a->next = NULL;						//将temp节点与新建立的a节点建立逻辑关系
        temp->next = a;						//指针每次都指向链表的最后一个节点 
        temp = temp->next;					//返回头指针从而找到整个链表 
    }
    return p;								//出口：返回链表 
}

//单链表的打印： 
void display(link *p){
    link* temp = p;							//将temp指针重新指向头结点
    while (temp->next){						//只要temp指针指向的结点的next不空，就执行输出语句。
        temp = temp->next;					//temp指针指向的结点的下一个节点 
        printf("%d ", temp->elem);			//顺序输出 
    }
    printf("\n \n");
}

//单链表的插入： 
link *addin(link *p, int elem, int situ){		//入口参数：执行插入的表，插入的元素，插入的位置 
    int i = 0;
	link *temp = p;								//创建临时结点temp
    for (i = 1; i < situ; i++){					//找到要插入位置的上一个结点
        temp = temp->next;						//temp指针指向的结点的下一个节点 
        if (temp == NULL){
            printf("插入位置无效\n");
            return p;							//出口：返回链表 
        }
    }
    link *c = (link*)malloc(sizeof(link));	//创建插入结点c
    c->elem = elem;
    c->next = temp->next;					//向链表中插入结点
    temp->next = c;
    return p;								//出口：返回链表 
}

//单链表的查找： 
int find(link *p, int elem){				//入口参数：执行查找的表，查找的元素 
    link *t = p;
    int i = 1;
    while (t->next){						//由于头节点的存在，因此while中的判断为t->next
        t = t->next;						//temp指针指向的结点的下一个节点 
        if (t->elem == elem){				//查找到相应对象，返回元素位置 
            return i;						//出口：返回查找元素的位置 
        }
        i++;
    }										//查找失败则返回-1 
    return -1;								//出口：查找失败，返回-1 
}

//单链表的删除： 
link * dele(link * p, int situ){		//入口参数：执行删除的表，删除的元素位置 
    int i = 0; 
	link * temp = p;
    for (i = 1; i < situ; i++){			//遍历到被删除结点的上一个结点
        temp = temp->next;				//temp指针指向的结点的下一个节点 
        if (temp->next == NULL){
            printf("没有该结点\n");
            return p;					//出口：返回链表 
        }
    }
    link * del = temp->next;			//单独设置一个指针指向被删除结点
    temp->next = temp->next->next;		//更改前一个结点的指针域
    free(del);							//释放del存储空间，防止内存泄漏
    return p;							//出口：返回链表 
}

int main() {
	int i = 0;
	int c1 = 0,c2 = 0;
	int f1 = 0,f2 = -1;
	int d1 = 0;
    link *t = init();					//初始化并建立链表 
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
	
    return 0;
}

