#include<stdio.h>
#define N 50

int main(){
    int a[N],m,n,x,y,i,count = 0;
    do{ 
		printf("请输入总人数：");
    	scanf("%d",&n);								//输入总人数n 
    }while(n <=0);
    do{
	    printf("请输入报数人数：");
    	scanf("%d",&m);								//输入报数m 
	}while(m <=0 || m >n);
    x = n;      					//记录总人数 
    for(i = 1; i <=n; i++){
        a[i] = i;
    }
    do{
        for(i = 1; i <=n; i++){
            if(a[i] != 0){     		//判断是否在前几个循环出局 
                count++;    		//报数 
        	}
			if(count == m){			//判断是否是报数者 
                a[i] = 0;    		//出局的人设为0 
                count = 0;			
                x--;       			//出局后，人数-1 
                if(x ==0){			//判断是否继续循环 
                    printf("最后一人是%d",i); 	//输出最后一人	
				}else{
					printf("%d ",i);	//输出出局人
				}	
            }
        }
    }while(x >0);    				//未淘汰完则循环继续 

    return 0;
}

