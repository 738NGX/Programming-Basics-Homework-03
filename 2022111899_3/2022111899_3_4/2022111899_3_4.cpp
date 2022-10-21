#include<iostream>
using namespace std;

int main()
{
	int a[3][4]={{30,25,23,56},{12,2,6,46},{-12,-34,16,28}};	//定义数组
	int max=a[0][0];											//max大小初始化
	int maxX,maxY;												//max坐标初始化
	
	//遍历循环查找max并且记录值和坐标
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(a[i][j]>max){
				max=a[i][j];
				maxX=i;
				maxY=j;
			}
		}
	}

	//最终输出
	printf("max=%d,row=%d,column=%d\n",max,maxX,maxY);
	return 0;
}


