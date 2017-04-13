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
        
    unsigned size() const;
    
    bool equals(const String& orig) const;
    
    const char* asCharArray() const;
    
    char& getChar(unsigned int index);
    char& operator[](unsigned int index);
    
    String substring(unsigned int start, unsigned int length) const;
    
    String concat(const String& orig) const;
    String concat(const char c) const;
    String concat(const char* const orig) const;
    
    String& append(const String& orig);
    String& append(const char c);
    String& append(const char* const orig);
    
    void setString(const String& orig);
    void setString(char c);
    void setString(const char* const orig);
    
    friend std::ostream& operator << (std::ostream&, const String&);
    String& operator = (const String& s);

    String operator += (const String& s);
    String operator += (const char c);
    String operator += (const char* const orig);
    
    friend String operator + (String lhs, const String& rhs);
//    friend String operator + (String lhs, const char rhs);
//    friend String operator + (String lhs, const char* const rhs);
    
    
private:
    char* string;
    const char END = '\0';
    const int BUFFER_SIZE = 25;
    
    void allocate(const char* const orig);
};

bool operator == (const String& orig1, const String& orig2);

#endif	/* CSTRING_H */

