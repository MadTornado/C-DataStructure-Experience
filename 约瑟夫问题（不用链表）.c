#include<stdio.h>
#define N 50

int main(){
    int a[N],m,n,x,y,i,count = 0;
    do{ 
		printf("��������������");
    	scanf("%d",&n);								//����������n 
    }while(n <=0);
    do{
	    printf("�����뱨��������");
    	scanf("%d",&m);								//���뱨��m 
	}while(m <=0 || m >n);
    x = n;      					//��¼������ 
    for(i = 1; i <=n; i++){
        a[i] = i;
    }
    do{
        for(i = 1; i <=n; i++){
            if(a[i] != 0){     		//�ж��Ƿ���ǰ����ѭ������ 
                count++;    		//���� 
        	}
			if(count == m){			//�ж��Ƿ��Ǳ����� 
                a[i] = 0;    		//���ֵ�����Ϊ0 
                count = 0;			
                x--;       			//���ֺ�����-1 
                if(x ==0){			//�ж��Ƿ����ѭ�� 
                    printf("���һ����%d",i); 	//������һ��	
				}else{
					printf("%d ",i);	//���������
				}	
            }
        }
    }while(x >0);    				//δ��̭����ѭ������ 

    return 0;
}

