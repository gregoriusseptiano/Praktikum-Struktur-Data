/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : Gregorius Septiano Ariadi / 24060124120026 */
/* Tanggal : Kamis, 4 Desember 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"

int main() {
    //kamus lokal
    bintree P, L, R;
    infotype X, Y;
    int n;

    //algoritma
    printf("=== PENGUJIAN ADT BINTREE LANJUTAN ===\n\n");

    /* 1. Membuat pohon awal */
    L = AlokasiTree('B');
    R = AlokasiTree('C');
    P = Tree('A', L, R);
    left(L) = AlokasiTree('D');
    right(L) = AlokasiTree('E');

    printf("Pohon awal (PrintTreeInden):\n");
    PrintTreeInden(P, 0);
    printf("\n");

    /* 2. PrintLevel */
    printf("PrintLevel level 2: ");
    PrintLevel(P, 2);
    printf("\n\n");

    /* 3. UpdateAllX */
    printf("UpdateAllX: Ubah 'E' menjadi 'X'\n");
    UpdateAllX(&P, 'E', 'X');
    PrintTreeInden(P, 0);
    printf("\n");

    /* 4. AddDaunTerkiri */
    printf("AddDaunTerkiri('Z')\n");
    AddDaunTerkiri(&P, 'Z');
    PrintTreeInden(P, 0);
    printf("\n");

    /* 5. AddDaun */
    printf("AddDaun: tambah anak kiri 'C' dengan 'Q'\n");
    AddDaun(&P, 'C', 'Q', True);
    PrintTreeInden(P, 0);
    printf("\n");

    /* 6. InsertX (BST) */
    printf("InsertX('M') sebagai BST Insert\n");
    InsertX(&P, 'M');
    PrintTreeInden(P, 0);
    printf("\n");

    /* 7. DelDaunTerkiri */
    printf("DelDaunTerkiri\n");
    DelDaunTerkiri(&P, 'Z'); 
    PrintTreeInden(P, 0);
    printf("\n");

    /* 8. DelDaun */
    printf("DelDaun('Q')\n");
    DelDaun(&P, 'Q');
    PrintTreeInden(P, 0);
    printf("\n");

    /* 9. DeleteX */
    printf("DeleteX('B')\n");
    DeleteX(&P, 'B');
    PrintTreeInden(P, 0);
    printf("\n");

    /* 10. BuildBalanceTree */
    printf("BuildBalanceTree dengan n = 3\n");
    n = 3;
    bintree T = BuildBalanceTree(n);
    printf("Tree hasil BuildBalanceTree:\n");
    PrintTreeInden(T, 0);
    printf("\n");

    /* 11. IsBalanceTree */
    printf("IsBalanceTree(P) = %d\n", IsBalanceTree(P));
    printf("IsBalanceTree(T) = %d\n\n", IsBalanceTree(T));

    /* 12. maxTree dan minTree */
    printf("maxTree(P) = %c\n", maxTree(P));
    printf("minTree(P) = %c\n\n", minTree(P));

    /* 13. BSearch */
    printf("BSearch(P, 'A') = %d\n", BSearch(P, 'A'));
    printf("BSearch(P, 'Z') = %d\n\n", BSearch(P, 'Z'));

    /* 14. InsSearch */
    printf("InsSearch(P, 'H')\n");
    P = InsSearch(P, 'H');
    PrintTreeInden(P, 0);
    printf("\n");

    /* 15. DelBtree */
    printf("DelBtree(P, 'H')\n");
    DelBtree(&P, 'H');
    PrintTreeInden(P, 0);
    printf("\n");

    printf("=== SELESAI ===\n");
    return 0;
}
