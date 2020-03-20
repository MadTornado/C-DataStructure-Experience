#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2 -1
//----------结构体定义---------- 
//节点结构体 
typedef struct HNodeType{
    int weight;		//权值 
    int parent;		//父节点 
    int lchild;		//左子树节点 
    int rchild;		//右子树节点 
    char value;		//实际值 
}HNodeType;
 
//编码结构体 
typedef struct {		
    int bit[MAXBIT];	//存储的编码 
    int start;			//头指针位置 
}HCodeType;

//----------哈夫曼树的构造---------- 
void HuffmanTree(HNodeType HuffNode[MAXNODE], int n){ 	//入口参数：节点结构体、含有字符数量，之后需要输入各个节点的权值 
    int i, j;						//循环变量 
	int m1, m2;						//构造哈夫曼树不同过程中两个最小权值节点的权值
	int x1, x2;						//构造哈夫曼树不同过程中两个最小权值节点在数组中的序号 
    for(i = 0; i<2*n-1; i++){		//初始化哈夫曼数组中的节点 
        HuffNode[i].weight = 0;		//权值初始化为0 
        HuffNode[i].parent = -1;	//根节点初始化-1，-1代表没有
        HuffNode[i].lchild = -1;	//左子树初始化-1，-1代表没有
        HuffNode[i].rchild = -1;	//右子树初始化-1，-1代表没有
    }  
    for(i = 0; i<n; i++){			//输入字符和该字符（叶子节点）的权值 
    	printf ("请输入第%d个字符:",i+1);
		scanf("%1s",&HuffNode[i].value);	//记录字符 
        printf("请输入该字符对应的权值：", i,HuffNode[i].value);	
        scanf("%d", &HuffNode[i].weight);	//记录每个叶子节点的权值 
    }
    printf ("\n");
    for(i = 0; i<n-1; i++){			//哈夫曼树的构造 
        m1 = m2 = MAXVALUE;    		//存放两个无父结点且结点权值最小的两个结点 
        x1 = x2 = 0;				//序号初始为0 
        for(j = 0; j<n+i; j++){		//找出所有节点中权值最小、无父节点的两个节点，并合并之为一颗二叉树
            if(HuffNode[j].weight<m1 && HuffNode[j].parent == -1){	//权值小于记录，且没有父节点 
                m2 = m1; 			//记录最小节点 
                x2 = x1; 			//记录节点 
                m1 = HuffNode[j].weight;	//记录当前节点 
                x1 = j;						//记录此时循环值，作为节点 
            }else if(HuffNode[j].weight<m2 && HuffNode[j].parent == -1){	//权值最小，且没有父节点 
                m2 = HuffNode[j].weight;	//记录当前节点 
                x2 = j;						//记录当前循环值，作为节点 
            }
        }    
		//以下为设置找到的两个子节点 x1、x2节点信息 */
        HuffNode[x1].parent  = n+i;		//父节点记录 
        HuffNode[x2].parent  = n+i;		//父节点记录 
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;	//两个节点的权值相加 
        HuffNode[n+i].lchild = x1;		//左孩子节点 
        HuffNode[n+i].rchild = x2;		//右孩子节点 
        printf("%d.左孩子节点为: %d ,右孩子节点为 %d ，根节点为 %d\n", i+1, HuffNode[x1].weight, HuffNode[x2].weight,(HuffNode[x1].weight+HuffNode[x2].weight));
        //打印节点信息 
    }
    printf ("\n");
}							//出口参数：初始化完成后的哈夫曼树 
 
//----------解码---------- 
void decodeing(char string[], HNodeType Buf[], int Num){	//入口参数：想要解码字符串、节点结构体，含有字符种类数量 
	int i;			//循环变量 
	int tmp = 0;	//临时变量 
	int code[1024];			//数字数组，存储数字字符对应的数字 
	int m = 2*Num-1;		//二位一分进行译码 
    char *nump;				//指针 
	char num[1024];			//数字字符数组，存储译码的字符串数字字符 
	for(i = 0; i<strlen(string); i++){	//将字符串转换为字符存入数字字符数组中 
		if(string[i] == '0'){ 			//如果当前字符串元素为0 
			num[i] = 0;        			//转换为字符的0 
		}else{ 							//如果当前字符串元素为1 
  			num[i] = 1;  				//转换为字符的1 
		}                  
	} 
	i = 0;
	nump = &num[0];			//指针指向数字字符数组最开始 
	while(nump<(&num[strlen(string)])){	//当这个指针没指到对应字符最后一位时 
		tmp = m-1;						//节点数减1 
		while(Buf[tmp].lchild != -1 && Buf[tmp].rchild != -1){	//如果左孩子节点和右孩子节点都存在，进入循环 
			if(*nump == 0){				 
    			tmp=Buf[tmp].lchild ;   //存储左孩子节点 
			}else{
				tmp=Buf[tmp].rchild;	//存储右孩子节点 
			} 
			nump++;    					//指向下一个位置的字符，用于记录 
		} 
		printf("%c",Buf[tmp].value);		//出口参数：译码后的字符串                                 
	}
}
 
int main(){
    HNodeType HuffNode[MAXNODE];	//定义节点结构体数组
    HCodeType HuffCode[MAXLEAF];	//定义编码结构体数组
    HCodeType cd; 					//定义临时变量来存放求解编码时的信息
	int n;							//字符个数 
    int i, j;						//循环变量 
	int c, p;						//记录临时编码结构体子节点和父节点 	
    char pp[100];					//记录译码的字符串 
    printf("请输入字符个数：");
    scanf("%d", &n);				//记录字符个数 
    HuffmanTree (HuffNode, n);		//创建哈夫曼树 
    for(i = 0; i<n; i++){			//cd用于后续编码操作 
        cd.start = n-1;				//编码结构体头指针指向最后一位 
        c = i;						//记录子节点
        p = HuffNode[c].parent;		//用于记录父节点 
        while (p != -1){   			//父节点存在时，进入循环 
            if (HuffNode[p].lchild == c)	//如果子节点与当前循环数相同 
                cd.bit[cd.start] = 0;		//当前位设置为0 
            else							//如果子节点与当前循环数不同 
                cd.bit[cd.start] = 1;		//当前位设置为1 
            cd.start--;       				//求编码的低一位
            c = p;                    		//更新叶子节点 
            p = HuffNode[c].parent; 		//更新父节点 
        }
        for(j = cd.start+1; j<n; j++){	
        	HuffCode[i].bit[j] = cd.bit[j];	//记录每个叶子节点的哈夫曼编码 
		}
        HuffCode[i].start = cd.start;		//记录编码的起始位 
    }
    /* 输出已保存好的所有存在编码的哈夫曼编码 */
    for(i = 0; i<n; i++){		//打印哈夫曼编码 
        printf ("%c的哈夫曼编码为: ", HuffNode[i].value);
        for (j = HuffCode[i].start+1; j<n; j++){
            printf ("%d", HuffCode[i].bit[j]);	//打印每个字符的哈夫曼编码 
        }
        printf ("\n");
    }
    printf("\n译码请输入编码:\n");
    scanf("%s",&pp);			//想要执行译码的字符串 
	decodeing(pp,HuffNode,n);	//译码 
	return 0;
}
