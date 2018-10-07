#include<stdio.h>

struct Data {
	int year;		//年
	int month;		//月
	int day;		//日
	char youbi;		//曜日
	char time;		//朝昼夜
	char menu[50];	//メニュー
	int cal;		//カロリー
}data[100];

int main(){
	Menu();
	return 0;
}

void Menu(){
	printf("＊食事管理プログラムへようこそ＊\n\n");
	printf("＊あなたのする作業を選んでください＊\n");
	printf(" →突撃！今日の三食");
	printf(" →食事の軌跡");
}

//森、大谷担当//
void Input() {

}

//尼崎担当//
void daily()
{
}

void weekly()
{
}

void monthly()
{
}

void caloriesearch()
{
}

//木村担当//
void Sort()
{
}

void YearSort() 
{
}

