#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;
struct sinhvien
{
	string hoten;
	string lop;
	string ns;
	string mssv;
};
struct Questions
{
	string cauhoi;
	string traloi;
	char dapan;
	char userdapan;
};
string questions[100];
Questions ques[100];
string chuanhoaTen(string s)
{
	stringstream ss(s);
	string res = "", temp;
	while (ss >> temp)
	{
		res += toupper(temp[0]);
		for (int i = 1; i < temp.size(); i++)
		{
			res += tolower(temp[i]);
		}
		res += " ";
	}
	res.pop_back();
	return res;
}
string chuanhoaNS(string s)
{
	string tmp = s;
	if (tmp[1] == '/')
	{
		tmp = "0" + tmp;
	}
	if (tmp[4] == '/')
	{
		tmp.insert(3, "0");
	}
	return tmp;
}	
sinhvien sv1;
int main()
{
	//Nhap thong tin sv
	//
	//
	//
	cout << "-----------------------------------------" << endl;
	cout << "NHAP THONG TIN SINH VIEN : " << endl;
	cout << "1. Ho va ten : ";
	getline(cin, sv1.hoten);
	cout << "2. Lop : ";
	getline(cin, sv1.lop);
	cout << "3. Ngay sinh: ";
	getline(cin, sv1.ns);
	cout << "4. Ma so sinh vien: ";
	getline(cin, sv1.mssv);
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "THONG TIN SINH VIEN : " << endl;
	cout << "1. Ho va ten : " << chuanhoaTen(sv1.hoten) << endl;
	cout << "2. Lop : " << sv1.lop << endl;
	cout << "3. Ngay sinh : " << chuanhoaNS(sv1.ns) << endl;
	cout << "4. MSSV : " << sv1.mssv << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Nhan G de sua thong tin " << endl;
	cout << "Nhan T de tien hanh lam bai : ";
	char luachon;
	cin >> luachon;
	while (luachon == 't' || luachon == 'g' ||  luachon == 'T' || luachon == 'G')
	{
		if (luachon == 't' || luachon == 'T')
		{
			break;
		}
		if (luachon == 'g' || luachon == 'G')
		{
			int num;
			cout << "Nhap thong tin muon sua, nhan 0 de tien hanh lam bai : ";
			cin >> num;
			cin.ignore();
			if (num == 0)
			{
				break;
			}
			if (num == 1)
			{
				string name;
				cout << "Ho va ten : ";
				getline(cin, name);
				sv1.hoten = chuanhoaTen(name);
			}
			else if (num == 2)
			{
				string lop;
				cout << "Lop : ";
				getline(cin, lop);
				sv1.lop = lop;
			}
			else if (num == 3)
			{
				string ns;
				cout << "Ngay sinh : ";
				getline(cin, ns);
				sv1.ns = chuanhoaNS(ns);
			}
			else if (num == 4)
			{
				string ms;
				cout << "MSSV : ";
				getline(cin, ms);
				sv1.mssv = ms;
			}
			else
			{
				cout << "LUA CHON KHONG HOP LE : " << endl;
				cout << "Vui long nhap lai : " << endl;
			}
		}
	}
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "THONG TIN DA SUA : " << endl;
	cout << "1. Ho va ten : " << sv1.hoten << endl;
	cout << "2. Lop : " << sv1.lop << endl;
	cout << "3. Ngay sinh : " << sv1.ns << endl;
	cout << "4. MSSV : " << sv1.mssv << endl;
	cout << "-----------------------------------------" << endl;
	//
	//
	//
	//ham xu ly bai thi
	ifstream file("questions.txt", ios::out);
	if (!file.is_open())
	{
		cout << "Cannot open file ";
		return 0;
	}
	string line;
	int dem = 0;
	while (getline(file, line))
	{
		questions[dem++] = line;
	}
	int demques = 0;
	for (int i = 0; i < dem; i += 6)
	{
		Questions q;
		q.cauhoi = questions[i];
		q.traloi = questions[i + 1] + "\n" + questions[i + 2] + "\n" + questions[i + 3] + "\n"
			+ questions[i + 4];
		q.dapan = questions[i + 5][0]; 
		ques[demques++] = q;
	}
	cout << endl;
	int cnt = 0;	
	cout << "-----------------------------------------" << endl;
	cout << "\t" << "\t"  << "MENU : " << endl;
	cout << "\t" << "* Choose A/B/C/D "<< endl << "\t" << "* S to skip" << endl;
	cout << "\t" << "* X to change the answers " << endl;
	cout << endl;	
	time_t startTime = time(0);
	tm startTm;
	localtime_s(&startTm, &startTime);
	for (int i = 0; i < demques; i++)
	{
		cout << endl;
		cout << ques[i].cauhoi << endl;
		cout << ques[i].traloi << endl;
		cout << endl;
		cout << "Your choice or press 'S' to skip : ";
		cin >> ques[i].userdapan;
		if (toupper(ques[i].userdapan) == toupper(ques[i].dapan))
		{
			cnt++;
		}
		if (ques[i].userdapan == 's' || ques[i].userdapan == 'S')
		{
			cout << endl;
			continue;
		}
		else if (ques[i].userdapan == 'x' || ques[i].userdapan == 'X')
		{
			int num; 
			cout << "Chon cau hoi muon doi dap an : ";
			cin >> num;
			cout << ques[num - 1].cauhoi << endl;
			cout << ques[num - 1].traloi << endl;
			cout << "Your choice or press 'S' to skip :";
			cin >> ques[num - 1].userdapan;
			if (toupper(ques[num - 1].userdapan) == toupper(ques[i - 1].dapan))
			{
				cnt++;
			}
			i = num - 1; 
		}
		while (ques[i].userdapan != 'a' && ques[i].userdapan != 'A' &&  
			ques[i].userdapan != 'b' && ques[i].userdapan != 'B' && ques[i].userdapan != 'c' 
			&& ques[i].userdapan != 'C' && ques[i].userdapan != 'd' && ques[i].userdapan != 'D')
		{
			cout << endl;
			cout << "\t" << "\t" << "VUI LONG NHAP LAI " << endl;
			cout << ques[i].cauhoi << endl;
			cout << ques[i].traloi << endl;
			cout << "Your choice or press 'S' to skip :";
			cin >> ques[i].userdapan;
			if (toupper(ques[i].userdapan) == toupper(ques[i].dapan))
			{
				cnt++;
			}
		}
	}
	cout << endl;
	cout << "\t" << "\t" << "\t" << "\t" << "\t" << "\t"  << "Double check ? " << endl;
	cout << "\t" << "\t" << "Choose X to change the answers : ";
	cout << "\t" << "\t" << "Choose E to finish ";
	char choice;
	cin >> choice;
	while (true)
	{
		if (choice == 'x' || choice == 'X')
		{
			cout << endl;
			int num;
			cout << "Chon cau hoi muon doi dap an (neu khong muon doi nua, nhan 0) ";
			cout << "Vui long chon can than. Chon sai se khong tinh diem : ";
			cin >> num;
			if (num == 0)
			{
				break;
			}
			cout << endl;
			cout << ques[num - 1].cauhoi << endl;
			cout << ques[num - 1].traloi << endl;
			cout << "Your choice : ";
			cin >> ques[num - 1].userdapan;
			if (toupper(ques[num - 1].userdapan) == toupper(ques[num - 1].dapan))
			{
				cnt++;
			}
			if (ques[num - 1].userdapan == 'e' || ques[num - 1].userdapan == 'E')
			{
				break;
			}
		}
		if (choice == 'e' || choice == 'E')
		{
			break;
		}
	}
	//
	//
	// 
	//ham tinh thoi gian
	time_t endTime = time(0);
	tm endTm;
	localtime_s(&endTm, &endTime);
	double elapsedSeconds = difftime(endTime, startTime);
	//thoi gian bat dau
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Start time: "
		<< 1900 + startTm.tm_year << '-'
		<< setw(2) << setfill('0') << 1 + startTm.tm_mon << '-'
		<< setw(2) << setfill('0') << startTm.tm_mday << ' '
		<< setw(2) << setfill('0') << startTm.tm_hour << ':'
		<< setw(2) << setfill('0') << startTm.tm_min << ':'
		<< setw(2) << setfill('0') << startTm.tm_sec << endl;
	//thoi gian ket thuc
	cout << "End time: "
		<< 1900 + endTm.tm_year << '-'
		<< setw(2) << setfill('0') << 1 + endTm.tm_mon << '-'
		<< setw(2) << setfill('0') << endTm.tm_mday << ' '
		<< setw(2) << setfill('0') << endTm.tm_hour << ':'
		<< setw(2) << setfill('0') << endTm.tm_min << ':'
		<< setw(2) << setfill('0') << endTm.tm_sec << endl;
	cout << "-----------------------------------------" << endl;
	//
	// 
	// 
	//Hien thong tin
	cout << "-----------------------------------------" << endl;
	cout << "THONG TIN SINH VIEN :" << endl;
	cout << "1. Ho va ten : " << chuanhoaTen(sv1.hoten) << endl;
	cout << "2. Lop : " << sv1.lop << endl;
	cout << "3. Ngay sinh : " << chuanhoaNS(sv1.ns) << endl;
	cout << "4. MSSV : " << sv1.mssv << endl;
	cout << "Thoi gian lam bai: " << elapsedSeconds << " seconds" << endl;
	cout << "YOUR NUMBER OF CORRECT ANSWERS : " << cnt << "/" << demques << endl;
	cout << "TOTAL : " << fixed << setprecision(2) << (double)cnt / demques * 10 << " MARKS" << endl;
	cout << "-----------------------------------------" << endl;
	file.close();
}
