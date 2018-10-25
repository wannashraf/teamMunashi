#include<stdio.h>
#include<stdlib.h>

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
int i,total,f,l,t,count,k,cal[100],storage,num,lnum;
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
				k++;
			}else{
				cal[k]+=data[count].cal;
				printf("%d/%d/%d -> %d cal\n",data[count].year,data[count].month,data[count].day,cal[k]);
				break;
			}
		}else if(t < f && t < l){
			
		}else{
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
				k++;
			}else{
				cal[k]+=data[count].cal;
				printf("%d/%d -> %d cal\n",data[count].year,data[count].month,cal[k]);
				break;
			}
		}else if(t < f && t < l){
			
		}else{
			break;
		}
		count++;
	}

}

void SearchMenu(){
	printf("日別でのカロリー、または月別でのカロリーを検索します。\n日別での検索を行うか、月別での検索を行うか選択してください。(a.日別,b.月別,c.終了)->\n");
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
			printf("error:有効な値が選択されていません\n");
			SearchMenu();
			break;
	}
}


//木村担当//
void Sort()
{
}

void YearSort() 
{
}

