#include"graphics.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ic(int xy, int yd1, int genislik1, int x, int y, int yd2, int genislik2, int a, int b){

	int cx, cy, dx, dy;

	if (xy == 1){
		cx = x + 50;
		cy = y + 50;
		if (genislik2 == 3 && yd2 == 2){ dx = a + 100; dy = b + 300; };
		if (genislik2 == 3 && yd2 == 1){ dx = a + 300; dy = b + 100; };
		if (genislik2 == 2 && yd2 == 2){ dx = a + 100; dy = b + 200; };
		if (genislik2 == 2 && yd2 == 1){ dx = a + 200; dy = b + 100; };
		if (cx>a && cx<dx && cy>b && cy<dy) return 1;
		cx = x + 150;
		if (cx>a && cx<dx && cy>b && cy<dy) return 1;
		if (genislik1 == 3)cx = x + 250;
		if (cx>a && cx<dx && cy>b && cy<dy) return 1;
		else return 0;
	}
	if (xy == 2){

		cx = a + 50;
		cy = b + 50;
		if (genislik1 == 3 && yd1 == 2){ dx = x + 100; dy = y + 300; };
		if (genislik1 == 3 && yd1 == 1){ dx = x + 300; dy = y + 100; };
		if (genislik1 == 2 && yd1 == 2){ dx = x + 100; dy = y + 200; };
		if (genislik1 == 2 && yd1 == 1){ dx = x + 200; dy = y + 100; };
		if (cx>x && cx<dx && cy>y && cy<dy) return 1;
		cy = b + 150;
		if (cx>x && cx<dx && cy>y && cy<dy) return 1;
		if (genislik2 == 3)cy = b + 250;
		if (cx>x && cx<dx && cy>y && cy<dy) return 1;

		else return 0;
	}





}



int main(){


	int hareket = 0;//hareket sayisi
	int kontrol = 1;//girecegi yer
	int y = 1;//oyunun bitimi
	int x = -1;//son hareketi geri almak
	int resim = 0;//kutu resmi
	int arka = 0;//arka plan resmi
	int ilk = 0;//resim seciminde kullandim


	int positive = -1, negative = -1;//hareketi geri almak icin atadigim degerler


	int r5 = 0, r6 = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0;
	FILE *oyun;


	initwindow(610, 700);

	while (y == 1)
	{

		cleardevice();

		while (kontrol == 1)//ANA MENU
		{
			ilk = 0;//renk secimine geri donmesi icin
			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			cleardevice();
			readimagefile("basla.bmp", 0, 0, 300, 300);
			readimagefile("nasil1.bmp", 300, 0, 610, 300);
			readimagefile("cik.bmp", 300, 300, 610, 600);
			readimagefile("about.bmp", 0, 300, 300, 600);
			readimagefile("kayit.bmp", 0, 610, 100, 700);
			readimagefile("ekr2.bmp", 130, 610, 230, 700);
			settextstyle(3, 1, 1);
			outtextxy(90, 680, "SON KAYIT");
			settextstyle(3, 2, 2);
			if (mousex() > 0 && mousex() < 100 && mousey()<700 && mousey()>610 && ismouseclick(WM_LBUTTONDBLCLK)){

				clearmouseclick(WM_LBUTTONDBLCLK);

				oyun = fopen("kayit.txt", "r");

				fscanf(oyun, "%d", &r1);
				fscanf(oyun, "%d", &r2);
				fscanf(oyun, "%d", &r3);
				fscanf(oyun, "%d", &r4);
				fscanf(oyun, "%d", &r5);
				fscanf(oyun, "%d", &r6);
				fscanf(oyun, "%d", &r7);
				fscanf(oyun, "%d", &r8);
				fscanf(oyun, "%d", &r9);
				fscanf(oyun, "%d", &r10);
				fscanf(oyun, "%d", &r11);
				fscanf(oyun, "%d", &r12);
				fscanf(oyun, "%d", &hareket);
				fscanf(oyun, "%d", &arka);
				fscanf(oyun, "%d", &resim);
				fscanf(oyun, "%d", &kontrol);

				fclose(oyun);



			}
			else{
				hareket = 0;
				r5 = 0, r6 = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0, r11 = 0, r12 = 0;

			}

			setbkcolor(7);

			settextstyle(3, 2, 2);
			outtextxy(600, 680, "!!BURADAKI TIKLAMALAR CIFT OLUCAK!!");
			settextstyle(6, 4, 4);
			setlinestyle(2, 4, 9);
			rectangle(0, 0, 300, 300);
			//outtextxy(245, 155, "BASLA");
			rectangle(300, 0, 602, 300);
			//outtextxy(475, 255, "NASIL");
			//outtextxy(590, 295, "OYNANIR?");
			rectangle(0, 300, 300, 600);
			settextstyle(6, 4, 4);
			//outtextxy(280, 600, "HAKKINDA");
			rectangle(300, 300, 602, 600);
			//	outtextxy(610, 560, "CIKIS");
			if (mousex() > 0 && mousex() < 300 && mousey()<300 && mousey()>0){ setcolor(COLOR(0, 0, 180)); }//basla
			if (mousex() > 0 && mousex() < 300 && mousey()<300 && mousey()>0 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				kontrol = 11;//hangi mod ile acacaz

				swapbuffers();
			}//basla
			if (mousex() > 300 && mousex() < 602 && mousey()<300 && mousey()>0){ setcolor(COLOR(200, 70, 0)); }//nasil oynanir
			if (mousex() > 300 && mousex() < 602 && mousey()<300 && mousey()>0 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				kontrol = 5;
				swapbuffers();
			}



			if (mousex() > 0 && mousex() < 300 && mousey()<600 && mousey()>300){ setcolor(COLOR(200, 0, 0)); }//hakkinda
			if (mousex() > 0 && mousex() < 300 && mousey()<600 && mousey()>300 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				kontrol = 2;
				swapbuffers();
			}
			if (mousex() > 300 && mousex() < 602 && mousey()<600 && mousey()>300){ setcolor(COLOR(200, 0, 100)); }//cikis
			if (mousex() > 300 && mousex() < 602 && mousey()<600 && mousey()>300 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				kontrol = 4;
				swapbuffers();
			}

			swapbuffers();

		}

		while (kontrol == 11){//hangi mod

			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			cleardevice();
			srand(time(NULL));
			readimagefile("tahta3.bmp", 0, 0, 610, 700);
			readimagefile("geri.bmp", 460, 655, 610, 700);

			if (mousex()<610 && mousex()>460 && mousey() > 655 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
				clearmouseclick(WM_LBUTTONDBLCLK);

				kontrol = 1;

				cleardevice();
				swapbuffers();



			}
			rectangle(0, 0, 200, 200);
			outtextxy(240, 240, "RASTGELE");
			readimagefile("relax.bmp", 0, 0, 200, 200);
			if (mousex()<200 && mousex()>0 && mousey() >0 && mousey() < 200 && ismouseclick(WM_LBUTTONDBLCLK)){
				clearmouseclick(WM_LBUTTONDBLCLK);

				resim = 1 + rand() % 4;
				arka = 1 + rand() % 4;
				kontrol = 3;
				ilk = 3;


				cleardevice();
				swapbuffers();
			}
			rectangle(0, 300, 200, 500);
			readimagefile("ozel.bmp", 0, 300, 200, 500);
			outtextxy(300, 540, "BEN SECERIM");
			if (mousex()<200 && mousex()>0 && mousey() >300 && mousey() < 500 && ismouseclick(WM_LBUTTONDBLCLK)){
				clearmouseclick(WM_LBUTTONDBLCLK);
				kontrol = 3;
				cleardevice();
				swapbuffers();
			}

			
			outtextxy(610, 100, "TERCIHINIZ ICIN");
			outtextxy(610, 300, "CIFT TIKLAMA");
			outtextxy(610, 500, "YAPINIZ");



			swapbuffers();




		}


		while (kontrol == 2)//hakkinda
		{
			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			clearmouseclick(WM_LBUTTONDBLCLK);
			cleardevice();
			readimagefile("bilgi.bmp", 0, 0, 602, 700);


			readimagefile("geri.bmp", 0, 655, 150, 700);

			if (mousex()<150 && mousex()> 0 && mousey() > 655 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
				clearmouseclick(WM_LBUTTONDBLCLK);

				kontrol = 1;
				cleardevice();
				swapbuffers();



			}

			swapbuffers();

		}



		while (kontrol == 3){//renk secimi


			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			clearmouseclick(WM_LBUTTONDBLCLK);
			cleardevice();
			while (ilk == 0){
				readimagefile("tahta3.bmp", 0, 0, 610, 700);

				readimagefile("a1.bmp", 0, 0, 200, 100);
				if (mousex()<200 && mousex()> 0 && mousey() >0 && mousey() < 100 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);

					cleardevice();
					swapbuffers();
					resim = 1;

					ilk = 1;
				}
				readimagefile("a2.bmp", 0, 200, 200, 300);
				if (mousex()<200 && mousex()> 0 && mousey() >200 && mousey() < 300 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);
					cleardevice();
					swapbuffers();
					resim = 2;

					ilk = 1;
				}
				readimagefile("a3.bmp", 0, 400, 200, 500);
				if (mousex()<200 && mousex()> 0 && mousey() >400 && mousey() < 500 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);
					cleardevice();
					swapbuffers();
					resim = 3;

					ilk = 1;

				}
				readimagefile("tahta2.bmp", 0, 600, 200, 700);
				if (mousex()<200 && mousex()> 0 && mousey() >600 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);
					cleardevice();
					swapbuffers();
					ilk = 1;
					resim = 4;


				}
				readimagefile("geri.bmp", 460, 655, 610, 700);

				if (mousex()<610 && mousex()>460 && mousey() > 655 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);

					kontrol = 1;
					ilk = 4;
					cleardevice();
					swapbuffers();



				}

				outtextxy(610, 100, "KUTU TERCIHINIZI");
				outtextxy(610, 300, "CIFT TIKLAYARAK");
				outtextxy(610, 500, "YAPINIZ");

				swapbuffers();

			}

			while (ilk == 1){

				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);

				cleardevice();
				readimagefile("geri.bmp", 460, 655, 610, 700);


				if (mousex()<610 && mousex()>460 && mousey() > 655 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);

					kontrol = 1;
					ilk = 4;
					cleardevice();
					swapbuffers();


				}




				readimagefile("tahta3.bmp", 0, 0, 610, 700);

				readimagefile("b1.bmp", 0, 0, 200, 100);
				if (mousex()<200 && mousex()> 0 && mousey() >0 && mousey() < 100 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);

					cleardevice();
					swapbuffers();
					arka = 1;

					ilk = 3;
				}
				readimagefile("b2.bmp", 0, 200, 200, 300);
				if (mousex()<200 && mousex()> 0 && mousey() >200 && mousey() < 300 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);
					cleardevice();
					swapbuffers();
					arka = 2;

					ilk = 3;
				}
				readimagefile("b3.bmp", 0, 400, 200, 500);
				if (mousex()<200 && mousex()> 0 && mousey() >400 && mousey() < 500 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);
					cleardevice();
					swapbuffers();
					arka = 3;

					ilk = 3;

				}
				readimagefile("b4.bmp", 0, 600, 200, 700);
				if (mousex()<200 && mousex()> 0 && mousey() >600 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);
					cleardevice();
					swapbuffers();
					ilk = 3;
					arka = 4;


				}
				readimagefile("geri.bmp", 460, 655, 610, 700);

				if (mousex()<610 && mousex()>460 && mousey() > 655 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);

					kontrol = 1;
					ilk = 4;
					cleardevice();
					swapbuffers();



				}

				outtextxy(610, 100, "ARKAPLAN ICIN");
				outtextxy(610, 300, "CIFT TIKLAMA");
				outtextxy(610, 500, "YAPINIZ");



				swapbuffers();


			}
			while (ilk == 3){


				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
				cleardevice();
				readimagefile("tahta3.bmp", 0, 0, 610, 700);
				readimagefile("geri.bmp", 460, 655, 610, 700);

				if (mousex()<610 && mousex()>460 && mousey() > 655 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);

					kontrol = 1;
					ilk = 4;
					cleardevice();
					swapbuffers();



				}
				rectangle(0, 0, 200, 200);
				readimagefile("tur1.bmp", 0, 0, 200, 200);
				if (mousex()<200 && mousex()>0 && mousey() >0 && mousey() < 200 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);
					kontrol = 0;
					ilk = 6;
					cleardevice();
					swapbuffers();
				}
				rectangle(0, 200, 200, 400);
				readimagefile("tur2.bmp", 0, 200, 200, 400);
				if (mousex()<200 && mousex()>0 && mousey() >200 && mousey() < 400 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);
					kontrol = 10;
					ilk = 6;
					cleardevice();
					swapbuffers();

				}
				rectangle(0, 400, 200, 600);
				readimagefile("zor.bmp", 0, 400, 200, 600);
				if (mousex()<200 && mousex()>0 && mousey() >400 && mousey() < 600 && ismouseclick(WM_LBUTTONDBLCLK)){
					clearmouseclick(WM_LBUTTONDBLCLK);
					kontrol = 12;
					ilk = 6;
					cleardevice();
					swapbuffers();

				}

				outtextxy(610, 100, "TUR ICIN ");
				outtextxy(610, 300, "CIFT TIKLAMA");
				outtextxy(610, 500, "YAPINIZ");



				swapbuffers();



			}








		}

		while (kontrol == 4){//CIKIS
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			clearmouseclick(WM_LBUTTONDBLCLK);
			readimagefile("cikis.bmp", 0, 0, 600, 600);
			settextstyle(3, 1, 2);
			//	outtextxy(610, 630, "YINE BEKLERIZ");
			readimagefile("bye.bmp", 200, 600, 400, 700);

			swapbuffers();
			delay(1800);
			kontrol = 667;
			y = 0;




		}






		while (kontrol == 5)//nasil oynanir
		{
			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			clearmouseclick(WM_LBUTTONDBLCLK);
			cleardevice();

			readimagefile("nasil.bmp", 0, 0, 602, 700);

			readimagefile("geri.bmp", 0, 655, 150, 700);

			if (mousex()<150 && mousex()> 0 && mousey() > 655 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
				clearmouseclick(WM_LBUTTONDBLCLK);

				kontrol = 1;
				cleardevice();
				swapbuffers();




			}


			swapbuffers();
		}


		while (kontrol == 7){//tebrikler

			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			clearmouseclick(WM_LBUTTONDBLCLK);

			FILE *dosya;
			char ad[20];
			int i = 0;
			int cikis = 0;
			dosya = fopen("hareket.txt", "a");

			settextstyle(3, 2, 2);
			setcolor(BLUE);
			setbkcolor(7);
			readimagefile("tebrik.bmp", 0, 0, 610, 700);
			outtextxy(500, 680, "ISLEMINIZ BITINCE BOSLUK TUSUNA BASINIZ!!");
			outtextxy(150, 85, "ADINIZI GIRINIZ->");//ad kaydetme
			outtextxy(260, 85, "                     ");
			swapbuffers();



			while (cikis == 0){

				ad[i] = getch();

				if (GetAsyncKeyState(VK_SPACE)) {
					cleardevice();
					swapbuffers();
					cikis = 1;
				}
				while (GetAsyncKeyState(VK_BACK)) {
					i--;
					ad[i] = getch();


				}
				swapbuffers();
				sprintf(&ad[i], "%c", ad[i]);
				outtextxy(180 + i * 15, 85, &ad[i]);
				swapbuffers();

				i++;



			}


			fprintf(dosya, "%s", ad);
			fprintf(dosya, "%d\n", 300 - hareket);

			fclose(dosya);




			char k1[20];
			char puan1[10];

			int sayac = 0;
			int j = 0;
			int sayi1, sayi2;
			cleardevice();
			dosya = fopen("hareket.txt", "r");
			while (j<5){

				fscanf(dosya, "%s", &k1);
				outtextxy(500, 100 + sayac * 30, k1);
				fscanf(dosya, "%s", &puan1);
				outtextxy(550, 100 + sayac * 30, puan1);

				fscanf(dosya, "%s", &k1);
				outtextxy(500, 100 + sayac * 30, k1);
				fscanf(dosya, "%s", &puan1);
				outtextxy(550, 100 + sayac * 30, puan1);

				sayac += 4;
				j++;
			}

			fclose(dosya);

			outtextxy(540, 40, "SKORLAR");
			readimagefile("cizgi.bmp", 0, 0, 410, 700);

			outtextxy(290, 680, "CIKMAK ICIN BIR TUSA BASINIZ");
			swapbuffers();
			getch();

			swapbuffers();
			kontrol = 1;

		}

		while (kontrol == 12)//3.tur
		{
			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			setlinestyle(1, 1, 3);
			setbkcolor(WHITE);
			settextstyle(3, 3, 2);
			setcolor(WHITE);

			if (arka == 1)	readimagefile("b1.bmp", 0, 0, 602, 700);
			if (arka == 2)	readimagefile("b2.bmp", 0, 0, 602, 700);
			if (arka == 3)	readimagefile("b3.bmp", 0, 0, 602, 700);
			if (arka == 4)	readimagefile("b4.bmp", 0, 0, 602, 700);
			readimagefile("hareket.bmp", 250, 600, 360, 700);


			char a[10];
			setbkcolor(BLACK);
			sprintf(a, "%d", hareket);
			outtextxy(358, 705, a);
			setbkcolor(WHITE);
			settextstyle(3, 3, 2);
			setcolor(WHITE);
			setlinestyle(0, 0, 4);
			rectangle(0, 0, 600, 600);
			rectangle(0, 600, 150, 700);
			readimagefile("geri.bmp", 0, 600, 150, 700);



			if (mousex()<150 && mousex()> 0 && mousey() > 600 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){//geri tusu
				clearmouseclick(WM_LBUTTONDBLCLK);
				kontrol = 1;
				arka = 0;//arka plan resmi
				ilk = 0;//resim seciminde kullandim

			}
			rectangle(0, r1, 100, r1 + 300);
			rectangle(200, r2, 300, r2 + 200);
			rectangle(300 + r3, 0, 600 + r3, 100);
			rectangle(100 + r4, 200, 300 + r4, 300);
			rectangle(300, 100 + r5, 400, 400 + r5);
			rectangle(400, 200 + r6, 500, 500 + r6);
			rectangle(500, 100 + r7, 600, 300 + r7);
			rectangle(100, 300 + r8, 200, 500 + r8);
			rectangle(200 + r9, 400, 400 + r9, 500);
			rectangle(500, 300 + r10, 600, 500 + r10);
			rectangle(r11, 500, 300 + r11, 600);


			if (resim == 1){
				readimagefile("a1.bmp", 0, r1, 100, r1 + 300);
				readimagefile("a1.bmp", 200, r2, 300, r2 + 200);
				readimagefile("a1.bmp", 300 + r3, 0, 600 + r3, 100);
				readimagefile("tahta.bmp", 100 + r4, 200, 300 + r4, 300);
				readimagefile("a1.bmp", 300, 100 + r5, 400, 400 + r5);
				readimagefile("a1.bmp", 400, 200 + r6, 500, 500 + r6);
				readimagefile("a1.bmp", 500, 100 + r7, 600, 300 + r7);
				readimagefile("a1.bmp", 100, 300 + r8, 200, 500 + r8);
				readimagefile("a1.bmp", 200 + r9, 400, 400 + r9, 500);
				readimagefile("a1.bmp", 500, 300 + r10, 600, 500 + r10);
				readimagefile("a1.bmp", r11, 500, 300 + r11, 600);
			}


			if (resim == 2){
				readimagefile("a2.bmp", 0, r1, 100, r1 + 300);
				readimagefile("a2.bmp", 200, r2, 300, r2 + 200);
				readimagefile("a2.bmp", 300 + r3, 0, 600 + r3, 100);
				readimagefile("tahta.bmp", 100 + r4, 200, 300 + r4, 300);
				readimagefile("a2.bmp", 300, 100 + r5, 400, 400 + r5);
				readimagefile("a2.bmp", 400, 200 + r6, 500, 500 + r6);
				readimagefile("a2.bmp", 500, 100 + r7, 600, 300 + r7);
				readimagefile("a2.bmp", 100, 300 + r8, 200, 500 + r8);
				readimagefile("a2.bmp", 200 + r9, 400, 400 + r9, 500);
				readimagefile("a2.bmp", 500, 300 + r10, 600, 500 + r10);
				readimagefile("a2.bmp", r11, 500, 300 + r11, 600);
			}

			if (resim == 3){
				readimagefile("a3.bmp", 0, r1, 100, r1 + 300);
				readimagefile("a3.bmp", 200, r2, 300, r2 + 200);
				readimagefile("a3.bmp", 300 + r3, 0, 600 + r3, 100);
				readimagefile("tahta.bmp", 100 + r4, 200, 300 + r4, 300);
				readimagefile("a3.bmp", 300, 100 + r5, 400, 400 + r5);
				readimagefile("a3.bmp", 400, 200 + r6, 500, 500 + r6);
				readimagefile("a3.bmp", 500, 100 + r7, 600, 300 + r7);
				readimagefile("a3.bmp", 100, 300 + r8, 200, 500 + r8);
				readimagefile("a3.bmp", 200 + r9, 400, 400 + r9, 500);
				readimagefile("a3.bmp", 500, 300 + r10, 600, 500 + r10);
				readimagefile("a3.bmp", r11, 500, 300 + r11, 600);
			}
			if (resim == 4){
				readimagefile("tahta2.bmp", 0, r1, 100, r1 + 300);
				readimagefile("tahta2.bmp", 200, r2, 300, r2 + 200);
				readimagefile("tahta2.bmp", 300 + r3, 0, 600 + r3, 100);
				readimagefile("tahta.bmp", 100 + r4, 200, 300 + r4, 300);
				readimagefile("tahta2.bmp", 300, 100 + r5, 400, 400 + r5);
				readimagefile("tahta2.bmp", 400, 200 + r6, 500, 500 + r6);
				readimagefile("tahta2.bmp", 500, 100 + r7, 600, 300 + r7);
				readimagefile("tahta2.bmp", 100, 300 + r8, 200, 500 + r8);
				readimagefile("tahta2.bmp", 200 + r9, 400, 400 + r9, 500);
				readimagefile("tahta2.bmp", 500, 300 + r10, 600, 500 + r10);
				readimagefile("tahta2.bmp", r11, 500, 300 + r11, 600);
			}



			readimagefile("tahta4.bmp", 600, 200, 650, 300);

			readimagefile("tahta7.bmp", 0, 592, 602, 606);


			readimagefile("tahta7.bmp", 590, 0, 610, 606);
			readimagefile("tahta7.bmp", 0, 0, 610, 7);
			readimagefile("tahta7.bmp", 0, 0, 6, 607);
			readimagefile("ok.gif", 590, 200, 610, 300);


			readimagefile("kayit.gif", 500, 606, 610, 700);
			readimagefile("gerial.gif", 370, 606, 490, 700);
			readimagefile("cift.bmp", 160, 606, 240, 700);


			if (mousex()<490 && mousex()>370 && mousey() > 606 && mousey() < 710 && ismouseclick(WM_LBUTTONDBLCLK)){//geri al tusu
				clearmouseclick(WM_LBUTTONDBLCLK);

				if (positive == r1&&	x == 10){ r1 -= 100; hareket--; }
				if (negative == r1&&	x == 20){ r1 += 100; hareket--; }
				if (positive == r2&&	x == 30){ r2 -= 100; hareket--; }
				if (negative == r2&&	x == 40){ r2 += 100; hareket--; }
				if (positive == r3&&	x == 50){ r3 -= 100; hareket--; }
				if (negative == r3&&	x == 60){ r3 += 100; hareket--; }
				if (positive == r4&&	x == 70){ r4 -= 100; hareket--; }
				if (negative == r4&&	x == 80){ r4 += 100; hareket--; }
				if (positive == r5&&	x == 90){ r5 -= 100; hareket--; }
				if (negative == r5&&	x == 100){ r5 += 100; hareket--; }
				if (positive == r6&&	x == 110){ r6 -= 100; hareket--; }
				if (negative == r6&&	x == 120){ r6 += 100; hareket--; }
				if (positive == r7&&	x == 130){ r7 -= 100; hareket--; }
				if (negative == r7&&	x == 140){ r7 += 100; hareket--; }
				if (positive == r8&&	x == 150){ r8 -= 100; hareket--; }
				if (negative == r8&&	x == 160){ r8 += 100; hareket--; }
				if (positive == r9&&	x == 170){ r9 -= 100; hareket--; }
				if (negative == r9&&	x == 180){ r9 += 100; hareket--; }
				if (positive == r10&&	x == 190){ r10 -= 100; hareket--; }
				if (negative == r10&&	x == 200){ r10 += 100; hareket--; }
				if (positive == r11&&	x == 210){ r11 -= 100; hareket--; }
				if (negative == r11&&	x == 220){ r11 += 100; hareket--; }
				if (negative == r12&&	x == 220){ r12 += 100; hareket--; }

				positive = -1;
				negative = -1;
				x = -1;


			}

			if (mousex()<610 && mousex()>500 && mousey() > 606 && mousey() < 710 && ismouseclick(WM_LBUTTONDBLCLK)){//kayit tusu
				clearmouseclick(WM_LBUTTONDBLCLK);
				oyun = fopen("kayit.txt", "w");
				fprintf(oyun, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, hareket, arka, resim, kontrol);

				fclose(oyun);
				setcolor(BLACK);
				outtextxy(500, 606, "KAYDEDILDI");



			}


			if (mousex()<150 && mousex()> 0 && mousey() > 600 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){
				clearmouseclick(WM_LBUTTONDBLCLK);
				kontrol = 1;

			}


			if (mousex() < 100 && mousex() > 0 && mousey() > r1 && mousey() < 300 + r1 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r1 += 100;
				if (r1 < 0 || r1 > 300){ r1 -= 100;  hareket--; }

				if (ic(2, 1, 3, 300 + r3, 0, 2, 3, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r3 
				if (ic(2, 1, 2, 100 + r4, 200, 2, 3, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 3, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r9
				if (ic(2, 1, 3, r11, 500, 2, 3, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r11



				clearviewport();
				swapbuffers();
				hareket++;
				positive = r1;
				x = 10;
			}

			if (mousex() < 100 && mousex() > 0 && mousey() > r1 && mousey() < 300 + r1 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r1 -= 100;
				if (r1 < 0 || r1 > 300){ r1 += 100; hareket--; }//

				if (ic(2, 1, 3, 300 + r3, 0, 2, 3, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r3 
				if (ic(2, 1, 2, 100 + r4, 200, 2, 3, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 3, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r9
				if (ic(2, 1, 3, r11, 500, 2, 3, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r11




				clearviewport();
				swapbuffers();
				hareket++;
				negative = r1;
				x = 20;
			}//r1



			if (mousex()<300 && mousex()>200 && mousey() > r2 && mousey() < 200 + r2 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r2 += 100;
				if (r2<0 || r2>400){ r2 -= 100;  hareket--; } //emin degil

				if (ic(2, 1, 3, 300 + r3, 0, 2, 2, 200, r2) == 1){ r2 -= 100; hareket--; }//r2 r3 
				if (ic(2, 1, 2, 100 + r4, 200, 2, 2, 200, r2) == 1){ r2 -= 100; hareket--; }//r2 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 2, 200, r2) == 1){ r2 -= 100; hareket--; }//r2 r9
				if (ic(2, 1, 3, r11, 500, 2, 2, 200, r2) == 1){ r2 -= 100; hareket--; }//r2 r11

				clearviewport();
				swapbuffers();
				hareket++;
				positive = r2;
				x = 30;
			}

			if (mousex()<300 && mousex()>200 && mousey() > r2 && mousey() < 200 + r2 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r2 -= 100;
				if (r2<0 || r2>400){ r2 += 100;  hareket--; } //emin degil

				if (ic(2, 1, 3, 300 + r3, 0, 2, 2, 200, r2) == 1){ r2 += 100; hareket--; }//r2 r3 
				if (ic(2, 1, 2, 100 + r4, 200, 2, 2, 200, r2) == 1){ r2 += 100; hareket--; }//r2 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 2, 200, r2) == 1){ r2 += 100; hareket--; }//r2 r9
				if (ic(2, 1, 3, r11, 500, 2, 2, 200, r2) == 1){ r2 += 100; hareket--; }//r2 r11

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r2;
				x = 40;
			}//r2




			if (mousex()<600 + r3&& mousex()>300 + r3 && mousey() > 0 && mousey() < 100 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r3 += 100;
				if (r3 <-300 || r3 >0){ r3 -= 100;  hareket--; }//emin degil

				if (ic(1, 1, 3, 300 + r3, 0, 2, 3, 0, r1) == 1){ r3 -= 100; hareket--; }//r3 r1
				if (ic(1, 1, 3, 300 + r3, 0, 2, 2, 200, r2) == 1){ r3 -= 100; hareket--; }//r3 r2
				if (ic(1, 1, 3, 300 + r3, 0, 2, 3, 300, 100 + r5) == 1){ r3 -= 100; hareket--; }//r3 r5
				if (ic(1, 1, 3, 300 + r3, 0, 2, 3, 400, 200 + r6) == 1){ r3 -= 100; hareket--; }//r3 r6
				if (ic(1, 1, 3, 300 + r3, 0, 2, 2, 500, 100 + r7) == 1){ r3 -= 100; hareket--; }//r3 r7
				if (ic(1, 1, 3, 300 + r3, 0, 2, 2, 100, 300 + r8) == 1){ r3 -= 100; hareket--; }//r3 r8

				cleardevice();
				swapbuffers();
				hareket++;
				positive = r3;
				x = 50;
			}

			if (mousex()<600 + r3  && mousex()>300 + r3 && mousey() > 0 && mousey() < 100 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r3 -= 100;
				if (r3 <-300 || r3 >0){ r3 += 100;  hareket--; }

				if (ic(1, 1, 3, 300 + r3, 0, 2, 3, 0, r1) == 1){ r3 += 100; hareket--; }//r3 r1
				if (ic(1, 1, 3, 300 + r3, 0, 2, 2, 200, r2) == 1){ r3 += 100; hareket--; }//r3 r2
				if (ic(1, 1, 3, 300 + r3, 0, 2, 3, 300, 100 + r5) == 1){ r3 += 100; hareket--; }//r3 r5
				if (ic(1, 1, 3, 300 + r3, 0, 2, 3, 400, 200 + r6) == 1){ r3 += 100; hareket--; }//r3 r6
				if (ic(1, 1, 3, 300 + r3, 0, 2, 2, 500, 100 + r7) == 1){ r3 += 100; hareket--; }//r3 r7
				if (ic(1, 1, 3, 300 + r3, 0, 2, 2, 100, 300 + r8) == 1){ r3 += 100; hareket--; }//r3 r8

				cleardevice();
				swapbuffers();
				hareket++;
				negative = r3;
				x = 60;
			}//r3



			if (mousex()<300 + r4 && mousex()>100 + r4 && mousey() > 200 && mousey() < 300 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r4 += 100;
				if (r4<-100){ r4 -= 100;  hareket--; }
				if (r4 >= 500){
					kontrol = 7;
					cleardevice();
					swapbuffers();
				}//oyun bitimi

				if (ic(1, 1, 2, 100 + r4, 200, 2, 3, 0, r1) == 1){ r4 -= 100; hareket--; }//r4 r1
				if (ic(1, 1, 2, 100 + r4, 200, 2, 2, 200, r2) == 1){ r4 -= 100; hareket--; }//r4 r2
				if (ic(1, 1, 2, 100 + r4, 200, 2, 3, 300, 100 + r5) == 1){ r4 -= 100; hareket--; }//r4 r5
				if (ic(1, 1, 2, 100 + r4, 200, 2, 3, 400, 200 + r6) == 1){ r4 -= 100; hareket--; }//r4 r6
				if (ic(1, 1, 2, 100 + r4, 200, 2, 2, 500, 100 + r7) == 1){ r4 -= 100; hareket--; }//r4 r7
				if (ic(1, 1, 2, 100 + r4, 200, 2, 2, 100, 300 + r8) == 1){ r4 -= 100; hareket--; }//r4 r8
				if (ic(1, 1, 2, 100 + r4, 200, 2, 2, 500, 300 + r10) == 1){ r4 -= 100; hareket--; }//r4 r10

				cleardevice();
				swapbuffers();
				hareket++;
				positive = r4;
				x = 70;
			}

			if (mousex()<300 + r4 && mousex()>100 + r4 && mousey() > 200 && mousey() < 300 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r4 -= 100;
				if (r4<-100){ r4 += 100; hareket--; }


				if (ic(1, 1, 2, 100 + r4, 200, 2, 3, 0, r1) == 1){ r4 += 100; hareket--; }//r4 r1
				if (ic(1, 1, 2, 100 + r4, 200, 2, 2, 200, r2) == 1){ r4 += 100; hareket--; }//r4 r2
				if (ic(1, 1, 2, 100 + r4, 200, 2, 3, 300, 100 + r5) == 1){ r4 += 100; hareket--; }//r4 r5
				if (ic(1, 1, 2, 100 + r4, 200, 2, 3, 400, 200 + r6) == 1){ r4 += 100; hareket--; }//r4 r6
				if (ic(1, 1, 2, 100 + r4, 200, 2, 2, 500, 100 + r7) == 1){ r4 += 100; hareket--; }//r4 r7
				if (ic(1, 1, 2, 100 + r4, 200, 2, 2, 100, 300 + r8) == 1){ r4 += 100; hareket--; }//r4 r8
				if (ic(1, 1, 2, 100 + r4, 200, 2, 2, 500, 300 + r10) == 1){ r4 += 100; hareket--; }//r4 r10

				cleardevice();
				swapbuffers();
				hareket++;
				negative = r4;
				x = 80;
			}//r4



			if (mousex() < 400 && mousex() > 300 && mousey() > 100 + r5 && mousey() < 400 + r5 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r5 += 100;
				if (r5 < -100 || r5 > 200){ r5 -= 100; hareket--; }




				if (ic(2, 1, 3, 300 + r3, 0, 2, 3, 300, 100 + r5) == 1){ r5 -= 100; hareket--; }//r5 r3
				if (ic(2, 1, 2, 100 + r4, 200, 2, 3, 300, 100 + r5) == 1){ r5 -= 100; hareket--; }//r5 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 3, 300, 100 + r5) == 1){ r5 -= 100; hareket--; }//r5 r9
				if (ic(2, 1, 3, r11, 500, 2, 3, 300, 100 + r5) == 1){ r5 -= 100; hareket--; }//r5 r11


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r5;
				x = 90;

			}

			if (mousex() < 400 && mousex() > 300 && mousey() > 100 + r5 && mousey() < 400 + r5 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r5 -= 100;
				if (r5 < -100 || r5 > 200){ r5 += 100; hareket--; }// emin degil

				if (ic(2, 1, 3, 300 + r3, 0, 2, 3, 300, 100 + r5) == 1){ r5 += 100; hareket--; }//r5 r3
				if (ic(2, 1, 2, 100 + r4, 200, 2, 3, 300, 100 + r5) == 1){ r5 += 100; hareket--; }//r5 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 3, 300, 100 + r5) == 1){ r5 += 100; hareket--; }//r5 r9
				if (ic(2, 1, 3, r11, 500, 2, 3, 300, 100 + r5) == 1){ r5 += 100; hareket--; }//r5 r11

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r5;
				x = 100;
			}//r5



			if (mousex()<500 && mousex()> 400 && mousey() > 200 + r6&& mousey() < 500 + r6 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r6 += 100;
				if (r6 < -200 || r6 > 100){ r6 -= 100; hareket--; } //emin degil

				if (ic(2, 1, 3, 300 + r3, 0, 2, 3, 400, 200 + r6) == 1){ r6 -= 100; hareket--; }//r6 r3
				if (ic(2, 1, 2, 100 + r4, 200, 2, 3, 400, 200 + r6) == 1){ r6 -= 100; hareket--; }//r6 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 3, 400, 200 + r6) == 1){ r6 -= 100; hareket--; }//r6 r9
				if (ic(2, 1, 3, r11, 500, 2, 3, 400, 200 + r6) == 1){ r6 -= 100; hareket--; }//r6 r11

				clearviewport();
				swapbuffers();
				hareket++;
				positive = r6;
				x = 110;
			}
			if (mousex()<500 && mousex()> 400 && mousey() >200 + r6&& mousey() < 500 + r6 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r6 -= 100;
				if (r6 < -200 || r6 > 100) { r6 += 100; hareket--; } //emin degil

				if (ic(2, 1, 3, 300 + r3, 0, 2, 3, 400, 200 + r6) == 1){ r6 += 100; hareket--; }//r6 r3
				if (ic(2, 1, 2, 100 + r4, 200, 2, 3, 400, 200 + r6) == 1){ r6 += 100; hareket--; }//r6 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 3, 400, 200 + r6) == 1){ r6 += 100; hareket--; }//r6 r9
				if (ic(2, 1, 3, r11, 500, 2, 3, 400, 200 + r6) == 1){ r6 += 100; hareket--; }//r6 r11

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r6;
				x = 120;
			}//r6




			if (mousex()<600 && mousex()>500 && mousey() > r7 + 100 && mousey() < r7 + 300 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r7 += 100;
				if (r7 < -100 || r7 > 100){ r7 -= 100;  hareket--; } // emin degil

				if (ic(2, 1, 3, 300 + r3, 0, 2, 2, 500, 100 + r7) == 1){ r7 -= 100; hareket--; }//r7 r3
				if (ic(2, 1, 2, 100 + r4, 200, 2, 2, 500, 100 + r7) == 1){ r7 -= 100; hareket--; }//r7 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 2, 500, 100 + r7) == 1){ r7 -= 100; hareket--; }//r7 r9
				if (ic(2, 2, 2, 500, 100 + r7, 2, 2, 500, 300 + r10) == 1){ r7 -= 100; hareket--; }//r7 r10
				if (ic(2, 1, 3, r1, 500, 2, 2, 500, 100 + r7) == 1){ r7 -= 100; hareket--; }//r7 r11

				clearviewport();
				swapbuffers();
				hareket++;
				positive = r7;
				x = 130;
			}

			if (mousex() < 600 && mousex() > 500 && mousey() > r7 + 100 && mousey() < r7 + 300 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r7 -= 100;
				if (r7 < -100 || r7 > 100){ r7 += 100; hareket--; } // emin degil

				if (ic(2, 1, 3, 300 + r3, 0, 2, 2, 500, 100 + r7) == 1){ r7 += 100; hareket--; }//r7 r3
				if (ic(2, 1, 2, 100 + r4, 200, 2, 2, 500, 100 + r7) == 1){ r7 += 100; hareket--; }//r7 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 2, 500, 100 + r7) == 1){ r7 += 100; hareket--; }//r7 r9
				if (ic(2, 2, 2, 500, 100 + r7, 2, 2, 500, 300 + r10) == 1){ r7 += 100; hareket--; }//r7 r10
				if (ic(2, 1, 3, r1, 500, 2, 2, 500, 100 + r7) == 1){ r7 += 100; hareket--; }//r7 r11
				clearviewport();
				swapbuffers();
				hareket++;
				negative = r7;
				x = 140;
			}//r7



			if (mousex() < 200 && mousex() > 100 && mousey() > 300 + r8 && mousey() < 500 + r8 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r8 += 100;
				if (r8 < -300 || r8 > 100){ r8 -= 100;  hareket--; } // emin degil

				if (ic(2, 1, 3, 300 + r3, 0, 2, 2, 100, 300 + r8) == 1){ r8 -= 100; hareket--; }//r8 r3
				if (ic(2, 1, 2, 100 + r4, 200, 2, 2, 100, 300 + r8) == 1){ r8 -= 100; hareket--; }//r8 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 2, 100, 300 + r8) == 1){ r8 -= 100; hareket--; }//r8 r9
				if (ic(2, 1, 3, r11, 500, 2, 2, 100, 300 + r8) == 1){ r8 -= 100; hareket--; }//r8 r11

				clearviewport();
				swapbuffers();
				hareket++;
				positive = r8;
				x = 150;
			}

			if (mousex() < 200 && mousex() > 100 && mousey() > 300 + r8 && mousey() < 500 + r8 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r8 -= 100;
				if (r8 < -300 || r8 > 100){ r8 += 100; hareket--; } // emin degil

				if (ic(2, 1, 3, 300 + r3, 0, 2, 2, 100, 300 + r8) == 1){ r8 += 100; hareket--; }//r8 r3
				if (ic(2, 1, 2, 100 + r4, 200, 2, 2, 100, 300 + r8) == 1){ r8 += 100; hareket--; }//r8 r4
				if (ic(2, 1, 2, 200 + r9, 400, 2, 2, 100, 300 + r8) == 1){ r8 += 100; hareket--; }//r8 r9
				if (ic(2, 1, 3, r11, 500, 2, 2, 100, 300 + r8) == 1){ r8 += 100; hareket--; }//r8 r11	

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r8;
				x = 160;
			}//r8



			if (mousex() < 400 + r9 && mousex() > 200 + r9 && mousey() > 400 && mousey() < 500 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r9 += 100;
				if (r9 < -200 || r9 > 200){ r9 -= 100;  hareket--; } // emin degil

				if (ic(1, 1, 2, 200 + r9, 400, 2, 3, 0, r1) == 1){ r9 -= 100; hareket--; }//r9 r1
				if (ic(1, 1, 2, 200 + r9, 400, 2, 2, 200, r2) == 1){ r9 -= 100; hareket--; }//r9 r2	
				if (ic(1, 1, 2, 200 + r9, 400, 2, 3, 300, 100 + r5) == 1){ r9 -= 100; hareket--; }//r9 r5
				if (ic(1, 1, 2, 200 + r9, 400, 2, 3, 400, 200 + r6) == 1){ r9 -= 100; hareket--; }//r9 r6
				if (ic(1, 1, 2, 200 + r9, 400, 2, 2, 100, 300 + r8) == 1){ r9 -= 100; hareket--; }//r9 r8
				if (ic(1, 1, 2, 200 + r9, 400, 2, 2, 500, 300 + r10) == 1){ r9 -= 100; hareket--; }//r9 r10		
				clearviewport();
				swapbuffers();
				hareket++;
				positive = r9;
				x = 170;

			}

			if (mousex() < 400 + r9 && mousex() > 200 + r9 && mousey() > 400 && mousey() < 500 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r9 -= 100;
				if (r9 < -200 || r9 >200){ r9 += 100; hareket--; } // emin degil
				if (ic(1, 1, 2, 200 + r9, 400, 2, 3, 0, r1) == 1){ r9 += 100; hareket--; }//r9 r1
				if (ic(1, 1, 2, 200 + r9, 400, 2, 2, 200, r2) == 1){ r9 += 100; hareket--; }//r9 r2	
				if (ic(1, 1, 2, 200 + r9, 400, 2, 3, 300, 100 + r5) == 1){ r9 += 100; hareket--; }//r9 r5
				if (ic(1, 1, 2, 200 + r9, 400, 2, 3, 400, 200 + r6) == 1){ r9 += 100; hareket--; }//r9 r6
				if (ic(1, 1, 2, 200 + r9, 400, 2, 2, 100, 300 + r8) == 1){ r9 += 100; hareket--; }//r9 r8
				if (ic(1, 1, 2, 200 + r9, 400, 2, 2, 500, 300 + r10) == 1){ r9 += 100; hareket--; }//r9 r10		

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r9;
				x = 180;
			}//r9




			if (mousex() < 600 && mousex() > 500 && mousey() > 300 + r10 && mousey() < 500 + r10 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r10 += 100;
				if (r10 < -300 || r10 > 100){ r10 -= 100;  hareket--; }//emin degil

				if (ic(2, 1, 2, 100 + r4, 200, 2, 2, 500, 300 + r10) == 1){ r10 -= 100; hareket--; }//r10 r4
				if (ic(2, 2, 2, 500, 100 + r7, 2, 2, 500, 300 + r10) == 1){ r10 -= 100; hareket--; }//r10 r7
				if (ic(2, 1, 2, 200 + r9, 400, 2, 2, 500, 300 + r10) == 1){ r10 -= 100; hareket--; }//r10 r9
				if (ic(2, 1, 3, r11, 500, 2, 2, 500, 300 + r10) == 1){ r10 -= 100; hareket--; }//r10 r11
				clearviewport();
				swapbuffers();
				hareket++;
				positive = r10;
				x = 190;
			}

			if (mousex()<600 && mousex()>500 && mousey() > 300 + r10 && mousey() < 500 + r10 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r10 -= 100;
				if (r10 < -300 || r10 > 100){ r10 += 100; hareket--; }//emin degil

				if (ic(2, 1, 2, 100 + r4, 200, 2, 2, 500, 300 + r10) == 1){ r10 += 100; hareket--; }//r10 r4
				if (ic(2, 2, 2, 500, 100 + r7, 2, 2, 500, 300 + r10) == 1){ r10 += 100; hareket--; }//r10 r7
				if (ic(2, 1, 2, 200 + r9, 400, 2, 2, 500, 300 + r10) == 1){ r10 += 100; hareket--; }//r10 r9
				if (ic(2, 1, 3, r11, 500, 2, 2, 500, 300 + r10) == 1){ r10 += 100; hareket--; }//r10 r11
				clearviewport();
				swapbuffers();
				hareket++;
				negative = r10;
				x = 200;
			}//r10




			if (mousex() < 300 + r11 && mousex() > r11 && mousey() > 500 && mousey() < 600 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r11 += 100;
				if (r11  <0 || r11 > 300){ r11 -= 100;  hareket--; }
				if (ic(1, 1, 3, r11, 500, 2, 3, 0, r1) == 1){ r11 -= 100; hareket--; }//r11 r1
				if (ic(1, 1, 3, r11, 500, 2, 2, 200, r2) == 1){ r11 -= 100; hareket--; }//r11 r2
				if (ic(1, 1, 3, r11, 500, 2, 3, 300, 100 + r5) == 1){ r11 -= 100; hareket--; }//r11 r5
				if (ic(1, 1, 3, r11, 500, 2, 3, 400, 200 + r6) == 1){ r11 -= 100; hareket--; }//r11 r6 
				if (ic(1, 1, 3, r11, 500, 2, 2, 100, 300 + r8) == 1){ r11 -= 100; hareket--; }//r11 r8
				if (ic(1, 1, 3, r11, 500, 2, 2, 500, 300 + r10) == 1){ r11 -= 100; hareket--; }//r11 r10

				clearviewport();
				swapbuffers();
				hareket++;
				positive = r11;
				x = 210;
			}

			if (mousex() < 300 + r11 && mousex()> r11 && mousey() > 500 && mousey() < 600 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r11 -= 100;
				if (r11 < 0 || r11 > 300){ r11 += 100; hareket--; }//eimn degil
				if (ic(1, 1, 3, r11, 500, 2, 3, 0, r1) == 1){ r11 += 100; hareket--; }//r11 r1
				if (ic(1, 1, 3, r11, 500, 2, 2, 200, r2) == 1){ r11 += 100; hareket--; }//r11 r2
				if (ic(1, 1, 3, r11, 500, 2, 3, 300, 100 + r5) == 1){ r11 += 100; hareket--; }//r11 r5
				if (ic(1, 1, 3, r11, 500, 2, 3, 400, 200 + r6) == 1){ r11 += 100; hareket--; }//r11 r6 
				if (ic(1, 1, 3, r11, 500, 2, 2, 100, 300 + r8) == 1){ r11 += 100; hareket--; }//r11 r8
				if (ic(1, 1, 3, r11, 500, 2, 2, 500, 300 + r10) == 1){ r11 += 100; hareket--; }//r11 r10


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r11;
				x = 220;
			}//r11



			swapbuffers();




		}

		while (kontrol == 10)//2.tur
		{

			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			setlinestyle(1, 1, 3);
			setbkcolor(WHITE);
			settextstyle(3, 3, 2);
			setcolor(WHITE);

			if (arka == 1)	readimagefile("b1.bmp", 0, 0, 602, 700);
			if (arka == 2)	readimagefile("b2.bmp", 0, 0, 602, 700);
			if (arka == 3)	readimagefile("b3.bmp", 0, 0, 602, 700);
			if (arka == 4)	readimagefile("b4.bmp", 0, 0, 602, 700);
			readimagefile("hareket.bmp", 250, 600, 360, 700);


			char a[10];
			setbkcolor(BLACK);
			sprintf(a, "%d", hareket);
			outtextxy(358, 705, a);
			setbkcolor(WHITE);
			settextstyle(3, 3, 2);
			setcolor(WHITE);
			setlinestyle(0, 0, 3);
			rectangle(0, 0, 600, 600);
			rectangle(0, 600, 150, 700);
			readimagefile("geri.bmp", 0, 600, 150, 700);



			if (mousex()<150 && mousex()> 0 && mousey() > 600 && mousey() < 700 && ismouseclick(WM_LBUTTONDBLCLK)){//geri tusu
				clearmouseclick(WM_LBUTTONDBLCLK);
				kontrol = 1;
				arka = 0;//arka plan resmi
				ilk = 0;//resim seciminde kullandim

			}

			rectangle(0, r1, 100, 200 + r1);
			rectangle(200 + r2, 0, 400 + r2, 100);
			rectangle(100 + r3, 100, 400 + r3, 200);
			rectangle(400, r4, 500, 200 + r4);
			rectangle(500, r5, 600, 300 + r5);
			rectangle(r6, 200, r6 + 200, 300);
			rectangle(200, 200 + r7, 300, 400 + r7);
			rectangle(300, 200 + r8, 400, 400 + r8);
			rectangle(400, 200 + r9, 500, 400 + r9);
			rectangle(r10, 500, r10 + 300, 600);
			rectangle(300, 400 + r11, 400, 600 + r11);
			rectangle(400 + r12, 400, 600 + r12, 500);


			if (resim == 1){
				readimagefile("a1.bmp", 0, r1, 100, 200 + r1);

				readimagefile("a1.bmp", 200 + r2, 0, 400 + r2, 100);

				readimagefile("a1.bmp", 100 + r3, 100, 400 + r3, 200);

				readimagefile("a1.bmp", 400, r4, 500, 200 + r4);

				readimagefile("a1.bmp", 500, r5, 600, 300 + r5);

				readimagefile("tahta.bmp", r6, 200, r6 + 200, 300);

				readimagefile("a1.bmp", 200, 200 + r7, 300, 400 + r7);

				readimagefile("a1.bmp", 300, 200 + r8, 400, 400 + r8);

				readimagefile("a1.bmp", 400, 200 + r9, 500, 400 + r9);

				readimagefile("a1.bmp", r10, 500, r10 + 300, 600);

				readimagefile("a1.bmp", 300, 400 + r11, 400, 600 + r11);

				readimagefile("a1.bmp", 400 + r12, 400, 600 + r12, 500);
			}


			if (resim == 2){
				readimagefile("a2.bmp", 0, r1, 100, 200 + r1);

				readimagefile("a2.bmp", 200 + r2, 0, 400 + r2, 100);

				readimagefile("a2.bmp", 100 + r3, 100, 400 + r3, 200);

				readimagefile("a2.bmp", 400, r4, 500, 200 + r4);

				readimagefile("a2.bmp", 500, r5, 600, 300 + r5);

				readimagefile("tahta.bmp", r6, 200, r6 + 200, 300);

				readimagefile("a2.bmp", 200, 200 + r7, 300, 400 + r7);

				readimagefile("a2.bmp", 300, 200 + r8, 400, 400 + r8);

				readimagefile("a2.bmp", 400, 200 + r9, 500, 400 + r9);

				readimagefile("a2.bmp", r10, 500, r10 + 300, 600);

				readimagefile("a2.bmp", 300, 400 + r11, 400, 600 + r11);

				readimagefile("a2.bmp", 400 + r12, 400, 600 + r12, 500);
			}

			if (resim == 3){
				readimagefile("a3.bmp", 0, r1, 100, 200 + r1);

				readimagefile("a3.bmp", 200 + r2, 0, 400 + r2, 100);

				readimagefile("a3.bmp", 100 + r3, 100, 400 + r3, 200);

				readimagefile("a3.bmp", 400, r4, 500, 200 + r4);

				readimagefile("a3.bmp", 500, r5, 600, 300 + r5);

				readimagefile("tahta.bmp", r6, 200, r6 + 200, 300);

				readimagefile("a3.bmp", 200, 200 + r7, 300, 400 + r7);

				readimagefile("a3.bmp", 300, 200 + r8, 400, 400 + r8);

				readimagefile("a3.bmp", 400, 200 + r9, 500, 400 + r9);

				readimagefile("a3.bmp", r10, 500, r10 + 300, 600);

				readimagefile("a3.bmp", 300, 400 + r11, 400, 600 + r11);

				readimagefile("a3.bmp", 400 + r12, 400, 600 + r12, 500);
			}

			if (resim == 3){
				readimagefile("tahta2.bmp", 0, r1, 100, 200 + r1);

				readimagefile("tahta2.bmp", 200 + r2, 0, 400 + r2, 100);

				readimagefile("tahta2.bmp", 100 + r3, 100, 400 + r3, 200);

				readimagefile("tahta2.bmp", 400, r4, 500, 200 + r4);

				readimagefile("tahta2.bmp", 500, r5, 600, 300 + r5);

				readimagefile("tahta.bmp", r6, 200, r6 + 200, 300);

				readimagefile("tahta2.bmp", 200, 200 + r7, 300, 400 + r7);

				readimagefile("tahta2.bmp", 300, 200 + r8, 400, 400 + r8);

				readimagefile("tahta2.bmp", 400, 200 + r9, 500, 400 + r9);

				readimagefile("tahta2.bmp", r10, 500, r10 + 300, 600);

				readimagefile("tahta2.bmp", 300, 400 + r11, 400, 600 + r11);

				readimagefile("tahta2.bmp", 400 + r12, 400, 600 + r12, 500);
			}


			readimagefile("tahta4.bmp", 600, 200, 650, 300);

			readimagefile("tahta7.bmp", 0, 592, 602, 606);


			readimagefile("tahta7.bmp", 590, 0, 610, 606);
			readimagefile("tahta7.bmp", 0, 0, 610, 7);
			readimagefile("tahta7.bmp", 0, 0, 6, 607);
			readimagefile("ok.gif", 590, 200, 610, 300);


			readimagefile("kayit.gif", 500, 606, 610, 700);
			readimagefile("gerial.gif", 370, 606, 490, 700);
			readimagefile("cift.bmp", 160, 606, 240, 700);


			if (mousex()<490 && mousex()>370 && mousey() > 606 && mousey() < 710 && ismouseclick(WM_LBUTTONDBLCLK)){//geri al tusu
				clearmouseclick(WM_LBUTTONDBLCLK);

				if (positive == r1&&	x == 10){ r1 -= 100; hareket--; }
				if (negative == r1&&	x == 20){ r1 += 100; hareket--; }
				if (positive == r2&&	x == 30){ r2 -= 100; hareket--; }
				if (negative == r2&&	x == 40){ r2 += 100; hareket--; }
				if (positive == r3&&	x == 50){ r3 -= 100; hareket--; }
				if (negative == r3&&	x == 60){ r3 += 100; hareket--; }
				if (positive == r4&&	x == 70){ r4 -= 100; hareket--; }
				if (negative == r4&&	x == 80){ r4 += 100; hareket--; }
				if (positive == r5&&	x == 90){ r5 -= 100; hareket--; }
				if (negative == r5&&	x == 100){ r5 += 100; hareket--; }
				if (positive == r6&&	x == 110){ r6 -= 100; hareket--; }
				if (negative == r6&&	x == 120){ r6 += 100; hareket--; }
				if (positive == r7&&	x == 130){ r7 -= 100; hareket--; }
				if (negative == r7&&	x == 140){ r7 += 100; hareket--; }
				if (positive == r8&&	x == 150){ r8 -= 100; hareket--; }
				if (negative == r8&&	x == 160){ r8 += 100; hareket--; }
				if (positive == r9&&	x == 170){ r9 -= 100; hareket--; }
				if (negative == r9&&	x == 180){ r9 += 100; hareket--; }
				if (positive == r10&&	x == 190){ r10 -= 100; hareket--; }
				if (negative == r10&&	x == 200){ r10 += 100; hareket--; }
				if (positive == r11&&	x == 210){ r11 -= 100; hareket--; }
				if (negative == r11&&	x == 220){ r11 += 100; hareket--; }
				if (negative == r12&&	x == 220){ r12 += 100; hareket--; }
				if (positive == r12&&	x == 210){ r12 -= 100; hareket--; }
				positive = -1;
				negative = -1;
				x = -1;


			}

			if (mousex()<610 && mousex()>500 && mousey() > 606 && mousey() < 710 && ismouseclick(WM_LBUTTONDBLCLK)){//kayit tusu
				clearmouseclick(WM_LBUTTONDBLCLK);
				oyun = fopen("kayit.txt", "w");
				fprintf(oyun, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, hareket, arka, resim, kontrol);

				fclose(oyun);
				setcolor(BLACK);
				outtextxy(500, 606, "KAYDEDILDI");



			}




			if (mousex()<100 && mousex()> 0 && mousey() > r1&& mousey() < r1 + 200 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r1 += 100;
				if (r1<0 || r1>400){ r1 -= 100;  hareket--; }

				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r10
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r12





				clearviewport();
				swapbuffers();
				hareket++;
				positive = r1;
				x = 10;


			}

			if (mousex()<100 && mousex()> 0 && mousey() > r1&& mousey() < r1 + 200 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r1 -= 100;


				if (r1<0 || r1>400){ r1 += 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r10
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r12

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r1;

				x = 20;
			}//r1
			if (mousex()<400 + r2 && mousex()>200 + r2 && mousey() > 0 && mousey() < 100 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r2 += 100;


				if (r2<-200 || r2>200){ r2 -= 100; hareket--; }
				if (ic(1, 1, 2, 200 + r2, 0, 2, 2, 0, r1) == 1){ r2 -= 100; hareket--; }//r2 r1
				if (ic(1, 1, 2, 200 + r2, 0, 2, 2, 400, r4) == 1){ r2 -= 100; hareket--; }//r2 r4
				if (ic(1, 1, 2, 200 + r2, 0, 2, 3, 500, r5) == 1){ r2 -= 100; hareket--; }//r2 r5
				if (ic(1, 1, 2, 200 + r2, 0, 2, 3, 200, 200 + r7) == 1){ r2 -= 100; hareket--; }//r2 r7
				if (ic(1, 1, 2, 200 + r2, 0, 2, 3, 300, 200 + r8) == 1){ r2 -= 100; hareket--; }//r2 r8


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r2;

				x = 30;
			}

			if (mousex()<400 + r2 && mousex()>200 + r2 && mousey() > 0 && mousey() < 100 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r2 -= 100;


				if (r2<-200 || r2>200){ r2 += 100; hareket--; }
				if (ic(1, 1, 2, 200 + r2, 0, 2, 2, 0, r1) == 1){ r2 += 100; hareket--; }//r2 r1
				if (ic(1, 1, 2, 200 + r2, 0, 2, 2, 400, r4) == 1){ r2 += 100; hareket--; }//r2 r4
				if (ic(1, 1, 2, 200 + r2, 0, 2, 3, 500, r5) == 1){ r2 += 100; hareket--; }//r2 r5
				if (ic(1, 1, 2, 200 + r2, 0, 2, 3, 200, 200 + r7) == 1){ r2 += 100; hareket--; }//r2 r7
				if (ic(1, 1, 2, 200 + r2, 0, 2, 3, 300, 200 + r8) == 1){ r2 += 100; hareket--; }//r2 r8



				clearviewport();
				swapbuffers();
				hareket++;
				negative = r2;

				x = 40;
			}//r2






			if (mousex()<400 + r3 && mousex()>100 + r3 && mousey() > 100 && mousey() < 200 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r3 += 100;


				if (r3<-100 || r3>200){ r3 -= 100; hareket--; }
				if (ic(1, 1, 3, 100 + r3, 100, 2, 2, 0, r1) == 1){ r3 -= 100; hareket--; }//r3 r1
				if (ic(1, 1, 3, 100 + r3, 100, 2, 2, 400, r4) == 1){ r3 -= 100; hareket--; }//r3 r4
				if (ic(1, 1, 3, 100 + r3, 100, 2, 3, 500, r5) == 1){ r3 -= 100; hareket--; }//r3 r5
				if (ic(1, 1, 3, 100 + r3, 100, 2, 2, 200, 200 + r7) == 1){ r3 -= 100; hareket--; }//r3 r7
				if (ic(1, 1, 3, 100 + r3, 100, 2, 2, 300, 200 + r8) == 1){ r3 -= 100; hareket--; }//r3 r8

				clearviewport();
				swapbuffers();
				hareket++;
				positive = r3;
				x = 50;
			}

			if (mousex()<400 + r3 && mousex()>100 + r3 && mousey() > 100 && mousey() < 200 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r3 -= 100;


				if (r3<-100 || r3>200){ r3 += 100; hareket--; }
				if (ic(1, 1, 3, 100 + r3, 100, 2, 2, 0, r1) == 1){ r3 += 100; hareket--; }//r3 r1
				if (ic(1, 1, 3, 100 + r3, 100, 2, 2, 400, r4) == 1){ r3 += 100; hareket--; }//r3 r4
				if (ic(1, 1, 3, 100 + r3, 100, 2, 3, 500, r5) == 1){ r3 += 100; hareket--; }//r3 r5
				if (ic(1, 1, 3, 100 + r3, 100, 2, 2, 200, 200 + r7) == 1){ r3 += 100; hareket--; }//r3 r7
				if (ic(1, 1, 3, 100 + r3, 100, 2, 2, 300, 200 + r8) == 1){ r3 += 100; hareket--; }//r3 r8


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r3;
				x = 60;
			}//r3


			if (mousex()<500 && mousex()>400 && mousey() > r4 && mousey() < r4 + 200 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r4 += 100;


				if (r4<0 || r4>400){ r4 -= 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 400, r4) == 1){ r4 -= 100; hareket--; }//r4 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 400, r4) == 1){ r4 -= 100; hareket--; }//r4 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 400, r4) == 1){ r4 -= 100; hareket--; }//r4 r6
				if (ic(1, 1, 2, 400, 200 + r9, 2, 2, 400, r4) == 1){ r4 -= 100; hareket--; }//r4 r9
				if (ic(2, 1, 3, r10, 500, 2, 2, 400, r4) == 1){ r4 -= 100; hareket--; }//r4 r10
				if (ic(2, 1, 2, 400 + r12, 400 + r9, 2, 2, 400, r4) == 1){ r4 -= 100; hareket--; }//r4 r12


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r4;
				x = 70;
			}
			if (mousex()<500 && mousex()>400 && mousey() > r4 && mousey() < r4 + 200 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r4 -= 100;


				if (r4<0 || r4>400){ r4 += 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 400, r4) == 1){ r4 += 100; hareket--; }//r4 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 400, r4) == 1){ r4 += 100; hareket--; }//r4 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 400, r4) == 1){ r4 += 100; hareket--; }//r4 r6
				if (ic(1, 1, 2, 400, 200 + r9, 2, 2, 400, r4) == 1){ r4 += 100; hareket--; }//r4 r9
				if (ic(2, 1, 3, r10, 500, 2, 2, 400, r4) == 1){ r4 += 100; hareket--; }//r4 r10
				if (ic(2, 1, 2, 400 + r12, 400 + r9, 2, 2, 400, r4) == 1){ r4 += 100; hareket--; }//r4 r12


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r4;
				x = 80;
			}//r4
			if (mousex()<600 && mousex()>500 && mousey() > r5 && mousey() < r5 + 300 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r5 += 100;


				if (r5<0 || r5>300){ r5 -= 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 3, 500, r5) == 1){ r5 -= 100; hareket--; }//r5 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 3, 500, r5) == 1){ r5 -= 100; hareket--; }//r5 r3
				if (ic(2, 1, 2, r6, 200, 2, 3, 500, r5) == 1){ r5 -= 100; hareket--; }//r5 r6
				if (ic(2, 1, 3, r10, 500, 2, 3, 500, r5) == 1){ r5 -= 100; hareket--; }//r5 r10
				if (ic(2, 1, 2, 400 + r12, 400, 2, 3, 500, r5) == 1){ r5 -= 100; hareket--; }//r5 r12


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r5;
				x = 90;
			}
			if (mousex()<600 && mousex()>500 && mousey() > r5 && mousey() < r5 + 300 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r5 -= 100;


				if (r5<0 || r5>300){ r5 += 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 3, 500, r5) == 1){ r5 += 100; hareket--; }//r5 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 3, 500, r5) == 1){ r5 += 100; hareket--; }//r5 r3
				if (ic(2, 1, 2, r6, 200, 2, 3, 500, r5) == 1){ r5 += 100; hareket--; }//r5 r6
				if (ic(2, 1, 3, r10, 500, 2, 3, 500, r5) == 1){ r5 += 100; hareket--; }//r5 r10
				if (ic(2, 1, 2, 400 + r12, 400, 2, 3, 500, r5) == 1){ r5 += 100; hareket--; }//r5 r12


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r5;
				x = 100;
			}//r5
			if (mousex()<200 + r6 && mousex()>r6 && mousey() > 200 && mousey() <300 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r6 += 100;


				if (r6 >= 600){

					kontrol = 7;
					cleardevice();
					swapbuffers();


				}//oyun bitimi
				if (ic(1, 1, 2, r6, 200, 2, 2, 0, r1) == 1){ r6 -= 100; hareket--; }//r6 r1
				if (ic(1, 1, 2, r6, 200, 2, 2, 400, r4) == 1){ r6 -= 100; hareket--; }//r6 r4
				if (ic(1, 1, 2, r6, 200, 2, 2, 500, r5) == 1){ r6 -= 100; hareket--; }//r6 r5
				if (ic(1, 1, 2, r6, 200, 2, 2, 200, 200 + r7) == 1){ r6 -= 100; hareket--; }//r6 r7
				if (ic(1, 1, 2, r6, 200, 2, 2, 300, 200 + r8) == 1){ r6 -= 100; hareket--; }//r6 r8
				if (ic(1, 1, 2, r6, 200, 2, 2, 400, 200 + r9) == 1){ r6 -= 100; hareket--; }//r6 r9
				if (ic(1, 1, 2, r6, 200, 2, 2, 300, 400 + r11) == 1){ r6 -= 100; hareket--; }//r6 r11

				clearviewport();
				swapbuffers();
				hareket++;
				positive = r6;
				x = 110;
			}
			if (mousex()<200 + r6 && mousex()>r6 && mousey() > 200 && mousey() <300 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r6 -= 100;


				if (r6<0 || r6>400){ r6 += 100; hareket--; }
				if (ic(1, 1, 2, r6, 200, 2, 2, 0, r1) == 1){ r6 += 100; hareket--; }//r6 r1
				if (ic(1, 1, 2, r6, 200, 2, 2, 400, r4) == 1){ r6 += 100; hareket--; }//r6 r4
				if (ic(1, 1, 2, r6, 200, 2, 2, 500, r5) == 1){ r6 += 100; hareket--; }//r6 r5
				if (ic(1, 1, 2, r6, 200, 2, 2, 200, 200 + r7) == 1){ r6 += 100; hareket--; }//r6 r7
				if (ic(1, 1, 2, r6, 200, 2, 2, 300, 200 + r8) == 1){ r6 += 100; hareket--; }//r6 r8
				if (ic(1, 1, 2, r6, 200, 2, 2, 400, 200 + r9) == 1){ r6 += 100; hareket--; }//r6 r9
				if (ic(1, 1, 2, r6, 200, 2, 2, 300, 400 + r11) == 1){ r6 += 100; hareket--; }//r6 r11

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r6;
				x = 120;
			}//r6
			if (mousex()<300 && mousex()>200 && mousey() > 200 + r7 && mousey() <400 + r7 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r7 += 100;


				if (r7<-200 || r7>200){ r7 -= 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 200, 200 + r7) == 1){ r7 -= 100; hareket--; }//r7 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 200, 200 + r7) == 1){ r7 -= 100; hareket--; }//r7 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 200, 200 + r7) == 1){ r7 -= 100; hareket--; }//r7 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 200, 200 + r7) == 1){ r7 -= 100; hareket--; }//r7 r10
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 200, 200 + r7) == 1){ r7 -= 100; hareket--; }//r7 r12



				clearviewport();
				swapbuffers();
				hareket++;
				positive = r7;
				x = 130;
			}

			if (mousex()<300 && mousex()>200 && mousey() > 200 + r7 && mousey() <400 + r7 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r7 -= 100;


				if (r7<-200 || r7>200){ r7 += 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 200, 200 + r7) == 1){ r7 += 100; hareket--; }//r7 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 200, 200 + r7) == 1){ r7 += 100; hareket--; }//r7 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 200, 200 + r7) == 1){ r7 += 100; hareket--; }//r7 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 200, 200 + r7) == 1){ r7 += 100; hareket--; }//r7 r10
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 200, 200 + r7) == 1){ r7 += 100; hareket--; }//r7 r12



				clearviewport();
				swapbuffers();
				hareket++;
				negative = r7;
				x = 140;
			}//r7
			if (mousex()<400 && mousex()>300 && mousey() > 200 + r8 && mousey() <400 + r8 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r8 += 100;


				if (r8<-200 || r8>200){ r8 -= 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 300, 200 + r8) == 1){ r8 -= 100; hareket--; }//r8 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 300, 200 + r8) == 1){ r8 -= 100; hareket--; }//8 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 300, 200 + r8) == 1){ r8 -= 100; hareket--; }//r8 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 300, 200 + r8) == 1){ r8 -= 100; hareket--; }//r8 r10
				if (ic(1, 1, 2, 300, 400 + r11, 2, 2, 300, 200 + r8) == 1){ r8 -= 100; hareket--; }//r8 r11
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 300, 200 + r8) == 1){ r8 -= 100; hareket--; }//r8 r12


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r8;
				x = 150;
			}
			if (mousex()<400 && mousex()>300 && mousey() > 200 + r8 && mousey() <400 + r8 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r8 -= 100;


				if (r8<-200 || r8>200){ r8 += 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 300, 200 + r8) == 1){ r8 += 100; hareket--; }//r8 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 300, 200 + r8) == 1){ r8 += 100; hareket--; }//8 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 300, 200 + r8) == 1){ r8 += 100; hareket--; }//r8 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 300, 200 + r8) == 1){ r8 += 100; hareket--; }//r8 r10
				if (ic(1, 1, 2, 300, 400 + r11, 2, 2, 300, 200 + r8) == 1){ r8 += 100; hareket--; }//r8 r11
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 300, 200 + r8) == 1){ r8 += 100; hareket--; }//r8 r12



				clearviewport();
				swapbuffers();
				hareket++;
				negative = r8;
				x = 160;
			}//r8
			if (mousex()<500 && mousex()>400 && mousey() > 200 + r9 && mousey() <400 + r9 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r9 += 100;


				if (r9<-200 || r9>200){ r9 -= 100; hareket--; }
				if (ic(2, 2, 2, 400, r4, 2, 2, 400, 200 + r9) == 1){ r9 -= 100; hareket--; }//r9 r4
				if (ic(2, 1, 2, r6, 200, 2, 2, 400, 200 + r9) == 1){ r9 -= 100; hareket--; }//r9 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 400, 200 + r9) == 1){ r9 -= 100; hareket--; }//r9 r10
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 400, 200 + r9) == 1){ r9 -= 100; hareket--; }//r9 r12


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r9;
				x = 170;
			}
			if (mousex()<500 && mousex()>400 && mousey() > 200 + r9 && mousey() <400 + r9 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r9 -= 100;


				if (r9<-200 || r9>200){ r9 += 100; hareket--; }
				if (ic(2, 2, 2, 400, r4, 2, 2, 400, 200 + r9) == 1){ r9 += 100; hareket--; }//r9 r4
				if (ic(2, 1, 2, r6, 200, 2, 2, 400, 200 + r9) == 1){ r9 += 100; hareket--; }//r9 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 400, 200 + r9) == 1){ r9 += 100; hareket--; }//r9 r10
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 400, 200 + r9) == 1){ r9 += 100; hareket--; }//r9 r12


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r9;
				x = 180;
			}//r9
			if (mousex()<300 + r10 && mousex()>r10 && mousey() >500 && mousey() <600 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r10 += 100;


				if (r10<0 || r10>300){ r10 -= 100; hareket--; }

				if (ic(1, 1, 3, r10, 500, 2, 2, 0, r1) == 1){ r10 -= 100; hareket--; }//r10 r1
				if (ic(1, 1, 3, r10, 500, 2, 3, 500, r5) == 1){ r10 -= 100; hareket--; }//r10 r5
				if (ic(1, 1, 3, r10, 500, 2, 2, 200, 200 + r7) == 1){ r10 -= 100; hareket--; }//r10 r7
				if (ic(1, 1, 3, r10, 500, 2, 2, 400, 200 + r9) == 1){ r10 -= 100; hareket--; }//r10 r9
				if (ic(1, 1, 3, r10, 500, 2, 2, 300, 400 + r11) == 1){ r10 -= 100; hareket--; }//r10 r11


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r10;
				x = 190;
			}
			if (mousex()<300 + r10 && mousex()>r10 && mousey() >500 && mousey() <600 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r10 -= 100;


				if (r10<0 || r10>300){ r10 += 100; hareket--; }
				if (ic(1, 1, 3, r10, 500, 2, 2, 0, r1) == 1){ r10 += 100; hareket--; }//r10 r1
				if (ic(1, 1, 3, r10, 500, 2, 3, 500, r5) == 1){ r10 += 100; hareket--; }//r10 r5
				if (ic(1, 1, 3, r10, 500, 2, 2, 200, 200 + r7) == 1){ r10 += 100; hareket--; }//r10 r7
				if (ic(1, 1, 3, r10, 500, 2, 2, 400, 200 + r9) == 1){ r10 += 100; hareket--; }//r10 r9
				if (ic(1, 1, 3, r10, 500, 2, 2, 300, 400 + r11) == 1){ r10 += 100; hareket--; }//r10 r11


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r10;
				x = 100;
			}//r10
			if (mousex()<400 && mousex()>300 && mousey() > 400 + r11 && mousey() <600 + r11 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r11 += 100;


				if (r11<-400 || r11>0){ r11 -= 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 300, 400 + r11) == 1){ r11 -= 100; hareket--; }//r11 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 300, 400 + r11) == 1){ r11 -= 100; hareket--; }//r11 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 300, 400 + r11) == 1){ r11 -= 100; hareket--; }//r11 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 300, 400 + r11) == 1){ r11 -= 100; hareket--; }//r11 r10
				if (ic(2, 2, 2, 300, 200 + r8, 2, 2, 300, 400 + r11) == 1){ r11 -= 100; hareket--; }//r11 r8
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 300, 400 + r11) == 1){ r11 -= 100; hareket--; }//r11 r12


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r11;
				x = 210;
			}
			if (mousex()<400 && mousex()>300 && mousey() > 400 + r11 && mousey() <600 + r11 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r11 -= 100;


				if (r11<-400 || r11>0){ r11 += 100; hareket--; }
				if (ic(2, 1, 2, 200 + r2, 0, 2, 2, 300, 400 + r11) == 1){ r11 += 100; hareket--; }//r11 r2
				if (ic(2, 1, 3, 100 + r3, 100, 2, 2, 300, 400 + r11) == 1){ r11 += 100; hareket--; }//r11 r3
				if (ic(2, 1, 2, r6, 200, 2, 2, 300, 400 + r11) == 1){ r11 += 100; hareket--; }//r11 r6
				if (ic(2, 1, 3, r10, 500, 2, 2, 300, 400 + r11) == 1){ r11 += 100; hareket--; }//r11 r10
				if (ic(2, 2, 2, 300, 200 + r8, 2, 2, 300, 400 + r11) == 1){ r11 += 100; hareket--; }//r11 r8
				if (ic(2, 1, 2, 400 + r12, 400, 2, 2, 300, 400 + r11) == 1){ r11 += 100; hareket--; }//r11 r12


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r11;
				x = 220;
			}//r11
			if (mousex()<600 + r12 && mousex()>400 + r12 && mousey() >400 && mousey() <500 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r12 += 100;


				if (r12<-400 || r12>0){ r12 -= 100; hareket--; }
				if (ic(1, 1, 2, 400 + r12, 400, 2, 2, 0, r1) == 1){ r12 -= 100; hareket--; }//r12 r1
				if (ic(1, 1, 2, 400 + r12, 400, 2, 3, 500, r5) == 1){ r12 -= 100; hareket--; }//r12 r5
				if (ic(1, 1, 2, 400 + r12, 400, 2, 2, 200, 200 + r7) == 1){ r12 -= 100; hareket--; }//r12 r7
				if (ic(1, 1, 2, 400 + r12, 400, 2, 2, 400, 200 + r9) == 1){ r12 -= 100; hareket--; }//r12 r9
				if (ic(1, 1, 2, 400 + r12, 400, 2, 2, 300, 400 + r11) == 1){ r12 -= 100; hareket--; }//r12 r11


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r12;
				x = 230;
			}
			if (mousex()<600 + r12 && mousex()>400 + r12 && mousey() >400 && mousey() <500 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r12 -= 100;


				if (r12<-400 || r12>0){ r12 += 100; hareket--; }
				if (ic(1, 1, 2, 400 + r12, 400, 2, 2, 0, r1) == 1){ r12 += 100; hareket--; }//r12 r1
				if (ic(1, 1, 2, 400 + r12, 400, 2, 3, 500, r5) == 1){ r12 += 100; hareket--; }//r12 r5
				if (ic(1, 1, 2, 400 + r12, 400, 2, 2, 200, 200 + r7) == 1){ r12 += 100; hareket--; }//r12 r7
				if (ic(1, 1, 2, 400 + r12, 400, 2, 2, 400, 200 + r9) == 1){ r12 += 100; hareket--; }//r12 r9
				if (ic(1, 1, 2, 400 + r12, 400, 2, 2, 300, 400 + r11) == 1){ r12 += 100; hareket--; }//r12 r11


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r12;
				x = 240;
			}//r12



			swapbuffers();




		}
		while (kontrol == 0)//OYUNUN GIRISI BASLA 1. tur
		{



			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
			//	clearmouseclick(WM_LBUTTONDBLCLK);


			setlinestyle(0, 0, 0);

			if (arka == 1)	readimagefile("b1.bmp", 0, 0, 602, 700);
			if (arka == 2)	readimagefile("b2.bmp", 0, 0, 602, 700);
			if (arka == 3)	readimagefile("b3.bmp", 0, 0, 602, 700);
			if (arka == 4)	readimagefile("b4.bmp", 0, 0, 602, 700);



			readimagefile("hareket.bmp", 250, 600, 360, 700);


			char a[10];
			setbkcolor(BLACK);
			sprintf(a, "%d", hareket);
			outtextxy(358, 705, a);
			setbkcolor(WHITE);
			settextstyle(3, 3, 2);
			setcolor(WHITE);
			setlinestyle(0, 0, 3);
			rectangle(0, 0, 600, 600);
			rectangle(0, 600, 150, 700);
			readimagefile("geri.bmp", 0, 600, 150, 700);



			if (ismouseclick(WM_LBUTTONDBLCLK) && mousex()<150 && mousex()> 0 && mousey() > 600 && mousey() < 700){//geri tusu
				clearmouseclick(WM_LBUTTONDBLCLK);
				kontrol = 1;
				arka = 0;//arka plan resmi
				ilk = 0;//resim seciminde kullandim

			}

			if (resim == 1){
				readimagefile("a1.bmp", 0, r1, 100, r1 + 200);
				readimagefile("a1.bmp", 100 + r2, 0, 300 + r2, 100);
				readimagefile("a1.bmp", 100 + r3, 100, 300 + r3, 200);
				readimagefile("a1.bmp", 300, r4, 400, 200 + r4);
				readimagefile("tahta.bmp", r5, 200, 200 + r5, 300);
				readimagefile("a1.bmp", 500, 0 + r6, 600, 300 + r6);
				readimagefile("a1.bmp", r7, 300, 300 + r7, 400);
				readimagefile("a1.bmp", 0, 400 + r8, 100, 600 + r8);
				readimagefile("a1.bmp", 200, 400 + r9, 300, 600 + r9);
				readimagefile("a1.bmp", 300 + r10, 400, 600 + r10, 500);
				readimagefile("a1.bmp", 400 + r11, 500, 600 + r11, 600);




			}
			if (resim == 2){
				readimagefile("a2.bmp", 0, r1, 100, r1 + 200);
				readimagefile("a2.bmp", 100 + r2, 0, 300 + r2, 100);
				readimagefile("a2.bmp", 100 + r3, 100, 300 + r3, 200);
				readimagefile("a2.bmp", 300, r4, 400, 200 + r4);
				readimagefile("tahta.bmp", r5, 200, 200 + r5, 300);
				readimagefile("a2.bmp", 500, 0 + r6, 600, 300 + r6);
				readimagefile("a2.bmp", r7, 300, 300 + r7, 400);
				readimagefile("a2.bmp", 0, 400 + r8, 100, 600 + r8);
				readimagefile("a2.bmp", 200, 400 + r9, 300, 600 + r9);
				readimagefile("a2.bmp", 300 + r10, 400, 600 + r10, 500);
				readimagefile("a2.bmp", 400 + r11, 500, 600 + r11, 600);




			}
			if (resim == 3){
				readimagefile("a3.bmp", 0, r1, 100, r1 + 200);
				readimagefile("a3.bmp", 100 + r2, 0, 300 + r2, 100);
				readimagefile("a3.bmp", 100 + r3, 100, 300 + r3, 200);
				readimagefile("a3.bmp", 300, r4, 400, 200 + r4);
				readimagefile("tahta.bmp", r5, 200, 200 + r5, 300);
				readimagefile("a3.bmp", 500, 0 + r6, 600, 300 + r6);
				readimagefile("a3.bmp", r7, 300, 300 + r7, 400);
				readimagefile("a3.bmp", 0, 400 + r8, 100, 600 + r8);
				readimagefile("a3.bmp", 200, 400 + r9, 300, 600 + r9);
				readimagefile("a3.bmp", 300 + r10, 400, 600 + r10, 500);
				readimagefile("a3.bmp", 400 + r11, 500, 600 + r11, 600);




			}
			if (resim == 4){
				readimagefile("tahta2.bmp", 0, r1, 100, r1 + 200);
				readimagefile("tahta2.bmp", 100 + r2, 0, 300 + r2, 100);
				readimagefile("tahta2.bmp", 100 + r3, 100, 300 + r3, 200);
				readimagefile("tahta2.bmp", 300, r4, 400, 200 + r4);
				readimagefile("tahta.bmp", r5, 200, 200 + r5, 300);
				readimagefile("tahta2.bmp", 500, 0 + r6, 600, 300 + r6);
				readimagefile("tahta2.bmp", r7, 300, 300 + r7, 400);
				readimagefile("tahta2.bmp", 0, 400 + r8, 100, 600 + r8);
				readimagefile("tahta2.bmp", 200, 400 + r9, 300, 600 + r9);
				readimagefile("tahta2.bmp", 300 + r10, 400, 600 + r10, 500);
				readimagefile("tahta2.bmp", 400 + r11, 500, 600 + r11, 600);




			}




			rectangle(0, r1, 100, r1 + 200);

			rectangle(100 + r2, 0, 300 + r2, 100);

			rectangle(100 + r3, 100, 300 + r3, 200);

			rectangle(300, r4, 400, 200 + r4);

			rectangle(0 + r5, 200, 200 + r5, 300);

			rectangle(500, 0 + r6, 600, 300 + r6);

			rectangle(r7, 300, 300 + r7, 400);

			rectangle(0, 400 + r8, 100, 600 + r8);

			rectangle(200, 400 + r9, 300, 600 + r9);

			rectangle(300 + r10, 400, 600 + r10, 500);

			rectangle(400 + r11, 500, 600 + r11, 600);

			readimagefile("tahta4.bmp", 600, 200, 650, 300);

			readimagefile("tahta7.bmp", 0, 592, 602, 606);


			readimagefile("tahta7.bmp", 590, 0, 610, 606);
			readimagefile("tahta7.bmp", 0, 0, 610, 7);
			readimagefile("tahta7.bmp", 0, 0, 6, 607);
			readimagefile("ok.gif", 590, 200, 610, 300);


			readimagefile("kayit.gif", 500, 606, 610, 700);
			readimagefile("gerial.gif", 370, 606, 490, 700);
			readimagefile("cift.bmp", 160, 606, 240, 700);


			if (mousex()<490 && mousex()>370 && mousey() > 606 && mousey() < 710 && ismouseclick(WM_LBUTTONDBLCLK)){//geri al tusu
				clearmouseclick(WM_LBUTTONDBLCLK);

				if (positive == r1&&	x == 10){ r1 -= 100; hareket--; }
				if (negative == r1&&	x == 20){ r1 += 100; hareket--; }
				if (positive == r2&&	x == 30){ r2 -= 100; hareket--; }
				if (negative == r2&&	x == 40){ r2 += 100; hareket--; }
				if (positive == r3&&	x == 50){ r3 -= 100; hareket--; }
				if (negative == r3&&	x == 60){ r3 += 100; hareket--; }
				if (positive == r4&&	x == 70){ r4 -= 100; hareket--; }
				if (negative == r4&&	x == 80){ r4 += 100; hareket--; }
				if (positive == r5&&	x == 90){ r5 -= 100; hareket--; }
				if (negative == r5&&	x == 100){ r5 += 100; hareket--; }
				if (positive == r6&&	x == 110){ r6 -= 100; hareket--; }
				if (negative == r6&&	x == 120){ r6 += 100; hareket--; }
				if (positive == r7&&	x == 130){ r7 -= 100; hareket--; }
				if (negative == r7&&	x == 140){ r7 += 100; hareket--; }
				if (positive == r8&&	x == 150){ r8 -= 100; hareket--; }
				if (negative == r8&&	x == 160){ r8 += 100; hareket--; }
				if (positive == r9&&	x == 170){ r9 -= 100; hareket--; }
				if (negative == r9&&	x == 180){ r9 += 100; hareket--; }
				if (positive == r10&&	x == 190){ r10 -= 100; hareket--; }
				if (negative == r10&&	x == 200){ r10 += 100; hareket--; }
				if (positive == r11&&	x == 210){ r11 -= 100; hareket--; }
				if (negative == r11&&	x == 220){ r11 += 100; hareket--; }
				positive = -1;
				negative = -1;
				x = -1;


			}

			if (mousex()<610 && mousex()>500 && mousey() > 606 && mousey() < 710 && ismouseclick(WM_LBUTTONDBLCLK)){//kayit tusu
				clearmouseclick(WM_LBUTTONDBLCLK);
				oyun = fopen("kayit.txt", "w");
				fprintf(oyun, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, hareket, arka, resim, kontrol);

				fclose(oyun);
				setcolor(BLACK);
				outtextxy(500, 606, "KAYDEDILDI");



			}




			if (mousex()<100 && mousex()> 0 && mousey() > r1&& mousey() < r1 + 200 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r1 += 100;
				if (r1<0 || r1>400){ r1 -= 100;  hareket--; }

				if (ic(2, 1, 2, 100 + r2, 0, 2, 2, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r2
				if (ic(2, 1, 2, 100 + r3, 100, 2, 2, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r3
				if (ic(2, 1, 2, r5, 200, 2, 2, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r5
				if (ic(2, 1, 3, r7, 300, 2, 2, 0, r1) == 1){ r1 -= 100; hareket--; }//r1 r7
				if (ic(2, 2, 2, 0, r1, 2, 2, 0, 400 + r8) == 1){ r1 -= 100; hareket--; }//r1 r8



				clearviewport();
				swapbuffers();
				hareket++;
				positive = r1;
				x = 10;


			}

			if (mousex()<100 && mousex()> 0 && mousey() > r1&& mousey() < r1 + 200 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r1 -= 100;


				if (r1<0 || r1>400){ r1 += 100; hareket--; }

				if (ic(2, 1, 2, 100 + r2, 0, 2, 2, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r2
				if (ic(2, 1, 2, 100 + r3, 100, 2, 2, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r3
				if (ic(2, 1, 2, r5, 200, 2, 2, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r5	
				if (ic(2, 1, 3, 0 + r7, 300, 2, 2, 0, r1) == 1){ r1 += 100; hareket--; }//r1 r7
				if (ic(2, 2, 2, 0, r1, 2, 2, 0, 400 + r8) == 1){ r1 += 100; hareket--; }//r1 r8


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r1;

				x = 20;
			}//r1



			if (mousex()<300 + r2&& mousex()>100 + r2 && mousey() > 0 && mousey() < 100 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r2 += 100;
				if (r2<-100 || r2>300){ r2 -= 100;  hareket--; }
				if (ic(1, 1, 2, 100 + r2, 0, 2, 2, 0, r1) == 1){ r2 -= 100; hareket--; }//r2 r1
				if (ic(1, 1, 2, 100 + r2, 0, 2, 2, 300, r4) == 1){ r2 -= 100; hareket--; }//r2 r4
				if (ic(1, 1, 2, 100 + r2, 0, 2, 3, 500, r6) == 1){ r2 -= 100; hareket--; }//r2 r6
				if (ic(1, 1, 2, 100 + r2, 0, 2, 2, 200, 400 + r9) == 1){ r2 -= 100; hareket--; }//r2 r9
				clearviewport();
				swapbuffers();
				hareket++;
				positive = r2;
				x = 30;

			}

			if (mousex()<300 + r2  && mousex()>100 + r2 && mousey() > 0 && mousey() < 100 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r2 -= 100;
				if (r2<-100 || r2>300){ r2 += 100; hareket--; }
				if (ic(1, 1, 2, 100 + r2, 0, 2, 2, 0, r1) == 1){ r2 += 100; hareket--; }//r2 r1
				if (ic(1, 1, 2, 100 + r2, 0, 2, 2, 300, r4) == 1){ r2 += 100; hareket--; }//r2 r4
				if (ic(1, 1, 2, 100 + r2, 0, 2, 3, 500, r6) == 1){ r2 += 100; hareket--; }//r2 r6
				if (ic(1, 1, 2, 100 + r2, 0, 2, 2, 200, 400 + r9) == 1){ r2 += 100; hareket--; }//r2 r9

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r2;
				x = 40;
			}//r2




			if (mousex()<300 + r3&& mousex()>100 + r3 && mousey() > 100 && mousey() < 200 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r3 += 100;
				if (r3<-100 || r3>300){ r3 -= 100;  hareket--; }
				if (ic(1, 1, 2, 100 + r3, 100, 2, 2, 0, r1) == 1){ r3 -= 100; hareket--; }//r3 r1
				if (ic(1, 1, 2, 100 + r3, 100, 2, 2, 300, r4) == 1){ r3 -= 100; hareket--; }//r3 r4
				if (ic(1, 1, 2, 100 + r3, 100, 2, 3, 500, r6) == 1){ r3 -= 100; hareket--; }//r3 r6
				if (ic(1, 1, 2, 100 + r3, 100, 2, 2, 200, 400 + r9) == 1){ r3 -= 100; hareket--; }//r3 r9
				cleardevice();
				swapbuffers();
				hareket++;
				positive = r3;
				x = 50;
			}

			if (mousex()<300 + r3  && mousex()>100 + r3 && mousey() > 100 && mousey() < 200 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r3 -= 100;
				if (r3<-100 || r3>300){ r3 += 100; hareket--; }
				if (ic(1, 1, 2, 100 + r3, 100, 2, 2, 0, r1) == 1){ r3 += 100; hareket--; }//r3 r1
				if (ic(1, 1, 2, 100 + r3, 100, 2, 2, 300, r4) == 1){ r3 += 100; hareket--; }//r3 r4
				if (ic(1, 1, 2, 100 + r3, 100, 2, 3, 500, r6) == 1){ r3 += 100; hareket--; }//r3 r6
				if (ic(1, 1, 2, 100 + r3, 100, 2, 2, 200, 400 + r9) == 1){ r3 += 100; hareket--; }//r3 r9
				cleardevice();
				swapbuffers();
				hareket++;
				negative = r3;
				x = 60;
			}//r3



			if (mousex()<400 && mousex()>300 && mousey() > r4&& mousey() < 200 + r4 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r4 += 100;
				if (r4<0 || r4>400){ r4 -= 100;  hareket--; }
				if (ic(2, 1, 2, 100 + r2, 0, 2, 2, 300, r4) == 1){ r4 -= 100; hareket--; }//r4 r2
				if (ic(2, 1, 2, 100 + r3, 100, 2, 2, 300, r4) == 1){ r4 -= 100; hareket--; }//r4 r3
				if (ic(2, 1, 2, r5, 200, 2, 2, 300, r4) == 1){ r4 -= 100; hareket--; }//r4 r5
				if (ic(2, 1, 3, r7, 300, 2, 2, 300, r4) == 1){ r4 -= 100; hareket--; }//r4 r7
				if (ic(2, 1, 2, 300 + r10, 400, 2, 2, 300, r4) == 1){ r4 -= 100; hareket--; }//r4 r10
				if (ic(2, 1, 2, 400 + r11, 500, 2, 2, 300, r4) == 1){ r4 -= 100; hareket--; }//r4 r11
				cleardevice();
				swapbuffers();
				hareket++;
				positive = r4;
				x = 70;

			}

			if (mousex()<400 && mousex()>300 && mousey() > r4&& mousey() < 200 + r4 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r4 -= 100;
				if (r4<0 || r4>400){ r4 += 100; hareket--; }
				if (ic(2, 1, 2, 100 + r2, 0, 2, 2, 300, r4) == 1){ r4 += 100; hareket--; }//r4 r2
				if (ic(2, 1, 2, 100 + r3, 100, 2, 2, 300, r4) == 1){ r4 += 100; hareket--; }//r4 r3
				if (ic(2, 1, 2, r5, 200, 2, 2, 300, r4) == 1){ r4 += 100; hareket--; }//r4 r5
				if (ic(2, 1, 3, r7, 300, 2, 2, 300, r4) == 1){ r4 += 100; hareket--; }//r4 r7
				if (ic(2, 1, 2, 300 + r10, 400, 2, 2, 300, r4) == 1){ r4 += 100; hareket--; }//r4 r10
				if (ic(2, 1, 2, 400 + r11, 500, 2, 2, 300, r4) == 1){ r4 += 100; hareket--; }//r4 r11

				cleardevice();
				swapbuffers();
				hareket++;
				negative = r4;
				x = 80;
			}//r4



			if (mousex()<200 + r5&& mousex()> r5 && mousey() > 200 && mousey() < 300 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r5 += 100;
				if (r5<0){ r5 -= 100; hareket--; }
				if (r5 >= 600){

					kontrol = 7;
					cleardevice();
					swapbuffers();


				}//oyun bitimi

				if (ic(1, 1, 2, r5, 200, 2, 2, 0, r1) == 1){ r5 -= 100; hareket--; }//r5 r1
				if (ic(1, 1, 2, r5, 200, 2, 2, 300, r4) == 1){ r5 -= 100; hareket--; }//r5 r4
				if (ic(1, 1, 2, r5, 200, 2, 3, 500, r6) == 1){ r5 -= 100; hareket--; }//r5 r6
				if (ic(1, 1, 2, r5, 200, 2, 2, 0, r8 + 400) == 1){ r5 -= 100; hareket--; }//r5 r8
				if (ic(1, 1, 2, r5, 200, 2, 2, 200, r9 + 400) == 1){ r5 -= 100; hareket--; }//r5 r9
				clearviewport();
				swapbuffers();
				hareket++;
				positive = r5;
				x = 90;

			}

			if (mousex()<200 + r5 && mousex()> r5 && mousey() > 200 && mousey() < 300 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r5 -= 100;
				if (r5<0 || r5>400){ r5 += 100; hareket--; }


				if (ic(1, 1, 2, r5, 200, 2, 2, 0, r1) == 1){ r5 += 100; hareket--; }//r5 r1
				if (ic(1, 1, 2, r5, 200, 2, 2, 300, r4) == 1){ r5 += 100; hareket--; }//r5 r4
				if (ic(1, 1, 2, r5, 200, 2, 3, 500, r6) == 1){ r5 += 100; hareket--; }//r5 r6
				if (ic(1, 1, 2, r5, 200, 2, 2, 0, r8 + 400) == 1){ r5 += 100; hareket--; }//r5 r8
				if (ic(1, 1, 2, r5, 200, 2, 2, 200, r9 + 400) == 1){ r5 += 100; hareket--; }//r5 r9
				clearviewport();
				swapbuffers();
				hareket++;
				negative = r5;
				x = 100;
			}//r5



			if (mousex()<600 && mousex()> 500 && mousey() > r6&& mousey() < 300 + r6 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r6 += 100;
				if (r6<0 || r6>300){ r6 -= 100; hareket--; }
				if (ic(2, 1, 2, 100 + r2, 0, 2, 3, 500, r6) == 1){ r6 -= 100; hareket--; }//r6 r2
				if (ic(2, 1, 2, 100 + r3, 100, 2, 3, 500, r6) == 1){ r6 -= 100; hareket--; }//r6 r3
				if (ic(2, 1, 2, r5, 200, 2, 3, 500, r6) == 1){ r6 -= 100; hareket--; }//r6 r5
				if (ic(2, 1, 3, r7, 300, 2, 3, 500, r6) == 1){ r6 -= 100; hareket--; }//r6 r7
				if (ic(2, 1, 3, 300 + r10, 400, 2, 3, 500, r6) == 1){ r6 -= 100; hareket--; }//r6 r10
				if (ic(2, 1, 2, 400 + r11, 500, 2, 3, 500, r6) == 1){ r6 -= 100; hareket--; }//r6 r11
				clearviewport();
				swapbuffers();
				hareket++;
				positive = r6;
				x = 110;
			}
			if (mousex()<600 && mousex()> 500 && mousey() > r6&& mousey() < 300 + r6 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r6 -= 100;
				if (r6<0 || r6>300) { r6 += 100; hareket--; }
				if (ic(2, 1, 2, 100 + r2, 0, 2, 3, 500, r6) == 1){ r6 += 100; hareket--; }//r6 r2
				if (ic(2, 1, 2, 100 + r3, 100, 2, 3, 500, r6) == 1){ r6 += 100; hareket--; }//r6 r3
				if (ic(2, 1, 2, r5, 200, 2, 3, 500, r6) == 1){ r6 += 100; hareket--; }//r6 r5
				if (ic(2, 1, 3, r7, 300, 2, 3, 500, r6) == 1){ r6 += 100; hareket--; }//r6 r7
				if (ic(2, 1, 3, 300 + r10, 400, 2, 3, 500, r6) == 1){ r6 += 100; hareket--; }//r6 r10
				if (ic(2, 1, 2, 400 + r11, 500, 2, 3, 500, r6) == 1){ r6 += 100; hareket--; }//r6 r11

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r6;
				x = 120;
			}//r6




			if (mousex()<r7 + 300 && mousex()>r7 && mousey() > 300 && mousey() < 400 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r7 += 100;
				if (r7<0 || r7>300){ r7 -= 100;  hareket--; }
				if (ic(1, 1, 3, r7, 300, 2, 2, 0, r1) == 1){ r7 -= 100; hareket--; }//r7 r1
				if (ic(1, 1, 3, r7, 300, 2, 2, 300, r4) == 1){ r7 -= 100; hareket--; }//r7 r4
				if (ic(1, 1, 3, r7, 300, 2, 3, 500, r6) == 1){ r7 -= 100; hareket--; }//r7 r6
				if (ic(1, 1, 3, r7, 300, 2, 2, 0, r8 + 400) == 1){ r7 -= 100; hareket--; }//r7 r8

				if (ic(1, 1, 3, r7, 300, 2, 2, 200, r9 + 400) == 1){ r7 -= 100; hareket--; }//r7 r9

				clearviewport();
				swapbuffers();
				hareket++;
				positive = r7;
				x = 130;
			}

			if (mousex()<r7 + 300 && mousex()>r7 && mousey() > 300 && mousey() < 400 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r7 -= 100;
				if (r7<0 || r7>300){ r7 += 100; hareket--; }
				if (ic(1, 1, 3, r7, 300, 2, 2, 0, r1) == 1){ r7 += 100; hareket--; }//r7 r1
				if (ic(1, 1, 3, r7, 300, 2, 2, 300, r4) == 1){ r7 += 100; hareket--; }//r7 r4
				if (ic(1, 1, 3, r7, 300, 2, 3, 500, r6) == 1){ r7 += 100; hareket--; }//r7 r6
				if (ic(1, 1, 3, r7, 300, 2, 2, 0, r8 + 400) == 1){ r7 += 100; hareket--; }//r7 r8
				if (ic(1, 1, 3, r7, 300, 2, 2, 200, r9 + 400) == 1){ r7 += 100; hareket--; }//r7 r9

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r7;
				x = 140;
			}//r7



			if (mousex()<100 && mousex()> 0 && mousey() > 400 + r8&& mousey() < 600 + r8 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r8 += 100;
				if (r8<-400 || r8>0){ r8 -= 100;  hareket--; }
				if (ic(2, 2, 2, 0, 400 + r8, 2, 2, 0, r1) == 1){ r8 -= 100; hareket--; }//r8 r1
				if (ic(2, 1, 3, r7, 300, 2, 2, 0, r8 + 400) == 1){ r8 -= 100; hareket--; }//r8 r7
				if (ic(2, 1, 2, r5, 200, 2, 2, 0, r8 + 400) == 1){ r8 -= 100; hareket--; }//r8 r5
				if (ic(2, 1, 3, 300 + r10, 400, 2, 2, 0, r8 + 400) == 1){ r8 -= 100; hareket--; }//r8 r10
				if (ic(2, 1, 2, 400 + r11, 500, 2, 2, 0, r8 + 400) == 1){ r8 -= 100; hareket--; }//r8 r11
				clearviewport();
				swapbuffers();
				hareket++;
				positive = r8;
				x = 150;
			}

			if (mousex()<100 && mousex()> 0 && mousey() > 400 + r8&& mousey() < 600 + r8 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r8 -= 100;
				if (r8<-400 || r8>0){ r8 += 100; hareket--; }
				if (ic(2, 2, 2, 0, 400 + r8, 2, 2, 0, r1) == 1){ r8 += 100; hareket--; }//r8 r1
				if (ic(2, 1, 2, r5, 200, 2, 2, 0, r8 + 400) == 1){ r8 += 100; hareket--; }//r8 r5
				if (ic(2, 1, 3, r7, 300, 2, 2, 0, r8 + 400) == 1){ r8 += 100; hareket--; }//r8 r7
				if (ic(2, 1, 3, 300 + r10, 400, 2, 2, 0, r8 + 400) == 1){ r8 += 100; hareket--; }//r8 r10
				if (ic(2, 1, 2, 400 + r11, 500, 2, 2, 0, r8 + 400) == 1){ r8 += 100; hareket--; }//r8 r11		
				clearviewport();
				swapbuffers();
				hareket++;
				negative = r8;
				x = 160;
			}//r8



			if (mousex()<300 && mousex()>200 && mousey() > 400 + r9&& mousey() < 600 + r9 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r9 += 100;
				if (r9<-400 || r9>0){ r9 -= 100;  hareket--; }
				if (ic(2, 1, 3, r7, 300, 2, 2, 200, r9 + 400) == 1){ r9 -= 100; hareket--; }//r9 r7	
				if (ic(2, 1, 2, r5, 200, 2, 2, 200, r9 + 400) == 1){ r9 -= 100; hareket--; }//r9 r5	
				if (ic(2, 1, 2, 100 + r3, 100, 2, 2, 200, r9 + 400) == 1){ r9 -= 100; hareket--; }//r9 r3
				if (ic(2, 1, 2, 100 + r2, 0, 2, 2, 200, r9 + 400) == 1){ r9 -= 100; hareket--; }//r9 r2
				if (ic(2, 1, 3, 300 + r10, 400, 2, 2, 200, r9 + 400) == 1){ r9 -= 100; hareket--; }//r9 r10
				if (ic(2, 1, 2, 400 + r11, 500, 2, 2, 200, r9 + 400) == 1){ r9 -= 100; hareket--; }//r9 r11		
				clearviewport();
				swapbuffers();
				hareket++;
				positive = r9;
				x = 170;
			}

			if (mousex()<300 && mousex()>200 && mousey() > 400 + r9&& mousey() < 600 + r9 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r9 -= 100;
				if (r9<-400 || r9>0){ r9 += 100; hareket--; }
				if (ic(2, 1, 3, r7, 300, 2, 2, 200, r9 + 400) == 1){ r9 += 100; hareket--; }//r9 r7	
				if (ic(2, 1, 2, r5, 200, 2, 2, 200, r9 + 400) == 1){ r9 += 100; hareket--; }//r9 r5	
				if (ic(2, 1, 2, 100 + r3, 100, 2, 2, 200, r9 + 400) == 1){ r9 += 100; hareket--; }//r9 r3
				if (ic(2, 1, 2, 100 + r2, 0, 2, 2, 200, r9 + 400) == 1){ r9 += 100; hareket--; }//r9 r2
				if (ic(2, 1, 3, 300 + r10, 400, 2, 2, 200, r9 + 400) == 1){ r9 += 100; hareket--; }//r9 r10
				if (ic(2, 1, 2, 400 + r11, 500, 2, 2, 200, r9 + 400) == 1){ r9 += 100; hareket--; }//r9 r11

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r9;
				x = 180;
			}//r9




			if (mousex()<600 + r10&& mousex()>300 + r10 && mousey() > 400 && mousey() < 500 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r10 += 100;
				if (r10<-300 || r10>0){ r10 -= 100;  hareket--; }
				if (ic(1, 1, 3, 300 + r10, 400, 2, 2, 200, r9 + 400) == 1){ r10 -= 100; hareket--; }//r10 r9
				if (ic(1, 1, 3, 300 + r10, 400, 2, 2, 0, r8 + 400) == 1){ r10 -= 100; hareket--; }//r10 r8
				if (ic(1, 1, 3, 300 + r10, 400, 2, 2, 300, r4) == 1){ r10 -= 100; hareket--; }//r10 r4


				clearviewport();
				swapbuffers();
				hareket++;
				positive = r10;
				x = 190;
			}

			if (mousex()<600 + r10&& mousex()>300 + r10 && mousey() > 400 && mousey() < 500 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r10 -= 100;
				if (r10<-300 || r10>0){ r10 += 100; hareket--; }
				if (ic(1, 1, 3, 300 + r10, 400, 2, 2, 200, r9 + 400) == 1){ r10 += 100; hareket--; }//r10 r9
				if (ic(1, 1, 3, 300 + r10, 400, 2, 2, 0, r8 + 400) == 1){ r10 += 100; hareket--; }//r10 r8
				if (ic(1, 1, 3, 300 + r10, 400, 2, 2, 300, r4) == 1){ r10 += 100; hareket--; }//r10 r4

				clearviewport();
				swapbuffers();
				hareket++;
				negative = r10;
				x = 200;
			}//r10




			if (mousex()<600 + r11&& mousex()>400 + r11 && mousey() > 500 && mousey() < 600 && ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				r11 += 100;
				if (r11<-400 || r11>0){ r11 -= 100;  hareket--; }
				if (ic(1, 1, 2, 400 + r11, 500, 2, 2, 200, 400 + r9) == 1){ r11 -= 100; hareket--; }//r11 r9
				if (ic(1, 1, 2, 400 + r11, 500, 2, 2, 0, 400 + r8) == 1){ r11 -= 100; hareket--; }//r11 r8
				if (ic(1, 1, 2, 400 + r11, 500, 2, 2, 300, r4) == 1){ r11 -= 100; hareket--; }//r11 r4
				if (ic(1, 1, 2, 400 + r11, 500, 2, 3, 500, r6) == 1){ r11 -= 100; hareket--; }//r11 r6

				clearviewport();
				swapbuffers();
				hareket++;
				positive = r11;
				x = 210;
			}

			if (mousex()<600 + r11&& mousex()>400 + r11 && mousey() > 500 && mousey() < 600 && ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				r11 -= 100;
				if (r11<-400 || r11>0){ r11 += 100; hareket--; }
				if (ic(1, 1, 2, 400 + r11, 500, 2, 2, 200, 400 + r9) == 1){ r11 += 100; hareket--; }//r11 r9
				if (ic(1, 1, 2, 400 + r11, 500, 2, 2, 0, 400 + r8) == 1){ r11 += 100; hareket--; }//r11 r8
				if (ic(1, 1, 2, 400 + r11, 500, 2, 2, 300, r4) == 1){ r11 += 100; hareket--; }//r11 r4
				if (ic(1, 1, 2, 400 + r11, 500, 2, 3, 500, r6) == 1){ r11 += 100; hareket--; }//r11 r6


				clearviewport();
				swapbuffers();
				hareket++;
				negative = r11;
				x = 220;
			}//r11



			swapbuffers();


		}

	}




	return EXIT_SUCCESS;

	closegraph(CURRENT_WINDOW);

}





