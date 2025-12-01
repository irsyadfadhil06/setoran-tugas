#include <stdio.h>
#include <stdlib.h> // Untuk system("cls") atau system("clear") jika diperlukan

// Fungsi untuk menghitung Luas Persegi Panjang
double hitungLuasPersegiPanjang(double panjang, double lebar) {
    return panjang * lebar;
}

// Fungsi untuk menghitung Volume Kubus
double hitungVolumeKubus(double sisi) {
    return sisi * sisi * sisi;
}

// Fungsi untuk menghitung Luas Jajargenjang
double hitungLuasJajargenjang(double alas, double tinggi) {
    return alas * tinggi;
}

void tampilkanMenu() {
    printf("\n============================================\n");
    printf("        PROGRAM HITUNG BANGUN DATAR/RUANG\n");
    printf("              (C MURNI)\n");
    printf("============================================\n");
    printf("Pilih Bangun yang akan dihitung:\n");
    printf("1. Persegi Panjang (Luas)\n");
    printf("2. Kubus (Volume) [Image of a cube]\n");
    printf("3. Jajargenjang (Luas)\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan (1-4): ");
}

int main() {
    int pilihan;
    // Menggunakan tipe data double untuk hasil yang lebih akurat (bisa menampung desimal)
    double p, l, s, a, t, hasil;

    do {
        tampilkanMenu();
        // Menggunakan scanf untuk mengambil input integer (pilihan)
        if (scanf("%d", &pilihan) != 1) {
            printf("\nInput tidak valid. Harap masukkan angka.\n");
            // Membersihkan buffer input untuk mencegah loop tak terbatas
            while (getchar() != '\n'); 
            continue;
        }

        switch (pilihan) {
            case 1:
                printf("\n--- PERSEGI PANJANG ---\n");
                printf("Masukkan Panjang: ");
                scanf("%lf", &p); // Menggunakan %lf untuk double
                printf("Masukkan Lebar: ");
                scanf("%lf", &l);
                
                if (p > 0 && l > 0) {
                    hasil = hitungLuasPersegiPanjang(p, l);
                    printf("Luas Persegi Panjang: **%.2lf**\n", hasil);
                } else {
                    printf("Input harus bilangan positif.\n");
                }
                break;

            case 2:
                printf("\n--- KUBUS ---\n");
                printf("Masukkan panjang Sisi: ");
                scanf("%lf", &s);
                
                if (s > 0) {
                    hasil = hitungVolumeKubus(s);
                    printf("Volume Kubus: **%.2lf**\n", hasil);
                } else {
                    printf("Input harus bilangan positif.\n");
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
                    printf("Luas Jajargenjang: **%.2lf**\n", hasil);
                } else {
                    printf("Input harus bilangan positif.\n");
                }
                break;

            case 4:
                printf("\nTerima kasih, program selesai.\n");
                break;

            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
        
    } while (pilihan != 4);

    return 0;
}