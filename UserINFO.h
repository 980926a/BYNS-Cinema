#ifndef __USERINFO_H__
#define __USERINFO_H__


#include <string>
#define MAX_Booker_LEN 32

class User {
public:
	User();
	User(std::string name, int resNum); //resNum=�����ȣ, name= �̸�

	void setName(std::string name);
	void setResNum(int resNum);

	std::string getName(void);
	int getResNum(void);

private:
	char name[MAX_Booker_LEN + 1];
	int resNum;
};


#endif