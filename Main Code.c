/*==--Made by Geonwoo--==*/

#include <stdio.h>
#include <time.h>
#include <windows.h>

int score = 0;
float t;
time_t startTime, endTime;

char Re;

//�⺻���� ���� 
char sentence[4][100] = { "",
	"1", //1�� 
	"�� ��", //2��
	"�� ��"  //3��
};

//Ŀ���� ��ġ�� �Ű��ִ� �Լ� 
void gotoxy(int x, int y) {
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

//�ʱ�ȭ - ����, ũ��, ��, �����, ���۹��� 
void Reset() {
	system("title Geonwoo's Ÿ�ڰ���");
	system("mode con cols=100 lines=30");
	system("color F0");
	system("cls");
	
	gotoxy(46, 2);
	printf("Ÿ�ڰ���");
	
	gotoxy(36, 9);
	printf("���Ͻô� ��ȣ�� �������ּ���");
	
	gotoxy(42, 13);
	printf("1      2      3");
	
	gotoxy(2, 28);
	printf("Made by Geonwoo_Kim");
	
	gotoxy(85, 28);
	printf("Version.1.0.2");
	
	gotoxy(42, 19);
	printf("����� ������: ");
}

//���ӽ����� �غ�ȭ��
void gameReady(int n) {
	system("cls");
	gotoxy(36, 13);
	printf("����� %d���� �����Ͽ����ϴ�.", n);
	Sleep(1000);
	
	system("cls");
	gotoxy(21, 13);
	printf("��� �� ȭ�鿡 ������ ������ \"��Ÿ����\" �Է��Ͻø� �˴ϴ�.");
	/*
	gotoxy(37, 14);
	printf("!!���͸� ��Ÿ���� ������!!");
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

//������ �������� �� + �������� + �ð� ���� 
void gameStart(int n) {
	
	/*
	char trash[1000];
	gets(trash); //���ڳ������߿� �Է¹����� ���� 
	*/
	
	
	system("cls");
	gotoxy(20, 9);
	printf("%s\n", sentence[n]);
	
	gotoxy(20, 10);
	char a[100];
	

	
	startTime = clock();
	gets(a);
	endTime = clock();
	
	score = strcmp(sentence[n], a); //�� ���ڿ��� ������ 0, �ٸ���  
	
	t = (float)(endTime-startTime)/(1000);
	
	Sleep(1000);
	system("cls");
}

main() { while(1) {
	
	Reset();
	
	int Choice;
	scanf("%d", &Choice);
	fflush(stdin); //�Է� ���� ���� 
	
	//���ð� �Ǵ� 
	if (!(Choice == 1 || Choice == 2 || Choice == 3)) {
		gotoxy(36, 20);
		printf("�߸��� ���� �ԷµǾ����ϴ�.");
		Sleep(500);
		continue;
	}
	
	gameReady(Choice);                        
	gameStart(Choice);
	
	//�������� �Ǵ� 
	if (score == 0) {
		gotoxy(36, 11);
		printf("�����մϴ�!");
		Sleep(500);
		gotoxy(36, 13);
		printf("Time: %.3f s", t);
	} else {
		gotoxy(36, 11);
		printf("�����ϼ̽��ϴ�.");
	}
	

	Sleep(500);
	gotoxy(36, 18);
	printf("�ٽ��Ͻðڽ��ϱ�? (Y, N): ");
	scanf("%c", &Re);
	fflush(stdin);

	if (Re == 'y' || Re == 'Y')
		continue;
	else
		break;
	
} }
