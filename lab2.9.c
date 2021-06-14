#include <stdio.h>
#include <locale.h>
#include <malloc.h>

void version(void);
double* input();
void rus(double *len);
void output(double *len);
void eng(double* len);

void main(void){
	int n; double* len;
	
	setlocale(LC_ALL, "Rus");
	len = input();
	do {
		printf("\n1.������� � ������� ������������ �������\n2.������� � ���������� ������������ �������\n3.���������� � ������ � ������\n4.����� � ��\n5.����������\n");
		printf("\n������� ����� ����:\n");
		scanf_s("%d", &n);
		while (getchar() != '\n');
		if (n == 1) {
			rus(len);
		}
		if (n == 2) {
			eng(len);
		}
		if (n == 3) {
			version();
		}
		if (n == 4) {
			output(len);
		}
		if(n<=0||n>=6) printf("������� ���������� ����� ����!\n");
	} while (n != 5);
}

double* input() {
	double *len1;
	len1 = (double*)malloc(4 * sizeof(double));
	printf("������� �������� �����\n���������:");
	scanf_s("%lf", &len1[0]);
	printf("�����:");
	scanf_s("%lf", &len1[1]);
	printf("����������:");
	scanf_s("%lf", &len1[2]);
	printf("����������:");
	scanf_s("%lf", &len1[3]);
	return len1;
}

void rus(double* len) {
	double verst, sazh, arsh, versh;

	verst = len[0];
	sazh = len[1];
	arsh = len[2];
	versh = len[3];
	versh =( len[3] + len[2] * 10 + len[1] * 1000 + len[0] * 1000000)/44.45;
	arsh = (int)(versh / 16);
	versh = versh-arsh*16 ;
	sazh = (int)(arsh / 3);
	arsh = arsh -sazh*3;
	verst = (int)(sazh / 500);
	sazh = sazh-verst * 500;
	printf("������: %f\n", verst);
	printf("������: %f\n", sazh);
	printf("������: %f\n", arsh);
	printf("������: %f\n", versh);
}

void eng(double* len) {
	double mile, yard, foot, inch;

	mile = len[0];
	yard = len[1];
	foot = len[2];
	inch = len[3];
	inch = (len[3]*0.1 + len[2] + len[1] * 100 + len[0] * 100000) / 2.54;
	foot = (int)(inch / 12);
	inch = inch - foot * 12;
	yard = (int)(foot / 3);
	foot = foot - yard * 3;
	mile = (int)(yard / 1760);
	yard = yard - mile * 1760;
	printf("����: %f\n", mile);
	printf("����: %f\n", yard);
	printf("����: %f\n", foot);
	printf("�����: %f\n", inch);
}

void version(void) {
	printf("LengthConversation 1.0\tNeverovskaya Alexandra\n");
}

void output(double* len) {
    int km, m, cm, mm;

	km = (int)len[0];
	m = (int)len[1];
	cm = (int)len[2];
	mm = (int)len[3];
	cm = cm + (int)(mm / 10);
	mm= (int)mm % 10;
	m = m +(int)( cm/ 100);
	cm =(int) cm % 100;
    km =km + (int)(m / 1000);
	m =(int) m % 1000;
	printf("����������: %d\n", km);
	printf("������: %d\n", m);
	printf("�����������: %d\n", cm);
	printf("�����������: %d\n", mm);
}

