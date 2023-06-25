#include "Manager.h"
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>
#pragma warning(disable: 4996)
Manager::~Manager()
{
    delete[] buffer;
    delete json;
}

void Manager::open(std::ifstream& ifs)
{
	try {
        char current;
        std::stringstream ss;
        if (!ifs.is_open()) {
            throw std::runtime_error("stream not opened");
        }
        while (ifs >> current) {
            ss << current;
        }
        isOpened = true;
        
        size_t len = ss.str().length();
        buffer = new char[len * 2];
        std::strcpy(buffer, ss.str().c_str());
        sview sv{ buffer, buffer + len };
        json = factory(sv);
        
	}
	catch (std::runtime_error& ex) {
        std::cerr << ex.what() << std::endl;
	}
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "unknown error" << std::endl;
    }
}

void Manager::print() const
{
    if (isOpened)
        json->print();
    else
        std::cout << "Json not opened!" << std::endl;
}

void Manager::close() const
{
    std::exit(0);
}
