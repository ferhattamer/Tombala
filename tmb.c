#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define tassayisi 90
#define oyuncusayisi 5
#define satirsayisi 3
#define sutunsayisi 5
#define kagittakisayilar 15

char isim[5][20];
int tombala[oyuncusayisi][satirsayisi][sutunsayisi];
int torba[tassayisi];
int karsilastir[15];
int kontroldizisi[kagittakisayilar];
int x,y,z,toplam,kazanan,sayi,seed,oyunbitti,sira,temp,operasyon,islem,b,rastgele,sayac,oyuncu,cik,x1,a,istem,girdi;
kartDagit()
{
	
	for(x=0;x<oyuncusayisi;x++){
		for(y=0;y<satirsayisi;y++){
			for(z=0;z<sutunsayisi;z++){
				tombala[x][y][z]=-1;
			}
		}
	}
}
void kartUret(int x){
	printf("lutfen oyuncu adi giriniz : ");
	scanf("%s",&isim[x]);
		for(b=0;b<15;b++){
		karsilastir[b]=0;
	}
		sira=0;
	for(y=0;y<3;y++){
		for(z=0;z<5;z++){
			sayi=rand()%tassayisi+1;
			tombala[x][y][z]=sayi;
			karsilastir[sira]=sayi;
			for(a=0;a<sira;a++){
				if(karsilastir[sira]==karsilastir[a]){
					sayi=rand()%tassayisi+1;
					tombala[x][y][z]=sayi;
					karsilastir[sira]=sayi;
					a=-1;
				}
			}
		sira=sira+1;
		}
	}	
	}

torbaOlustur()
{
	for(x=0;x<tassayisi;x++){
		torba[x]=x+1;
	}
}
torbaYazdir()
{
	for(x=0;x<tassayisi;x++){if(torba[x]!=0){
	printf("|%d|",torba[x]);}
	}
}
void sayiUret(int x)
{
	cik=0;
	do{
			rastgele=rand()%tassayisi;
			if(torba[rastgele]!=0){
			printf("torbadan cekilentas : %d \n",torba[rastgele]);
			for(x=0;x<oyuncusayisi;x++){
		for(y=0;y<satirsayisi;y++){
			for(z=0;z<sutunsayisi;z++){
				if(tombala[x][y][z]==torba[rastgele])
				{
				tombala[x][y][z]=0;
				printf("cekilen tas kartinizdan silindi",torba[rastgele]);
				kartYazdir(x);
				}
			}
		}
	}
			torba[rastgele]=0;
	cik=cik+1;
	}
	}while(cik<1);
	
}
 kartYazdir(int x)
{
	printf("\n");
	printf("%d numarali oyuncu : ",x+1);
	for(y=0;y<20;y++){
		printf("%c",isim[x][y]);
		}printf("\n");
		for(y=0;y<satirsayisi;y++){
			for(z=0;z<sutunsayisi;z++){
				
				printf("|%d|",tombala[x][y][z]);
			}
			printf("\n");
		}printf("\n");
	
}
void tombalaBul(int x )
{
	printf("tombala araniyor.");
		sleep(1);
										printf(".");
										sleep(1);
										printf(".");
										sleep(1);
											printf(".");
										sleep(1);
										printf(".");
										sleep(1);
											printf(".");
										sleep(1);
										printf(".");
										sleep(1);
										printf(".\n");
	for(y=0;y<satirsayisi;y++){
		for(z=0;z<sutunsayisi;z++){
			toplam=toplam+tombala[x][y][z];
		}
	}
	
			if(toplam==0)
			{
				kazanan=x+1;
				printf("\n\n oyun bitti %d numarali oyuncu kazandi : ",kazanan);
					for(y=0;y<20;y++){
		printf("%c",isim[x][y]);
		}printf("\n");
				operasyon=5;
			}
			printf("%d numarali oyuncuda tombala yok.\n",++x);
			toplam=0;
}
void karttaAra(int sayi){
	for(y=0;y<satirsayisi;y++){
		for(z=0;z<sutunsayisi;z++){
			if(tombala[sayi][y][z]==rastgele)
			{
				tombala[sayi][y][z]=0;
			}
		}
	}
}

nasilOynanir()
{
		printf("\n\nTOMBALA NASIL OYNANIR\n");
	printf("---------------------");
	printf("\nSize Rastgele kart verilir.");
	printf("\nTorbadan hilesiz rastgele tas cekilir. \n");
	printf("\nCikan tas kartinizda var ise o sayi kartinizdan silinir .\n");
	printf("\nKartinizdaki tum sayilar silindiinde oyunu kazanmis olursunuz.\n ");
	printf("\nIyi Sanslar :)) ");
}

main()
{
torbaOlustur();
seed=(time(NULL));
srand(seed);
	do{
			printf("\n        OYUN MENUSU");
		printf("\n        ------------");
		printf("\n	1 - Oyuncu ekle");
		printf("\n	2 - Torbadan tas cek");
		printf("\n	3 - Kartlari yazdir");
		printf("\n	4 - Nasil oynanir?");
		printf("\n	5 - Oynamak istemiyorum - Cikis");
		printf("\n 	6 - Torba yazdir");
		printf("\n 	7 - Yeniden Baslat");
		printf("\nYapmak istediginiz islem  ");
		do{
	scanf("%c",&girdi);
			operasyon = (int)girdi;
			if((operasyon<49)||(operasyon>55))
        {
            printf("1-7 arasinda bir Sayi girin :  ");
            continue;
        }

    }while(operasyon<49||operasyon>55);
		switch(operasyon){
			case 49://oyuncu ekle en fazla 5
			if(islem<5){
				if(istem==0){
				kartUret(islem);
				kartYazdir(islem);
				oyuncu=islem;
				islem=islem+1;
			}
			else printf("sayi uretttiniz yeni oyuncu ekleyemezsiniz.lutfen oyunu yeniden baslatin.\n");
		}
		else printf("en fazla 5 oyuncu ile oynayabilirsiniz lutfen oyuna baslayiniz");
				break;
				case 50:
					if(islem>0){
					printf("torba karistiriliyor.");	sleep(1);
										printf(".");
										sleep(1);
										printf(".");
										sleep(1);
										printf(".\n");
						sayiUret(oyuncu);
					for(x=oyuncu;x>=0;x--){
					tombalaBul(x);
					istem=istem+1;
				}
					}
					else printf("oyuncu eklemeden rastgele sayi secemezsiniz.");
					break;
					case 51:
					for(x=oyuncu;x>=0;x--){
					kartYazdir(x);
				}
						break;
						case 52:
							nasilOynanir();
							break;
							case 53:
								printf("oyunkapatiliyor.");
									sleep(1);
										printf(".");
										sleep(1);
										printf(".");
										sleep(1);
										printf(".");
								break;
								case 54:
									torbaYazdir();
									break;
									case 55:
										islem=0;
										istem=0;
										torbaOlustur();
										printf("oyun yeniden baslatildi.");
										sleep(1);
										printf(".");
										sleep(1);
										printf(".");
										sleep(1);
										printf(".");	
										break;
											default:
												printf("lutfen 1-7 arasinda sayi gir : ");
												break;
		}
		
	}while(operasyon!=53);
}
