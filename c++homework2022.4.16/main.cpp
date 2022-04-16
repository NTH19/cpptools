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
			cout << "用户名或者密码错误\n";
			system("pause");
			return 0;
		}
		else {
			cout << "登入成功!!\n";
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
				cout << "\t\t请输入正确的指令！" << endl;
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
			cout << "用户名或者密码错误\n";
			system("pause");
			return 0;
		}else {
			cout << "登入成功!!\n";
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
				cout << "\t\t请输入正确的指令！" << endl;
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
		cout << "错误\n"; return 0;
	}

	
	return 0;
}

int ShowAuxMenu()
{
	cout << ("\n\t\t+==============================================================+\n");
	cout << ("\t\t+                  飞机票管理系统  主菜单                        +\n");
	cout << ("\t\t+==============================================================+\n");
	cout << ("\t\t+ 【航班基本信息管理】                                         +\n");
	cout << ("\t\t+     1. 添加航班           2. 删除航班        3. 修改航班     +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t+ 【航班动态管理】                                             +\n");
	cout << ("\t\t+     4. 发布延误取消通知                                      +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t+ 0. 退出系统                                                  +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");

	cout << ("\t\t+ 输入您的功能选项序号：");

	int ans = 0;
	scanf("%d", &ans);

	return ans;
}

int ShowUsrMenu()
{
	cout << ("\n\t\t+=============================================================+\n");
	cout << ("\t\t+                  飞机票管理系统  主菜单                      +\n");
	cout << ("\t\t+==============================================================+\n");
	cout << ("\t\t+ 【票务管理】                                                 +\n");
	cout << ("\t\t+     1. 购票申请           2. 退票申请                        +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t+ 【票务查询】                                                 +\n");
	cout << ("\t\t+     3. 按航班号查询       4. 按起降地查询                    +\n");
	cout << ("\t\t+     5. 显示所有航班       6. 显示所有购票信息                +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t+ 0. 退出系统                                                  +\n");
	cout << ("\t\t+--------------------------------------------------------------+\n");

	cout << ("\t\t+ 输入您的功能选项序号：");

	int ans = 0;
	scanf("%d", &ans);

	return ans;
}
int ShowSystem() {
	cout << ("\n\t\t\t+==============================================================+\n");
	cout << ("\t\t\t+                         登入界面                             +\n");
	cout << ("\t\t\t+==============================================================+\n");
	cout << ("\t\t\t+ 0. 登入管理员系统                                            +\n");
	cout << ("\t\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t\t+ 1. 登入乘客系统                                              +\n");
	cout << ("\t\t\t+--------------------------------------------------------------+\n");
	cout << ("\t\t\t+ 2. 退出系统                                                  +\n");
	cout << ("\t\t\t+--------------------------------------------------------------+\n");
	int ans = 0;

	cout << ("\t\t\t+ 输入您的功能选项序号：");

	scanf("%d", &ans);
	return ans;
}
void ShowEntry(string &usr,string &pwd) {
	cout << "请输入用户名:";
	cin >> usr;
	cout << "请输入密码:";
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