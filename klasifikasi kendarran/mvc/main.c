// main_kendaraan.c (Controller + Implementasi Model & View)
#include <stdio.h>
#include <stdlib.h>
#include "model.h" // Mengimpor struktur dan init functions
#include "view.h" // Mengimpor fungsi tampilan

// =========================================================
// IMPLEMENTASI METHOD (TAMPILAN) - Bagian dari Model/Logic
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

// =========================================================
// IMPLEMENTASI CONSTRUCTOR - Bagian dari Model/Data
// =========================================================

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
// IMPLEMENTASI VIEW - Bagian dari Tampilan
// =========================================================

void tampilkanMenuRoda() {
    printf("=== KLASIFIKASI KENDARAAN INTERAKTIF (MVC C) ===\n\n");
    printf("Pilih Kategori Roda:\n");
    printf("1. Roda Dua\n");
    printf("2. Roda Empat\n");
    printf("3. Roda Enam\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan (1-4): ");
}

void tampilkanMenuRodaDua() {
    printf("Pilih Merek Roda Dua:\n");
    printf("1. Kawasaki (Ninja ZX-25R)\n");
    printf("2. Suzuki (Satria F150)\n");
    printf("3. BMW (R 1250 GS)\n");
    printf("Masukkan pilihan (1-3): ");
}

void tampilkanMenuRodaEmpat() {
    printf("Pilih Merek Roda Empat:\n");
    printf("1. Suzuki (Ertiga)\n");
    printf("2. BMW (X7)\n");
    printf("Masukkan pilihan (1-2): ");
}

void tampilkanMenuRodaEnam() {
    printf("Pilih Merek Roda Enam:\n");
    printf("1. Isuzu (Giga FVM)\n");
    printf("Masukkan pilihan (1): ");
}

void tampilkanPesanError(const char *pesan) {
    printf("\n[ERROR] %s\n", pesan);
}

// =========================================================
// FUNGSI UTAMA (CONTROLLER)
// =========================================================

int main() {
    int pilihan_roda, pilihan_merek;
    
    // Inisialisasi data kendaraan (Model)
    RodaDua kawasaki_ninja; init_RodaDua(&kawasaki_ninja, "Kawasaki", "Ninja ZX-25R", "Sport");
    RodaDua suzuki_satria; init_RodaDua(&suzuki_satria, "Suzuki", "Satria F150", "Underbone");
    RodaDua bmw_motor; init_RodaDua(&bmw_motor, "BMW", "R 1250 GS", "Touring");
    
    RodaEmpat suzuki_ertiga; init_RodaEmpat(&suzuki_ertiga, "Suzuki", "Ertiga", "MPV");
    RodaEmpat bmw_mobil; init_RodaEmpat(&bmw_mobil, "BMW", "X7", "SUV Mewah");
    
    RodaEnam isuzu_truk; init_RodaEnam(&isuzu_truk, "Isuzu", "Giga FVM", "Truk Box"); 
    
    do {
        tampilkanMenuRoda(); // Panggil View
        
        if (scanf("%d", &pilihan_roda) != 1) {
            tampilkanPesanError("Input tidak valid. Harap masukkan angka.");
            while (getchar() != '\n'); 
            continue;
        }

        if (pilihan_roda == 4) {
            printf("\nTerima kasih, program selesai.\n");
            break;
        }
        
        if (pilihan_roda < 1 || pilihan_roda > 3) {
            tampilkanPesanError("Pilihan roda tidak valid. Coba lagi.");
            continue;
        }
        
        printf("\n");
        
        // Controller mengatur menu merek dan menampilkan Model yang benar
        switch (pilihan_roda) {
            case 1: // RODA DUA
                tampilkanMenuRodaDua(); // Panggil View
                scanf("%d", &pilihan_merek);
                
                switch (pilihan_merek) {
                    case 1: kawasaki_ninja.super.tampilkanInfo(&kawasaki_ninja); break; // Panggil Model Method
                    case 2: suzuki_satria.super.tampilkanInfo(&suzuki_satria); break; 
                    case 3: bmw_motor.super.tampilkanInfo(&bmw_motor); break;
                    default: tampilkanPesanError("Pilihan merek tidak valid."); break;
                }
                break;
                
            case 2: // RODA EMPAT
                tampilkanMenuRodaEmpat(); // Panggil View
                scanf("%d", &pilihan_merek);
                
                switch (pilihan_merek) {
                    case 1: suzuki_ertiga.super.tampilkanInfo(&suzuki_ertiga); break; // Panggil Model Method
                    case 2: bmw_mobil.super.tampilkanInfo(&bmw_mobil); break;
                    default: tampilkanPesanError("Pilihan merek tidak valid."); break;
                }
                break;
                
            case 3: // RODA ENAM
                tampilkanMenuRodaEnam(); // Panggil View
                scanf("%d", &pilihan_merek);
                
                switch (pilihan_merek) {
                    case 1: isuzu_truk.super.tampilkanInfo(&isuzu_truk); break; // Panggil Model Method
                    default: tampilkanPesanError("Pilihan merek tidak valid."); break;
                }
                break;
        }
        printf("\nTekan ENTER untuk melanjutkan...\n");
        while (getchar() != '\n');
        getchar();
        
    } while (pilihan_roda != 4);

    return 0;
}