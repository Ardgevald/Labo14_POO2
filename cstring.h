/* 
 * File:   cstring.h
 * Author: Miguel-Portable
 *
 * Created on 17. mars 2017, 14:34
 */

#ifndef CSTRING_H
#define	CSTRING_H

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
    
    bool equals(const String& orig) const;
    
    const char* asCharArray() const;
    
    char& getChar(unsigned int index);
    char& operator[](unsigned int index);
    
    String substring(unsigned int start, unsigned int length) const;
    
    String concat(const String& orig);
    String concat(const char c);
    String concat(const char* const orig);
    
    String& append(const String& orig);
    String& append(const char c);
    String& append(const char* const orig);
    
private:
    char* string;
    const char END = '\0';
    
};

bool operator==(const String& orig1, const String& orig2);

#endif	/* CSTRING_H */

