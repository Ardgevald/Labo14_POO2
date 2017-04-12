/* 
 * File:   main.cpp
 * Author: Miguel-Portable
 *
 * Created on 17. mars 2017, 14:23
 */

#include <cstdlib>
#include <iostream>
#include "cstring.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    String s1("Test");
    String s2("Test2");
    String s3(s2);
    String s4('T');
    String s5(-95);
    String s6(23.14159);    
    String s7(true);
    String s8(false);
    String s9("Test");
    s9.getChar(0) = 'F';
    s9[1] = 'a';
    
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();
    s6.display();
    s7.display();
    s8.display();
    s9.display();
    
    return 0;
}

