/* 
 * File:   cstring.cpp
 * Author: Miguel-Portable
 * 
 * Created on 17. mars 2017, 14:34
 */

#include "cstring.h"

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdexcept>

String::String() : String(""){
}

String::String(const char* const string){
    this->string = new char[strlen(string)];
    strcpy(this->string, string);
}

String::String(const String& orig) : String(orig.string){
}

String::~String() {
    delete[] string;
}

String::String(const char c){
    this->string = new char[2];
    string[0] = c;
    string[1] = END;
}

String::String(const int number){
    
    int numTemp;
    int size;
    
    if(number >= 0){
        numTemp = number;
        size = floor(log10(numTemp)) + 2;
    }else{
        numTemp = -number;
        size = floor(log10(numTemp)) + 3;
    }
    
    this->string = new char[size];
    
    int limit = 0;
    if(number < 0){
        string[0] = '-';
        limit = 1;
    }
    
        for (int i = size - 2; i >= limit; i--) {
        char c = ((char)(numTemp % 10)) + '0';
        string[i] = c;
        numTemp /= 10;
    }
    
    string[size - 1] = END;
}

String::String(const double d){
    this->string = new char[25];
    sprintf(this->string, "%30f", d);
}

String::String(const bool b) : String((b ? "1" : "0")){}

unsigned String::size() const{
    return strlen(string);
}

void String::display(){
    printf("%s\n", string);
}

String& String::concat(const String& orig) {
    
}


char& String::getChar(unsigned int index){
    if(index >= size()){
        throw std::out_of_range("out of bounds");
    }
    
    char& c = string[index];
    
    return c;
}

char& String::operator[](unsigned int index){
    return getChar(index);
}

