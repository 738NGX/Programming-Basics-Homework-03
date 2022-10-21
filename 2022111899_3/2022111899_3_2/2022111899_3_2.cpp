#include<iostream>
#include<vector>
using namespace std;

const int len=5;							//字符串个数

int main(){
	int i,j;								//计数器
	bool flag;								//记录一次起泡中是否发生过交换
	vector<string> str;						//字符串容器
	string input;							//用户输入的字符串
	cout<<"Please input strings:"<<endl;

	//用户输入
	for(i=1;i<=len;i++){
		cin>>input;
		str.push_back(input);
	}
	cout<<endl;

	//冒泡排序
	for(i=1;i<len;i++){
 		flag=false;							//记录重置
		for(j=0;j<len-i;j++){
			if(str[j+1]<str[j]){
				str[j].swap(str[j+1]);		//字符串交换
				flag=true;					//标记
			}
		}
		if(!flag){
			break;							//没有发生交换,终止排序
		}
	}

	//最终输出
	cout<<"Sorted Strings:"<<endl;
	for(i=0;i<len;i++){
		cout<<str[i]<<endl;
	}
	return 0;
}



