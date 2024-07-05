#include"String.h"
#include<cstring>
using namespace std;
//initializing static  class member
int String::Num_strings =0;
//Constructor and other methods
String::String(const char * s){
    Len=strlen(s);
    Str=new char[Len+1];
    strcpy(Str,s);
    Num_strings++;
}
 String::String(){
    Len=2;
    Str =new char[1];
    Str[0]='\0';
    Num_strings++;
}
String::String(const String & s){
    Len=s.Len;
    Str = new char [Len+1];
    strcpy(Str,s.Str);
    Num_strings++;
}
String::~String(){
    --Num_strings;
    delete [] Str;
}
int String::GetterLen() const{
    return Len;
}
//overload operator methods
String & String::operator =(const String & s){
    if(this==&s)
        return *this;
    Len=s.Len;
    delete [] Str;
    Str =new char[Len+1];
    strcpy(Str,s.Str);
    return * this;
}
String & String::operator=(const char * s){
    Len=strlen(s);
    delete[] Str;
    Str=new char [Len+1];
    strcpy(Str,s);
    return *this;
}
char & String::operator[](int i){
    return Str[i];
}
const char & String::operator[](int i) const{
    return Str[i];
}
ostream & operator<<(ostream & os,const String & st){
    os<< st.Str;
    return os;
}
istream & operator>>(istream & is,String & st){
    char temp[String::CINLIN];
    is.get(temp,String::CINLIN);
    if(is){
        st=temp;
    }
    while(is&&is.get()!='\n')
        continue;
    return is;
}
    //static function
int String::HowMany(){
    return Num_strings;
}
void String::ReverseString(){
    char * TempStr=new char[Len+1];
    int j=0;
    for(int i=this->Len-1;i>=0;i--){
        TempStr[j++]=this->Str[i];
    }
    delete [] Str;
    this->Str=TempStr;
}
void String::ToUpperString(){
    for(int i=this->Len-1;i>=0;i--){
        this->Str[i]=toupper(this->Str[i]);
    }
}
void String::ToLowerString(){
    for(int i=this->Len-1;i>=0;i--){
        this->Str[i]=tolower(this->Str[i]);
    }
}
String operator+(String &St1,const String & St2){
    char * TempStr=new char[St1.Len+St2.Len+1];
    char *str1=new char[St1.Len+1];
    strcpy(str1,St1.Str);
    char *str2=new char[St2.Len+1];
    strcpy(str2,St2.Str);
    strcat(str1,str2);
    strcpy(TempStr,str1);
    String resStr(TempStr);
    return resStr;
}