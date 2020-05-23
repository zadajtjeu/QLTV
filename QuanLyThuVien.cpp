#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

/*
 * Nhom11 - KTPM3 - K13
 * KHOA CNTT - DHCNHN - HAUI
 * Warning: Khong xoa ban quyen!
*/

class Date
{
	int dd,mm,yyyy;
public:
	void input()
	{
		scanf("%d/%d/%d", &dd, &mm, &yyyy);
		fflush(stdin);
	}
	void output()
	{
		cout<<setw(5)<<right<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<yyyy<<setw(5)<<" ";
	}
};

class DocGia
{
	char MaDG[10];
	char MaSV[10];
	char HoTenDG[50];
	Date NgaySinh;
	char NoiSinh[30];
	char Lop[20];
	int Nam;
	Date NgayLT;
	Date NgayHH;
public:
	void insertDG()
	{
		system("cls");
		cout<<"\tTHEM DOC GIA\n";
		cout<<" - Nhap ma doc gia: ";
		gets(MaDG);
		cout<<" - Nhap ma sinh vien: ";
		gets(MaSV);
		cout<<" - Nhap ho ten doc gia: ";
		gets(HoTenDG);
		cout<<" - Nhap ngay sinh (dd/mm/yyyy): ";
		NgaySinh.input();
		cout<<" - Nhap noi sinh: ";
		gets(NoiSinh);
		cout<<" - Nhap lop: ";
		gets(Lop);
		cout<<" - Nhap nam vao hoc: ";
		cin>>Nam;
		cout<<" - Nhap ngay lap the (dd/mm/yyyy): ";
		NgayLT.input();
		cout<<" - Nhap ngay ht han cua the (dd/mm/yyyy): ";
		NgayHH.input();
	}

	void showDG()
	{
		cout<<setw(10)<<left<<MaDG;
		cout<<setw(10)<<MaSV;
		cout<<setw(30)<<HoTenDG;
		NgaySinh.output();
		cout<<setw(20)<<left<<NoiSinh;
		cout<<setw(10)<<Lop;
		cout<<setw(10)<<Nam;
		NgayLT.output();
		NgayHH.output();
		cout<<endl;
	}

	void editDG()
	{
		showDG();
		cout<<"\tSUA DOC GIA \n";
		cout<<" - Sua ho ten doc gia: ";
		gets(HoTenDG);
		cout<<" - Sua ngay sinh (dd/mm/yyyy): ";
		NgaySinh.input();
		cout<<" - Sua noi sinh: ";
		gets(NoiSinh);
		cout<<" - Sua lop: ";
		gets(Lop);
		cout<<" - Sua nam vao hoc: ";
		cin>>Nam;
		cout<<" - Sua ngay lap the (dd/mm/yyyy): ";
		NgayLT.input();
		cout<<" - Sua ngay ht han cua the (dd/mm/yyyy): ";
		NgayHH.input();
	}
	char* getMaDG()
	{
		return MaDG;
	}
};

class Sach
{
	char MaS[10];
	char TenS[100];
	char NXB[50];
	int namXB;
	char TG[50];
	char TheLoai[50];
	int soluong;
	long long GiaTien;
public:
	void insertSach()
	{
		system("cls");
		cout<<"\tTHEM SACH\n";
		cout<<" - Nhap ma sach: ";
		gets(MaS);
		cout<<" - Nhap ten sach: ";
		gets(TenS);
		cout<<" - Nhap nha xuat ban: ";
		gets(NXB);
		cout<<" - Nhap nam xuat ban: ";
		cin>>namXB; fflush(stdin);
		cout<<" - Nhap ten tac gia: ";
		gets(TG);
		cout<<" - Nhap the loai: ";
		gets(TheLoai);
		cout<<" - Nhap so luong: ";
		cin>>soluong;
		cout<<" - Nhap gia tien: ";
		cin>>GiaTien; fflush(stdin);
	}


	void showSach()
	{
		cout<<setw(10)<<left<<MaS;
		cout<<setw(30)<<TenS;
		cout<<setw(20)<<NXB;
		cout<<setw(10)<<right<<namXB;
		cout<<"  "<<setw(20)<<left<<TG;
		cout<<setw(20)<<TheLoai;
		cout<<setw(10)<<right<<soluong;
		cout<<setw(10)<<GiaTien;
		cout<<endl;
	}

	void editSach()
	{
		showSach();
		cout<<"\tSUA SACH \n";
		cout<<" - Sua ten sach: ";
		gets(TenS);
		cout<<" - Sua nha xuat ban: ";
		gets(NXB);
		cout<<" - Sua nam xuat ban: ";
		cin>>namXB; fflush(stdin);
		cout<<" - Sua ten tac gia: ";
		gets(TG);
		cout<<" - Sua the loai: ";
		gets(TheLoai);
		cout<<" - Sua so luong: ";
		cin>>soluong;
		cout<<" - Sua gia tien: ";
		cin>>GiaTien; fflush(stdin);
	}

	char* getMaS()
	{
		return MaS;
	}
};


class PhieuMuon
{
	char MaDG[10];
	char MaS[10];
	Date NgayMuon;
	bool DaTra;
public:
	void createPhieuMuon()
	{
		system("cls");
		cout<<"\tTAO PHIEU MUON\n";
		cout<<" - Nhap Ma Doc Gia: ";
		gets(MaDG);
		cout<<" - Nhap Ma Sach: ";
		gets(MaS);
		cout<<" - Nhap Ngay Muon: ";
		NgayMuon.input();
		DaTra = 0;
	}

	void showPhieuMuon()
	{
		char status[10];
		cout<<setw(10)<<left<<MaDG;
		cout<<setw(10)<<MaS;
		NgayMuon.output();
		if(DaTra)
			strcpy(status,"OK");
		else
			strcpy(status,"Chua tra");
		cout<<setw(10)<<right<<status;
		cout<<endl;
	}

	void editPhieuMuon()
	{
		showPhieuMuon();
        cout<<"\tSUA PHIEU MUON\n";
		cout<<" - Sua Ma Doc Gia: ";
		gets(MaDG);
		cout<<" - Sua Ma Sach: ";
		gets(MaS);
		cout<<" - Sua Ngay Muon: ";
		NgayMuon.input();
		cout<<" - Sua Tinh Trang (0-Chua tra, 1-Da tra): ";
		cin>>DaTra; fflush(stdin);
	}

	void trasach()
	{
		DaTra=1;
	}
	char* getMaDG()
	{
		return MaDG;
	}
	char* getMaS()
	{
		return MaS;
	}
	bool getDaTra()
	{
		return DaTra;
	}
	
	
};

void titlePhieuMuon()
{
	cout<<"====================================================================\n";
	cout<<setw(10)<<left<<"Ma DG";
	cout<<setw(10)<<"Ma Sach";
	cout<<setw(13)<<right<<"Ngay Muon"<<setw(5)<<" ";
	cout<<setw(10)<<right<<"Tinh Trang";
	cout<<endl;
	cout<<"====================================================================\n";
}
void titleDG()
{
	cout<<"====================================================================";
	cout<<"====================================================================\n";
	cout<<setw(10)<<left<<"Ma DG";
	cout<<setw(10)<<"Ma SV";
	cout<<setw(30)<<"Ho Ten";
	cout<<setw(5)<<" "<<setw(13)<<left<<"Nam Sinh";
	cout<<setw(20)<<left<<"Noi Sinh";
	cout<<setw(10)<<"Lop";
	cout<<setw(10)<<"Nam";
	cout<<setw(3)<<" "<<setw(13)<<left<<"Ngay LT";
	cout<<setw(3)<<" "<<setw(13)<<"Ngay HH";
	cout<<endl;
	cout<<"====================================================================";
	cout<<"====================================================================\n";
}
void titleSach()
{
	cout<<"====================================================================";
	cout<<"====================================================================\n";
	cout<<setw(10)<<left<<"Ma Sach";
	cout<<setw(30)<<"Ten Sach";
	cout<<setw(20)<<"NXB";
	cout<<setw(10)<<right<<"Nam XB";
	cout<<"  "<<setw(20)<<left<<"TG";
	cout<<setw(20)<<"The Loai";
	cout<<setw(10)<<right<<"SL";
	cout<<setw(10)<<"Gia Tien";
	cout<<endl;
	cout<<"====================================================================";
	cout<<"====================================================================\n";
}

fstream fp,fp1; //In-Out File
Sach Book; //Sach
DocGia DG; //DocGia
PhieuMuon MT; //MuonTra

//***************************************************************
// function to insert record of file
//****************************************************************
void insertSach()
{
	char ch;
	fp.open("sach.dat",ios::out|ios::app);
	do
	{
		system("cls");
		Book.insertSach();
		fp.write((char*)&Book,sizeof(Sach));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch; fflush(stdin);
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void insertDG()
{
	char ch;
	fp.open("docgia.dat",ios::out|ios::app);
	do
	{
		DG.insertDG();
		fp.write((char*)&DG,sizeof(DocGia));
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch; fflush(stdin);
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void find_DG(char*);
void find_Sach(char*);
void createPhieuMuon()
{
	char ch;
	fp.open("muontra.dat",ios::out|ios::app);
	do
	{
		MT.createPhieuMuon();
		fp.write((char*)&MT,sizeof(PhieuMuon));
		cout<<"\nTHONG TIN PHIEU MUON\n";
		find_DG(MT.getMaDG());
		find_Sach(MT.getMaS());
		cout<<"\n\ndo you want to add more record..(y/n?)";
		cin>>ch; fflush(stdin);
	}while(ch=='y'||ch=='Y');
	fp.close();
}

//***************************************************************
// function to modify record of file
//****************************************************************
void modifySach()
{
	char n[10];
	int found=0;
	system("cls");
	cout<<"\n\n\tSUA THONG TIN SACH.... ";
	cout<<"\n\n\tNhap ma sach: ";
	gets(n);
	fp.open("sach.dat",ios::in|ios::out);
	while(fp.read((char*)&Book,sizeof(Sach)) && found==0)
	{
		if(strcmp(Book.getMaS(),n)==0)
		{
			titleSach();
			Book.editSach();
			int pos=-1*sizeof(Book);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&Book,sizeof(Sach));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	cout<<endl; system("pause"); cout<<endl;
}
void modifyDG()
{
	char n[10];
	int found=0;
	system("cls");
	cout<<"\n\n\tSUA THONG TIN DOC GIA... ";
	cout<<"\n\n\tNhap ma doc gia: ";
	gets(n);
	fp.open("docgia.dat",ios::in|ios::out);
	while(fp.read((char*)&DG,sizeof(DocGia)) && found==0)
	{
		if(strcmp(DG.getMaDG(),n)==0)
		{
			titleDG();
			DG.editDG();
			int pos=-1*sizeof(DG);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&DG,sizeof(DocGia));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	cout<<endl; system("pause"); cout<<endl;
}
void modifyPhieuMuon()
{
	char MaDG[10], MaS[10];
	int found=0;
	system("cls");
	cout<<"\n\n\tSUA THONG TIN PHIEU MUON... ";
	cout<<"\n\n\tNhap ma doc gia: ";
	gets(MaDG);
	cout<<"\n\n\tNhap ma sach: ";
	gets(MaS);
	fp.open("muontra.dat",ios::in|ios::out);
	while(fp.read((char*)&MT,sizeof(PhieuMuon)) && found==0)
	{
		if(strcmp(MT.getMaDG(),MaDG)==0 && strcmp(MT.getMaS(),MaS)==0)
		{
			titlePhieuMuon();
			MT.editPhieuMuon();
			int pos=-1*sizeof(MT);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&MT,sizeof(PhieuMuon));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	cout<<endl; system("pause"); cout<<endl;
}
//***************************************************************
// function to delete record of file
//****************************************************************
void deleteDG()
{
	char n[10];
	int flag=0;
	system("cls");
	cout<<"\n\n\n\tXOA DOC GIA...";
	cout<<"\n\nNhap Ma Doc gia muon xoa : ";
	gets(n);
	fp.open("docgia.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&DG,sizeof(DocGia)))
	{
		if(strcmp(DG.getMaDG(),n)!=0)
			fp2.write((char*)&DG,sizeof(DocGia));
		else
			flag=1;
	}

	fp2.close();
	fp.close();
	remove("docgia.dat");
	rename("Temp.dat","docgia.dat");
	if(flag==1)
		cout<<"\n\n\tRecord Deleted ..";
	else
		cout<<"\n\nRecord not found";
	cout<<endl; system("pause"); cout<<endl;
}
void deleteSach()
{
	char n[10];
	system("cls");
	cout<<"\n\n\n\tXOA SACH ...";
	cout<<"\n\nNhap Ma Sach can xoa : ";
	gets(n);
	fp.open("sach.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&Book,sizeof(Sach)))
	{
		if(strcmp(Book.getMaS(),n)!=0)
		{
			fp2.write((char*)&Book,sizeof(Sach));
		}
	}

	fp2.close();
	fp.close();
	remove("sach.dat");
	rename("Temp.dat","sach.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cout<<endl; system("pause"); cout<<endl;
}
void deletePhieuMuon()
{
	char MaDG[10], MaS[10];
	system("cls");
	cout<<"\n\n\n\tXOA PHIEU MUON ...";
	cout<<"\n\n\tNhap ma doc gia: ";
	gets(MaDG);
	cout<<"\n\n\tNhap ma sach: ";
	gets(MaS);
	fp.open("muontra.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&MT,sizeof(PhieuMuon)))
	{
		if(strcmp(MT.getMaDG(),MaDG)!=0 && strcmp(MT.getMaS(),MaS)!=0)
		{
			fp2.write((char*)&MT,sizeof(PhieuMuon));
		}
	}

	fp2.close();
	fp.close();
	remove("muontra.dat");
	rename("Temp.dat","muontra.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cout<<endl; system("pause"); cout<<endl;
}
//***************************************************************
// function to read specific record from file
//****************************************************************
void find_Sach(char n[])
{
	cout<<"\nTHONG TIN SACH\n";
	int flag=0;
	fp.open("sach.dat",ios::in);
	titleSach();
	while(fp.read((char*)&Book,sizeof(Sach)))
	{
		if(strcmp(Book.getMaS(),n)==0)
		{
			Book.showSach();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nBook does not exist";
	cout<<endl; system("pause"); cout<<endl;
}
void find_DG(char n[])
{
	cout<<"\nTHONG TIN DOC GIA\n";
	int flag=0;
	fp.open("docgia.dat",ios::in);
	titleDG();
	while(fp.read((char*)&DG,sizeof(DocGia)))
	{
		if((strcmp(DG.getMaDG(),n)==0))
		{
			DG.showDG();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nStudent does not exist";
	cout<<endl; system("pause"); cout<<endl;
}
void find_PhieuMuon(char MaDG[], char MaS[])
{
	cout<<"\nTHONG TIN PHIEU MUON\n";
	int flag=0;
	fp.open("muontra.dat",ios::in);
	titlePhieuMuon();
	while(fp.read((char*)&MT,sizeof(PhieuMuon)))
	{
		if((strcmp(MT.getMaDG(),MaDG)==0) && (strcmp(MT.getMaS(),MaS)==0))
		{
			MT.showPhieuMuon();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nPhieu Muon does not exist";
	cout<<endl; system("pause"); cout<<endl;
}
//***************************************************************
// function to display all students list
//****************************************************************
void display_all_DG()
{
	system("cls");
	fp.open("docgia.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		cout<<endl; system("pause"); cout<<endl;
		return;
	}
	cout<<"\n\n\t\tDANH SACH DOC GIA\n\n";
	titleDG();
	while(fp.read((char*)&DG,sizeof(DocGia)))
	{
		DG.showDG();
	}

	fp.close();
	cout<<endl; system("pause"); cout<<endl;
}
//***************************************************************
// function to display Books list
//****************************************************************
void display_all_Sach()
{
	system("cls");
	fp.open("sach.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		cout<<endl; system("pause"); cout<<endl;
		return;
	}
	cout<<"\n\n\t\tDANH SACH SACH\n\n";
	titleSach();
	while(fp.read((char*)&Book,sizeof(Sach)))
	{
		Book.showSach();
	}
	fp.close();
	cout<<endl; system("pause"); cout<<endl;
}

//***************************************************************
// function to display Phieu Muon
//****************************************************************
void display_all_PhieuMuon()
{
	system("cls");
	fp.open("muontra.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		cout<<endl; system("pause"); cout<<endl;
		return;
	}
	cout<<"\n\n\t\tDANH PHIEU MUON\n\n";
	titlePhieuMuon();
	while(fp.read((char*)&MT,sizeof(PhieuMuon)))
	{
		MT.showPhieuMuon();
	}
	fp.close();
	cout<<endl; system("pause"); cout<<endl;
}
//***************************************************************
// function update tra sach
//****************************************************************
void updateTinhTrangPhieuMuon()
{
	char MaDG[10], MaS[10];
	system("cls");
	cout<<"\n\n\n\tUPDATE PHIEU MUON TRA SACH ...";
	cout<<"\n\n\tNhap ma doc gia: ";
	gets(MaDG);
	cout<<"\n\n\tNhap ma sach: ";
	gets(MaS);
	fp.open("muontra.dat",ios::in|ios::out);
	int flag=0;
	titlePhieuMuon();
	while(fp.read((char*)&MT,sizeof(PhieuMuon)))
	{
		if((strcmp(MT.getMaDG(),MaDG)==0) && (strcmp(MT.getMaS(),MaS)==0))
		{
			MT.trasach();
			MT.showPhieuMuon();
			int pos=-1*sizeof(PhieuMuon);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&MT,sizeof(PhieuMuon));
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\nPhieu Muon does not exist";
	else
		cout<<"\n\n\t Record Updated";
	cout<<endl; system("pause"); cout<<endl;
}
void PhieuChuaTra()
{
	int flag=0;
	system("cls");
	cout<<"\n\n\n\tDANH SACH PHIEU MUON CHUA TRA ...";
	fp.open("muontra.dat",ios::in|ios::out);
	titlePhieuMuon();
	while(fp.read((char*)&MT,sizeof(PhieuMuon)))
	{
		if (MT.getDaTra() == 0)
		{
			MT.showPhieuMuon();
			flag=1;
		}
	}
	if (flag==0)
	{
		cout<<"\n\nEmpty!";
	}
	fp.close();
	cout<<endl; system("pause"); cout<<endl;
}
void SachChuaTra()
{
	system("cls");
	cout<<"\n\n\n\tSACH CHUA DUOC TRA ...";
	fp.open("muontra.dat",ios::in|ios::out);
	while(fp.read((char*)&MT,sizeof(PhieuMuon)))
	{
		titlePhieuMuon();
		MT.showPhieuMuon();
		find_Sach(MT.getMaS());
	}
	fp.close();
	cout<<endl; system("pause"); cout<<endl;
}
void DGChuaTraSach()
{
	system("cls");
	cout<<"\n\n\n\tDOC GIA CHUA TRA SACH ...";
	fp.open("muontra.dat",ios::in|ios::out);
	while(fp.read((char*)&MT,sizeof(PhieuMuon)))
	{
		titlePhieuMuon();
		MT.showPhieuMuon();
		find_DG(MT.getMaDG());
	}
	fp.close();
	cout<<endl; system("pause"); cout<<endl;
}
//***************************************************************
// MENU QUAN LY DOC GIA
//****************************************************************
void DG_management()
{
	system("cls");
	int ch1;
	cout<<"\n\n\n\tQUAN LY DOC GIA";
	cout<<"\n\n\t1.THEM DOC GIA ";
	cout<<"\n\n\t2.HIEN THI TAT CA DOC GIA ";
	cout<<"\n\n\t3.TIM THONG TIN DOC GIA ";
	cout<<"\n\n\t4.SUA THONG TIN DOC GIA ";
	cout<<"\n\n\t5.XOA DOC GIA ";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch1; fflush(stdin);
	switch(ch1)
	{
		case 1:
		system("cls");
		insertDG();
		break;
		case 2:
		display_all_DG();
		break;
		case 3:
		char num[10];
		system("cls");
		cout<<"\n\n\tNhap ma doc gia can tim: ";
		gets(num);
		find_DG(num);
		break;
		case 4:
		modifyDG();
		break;
		case 5:
		deleteDG();
		break;
		case 6:
		return;
		default:cout<<"\a";
	}
	DG_management();
}

//***************************************************************
// MENU QUAN LY SACH
//****************************************************************
void book_management()
{
	system("cls");
	int ch2;
	cout<<"\n\n\n\tQUAN LY SACH";
	cout<<"\n\n\t1.THEM SACH ";
	cout<<"\n\n\t2.HIEN THI TAT CA SACH ";
	cout<<"\n\n\t3.TIM THONG TIN SACH ";
	cout<<"\n\n\t4.SUA THONG TIN SACH ";
	cout<<"\n\n\t5.XOA SACH ";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch2; fflush(stdin);
	switch(ch2)
	{
		case 1:
		system("cls");
		insertSach();
		break;
		case 2:
		display_all_Sach();
		break;
		case 3:
		char num[10];
		system("cls");
		cout<<"\n\n\tNhap ma sach can tim: ";
		gets(num);
		find_Sach(num);
		break;
		case 4:
		modifySach();
		break;
		case 5:
		deleteSach();
		break;
		case 6:
		return;
		default:cout<<"\a";
	}
	book_management();
}
//***************************************************************
// MENU QUAN LY PHIEU MUON
//****************************************************************
void PhieuMuon_management()
{
	system("cls");
	int ch1;
	cout<<"\n\n\n\tQUAN LY PHIEU MUON";
	cout<<"\n\n\t1.TAO PHIEU MUON ";
	cout<<"\n\n\t2.HIEN THI TAT PHIEU MUON ";
	cout<<"\n\n\t3.TIM THONG TIN PHIEU MUON ";
	cout<<"\n\n\t4.SUA THONG TIN PHIEU MUON ";
	cout<<"\n\n\t5.XOA PHIEU MUON ";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch1; fflush(stdin);
	switch(ch1)
	{
		case 1:
		system("cls");
		createPhieuMuon();
		break;
		case 2:
		display_all_PhieuMuon();
		break;
		case 3:
		char MaDG[10], MaS[10];
		system("cls");
		cout<<"\n\n\tNhap ma doc gia: ";
		gets(MaDG);
		cout<<"\n\n\tNhap ma sach: ";
		gets(MaS);
		find_PhieuMuon(MaDG, MaS);
		break;
		case 4:
		modifyPhieuMuon();
		break;
		case 5:
		deletePhieuMuon();
		break;
		case 6:
		return;
		default:cout<<"\a";
	}
	PhieuMuon_management();
}
//***************************************************************
// MENU QUAN LY TRA SACH
//****************************************************************
void Tra_management()
{
	system("cls");
	int ch1;
	cout<<"\n\n\n\tQUAN LY TRA SACH";
	cout<<"\n\n\t1.CAP NHAP SACH TRA ";
	cout<<"\n\n\t2.HIEN THI PHIEU CHUA TRA ";
	cout<<"\n\n\t3.HIEN THI SACH CHUA TRA ";
	cout<<"\n\n\t4.HIEN THI DOC GIA CHUA TRA SACH ";
	cout<<"\n\n\t5.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch1; fflush(stdin);
	switch(ch1)
	{
		case 1:
		system("cls");
		updateTinhTrangPhieuMuon();
		break;
		case 2:
		PhieuChuaTra();
		break;
		case 3:
		SachChuaTra();
		break;
		case 4:
		DGChuaTraSach();
		break;
		case 5:
		return;
		default:cout<<"\a";
	}
	Tra_management();
}
//***************************************************************
// INTRODUCTION FUNCTION
//****************************************************************
void intro()
{
	system("cls");
	cout<<"\t\t\t LIBRARY\n";
	cout<<"\t\t\tMANAGEMENT\n";
	cout<<"\t\t\t  SYSTEM\n";
	system("pause");
}
int main()
{
	char ch;
	intro();
	do
	{
		system("cls");
		cout<<"\n\t\tMAIN MENU\n";
		cout<<"\n\t01. QUAN LY SACH";
		cout<<"\n\t02. QUAN LY DOC GIA";
		cout<<"\n\t03. QUAN LY MUON SACH";
		cout<<"\n\t04. QUAN LY TRA SACH";
		cout<<"\n\t05. THONG KE";
		cout<<"\n\t06. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-6) ";
		cin>>ch; fflush(stdin);
		switch(ch)
		{
			case '1':
			system("cls");
			book_management();
			break;
			case '2':
			DG_management();
			break;
			case '3':
			PhieuMuon_management();
			break;
			case '4':
			Tra_management();
			break;
			case '6':
			exit(0);
			default :cout<<"\a";
		}
	}while(ch!=6);

	return 0;
}
