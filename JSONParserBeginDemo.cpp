#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cstdlib>
struct sview{
public:
    sview():begin(nullptr), end(nullptr) {
        std::cout << "sview()" << std::endl;
    }
    sview(char* begin, char* end):begin(begin), end(end) {
        std::cout << "sview(params)" << std::endl;
    }
    sview ltrim(){
        if(begin > end)
            throw std::invalid_argument("begin > end");
        char* current = begin;
        while(current < end){
            if(std::isspace(*current) == 0){
                break;
            }
            ++current;
        }
        return {current, end};
    }
    sview rtrim(){
        if(begin > end)
            throw std::invalid_argument("begin > end");
        char* current = end - 1;
        while(current > begin && std::isspace(*current) != 0){
            --current;
        }
        return {begin, current + 1};
    }
    sview trim(){
        return ltrim().rtrim();
    }
    void print() const{
        size_t len = end - begin;
        char* current = begin;
        for(size_t i = 0; i < len; i++){
            std::cout << *current;
            ++current;
        }
        std::cout << std::endl;
    }
    char operator[](size_t idx) const{
        return *(begin + idx);
    }
    sview substr(size_t from, size_t to){
        return { begin + from, begin + from + to };
    }
    size_t length() const{
        return end - begin;
    }
private:
    char* begin;
    char* end;
};

struct Value{
public:
    virtual ~Value() = default;
    virtual void print() const = 0;
    virtual void parse(sview s) = 0;
};
Value* factory(sview s);
struct Object: public Value{
public:
    Object():value(nullptr) {}
    void parse(sview s) override{
        size_t i = 0;
        while(s[i] != ':'){
            ++i;
        }
        key = s.substr(0, i);
        key = key.trim();
        sview valueStr = s.substr(i + 1, s.length() - (i + 1));
        value = factory(valueStr);
        value->parse(valueStr);
    }
    void print() const override{
        std::cout << "Key:";
        key.print();
        std::cout << " Value:";
        value->print();
    }
    ~Object(){
        delete value;
    }
private:
    sview key;
    Value* value;
};

struct Number: public Value{
public:
    Number(sview number){
        parse(number);
    }
    void parse(sview number) override{
        sview trimmed = number.trim();
        const size_t len = trimmed.length();
        char buffNum[len];
        for(size_t i = 0; i < len; i++){
            buffNum[i] = trimmed[i];
        }
        num = std::atof(buffNum);
    }
    void print() const override{
        std::cout << num << " "; 
    }
private:
    double num;
};

Value* factory(sview s){
    s = s.trim();
   
    if(s[0] == '{' && s[s.length() - 1] == '}'){
        sview objWithoutBrakets = s.substr(1, s.length()-2);
        Object* obj = new Object();
        obj->parse(objWithoutBrakets);
        return obj;
    }
    if(s[0] >= '0' && s[0] <= '9'){
        Number* num = new Number(s);
        num->parse(s);
        return num;
    }
    return nullptr;
}
int main()
{
    char json[] = "   { \" hello \": {\"margi\" : 13}  }   ";
    sview s(json, json + strlen(json));
    //s.print();
    Value* jsonV = factory(s);
    jsonV->print();
    
    return 0;
}
