# Praktikum dan Tugas Struktur Data

Repositori ini berisi kumpulan modul praktikum dan tugas mata kuliah **Struktur Data** pada Semester 3. Semua implementasi struktur data abstrak (Abstract Data Type / ADT) dalam repositori ini ditulis menggunakan bahasa pemrograman **C**.

## 📂 Struktur Repositori

Materi praktikum dibagi menjadi beberapa folder direktori (SD01 - SD12) yang berurutan sesuai dengan topik modul praktikum, beserta folder khusus untuk tugas kelas:

*   **[SD01](./SD01) - ADT Titik (Point):** Implementasi tipe bentukan titik dalam koordinat kartesian beserta operasi-operasi primitifnya.
*   **[SD02](./SD02) - ADT Tabel (Array):** Implementasi struktur data tabel/array statis secara kontigu beserta operasinya.
*   **[SD03](./SD03) - ADT Matriks:** Implementasi struktur data matriks (baris dan kolom) beserta operasinya (penjumlahan, perkalian, transpose, dll).
*   **[SD04](./SD04) - ADT Stack:** Implementasi struktur data Tumpukan (*Stack*) menggunakan array dengan prinsip LIFO (*Last In, First Out*).
*   **[SD05](./SD05) - ADT Queue 1 & 2:** Implementasi dasar struktur data Antrean (*Queue*) berprinsip FIFO (*First In, First Out*).
*   **[SD06](./SD06) - ADT Queue 3 (Studi Kasus Puskesmas):** Implementasi lanjutan *Queue* dan aplikasinya pada kasus antrean pasien Puskesmas.
*   **[SD07](./SD07) - List Linier 1:** Implementasi *Singly Linked List* menggunakan representasi pointer.
*   **[SD08](./SD08) - List Linier 2:** Implementasi *Doubly / Circular Linked List*.
*   **[SD09](./SD09) - List Linier 3:** Implementasi variasi dan operasi tingkat lanjut pada *Linked List*.
*   **[SD10](./SD10) - Pohon 1 (Tree):** Dasar-dasar implementasi struktur data Pohon Biner (*Binary Tree*).
*   **[SD11](./SD11) - Pohon 2:** Lanjutan implementasi struktur data pohon, seperti *Binary Search Tree* (BST).
*   **[SD12](./SD12) - Pohon 3:** Implementasi pohon kompleks (*N-ary tree* atau operasi pohon lanjutan).
*   **[Tugas Struktur Data Kelas E](./Tugas%20Struktur%20Data%20Kelas%20E):** Kumpulan *project* atau tugas khusus untuk kelas E (termasuk program Queue dan Laporannya).

---

## 🛠️ Prasyarat dan Cara Menjalankan

Program-program dalam repositori ini dibangun secara modular menggunakan bahasa C (terdiri dari file header `.h`, implementasi `.c`, dan file *driver/main* `.c`).

Pastikan sistem operasi Anda sudah memiliki kompiler C (seperti **GCC** / **MinGW**) yang terkonfigurasi pada *environment variables* Anda.

### Langkah-langkah kompilasi:

1. Buka terminal atau *command prompt*.
2. Arahkan *working directory* ke modul yang ingin dijalankan (contoh: modul `SD01`).
   ```bash
   cd SD01
   ```
3. Lakukan kompilasi dengan menyertakan file utama (`main`) dan file implementasinya.
   ```bash
   gcc maintitik.c titik.c -o main.exe
   ```
4. Jalankan program hasil kompilasi.
   ```bash
   ./main.exe
   ```
   *(Catatan: Sesuaikan nama file driver `.c` yang dijalankan, misalnya `maintabel.c` pada SD02, dll.)*
