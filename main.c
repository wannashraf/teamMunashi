#include<stdio.h>

struct Data {
	int year;		//年
	int month;		//月
	int day;		//日
	char time[10];		//朝昼夜
	char menu[50];	//メニュー
	int cal;		//カロリー
}data[100];

int total;

void Menu();
void Read();
void DateSort();
void CalorieSort();
void Delete();

int main(){
	Menu();
	return 0;
}

void Menu(){
	printf("＊食事管理プログラムへようこそ＊\n\n");
	printf("＊あなたのする作業を選んでください＊\n");
	printf(" →突撃！今日の三食\n");
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
void Read()
{
	FILE *fi;
	fi = fopen("test.txt","r");
	while(fscanf(fi,"%d/%d/%d/%s /%s /%d\n",&data[total].year,&data[total].month,&data[total].day,data[total].time,data[total].menu,&data[total].cal) != EOF){
		printf("%d/%d/%d/ %s / %s /%d\n",data[total].year,data[total].month,data[total].day,data[total].time,data[total].menu,data[total].cal);
		total++;
	}
	fclose(fi);
}

void DateSort(){
	int i,j;				//変数
	struct Data a;
	FILE *fw;

	fw = fopen("test.txt","w");
	fprintf(fw,"%d\n",total);
	for(i=0;i<total;i++){
		for(j=i;j<total;j++){
			if(data[i].year > data[j].year){
				a = data[i];
				data[i] = data[j];
				data[j] = a;
			}else if(data[i].year == data[j].year){
				if(data[i].month > data[j].month){
					a = data[i];
					data[i]= data[j];
					data[j] = a;
				}else if(data[i].month == data[j].month){
					if(data[i].day > data[j].day){
						a = data[i];
						data[i] = data[j];
						data[j] = a;
					}
				}
			}
		}
	}
	for(i=0;i<total;i++)
		fprintf(fw,"%d/%d/%d/%s /%s /%d\n",data[i].year,data[i].month,data[i].day,data[i].time,data[i].menu,data[i].cal);
	fclose(fw);
}

void CalorieSort(){
	int i,j,b;
	struct Data a;
	FILE *fw;

	fw = fopen("test.txt","w");
	fprintf(fw,"%d\n",total);

	printf("昇順 -> 1\n");
	printf("降順 -> 2\n");
	scanf("%d",&b);
	switch(b){
		case 1:
			for(i=0;i<total;i++){
				for(j=i;j<total;j++){
					if(data[i].cal > data[j].cal){
						a = data[i];
						data[i] = data[j];
						data[j] = a;
					}
				}
			}
			break;
		default:
			break;
	}
	for(i=0;i<total;i++)
		fprintf(fw,"%d/%d/%d/%s /%s /%d\n",data[i].year,data[i].month,data[i].day,data[i].time,data[i].menu,data[i].cal);
	fclose(fw);
}

void Delete(){
	int i,n;
	struct Data a;
	FILE *fw;

	fw = fopen("test.txt","w");
	printf("消去する日付を入力してください\n");
	scanf("%d",&a.year);
	scanf("%d",&a.month);
	scanf("%d",&a.day);
	for(i=0;i<total;i++){
		if((a.year == data[i].year)&&(a.month == data[i].month)&&(a.day == data[i].day)){
			printf("[%d] %d %d %d %s %s %d\n",i,data[i].year,data[i].month,data[i].day,data[i].time,data[i].menu,data[i].cal);
		}
	}
	printf("削除したい番号を入力してください\n");
	scanf("%d",&n);
	total--;
	for(i=n;i<total;i++){
		data[i] = data[i+1];
	}
	for(i=0;i<total;i++){
		fprintf(fw,"%d/%d/%d/%s /%s /%d\n",data[i].year,data[i].month,data[i].day,data[i].time,data[i].menu,data[i].cal);
	}
	fclose(fw);
}
