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
    cout << boolalpha << message << endl
         << left << setw(10) << expectedResult << " : " << s << endl << endl;
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
    
    s2 = s1 + s1;
    displayTestMessage("Concatenation de deux String avec + ", "2323", s2);
    
    s2 = s1 + s1 + "Test";
    displayTestMessage("Concatenation de deux String et une chaine avec +", "2323Test", s2);
    
    s2 = 23;
    s2 += "Test";
    displayTestMessage("Concatenation sur une chaîne avec +=", "23Test", s2);
    
    s2 = s1.equals(s1);
    displayTestMessage("Comparaison de Strings", "true", s2);
    
    s2 = s9.equals("Fast");
    displayTestMessage("Comparaison de String avec chaine", "true", s2);
    
    s9 = 'T';
    s2 = s9.equals('T');
    displayTestMessage("Comparaison de String avec char", "true", s2);
    
    String s3("Test");
    s1 = "Test";
    
    s2 = s1 == s3;
    displayTestMessage("Comparaison de Strings avec ==", "true", s2);
    
    s2 = s1 == "Test";
    displayTestMessage("Comparaison de String et chaine avec ==", "true", s2);
    
    s2 = s9 == 'T';
    displayTestMessage("Comparaison de String et char avec ==", "true", s2);
    
    displayTestMessage("Utilisation de asCharArray", s1.asCharArray(), s1);
    
    String s11("ABCDEFGH");
    String s12;
    try{
        s12 = s11.substring(3,3);
        displayTestMessage("Substring valide dans la String", "DEF", s12);
        
        s12 = s11.substring(3,15);
        displayTestMessage("Substring trop grand dans la String", "DEFGH", s12);
        
        s12 = s11.substring(18,3);
        displayTestMessage("Substring invalide dans la String", "Erreur", s12);
    }catch(const out_of_range& e){
        cout << e.what() << endl;
    }
    
    
    return 0;
}
