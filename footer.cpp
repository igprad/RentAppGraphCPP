#include "header.h"


void footer1()
{
		setcolor(0,7);
		gotoxy(10,48);cout<<"                                                                                                     "<<endl;
		gotoxy(10,49);cout<<"            ESC = EXIT               ARROW KEY = BERGERAK          ENTER = PILIH MENU                "<<endl;
		gotoxy(10,50);cout<<"                                                                                                     "<<endl;
		setcolor(0,0);
}

void footer2()
{
		setcolor(0,7);
		gotoxy(10,48);cout<<"                                                                                                     "<<endl;
		gotoxy(10,49);cout<<"      ESC = KEMBALI KE MENU UTAMA         ARROW KEY = BERGERAK          ENTER = PILIH MENU           "<<endl;
		gotoxy(10,50);cout<<"                                                                                                     "<<endl;
		setcolor(0,0);
}

void footer_menu_entri()
{
		setcolor(0,7);
		gotoxy(0,0);cout<<"                                                                                                                        "<<endl;
		gotoxy(0,1);cout<<"                   ESC=KEMBALI KE INPUT        ENTER=TAMBAH        F1=HELP       F2=EDIT      F3=HAPUS                  "<<endl;
		gotoxy(0,2);cout<<"                                                                                                                        "<<endl;
		setcolor(0,0);
}

void footer_menu_pinjam()
{
		setcolor(0,7);
		gotoxy(0,0);cout<<"                                                                                                                        "<<endl;
		gotoxy(0,1);cout<<"                     ESC=KEMBALI KE INPUT       ENTER=TAMBAH         F1=HELP          F3=PENGEMBALIAN                   "<<endl;
		gotoxy(0,2);cout<<"                                                                                                                        "<<endl;
		setcolor(0,0);
}

void footer_menu_pengembalian()
{
		setcolor(0,7);
		gotoxy(0,0);cout<<"                                                                                                                        "<<endl;
		gotoxy(0,1);cout<<"                               ESC=KEMBALI KE PEMINJAMAN                ENTER=KEMBALIKAN/HAPUS                          "<<endl;
		gotoxy(0,2);cout<<"                                                                                                                        "<<endl;
		setcolor(0,0);
}




void footer_menu_laporan_staff()
{
		setcolor(0,7);
		gotoxy(0,0);cout<<"                                                                                                                        "<<endl;
		gotoxy(0,1);cout<<"                          ESC=KEMBALI KE LAPORAN            F1=URUT NIP            F3=URUT NAMA                         "<<endl;
		gotoxy(0,2);cout<<"                                                                                                                        "<<endl;
		setcolor(0,0);
}

void footer_menu_laporan_mobil()
{
		setcolor(0,7);
		gotoxy(0,0);cout<<"                                                                                                                        "<<endl;
		gotoxy(0,1);cout<<"                          ESC=KEMBALI KE LAPORAN            F1=URUT PLAT          F3=URUT MERK                          "<<endl;
		gotoxy(0,2);cout<<"                                                                                                                        "<<endl;
		setcolor(0,0);
}

void footer_menu_laporan_peminjaman()
{
		setcolor(0,7);
		gotoxy(0,0);cout<<"                                                                                                                        "<<endl;
		gotoxy(0,1);cout<<"                ESC=KEMBALI KE LAPORAN        ENTER=LAPORAN SEORANG STAFF      F1=LAPORAN JUMLAH PEMINJAMAN             "<<endl;
		gotoxy(0,2);cout<<"                                                                                                                        "<<endl;
		setcolor(0,0);
}