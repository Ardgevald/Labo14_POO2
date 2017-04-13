/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo 14
 Fichier     : cstring.h
 Auteur(s)   : Théo Gallandat & Miguel Pombo Dias
 Date        : 13.04.2017

 But         : Fourni une classe représentant une string, a la manière de la lib
               Srting

 Remarque(s) : R.A.S

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef CSTRING_H
#define	CSTRING_H
#include <iostream>

class String {
public:
   /**
    * Constructeur vide
    */
    String();
    
    /**
     * Constructeur de copie
     * @param orig la string a copier
     */
    String(const String& orig);
    
    /**
     * Destructeur
     */
    virtual ~String();
    
    /**
     * Constructeur pour une chaine de caractères
     * @param string
     */
    String(const char* const string);
    
    /**
     * Constructeur pour un caractère unique
     * @param c
     */
    String(const char c);
    
    /**
     * Constructeur pour un int
     * @param i
     */    
    String(const int i);
    
    /**
     * Constructeur pour un double
     * @param d
     */
    String(const double d);
    
    /**
     * Constructeur pour un booleen
     * @param b
     */
    String(const bool b);
    
    /**
     * Taille de la string
     * @return taille
     */
    unsigned size() const;
    
    /**
     * Verifie si deux instance de string sont égales
     * @param orig string a comparer
     * @return true ou false
     */
    bool equals(const String& orig) const;
    
    /**
     * Retourne la string en temps que tableau de caractères constant
     * @return tableau de char constant
     */
    const char* asCharArray() const;
    
    /**
     * Retourne un caratctere a un index donner et permet de le modifier.
     * @param index
     * @return caractere voulu
     */
    char& getChar(unsigned int index);
    
    /**
     * Surcharge de l'opérateur [], permet un acces a un caractere voulu et modifiable
     * @param index
     * @return caractere
     */
    char& operator[](unsigned int index);
    
    /**
     * Crée une sous-string d'une string
     * @param start : le début voulu
     * @param length : la longueur voulu
     * @return la sous string
     */
    String substring(unsigned int start, unsigned int length) const;
    
    /**
     * Permet la concatenation de d'une String, d'un caractère ou d'une chaine de
     * caractère
     * @param orig : String, caractère ou chaine de caractère.
     * @return une nouvelle string
     */
    String concat(const String& orig);
    String concat(const char c);
    String concat(const char* const orig);
    
    /**
     * Permet la concatenation de d'une String, d'un caractère ou d'une chaine de
     * caractère
     * @param : String, caractère ou chaine de caractère.
     * @return la string modifiée
     */
    String& append(const String& orig);
    String& append(const char c);
    String& append(const char* const orig);
    
    /**
     * Permet de modifier l'instance d'une String (changer la chaine de caractère)
     * @param orig
     */
    void setString(const String& orig);
    void setString(char c);
    void setString(const char* const orig);
    
    /**
     * Surcharge de l'opérateur << pour permettre un affichage de la String
     * @param s
     * @return 
     */
    friend std::ostream& operator << (std::ostream&, const String& s);
    
    /**
     * Surcharges de l'opérateur = pour l'affectation
     * @param : String, caractère ou chaine de caractère.
     * @return 
     */
    String& operator = (const String& s);

    /**
     * Surcharges de l'opérateur += pour l'affectation
     * @param : String, caractère ou chaine de caractère.
     * @return 
     */
    String operator += (const String& s);
    String operator += (const char c);
    String operator += (const char* const orig);
    
    /**
     * Surcharge de l'opérateur + pour permettre une concatenation de deux String
     * @param lhs et rhs les 2 opérandes
     */
    friend String operator + (String lhs, const String& rhs);
//    friend String operator + (String lhs, const char rhs);
//    friend String operator + (String lhs, const char* const rhs);
    
    
private:
   // chaine de caractère qui représente la string
    char* string;
    
    //caractère de fin de chaine
    const char END = '\0';
    
    //taille max du buffer
    const int BUFFER_SIZE = 25;
    
    //Fonction d'allocation de mémoire pour le setString
    void allocate(const char* const orig);
};

/**
 * Surcharge de l'opérateur ==  qui permet de verifier si 2 instance sont les meme
 * @param orig1
 * @param orig2
 * @return true ou false
 */
bool operator == (const String& orig1, const String& orig2);

#endif	/* CSTRING_H */

