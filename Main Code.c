/*==--Made by Geonwoo--==*/

#include <stdio.h>
#include <time.h>
#include <windows.h>

int score = 0;
float t;
time_t startTime, endTime;

char Re;
char sentence[6][100] = {"",
	"동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라 만세", //1번  
	"저기있는 저 분은 박법학박사이고, 여기있는 이 분은 백법학박사이다.", //2번 
	"너에게 난 해질녘 노을처럼 한편에 아름다운 추억이 되고",  //3번 
	"레지기가가가가가 꽁기깅강꽁기깅깅강꽁기깅강공강뿌와앙", //4번
	"슈....슈...슈슉....슈....슈......슈슉...ㅅ...시...야발롬아..." //5번 
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
	
	gotoxy(41, 13);
	printf("1   2   3   4   5");
	
	gotoxy(2, 28);
	printf("Made by Geonwoo_Kim");
	
	gotoxy(85, 28);
	printf("Version.1.1.0");
	
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
	gotoxy(21, 15);
	printf("한영키 한번 눌러주세요!");
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
	gotoxy(15, 9);
	printf("%s\n", sentence[n]);
	
	gotoxy(15, 10);
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
	if (!(Choice == 1 || Choice == 2 || Choice == 3 || Choice == 4 || Choice == 5)) {
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
	gotoxy(36, 16);
	printf("(한영키 한 번 눌러주세요)");
	gotoxy(36, 18);
	printf("다시하시겠습니까? (Y or n): ");
	scanf("%c", &Re);
	fflush(stdin);

	if (Re == 'Y' || Re == 'y')
		continue;
	else
		break;
	
} }
