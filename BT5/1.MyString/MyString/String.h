#ifndef STRING_H_
#define STRING_H_
#include<iostream>
using std::ostream;
using std::istream;
class String{
    private:
        char * Str;
        int Len;
        static int Num_strings;      //numbers of object
        static const int CINLIN =80 ;//cin input limit
    public:
    //Constructor and other methods
        String(const char * s);      //Constuctor
        String();                    //default constructor
        String(const String &);      //copy constructor
        ~String();
        int GetterLen() const;
        void ReverseString();
        void ToUpperString();
        void ToLowerString();
    //overload operator methods
        String & operator =(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        const char &operator[](int i) const;
    //overload operator friends
        friend String operator+(String &St1,const String & St2);
        friend ostream & operator<<(ostream & os,const String & st);
        friend istream & operator>>(istream & is,String & st);
    //static function
        static int HowMany();
};
#endif