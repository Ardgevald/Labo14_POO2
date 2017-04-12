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
#include <algorithm>

String::String() : String(""){
}

String::String(const char* const orig){
    string = new char[strlen(orig)];
    strcpy(string, orig);
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
    string = new char[BUFFER_SIZE];
    snprintf(string, BUFFER_SIZE ,"%f", d);
}

String::String(const bool b) : String((b ? "1" : "0")){}

unsigned String::size() const{
    return strlen(string);
}

bool String::equals(const String& orig) const {
    return strcmp(string, orig.string) == 0;
}

bool operator==(const String& orig1, const String& orig2) {
    return orig1.equals(orig2);
}

const char* String::asCharArray() const{
    return string;
}

String String::substring(unsigned int start, unsigned int length) const{
    if(start > size()){
        throw std::out_of_range("String is smaller than start");
    }
    
    length = std::min(length, size() - start);
    
    char* s = new char[length + 1];
    strncpy(s, string + start, length);
    s[length] = END;
    
    return String(s);
}


void String::display(){
    printf("%s\n", string);
}

String String::concat(const String& orig) {
    String temp(this);
    this->append(orig);
    return temp;
}

String String::concat(const char* const orig) {
    String temp(this);
    this->append(orig);
    return temp;
}

String String::concat(const char c) {
    String temp(this);
    this->append(c);
    return temp;
}

String& String::append(const String& orig) {
    return this->append(orig.string);
}

String& String::append(const char c) {
    return this->append(&c);
}

String& String::append(const char* const orig) {
    char* s = new char[size() + strlen(orig) + 1];
    strcpy(s, string);
    strcpy(s + size(), orig);
    
    delete[] string;
    string = s;
}

char& String::getChar(unsigned int index){
    if(index >= size()){
        throw std::out_of_range("out of range");
    }
    
    return string[index];
}

char& String::operator[](unsigned int index){
    return getChar(index);
}
std::ostream& operator<<(std::ostream& os, const String& s) {
   String copie(s);
   for (int i = 0; i < s.size(); i++) {
      os << copie[i];
   }
   return os;
}