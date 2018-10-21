#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Menu();
void InputMenu();
void OutputMenu();
void Dictionary();
void DicClean();
void DicOutput();
void DicSortCal();
void DicSortName();

struct Data {
	int year;		//年
	int month;		//月
	int day;		//日
	char youbi;		//曜日
	char time[50];		//朝昼夜
	char menu[50];	//メニュー
	int cal;		//カロリー
}data[100];

struct Dick {
	char menu[50];
	int calorie;
}dic[10000];

int main() {
	Menu();
	return 0;
}

void Menu() {
	int Num;
	printf("＊食事管理プログラムへようこそ＊\n\n");
	printf("≪ ・・・メインメニュー・・・ ≫\n");
	while (1)
	{
		printf("＊あなたのする作業を選んでください＊\n");
		printf(" →  1.突撃！今日の三食\n");
		printf(" →  2.食事の軌跡\n");
		printf(" →  3.食事辞典\n");
		printf(" →  0.終了\n→  ");
		scanf("%d", &Num);
		switch (Num)
		{
		case 1:
			InputMenu();
			break;
		case 2:
			OutputMenu();
			break;
		case 3:
			Dictionary();
			break;
		case 0:
			printf("＊プログラムを終了します＊\n＊またのご利用お待ちしております＊\n");
			break;
		default:
			printf("＊入力が間違っています＊\n＊再度入力してください＊\n\n");
			break;
		}
		if (Num == 0)break;
	}
}

void InputMenu() {
	int Num;
	printf("--------------------------------------------\n");
	printf("≪・・・突撃！今日の三食・・・≫\n");
	while (1)
	{
		printf("＊何をしようかな・・・＊\n");
		printf(" →  1.今日の食事を記録する\n");
		printf(" →  2.食べ物を追加する\n");
		printf(" →  3.食べ物を変更・削除する\n");
		printf(" →  0.何もしない\n→  ");
		scanf("%d", &Num);
		switch (Num)
		{
		case 1:
			//InputMenu();
			break;
		case 2:
			//OutputMenu();
			break;
		case 3:
			//Dictionary();
			break;
		case 0:
			printf("＊＊メインメニューへ戻ります＊＊\n\n");
			printf("≪ ・・・メインメニュー・・・ ≫\n");
			break;
		default:
			printf("＊入力が間違っています＊\n＊再度入力してください＊\n\n");
			break;
		}
		if (Num == 0)break;
	}
}

void OutputMenu() {
	int Num;
	printf("--------------------------------------------\n");
	printf("≪・・・食事の軌跡・・・≫\n\n");
	while (1)
	{
		printf("＊何をしようかな…＊\n");
		printf(" →  1.今日の食事を記録する\n");
		printf(" →  2.食べ物を追加する\n");
		printf(" →  3.食べ物を変更・削除する\n");
		printf(" →  0.何もしない\n→  ");
		scanf("%d", &Num);
		switch (Num)
		{
		case 1:
			//InputMenu();
			break;
		case 2:
			//OutputMenu();
			break;
		case 3:
			//Dictionary();
			break;
		case 0:
			printf("＊＊メインメニューへ戻ります＊＊\n\n");
			printf("≪ ・・・メインメニュー・・・ ≫\n");
			break;
		default:
			printf("＊入力が間違っています＊\n＊再度入力してください＊\n\n");
			break;
		}
		if (Num == 0)break;
	}
}

void Dictionary() {
	int Num;
	printf("--------------------------------------------\n");
	printf("≪ ・・・食事辞典・・・ ≫\n\n");
	DicClean();
	while (1)
	{
		printf("＊何を調べますか＊\n");
		printf(" →  1.食べた食事の一覧を見る\n");
		printf(" →  2.カロリー順でソートする\n");
		printf(" →  3.名前順でソートする\n");
		printf(" →  0.何もしない\n→  ");
		scanf("%d", &Num);
		switch (Num)
		{
		case 1:
			DicOutput();
			break;
		case 2:
			DicSortCal();
			break;
		case 3:
			DicSortName();
			break;
		case 0:
			printf("＊＊メインメニューへ戻ります＊＊\n\n");
			printf("≪ ・・・メインメニュー・・・ ≫\n");
			break;
		default:
			printf("＊入力が間違っています＊\n＊再度入力してください＊\n\n");
			break;
		}
		if (Num == 0)break;
	}
}

void DicClean() {
	FILE *fi, *fo;
	bool s[10000];
	int count = 0;

	fi = fopen("test.txt", "r");
	while (fscanf(fi, "%d/%d/%d/%s /%s /%d\n", &data[count].year, &data[count].month, &data[count].day, data[count].time, data[count].menu, &data[count].cal) != EOF) {
		count++;
	}
	for (int i = 0; i < count; i++) {
		s[i] = true;
	}

	fclose(fi);
	fo = fopen("Dictionary.txt", "w");

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (strcmp(data[i].menu, data[j].menu) == 0) {
				s[j] = false;
			}
		}
	}

	for (int i = 0; i < count; i++) {
		if (s[i]) {
			fprintf(fo, "%s /%d\n", data[i].menu, data[i].cal);
		}
	}
	fclose(fo);
}

void DicOutput() {
	int i, Dcount = 0;
	FILE *fo;
	fo = fopen("Dictionary.txt", "r");
	while (fscanf(fo, "%s /%d\n", dic[Dcount].menu, &dic[Dcount].calorie) != EOF) {
		Dcount++;
	}
	for (i = 0; i < Dcount; i++) {
		printf("%s  ......  %dkcal\n", dic[i].menu, dic[i].calorie);
	}
	printf("\n＊..以上 %d 品が登録されています..＊\n\n", Dcount);
	fclose(fo);
}

void DicSortCal() {

}

void DicSortName() {

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

