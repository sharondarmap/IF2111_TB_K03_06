#include <stdio.h>
#include "setmap.h"

int main() {
    Map keranjang;
    
    CreateEmptyKeranjang(&keranjang);
    
    // Create some sample Barang
    Barang barang1 = {"Laptop", 10000};
    Barang barang2 = {"Mouse", 5000};
    Barang barang3 = {"Keyboard", 7500};
    Barang barang4 = {"Monitor", 15000};
    
    printf("=== Pengujian ADT Keranjang ===\n\n");
    
    // Test adding items
    printf("1. Menambahkan barang ke keranjang:\n");
    AddToKeranjang(&keranjang, barang1, 2);
    AddToKeranjang(&keranjang, barang2, 3);
    AddToKeranjang(&keranjang, barang3, 1);
    TampilkanKeranjang(keranjang);
    
    // Test checking item quantity
    printf("\n2. Mengecek jumlah barang:\n");
    printf("Jumlah barang 1: %d\n", GetItemQuantity(keranjang, barang1));
    printf("Jumlah barang 2: %d\n", GetItemQuantity(keranjang, barang2));
    
    // Test checking if item is in keranjang
    printf("\n3. Mengecek keberadaan barang:\n");
    printf("barang 1 ada di keranjang: %s\n", IsItemInKeranjang(keranjang, barang1) ? "Ya" : "Tidak");
    printf("barang 4 ada di keranjang: %s\n", IsItemInKeranjang(keranjang, barang4) ? "Ya" : "Tidak");
    
    // Test updating item quantity
    printf("\n4. Mengupdate jumlah barang:\n");
    UpdateKeranjangItemQuantity(&keranjang, barang1, 5);
    TampilkanKeranjang(keranjang);
    
    // Test removing an item
    printf("\n5. Menghapus barang dari keranjang:\n");
    RemoveFromKeranjang(&keranjang, barang2);
    TampilkanKeranjang(keranjang);
    
    // Test total price calculation
    printf("\n6. Total harga keranjang:\n");
    printf("Total Harga: %d\n", HitungTotalHargaKeranjang(keranjang));
    
    // Test adding same item (should increase quantity)
    printf("\n7. Menambahkan barang yang sudah ada:\n");
    AddToKeranjang(&keranjang, barang1, 3);
    TampilkanKeranjang(keranjang);
    
    // Test empty and full conditions
    printf("\n8. Status Keranjang:\n");
    printf("Keranjang kosong: %s\n", IsKeranjangEmpty(keranjang) ? "Ya" : "Tidak");
    printf("Keranjang penuh: %s\n", IsKeranjangFull(keranjang) ? "Ya" : "Tidak");
    
    return 0;
}