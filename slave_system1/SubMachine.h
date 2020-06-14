#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <winsock2.h>
#include <string>
#include <map>
#include <fstream>
#include <winsock2.h>
#include <time.h>
#include <signal.h> 
#include <windows.h>
#pragma comment (lib, "ws2_32.lib") 

using namespace std;

//开关机
#define ON 1
#define OFF 0

//工作模式
#define COOL 0
#define HEAT 1

//风速
#define LOW 0
#define MEDIUM 1
#define HIGH 2

class SubMachine
{
public:
	SubMachine();
	~SubMachine();
	int get_room_num();
	int get_target_temp();
	int get_current_temp();
	int get_current_wind();
	int get_last_wind();
	double get_fee();
	int get_working_state();
	int get_main_working_mode();
	void set_RoomID(int id);
	void set_lastwind(int newspeed);
	int CloseMachine();
	int OpenMachine();
	int increaseTargetTemp();
	int decreaseTargetTemp();
	void changeWindSpeed(int newspeed);
	void Start();
	int islinked();
	void initial_temp(int temp);

private:
	SOCKET sockfd;
	sockaddr_in ser_addr;
	int room_num;
	int target_temp;
	int current_temp;
	int last_wind;
	int current_wind;
	double fee;
	double energy;
	int working_state;
	int main_working_mode;
	int islink;

	//用来标识发出的请求
	int Ans_id = 0;
	//用来标识温度请求的时间
	clock_t f;
	clock_t b;
	clock_t h;
	clock_t r;
	//用来标识调用温度指令的次数
	int flag;
	struct recv_String;
	struct identity;
	struct out_time;
	map<int, out_time> time_table;
	map<int, out_time> ::iterator it;
	int init_socket();
	bool is_response(char * recv_buffer);
	void sendToServer(char * buffer, int buffer_size);
	void set_room_num(int temp);
	void set_target_temp(int temp);
	void set_current_temp(int temp);
	void set_current_wind(int temp);
	void set_fee(double temp);
	void set_working_state(int temp);
	void set_main_working_mode(int temp);
};

