#include "header.h"

void entri_staff_display(ListStaff S)
{
	int x0=13,y0=13;
	int x1=20,y1=13;
	int x2=55,y2=13;
	int i=1;
		system("cls");
		setcolor(0,7);
		gotoxy(10,0);cout<<"                                      PEMINJAMAN MOBIL PT. XXXXX                                     "<<endl;
		gotoxy(10,1);cout<<"                                                                                                     "<<endl;
		gotoxy(10,2);cout<<"                                       SUB MENU ENTRI - STAFF                                        "<<endl;
		setcolor(0,0);

		setcolor(0,15);
		gotoxy(10,4);cout<<"                                                                                                     "<<endl;
		gotoxy(10,5);cout<<"                             Selamat Datang Di Aplikasi Peminjaman Mobil                             "<<endl;
		gotoxy(10,6);cout<<"                                                                                                     "<<endl;
		gotoxy(10,7);cout<<"                            Ini Adalah Data Staff yang sudah di daftarkan                            "<<endl;
		gotoxy(10,8);cout<<"                                                                                                     "<<endl;
		gotoxy(10,9);cout<<" =================================================================================================== "<<endl;
		gotoxy(10,10);cout<<" = NO =             NIP                 =                          NAMA                            = "<<endl;
		gotoxy(10,11);cout<<" =================================================================================================== "<<endl;
		gotoxy(10,12);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,13);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,14);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,15);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,16);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,17);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,18);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,19);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,20);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,21);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,22);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,23);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,24);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,25);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,26);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,27);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,28);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,29);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,30);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,31);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,32);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,33);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,34);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,35);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,36);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,37);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,38);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,39);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,40);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,41);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,42);cout<<" =    =                                 =                                                          = "<<endl;
		gotoxy(10,43);cout<<" =================================================================================================== "<<endl;
		footer_menu_entri();
		if(IsEmpty_Staff(S))
		{
			setcolor(0,15);
			gotoxy(28,22);cout<<"Data Kosong"<<endl;
			gotoxy(75,22);cout<<"Data Kosong"<<endl;
		}
		else
		{
			while(S.First!=NULL)
			{
				setcolor(0,15);
				gotoxy(x0,y0);cout<<i<<endl;
				gotoxy(x1,y1);cout<<S.First->Data.NIP<<endl;
				gotoxy(x2,y2);cout<<S.First->Data.Nama<<endl;
				S.First=S.First->Next;
				i++;
				y0=y0+2;
				y1=y1+2;
				y2=y2+2;
			}
		}

}