/* 
 * File:   cstring.h
 * Author: Miguel-Portable
 *
 * Created on 17. mars 2017, 14:34
 */

#ifndef CSTRING_H
#define	CSTRING_H
#include <iostream>

class String {
public:
    String();
    String(const String& orig);
    virtual ~String();
    
    String(const char* const string);
    String(const char c);
    String(const int i);
    String(const double d);
    String(const bool b);
    
    void display();
    
    unsigned size() const;
    const char* asCharArray();
    
    char& getChar(unsigned int index);
    char& operator[](unsigned int index);
    friend std::ostream& operator << (std::ostream&, const String&);

    
    String concat(const String& orig);
    String concat(const char c);
    String concat(const char* const string);
    
    String& append(const String& orig);
    String& append(const char c);
    String& append(const char* const string);
    
    
    
    
private:
    char* string;
    const char END = '\0';
    
};

#endif	/* CSTRING_H */

