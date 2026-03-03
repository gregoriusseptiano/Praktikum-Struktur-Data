/* Program   : tqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah*/
/* NIM/Nama  : 24060124200026 / Gregorius Septiano Ariadi*/
/* Tanggal   : Kamis, 2 Oktober 2025*/
/***********************************/

#include <stdio.h>
#include "boolean.h"
#include "tqueue2.h"



/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q) {
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q) {
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q) {
    if (isEmptyQueue2(Q)) {
        return '-'; 
    }
    return Q.wadah[Q.head];
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */

char infoTail2(tqueue2 Q) {
    if (isEmptyQueue2(Q)) {
        return '-';
    }
    return Q.wadah[Q.tail];
}
/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q) {
    return (Q.head == 0 && Q.tail == 0);
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q) {
    return (Q.head == 1 && Q.tail == 5);
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q) {
    return (Q.head == Q.tail && Q.head != 0);
}

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q) {
    int i;
    (*Q).head = 0;
    (*Q).tail = 0;
    for (i = 1; i <= 5; i++) {
        (*Q).wadah[i] = '#';
    }
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */

int sizeQueue2(tqueue2 Q) {
    if (isEmptyQueue2(Q)) {
        return 0;
    }
    return Q.tail - Q.head + 1;
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q) {
    int i;
    if (isEmptyQueue2(Q)) {
        for (i = 1; i <= 5; i++) {
            printf("# ");
        }
        printf("\n");
    } else {
        for (i = 1; i <= 5; i++) {
            printf("%c ", Q.wadah[i]);
        }
        printf("\n");
    }
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q) {
    if (isEmptyQueue2(Q)) {
        printf("Antrian kosong\n");
    } else {
        int i;
        for (i = Q.head; i <= Q.tail; i++) {
            printf("%c ", Q.wadah[i]);
        }
        printf("\n");
    }
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q) {
    return (Q.tail == 5);
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q) {
    int i, j = 1;
    for (i = (*Q).head; i <= (*Q).tail; i++) {
        (*Q).wadah[j] = (*Q).wadah[i];
        j++;
    }
    (*Q).head = 1;
    (*Q).tail = j - 1;
    for (i = (*Q).tail + 1; i <= 5; i++) {
        (*Q).wadah[i] = '#';
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */

void enqueue2(tqueue2 *Q, char E) {
    if (isFullQueue2(*Q)) {
        printf("Queue penuh, tidak bisa enqueue %c\n", E);
    } else {
        if (isEmptyQueue2(*Q)) {
            (*Q).head = 1;
            (*Q).tail = 1;
            (*Q).wadah[1] = E;
        } else {
            if (isTailStop(*Q)) {
                resetHead(Q);
            }
            (*Q).tail++;
            (*Q).wadah[(*Q).tail] = E;
        }
    }
}

/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E) {
    if (isEmptyQueue2(*Q)) {
        *E = '@';
    } else if (isOneElement2(*Q)) {
        *E = (*Q).wadah[(*Q).head];
        (*Q).wadah[(*Q).head] = '#';
        (*Q).head = 0;
        (*Q).tail = 0;
    } else {
        *E = (*Q).wadah[(*Q).head];
        (*Q).wadah[(*Q).head] = '#';
        (*Q).head++;
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N) {
    char e;
    int i;
    for (i = 1; i <= N; i++) {
        printf("Masukkan elemen ke-%d: ", i);
        scanf(" %c", &e);
        enqueue2(Q, e);
    }
}

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1, tqueue2 Q2) {
    if (sizeQueue2(Q1) != sizeQueue2(Q2)) {
        return false;
    }
    int i, j;
    for (i = Q1.head, j = Q2.head; i <= Q1.tail && j <= Q2.tail; i++, j++) {
        if (Q1.wadah[i] != Q2.wadah[j]) {
            return false;
        }
    }
    return true;
}