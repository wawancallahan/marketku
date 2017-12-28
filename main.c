/*
 * {
 *      "name": "marketku/c",
 *      "description": "Point Of Sales Created By Team 2",
 *      "type": "Project",
 *      "require": "c",
 *      "team-dev": {
 *          "Dandy Hidayat",
 *          "Mia Lidiyani",
 *          "Sarah Rizkia Suhada",
 *          "Imam Fahrizal Rahmat",
 *          "Kurniawan Prima A"
 *      },
 *      "repository": "https://github.com/wawancallahan/marketku"
 * }
 * 
 * 
 **/


#include <stdio.h>
#include <stdlib.h>

int main()
{    
    /* Deklarasi Variabel Menu
     * 
     * 
     * */
     
     char MenuArray[3][20] = {
        "Makanan",
        "Minuman",
        "Kebutuhan Pokok"
     };
     
     int MenuCount = sizeof(MenuArray) / sizeof(MenuArray[0]);
    
    /* Deklarasi variabel pembantu
     * 
     * */
     
     int forMenu, forMenuSwitch, forCodeMenu, forBuy, forGetBuy, forCode, forRemove, forRemoveBuy, forAvailable, forAvailableItem, forMemberList;
     int getMainMenu, getMenu, getCodeMenu, getBuyCode, getTotalMenu, getRemoveItem, getReduceItem, getMemberMenu, getMethodPayment, getDebitCard, getCreditCard;
     int reCallMenu = 0;
     int setMenu;
     int BuyMenu[100], BuyCode[100], BuyTotal[100];
     int BuyCount = 0;
     int BuyFail = 1, MemberFail = 1, DebitFail = 1, CreditFail = 1;
     int getMore, getDetailInvent;
     int totalPrice = 0, finalTotalPrice, setPayment, totalPriceInvent = 0;
     
     char getMember, getPayment;
     int getCodeMember, getCodeDebitCard, getCodeCreditCard;
     char reCodeMember, reRemove, reCodeDebitCard, reCodeCreditCard;
     int MemberOn = 0, DebitOn = 0, CreditOn = 0;
     int MemberDiscount, Discount = 5, DiscountPayment, DebitPayment, CreditPayment;
     int randomCode;
     
     char getName[100], getAddress[100];
     
     
     int return_value = 0;
     
    /* Deklarasi Variabel Daftar Item
     * 
     * */
    int codeItemMakanan[10] = { 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
    
    char namaItemMakanan[10][30] = { "Vanilla Beans", "Roti Gandum", "Doritos", "Sosis",
                                     "Marshmellow", "Indomie", "Cultured Butter", "Creme Fraiche",
                                     "Artichoke Hearts", "Walnut" };
    
    int hargaItemMakanan[10] = { 4500, 3700, 6900, 2400, 7500, 2300, 7000, 10000, 2000,
                                 3400 };
                                 
                                 
    int codeItemMinuman[10] = { 111, 112, 113, 114, 115, 116, 117, 118, 119, 120 };
    
    char namaItemMinuman[10][30] = { "Ensure Susu", "Produgen Gold", "Vidoran XMart", "Torany Sirup",
                                     "Kiyora Tea", "Nescafe", "Coolant", "Minute Maid",
                                     "Buavita", "Q Guava" };
    
    int hargaItemMinuman[10] = { 3500, 2000, 2300, 1500, 1800, 3300, 3600, 6000, 7000,
                                 5800 };
                                 
                                 
    int codeItemKebutuhanPokok[10] = { 121, 122, 123, 124, 125, 126, 127, 128, 129, 130 };
    
    char namaItemKebutuhanPokok[10][30] = { "Avena Minyak Goreng", "Beras Muncul", "Gula Merah Curah ", "Gula Pasir",
                                     "Rose Brand", "Daging Sapi", "Ikan Bandeng", "Telur Ayam Ras",
                                     "Cabe Merah Keriting", "Margarin Blueband Cup" };
    
    int hargaItemKebutuhanPokok[10] = { 12000, 15000, 7000, 8000, 18000, 45000, 23000, 2000, 2400,
                                 19000 };
                                
    /**
     * Deklarasi Daftar Kode Debit Card & Kredit Card
     * 
     * */
     
     int codeDebitCard[5] = {
         95023293,
         29312852,
         21831298,
         94854542,
         55353513
     };
     
     int codeCreditCard[5] = {
         827847529,
         353535111,
         158957313,
         294862456,
         344459454
     };
                                 
    /**
     * Deklarasi Daftar Kode Member
     * 
     * */
      
    int MemberCountDefault = 5;
                           
    int codeMember[100] = {
        5270,
        2300,
        5717,
        7254,
        9014
    };
    
    int discountCodeMember[100] = {
        10,
        10,
        10,
        10,
        10
    };
    
    int codeMemberCount = sizeof(codeMember) / sizeof(codeMember[0]);
    
    printf("\t========================================================");
    printf("\n\t|\t\t Selamat Datang Di Marketku\t       |\n");
    printf("\t======================================================== \n\n");
    
    MenuUtama:
    
    printf("\n\t\t\t  Menu Utama\n");
    
    printf("\t\t================================== \n");
    printf("\t\t| %-7s | %-20s | \n", "1.", "Membeli Barang");
    printf("\t\t| %-7s | %-20s | \n", "2.", "Member");
    printf("\t\t| %-7s | %-20s | \n", "0.", "Keluar");
    printf("\t\t================================== \n");
    
    while (!return_value) {
        printf("Masukkan Pilihan ? ");
        return_value = scanf(" %d", &getMainMenu);
        while(getchar() != '\n');
    }
    
    return_value = 0;
    
    switch(getMainMenu) {
        case 0:
            printf("\n");
            return 0;
            break;
        case 1:
            Menu:
            system("cls");
            printf("\n\t\t\t\t    Daftar Menu \n");
            
            printf("\t\t\t================================== \n");
            for(forMenu = 0; forMenu < MenuCount; forMenu++) {
                printf("\t\t\t| %-7d | %-20s | \n", forMenu + 1, MenuArray[forMenu]);
            }
            printf("\t\t\t================================== \n");
            
            while (!return_value) {
                printf("\nPilih Menu (Ketikkan Angka) : ");
                return_value = scanf(" %d", &getMenu);
                while(getchar() != '\n');
            }
            
            return_value = 0;
            
            getMoreCurrentMenuLabel:
            
            do {
                switch(getMenu) {
                    case 1:
                        system("cls");

                        reCallMenu = 0;
                        setMenu = 1;
                        
                        printf("\n\t\t\t       Daftar Makanan \n");
                        printf("\t========================================================= \n");
                        printf("\t| %-7s | %-30s | %-10s | \n", "Kode", "Nama Makanan", "Harga");
                        printf("\t| %-7s | %-30s | %-10s | \n", "", "", "");
                        for(forMenuSwitch = 0; forMenuSwitch < 10; forMenuSwitch++) {
                            printf("\t| %-7d | %-30s | %-10d | \n", codeItemMakanan[forMenuSwitch], namaItemMakanan[forMenuSwitch], hargaItemMakanan[forMenuSwitch]);
                        }
                        printf("\t========================================================= \n");
                        
                        break;
                    case 2:
                        system("cls");
                        
                        reCallMenu = 0;
                        setMenu = 2;
                        
                        printf("\n\t\t\t       Daftar Minuman \n");
                        printf("\t========================================================= \n");
                        printf("\t| %-7s | %-30s | %-10s | \n", "Kode", "Nama Minuman", "Harga");
                        printf("\t| %-7s | %-30s | %-10s | \n", "", "", "");
                        for(forMenuSwitch = 0; forMenuSwitch < 10; forMenuSwitch++) {
                            printf("\t| %-7d | %-30s | %-10d | \n", codeItemMinuman[forMenuSwitch], namaItemMinuman[forMenuSwitch], hargaItemMinuman[forMenuSwitch]);
                        }
                        printf("\t========================================================= \n");
                        
                        break;
                    case 3:
                        system("cls");
                        
                        reCallMenu = 0;
                        setMenu = 3;
                        
                        printf("\n\t\t\t       Daftar Kebutuhan Pokok \n");
                        printf("\t========================================================= \n");
                        printf("\t| %-7s | %-30s | %-10s | \n", "Kode", "Nama Kebutuhan Pokok", "Harga");
                        printf("\t| %-7s | %-30s | %-10s | \n", "", "", "");
                        for(forMenuSwitch = 0; forMenuSwitch < 10; forMenuSwitch++) {
                            printf("\t| %-7d | %-30s | %-10d | \n", codeItemKebutuhanPokok[forMenuSwitch], namaItemKebutuhanPokok[forMenuSwitch], hargaItemKebutuhanPokok[forMenuSwitch]);
                        }
                        printf("\t========================================================= \n");
                        
                        break;
                    default :
                        
                        reCallMenu = 1;
                        while (!return_value) {
                            printf("Menu Hanya Ada Dari 1 - 3 \n");
                            printf("Pilih Menu Ulang (Ketikkan Angka) : ");
                            return_value = scanf(" %d", &getMenu);
                            while(getchar() != '\n');
                        }
                        
                        return_value = 0;
                        break;
                }
            }
            while(reCallMenu == 1);
            
            CodeMenuLabel:
            
            printf("\nSilahkan Pilih Item Dengan Memasukkan Kode\n");
            
            while (!return_value) {
                printf("Masukkan Kode : ");
                return_value = scanf(" %d", &getCodeMenu);
                while(getchar() != '\n');
            }
            
            return_value = 0;
            
            getCodeMenuLabel:
            
            switch(setMenu) {
                case 1:
                
                    for(forCodeMenu = 0; forCodeMenu < 10; forCodeMenu++) {
                        if(getCodeMenu == codeItemMakanan[forCodeMenu]) {
                            do {
                                while (!return_value) {
                                    printf("Masukkan Jumlah : ");
                                    return_value = scanf(" %d", &getTotalMenu);
                                    while(getchar() != '\n');
                                }
                                
                                return_value = 0;
                                
                                if(getTotalMenu <= 0) {
                                    printf("Jumlah Tidak Boleh Berisi 0 atau Kurang Dari 0 \n \n");
                                }
                            }
                            while(getTotalMenu <= 0);
                            
                            for(forAvailable = 0; forAvailable < BuyCount; forAvailable++) {
                                if(BuyCode[forAvailable] == getCodeMenu) {
                                    BuyTotal[forAvailable] = BuyTotal[forAvailable] + getTotalMenu;
                                    goto AvailableItemFirst;
                                }
                            }
                            
                            
                            BuyCode[BuyCount] = getCodeMenu;
                            BuyMenu[BuyCount] = setMenu;
                            BuyTotal[BuyCount] = getTotalMenu;
                            BuyCount = BuyCount + 1;
                            
                            AvailableItemFirst:
                            BuyFail = 0;
                        }
                    }
                    
                    if(BuyFail == 1) {
                        getCodeMenu = '\0';
                        printf("\nMaaf, Kode Yang Anda Masukkan Salah \n");
                        goto CodeMenuLabel;
                    }
                    
                    break;
                    
                case 2:
                    for(forCodeMenu = 0; forCodeMenu < 10; forCodeMenu++) {
                        if(getCodeMenu == codeItemMinuman[forCodeMenu]) {
                            do {
                                while (!return_value) {
                                    printf("Masukkan Jumlah : ");
                                    return_value = scanf(" %d", &getTotalMenu);
                                    while(getchar() != '\n');
                                }
                                
                                return_value = 0;
                                if(getTotalMenu <= 0) {
                                             printf("Jumlah Tidak Boleh Berisi 0 atau Kurang Dari 0 \n \n");
                                }
                            }
                            while(getTotalMenu <=0);
                            
                            for(forAvailable = 0; forAvailable < BuyCount; forAvailable++) {
                                if(BuyCode[forAvailable] == getCodeMenu) {
                                    BuyTotal[forAvailable] = BuyTotal[forAvailable] + getTotalMenu;
                                    goto AvailableItemSecond;
                                }
                            }
                            
                            BuyCode[BuyCount] = getCodeMenu;
                            BuyMenu[BuyCount] = setMenu;
                            BuyTotal[BuyCount] = getTotalMenu;
                            BuyCount = BuyCount + 1;
                            
                            AvailableItemSecond:
                            BuyFail = 0;
                        }
                    }
                    
                    if(BuyFail == 1) {
                        getCodeMenu = '\0';
                        printf("\nMaaf, Kode Yang Anda Masukkan Salah \n");
                        goto CodeMenuLabel;
                    }
                    
                    break;
                    
                case 3:
                
                    for(forCodeMenu = 0; forCodeMenu < 10; forCodeMenu++) {
                        if(getCodeMenu == codeItemKebutuhanPokok[forCodeMenu]) {
                            do {
                                while (!return_value) {
                                    printf("Masukkan Jumlah : ");
                                    return_value = scanf(" %d", &getTotalMenu);
                                    while(getchar() != '\n');
                                }
                                
                                return_value = 0;
                                
                                if(getTotalMenu <= 0) {
                                    printf("Jumlah Tidak Boleh Berisi 0 atau Kurang Dari 0 \n \n");
                                }
                            }
                            while(getTotalMenu <=0);
                            
                            for(forAvailable = 0; forAvailable < BuyCount; forAvailable++) {
                                if(BuyCode[forAvailable] == getCodeMenu) {
                                    BuyTotal[forAvailable] = BuyTotal[forAvailable] + getTotalMenu;
                                    goto AvailableItemThird;
                                }
                            }
                            
                            BuyCode[BuyCount] = getCodeMenu;
                            BuyMenu[BuyCount] = setMenu;
                            BuyTotal[BuyCount] = getTotalMenu;
                            BuyCount = BuyCount + 1;
                            
                            AvailableItemThird:
                            BuyFail = 0;
                        }
                    }
                    
                    if(BuyFail == 1) {
                        getCodeMenu = '\0';
                        printf("\nMaaf, Kode Yang Anda Masukkan Salah \n");
                        goto CodeMenuLabel;
                    }
                    
                    break;
            }
            
            BuyFail = 1;
            
            system("cls");
            MenuMore:
            MenuMoreFail:
            printf("\n\t\t====================================================== \n");
            printf("\t\t| %-7s | %-40s | \n", "1.", "Pilih Barang Dengan Menu Yang Sama");
            printf("\t\t| %-7s | %-40s | \n", "2.", "Pilih Barang Dengan Menu Yang Lain");
            printf("\t\t| %-7s | %-40s | \n", "3.", "Lakukan Pembayaran");
            printf("\t\t| %-7s | %-40s | \n", "4.", "Lihat Barang Yang Telah Diambil");
            printf("\t\t====================================================== \n");
            
            while (!return_value) {
                printf("Pilihan : ? ");
                return_value = scanf(" %d", &getMore);
                while(getchar() != '\n');
            }
            
            return_value = 0;
            
            switch(getMore) {
                case 1:
                    system("cls");
                    goto getMoreCurrentMenuLabel;
                    break;
                case 2:
                    printf("\n");
                    system("cls");
                    goto Menu;
                    break;
                case 3:
                    if(BuyCount < 1) {
                        printf("\nItem Yang Ada Ambil Tidak Ada \n\n");
                        goto MenuMoreFail;
                    }
                    
                    system("cls");
                    
                    printf("\n\t\t\t       Daftar Barang Yang Diambil \n");
                    printf("\t============================================================================================================ \n");
                    printf("\t| %-7s | %-17s | %-30s | %-10s | %-10s | %-15s |\n", "Kode", "Nama Menu", "Nama Barang","Harga", "Jumlah", "Total");
                    printf("\t| %-7s | %-17s | %-30s | %-10s | %-10s | %-15s |\n", "", "", "", "", "", "");
                    for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                        switch(BuyMenu[forBuy]) {
                            case 1:
                                for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                    if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                        printf("\t| %-7d | %-17s | %-30s | %-10d | %-10d | %-15d |\n", codeItemMakanan[forGetBuy], "Makanan", namaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                        totalPrice = totalPrice + (hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                    }
                                }
                                break;
                                
                            case 2:
                                for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                    if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                        printf("\t| %-7d | %-17s | %-30s | %-10d | %-10d | %-15d |\n", codeItemMinuman[forGetBuy], "Minuman", namaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                        totalPrice = totalPrice + (hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                    }
                                }
                                break;
                            case 3:
                                for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                    if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                        printf("\t| %-7d | %-17s | %-30s | %-10d | %-10d | %-15d |\n", codeItemKebutuhanPokok[forGetBuy], "Kebutuhan Pokok", namaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                        totalPrice = totalPrice + (hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                    }
                                }
                                break;
                        }
                        printf("\t============================================================================================================ \n");
                    }
                    
                    printf("\t| %86s | %-15d |\n", "Total", totalPrice);
                    
                    Discount == 0 ? printf("\t| %86s | %-15s |\n", "Diskon", "Tidak Ada Diskon") : printf("\t| %86s | %-15d |\n", "Diskon", Discount);
                    
                    MemberLabel:
                    printf("Apakah Mempunyai Data Member ? (y/n) ");
                    scanf(" %c", &getMember);
                    
                    if(getMember == 'y' || getMember == 'Y') {
                        do {
                            while (!return_value) {
                                printf("Masukkan Kode Member : ");
                                return_value = scanf(" %d", &getCodeMember);
                                while(getchar() != '\n');
                            }
                            
                            return_value = 0;
                            
                            for(forCode = 0; forCode < MemberCountDefault; forCode++) {
                                if(getCodeMember == codeMember[forCode]) {
                                    printf("\t| %86s | %-15d%% |\n", "Member", discountCodeMember[forCode]);
                                    MemberOn = 1;
                                    MemberFail = 0;
                                }
                            }
                            
                            if(MemberFail == 1) {
                                printf("Kode Member Tidak Valid \n");
                                
                                ReplyCodeMember:
                                printf("Apakah Ingin Mengulangi Kode Member ? (y/n)");
                                scanf(" %c", &reCodeMember);
                                
                                if(reCodeMember == 'y' || reCodeMember == 'Y') {
                                    MemberFail = 1;
                                    
                                    reCodeMember = '\0';
                                
                                } else if(reCodeMember == 'n' || reCodeMember == 'N') {
                                    MemberFail = 0;
                                    
                                    reCodeMember = '\0';
                                    
                                    printf("\t| %86s | %-15s |\n", "Member", "Tidak Ada Member");
                                } else {
                                    printf("Tidak Ada Dalam Pilihan \n");
                                    
                                    reCodeMember = '\0';
                                    
                                    goto ReplyCodeMember;
                                }
                                 
                            }
                        }
                        while(MemberFail == 1);
                    } else if (getMember == 'n' || getMember == 'N') {
                        printf("\t| %86s | %-15s |\n", "Member", "Tidak Ada Member");
                    } else {
                        getMember = '\0';
                        printf("Tidak Ada Dalam Pilihan \n");
                        goto MemberLabel;
                    }
                    
                    MemberFail = 1;
                    
                    printf("\t| %86s | %-15s |\n", "Pajak", "10%");
                    
                    MemberDiscount = MemberOn == 1 ? totalPrice / 10 : 0;
                    DiscountPayment = Discount == 0 ? 0 : (totalPrice * Discount) / 100;
                    
                    finalTotalPrice = totalPrice - DiscountPayment - MemberDiscount + (totalPrice / 10);
                    
                    printf("\t| %86s | %-15d |\n", "Total Keseluruhan", finalTotalPrice);
                    
                    PaymentLabel:
                    printf("Apakah Ingin Membayar ? (y/n) ");
                    scanf(" %c", &getPayment);
                    
                    if(getPayment == 'y' || getPayment == 'Y') {
                        
                        MethodPaymentLabel:
                        
                        printf("\n\t\t========================= \n");
                        printf("\t\t| %-7s | %-11s | \n", "1." ,"Cash");
                        printf("\t\t| %-7s | %-11s | \n", "2." ,"Debit Card");
                        printf("\t\t| %-7s | %-11s | \n", "3." ,"Kredit Card");
                        printf("\t\t=========================\n");
                        
                        while (!return_value) {
                            printf("Pilih Metode Pembayaran ? ");
                            return_value = scanf(" %d", &getMethodPayment);
                            while(getchar() != '\n');
                        }
                        
                        return_value = 0;
                        
                        switch(getMethodPayment) {
                            case 1:
                                do {
                                    while (!return_value) {
                                        printf("\nMasukkan Pembayaran : ");
                                        return_value = scanf(" %d", &setPayment);
                                        while(getchar() != '\n');
                                    }
                                    
                                    return_value = 0;
                                    
                                    if(setPayment >= finalTotalPrice) {
                                        printf("Kembalian : %d \n\n", setPayment - finalTotalPrice);
                                    }
                                    else {
                                        printf("Pembayaran Kurang Dari Total Keseluruhan \n");
                                    }
                                }
                                while(finalTotalPrice > setPayment);
                                
                                system("cls");
                                printf("\n\t\t\t\t\t MarketKu\n");
                                
                                printf("\t=========================================================================\n");
                                printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                                    switch(BuyMenu[forBuy]) {
                                        case 1:
                                            for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                                    printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                                }
                                            }
                                            break;
                                            
                                        case 2:
                                            for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                                    printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                                }
                                            }
                                            break;
                                        case 3:
                                            for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                                    printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                                }
                                            }
                                            break;
                                    }
                                }
                                printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                printf("\t=========================================================================\n");
                                
                                
                                printf("\t| %51s | %-15d |\n", "Total", totalPrice);
                    
                                Discount == 0 ? printf("") : printf("\t| %51s | %-15d |\n", "Diskon", Discount);
                                
                                MemberOn == 1 ? printf("\t| %51s | %-15s |\n", "Member", "10%") : printf("");
                                
                                printf("\t| %51s | %-15s |\n", "Pajak", "10%");
                                printf("\t| %51s | %-15d |\n", "Total Keseluruhan", finalTotalPrice);
                                
                                printf("\t| %51s | %-15d |\n", "Tunai", setPayment);
                                printf("\t| %51s | %-15d |\n", "Kembalian", setPayment - finalTotalPrice);
                                printf("\t=========================================================================\n");
                                
                                printf("\n\n\t\t\t Terima Kasih, Selamat Belanja Kembali\n");
                                printf("\t\t       ======= Layanan Konsumen MarketKu ======= \n");                             
                                break;
                            case 2:
                                DebitCardLabel:
                                printf("\t\t============================================ \n");
                                printf("\t\t| %-7s | %-30s | \n", "1." ,"Bank Mandiri");
                                printf("\t\t| %-7s | %-30s | \n", "2." ,"Bank BRI");
                                printf("\t\t| %-7s | %-30s | \n", "3." ,"Bank BNI");
                                printf("\t\t| %-7s | %-30s | \n", "4." ,"Bank BTN");
                                printf("\t\t| %-7s | %-30s | \n", "0." ,"Pergi ke Menu Sebelumnya");
                                printf("\t\t============================================ \n");
                                
                                while (!return_value) {
                                    printf("Masukkan Pilihan ? ");
                                    return_value = scanf(" %d", &getDebitCard);
                                    while(getchar() != '\n');
                                }
                                
                                return_value = 0;
                                
                                switch(getDebitCard) {
                                    case 0: 
                                        printf("\n\n");
                                        goto MethodPaymentLabel;
                                        break;
                                    case 1:
                                        
                                        do {
                                            while (!return_value) {
                                                printf("Masukkan Kode Debit Card : ");
                                                return_value = scanf(" %d", &getCodeDebitCard);
                                                while(getchar() != '\n');
                                            }
                                            
                                            return_value = 0;
                                            
                                            for(forCode = 0; forCode < 5; forCode++) {
                                                if(getCodeDebitCard == codeDebitCard[forCode]) {
                                                    printf("\t| %86s | %-15d%% |\n", "Debit Card", 5);
                                                    DebitOn = 1;
                                                    DebitFail = 0;
                                                }
                                            }
                                            
                                            if(DebitFail == 1) {
                                                printf("Kode Debit Tidak Valid \n");
                                                
                                                ReplyCodeDebitCardSatu:
                                                printf("Apakah Ingin Mengulangi Kode Debit ? (y/n)");
                                                scanf(" %c", &reCodeDebitCard);
                                                
                                                if(reCodeDebitCard == 'y' || reCodeDebitCard == 'Y') {
                                                    DebitFail = 1;
                                                    
                                                    reCodeDebitCard = '\0';
                                                
                                                } else if(reCodeDebitCard == 'n' || reCodeDebitCard == 'N') {
                                                    DebitFail = 1;
                                                    DebitOn = 0;
                                                    reCodeDebitCard = '\0';
                                                    goto DebitCardLabel;
                                                } else {
                                                    reCodeDebitCard = '\0';
                                                    printf("Tidak Ada Dalam Pilihan \n");
                                                    
                                                    goto ReplyCodeDebitCardSatu;
                                                }
                                                 
                                            }
                                        }
                                        while(DebitFail == 1);
                                        
                                        system("cls");
                                        printf("\n\t\t\t\t\t MarketKu\n");
                                        
                                        printf("\t=========================================================================\n");
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                                            switch(BuyMenu[forBuy]) {
                                                case 1:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                    
                                                case 2:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                case 3:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        printf("\t=========================================================================\n");
                                        
                                        
                                        printf("\t| %51s | %-15d |\n", "Total", totalPrice);
                            
                                        Discount == 0 ? printf("") : printf("\t| %51s | %-15d |\n", "Diskon", Discount);
                                        
                                        MemberOn == 1 ? printf("\t| %51s | %-15s |\n", "Member", "10%") : printf("");
                                        DebitPayment = DebitOn == 1 ? (totalPrice * 5) / 100 : 0;
                                        printf("\t| %51s | %-15s |\n", "Pajak", "10%");
                                        
                                        printf("\t| %51s | %-15s |\n", "Bank Mandiri", "5%");
                                        printf("\t| %51s | %-15d |\n", "Total Keseluruhan", finalTotalPrice - DebitPayment);
                                        
                                        printf("\t=========================================================================\n");
                                        
                                        printf("\n\n\t\t\t Terima Kasih, Selamat Belanja Kembali\n");
                                        printf("\t\t       ======= Layanan Konsumen MarketKu ======= \n");
                                        break;
                                    case 2:
                                        
                                        do {
                                            while (!return_value) {
                                                printf("Masukkan Kode Debit Card : ");
                                                return_value = scanf(" %d", &getCodeDebitCard);
                                                while(getchar() != '\n');
                                            }
                                            
                                            return_value = 0;
                                            
                                            for(forCode = 0; forCode < 5; forCode++) {
                                                if(getCodeDebitCard == codeDebitCard[forCode]) {
                                                    printf("\t| %86s | %-15d%% |\n", "Debit Card", 5);
                                                    DebitOn = 1;
                                                    DebitFail = 0;
                                                }
                                            }
                                            
                                            if(DebitFail == 1) {
                                                printf("Kode Debit Tidak Valid \n");
                                                
                                                ReplyCodeDebitCardDua:
                                                printf("Apakah Ingin Mengulangi Kode Debit ? (y/n)");
                                                scanf(" %c", &reCodeDebitCard);
                                                
                                                if(reCodeDebitCard == 'y' || reCodeDebitCard == 'Y') {
                                                    DebitFail = 1;
                                                    
                                                    reCodeDebitCard = '\0';
                                                
                                                } else if(reCodeDebitCard == 'n' || reCodeDebitCard == 'N') {
                                                    DebitFail = 1;
                                                    DebitOn = 0;
                                                    reCodeDebitCard = '\0';
                                                    goto DebitCardLabel;
                                                } else {
                                                    reCodeDebitCard = '\0';
                                                    printf("Tidak Ada Dalam Pilihan \n");
                                                    
                                                    goto ReplyCodeDebitCardDua;
                                                }
                                                 
                                            }
                                        }
                                        while(DebitFail == 1);
                                        
                                        system("cls");
                                        printf("\n\t\t\t\t\t MarketKu\n");
                                        
                                        printf("\t=========================================================================\n");
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                                            switch(BuyMenu[forBuy]) {
                                                case 1:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                    
                                                case 2:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                case 3:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        printf("\t=========================================================================\n");
                                        
                                        
                                        printf("\t| %51s | %-15d |\n", "Total", totalPrice);
                            
                                        Discount == 0 ? printf("") : printf("\t| %51s | %-15d |\n", "Diskon", Discount);
                                        
                                        MemberOn == 1 ? printf("\t| %51s | %-15s |\n", "Member", "10%") : printf("");
                                        DebitPayment = DebitOn == 1 ? (totalPrice * 5) / 100 : 0;
                                        printf("\t| %51s | %-15s |\n", "Pajak", "10%");
                                        
                                        printf("\t| %51s | %-15s |\n", "Bank BRI", "5%");
                                        printf("\t| %51s | %-15d |\n", "Total Keseluruhan", finalTotalPrice - DebitPayment);
                                        printf("\t=========================================================================\n");
                                        
                                        printf("\n\n\t\t\t Terima Kasih, Selamat Belanja Kembali\n");
                                        printf("\t\t       ======= Layanan Konsumen MarketKu ======= \n");

                                        break;
                                    case 3:
                                        
                                        do {
                                            while (!return_value) {
                                                printf("Masukkan Kode Debit Card : ");
                                                return_value = scanf(" %d", &getCodeDebitCard);
                                                while(getchar() != '\n');
                                            }
                                            
                                            return_value = 0;
                                            
                                            for(forCode = 0; forCode < 5; forCode++) {
                                                if(getCodeDebitCard == codeDebitCard[forCode]) {
                                                    printf("\t| %86s | %-15d%% |\n", "Debit Card", 5);
                                                    DebitOn = 1;
                                                    DebitFail = 0;
                                                }
                                            }
                                            
                                            if(DebitFail == 1) {
                                                printf("Kode Debit Tidak Valid \n");
                                                
                                                ReplyCodeDebitCardTiga:
                                                printf("Apakah Ingin Mengulangi Kode Debit ? (y/n)");
                                                scanf(" %c", &reCodeDebitCard);
                                                
                                                if(reCodeDebitCard == 'y' || reCodeDebitCard == 'Y') {
                                                    DebitFail = 1;
                                                    
                                                    reCodeDebitCard = '\0';
                                                
                                                } else if(reCodeDebitCard == 'n' || reCodeDebitCard == 'N') {
                                                    DebitFail = 1;
                                                    DebitOn = 0;
                                                    reCodeDebitCard = '\0';
                                                    goto DebitCardLabel;
                                                } else {
                                                    reCodeDebitCard = '\0';
                                                    printf("Tidak Ada Dalam Pilihan \n");
                                                    
                                                    goto ReplyCodeDebitCardTiga;
                                                }
                                                 
                                            }
                                        }
                                        while(DebitFail == 1);
                                        
                                        system("cls");
                                        printf("\n\t\t\t\t\t MarketKu\n");
                                        
                                        printf("\t=========================================================================\n");
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                                            switch(BuyMenu[forBuy]) {
                                                case 1:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                    
                                                case 2:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                case 3:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        printf("\t=========================================================================\n");
                                        
                                        
                                        printf("\t| %51s | %-15d |\n", "Total", totalPrice);
                            
                                        Discount == 0 ? printf("") : printf("\t| %51s | %-15d |\n", "Diskon", Discount);
                                        
                                        MemberOn == 1 ? printf("\t| %51s | %-15s |\n", "Member", "10%") : printf("");
                                        DebitPayment = DebitOn == 1 ? (totalPrice * 5) / 100 : 0;
                                        printf("\t| %51s | %-15s |\n", "Pajak", "10%");
                                        
                                        printf("\t| %51s | %-15s |\n", "Bank BNI", "5%");
                                        printf("\t| %51s | %-15d |\n", "Total Keseluruhan", finalTotalPrice - DebitPayment);
                                        printf("\t=========================================================================\n");
                                        
                                        printf("\n\n\t\t\t Terima Kasih, Selamat Belanja Kembali\n");
                                        printf("\t\t       ======= Layanan Konsumen MarketKu ======= \n");

                                        break;
                                    case 4:
                                        
                                        do {
                                            while (!return_value) {
                                                printf("Masukkan Kode Debit Card : ");
                                                return_value = scanf(" %d", &getCodeDebitCard);
                                                while(getchar() != '\n');
                                            }
                                            
                                            return_value = 0;
                                            
                                            for(forCode = 0; forCode < 5; forCode++) {
                                                if(getCodeDebitCard == codeDebitCard[forCode]) {
                                                    printf("\t| %86s | %-15d%% |\n", "Debit Card", 5);
                                                    DebitOn = 1;
                                                    DebitFail = 0;
                                                }
                                            }
                                            
                                            if(DebitFail == 1) {
                                                printf("Kode Debit Tidak Valid \n");
                                                
                                                ReplyCodeDebitCardEmpat:
                                                printf("Apakah Ingin Mengulangi Kode Debit ? (y/n)");
                                                scanf(" %c", &reCodeDebitCard);
                                                
                                                if(reCodeDebitCard == 'y' || reCodeDebitCard == 'Y') {
                                                    DebitFail = 1;
                                                    
                                                    reCodeDebitCard = '\0';
                                                
                                                } else if(reCodeDebitCard == 'n' || reCodeDebitCard == 'N') {
                                                    DebitFail = 1;
                                                    DebitOn = 0;
                                                    reCodeDebitCard = '\0';
                                                    goto DebitCardLabel;
                                                } else {
                                                    reCodeDebitCard = '\0';
                                                    printf("Tidak Ada Dalam Pilihan \n");
                                                    
                                                    goto ReplyCodeDebitCardEmpat;
                                                }
                                                 
                                            }
                                        }
                                        while(DebitFail == 1);
                                        
                                        system("cls");
                                        printf("\n\t\t\t\t\t MarketKu\n");
                                        
                                        printf("\t=========================================================================\n");
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                                            switch(BuyMenu[forBuy]) {
                                                case 1:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                    
                                                case 2:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                case 3:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        printf("\t=========================================================================\n");
                                        
                                        
                                        printf("\t| %51s | %-15d |\n", "Total", totalPrice);
                            
                                        Discount == 0 ? printf("") : printf("\t| %51s | %-15d |\n", "Diskon", Discount);
                                        
                                        MemberOn == 1 ? printf("\t| %51s | %-15s |\n", "Member", "10%") : printf("");
                                        DebitPayment = DebitOn == 1 ? (totalPrice * 5) / 100 : 0;
                                        printf("\t| %51s | %-15s |\n", "Pajak", "10%");
                                        
                                        printf("\t| %51s | %-15s |\n", "Bank BTN", "5%");
                                        printf("\t| %51s | %-15d |\n", "Total Keseluruhan", finalTotalPrice - DebitPayment);
                                        printf("\t=========================================================================\n");
                                        
                                        printf("\n\n\t\t\t Terima Kasih, Selamat Belanja Kembali\n");
                                        printf("\t\t       ======= Layanan Konsumen MarketKu ======= \n");
                                   
                                        break;
                                    default:
                                        printf("Tidak Ada Dalam Pilihan \n\n");
                                        goto DebitCardLabel;
                                }
                                break;
                            case 3:
                                CreditCardLabel:
                                printf("\t\t============================================ \n");
                                printf("\t\t| %-7s | %-30s | \n", "1." ,"Master Card");
                                printf("\t\t| %-7s | %-30s | \n", "2." ,"Visa");
                                printf("\t\t| %-7s | %-30s | \n", "3." ,"Paypal");
                                printf("\t\t| %-7s | %-30s | \n", "0." ,"Pergi ke Menu Sebelumnya");
                                printf("\t\t============================================ \n");
                                
                                while (!return_value) {
                                    printf("Masukkan Pilihan ? ");
                                    return_value = scanf(" %d", &getCreditCard);
                                    while(getchar() != '\n');
                                }
                                
                                return_value = 0;
                                
                                switch(getCreditCard) {
                                    case 0: 
                                        printf("\n\n");
                                        goto MethodPaymentLabel;
                                        break;
                                    case 1:
                                        
                                        do {
                                            while (!return_value) {
                                                printf("Masukkan Kode Credit Card : ");
                                                return_value = scanf(" %d", &getCodeCreditCard);
                                                while(getchar() != '\n');
                                            }
                                            
                                            return_value = 0;
                                            
                                            for(forCode = 0; forCode < 5; forCode++) {
                                                if(getCodeCreditCard == codeCreditCard[forCode]) {
                                                    printf("\t| %86s | %-15d%% |\n", "Credit Card", 5);
                                                    CreditOn = 1;
                                                    CreditFail = 0;
                                                }
                                            }
                                            
                                            if(CreditFail == 1) {
                                                printf("Kode Kredit Tidak Valid \n");
                                                
                                                ReplyCodeCreditCardSatu:
                                                printf("Apakah Ingin Mengulangi Kode Kredit ? (y/n)");
                                                scanf(" %c", &reCodeCreditCard);
                                                
                                                if(reCodeCreditCard == 'y' || reCodeCreditCard == 'Y') {
                                                    CreditFail = 1;
                                                    
                                                    reCodeCreditCard = '\0';
                                                
                                                } else if(reCodeCreditCard == 'n' || reCodeCreditCard == 'N') {
                                                    CreditFail = 1;
                                                    CreditOn = 0;
                                                    reCodeCreditCard = '\0';
                                                    goto CreditCardLabel;
                                                } else {
                                                    reCodeCreditCard = '\0';
                                                    printf("Tidak Ada Dalam Pilihan \n");
                                                    
                                                    goto ReplyCodeCreditCardSatu;
                                                }
                                                 
                                            }
                                        }
                                        while(CreditFail == 1);
                                        
                                        
                                        system("cls");
                                        printf("\n\t\t\t\t\t MarketKu\n");
                                        
                                        printf("\t=========================================================================\n");
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                                            switch(BuyMenu[forBuy]) {
                                                case 1:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                    
                                                case 2:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                case 3:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        printf("\t=========================================================================\n");
                                        
                                        
                                        printf("\t| %51s | %-15d |\n", "Total", totalPrice);
                            
                                        Discount == 0 ? printf("") : printf("\t| %51s | %-15d |\n", "Diskon", Discount);
                                        
                                        MemberOn == 1 ? printf("\t| %51s | %-15s |\n", "Member", "10%") : printf("");
                                        CreditPayment = CreditOn == 1 ? (totalPrice * 5) / 100 : 0;
                                        printf("\t| %51s | %-15s |\n", "Pajak", "10%");
                                        
                                        printf("\t| %51s | %-15s |\n", "Master Card", "5%");
                                        printf("\t| %51s | %-15d |\n", "Total Keseluruhan", finalTotalPrice - CreditPayment);
                                        printf("\t=========================================================================\n");
                                        
                                        printf("\n\n\t\t\t Terima Kasih, Selamat Belanja Kembali\n");
                                        printf("\t\t       ======= Layanan Konsumen MarketKu ======= \n");
                                        break;
                                    case 2:
                                        
                                        do {
                                            while (!return_value) {
                                                printf("Masukkan Kode Credit Card : ");
                                                return_value = scanf(" %d", &getCodeCreditCard);
                                                while(getchar() != '\n');
                                            }
                                            
                                            return_value = 0;
                                            
                                            for(forCode = 0; forCode < 5; forCode++) {
                                                if(getCodeCreditCard == codeCreditCard[forCode]) {
                                                    printf("\t| %86s | %-15d%% |\n", "Credit Card", 5);
                                                    CreditOn = 1;
                                                    CreditFail = 0;
                                                }
                                            }
                                            
                                            if(CreditFail == 1) {
                                                printf("Kode Kredit Tidak Valid \n");
                                                
                                                ReplyCodeCreditCardDua:
                                                printf("Apakah Ingin Mengulangi Kode Kredit ? (y/n)");
                                                scanf(" %c", &reCodeCreditCard);
                                                
                                                if(reCodeCreditCard == 'y' || reCodeCreditCard == 'Y') {
                                                    CreditFail = 1;
                                                    
                                                    reCodeCreditCard = '\0';
                                                
                                                } else if(reCodeCreditCard == 'n' || reCodeCreditCard == 'N') {
                                                    CreditFail = 1;
                                                    CreditOn = 0;
                                                    reCodeCreditCard = '\0';
                                                    goto CreditCardLabel;
                                                } else {
                                                    reCodeCreditCard = '\0';
                                                    printf("Tidak Ada Dalam Pilihan \n");
                                                    
                                                    goto ReplyCodeCreditCardDua;
                                                }
                                                 
                                            }
                                        }
                                        while(CreditFail == 1);
//                                        
                                        system("cls");
                                        printf("\n\t\t\t\t\t MarketKu\n");
                                        
                                        printf("\t=========================================================================\n");
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                                            switch(BuyMenu[forBuy]) {
                                                case 1:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                    
                                                case 2:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                case 3:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        printf("\t=========================================================================\n");
                                        
                                        
                                        printf("\t| %51s | %-15d |\n", "Total", totalPrice);
                            
                                        Discount == 0 ? printf("") : printf("\t| %51s | %-15d |\n", "Diskon", Discount);
                                        
                                        MemberOn == 1 ? printf("\t| %51s | %-15s |\n", "Member", "10%") : printf("");
                                        CreditPayment = CreditOn == 1 ? (totalPrice * 5) / 100 : 0;
                                        printf("\t| %51s | %-15s |\n", "Pajak", "10%");
                                        
                                        printf("\t| %51s | %-15s |\n", "Visa", "5%");
                                        printf("\t| %51s | %-15d |\n", "Total Keseluruhan", finalTotalPrice - CreditPayment);
                                        printf("\t=========================================================================\n");
                                        
                                        printf("\n\n\t\t\t Terima Kasih, Selamat Belanja Kembali\n");
                                        printf("\t\t       ======= Layanan Konsumen MarketKu ======= \n");

                                        break;
                                    case 3:
                                        
                                        do {
                                            while (!return_value) {
                                                printf("Masukkan Kode Credit Card : ");
                                                return_value = scanf(" %d", &getCodeCreditCard);
                                                while(getchar() != '\n');
                                            }
                                            
                                            return_value = 0;
                                            
                                            for(forCode = 0; forCode < 5; forCode++) {
                                                if(getCodeCreditCard == codeCreditCard[forCode]) {
                                                    printf("\t| %86s | %-15d%% |\n", "Credit Card", 5);
                                                    CreditOn = 1;
                                                    CreditFail = 0;
                                                }
                                            }
                                            
                                            if(CreditFail == 1) {
                                                printf("Kode Kredit Tidak Valid \n");
                                                
                                                ReplyCodeCreditCardTiga:
                                                printf("Apakah Ingin Mengulangi Kode Kredit ? (y/n)");
                                                scanf(" %c", &reCodeCreditCard);
                                                
                                                if(reCodeCreditCard == 'y' || reCodeCreditCard == 'Y') {
                                                    CreditFail = 1;
                                                    
                                                    reCodeCreditCard = '\0';
                                                
                                                } else if(reCodeCreditCard == 'n' || reCodeCreditCard == 'N') {
                                                    CreditFail = 1;
                                                    CreditOn = 0;
                                                    reCodeCreditCard = '\0';
                                                    goto CreditCardLabel;
                                                } else {
                                                    reCodeCreditCard = '\0';
                                                    printf("Tidak Ada Dalam Pilihan \n");
                                                    
                                                    goto ReplyCodeCreditCardTiga;
                                                }
                                                 
                                            }
                                        }
                                        while(CreditFail == 1);
                                        
                                        system("cls");
                                        printf("\n\t\t\t\t\t MarketKu\n");
                                        
                                        printf("\t=========================================================================\n");
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                                            switch(BuyMenu[forBuy]) {
                                                case 1:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                    
                                                case 2:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                                case 3:
                                                    for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                                        if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                                            printf("\t| %-30s | %-5d | %-10d | %-15d |\n", namaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                                        }
                                                    }
                                                    break;
                                            }
                                        }
                                        printf("\t| %-30s | %-5s | %-10s | %-15s |\n", "", "", "", "");
                                        printf("\t=========================================================================\n");
                                        
                                        
                                        printf("\t| %51s | %-15d |\n", "Total", totalPrice);
                            
                                        Discount == 0 ? printf("") : printf("\t| %51s | %-15d %% |\n", "Diskon", Discount);
                                        
                                        MemberOn == 1 ? printf("\t| %51s | %-15s |\n", "Member", "10%") : printf("");
                                        CreditPayment = CreditOn == 1 ? (totalPrice * 5) / 100 : 0;
                                        printf("\t| %51s | %-15s |\n", "Pajak", "10%");
                                        
                                        printf("\t| %51s | %-15s |\n", "Paypal", "5%");
                                        printf("\t| %51s | %-15d |\n", "Total Keseluruhan", finalTotalPrice - CreditPayment);
                                        printf("\t=========================================================================\n");
                                        
                                        printf("\n\n\t\t\t Terima Kasih, Selamat Belanja Kembali\n");
                                        printf("\t\t       ======= Layanan Konsumen MarketKu ======= \n");

                                        break;
                                    default:
                                        printf("Tidak Ada Dalam Pilihan \n\n");
                                        goto CreditCardLabel;
                                }
                                break;
                            default:
                                printf("Tidak Ada Dalam Pilihan \n");
                                goto MethodPaymentLabel;
                        }
                        
                    } else if (getPayment == 'n' || getPayment == 'N') {
                        MemberOn = 0;
                        totalPrice = 0;
                        goto MenuMore;
                    } else {
                        getPayment = '\0';
                        printf("Tidak Ada Dalam Pilihan \n");
                        goto PaymentLabel;
                    }
                    
                    break;
                case 4:
                    if(BuyCount < 1) {
                        system("cls");
                        printf("\nItem Yang Ada Ambil Tidak Ada \n\n");
                        goto MenuMoreFail;
                    }
                    system("cls");
                    printf("\n");
                    totalPriceInvent = 0;
                    printf("\n\t\t\t\t       Daftar Barang Yang Diambil \n");
                    printf("\t======================================================================================================= \n");
                    printf("\t| %-7s | %-17s | %-30s | %-10s | %-10s | %-10s | \n", "Kode", "Nama Menu", "Nama Barang","Harga", "Jumlah", "Total");
                    printf("\t| %-7s | %-17s | %-30s | %-10s | %-10s | %-10s | \n", "", "", "", "", "", "");
                    for(forBuy = 0; forBuy < BuyCount; forBuy++) {
                        switch(BuyMenu[forBuy]) {
                            case 1:
                                for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                    if(BuyCode[forBuy] == codeItemMakanan[forGetBuy]) {
                                        printf("\t| %-7d | %-17s | %-30s | %-10d | %-10d | %-10d | \n", codeItemMakanan[forGetBuy], "Makanan" ,namaItemMakanan[forGetBuy], hargaItemMakanan[forGetBuy], BuyTotal[forBuy], hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                        totalPriceInvent = totalPriceInvent + (hargaItemMakanan[forGetBuy] * BuyTotal[forBuy]);
                                    }
                                }
                                break;
                                
                            case 2:
                                for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                    if(BuyCode[forBuy] == codeItemMinuman[forGetBuy]) {
                                        printf("\t| %-7d | %-17s | %-30s | %-10d | %-10d | %-10d | \n", codeItemMinuman[forGetBuy], "Minuman", namaItemMinuman[forGetBuy], hargaItemMinuman[forGetBuy], BuyTotal[forBuy], hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                        totalPriceInvent = totalPriceInvent + (hargaItemMinuman[forGetBuy] * BuyTotal[forBuy]);
                                    }
                                }
                                break;
                            case 3:
                                for(forGetBuy = 0; forGetBuy < 10; forGetBuy++) {
                                    if(BuyCode[forBuy] == codeItemKebutuhanPokok[forGetBuy]) {
                                        printf("\t| %-7d | %-17s | %-30s | %-10d | %-10d | %-10d \n", codeItemKebutuhanPokok[forGetBuy], "Kebutuhan Pokok", namaItemKebutuhanPokok[forGetBuy], hargaItemKebutuhanPokok[forGetBuy], BuyTotal[forBuy], hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                        totalPriceInvent = totalPriceInvent + (hargaItemKebutuhanPokok[forGetBuy] * BuyTotal[forBuy]);
                                    }
                                }
                                break;
                        }
                    }
                    printf("\t======================================================================================================= \n");

                    printf("\t| %86s | %-10d |\n", "Total", totalPriceInvent);
                    printf("\t======================================================================================================= \n");
                    DetailInvent:
                    printf("\n\t\t====================================================== \n");
                    printf("\t\t| %-7s | %-40s | \n", "1." ,"Pergi Ke Menu Sebelumnya");
                    printf("\t\t| %-7s | %-40s | \n", "2." ,"Kurangi Jumlah Yang Diambil");
                    printf("\t\t| %-7s | %-40s | \n", "3." ,"Batalkan Barang");
                    printf("\t\t====================================================== \n");
                    
                    while (!return_value) {
                        printf("Masukkan Pilihan ? ");
                        return_value = scanf(" %d", &getDetailInvent);
                        while(getchar() != '\n');
                    }
                    
                    return_value = 0;
                    
                    switch(getDetailInvent) {
                        case 1:
                            system("cls");
                            goto MenuMore;
                            break;
                        case 2:
                            ReplyCodeReduceQty:
                            
                            while (!return_value) {
                                printf("Masukkan Kode Barang Yang Akan Di Kurangi Jumlahnya : ");
                                return_value = scanf(" %d", &getRemoveItem);
                                while(getchar() != '\n');
                            }
                            
                            return_value = 0;
                            
                            for(forRemove = 0; forRemove < BuyCount; forRemove++) {
                                if(BuyCode[forRemove] == getRemoveItem) {
                                    
                                    ReduceQty:
                                    
                                    while (!return_value) {
                                       printf("Masukkan Jumlah Yang Akan Dikurangi : ");
                                        return_value = scanf(" %d", &getReduceItem);
                                        while(getchar() != '\n');
                                    }
                                    
                                    return_value = 0;
                                    
                                    if(getReduceItem <= 0) {
                                        printf("Jumlah Yang Akan Dikurangi Tidak Boleh Kurang Dari Sama Dengan 0 \n\n");
                                        
                                        goto ReduceQty;
                                    }
                                    
                                    if(getReduceItem > BuyTotal[forRemove]) {
                                        printf("Jumlah Yang Akan Dikurangi Melebihi Jumlah Yang Ada \n\n");
                                        
                                        goto ReduceQty;
                                    
                                    } else if (getReduceItem == BuyTotal[forRemove]) {
                                        printf("Jumlah Yang Akan Dikurangi Sama Dengan Jumlah Yang Ada \n Pembatalan Barang Otomatis Dilakukan \n\n");
                                        
                                        for(forRemoveBuy = forRemove; forRemoveBuy < BuyCount - 1; forRemoveBuy++) {
                                            BuyCode[forRemoveBuy] = BuyCode[forRemoveBuy + 1];
                                        }
                                        
                                        for(forRemoveBuy = forRemove; forRemoveBuy < BuyCount - 1; forRemoveBuy++) {
                                            BuyMenu[forRemoveBuy] = BuyMenu[forRemoveBuy + 1];
                                        }
                                        
                                        for(forRemoveBuy = forRemove; forRemoveBuy < BuyCount - 1; forRemoveBuy++) {
                                            BuyTotal[forRemoveBuy] = BuyTotal[forRemoveBuy + 1];
                                        }
                                        
                                        BuyCount = BuyCount - 1;
                                        system("cls");
                                        printf("Item Berhasil Di Kurangi Dan Di Batalkan \n");
                                        
                                        goto MenuMore;
                                    }
                                    
                                    BuyTotal[forRemove] = BuyTotal[forRemove] - getReduceItem;                    
                                    system("cls");
                                    printf("Item Berhasil Di Kurangi Jumlahnya \n");
                                    
                                    goto MenuMore;
                                }
                            }
                            
                            printf("Kesalahan Kode Barang Yang Dimasukkan \n");
                            
                            ReplyReduceQty:
                            printf("Apakah Anda Ingin Memasukkan Ulang ? (y/n) ");
                            scanf(" %c", &reRemove);
                            
                            if(reRemove == 'y' || reRemove == 'Y') {
                                reRemove = '\0';
                                goto ReplyCodeReduceQty;
                            
                            } else if(reRemove == 'n' || reRemove == 'N') {
                                reRemove = '\0';
                                goto DetailInvent;
                            } else {
                                reRemove = '\0';
                                printf("Tidak Ada Dalam Pilihan \n");
                                goto ReplyReduceQty;
                            }
                            break;
                        case 3:
                            ReplyCodeRemove:
                            
                            while (!return_value) {
                                printf("Masukkan Kode Barang Yang Akan Di Batalkan : ");
                                return_value = scanf(" %d", &getRemoveItem);
                                while(getchar() != '\n');
                            }
                            
                            return_value = 0;
                    
                            for(forRemove = 0; forRemove < BuyCount; forRemove++) {
                                if(BuyCode[forRemove] == getRemoveItem) {
                                    for(forRemoveBuy = forRemove; forRemoveBuy < BuyCount - 1; forRemoveBuy++) {
                                        BuyCode[forRemoveBuy] = BuyCode[forRemoveBuy + 1];
                                    }
                                    
                                    for(forRemoveBuy = forRemove; forRemoveBuy < BuyCount - 1; forRemoveBuy++) {
                                        BuyMenu[forRemoveBuy] = BuyMenu[forRemoveBuy + 1];
                                    }
                                    
                                    for(forRemoveBuy = forRemove; forRemoveBuy < BuyCount - 1; forRemoveBuy++) {
                                        BuyTotal[forRemoveBuy] = BuyTotal[forRemoveBuy + 1];
                                    }
                                    
                                    BuyCount = BuyCount - 1;
                                    system("cls");
                                    printf("Item Berhasil Di Batalkan \n");
                                    
                                    goto MenuMore;
                                }
                            }
                            
                            printf("Kesalahan Kode Barang Yang Dimasukkan \n");
                            
                            ReplyRemove:
                            printf("Apakah Anda Ingin Memasukkan Ulang ? (y/n) ");
                            scanf(" %c", &reRemove);
                            
                            if(reRemove == 'y' || reRemove == 'Y') {
                                reRemove = '\0';
                                goto ReplyCodeRemove;
                            
                            } else if(reRemove == 'n' || reRemove == 'N') {
                                reRemove = '\0';
                                goto DetailInvent;
                            } else {
                                reRemove = '\0';
                                printf("Tidak Ada Dalam Pilihan \n");
                                goto ReplyRemove;
                            }
                            
                            break;
                        default :
                            printf("Menu Hanya Ada Dari 1 - 4 \n");
                            goto DetailInvent;
                            break;
                    }
                    break;
                    
                default:
                    system("cls");
                    printf("Menu Hanya Ada Dari 1 - 4 \n");
                    printf("\nApakah Anda Ingin Menambah Item Lagi ? \n");
                    goto MenuMoreFail;
            }
            break;
        case 2:
            system("cls");
            MemberMenusLabel:
            printf("\n\t\t====================================================== \n");
            printf("\t\t| %-7s | %-40s | \n", "1." ,"Daftar Member");
            printf("\t\t| %-7s | %-40s | \n", "2." ,"Lihat Data Member");
            printf("\t\t| %-7s | %-40s | \n", "3." ,"Kembali Ke Menu Sebelumnya");
            printf("\t\t====================================================== \n");
            
            while (!return_value) {
                printf("Masukkan Pilihan ? ");
                return_value = scanf(" %d", &getMemberMenu);
                while(getchar() != '\n');
            }
            
            return_value = 0;
            
            switch(getMemberMenu) {
                case 1:
                    system("cls");
                    printf("\nMasukkan Nama Anda : ");
                    scanf(" %[^\n]%*c", getName);
                    printf("Masukkan Alamat Anda : ");
                    scanf(" %[^\n]%*c", getAddress);
                    randomCode = rand() % 10000;
                    
                    printf("Kode Anda : %d \n", randomCode);
                    
                    codeMember[MemberCountDefault] = randomCode;
                    discountCodeMember[MemberCountDefault] = 5;
                    
                    MemberCountDefault = MemberCountDefault + 1;
                    
                    printf("Data Member Berhasil Dibuat ");
   
                    goto MemberMenusLabel;
                    break;
                case 2:
                    system("cls");
                    printf("\n");
                    printf("\n\t\t========================\n");
                    printf("\t\t| %-10s | %-5s  | \n", "Kode" ,"Diskon");
                    for(forMemberList = 0; forMemberList < MemberCountDefault; forMemberList++) {
                        printf("\t\t| %-10d | %-5d %% | \n", codeMember[forMemberList], discountCodeMember[forMemberList]);
                    }
                    printf("\t\t========================\n");
                    
                    goto MemberMenusLabel;
                    break;
                case 3:
                    system("cls");
                    goto MenuUtama;
                    break;
                default:
                    printf("Menu Hanya Ada Dari 1 - 3 \n\n");
                    goto MemberMenusLabel;
            }
            
            break;
        default:
            printf("Pilihan Hanya Ada 0, 1 dan 2 \n\n");
            goto MenuUtama;
    }
    
    return 0;
}