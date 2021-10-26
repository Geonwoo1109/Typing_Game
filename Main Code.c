/*==--Made by Geonwoo--==*/

#include <stdio.h>
#include <time.h>
#include <windows.h>

int score = 0;
float t;
time_t startTime, endTime;

char Re;

//기본문장 선택 
char sentence[4][100] = { "",
	"동해물과 백두산이", //1번 
	"마르고 닳도록", //2번
	"하느님이 보우하사"  //3번
};

//커서의 위치를 옮겨주는 함수 
void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

//초기화 - 제목, 크기, 색, 지우기, 시작문구 
void Reset() {
	system("title Geonwoo's 타자게임");
	system("mode con cols=100 lines=30");
	system("color F0");
	system("cls");
	
	gotoxy(46, 2);
	printf("타자게임");
	
	gotoxy(36, 9);
	printf("원하시는 번호를 선택해주세요");
	
	gotoxy(42, 13);
	printf("1      2      3");
	
	gotoxy(2, 28);
	printf("Made by Geonwoo_Kim");
	
	gotoxy(85, 28);
	printf("Version.1.0.2");
	
	gotoxy(42, 19);
	printf("당신의 선택은: ");
}

//게임시작전 준비화면
void gameReady(int n) {
	system("cls");
	gotoxy(36, 13);
	printf("당신은 %d번을 선택하였습니다.", n);
	Sleep(1000);
	
	system("cls");
	gotoxy(21, 13);
	printf("잠시 후 화면에 나오는 문장을 \"오타없이\" 입력하시면 됩니다.");
	/*
	gotoxy(37, 14);
	printf("!!엔터를 연타하지 마세요!!");
	*/
	Sleep(1000);
	
	system("cls");
	gotoxy(49, 13);
	printf("3", n);
	Sleep(900);
	
	system("cls");
	gotoxy(49, 13);
	printf("2", n);
	Sleep(900);
	
	system("cls");
	gotoxy(49, 13);
	printf("1", n);
	Sleep(900);
	
	system("cls");
} 

//게임이 시작했을 때 + 게임진행 + 시간 측정 
void gameStart(int n) {
	
	/*
	char trash[1000];
	gets(trash); //숫자나오는중에 입력받은값 제거 
	*/
	
	
	system("cls");
	gotoxy(20, 9);
	printf("%s\n", sentence[n]);
	
	gotoxy(20, 10);
	char a[100];
	

	
	startTime = clock();
	gets(a);
	endTime = clock();
	
	score = strcmp(sentence[n], a); //두 문자열이 같으면 0, 다르면  
	
	t = (float)(endTime-startTime)/(1000);
	
	Sleep(1000);
	system("cls");
}

main() { while(1) {
	
	Reset();
	
	int Choice;
	scanf("%d", &Choice);
	fflush(stdin); //입력 버퍼 제거 
	
	//선택값 판단 
	if (!(Choice == 1 || Choice == 2 || Choice == 3)) {
		gotoxy(36, 20);
		printf("잘못된 값이 입력되었습니다.");
		Sleep(500);
		continue;
	}
	
	gameReady(Choice);                        
	gameStart(Choice);
	
	//성공실패 판단 
	if (score == 0) {
		gotoxy(36, 11);
		printf("축하합니다!");
		Sleep(500);
		gotoxy(36, 13);
		printf("Time: %.3f s", t);
	} else {
		gotoxy(36, 11);
		printf("실패하셨습니다.");
	}
	

	Sleep(500);
	gotoxy(36, 18);
	printf("다시하시겠습니까? (Y, N): ");
	scanf("%c", &Re);
	fflush(stdin);

	if (Re == 'y' || Re == 'Y')
		continue;
	else
		break;
	
} }
