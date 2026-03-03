/* File : pohon3.c */
/* Deskripsi : realisasi body ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124120026 / Gregorius Septiano Ariadi */
/* Tanggal : Kamis, 11 Desember 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"

/************************ PROTOTYPE ************************/
/********** PEMBUATAN POHON BARU ***********/
/* function Tree3 (A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan) {
    // kamus lokal
    bintree3 P;

    // algoritma
    P = (bintree3) malloc(sizeof(node3));

    if (P != NIL) {
        parent(P) = A;
        info(P) = X;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
        return P;
    } else {
        return NIL;
    }
}

/* penelusuran */
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P) {
    // kamus lokal

    // algoritma 
    if (!IsEmptyTree(P)) {
        printf("%c(", info(P));
        printDFS(left(P));
        printf(",");
        printDFS(right(P));
        printf(")");
    } else {
        printf("( )");
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2 (int a, int b){
    // kamus lokal

    // algoritma
    if (a > b) 
        return a;
    else 
        return b;
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree3 P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (IsDaun(P)) {  // jika P = daun
      return 0;
    } else {  // jika P != daun
      return 1 + Max2(Tinggi(left(P)), Tinggi(right(P)));
    }
  } else {  // jika kosong
    return 0;
  }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree3 P, int N) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P) && N > 0) { // jika tidak kosong dan N > 0
    if (N == 1) {
      printf("%c ", info(P));
    } else {
      PrintLevel(left(P), N - 1);
      PrintLevel(right(P), N - 1);
    }
  }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS (bintree3 P) {
    // kamus lokal
    int i;

    // algoritma 
    for (i = 1; i <= Tinggi(P) + 1; i++) {
        PrintLevel(P, i);
    }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P) {
   // kamus lokal

   // algoritma
   return P == NIL;
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun (bintree3 P) {
   // kamus lokal

   // algoritma
   if (!IsEmptyTree(P)) {
      return left(P) == NIL && right(P) == NIL;
   } else {
      return False;
   }
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner (bintree3 P) {
   // kamus lokal

   // algoritma
   return left(P) != NIL && right(P) != NIL;
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft (bintree3 P) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P)) {
        if (left(P) != NIL && right(P) == NIL) {
            return True;
        } else {
            return False;
        }
    } return False;
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight (bintree3 P) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P)) {
        if (left(P) == NIL && right(P) != NIL) {
            return True;
        } else {
            return False;
        }
    } return False;
}

/*PENELUSURAN*/
/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 P) {
    // kamus lokal
    
    // algoritma
    if (P != NIL) {
        visited(P) = False;
        resetVisited(left(P));
        resetVisited(right(P));
    }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X) {
   // kamus lokal

   // algoritma
   if (!(IsEmptyTree(P))){
      if (!(visited(P))){
         visited(P) = True;
         printPathX(left(P), X);
         printPathX(right(P), X);
         resetVisited(P);
      }
      else{
         printPathX(parent(P), X);
         printf("%c ", info(P));
      }
      if (info(P) == X){
         printPathX(parent(P), X);
         printf("%c ", info(P));
      }
   }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX (bintree3 P, infotype X) {
   // kamus lokal
   bintree3 temp;

   // algoritma
   if (!IsEmptyTree(P)) {  // jika tidak kosong
      if (info(P) == X && IsDaun(P)) { // jika ketemu
         temp = P;
         visited(temp) = True;

         while (parent(temp) != NIL) {
            visited(parent(temp)) = True;
            temp = parent(temp);
         }

         do {
            printf("%c ", info(temp));

            if (left(temp) != NIL && visited(left(temp))) {
               temp = left(temp);
            } else if (right(temp) != NIL && visited(right(temp))) {
               temp = right(temp);
            } else {
               temp = NIL;
            }
         } while (temp != NIL);

         resetVisited(P);
      } else { // jika blm ketemu
         printPathDaunX(left(P), X);
         printPathDaunX(right(P), X);
      }
   }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths (bintree3 P) {
   // kamus lokal
   bintree3 temp;

   // algoritma
   if (!IsEmptyTree(P)) {  // jika tidak kosong
      if (IsDaun(P)) { // jika ketemu
         printf("\n");

         temp = P;
         visited(temp) = True;

         while (parent(temp) != NIL) {
            visited(parent(temp)) = True;
            temp = parent(temp);
         }

         do {
            printf("%c ", info(temp));

            if (left(temp) != NIL && visited(left(temp))) {
               temp = left(temp);
            } else if (right(temp) != NIL && visited(right(temp))) {
               temp = right(temp);
            } else {
               temp = NIL;
            }
         } while (temp != NIL);

      } else { // jika blm ketemu
         printAllPaths(left(P));
         printAllPaths(right(P));
      }
   }
   resetVisited(P);
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree (bintree3 P) {
   // kamus lokal

   // algoritma
   if (!IsEmptyTree(P)) {  // jika tidak kosong
      if (IsDaun(P)) {  // jika daun
         return 1;
      } else { // jika tidak daun
         return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
      }
   } else { // jika kosong
      return 0;
   }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun (bintree3 P) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P)) {
        if (IsDaun(P)) {
            return 1;
        } else {
            return NbDaun(left(P)) + NbDaun(right(P));
        }
    } else {
        return 0;
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level (bintree3 P) {
   // kamus lokal

   // algoritma
   if (!IsEmptyTree(P)) {  // jika tidak kosong
      if (IsDaun(P)) {  // jika daun
         return 1;
      } else { // jika bukan daun
         return 1 + Max2(Level(left(P)), Level(right(P)));
      }
   } else { // jika kosong
      return 0;
   }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT (bintree3 P, int T) {
   // kamus lokal

   // algoritma
   if (T > 0 && !IsEmptyTree(P)) {  // jika T > 0 dan tidak kosong
      if (T == 1) {  // jika T = 1
         return 1;
      } else { // jika T > 1
         return CountLevelT(left(P), T - 1) + CountLevelT(right(P), T - 1);
      }
   } else { // jika T <= 0 atau pohon kosong
      return 0;
   }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
//printList sudah ADA di list1.h

/*procedure Pconcat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat (List1 *Asli, List1 Tambahan) {
   // kamus lokal
   address P;

   // algoritma
   if (!IsEmptyList(*Asli) && !IsEmptyList(Tambahan)) { // jika list Asli dan Tambahan tidak kosong
      P = First(*Asli); // mulai dari elemen pertama

      while (next(P) != NIL) {
         P = next(P);
      }  // end while jika next(P) = NIL

      next(P) = First(Tambahan);
   } else if (IsEmptyList(*Asli) && !IsEmptyList(Tambahan)) {  // jika list Asli kosong dan Tambahan tidak kosong
      First(*Asli) = First(Tambahan);
   }
}

/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan) {
   // kamus lokal
   List1 LNew;
   address P;

   // algoritma
   CreateList(&LNew);

   // salin list Asli
   P = First(Asli);
   while (P != NIL) {
      InsertVLast(&LNew, info(P));
      P = next(P);
   }

   // salin list Tambahan
   P = First(Tambahan);
   while (P != NIL) {
      InsertVLast(&LNew, info(P));
      P = next(P);
   }

   return LNew;
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix (bintree3 P) {
   // kamus lokal
   List1 LPrefix, Lleft, Lright;

   // algoritma
   CreateList(&LPrefix);

   if (!IsEmptyTree(P)) {  // jika tidak kosong
      InsertVLast(&LPrefix, info(P));  // akar

      Lleft = LinearPrefix(left(P));
      Lright = LinearPrefix(right(P));

      // gabungkan akar, kiri, dan kanan
      LPrefix = Fconcat(LPrefix, Lleft);
      LPrefix = Fconcat(LPrefix, Lright);
   }

   return LPrefix;
}

/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix (bintree3 P) { 
   // kamus lokal 
   List1 LPosfix, Lleft, Lright; 

   // algoritma 
   CreateList(&LPosfix); 
   if (!IsEmptyTree(P)) { 
      Lleft = LinearPosfix(left(P)); 
      Lright = LinearPosfix(right(P)); 
      
      // gabungkan kiri dan kanan 
      LPosfix = Fconcat(LPosfix, Lleft); 
      LPosfix = Fconcat(LPosfix, Lright); 
      
      // insert akar 
      InsertVLast(&LPosfix, info(P)); 
   } 
   
   return LPosfix; 
}

/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix (bintree3 P) {
   // kamus lokal
   List1 LInfix, Lleft, Lright;

   // algoritma
   CreateList(&LInfix);

   if (!IsEmptyTree(P)) {
      Lleft = LinearInfix(left(P));
      Lright = LinearInfix(right(P));

      // gabungkan kiri dan akar
      LInfix = Fconcat(LInfix, Lleft);
      InsertVLast(&LInfix, info(P));

      // gabungkan dengan kanan
      LInfix = Fconcat(LInfix, Lright);
   }

   return LInfix;
}

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS(bintree3 P) {
    /* lamus lokal */
    List1 L;
    bintree3 queue[1000];
    int head;
    int tail;
    bintree3 X;

    /* algoritma */
    CreateList(&L);
    if (IsEmptyTree(P)) {
        return L;
    }
    head = 0;
    tail = 0;
    queue[tail] = P;
    tail++;

    while (head < tail) {
        X = queue[head];
        head++;
        InsertVLast(&L, info(X));
        if (left(X) != NIL) {
            queue[tail] = left(X);
            tail++;
        }
        if (right(X) != NIL) {
            queue[tail] = right(X);
            tail++;
        }
    }

    return L;
}