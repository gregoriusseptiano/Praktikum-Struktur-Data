/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : Gregorius Septiano Ariadi / 24060124120026 */
/* Tanggal : Kamis, 27 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"

int main() {
    // kamus lokal
    bintree P;
    bintree L, R;

    // algoritma
    printf("=== PENGUJIAN ADT BINTREE ===\n\n");
    // 1. AlokasiTree dan Tree
    L = AlokasiTree('B');
    R = AlokasiTree('C');
    P = Tree('A', L, R);
    printf("Pohon awal (PrintPrefix): ");
    PrintPrefix(P);
    printf("\n\n");

    // 2. GetLeft dan GetRight
    printf("Akar kiri : %c\n", info(GetLeft(P)));
    printf("Akar kanan : %c\n\n", info(GetRight(P)));

    // 3. Predikat
    printf("IsEmptyTree : %d\n", IsEmptyTree(P));
    printf("IsDaun A : %d\n", IsDaun(P));
    printf("IsBiner A : %d\n", IsBiner(P));
    printf("IsUnerLeft : %d\n", IsUnerLeft(P));
    printf("IsUnerRight : %d\n\n", IsUnerRight(P));

    // 4. NbElm dan NbDaun
    printf("Jumlah elemen : %d\n", NbElm(P));
    printf("Jumlah daun : %d\n\n", NbDaun(P));

    // 5. Tinggi
    printf("Tinggi pohon : %d\n\n", Tinggi(P));

    // 6. SearchX dan UpdateX
    printf("Cari node 'B' : %d\n", SearchX(P, 'B'));
    printf("Ubah 'B' menjadi 'D'\n");
    UpdateX(&P, 'B', 'D');
    PrintPrefix(P);
    printf("\n\n");

    // 7. CountX
    printf("Jumlah node 'D' : %d\n\n", CountX(P, 'D'));

    // 8. IsSkewLeft dan IsSkewRight
    printf("IsSkewLeft : %d\n", IsSkewLeft(P));
    printf("IsSkewRight : %d\n\n", IsSkewRight(P));

    // 9. PrintPrefixRingkas
    printf("Prefix ringkas : ");
    PrintPrefixRingkas(P);
    printf("\n\n");

    // 10. LevelX dan CountLevel
    printf("Level node 'D' : %d\n", LevelX(P, 'D'));
    printf("Jumlah level 2 : %d\n\n", CountLevel(P, 2));

    // 11. PrintLevel
    printf("Node level 2 : ");
    PrintLevel(P, 2);
    printf("\n\n");

    // 12. GetDaunTerkiri
    printf("Daun terkiri : %c\n\n", GetDaunTerkiri(P));

    // 13. FrekuensiX
    printf("Frekuensi 'A' : %.2f\n\n", FrekuensiX(P, 'A'));

    // 14. CountVocal dan PrintVocal
    printf("Jumlah vokal : %d\n", CountVocal(P));
    printf("Huruf vokal : ");
    PrintVocal(P);
    printf("\n\n");

    // 15. CountConsonant dan PrintConsonant
    printf("Jumlah konsonan : %d\n", CountConsonant(P));
    printf("Huruf konsonan : ");
    PrintConsonant(P);
    printf("\n\n");

    // 16. Modus
    printf("Modus huruf : %c\n\n", Modus(P));

    // 17. DealokasiTree
    DealokasiTree(&P);
    printf("Tree sudah didealokasi.\n");


    printf("\n=== SELESAI ===\n");
    return 0;
}