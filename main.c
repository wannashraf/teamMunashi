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
	printf(" →突撃！今日の三食")
}

//森、大谷担当//
void Input() {

}

//尼崎担当//
void daily()
{
}

void monthly()
{
}

void yearly()
{
}

void caloriesearch()
{
	int number;
	while(1){
		printf("日別、月別、年別のカロリーを表示します\n数字を入力してください（1.日別　2.月別　3.年別 0.終了）-->" );
		scanf("%d",&number);
		if (number==1){
			printf("1.日別\n");
			daily();
		} else if(number==2){
			printf("2.月別\n");
			monthly();
		} else if(number==3){
			printf("3.年別\n");
			yearly();
		} else if(number==0){
			printf("終了します\n");
			break;
		} else {
			printf("もう一度入力してください\n");
		}
	}
}

//木村担当//
void Sort()
{
}

void YearSort() 
{
}

