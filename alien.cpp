#include <iostream>

using namespace std;

int main() {
    char pesan[1000]; 
    
    cout << "Masukkan pesan yang ingin disandi: ";
    cin.getline(pesan, 1000);

    char pesan_tersandi[1000];
    int nilai_sebelumnya = 0;
    int i = 0;

    while (pesan[i] != '\0') {
        char huruf = pesan[i];

        if (huruf >= 'a' && huruf <= 'z') {
            huruf = huruf - 32;
        }

        if (huruf >= 'A' && huruf <= 'Z') {
            
            int nilai_sekarang = (huruf - 'A') + 1;

            if (i == 0) {
                pesan_tersandi[i] = huruf;
            } else {
                
                int nilai_baru = nilai_sekarang + nilai_sebelumnya;
                int nilai_final = (nilai_baru - 1) % 26 + 1;
                char huruf_baru = (nilai_final - 1) + 'A';
                pesan_tersandi[i] = huruf_baru;
            }
            nilai_sebelumnya = nilai_sekarang;
        } else {

            pesan_tersandi[i] = pesan[i];
        }

        i++;
    }
    pesan_tersandi[i] = '\0';

    cout << "\nPesan Asli    : " << pesan << endl;
    cout << "Pesan Tersandi: " << pesan_tersandi << endl;

    return 0;
}