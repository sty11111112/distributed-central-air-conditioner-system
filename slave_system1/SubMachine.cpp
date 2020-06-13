#include "SubMachine.h"

struct SubMachine::recv_String {
	int ansid;
	int recv_request;   //接收的请求类型
	int room_id;
	float recv_curTemp;
	int recv_temp;
	int recv_wind;
	int recv_mode;
	float recv_fee;
};

struct SubMachine::out_time {
	char *buf;
	int len;
	char time;
	int count;
};

int SubMachine::init_socket()
{
	WSAData wsa;
	WORD sockVersion = MAKEWORD(2, 2);
	if (WSAStartup(sockVersion, &wsa) != 0)
	{
		WSACleanup();
		printf("初始化失败\n");
		return -1;
	}

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(53);
	ser_addr.sin_addr.s_addr = INADDR_ANY;

	if (connect(sockfd, (SOCKADDR *)&ser_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		cout << "与中央空调连接失败！" << endl;
		return -1;
	}
	else {
		cout << "与中央空调连接成功！" << endl;
	}

	return 1;

}

bool SubMachine::is_response(char * recv_buffer) {
	unsigned short flags = 0;
	memcpy(&flags, recv_buffer + 2, 2);
	if (flags == 0x8081)
		return 1;
	else
		return 0;
}

void SubMachine::sendToServer(char * buffer, int buffer_size) {
	if (sendto(sockfd, buffer, buffer_size, 0, (struct sockaddr*)&ser_addr, sizeof(struct sockaddr)) == -1)
	{
		printf("未成功发送请求至中央空调\n");
		return;
	}
}

void SubMachine::set_room_num(int temp)
{
	room_num = temp;
	printf("房间号设置为:%d\n", room_num);

}
void SubMachine::set_target_temp(int temp)
{
	target_temp = temp;
	printf("目标温度设置为:%d\n", target_temp);
}
void SubMachine::set_current_temp(float temp)
{
	current_temp = temp;
	printf("当前温度为:%f\n", current_temp);
}
void SubMachine::set_current_wind(int temp)
{
	current_wind = temp;
	if (current_wind == LOW) {
		printf("目标风速设置为:LOW\n");
		last_wind = current_wind;
	}
	if (current_wind == MEDIUM) {
		printf("目标风速设置为:MEDIUM\n");
		last_wind = current_wind;
	}
	if (current_wind == HIGH) {
		printf("目标风速设置为:HIGH\n");
		last_wind = current_wind;
	}
	if (current_wind == NULL)
		printf("停止送风\n");
}
void SubMachine::set_fee(float temp)
{
	fee = temp;
	energy = fee / 5.0;
	printf("住户费用为:%f\n", fee);
	printf("消耗能量为:%f\n", energy);
}
void SubMachine::set_working_state(int temp)
{
	working_state = temp;
}
void SubMachine::set_main_working_mode(int temp)
{
	main_working_mode = temp;
	if (main_working_mode == HEAT)
		printf("供暖模式\n");
	if (main_working_mode == COOL)
		printf("制冷模式\n");
}

int SubMachine::get_room_num()
{
	return room_num;
}
int SubMachine::get_target_temp()
{
	return target_temp;
}
float SubMachine::get_current_temp()
{
	return current_temp;
}
int SubMachine::get_current_wind()
{
	return current_wind;
}
float SubMachine::get_fee()
{
	return fee;
}
int SubMachine::get_working_state()
{
	return working_state;
}
int SubMachine::get_main_working_mode()
{
	return main_working_mode;
}

void SubMachine::set_RoomID(int id) {
	set_room_num(id);
}
int SubMachine::CloseMachine() {

	islink = 1;
	set_main_working_mode(-1);
	set_working_state(OFF);
	set_current_temp(NULL);
	set_target_temp(NULL);
	set_current_wind(NULL);
	closesocket(sockfd);
	//释放DLL资源
	WSACleanup();
	printf("从控机成功被关闭\n");
	return 1;
}

int SubMachine::OpenMachine() {
	printf("初始化socket...\n");

	if (init_socket() == -1) {
		return -1;
	}
	islink = 1;
	set_working_state(ON);
	printf("初始化成功... \n");
	printf("从控机成功被开启\n");
	set_current_temp(25);
	main_working_mode = COOL;
	current_wind = 1;
	b = clock();
	h = clock();
	return 1;
}


int SubMachine::increaseTargetTemp() {
	flag++;
	f = clock();
	return 1;
}

int SubMachine::decreaseTargetTemp() {
	flag--;
	f = clock();
	return 1;
}

void SubMachine::changeWindSpeed(int newspeed) {
	char send_buffer[512];
	recv_String req;
	clock_t z = clock();
	req.recv_mode = 4;
	req.room_id = room_num;
	Ans_id++;
	req.ansid = Ans_id;
	req.recv_wind = newspeed;
	memset(send_buffer, 0, 512);
	memcpy(send_buffer, &req, sizeof(req));
	sendToServer(send_buffer, sizeof(send_buffer));
	out_time ans;
	ans.buf = send_buffer;
	ans.len = sizeof(send_buffer);
	ans.time = z;
	ans.count = 0;
	time_table.insert(pair<unsigned long, out_time>(Ans_id, ans));
}

void SubMachine::Start()
{
	char send_buffer[512];
	char recv_buffer[512];
	SOCKADDR_IN recv_addr;
	int recv_size;
	clock_t z = clock();
	clock_t r;

	if (working_state == ON) {
		//温度自然变化
		if (current_wind = NULL) {
			if (z - b >= 10000) {
				if (main_working_mode == COOL)
					current_temp = current_temp + 1;
				if (main_working_mode == HEAT)
					current_temp = current_temp - 1;
				b = clock();
			}
		}
		//低风速
		if (current_wind == LOW) {
			if (z - b >= 25000) {
				if (current_temp > target_temp)
					current_temp = current_temp - 1;
				if (current_temp < target_temp)
					current_temp = current_temp + 1;
				b = clock();
			}
		}
		//中风速
		if (current_wind == MEDIUM) {
			if (z - b >= 20000) {
				if (current_temp > target_temp)
					current_temp = current_temp - 1;
				if (current_temp < target_temp)
					current_temp = current_temp + 1;
				b = clock();
			}
		}
		//高度风
		if (current_wind == HIGH) {
			if (z - b >= 15000) {
				if (current_temp > target_temp)
					current_temp = current_temp - 1;
				if (current_temp < target_temp)
					current_temp = current_temp + 1;
				b = clock();
			}
		}
	}
	if (working_state == ON) {
		for (it = time_table.begin(); it != time_table.begin(); it++) {
			if (z - (it->second.time) > 2000) {
				//重发次数达到5次，判断链接断开，5秒后进行重连
				if (time_table[it->first].count >= 5) {
					if (islink == 1) 
						islink = 0;//设置为重连状态
						
					if (islink == 0) {
						r = clock();
						islink--;
					}
					if (z - r >= 5000) {
						closesocket(sockfd);
						//释放DLL资源
						WSACleanup();
						if (init_socket() == -1) {
							islink = 0;
							break;
						}
						islink = 1;
						time_table.clear();
					}
					break;
				}
				else {
					sendToServer(it->second.buf, it->second.len);
					printf("请求发送超时，重发\n");
					time_table[it->first].time = z;
					time_table[it->first].count++;
				}
			}
		}
	}

	//温度达到目标温度
	if (working_state == ON) {
		struct recv_String tem;
		memset(&tem, 0, sizeof(tem));
		if (current_temp == target_temp) {
			tem.recv_mode = 4;
			tem.room_id = room_num;
			tem.recv_wind = NULL;
			Ans_id++;
			tem.ansid = Ans_id;
			memset(send_buffer, 0, 512);
			memcpy(send_buffer, &tem, sizeof(tem));
			sendToServer(send_buffer, sizeof(send_buffer));
			out_time ans;
			ans.buf = send_buffer;
			ans.len = sizeof(send_buffer);
			ans.time = z;
			ans.count = 0;
			time_table.insert(pair<unsigned long, out_time>(Ans_id, ans));
		}
	}

	//目标状态下，温差超过1度
	if (working_state == ON) {
		struct recv_String tem;
		memset(&tem, 0, sizeof(tem));
		if (abs(target_temp - current_temp) >= 1 && current_wind == NULL) {
			tem.recv_mode = 4;
			tem.room_id = room_num;
			tem.recv_wind = last_wind;
			Ans_id++;
			tem.ansid = Ans_id;
			memset(send_buffer, 0, 512);
			memcpy(send_buffer, &tem, sizeof(tem));
			sendToServer(send_buffer, sizeof(send_buffer));
			out_time ans;
			ans.buf = send_buffer;
			ans.len = sizeof(send_buffer);
			ans.time = z;
			ans.count = 0;
			time_table.insert(pair<unsigned long, out_time>(Ans_id, ans));
		}
	}

	struct recv_String req;

	if (working_state == ON && z - h >= 5000) {
		req.room_id = room_num;
		req.recv_mode = -1;
		Ans_id++;
		req.ansid = Ans_id;
		memset(send_buffer, 0, 512);
		memcpy(send_buffer, &req, sizeof(req));
		sendToServer(send_buffer, sizeof(send_buffer));
		h = clock();
		out_time ans;
		ans.buf = send_buffer;
		ans.len = sizeof(send_buffer);
		ans.time = z;
		ans.count = 0;
		time_table.insert(pair<unsigned long, out_time>(Ans_id, ans));
	}

	if (working_state == ON) {
		//温度请求
		if (z - f >= 1000) {
			req.room_id = room_num;
			Ans_id++;
			req.ansid = Ans_id;
			req.recv_mode = 3;
			req.recv_temp = target_temp + flag;
			flag = 0;
			memset(send_buffer, 0, 512);
			memcpy(send_buffer, &req, sizeof(req));
			sendToServer(send_buffer, sizeof(send_buffer));
			out_time ans;
			ans.buf = send_buffer;
			ans.len = sizeof(send_buffer);
			ans.time = z;
			ans.count = 0;
			time_table.insert(pair<unsigned long, out_time>(Ans_id, ans));
		}
	}

	if (working_state == ON) {
		int recv_len = sizeof(sockaddr);
		memset(recv_buffer, 'z', 512);
		if ((recv_size = recvfrom(sockfd, recv_buffer, sizeof(recv_buffer), 0, (sockaddr *)&recv_addr, &recv_len)) == -1)
		{
			printf("接收包错误\n");
		}
		//接受来自中央空调的控制和响应信息
		else if (is_response(recv_buffer)) {
			//模式与缺省温度设置
			struct recv_String res;
			memset(&res, 0, sizeof(res));
			memcpy(&res, recv_buffer, sizeof(res));

			if (res.recv_request == -1) {
				if (res.room_id == room_num) {
					if (time_table.find(res.ansid) == time_table.end()) {

					}
					else {
						time_table.erase(res.ansid);
					}
				}
			}

			if (res.recv_request == 1) {
				if (res.room_id == room_num) {
					set_target_temp(res.recv_temp);
					set_main_working_mode(res.recv_mode);
					if (time_table.find(res.ansid) == time_table.end()) {

					}
					else {
						time_table.erase(res.ansid);
					}
				}
			}
			//查询温度请求
			if (res.recv_request == 2) {
				if (res.room_id == room_num) {
					res.room_id = room_num;
					res.recv_curTemp = current_temp;
					Ans_id = Ans_id + 1;
					res.ansid = Ans_id;
					memset(send_buffer, 0, 512);
					memcpy(send_buffer, &res, sizeof(res));
					sendToServer(send_buffer, sizeof(send_buffer));
					out_time ans;
					ans.buf = send_buffer;
					ans.len = sizeof(send_buffer);
					ans.time = z;
					ans.count = 0;
					time_table.insert(pair<unsigned long, out_time>(Ans_id, ans));
				}
			}
			//温度设置响应
			if (res.recv_request == 3) {
				if (res.room_id == room_num) {
					set_target_temp(res.recv_temp);
					if (time_table.find(res.ansid) == time_table.end()) {

					}
					else {
						time_table.erase(res.ansid);
					}
				}
			}
			//风速设置响应
			if (res.recv_request == 4) {
				if (res.room_id == room_num) {
					set_current_wind(res.recv_wind);
					if (time_table.find(res.ansid) == time_table.end()) {

					}
					else {
						time_table.erase(res.ansid);
					}
				}
			}
			//用量及费用
			if (res.recv_request == 5) {
				if (res.room_id == room_num) {
					set_fee(res.recv_fee);
					if (time_table.find(res.ansid) == time_table.end()) {

					}
					else {
						time_table.erase(res.ansid);
					}
				}
			}
		}
	}
}

int SubMachine::islinked() {
	if (islink == 1)
		return 1;
	else
		return -1;
}

SubMachine::SubMachine()
{
	islink = 1;
	set_main_working_mode(-1);
	set_working_state(OFF);
	set_current_temp(NULL);
	set_target_temp(NULL);
	set_current_wind(NULL);
	closesocket(sockfd);
	//释放DLL资源
	WSACleanup();

	time_table.clear();

}


SubMachine::~SubMachine()
{
}
