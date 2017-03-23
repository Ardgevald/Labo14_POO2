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

String::String(){
    String("");
}

String::String(const char* const string){
    
    this->string = new char[strlen(string)];
    
    int i;
    for (i = 0; i < strlen(string) ; i++) {
        *(this->string + i) = *(string + i);
    }
    *(this->string + i) = END;
}

String::String(const char c){
    String("" + c);
}

String::String(const int number){
    
    int numTemp;
    int size;
    
    if(number < 0){
        numTemp = number;
        size = floor(log10(number)) + 1;
    }else{
        numTemp = -number;
        size = floor(log10(number)) + 2;
    }
    
    this->string = new char[size];
    
    for (int i = size; i >= 0; i--) {
        *(this->string + i) = (char)(number / pow(10, i));
    }
}

String::String(const String& orig){
    this->string = new char[orig.size()];
    
    memcpy(this->string, orig.string, orig.size());
}

unsigned String::size() const{
    return strlen(string);
}

String::~String() {
    delete[] string;
}

void String::display(){
    printf("%s\n", string);
}


