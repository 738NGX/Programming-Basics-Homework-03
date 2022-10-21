#include<iostream>
#include<vector>
using namespace std;

vector<int> dateNum(int date,bool leapYear);
bool ifLeapYear(int year);
int year2startDay(int year);

const int tgDate=13;		//需要求的目标日期

int main(){
	int day[7]={0}; 		//day[n]即星期n
	int n;					//输入年数
	cout<<"请输入n:";
	cin>>n;

	//计数阶段
	for(int year=1900;year<1900+n;year++){
		for(int month=1;month<=12;month++){
			switch((dateNum(tgDate,ifLeapYear(year))[month-1]%7+year2startDay(year)-1)%7){
				//计算year年month月tgDate日是星期几，表达式结果范围在-1~6之间，对应结果如下:
				case -1: day[6]++; break;  case 0: day[0]++; break;
				case 1: day[1]++; break;   case 2: day[2]++; break;
				case 3: day[3]++; break;   case 4: day[4]++; break;
				case 5: day[5]++; break;   case 6: day[6]++; break;
			}
		}
	}

	//最终输出
	cout<<"MON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN"<<endl;
	for(int i=1;i<=6;i++){
		cout<<day[i]<<"\t";
	}
	cout<<day[0]<<endl;
	return 0;
}

/**
 * @brief 输入日期，将每月的该日期转换为其在一年中的第几天
 * 
 * @param date 输入日期
 * @param leapYear 是否为闰年
 * @return 每月date日所对应的在一年中的第几天，一个长度为12的整型数容器
 */
vector<int> dateNum(int date,bool leapYear){
	vector<int> target;
	int n=date;	
	target.push_back(n);
	for(int i=1;i<12;i++){
		switch(i){
			case 1: n+=31; break; case 11: n+=30; break;
			case 2:
				if(!leapYear)
					n+=28;
				else
					n+=29;
				break;
			case 3: n+=31; break; case 4: n+=30; break;
			case 5: n+=31; break; case 6: n+=30; break;
			case 7: n+=31; break; case 8: n+=31; break;
			case 9: n+=30; break; case 10: n+=31; break;
		}
		target.push_back(n);
	}
	return(target);
}

/**
 * @brief 判断某个年份是否为闰年
 * 
 * @param year 输入年份
 * @return true 是闰年
 * @return false 不是闰年
 */
bool ifLeapYear(int year){
	return((year%4==0&&year%100!=0)||(year%400==0));
}

/**
 * @brief 输入一个1900年及以后的年份，计算其1月1日是星期几
 * 
 * @param year 输入年份
 * @return year年的1月1日是星期几
 */
int year2startDay(int year){
	int startDay=1;					//year年的1月1日是星期几
	for(int i=1901;i<=year;i++){
		if(ifLeapYear(i-1))
			startDay+=2;
		else
			startDay++;
		if(startDay>=7)
			startDay-=7;
	}
	return(startDay);
}



