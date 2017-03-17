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
    String(const char* const string);
    String(const char c);
    String(const int i);
    String(const double d);
    String(const bool b);
    String(const String& orig);
    
    void display();
    
    int size() const;
    const char* asCharArray();
    
    virtual ~String();
private:
    char* string;
    const char END = '\0';
};

#endif	/* CSTRING_H */

