#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//自分担当
void Menu();			//最初のメニュー
void InputMenu();		//入力のメニュー
void OutputMenu();		//出力のメニュー
void Dictionary();		//辞書のメニュー
void DicClean();		//辞書の整理関数
void DicRead();			//読み取り関数
void DicOutput();		//出力関数
void DicSortCal(int X);	//カロリーソート関数
void DicSearchName();	//検索関数

//他の人の担当
void Input();			//通常入力関数
void Add();				//追加入力関数
void Delete();			//データ削除関数
void Read();			//データ読み込み関数
void CalorieSort();		//カロリーソート関数
void DateSort();		//日付ソート関数
void SearchMenu();		//範囲指定関数

struct Data {
	int year;		//年
	int month;		//月
	int day;		//日
	char time[10];	//朝昼夜
	char menu[50];	//メニュー
	int cal;		//カロリー
}data[10000];

struct Dic {
	char menu[50];	//辞書用メニュー
	int calorie;	//辞書用カロリー
}dic[10000];

int main() {
	Menu();			//メニュー関数へ
	return 0;
}

int DataCount;

void Menu() {
	int Num;			//int型に変換後入れる変数
	char Numc[10];		//入力させる変数
	printf("＊食事管理プログラムへようこそ＊\n\n");
	printf("≪ ・・・メインメニュー・・・ ≫\n");
	while (1)
	{
		printf("＊あなたのする作業を選んでください＊\n");
		printf(" →  1.突撃！今日の三食\n");
		printf(" →  2.食事の軌跡\n");
		printf(" →  3.食事辞典\n");
		printf(" →  0.終了\n→  ");
		scanf("%s", Numc);
		if (strlen(Numc) == 1) Num = Numc[0] - 48;//一文字だった場合に変換する
		switch (Num)
		{
		case 1:
			InputMenu();	//入力メニューへ
			break;
		case 2:
			OutputMenu();	//出力メニューへ
			break;
		case 3:
			Dictionary();	//辞書関数へ
			break;
		case 0:
			printf("＊プログラムを終了します＊\n＊またのご利用お待ちしております＊\n\n");
			break;
		default:
			printf("＊入力が間違っています＊\n＊再度入力してください＊\n\n");
			break;
		}
		if (Num == 0)break;
	}
}

void InputMenu() {
	int Num;			//int型に変換後入れる変数
	char Numc[10];		//入力させる変数
	printf("--------------------------------------------\n");
	printf("≪・・・突撃！今日の三食・・・≫\n");
	while (1)
	{
		printf("＊何をしようかな・・・＊\n");
		printf(" →  1.今日の食事を記録する\n");
		printf(" →  2.食べ物を追加する\n");
		printf(" →  3.食べ物を変更・削除する\n");
		printf(" →  0.何もしない\n→  ");
		scanf("%s", Numc);
		if (strlen(Numc) == 1) Num = Numc[0] - 48;//一文字だった場合に変換する
		switch (Num)
		{
		case 1:
			Input();		//三食の入力関数へ
			break;
		case 2:
			Add();			//食事の追加機能へ
			break;
		case 3:
			Read();			//読み取り関数
			Delete();		//削除関数へ
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
	int Num;			//int型に変換後入れる変数
	char Numc[10];		//入力させる変数
	printf("--------------------------------------------\n");
	printf("≪・・・食事の軌跡・・・≫\n\n");
	while (1)
	{
		printf("＊何をしようかな…＊\n");
		printf(" →  1.カロリー順で記録を見る\n");
		printf(" →  2.日付順で記録を見る\n");
		printf(" →  3.日付の範囲を指定して記録を見る\n");
		printf(" →  0.何もしない\n→  ");
		scanf("%s", Numc);
		if (strlen(Numc) == 1) Num = Numc[0] - 48;//一文字だった場合に変換する
		switch (Num)
		{
		case 1:
			Read();			//読み取り関数
			CalorieSort();	//カロリー順でソート
			break;
		case 2:
			Read();			//読み取り関数
			DateSort();		//日付順でソート
			break;
		case 3:
			SearchMenu();		//日付の範囲指定してソート
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
	int Num;			//int型に変換後入れる変数
	char Numc[10];		//入力させる変数
	printf("--------------------------------------------\n");
	printf("≪ ・・・食事辞典・・・ ≫\n\n");
	DicClean();			//重複をなくす関数へ
	while (1)
	{
		printf("＊何を調べますか＊\n");
		printf(" →  1.食べた食事の一覧を見る\n");
		printf(" →  2.カロリー順で並び替える\n");
		printf(" →  3.名前検索\n");
		printf(" →  0.何もしない\n→  ");
		DicRead();				//データ読み取り関数へ
		scanf("%s", Numc);
		if (strlen(Numc) == 1) Num = Numc[0] - 48;//一文字だった場合に変換する
		switch (Num)
		{
		case 1:
			printf("\n");
			DicOutput();		//出力関数へ
			break;
		case 2:
			printf(" 　→  1.昇順で並び替える\n");
			printf(" 　→  2.降順で並び替える\n");
			int S;
			char sc[10];
			scanf("%s", sc);
			if (strlen(sc) == 1) S = sc[0] - 48;//一文字だった場合に変換する
			switch (S) {
			case 1:
				DicSortCal(S);		//ソートの関数へ(引数で分岐)
				break;
			case 2:
				DicSortCal(S);		//ソートの関数へ(引数で分岐)
				break;
			default:
				printf("＊入力が間違っています＊\n＊戻ります＊\n\n");
				break;
			}
			if (S == 1 || S == 2) {		//1か2の場合並び替え完了と出す
				printf("・\n・\n＊＊・・・カロリー順で並び替えが完了しました・・・＊＊\n\n");
			}
			break;
		case 3:
			DicSearchName();			//辞書内検索用関数へ
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
	bool s[10000];		//重複判定用フラグ
	int count = 0;

	fi = fopen("Calorie.txt", "r");
	while (fscanf(fi, "%d/%d/%d/%s /%s /%d\n", &data[count].year, &data[count].month, &data[count].day, data[count].time, data[count].menu, &data[count].cal) != EOF) {
		count++;
	}
	for (int i = 0; i < count; i++) {
		s[i] = true;		//全てにtrue
	}

	fclose(fi);
	fo = fopen("Dictionary.txt", "w");

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (strcmp(data[i].menu, data[j].menu) == 0) {
				s[j] = false;		//同じ値が出たらfalse
			}
		}
	}

	for (int i = 0; i < count; i++) {
		if (s[i]) {
			fprintf(fo, "%s /%d\n", data[i].menu, data[i].cal);//trueのみファイル出力
		}
	}
	fclose(fo);
}

void DicRead() {			//辞書からデータの個数とデータを入手
	FILE *fo;
	fo = fopen("Dictionary.txt", "r");
	DataCount = 0;
	while (fscanf(fo, "%s /%d\n", dic[DataCount].menu, &dic[DataCount].calorie) != EOF) {
		DataCount++;
	}
}

void DicOutput() {
	int i;
	for (i = 0; i < DataCount; i++) {
		printf("%s  ......  %dkcal\n", dic[i].menu, dic[i].calorie);//辞書内全データ出力
	}
	printf("\n＊..以上 %d 品が登録されています..＊\n\n", DataCount);
}

void DicSortCal(int X) {	//カロリー順並び替え関数
	struct Dic a;
	FILE *F5;
	for (int i = 0; i<DataCount - 1; i++) {			//比較して昇順に並び替え
		for (int j = i + 1; j<DataCount; j++) {
			if (dic[i].calorie < dic[j].calorie) {
				a = dic[i];
				dic[i] = dic[j];
				dic[j] = a;
			}
		}
	}
	F5 = fopen("Dictionary.txt", "w");
	if (X == 1) {//引数が1ならそのまま出力
		for (int i = 0; i < DataCount; i++) {
			fprintf(F5, "%s /%d\n", dic[i].menu, dic[i].calorie);
		}
	}
	else if (X == 2) {//2なら逆順に出力
		for (int i = DataCount - 1; i >= 0; i--) {
			fprintf(F5, "%s /%d\n", dic[i].menu, dic[i].calorie);
		}
	}
	fclose(F5);
}

void DicSearchName() {		//名前検索関数
	int Box, count;
	char str[100];
	char *ret;
	bool ans[10000];//比較のためのフラグ
	while (1) {
		count = 0;
		for (int i = 0; i < DataCount; i++) {//全部trueに
			ans[i] = true;
		}
		printf("検索したい文字列を入力してください（0を入力で終了）\n >>>");
		scanf("%s", str);
		if (strlen(str) == 1) Box = str[0] - 48;
		if (Box == 0) {
			printf("\n＊＊食事辞典メニューに戻ります＊＊\n");
			printf("\n≪ ・・・食事辞典・・・ ≫\n\n");
			break;
		}
		for (int i = 0; i < DataCount; i++) {
			if ((ret = strstr(dic[i].menu, str)) == NULL) {//検索
				ans[i] = false;
			}
			else {
				count++;
			}
		}

		printf("検索した文字列 >>> %s \n", str);
		if (count == 0) {//一つも存在しなかった場合
			printf("\n＊＊---入力した文字列を含むメニューは存在しません---＊＊\n\n");
		}
		else {
			for (int i = 0; i < DataCount; i++) {
				if (ans[i]) {//trueのみ出力
					printf("%s /%dkcal\n", dic[i].menu, dic[i].calorie);
				}
			}
			printf("\n以上 %d 品見つかりました\n\n", count);
		}
	}
}

//森、大谷担当//
void Input() {
	printf("ここで三食の入力を行う。。。\n\n");
}

void Add() {
	printf("ここで追加のの入力を行う。。。\n\n");
}

void Delete() {
	printf("ここでデータの削除を行う。。。\n\n");
}

//尼崎担当//
void SearchMenu() {
	printf("ここでメニューの範囲指定を行う。。。\n\n");
}

//木村担当//
void Read() {
	printf("ここでデータの読み取りを行う。。。\n");
}

void CalorieSort() {
	printf("ここでカロリー順にソートを行う。。。\n\n");
}

void DateSort() {
	printf("ここで日付順にソートを行う。。。\n\n");
}