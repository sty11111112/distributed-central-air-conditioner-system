#include<iostream>
#include"log.h"
using namespace std;


void account::get_account()
{
	cout << "�����뷿��ţ�" << endl;
	cin >> room_num;
	cout << "���������֤�ţ�" << endl;
	cin >> id;
}

void account::check_account()
{
	if (room_num == 1) {
		if (id == 11111111) {
			cout << "��¼�ɹ�";
		}
		else {
			cout << "��¼ʧ��";
		}
	}
	else if (room_num == 2) {
		if (id == 22222222) {
			cout << "��¼�ɹ�";
		}
		else {
			cout << "��¼ʧ��";
		}
	}
	else if (room_num == 3) {
		if (id == 33333333) {
			cout << "��¼�ɹ�";
		}
		else {
			cout << "��¼ʧ��";
		}
	}
	else cout << "error";
}

// ��֤�˻�
void log_in()
{
	account A;
	A.get_account();
	A.check_account();
}
