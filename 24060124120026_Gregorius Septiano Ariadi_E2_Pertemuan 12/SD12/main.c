/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : Gregorius Septiano Ariadi / 24060124120026 */
/* Tanggal : Kamis, 11 Desember 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"
#include "list1.h"

int main() {
    // Kamus lokal
    bintree3 A, B, C, D, E, F;
    List1 L1, L2, L3, Lbaru, Lbfs;

    // algoritma
    printf("=== UJI ADT BINTREE3 ===\n\n");

    D = Tree3(NIL, 'D', False, NIL, NIL);
    E = Tree3(NIL, 'E', False, NIL, NIL);
    B = Tree3(NIL, 'B', False, D, E);
    parent(D) = B;
    parent(E) = B;

    F = Tree3(NIL, 'F', False, NIL, NIL);
    C = Tree3(NIL, 'C', False, NIL, F);
    parent(F) = C;

    A = Tree3(NIL, 'A', False, B, C);
    parent(B) = A;
    parent(C) = A;

    printf("1. printDFS: ");
    printDFS(A);
    printf("\n\n");

    printf("2. IsEmptyTree A: %d\n", IsEmptyTree(A));
    printf("3. IsDaun D: %d\n", IsDaun(D));
    printf("4. IsBiner A: %d\n", IsBiner(A));
    printf("5. IsUnerLeft C: %d\n", IsUnerLeft(C));
    printf("6. IsUnerRight C: %d\n\n", IsUnerRight(C));

    printf("7. Tinggi: %d\n", Tinggi(A));
    printf("8. Level: %d\n", Level(A));
    printf("9. Jumlah elemen tree: %d\n", NbElmTree(A));
    printf("10. Jumlah daun: %d\n\n", NbDaun(A));

    printf("11. PrintLevel level 2: ");
    PrintLevel(A, 2);
    printf("\n\n");

    printf("12. PrintBFS: ");
    PrintBFS(A);
    printf("\n\n");

    printf("13. printPathX ke E: ");
    printPathX(A, 'E');
    printf("\n\n");

    printf("14. printPathDaunX ke F: ");
    printPathDaunX(A, 'F');
    printf("\n\n");

    printf("15. printAllPaths:");
    printAllPaths(A);
    printf("\n\n");

    printf("16. CountLevelT level 2: %d\n\n", CountLevelT(A, 2));

    printf("17. LinearPrefix: ");
    L1 = LinearPrefix(A);
    PrintList(L1);
    printf("\n\n");

    printf("18. LinearInfix: ");
    L2 = LinearInfix(A);
    PrintList(L2);
    printf("\n\n");

    printf("19. LinearPosfix: ");
    L3 = LinearPosfix(A);
    PrintList(L3);
    printf("\n\n");

    printf("20. Pconcat L1 + L2: ");
    Pconcat(&L1, L2);
    PrintList(L1);
    printf("\n\n");

    printf("21. Fconcat L2 + L3: ");
    Lbaru = Fconcat(L2, L3);
    PrintList(Lbaru);
    printf("\n\n");

    printf("22. LinearBreadthFS: ");
    Lbfs = LinearBreadthFS(A);
    PrintList(Lbfs);
    printf("\n\n");

    resetVisited(A);

    printf("=== SELESAI ===\n");
    return 0;

}
