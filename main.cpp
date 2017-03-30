/* 
 * File:   main.cpp
 * Author: Miguel-Portable
 *
 * Created on 17. mars 2017, 14:23
 */

#include <typeinfo>
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
    String s6(-23.14159);
    
    
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();
    s6.display();
    
    return 0;
}

