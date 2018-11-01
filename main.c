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
void Delete();			//データ削除関
void Read();			//データ読み込み関数
void CalorieSort();		//カロリーソート関数
void DateSort();		//日付ソート関数
void SearchMenu();		//範囲指定関数
void Reset();
void TextRead();

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

<<<<<<< HEAD
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

/// <param name="i">配列初期化用</param>
/// <param name="total">ファイル読み込み配列用</param>
/// <param name="f">(=firstday or firstmonth),検索する期間の最初の日、月</param>
/// <param name="l">(=lastday or lastmonth),検索する期間の最後の日、月</param>
/// <param name="t">(=theday or themonth),ファイルから読み取ったある1つのデータの1年1月1日からの経過日数</param>
/// <param name="count">データ配列用</param>
/// <param name="k">カロリー計算配列用</param>
/// <param name="cal">カロリー計算格納用</param>
/// <param name="storage">日付の比較保存用</param>
/// <param name="num">(=number of days in the month),ファイルから読み取ったある1つのデータの月の日数</param>
/// <param name="lnum">検索する期間の最後の月の日数</param>
/// <param name="j">期間内合計カロリー計算時のカロリー配列の個数保存用</param>
/// <param name="tnumdays">(=total number of days)データ全体の日の合計</param>
/// <param name="tmonths">(=total months)データ全体の月の合計</param>
/// <param name="tcal">(=total calorie)カロリーの合計</param>
/// <param name="dcave">(=daily calorie average)カロリーの日平均</param>
/// <param name="mcave">(=monthly calorie average)カロリーの月平均</param>
int i,total,f,l,t,count,k,cal[100],storage,num,lnum,j,tnumdays,tmonths,tcal,dcave,mcave;
/// <param name="choice">メニュー選択用</param>
char choice;

/// <param name="y">年</param>
/// <param name="m">月</param>
/// <param name="d">日</param>
/// <returns>1年1月1日からの経過日数</returns>
static int GetDays(int y, int m, int d){
	// 1・2月 → 前年の13・14月
	if (m <= 2){
		--y;
		m += 12;
	}
	int dy = 365 * (y - 1); // 経過年数×365日
	int c = y / 100;
	int dl = (y >> 2) - c + (c >> 2); // うるう年分
	int dm = (m * 979 - 1033) >> 5; // 1月1日から m 月1日までの日数
	return dy + dl + dm + d - 1;
}

/// <param name="y">年</param>
/// <param name="m">月</param>
static int DaysInMonth(int y, int m){
	// 1・3・5・7・8・10・12月 → 31日
	// 4・6・9・11月 → 30日
	// 2月 → 指定した年が400で割り切れる、もしくは4で割り切れて100で割り切れない → 29日
	// 2月 → 指定した年が4で割り切れない、もしくは4で割り切れても100で割り切れる → 28日
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
		return 31;
	}else if (m == 4 || m == 6 || m == 9 || m == 11){
		return 30;
	}else if (m == 2){
		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)){
			return 29;
		}else{
			return 28;
		}
	}
}

struct date_daily {
		int year;		//年
		int month;		//月
		int day;		//日
}fdate_daily,ldate_daily;

struct date_monthly {
		int year;		//年
		int month;		//月	
}fdate_monthly,ldate_monthly;

void Reset(){
	total = 0;
	f = 0;
	l = 0;
	t = 0;
	count = 0;
	k = 0;
	for(i=0;i<100;i++){
		cal[i] = 0;
	}
	storage = 0;
	num = 0;
	lnum = 0;
	j = 0;
	tnumdays = 0;
	tmonths = 0;
	tcal = 0;
	dcave = 0;
	mcave = 0;
}

void TextRead(){
	FILE *fi;
	fi = fopen("Calorie.txt","r");
	total = 0;

	while(fscanf(fi,"%d/%d/%d/%s /%s /%d",&data[total].year,&data[total].month,&data[total].day,data[total].time,data[total].menu,&data[total].cal) != EOF){
		total++;
	}
/*動作確認用	int v;
	printf("%d\n",total);
	for(v=0;v<total;v++){
		printf("%d %d %d %s %s %d\n",
		data[v].year,data[v].month,data[v].day,data[v].time,data[v].menu,data[v].cal);
	}*/
	fclose(fi);
}

void Daily(){
	printf("日別の摂取カロリーを算出します。\n 算出したい期間を選択してください。\n 年/月/日〜年/月/日(例:1990/1/1~1990/1/2)->");
	scanf("%d/%d/%d~%d/%d/%d",&fdate_daily.year,&fdate_daily.month,&fdate_daily.day,&ldate_daily.year,&ldate_daily.month,&ldate_daily.day);
	printf("以下に %d/%d/%d〜%d/%d/%d の日別カロリーを算出します。\n",fdate_daily.year,fdate_daily.month,fdate_daily.day,ldate_daily.year,ldate_daily.month,ldate_daily.day);
	
	f=GetDays(fdate_daily.year,fdate_daily.month,fdate_daily.day);
	l=GetDays(ldate_daily.year,ldate_daily.month,ldate_daily.day);
//動作確認用	printf("%d %d\n",f,l);
	while(1){
		t=GetDays(data[count].year,data[count].month,data[count].day);
//動作確認用		printf("%d\n",t);
		if( t > f && t < l || t == f || t == l){
			storage=GetDays(data[count+1].year,data[count+1].month,data[count+1].day);
			if(t == storage){
				cal[k]+=data[count].cal;
			}else if(data[count+1].day != '\0'){
				cal[k]+=data[count].cal;
				printf("%d/%d/%d -> %d cal\n",data[count].year,data[count].month,data[count].day,cal[k]);
				tnumdays++;
				k++;
			}else{
				cal[k]+=data[count].cal;
				printf("%d/%d/%d -> %d cal\n",data[count].year,data[count].month,data[count].day,cal[k]);
				tnumdays++; //else内の日数を足すために+1する
				j=k+1; //else内の日数を足すために+1する
				for(k=0;k<j;k++){
					tcal+=cal[k];
				}
//動作確認用				printf("%d",tcal);
				dcave=tcal/tnumdays;
				printf("日平均のカロリーは %d calです。（小数点以下切り捨て）\nなお、この値は1日の朝昼夕のデータが全て入力されていなくても1日とみなして算出している値です。\n正しい値を取るにはすべての食事の入力を行ってください。\n",dcave);
				break;
			}
		}else if(t < f && t < l){
			
		}else{
			printf("error:有効な値が選択されていません。検索メニューに戻ります\nTips:期間内のデータが3つ未満の場合、カロリー計算は行えません。\n");
			Reset();
			break;
		}
		count++;
	}
}

void Monthly(){

	printf("月別の摂取カロリーを算出します。\n 算出したい期間を選択してください。\n 年/月〜年/月(例:1990/1~1990/2)->");
	scanf("%d/%d~%d/%d",&fdate_monthly.year,&fdate_monthly.month,&ldate_monthly.year,&ldate_monthly.month);
	printf("以下に %d/%d〜%d/%d の月別カロリーを算出します。\n",fdate_monthly.year,fdate_monthly.month,ldate_monthly.year,ldate_monthly.month);
	
	f=GetDays(fdate_monthly.year,fdate_monthly.month,1);
	lnum=DaysInMonth(ldate_monthly.year,ldate_monthly.month);
	l=GetDays(ldate_monthly.year,ldate_monthly.month,lnum);
//動作確認用	printf("%d %d\n",f,l);
	while(1){
		num=DaysInMonth(data[count].year,data[count].month);
		t=GetDays(data[count].year,data[count].month,num);
//動作確認用		printf("%d\n",t);
		if( t > f && t < l || t == f || t == l){
			num=DaysInMonth(data[count].year,data[count].month);
			storage=GetDays(data[count+1].year,data[count+1].month,num);
			if(t == storage){
				cal[k]+=data[count].cal;
			}else if(data[count+1].month != '\0'){
				cal[k]+=data[count].cal;
				printf("%d/%d -> %d cal\n",data[count].year,data[count].month,cal[k]);
				tnumdays+=num;
				tmonths++;
				k++;
			}else{
				cal[k]+=data[count].cal;
				printf("%d/%d -> %d cal\n",data[count].year,data[count].month,cal[k]);
				tnumdays+=num;
				tmonths++; //else内の月の数を足すために+1する
				j=k+1; //else内の月の数を足すために+1する
				for(k=0;k<j;k++){
					tcal+=cal[k];
				}
//動作確認用					printf("%d",tcal);
				mcave=tcal/tmonths;
				dcave=tcal/tnumdays;
				printf("月平均のカロリーは %d cal,日平均のカロリーは %d calです。（小数点以下切り捨て）\nなお、この値は1日の朝昼夕のデータが全て入力されていなくても1日とみなし、\n1月のデータが全て入力されていなくても1月とみなして算出している値です。\n正しい値を取るにはすべての食事の入力を行ってください。\n",mcave,dcave);
				break;
			}
		}else if(t < f && t < l){
			
		}else{
			printf("error:有効な値が選択されていません。検索メニューに戻ります\nTips:期間内のデータが3つ未満の場合、カロリー計算は行えません。\n");
			Reset();
			break;
		}
		count++;
	}

}

void SearchMenu(){
	printf("------------------------------------------------------------------------------------\n日別でのカロリー、または月別でのカロリーを検索します。\n日別での検索を行うか、月別での検索を行うか選択してください。(a.日別,b.月別,c.終了)->\n");
	scanf("%c",&choice);
	if (choice == '\n'){
		scanf("%c",&choice);
	}
	switch(choice){
		case 'a':
			printf("日別検索\n");
			Reset();
			TextRead();
			Daily();
			SearchMenu();
			break;
		case 'b':
			printf("月別検索\n");
			Reset();
			TextRead();
			Monthly();
			SearchMenu();
			break;
		case 'c':
			printf("終了します\n");
			break;
		default:
			printf("error:有効な値が選択されていません\n終了します\n");
			break;
	}
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