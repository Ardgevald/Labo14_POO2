/* 
 * File:   cstring.cpp
 * Author: Miguel-Portable
 * 
 * Created on 17. mars 2017, 14:34
 */

#include "cstring.h"

#include <string.h>
#include <stdio.h>

String::String(){
    String("");
}

String::String(const char* const string){
    int i;
    for (i = 0; i < strlen(string) ; i++) {
        *(this->string + i) = *(string + i);
    }
    *(this->string + i) = END;
}

String::~String() {
    
}

void String::display(){
    printf("%s\n", string);
}
