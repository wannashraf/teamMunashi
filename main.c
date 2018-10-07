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
	int total;
	FILE *fi;
	
	fi = fopen("","r");
	
	total = 0;
	while(fi != EOF){
		fscanf("%d / %d / %d (%c) %c %s %dkcal",&data[total].year,&data[total].month,&data[total]day,&data[total].youbi,&data[total].time,data[total].menu,&data[total].cal);
		total++;
	}
	YearSort();
}

void YearSort(){
	int i,j;				//変数
	struct Data a;

	for(i=0;i<total;i++){
		for(j=i;j<total;j++){
			if(data[i].year > data[j].year){
				a = data[i];
				data[i] = data[j];
				data[j] = a;
			}else if(data[i].year = data[j].year){
				if(data[i].month > data[i].month){
					a = data[i];
					data[i] = data[j];
					data[j] = a;
				}else if(data[i].month = data[j].month){
					if(data[i].day > data[j].day){
						a = data[i];
						data[i] = data[j];
						data[j] = a;
					}
				}
			}
		}
	}
}

