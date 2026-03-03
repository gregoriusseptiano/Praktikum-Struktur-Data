/* File : pohon2.c */
/* Deskripsi : realisasi body ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : Gregorius Septiano Ariadi / 24060124120026 */
/* Tanggal : Kamis, 4 Desember 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H) {
    //kamus lokal  
    int i;

    //algoritma
    if (!(IsEmptyTree(P))){
        printf("%c\n", info(P));
        if (!(IsEmptyTree(left(P))) || !(IsEmptyTree(right(P)))){
            for (i = 0; i < H; i++){
            printf(" ");
        }
        PrintTreeInden(left(P), H+3);
        for (i = 0; i < H; i++) {
            printf(" ");
        }
        PrintTreeInden(right(P), H+3);
        }
    } 
    else{
        printf("()\n");
    }
}

// /* procedure PrintLevel(input P:bintree, input N:integer) #sudah ada di pohon1.c, jika tidak di comment akan terjadi duplikasi
// {I.S. L terdefinisi; F.S. :-}
// { menampilkan info semua elemen bintree P pada generasi/level N} */
// void PrintLevel(bintree P, int N) {
//     //kamus lokal

//     //algoritma
//     if (P != NIL) {
//         if (N == 1) {
//             printf("%c ", info(P));
//         } else {
//             PrintLevel(left(P), N - 1);
//             PrintLevel(right(P), N - 1);
//         }
//     }
// }

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y) {
    //kamus lokal

    //algoritma
    if (*P != NIL) {
        if (info(*P) == X) {
            info(*P) = Y;
        }
        UpdateAllX(&left(*P), X, Y);
        UpdateAllX(&right(*P), X, Y);
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X) {
    //kamus lokal
    bintree curr, newNode;

    //algoritma
    if (*P == NIL) {
        *P = AlokasiTree(X);
    } else {
        curr = *P;
        while (left(curr) != NIL) {
            curr = left(curr);
        }
        newNode = AlokasiTree(X);
        if (newNode != NIL) {
            left(curr) = newNode;
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri) {
    //kamus lokal

    //algoritma
    if (*P != NIL) {
        if (info(*P) == X && IsDaun(*P)) {
            if (Kiri) {
                left(*P) = AlokasiTree(Y);
            } else {
                right(*P) = AlokasiTree(Y);
            }
        } else {
            AddDaun(&left(*P), X, Y, Kiri);
            AddDaun(&right(*P), X, Y, Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
    //kamus lokal

    //algoritma
    if (*P == NIL) {
        *P = AlokasiTree(X);
    } else {
        if (X != info(*P)) {
            if (X < info(*P)) {
                InsertX(&left(*P), X);
            } else {
                InsertX(&right(*P), X);
            }
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype X) {
    //kamus lokal
    bintree curr, parent;

    //algoritma
    if (*P != NIL) {
        parent = NIL;
        curr = *P;
        while (left(curr) != NIL) {
            parent = curr;
            curr = left(curr);
        } 
        if (parent == NIL) {
            *P = right(curr);
            free(curr);
        } else {
            left(parent) = right(curr);
            free(curr);
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
    //kamus lokal

    //algoritma
    if (*P != NIL) {
        if (info(*P) == X && IsDaun(*P)) {
            free(*P);
            *P = NIL;
        } else {
            DelDaun(&left(*P), X);
            DelDaun(&right(*P), X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X) {
    //kamus lokal
    infotype old;

    //algoritma
    if (*P != NIL) {
        if (info(*P) == X) {
            if (IsDaun(*P)) {
                free(*P);
                *P = NIL;
            } else if (left(*P) != NIL) {
                old = info(left(*P));
                info(*P) = old;
                DeleteX(&left(*P), old);
            } else {
                old = info(right(*P));
                info(*P) = old;
                DeleteX(&right(*P), old);
            }
        } else {
            DeleteX(&left(*P), X);
            DeleteX(&right(*P), X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
    //kamus lokal
    bintree P;
    int mid;
    infotype X;

    //algoritma
    if (n == 0) {
        return NIL;
    }

    mid = n / 2;
    P = AlokasiTree('#');

    if (P == NIL) {
        return NIL;
    }

    left(P) = BuildBalanceTree(mid);

    printf("Masukkan nilai node: ");
    scanf(" %c", &X);
    info(P) = X;

    right(P) = BuildBalanceTree(n - mid - 1);

    return P;
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
    //kamus lokal
    int L, R;

    //algoritma
    if (P == NIL) {
        return True;
    }

    L = NbElm(left(P));
    R = NbElm(right(P));
    
    if (L - R <= 1 && R - L <= 1) {
        return True;
    } else {
        return False; 
    }
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P) {
    //kamus lokal
    int L, R, m;

    //algoritma
    if (P == NIL) {
        return -999;
    }
    L = maxTree(left(P));
    R = maxTree(right(P));
    m = info(P);

    if (L > m) m = L;
    if (R > m) m = R;

    return m;
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P) {
    //kamus lokal
    int L, R, m;

    //algoritma
    if (P == NIL) {
        return 999;
    }
    L = minTree(left(P));
    R = minTree(right(P));
    m = info(P);
    
    if (L < m) m = L;
    if (R < m) m = R;

    return m;
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return False;
    }
    if (info(P) == X) {
        return True;
    } else if (X < info(P)) {
        return BSearch(left(P), X);
    } else {
        return BSearch(right(P), X);
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return AlokasiTree(X);
    }

    if (X == info(P)) {
        return P;
    }

    if (X < info(P)) {
        left(P) = InsSearch(left(P), X);
    } else {
        right(P) = InsSearch(right(P), X);
    }

    return P;
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X) {
    //kamus lokal
    bintree temp;

    //algoritma
    if (*P != NIL) {
        if (X < info(*P)) {
            DelBtree(&left(*P), X);
        } else if (X > info(*P)) {
            DelBtree(&right(*P), X);
        } else {
            if (left(*P) == NIL && right(*P) == NIL) {
                free(*P);
                *P = NIL;
            } else if (left(*P) == NIL) {
                temp = *P;
                *P = right(*P);
                free(temp);
            } else if (right(*P) == NIL) {
                temp = *P;
                *P = left(*P);
                free(temp);
            } else {
                temp = right(*P);
                while (left(temp) != NIL) {
                    temp = left(temp);
                }
                info(*P) = info(temp);
                DelBtree(&right(*P), info(temp));
            }
        }
    }
}