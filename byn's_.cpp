#include "UserINFO.h"
#include "SeatINFO.h"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>

using namespace std;

void write_usr(string name, int resnum, int seatnum) { //������ȣ ���� �� ����� ���Ͽ� �����ϴ� �Լ�
	User usr(name, resnum, seatnum); // ���� ����ü ����
	string filepath = "./UserList.dat"; // ����� ����
	int fd = open(filepath.c_str(), O_CREAT | O_APPEND | O_WRONLY, 0644); //����
	if (fd == -1) {
		perror("open() error");
		//return 1;
	}
	if (write(fd, &usr, sizeof(User)) == -1) { // ��
		perror("write() error");
		// return 2;
	}

	close(fd);//����
}

void read_usr(int resNum) { //���� Ȯ�� �� �� �Էµ� ������ȣ�� ����� ���Ͽ� �ִ��� Ȯ���ϴ� �Լ�
	string filepath = "./UserList.dat";
	int fd = open(filepath.c_str(), O_RDONLY);
	if (fd == -1) {
		perror("open() error");
		// return 1;
	}
	ssize_t rSize = 0;
	User usr = User();
	list<User> usrList;
	do {
		rSize = read(fd, &sur, sizeof(User)); // ���� ����ü ������ �о

		if (rSize == -1) {
			perror("read() error!");
			// return 2;
		}

		if (rSize == 0) {
			/// break;
		}

		usrList.push_back(usr);// ��������Ʈ�� �ִ´�.
	} while (rSize > 0);

	close(fd);

	list<User>::iterator iter;

	for (iter = usrList.begin(); iter != usrList.end(); ++iter) { // ��������Ʈ ��ġ ���� ������ȣ ã���� 
		if (iter->getResNum == resNum)
			cout << getSeatNum << " �¼� ���� �Ǿ��ֽ��ϴ�." << endl; // ���
		else
			cout << "������ �¼��� �����ϴ�." << endl; // ��ã���� ���
	}
}

int main(int argc, int argv[]) {

	list <User> UL; //User List
	list <Seat> SL; //Seat List



	return 0;
}