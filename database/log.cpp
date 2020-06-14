#include<iostream>
#include"log.h"
using namespace std;


void account::get_account()
{
	cout << "ÇëÊäÈë·¿¼äºÅ£º" << endl;
	cin >> room_num;
	cout << "ÇëÊäÈëÉí·ÝÖ¤ºÅ£º" << endl;
	cin >> id;
}

void account::check_account()
{
	if (room_num == 1) {
		if (id == 11111111) {
			cout << "µÇÂ¼³É¹¦";
		}
		else {
			cout << "µÇÂ¼Ê§°Ü";
		}
	}
	else if (room_num == 2) {
		if (id == 22222222) {
			cout << "µÇÂ¼³É¹¦";
		}
		else {
			cout << "µÇÂ¼Ê§°Ü";
		}
	}
	else if (room_num == 3) {
		if (id == 33333333) {
			cout << "µÇÂ¼³É¹¦";
		}
		else {
			cout << "µÇÂ¼Ê§°Ü";
		}
	}
	else cout << "error";
}

// ÑéÖ¤ÕË»§
void log_in()
{
	account A;
	A.get_account();
	A.check_account();
}
