#pragma once
struct sview {
public:
	sview();
	sview(char* begin, char* end);
	sview ltrim() const;
	sview rtrim() const;
	sview trim() const;
	void print() const;
	char operator[](size_t idx) const;//Angel55 repo
	char* beginPtr() const;
	char* endPtr() const;
	size_t length() const;
private:
	char* begin;
	char* end;
};  
