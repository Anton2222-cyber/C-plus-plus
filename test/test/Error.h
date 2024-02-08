#pragma once
class Error
{
protected:
	int code;
	char* name;
public:
	Error(int code, const char* name);
	~Error();
	void Show();

};

