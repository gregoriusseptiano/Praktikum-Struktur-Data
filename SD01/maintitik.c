/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124120026/Gregorius Septiano Ariadi*/
/* Tanggal   : Kamis, 4 September 2025*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
	//kamus main
	Titik T1;
	Titik T2;
	Titik T3;
	Titik T4;

	//algoritma
	printf("Halo, ini driver modul Titik \n");
	
	makeTitik0(&T1);
	printf("\nNilai Absis T1 = %d",getAbsis(T1));
	printf("\nNilai Ordinat T1 = %d",getOrdinat(T1));

	makeTitik(&T2,4,10);
	printf("\nNilai Absis T2 = %d",getAbsis(T2));
	printf("\nNilai Ordinat T2 = %d",getOrdinat(T2));

	makeTitik(&T3,8,7);
	setAbsis(&T3,3);
	setOrdinat(&T3,5);
	printf("\nNilai Absis T3 setelah di-set = %d",getAbsis(T3));
	printf("\nNilai Ordinat T3 setelah di-set = %d",getOrdinat(T3));

	printf("\nApakah T1 di titik origin? %d",isOrigin(T1));
	printf("\nApakah T2 di sumbu X? %d",isOnSumbuX(T2));
	printf("\nApakah T2 di sumbu Y? %d",isOnSumbuY(T2));
	printf("\nApakah T1 dan T2 sama? %d",isEqual(T1,T2));

	refleksiX(&T3);
	refleksiY(&T3);
	printf("\nNilai Absis T3 setelah refleksi = %d",getAbsis(T3));
	printf("\nNilai Ordinat T3 setelah refleksi = %d",getOrdinat(T3));

	geser(&T3,5,7);
	printf("\nNilai Absis T3 setelah digeser = %d",getAbsis(T3));
	printf("\nNilai Ordinat T3 setelah digeser = %d",getOrdinat(T3));
	
	makeTitik(&T4,3,6);
	dilatasi(&T4,12);
	printf("\nNilai Absis T4 setelah dilatasi (pusat 0,0) = %d",getAbsis(T4));
	printf("\nNilai Ordinat T4 setelah dilatasi (pusat 0,0) = %d",getOrdinat(T4));
	
	dilatasiX(&T4,T2,9);
	printf("\nNilai Absis T4 setelah dilatasi terhadap T2 = %d",getAbsis(T4));
	printf("\nNilai Ordinat T4 setelah dilatasi terhadap T2 = %d",getOrdinat(T4));

	printf("\nT4 berada di kuadran = %d",kuadran(T4));

	return 0;
}
