/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : 24060124120026 / Gregorius Septiano Ariadi */
/* Tanggal : Kamis, 06 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address P) {
	//kamus lokal
	
	//algoritma
    if (P != NIL) {
        free(P);
    }
}

/*********** OPERATORS ***********/

/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List1 L) {
	//kamus lokal 
	address P;
	//algoritma
    P = First(L);
    printf("\nElemen =\t");
    while (P != NIL) {
        printf("%c\t", info(P));
        P = next(P);
    }
    printf("\n"); 
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L){
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L){
	return First(L) == NIL;
}


/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L) {
    //kamus lokal 
	address P;
    int count;
	//algoritma
	count = 0;
	P = First(L);
	while (P != NIL) {
		count++;
		P = next(P);
	}
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ){
    //kamus lokal
	address P;
    //algoritma
	P = Alokasi(V);
	if(IsEmptyList(*L)) {
		First(*L) = P;
	} else {
		next(P) = First(*L);
		First(*L) = P;
	}
}


/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V) {
    //kamus lokal
    address P, Q;
    //algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
        } else {
            Q = First(*L);
            while (next(Q) != NIL) {
                Q = next(Q);
            }
            next(Q) = P;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V) {
    //kamus lokal
    address P;
    //algoritma
    if (IsEmptyList(*L)) {
        *V = '#';
    } else {
        P = First(*L);
        *V = info(P);
        First(*L) = next(P);
        Dealokasi(P);
    }
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V) {
    //kamus lokal
    address P, Prec;
    //algoritma
    if (IsEmptyList(*L)) {
        *V = '#';
    } else if (next(First(*L)) == NIL) {
        P = First(*L);
        *V = info(P);
        First(*L) = NIL;
        Dealokasi(P);
    } else {
        Prec = NIL;
        P = First(*L);
        while (next(P) != NIL) {
            Prec = P;
            P = next(P);
        }
        *V = info(P);
        next(Prec) = NIL;
        Dealokasi(P);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A) {
    //kamus lokal
    address P;
    //algoritma
	P = First(L);
	*A = NIL;
	while (P != NIL && *A == NIL) {
		if (info(P) == X) {
			*A = P;
		} else {
			P = next(P);
		}
	}
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y) {
    //kamus lokal
    address P;
    //algoritma
    P = First(*L);
    while (P != NIL) {
        if (info(P) == X) {
            info(P) = Y;
        }
        P = next(P);
    }
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L) {
    //kamus lokal
    address prev, curr, nextNode;
    //algoritma
    prev = NIL;
    curr = First(*L);
    while (curr != NIL) {
        nextNode = next(curr);
        next(curr) = prev;
        prev = curr;
        curr = nextNode;
    }
    First(*L) = prev;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountVocal(L:List1) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List1 L) {
    //kamus lokal
    address P;
    int count;
    char c;
    //algoritma
    count = 0;
    P = First(L);
    while (P != NIL) {
        c = info(P);
        if (c=='a' || c=='i' || c=='u' || c=='e' || c=='o' ||
            c=='A' || c=='I' || c=='U' || c=='E' || c=='O') {
            count++;
        }
        P = next(P);
    }
    return count;
}

/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X) {
    //kamus lokal
    address P;
    int count;
    //algoritma
	P = First(L);
	count = 0;
	while (P != NIL) {
		if (info(P) == X) {
			count++;
		}
		P = next(P);
	}
	return count;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X) {
    //kamus lokal
    int n;
    //algoritma
	n = NbElm(L);
	if (n == 0) {
		return 0;
	} else {
		return (float)CountX(L, X) / n * 100;
	}
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X) {
    //kamus lokal
    address P;
    int i, found;
    //algoritma    
	P = First(L);
	i = 1, found = 0;
	printf("Posisi %c: ", X);
	while (P != NIL) {
		if (info(P) == X) {
			printf("%d ", i);
			found = 1;
		}
		i++;
		P = next(P);
	}
	if (!found) {
		printf("tidak ditemukan");
	}
	printf("\n");
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y) {
    //kamus lokal
    address P;
    //algoritma    
	P = First(*L);
	while (P != NIL) {
		if (info(P) == X) {
			info(P) = Y;
		}
		P = next(P);
	}
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA) {
    //kamus lokal
	address P, Q;
    //algoritma  
	SearchX(*L, V, &P);
	if (P != NIL) {
		Q = Alokasi(VA);
		if (Q != NIL) {
			next(Q) = next(P);
			next(P) = Q;
		}
	}
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L) {
    //kamus lokal
    address P;
    //algoritma     
	P = First(L);
	if (P == NIL) {
		return '#';
	}
	int max = 0;
	infotype modus = info(P);
	while (P != NIL) {
		int c = CountX(L, info(P));
		if (c > max) {
			max = c;
			modus = info(P);
		}
		P = next(P);
	}
	return modus;
}

/*function NbModus(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int NbModus(List1 L) {
    //kamus lokal
    address P;
    //algoritma   
	P = First(L);
	if (P == NIL) {
		return 0;
	}
	int max = 0;
	while (P != NIL) {
		int c = CountX(L, info(P));
		if (c > max) {
			max = c;
		}
		P = next(P);
	}
	return max;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L) {
    //kamus lokal
    address P;
    //algoritma 
	CreateList(L);
	P = First(L1);
	while (P != NIL) {
		InsertVLast(L, info(P));
		P = next(P);
	}
	P = First(L2);
	while (P != NIL) {
		InsertVLast(L, info(P));
		P = next(P);
	}
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List1 L, List1 *L1, List1 *L2) {
        //kamus lokal
    address P;
    int n, mid, i;
    //algoritma 
	CreateList(L1);
	CreateList(L2);
	n = NbElm(L);
	mid = (n + 1) / 2;
	i = 1;
	P = First(L);
	while (P != NIL) {
		if (i <= mid) {
			InsertVLast(L1, info(P));
		} else {
			InsertVLast(L2, info(P));
		}
		i++;
		P = next(P);
	}
}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2) {
    //kamus lokal
    address P;
    //algoritma 
	CreateList(L2);
	P = First(L1);
	while (P != NIL) {
		InsertVLast(L2, info(P));
		P = next(P);
	}
}