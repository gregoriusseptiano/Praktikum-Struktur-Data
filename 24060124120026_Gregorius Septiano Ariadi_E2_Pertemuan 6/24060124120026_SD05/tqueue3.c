/* Program   : tqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060124120026 / Gregorius Septiano Ariadi*/
/* Tanggal   : Kamis, 9 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "boolean.h"
#include "tqueue3.h"

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q) {
    return (head3(Q) == 0 && tail3(Q) == 0);
}
 
/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q) {
    if (isEmptyQueue3(Q)) {
        return false;
    } else {
        return ((tail3(Q) % 5) + 1 == head3(Q));
    }
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q) {
    return (head3(Q) == tail3(Q) && head3(Q) != 0);
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q) {
    // kamus lokal
    int i;

    // algoritma
    for (i = 1; i <= 5; i++) {
        (*Q).wadah[i] = '#';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q) {
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q) {
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q) {
    if (!isEmptyQueue3(Q)) {
        return Q.wadah[head3(Q)];
    } else {
        printf("Queue kosong!\n");
        return '#';
    }
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q) {
    if (!isEmptyQueue3(Q)) {
        return Q.wadah[tail3(Q)];
    } else {
        printf("Queue kosong!\n");
        return '#';
    }
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q) {
    if (isEmptyQueue3(Q))
        return 0;
    else if (isTailOverHead(Q))
        return (5 - head3(Q) + 1) + tail3(Q);
    else
        return (tail3(Q) - head3(Q) + 1);
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q) {
    // kamus lokal
    int i;

    // algoritma
    printf("[");
    for (i = 1; i <= 5; i++) {
        printf("%c", Q.wadah[i]);
        if (i < 5) printf(" ");
    }
    printf("]\n");
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q) {
    if (isEmptyQueue3(Q)) {
        printf("Queue kosong\n");
    } else {
        int i = head3(Q);
        while (i != tail3(Q)) {
            printf("%c ", Q.wadah[i]);
            i = (i % 5) + 1;   
        }
        printf("%c\n", Q.wadah[i]);
    }
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E) {
    if (isFullQueue3(*Q)) {
        printf("Queue penuh, tidak bisa enqueue '%c'\n", E);
    } else {
        if (isEmptyQueue3(*Q)) {
            (*Q).head = 1;
            (*Q).tail = 1;
        } else {
            (*Q).tail = (tail3(*Q) % 5) + 1;
        }
        (*Q).wadah[tail3(*Q)] = E;
    }
}

/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */

void dequeue3(tqueue3 *Q, char *E) {
    if (isEmptyQueue3(*Q)) {
        *E = ' ';
        printf("Queue kosong, tidak bisa dequeue\n");
    } else {
        *E = (*Q).wadah[head3(*Q)];
        (*Q).wadah[head3(*Q)] = '#';
        if (isOneElement3(*Q)) {
            (*Q).head = 0;
            (*Q).tail = 0;
        } else {
            (*Q).head = (head3(*Q) % 5) + 1;
        }
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q) {
        return (tail3(Q) < head3(Q));
}