/* 
 * File:   main.cpp
 * Author: Miguel-Portable
 *
 * Created on 17. mars 2017, 14:23
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "cstring.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    String s1("Test1");
    String s2("Test2");
    String s3(s2);
    String s4('T');
    String s5(-95);
    String s6(23.14159);    
    String s7(true);
    String s8(false);
    String s9("Test");
    s9.getChar(0) = 'F';
    
    s1.setString('c');
    cout << s1 << endl;
    
//    char& c = s9[1];
//    cout << c << endl;
//    c = 'a';
//    String s10("Test");
//    s10.append("23").append(s5).append('!');
//    
//    cout << s1 << endl;
//    cout << s2 << endl;
//    cout << s3 << endl;
//    cout << s4 << endl;
//    cout << s5 << endl;
//    cout << s6 << endl;
//    cout << s7 << endl;
//    cout << s8 << endl;
//    cout << s9 << endl;
//    cout << s10 << endl;    
//    cout << boolalpha << s3.equals(s2) << endl;
//    cout << s3.equals("Test") << endl;
//    cout << s4.equals('T') << endl;
//    cout << (s3 == s2) << endl;
//    cout << (s3 == "Test") << endl;
//    cout << (s4 == 'T') << endl;
//    cout << ('T' == s4) << endl;
    
//    const char* a = s10.asCharArray();
//    a++;
//    printf("%s\n", a);
//    cout << s10 << endl;
//    
//    String s11("ABCDEFGH");
//    try{
//        cout << s11.substring(3,3) << endl;
//        cout << s11.substring(3,15) << endl;
//        cout << s11.substring(18,3) << endl;
//    }catch(const out_of_range& e){
//        cout << e.what() << endl;
//    }
    return 0;
}

