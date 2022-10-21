#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int a[3][4]={{27,12,23,56},{37,2,56,46},{-12,-34,56,8}};	//定义数组
	int max=a[0][0];											//max定义及大小初始化
	vector<int> maxX,maxY;										//max坐标容器定义及初始化
	maxX.push_back(0);
	maxY.push_back(0);
	
	//遍历循环查找max并且记录值和坐标
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(a[i][j]>=max){
				//最大值发生更新，清空容器重新计数
				if(a[i][j]>max){
					maxX.erase(maxX.begin(),maxX.end());
					maxY.erase(maxY.begin(),maxY.end());
					max=a[i][j];
				}
				maxX.push_back(i);
				maxY.push_back(j);
			}
		}
	}

	//最终输出
	for(int i=0;i<maxX.size();i++)
		printf("max=%d,row=%d,column=%d\n",max,maxX[i],maxY[i]);
	return 0;
}


