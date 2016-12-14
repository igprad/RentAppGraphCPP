#include <iostream.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#define BAWAH 256+80
#define ATAS 256+72
#define KIRI 256+75
#define KANAN 256+77
#define ESC 27
#define ENTER 13
#define F1 59
#define F2 60
#define F3 61
#define F10 68


typedef char string[20];

typedef struct{
	int jumlah;
	int NIP;
}JumPinjam;

typedef struct{
	int NIP;
	string Nama;
}Staff;

typedef struct{
	string No_Plat;
	string Merk;
}Mobil;

typedef struct{
	int NIP_Pinjam;
	string Nama_Pinjam;
	string No_Plat_Pinjam;
	string Merk_Pinjam;
}Pinjam;

typedef struct NodeJumPinjam *address;

typedef struct NodeStaff *address1;

typedef struct NodeMobil *address2;

typedef struct NodePinjam *address3;

typedef struct NodeJumPinjam{
	JumPinjam Data;
	address Next;
}NodeJumPinjam;

typedef struct NodeStaff{
	Staff Data;
	address1 Next;
}NodeStaff;

typedef struct NodeMobil{
	Mobil Data;
	address2 Next;
}NodeMobil;

typedef struct NodePinjam{
	Pinjam data;
	address3 Next;
}NodePinjam;

typedef struct{
	address First;
}ListJumlah;

typedef struct{
	address1 First;
}ListStaff;

typedef struct{
	address2 First;
}ListMobil;

typedef struct{
	address3 First;
}ListPinjam;

//graphics
int readKey();
void setScreenSize(int x, int y);
void gotoxy(int x,int y);
void setcolor(char text,char latar);
void main_menu();
void main_menu_selected1();
void main_menu_selected4();
void sub_menu_entri();
void sub_menu_hapus();
void sub_menu_edit();
void sub_menu_laporan();
void footer1();
void footer2();
void footer_menu_entri();
void footer_menu_pinjam();
void footer_menu_pengembalian();
void footer_menu_laporan_staff();
void footer_menu_laporan_mobil();
void footer_menu_laporan_peminjaman();

void sub_menu_entri_selected1();
void sub_menu_entri_selected2();
void sub_menu_entri_selected3();
void sub_menu_laporan_selected1();
void sub_menu_laporan_selected2();
void sub_menu_laporan_selected3();

void exit_display();

//================================================================

void laporan_staff_display(ListStaff S,int key);
void laporan_mobil_display(ListMobil M,int key);
void laporan_peminjaman_display(ListPinjam P,int key);
void laporan_peminjaman_jumlah(ListJumlah J,int key);

//================================================================
void entri_staff_display(ListStaff S);
void entri_mobil_display(ListMobil M);
void entri_pinjam_display(ListPinjam P);
void pop_up_entri_staff(ListStaff &S,Staff DataStaff,int key);
void pop_up_entri_Mobil(ListMobil &M,Mobil DataMobil,int key);
void pop_up_entri_pinjam(ListPinjam &P,ListStaff S,ListMobil M,string pil_entri,int entri_nip,int key);
void pop_up_help_staff();
void pop_up_help_mobil();
void pop_up_help_peminjaman();
void pop_up_kosong_data();
void pop_up_kurang_data();
void pop_up_ketentuan_mobil();
void pop_up_pinjam_list_tersedia(ListPinjam P,ListStaff S,ListMobil M,int key);
void pop_up_hapus_pinjam(ListPinjam &P,ListStaff S,ListMobil M,string pil_entri,int entri_nip,int key);
void pop_up_peminjaman_staff(ListPinjam P,int &entri_nip,int key);
void pop_up_peminjaman_staff_display(ListPinjam P,int entri_nip,int key);

void switch_case_entri_staff(ListJumlah &J,ListPinjam &P,int entri_nip,string pil_entri,int &pil,string &sub_menu_status,int key,Staff DataStaff,Mobil DataMobil,ListStaff &S,ListMobil &M,char status_menu);
void edit_staff_display(ListStaff &S,int key,ListPinjam P);
void edit_mobil_display(ListMobil &M,int key,ListPinjam P);
void hapus_staff_display(ListStaff &S,int key,ListPinjam P);
void hapus_mobil_display(ListMobil &M,int key,ListPinjam P);
void pengembalian_display(ListPinjam P,ListMobil M,ListStaff S,int key);

//fungsionalitas
void create_empty_jumlah(ListJumlah &J);
void create_empty_pinjam(ListPinjam &P);
void create_empty_mobil(ListMobil &M);
void create_empty_staff(ListStaff &S);
void entri_mobil(ListMobil &M,Mobil data);
void entri_staff(ListStaff &S,Staff data);
void edit_staff(ListStaff &S,int NIP);
void edit_mobil(ListMobil &M,string plat);
void del_staff(ListStaff &S,int NIP);
void del_mobil(ListMobil &M,string plat);
void dealokasi_staff(address1 staff);
void dealokasi_mobil(address2 mobil);
void pinjam(ListPinjam &P,ListStaff S,ListMobil M,int NIP,string plat);
void pengembalian(ListPinjam &P,int NIP,string plat);
void getMenu(char &status_menu, int &key);
void getSubMenu_Entri(string &status_menu, int &key);
void getSubMenu_Laporan(string &status_menu, int &key);
void SubMenu_Entri_Enter(ListPinjam &P,int entri_nip,string pil_entri,ListMobil &M,ListStaff &S,int &key,char status_menu,Staff DataStaff,Mobil DataMobil,int &pil,string &sub_menu_status);
void SubMenu_Laporan_Enter(ListJumlah &J,ListPinjam &P,int entri_nip,string pil_entri,ListMobil &M,ListStaff &S,int &key,char status_menu,Staff DataStaff,Mobil DataMobil,int &pil,string &sub_menu_status);

//laporan
void laporan_mobil_urut_merk(ListMobil &M);
void laporan_mobil_urut_plat(ListMobil &M);
void laporan_staff_urut_NIP(ListStaff &S);
void laporan_staff_urut_nama(ListStaff &S);
void laporan_pinjam_urut_NIP(ListPinjam &P);
void laporan_jumlah_peminjaman_tiap_staff_urut_terbesar(ListPinjam P,ListJumlah &J);
void tampil_laporanPinjam_perStaff(ListPinjam P,int NIP);
void show_mobil(ListMobil M);
void show_staff(ListStaff S);
void show_pinjam(ListPinjam P);


//fungsi-penting
address alokasi_jumlah(JumPinjam data);
address1 search_staff(ListStaff S,Staff data);
address1 alokasi_staff(Staff data);
address2 search_mobil(ListMobil M,Mobil data);
address2 alokasi_mobil(Mobil data);
address3 alokasi_pinjam(Pinjam data);
bool IsEmpty_Mobil(ListMobil M);
bool IsEmpty_Staff(ListStaff S);
bool IsEmpty_Peminjaman(ListPinjam P);
bool CekMerkLolos(Mobil data);
bool isOne_pinjam(ListPinjam P);

//kondisi
bool CekPlatLolos(string plat);
bool isFound_Staff(ListStaff S,int NIP);
bool isFound_Mobil(ListMobil M,string plat);
bool isFound_Staff_onPinjam(ListPinjam P,int NIP);
bool isFound_Mobil_onPinjam(ListPinjam P,string plat);
bool isLessData_Peminjaman(ListPinjam P,ListMobil M);
bool valid_input_string(string input);

