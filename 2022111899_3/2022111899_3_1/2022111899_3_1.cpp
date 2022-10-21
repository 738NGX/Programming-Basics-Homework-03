#include<iostream>
using namespace std;

int main(){
	int input;									//输入的预期行数
	int **pascalTriangle;						//杨辉三角:动态二维数组
	int i,j,k;									//计数器
	cout<<"请输入要打印的杨辉三角形的总行数n:";
	cin>>input;
	int line=input;								//实际行数
	int column=2*input-1;						//实际列数
	pascalTriangle=new int *[line];				//申请每一行首地址指针

	//为每一行申请空间
	for(i=0;i<line;i++){
		pascalTriangle[i]=new int[column];
	}

	//为杨辉三角所有元素赋初值0
	for(i=0;i<line;i++){
		for(j=0;j<column;j++){
			pascalTriangle[i][j]=0;
		}
	}

	//建立三角型框架:最外层赋值为1
	pascalTriangle[0][input-1]=1;
	j=1;
	for(i=1;i<line;i++){
		pascalTriangle[i][input-1+j]=1;
		pascalTriangle[i][input-1-j]=1;
		j++;
	}

	//计算三角形元素:中间的数为上一行中前一列的数和后一列的数之和
	for(i=1;i<line;i++){
		for(j=1;j<column-1;j++){
			pascalTriangle[i][j]=pascalTriangle[i-1][j-1]+pascalTriangle[i-1][j+1];
		}
	}

	//最终输出:为0不输出，不为0时输出对应值;每一位数字随n的变化调整占位
	switch(line/12){
		case 0:
			for(i=0;i<line;i++){
				for(j=1;j<line-i;j++){
					printf("  ");
				}
				for(j=0;j<column;j++){
					if(pascalTriangle[i][j]==0){
						continue;
					}
					else{
						printf("%-4d",pascalTriangle[i][j]);
					}			
				}
				cout<<endl;		//完整输出一行后换行
			}
			break;
		case 1:
			for(i=0;i<line;i++){
				for(j=1;j<line-i;j++){
					printf("    ");
				}
				for(j=0;j<column;j++){
					if(pascalTriangle[i][j]==0){
						continue;
					}
					else{
						printf("%-8d",pascalTriangle[i][j]);
					}			
				}
			cout<<endl;		//完整输出一行后换行
			}
			break;
		default:
			for(i=0;i<line;i++){
				for(j=1;j<line-i;j++){
					printf("      ");
				}
				for(j=0;j<column;j++){
					if(pascalTriangle[i][j]==0){
						continue;
					}
					else{
						printf("%-12d",pascalTriangle[i][j]);
					}			
				}
			cout<<endl;		//完整输出一行后换行
			}
			break;
	}
	return 0;
}