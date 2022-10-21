#include<iostream>
using namespace std;

bool isInGroup[20];

int main(){
	bool isInGroup[20];								//是否还在圈内
	for (int i=0;i<20;i++) 
		isInGroup[i]=true;					
	int personNumberInGroup=20;						//当前圈内人数
	int flag=0;										//报数统计标志
	while(personNumberInGroup>1){					//不到最后一人不停止
		for(int i=0;i<20;i++){						//开始一轮报数
			if(isInGroup[i])						//还在圈内，报数
				flag++;
			if(flag==3){							//达到3的倍数，离开圈子，flag归零
				isInGroup[i]=false;
				personNumberInGroup--;
				flag=0;
				printf("Player %d quited.\n",i);	//打印出局者
			}
		}
	}
	for (int i=0;i<20;i++) 
		if(isInGroup[i])
			printf("Player %d winned.\n",i);		//打印幸存者
	return 0;
}


