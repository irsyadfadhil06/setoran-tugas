// main.c (Controller + Implementasi Model & View)
#include <stdio.h>
#include "model.h"
#include "view.h"

// =================================================================
// Implementasi Model (Logika Perhitungan)
// =================================================================

double hitungLuasPersegiPanjang(double panjang, double lebar) {
    return panjang * lebar;
}

double hitungVolumeKubus(double sisi) {
    return sisi * sisi * sisi;
}

double hitungLuasJajargenjang(double alas, double tinggi) {
    return alas * tinggi;
}

// =================================================================
// Implementasi View (Tampilan Output) - SINTAKS DI SINI DIPERBAIKI
// =================================================================

void tampilkanMenu() {
    printf("\n============================================\n");
    printf("        MEENGHITUNG BANGUN DATAR/RUANG\n");
    printf("============================================\n");
    printf("Pilih Bangun yang akan dihitung:\n");
    
    // Perbaikan syntax error
    printf("1. Persegi Panjang (Luas) \n");
    printf("2. Kubus (Volume) \n");
    printf("3. Jajargenjang (Luas) \n");
    
    printf("4. Keluar\n");
    printf("Masukkan pilihan (1-4): ");
}

void tampilkanHasil(const char *namaBangun, const char *jenisPerhitungan, double hasil) {
    printf("%s %s: **%.2lf**\n", jenisPerhitungan, namaBangun, hasil);
}

void tampilkanPesanError(const char *pesan) {
    printf("\n[ERROR] %s\n", pesan);
}

// =================================================================
// Controller (Logika Utama Program)
// =================================================================

int main() {
    int pilihan;
    double p, l, s, a, t, hasil;

    do {
        tampilkanMenu();
        
        if (scanf("%d", &pilihan) != 1) {
            tampilkanPesanError("Input tidak valid. Harap masukkan angka.");
            while (getchar() != '\n'); 
            continue;
        }

        switch (pilihan) {
            case 1:
                printf("\n--- PERSEGI PANJANG ---\n");
                printf("Masukkan Panjang: ");
                scanf("%lf", &p); 
                printf("Masukkan Lebar: ");
                scanf("%lf", &l);
                
                if (p > 0 && l > 0) {
                    hasil = hitungLuasPersegiPanjang(p, l); 
                    tampilkanHasil("Persegi Panjang", "Luas", hasil); 
                } else {
                    tampilkanPesanError("Input panjang dan lebar harus bilangan positif."); 
                }
                break;

            case 2:
                printf("\n--- KUBUS ---\n");
                printf("Masukkan panjang Sisi: ");
                scanf("%lf", &s);
                
                if (s > 0) {
                    hasil = hitungVolumeKubus(s); 
                    tampilkanHasil("Kubus", "Volume", hasil); 
                } else {
                    tampilkanPesanError("Input sisi harus bilangan positif."); 
                }
                break;

            case 3:
                printf("\n--- JAJARGENJANG ---\n");
                printf("Masukkan Alas: ");
                scanf("%lf", &a);
                printf("Masukkan Tinggi: ");
                scanf("%lf", &t);

                if (a > 0 && t > 0) {
                    hasil = hitungLuasJajargenjang(a, t); 
                    tampilkanHasil("Jajargenjang", "Luas", hasil); 
                } else {
                    tampilkanPesanError("Input alas dan tinggi harus bilangan positif."); 
                }
                break;

            case 4:
                printf("\nTerima kasih, program selesai.\n");
                break;

            default:
                tampilkanPesanError("Pilihan tidak valid. Silakan coba lagi."); 
                break;
        }
        
    } while (pilihan != 4);

    return 0;
}