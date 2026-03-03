/* File : List2.c */
/* Deskripsi : realisasib body ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : Gregorius Septiano Ariadi / 24060124120026*/
/* Tanggal : Kamis, 13 November 2025*/

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"
#include "boolean.h" 

/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
    //kamus lokal
    address P;
    //algoritma 
    P = (address) malloc(sizeof(Elm)); 
    if (P != NIL ) {
        info(P) = E;
        next(P) = P;
    }
    return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi(address *P) {
    //kamus lokal 

    //algoritma   
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList(List2 *L) {
    //kamus lokal 
    
    //algoritma
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List2 L) {
    //kamus lokal 
    
    //algoritma
    return (First(L) == NIL);
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm(List2 L) {
    //kamus lokal 
    
    //algoritma
    return (!IsEmptyList(L) && next(First(L)) == First(L));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L) {
    //kamus lokal 
    address P;
    //algoritma
    if (IsEmptyList(L)) {
        printf("List kosong\n");
    } else {
        P = First(L);
        do {
            printf("%c ", info(P));
            P = next(P);
        } while (P != First(L));
        printf("\n");
    }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
    //kamus lokal 
    int n;
    address P;
    //algoritma
    n = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            n++;
            P = next(P);
        } while (P != First(L));
    }
    return n;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V) {
    //kamus lokal 
    address P, Last;
    //algoritma    
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P;
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(P) = First(*L);
            next(Last) = P;
            First(*L) = P;
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V) {
    //kamus lokal 
    address P, Last;
    //algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = P;
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(Last) = P;
            next(P) = First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
    //kamus lokal
    address P, Last;
    //algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        *V = info(P);
        if (IsOneElm(*L)) {
            First(*L) = NIL;
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
        }
        Dealokasi(&P);
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
    //kamus lokal
    address P, Prec;
    //algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L); 
        Prec = NIL;
        while (next(P) != First(*L)) {
            Prec = P;
            P = next(P);
        }
        *V = info(P);
        if (Prec == NIL) {
            First(*L) = NIL;
        } else {
            next(Prec) = First(*L);
        }
        Dealokasi(&P);
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
    //kamus lokal
    address P, Prec, Last;
    //algoritma
    if (!IsEmptyList(*L)) {
        Last = First(*L);
        while (next(Last) != First(*L)) {
            Last = next(Last);
        }
        P = First(*L);
        Prec = Last;
        do {
            if (info(P) == X) {
                if (P == First(*L)) {
                    DeleteVFirst(L, &X);
                } else if (next(P) == First(*L)) { 
                    DeleteVLast(L, &X);
                } else {
                    next(Prec) = next(P);
                    Dealokasi(&P);
                }
                return;
            }
            Prec = P;
            P = next(P);
        } while (P != First(*L));
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
    //kamus lokal
    address P;
    //algoritma
    *A = NIL;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) {
                *A = P;
                return;
            }
            P = next(P);
        } while (P != First(L));
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
    //kamus lokal
    address P;
    //algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X) {
                info(P) = Y;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L) {
    //kamus lokal
    address Prev, Curr, Next, Last;
    //algoritma
    if (!IsEmptyList(*L) && !IsOneElm(*L)) {
        Last = First(*L);
        while (next(Last) != First(*L)) {
            Last = next(Last);
        }
        Prev = Last;
        Curr = First(*L);
        do {
            Next = next(Curr);
            next(Curr) = Prev;
            Prev = Curr;
            Curr = Next;
        } while (Curr != First(*L));
        First(*L) = Prev;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
    //kamus lokal
    int count;
    address P;
    //algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) count++;
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X) {
    //kamus lokal
    int total;
    //algoritma
    total = NbElm(L);
    if (total == 0) 
        return 0;
    return (float)CountX(L, X) / total;
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
    //kamus lokal
    int count;
    address P;
    char c;
    //algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            c = info(P);
            if (c=='A'||c=='I'||c=='U'||c=='E'||c=='O'||
                c=='a'||c=='i'||c=='u'||c=='e'||c=='o')
                count++;
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L) {
    //kamus lokal
    int count;
    address P;
    //algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P)=='N' && info(next(P))=='G') 
                count++;
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
    //kamus lokal
    address P, New;
    //algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X) {
                New = Alokasi(V);
                next(New) = next(P);
                next(P) = New;
                return;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
    //kamus lokal
    address P, Prec, New;
    //algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        Prec = NIL;
        do {
            if (info(P) == X) {
                if (Prec == NIL) {
                    InsertVFirst(L, V);
                } else {
                    New = Alokasi(V);
                    next(New) = P;
                    next(Prec) = New;
                }
                return;
            }
            Prec = P;
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
    //kamus lokal
    address P, Del;
    //algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X && next(P) != P) {
                Del = next(P);
                *V = info(Del);
                next(P) = next(Del);
                Dealokasi(&Del);
                return;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
    //kamus lokal
    address P, Prec, Prec2;
    //algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        P = First(*L);
        Prec = NIL;
        Prec2 = NIL;
        do {
            if (info(P) == X && Prec != NIL) {
                *V = info(Prec);
                if (Prec2 == NIL) {
                    DeleteVFirst(L, V);
                } else {
                    next(Prec2) = P;
                    Dealokasi(&Prec);
                }
                return;
            }
            Prec2 = Prec;
            Prec = P;
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X) {
    //kamus lokal

    //algoritma
    while (CountX(*L, X) > 0) {
        DeleteX(L, X);
    }
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
    //kamus lokal
    int idx, found;
    address P;
    //algoritma
    if (IsEmptyList(L)) {
        printf("0\n");
        return;
    }
    idx = 1;
    found = 0;
    P = First(L);
    do {
        if (info(P) == X) {
            printf("%d ", idx);
            found = 1;
        }
        idx++;
        P = next(P);
    } while (P != First(L));
    if (!found) printf("0");
    printf("\n");
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L) {
    //kamus lokal
    int max, c;
    address P;
    //algoritma
    max = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            c = CountX(L, info(P));
            if (c > max) max = c;
            P = next(P);
        } while (P != First(L));
    }
    return max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
    //kamus lokal
    char m;
    int max, c;
    address P;
    //algoritma
    if (IsEmptyList(L)) 
        return '#';
    m = info(First(L));
    max = 0;
    P = First(L);
    do {
        c = CountX(L, info(P));
        if (c > max) {
            max = c;
            m = info(P);
        }
        P = next(P);
    } while (P != First(L));
    return m;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    //kamus lokal
    address P, Q;
    //algoritma
    CreateList(L);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
    }
    if (!IsEmptyList(L2)) {
        Q = First(L2);
        do {
            InsertVLast(L, info(Q));
            Q = next(Q);
        } while (Q != First(L2));
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2) {
    //kamus lokal
    int n, mid, i;
    address P;
    //algoritma
    CreateList(L1);
    CreateList(L2);
    n = NbElm(L);
    if (n < 2) return;
    mid = n / 2;
    P = First(L);
    for (i = 1; i <= mid; i++) {
        InsertVLast(L1, info(P));
        P = next(P);
    }
    for (i = mid + 1; i <= n; i++) {
        InsertVLast(L2, info(P));
        P = next(P);
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
    //kamus lokal
    address P;
    //algoritma
    CreateList(L2);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    }
}