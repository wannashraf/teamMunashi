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
void Input();

int main()
{
	Input();
	return 0;
}
void Input()
{
	char breakfast[100],lunch[100],dinner[100];
	int year,month,day,breakfastcalorie,lunchcalorie,dinnercalorie,food;
	FILE *fa;
	fa=fopen("Calorie.txt","w");
		if(fa==NULL){
			printf("ファイルが開けませんでした！\n");
		}
		printf("＊食事の新規入力を行います＊\n");
		printf("＊（「0」で入力を終了します）＊\n");

		printf("＊食事した日付を入力してください＊\n");

		printf("＊何年？＊\n");
		printf("＊例：西暦2000年→「2000」と入力してください＊\n");
		scanf("%d",&year);

		printf("＊何月？＊\n");
		printf("＊例：1月→「01」と入力してください＊\n");
		scanf("%d",&month);

		printf("＊何日？＊\n");
		printf("＊例：31日→「31」と入力してください＊\n");
		scanf("%d",&day);

		printf("＊では食事と食事のカロリーの入力を開始します！＊\n");
		printf("＊入力を終了し、次に移りたいときは「0」を入力してください＊\n");

	while(1){
		printf("＊%d年%d月%d日の朝食はなんですか？＊\n",year,month,day);
		scanf("%s",breakfast);
		if(breakfast[0]=='0') break;
		printf("＊朝食のカロリーはいくらですか？＊\n");
		printf("＊例：2000kcal→「2000」と入力してください＊\n");
		scanf("%d",&breakfastcalorie);
		fprintf(fa,"%d/%d/%d/ breakfast / %s /%d\n",year,month,day,breakfast,breakfastcalorie);
	}

	while(1){
		printf("＊%d年%d月%d日の昼食はなんですか？＊\n",year,month,day);
		scanf("%s",lunch);
		if(lunch[0]=='0') break;
		printf("＊昼食のカロリーはいくらですか？＊\n");
		scanf("%d",&lunchcalorie);
		fprintf(fa,"%d/%d/%d/ lunch / %s /%d\n",year,month,day,lunch,lunchcalorie);
	}

	while(1){
		printf("＊%d年%d月%d日の夕食はなんですか？＊\n",year,month,day);
		scanf("%s",dinner);
		if(dinner[0]=='0') break;
		printf("＊夕食のカロリーはいくらですか？＊\n");
		scanf("%d",&dinnercalorie);
		fprintf(fa,"%d/%d/%d/ dinner / %s /%d\n",year,month,day,dinner,dinnercalorie);
	}
	printf("＊%d年%d月%d日の食事の入力が完了しました！＊\n",year,month,day);
	printf("＊メニュー画面に戻ります＊\n");
	fclose(fa);
}

void Add()
{
	char breakfast[100],lunch[100],dinner[100];
	int year,month,day,breakfastcalorie,lunchcalorie,dinnercalorie;
	FILE *fa;
	fa=fopen("Calorie.txt","a");
		if(fa==NULL){
			printf("ファイルが開けませんでした！\n");
		}
		printf("＊食事の追加を行います＊\n");
		printf("＊（「0」で入力を終了します）＊\n");

		printf("＊食事を追加したい日付を入力してください＊\n");

		printf("＊何年？＊\n");
		printf("＊例：西暦2000年→「2000」と入力してください＊\n");
		scanf("%d",&year);

		printf("＊何月？＊\n");
		printf("＊例：1月→「01」と入力してください＊\n");
		scanf("%d",&month);

		printf("＊何日？＊\n");
		printf("＊例：31日→「31」と入力してください＊\n");
		scanf("%d",&day);

		printf("＊追加したい食事を以下から選んで下さい＊");
		printf("＊朝食-→1を入力して下さい＊");
		printf("＊昼食-→2を入力して下さい＊");
		printf("＊夕食-→3を入力して下さい＊");
		scanf("%d",&food);
		printf("＊入力を終了したいときは「0」を入力してください＊\n");

switch (food) {
	case 1:
	while(1){
		printf("＊%d年%d月%d日の朝食はなんですか？＊\n",year,month,day);
		scanf("%s",breakfast);
		if(breakfast[0]=='0') break;
		printf("＊朝食のカロリーはいくらですか？＊\n");
		printf("＊例：2000kcal→「2000」と入力してください＊\n");
		scanf("%d",&breakfastcalorie);
		fprintf(fa,"%d/%d/%d/ breakfast / %s /%d\n",year,month,day,breakfast,breakfastcalorie);
	}

	case 2:
	while(1){
		printf("＊%d年%d月%d日の昼食はなんですか？＊\n",year,month,day);
		scanf("%s",lunch);
		if(lunch[0]=='0') break;
		printf("＊昼食のカロリーはいくらですか？＊\n");
		scanf("%d",&lunchcalorie);
		fprintf(fa,"%d/%d/%d/ lunch / %s /%d\n",year,month,day,lunch,lunchcalorie);
	}

  case 3:
	while(1){
		printf("＊%d年%d月%d日の夕食はなんですか？＊\n",year,month,day);
		scanf("%s",dinner);
		if(dinner[0]=='0') break;
		printf("＊夕食のカロリーはいくらですか？＊\n");
		scanf("%d",&dinnercalorie);
		fprintf(fa,"%d/%d/%d/ dinner / %s /%d\n",year,month,day,dinner,dinnercalorie);
	}
}

	printf("＊%d年%d月%d日の食事の入力が完了しました！＊\n",year,month,day);
	printf("＊メニュー画面に戻ります＊\n");
	fclose(fa);
}



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
void YearSort()
{
}
