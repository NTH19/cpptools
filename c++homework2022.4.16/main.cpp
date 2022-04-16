#include "FlightSystem.h"

using namespace std;

int ShowUsrMenu();
int ShowAuxMenu();
int ShowSystem();
void ShowEntry(string& usr, string& pwd);
bool correct(string& usr, string& pwd, string lj);
FlightSystem  fs;

int main()
{
	int cho=ShowSystem();
	if (cho == 2)return 0;
	string usr, pwd;
	system("cls");
	bool res;
	switch (cho)
	{
	case 0:
		ShowEntry(usr, pwd); 
		res=correct(usr, pwd, "./aux.ini");
		if (!res) {
			cout << "�û��������������\n";
			system("pause");
			return 0;
		}
		else {
			cout << "����ɹ�!!\n";
		}
		fs.LoadFromFile();
		system("pause");
		system("cls");
		while (true) {
			int nSel = ShowAuxMenu();
			fs.LoadFromFile();
			cout << endl;
			switch (nSel)
			{
			case 1:
				fs.AddFlight();
				break;
			case 2:
				fs.DelFlight();
				break;
			case 3:
				fs.ModFlight();
				break;
			case 4:
				fs.Delay();
				break;
			case 0:
				fs.SaveToFile();
				return 0;
			default:
			{
				cout << "\t\t��������ȷ��ָ�" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			break;
			}
			cout << endl;
			system("pause");
			system("cls");
		
		}
	case 1:
		ShowEntry(usr, pwd);
		res = correct(usr, pwd, "./usr.ini");
		if (!res) {
			cout << "�û��������������\n";
			system("pause");
			return 0;
		}else {
			cout << "����ɹ�!!\n";
		}
		system("pause");
		system("cls");
		while (true) {
			int nSel = ShowUsrMenu();

			cout << endl;
			fs.LoadFromFile();
			switch (nSel)
			{
			case 1:
				fs.BuyTicket();
				break;
			case 2:
				fs.RefundTicket();
				break;
			case 3:
				fs.SearchByFlight();
				break;
			case 4:
				fs.SearchByAddress();
				break;
			case 5:
				fs.SearchAllFlights();
				break;
			case 6:
				fs.SearchAllTickets();
				break;
			case 0:
				fs.SaveToFile();
				return 0;
			default:
			{
				cout << "\t\t��������ȷ��ָ�" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			break;
			}
			cout << endl;
			system("pause");
			system("cls");
		}
		break;
	default:
		cout << "����\n"; return 0;
	}

	
	return 0;
}

int ShowAuxMenu()
{
	cout << ("\n\t\t+==============================================================+\n");
	cout << ("\t\t+                  �ɻ�Ʊ����ϵͳ  ���˵�                        +\n");
	cout << ("\t\t+==============================================================+\n");
	cout << ("\t\t+ �����������Ϣ����                                         +\n");
	cout << ("\t\t+     1. ��Ӻ���           2. ɾ������        3. �޸ĺ���     +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t+ �����ද̬����                                             +\n");
	cout << ("\t\t+     4. ��������ȡ��֪ͨ                                      +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t+ 0. �˳�ϵͳ                                                  +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");

	cout << ("\t\t+ �������Ĺ���ѡ����ţ�");

	int ans = 0;
	scanf("%d", &ans);

	return ans;
}

int ShowUsrMenu()
{
	cout << ("\n\t\t+=============================================================+\n");
	cout << ("\t\t+                  �ɻ�Ʊ����ϵͳ  ���˵�                      +\n");
	cout << ("\t\t+==============================================================+\n");
	cout << ("\t\t+ ��Ʊ�����                                                 +\n");
	cout << ("\t\t+     1. ��Ʊ����           2. ��Ʊ����                        +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t+ ��Ʊ���ѯ��                                                 +\n");
	cout << ("\t\t+     3. ������Ų�ѯ       4. ���𽵵ز�ѯ                    +\n");
	cout << ("\t\t+     5. ��ʾ���к���       6. ��ʾ���й�Ʊ��Ϣ                +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t+ 0. �˳�ϵͳ                                                  +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");

	cout << ("\t\t+ �������Ĺ���ѡ����ţ�");

	int ans = 0;
	scanf("%d", &ans);

	return ans;
}
int ShowSystem() {
	cout << ("\n\t\t\t+==============================================================+\n");
	cout << ("\t\t\t+                         �������                             +\n");
	cout << ("\t\t\t+==============================================================+\n");
	cout << ("\t\t\t+ 0. �������Աϵͳ                                            +\n");
	cout << ("\t\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t\t+ 1. ����˿�ϵͳ                                              +\n");
	cout << ("\t\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t\t+ 2. �˳�ϵͳ                                                  +\n");
	cout << ("\t\t\t+--------------------------------------------------------------+\n");
	int ans = 0;

	cout << ("\t\t\t+ �������Ĺ���ѡ����ţ�");

	scanf("%d", &ans);
	return ans;
}
void ShowEntry(string &usr,string &pwd) {
	cout << "�������û���:";
	cin >> usr;
	cout << "����������:";
	cin >> pwd;
}
bool correct(string& usr, string& pwd,string  lj) {
	ifstream f;
	f.open(lj, ios::binary | ios::in);
	int am;
	f >> am;
	unordered_map<string, string> u_p;
	while (am--) {
		string temp,temp2;
		f >> temp>>temp2;
		u_p[temp] = temp2;
	}
	if (u_p[usr] == pwd) return true;
	else return false;
}