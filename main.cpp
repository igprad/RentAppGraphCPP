#include "header.h"

void main()
{
	int pil;
	int key;
	int entri_nip=0;
	char status_menu;
	string sub_menu_status;
	string pil_entri;
	Staff DataStaff;
	strcpy(DataStaff.Nama,"-");
	Mobil DataMobil;
	strcpy(DataMobil.Merk,"-");
	ListStaff S;
	ListMobil M;
	ListPinjam P;
	ListJumlah J;
	create_empty_pinjam(P);
	create_empty_mobil(M);
	create_empty_staff(S);
	//system("mode CON: COLS=120");
	system("mode 120,52");
	do{
		
		setcolor(0,0);
		strcpy(sub_menu_status,"NULL");
		status_menu='0';
		main_menu();
		getMenu(status_menu,key);
		switch_case_entri_staff(J,P,entri_nip,pil_entri,pil,sub_menu_status,key,DataStaff,DataMobil,S,M,status_menu);
		switch(pil)
		{		
		case 0: exit_display();getch();break;
		case 20: break;
		}
	}while(pil!=0);
}