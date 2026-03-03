/* File : pohon1.c */
/* Deskripsi : realisasi body ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : Gregorius Septiano Ariadi / 24060124120026 */
/* Tanggal : Kamis, 27 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function AlokasiTree( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree AlokasiTree(infotype E) {
    //kamus lokal
    bintree P;
    //algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}
 
/* procedure DealokasiTree (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void DealokasiTree(bintree *P) {
    //kamus lokal

    //algoritma
    if (*P != NIL) {
        free(*P);
        *P = NIL;
    }
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
/*representasi logik fungsi*/
bintree Tree (infotype akar, bintree left, bintree right) {
    //kamus lokal
    bintree P;
    //algoritma
    P = AlokasiTree(akar);
    if (P != NIL) {
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
    //kamus lokal
    
    //algoritma
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P) {
    //kamus lokal

    //algoritma
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan True bila bintree L kosong} */
boolean IsEmptyTree(bintree P) {
    //kamus lokal

    //algoritma
    return (P == NIL);
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan True jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P) {
    //kamus lokal

    //algoritma
    if (P != NIL && left(P) == NIL && right(P) == NIL) {
        return True;
    } else {
        return False;
    }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan True jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P) {
    //kamus lokal

    //algoritma
    if (P != NIL && left(P) != NIL && right(P) != NIL) {
        return True;
    } else {
        return False;
    }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan True jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P) {
    //kamus lokal

    //algoritma
    if (P != NIL && left(P) != NIL && right(P) == NIL) {
        return True;
    } else {
        return False;
    }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan True jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P) {
    //kamus lokal

    //algoritma
    if (P != NIL && left(P) == NIL && right(P) != NIL) {
        return True;
    } else {
        return False;
    }
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
    //kamus lokal
    
    //algoritma 
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c(",info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return 0;
    } else {
        return 1 + NbElm(left(P)) + NbElm(right(P));
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return 0;
    }
    if (IsDaun(P)) {
        return 1;
    }
    return NbDaun(left(P)) + NbDaun(right(P));
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
    //kamus lokal

    //algoritma
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return -1;
    } else {
        return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan True jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return False;
    }
    if (info(P) == X) {
        return True;
    }
    return SearchX(left(P), X) || SearchX(right(P), X);
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y) {
    //kamus lokal

    //algoritma
    if (*P != NIL) {
        if (info(*P) == X) {
            info(*P) = Y;
        }
        UpdateX(&left(*P), X, Y);
        UpdateX(&right(*P), X, Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return 0;
    }
    if (info(P) == X) {
        return 1 + CountX(left(P), X) + CountX(right(P), X);
    } else {
        return CountX(left(P), X) + CountX(right(P), X);
    }
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim True jika P adalah pohon condong kiri } */
boolean IsSkewLeft(bintree P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return True;
    }
    if (right(P) != NIL) {
        return False;
    }
    return IsSkewLeft(left(P));
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim True jika P adalah pohon condong kanan }*/
boolean IsSkewRight(bintree P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return True;
    }
    if (left(P) != NIL) {
        return False;
    }   
    return IsSkewRight(right(P));
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return;
    }
    printf("%c", info(P));
    if (left(P) != NIL || right(P) != NIL) {
        printf("(");
        PrintPrefixRingkas(left(P));
        if (right(P) != NIL) {
            printf(",");
            PrintPrefixRingkas(right(P));
        }
        printf(")");
    }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
    //kamus lokal
    int level;
    //algoritma
    if (P == NIL) {
        return 0;
    }
    if (info(P) == X) {
        return 1;
    }
    level = LevelX(left(P), X);
    if (level != 0) {
        return level + 1;
    }
    level = LevelX(right(P), X);
    if (level != 0) {
        return level + 1;
    }
    return 0;
}

/*function CountLevel(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return 0;
    }
    if (T == 1) {
        return 1;
    }
    return CountLevel(left(P), T - 1) + CountLevel(right(P), T - 1);
}

/*procedure PrintLevel( input P:bintree, input N: integer )
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree P, int N) {
    //kamus lokal

    //algoritma
    if (P != NIL) {
        if (N == 1) {
            printf("%c ", info(P));
        } else {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
} 

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return '#';
    }
    if (IsDaun(P)) {
        return info(P);
    }
    if (left(P) != NIL) {
        return GetDaunTerkiri(left(P));
    }
    return GetDaunTerkiri(right(P));
}

/*function FrekuensiX(P:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree P }*/
float FrekuensiX(bintree P, infotype X) {
    //kamus lokal

    //algoritma
    if (NbElm(P) == 0) {
        return 0;
    }
    return (float) CountX(P, X) / NbElm(P);
}

/*function CountVocal(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree P}*/
int CountVocal(bintree P) {
    //kamus lokal
    char c;
    //algoritma
    if (P == NIL) {
        return 0;
    }
    c = info(P);
    if (c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O' ||
        c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
        return 1 + CountVocal(left(P)) + CountVocal(right(P));
    }
    return CountVocal(left(P)) + CountVocal(right(P));
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P) {
    //kamus lokal
    char c;
    //algoritma
    if (P != NIL) {
        c = info(P);
        if (c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O' ||
            c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
            printf("%c ", c);
        }
        PrintVocal(left(P));
        PrintVocal(right(P));
    }
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree L}*/
int CountConsonant(bintree P) {
    //kamus lokal
    char c;
    //algoritma
    if (P == NIL) {
        return 0;
    }
    c = info(P);
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        if (!(c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O' ||
              c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')) {
            return 1 + CountConsonant(left(P)) + CountConsonant(right(P));
        }
    }
    return CountConsonant(left(P)) + CountConsonant(right(P));
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P) {
    //kamus lokal
    char c;
    //algoritma
    if (P != NIL) {
        c = info(P);
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (!(c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O' ||
                  c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')) {
                printf("%c ", c);
            }
        }
        PrintConsonant(left(P));
        PrintConsonant(right(P));
    }
}

/*function Modus(P:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P) {
    //kamus lokal
    static int freq[256];
    static int depth;
    int i;
    int max;
    char modus;
    //algoritma
    if (depth == 0) {
        for (i = 0; i < 256; i++) {
            freq[i] = 0;
        }
    }
    if (P != NIL) {
        depth++;
        freq[(unsigned char) info(P)]++;
        Modus(left(P));
        Modus(right(P));
        depth--;
    }
    if (depth == 0) {
        max = 0;             
        modus = '#';
        for (i = 0; i < 256; i++) {
            if (freq[i] > max) {
                max = freq[i];
                modus = (char) i;
            }
        }
        return modus;
    }
    return '#';
}