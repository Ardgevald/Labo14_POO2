/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo 14
 Fichier     : main.cpp
 Auteur(s)   : Théo Gallandat & Miguel Pombo Dias
 Date        : 13.04.2017

 But         : Fourni une série de test de la classe String

 Remarque(s) : R.A.S

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdexcept>
#include "cstring.h"


using namespace std;

void displayTestMessage(const char* message,const char* expectedResult ,const String& s){
    cout << left << setw(30) << message << endl
         << setw(8) << expectedResult << " : " << s << endl;
}

int main(int argc, char** argv) {

    String s1("Test");
    displayTestMessage("Constructeur via const char *", "Test", s1);
    
    String s2(s1);
    displayTestMessage("Constructeur de copie", "Test", s2);
    
    String s4('T');
    displayTestMessage("Constructeur via char", "T", s4);
    
    String s5(-95);
    displayTestMessage("Constructeur via int", "-95", s5);
    
    String s6(-23.14159);  
    displayTestMessage("Constructeur via double", "-23.141590", s6);
    
    String s7(true);
    displayTestMessage("Constructeur via bool", "true", s7);
    
    String s9("Test");
    s9.getChar(0) = 'F';
    displayTestMessage("Remplacement de caractere via getchar()", "Fest", s9);
    
    char& c = s9[1];
    c = 'a';
    displayTestMessage("Remplacement de caractere via []", "Fast", s9);
    
    s1.setString('c');
    displayTestMessage("Remplacement d'une string par une autre via setString", "c", s1);
    
    s1 = "Retest";
    displayTestMessage("Remplacement d'une string par une autre via =", "Retest", s1);
    
    s1 = 23;
    displayTestMessage("Remplacement d'une string par une autre via = (int)", "23", s1);
    
    s1 = s1 + s1;
    displayTestMessage("Concatenation de deux chaines avec + ", "2323", s1);
    
    
//    cout << boolalpha << s1.equals(s2) << endl;
//    cout << s2.equals("Test") << endl;
//    cout << s4.equals('T') << endl;
//    cout << (s1 == s2) << endl;
//    cout << (s1 == "Test") << endl;
//    cout << (s4 == 'T') << endl;
//    cout << ('T' == s4) << endl;
//    
//    const char* a = s7.asCharArray();
//    a++;
//    printf("%s\n", a);
//    cout << s7 << endl;
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
