#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// =========================================================
// 1. DEKLARASI TIPE DATA (STRUCTS & POINTER FUNGSI)
// =========================================================

typedef void (*TampilkanInfoFunc)(void*);

// Struktur dasar Kendaraan (Parent Class)
typedef struct {
    char merek[50];
    char model[50];
    int jumlahRoda;
    TampilkanInfoFunc tampilkanInfo; 
} Kendaraan;

// Struktur Roda Dua (Child Class)
typedef struct {
    Kendaraan super; 
    char tipe[50];   
} RodaDua;

// Struktur Roda Empat (Child Class)
typedef struct {
    Kendaraan super; 
    char segmen[50]; 
} RodaEmpat;

// Struktur Roda Enam (Child Class)
typedef struct {
    Kendaraan super; 
    char fungsi[50]; 
} RodaEnam;


// =========================================================
// 2. DEKLARASI FUNGSI (METHOD & CONSTRUCTOR)
// =========================================================

// Deklarasi Method (Fungsi tampilan spesifik)
void tampilkanInfo_RodaDua(void* obj);
void tampilkanInfo_RodaEmpat(void* obj);
void tampilkanInfo_RodaEnam(void* obj);

// Deklarasi Constructor (Fungsi inisialisasi)
void init_Kendaraan(Kendaraan* k, const char* merek, const char* model, int roda, TampilkanInfoFunc info_func);
void init_RodaDua(RodaDua* rd, const char* merek, const char* model, const char* tipe);
void init_RodaEmpat(RodaEmpat* re, const char* merek, const char* model, const char* segmen);
void init_RodaEnam(RodaEnam* re, const char* merek, const char* model, const char* fungsi);


// =========================================================
// 3. IMPLEMENTASI FUNGSI (METHOD & CONSTRUCTOR)
// Ditempatkan di sini untuk kemudahan kompilasi satu file
// =========================================================

void tampilkanInfo_RodaDua(void* obj) {
    RodaDua* rd = (RodaDua*)obj; 
    printf("\nKategori: **Roda Dua** (Tipe %s)\n", rd->tipe);
    printf("Merek: %s\n", rd->super.merek);
    printf("Model: %s\n", rd->super.model);
    printf("Jumlah Roda: %d\n", rd->super.jumlahRoda);
    printf("--------------------------------\n");
}

void tampilkanInfo_RodaEmpat(void* obj) {
    RodaEmpat* re = (RodaEmpat*)obj; 
    printf("\nKategori: **Roda Empat** (Segmen %s)\n", re->segmen);
    printf("Merek: %s\n", re->super.merek);
    printf("Model: %s\n", re->super.model);
    printf("Jumlah Roda: %d\n", re->super.jumlahRoda);
    printf("--------------------------------\n");
}

void tampilkanInfo_RodaEnam(void* obj) {
    RodaEnam* re = (RodaEnam*)obj; 
    printf("\nKategori: **Roda Enam** (Fungsi %s)\n", re->fungsi);
    printf("Merek: %s\n", re->super.merek);
    printf("Model: %s\n", re->super.model);
    printf("Jumlah Roda: %d\n", re->super.jumlahRoda);
    printf("--------------------------------\n");
}

void init_Kendaraan(Kendaraan* k, const char* merek, const char* model, int roda, TampilkanInfoFunc info_func) {
    strncpy(k->merek, merek, 49); k->merek[49] = '\0';
    strncpy(k->model, model, 49); k->model[49] = '\0';
    k->jumlahRoda = roda;
    k->tampilkanInfo = info_func;
}

void init_RodaDua(RodaDua* rd, const char* merek, const char* model, const char* tipe) {
    init_Kendaraan(&(rd->super), merek, model, 2, tampilkanInfo_RodaDua);
    strncpy(rd->tipe, tipe, 49); rd->tipe[49] = '\0';
}

void init_RodaEmpat(RodaEmpat* re, const char* merek, const char* model, const char* segmen) {
    init_Kendaraan(&(re->super), merek, model, 4, tampilkanInfo_RodaEmpat);
    strncpy(re->segmen, segmen, 49); re->segmen[49] = '\0';
}

void init_RodaEnam(RodaEnam* re, const char* merek, const char* model, const char* fungsi) {
    init_Kendaraan(&(re->super), merek, model, 6, tampilkanInfo_RodaEnam);
    strncpy(re->fungsi, fungsi, 49); re->fungsi[49] = '\0';
}


// =========================================================
// 4. FUNGSI UTAMA (MAIN CONTROLLER)
// =========================================================

int main() {
    int pilihan_roda, pilihan_merek;
    
    // Inisialisasi data kendaraan di awal program
    RodaDua kawasaki_ninja; init_RodaDua(&kawasaki_ninja, "Kawasaki", "Ninja ZX-25R", "Sport");
    RodaDua suzuki_satria; init_RodaDua(&suzuki_satria, "Suzuki", "Satria F150", "Underbone");
    RodaDua bmw_motor; init_RodaDua(&bmw_motor, "BMW", "R 1250 GS", "Touring");
    
    RodaEmpat suzuki_ertiga; init_RodaEmpat(&suzuki_ertiga, "Suzuki", "Ertiga", "MPV");
    RodaEmpat bmw_mobil; init_RodaEmpat(&bmw_mobil, "BMW", "X7", "SUV Mewah");
    
    RodaEnam isuzu_truk; init_RodaEnam(&isuzu_truk, "Isuzu", "Giga FVM", "Truk Box"); 
    
    
    printf("=== KLASIFIKASI KENDARAAN INTERAKTIF ===\n\n");

    do {
        printf("Pilih Kategori Roda:\n");
        printf("1. Roda Dua\n");
        printf("2. Roda Empat\n");
        printf("3. Roda Enam\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan (1-4): ");
        
        if (scanf("%d", &pilihan_roda) != 1) {
            printf("\nInput tidak valid. Harap masukkan angka.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (pilihan_roda == 4) {
            printf("\nTerima kasih, program selesai.\n");
            break;
        }
        
        if (pilihan_roda < 1 || pilihan_roda > 3) {
            printf("\nPilihan roda tidak valid. Coba lagi.\n");
            continue;
        }
        
        printf("\n");
        
        // SWITCH BERLAPIS UNTUK MEMILIH MEREK
        switch (pilihan_roda) {
            case 1: // RODA DUA
                printf("Pilih Merek Roda Dua:\n");
                printf("1. Kawasaki (Ninja ZX-25R)\n");
                printf("2. Suzuki (Satria F150)\n");
                printf("3. BMW (R 1250 GS)\n");
                printf("Masukkan pilihan (1-3): ");
                scanf("%d", &pilihan_merek);
                
                switch (pilihan_merek) {
                    case 1: kawasaki_ninja.super.tampilkanInfo(&kawasaki_ninja); break;
                    case 2: suzuki_satria.super.tampilkanInfo(&suzuki_satria); break;
                    case 3: bmw_motor.super.tampilkanInfo(&bmw_motor); break;
                    default: printf("\nPilihan merek tidak valid.\n"); break;
                }
                break;
                
            case 2: // RODA EMPAT
                printf("Pilih Merek Roda Empat:\n");
                printf("1. Suzuki (Ertiga)\n");
                printf("2. BMW (X7)\n");
                printf("Masukkan pilihan (1-2): ");
                scanf("%d", &pilihan_merek);
                
                switch (pilihan_merek) {
                    case 1: suzuki_ertiga.super.tampilkanInfo(&suzuki_ertiga); break;
                    case 2: bmw_mobil.super.tampilkanInfo(&bmw_mobil); break;
                    default: printf("\nPilihan merek tidak valid.\n"); break;
                }
                break;
                
            case 3: // RODA ENAM
                printf("Pilih Merek Roda Enam:\n");
                printf("1. Isuzu (Giga FVM)\n");
                printf("Masukkan pilihan (1): ");
                scanf("%d", &pilihan_merek);
                
                switch (pilihan_merek) {
                    case 1: isuzu_truk.super.tampilkanInfo(&isuzu_truk); break;
                    default: printf("\nPilihan merek tidak valid.\n"); break;
                }
                break;
        }
        printf("\nTekan ENTER untuk melanjutkan...\n");
        while (getchar() != '\n'); // Membersihkan buffer
        getchar(); // Menunggu input ENTER
        
    } while (pilihan_roda != 4);

    return 0;
}