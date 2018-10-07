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
	char ymd[10];
	fa=fopen("Calorie.txt","a");
	if(fa==NULL){
		printf("ファイルが開けませんでした！\n");
	}
	printf("＊食事の新規追加を行います＊\n");
	printf("＊（「0」で入力を終了します）＊\n");
	printf("＊食事した日付を入力してください＊\n");
	printf("＊（例：2018年1月1日→2018/01/01）＊\n");
	scanf("%s",&ymd[10]);
	printf("＊では食事の入力を開始します！＊\n");
	printf("＊何も食べていない時は「0」を入力してください！＊\n");
	printf("＊%d年%d月%d日の朝食はなんですか？＊\n",year,month,day);
	scanf("%s",&morning);
	printf("朝食のカロリーはいくらですか？＊\n");
	scanf("%d",&morningcalorie);
	printf("＊%d年%d月%d日の昼食はなんですか？＊\n",year,month,day);
	scanf("%s",&lunch);
	printf("昼食のカロリーはいくらですか？＊\n");
	scanf("%d",&lunchcalorie);
	printf("＊%d年%d月%d日の夕食はなんですか？＊\n",year,month,day);
	scanf("%s",&dinner);
	printf("夕食のカロリーはいくらですか？＊\n");
	scanf("%d",&dinnercalorie);
	printf("＊%d年%d月%d日の間食はなんですか？＊\n",year,month,day);
	scanf("%s",&break);
	printf("夕食のカロリーはいくらですか？＊\n");
	scanf("%d",&break);

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

