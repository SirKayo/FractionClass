#include<iostream>
using namespace std;
class Fraction{
    private:
        int num, den;
    public:
        Fraction(int n, int d);
        Fraction(int n);
        Fraction();
        Fraction(char *s);
        Fraction(Fraction const &other);
        
        void set(int n, int d){
            num = n;
            den = d;
            normalize();
        }       
        int get_num() const {return num;}
        int get_den() const {return den;}

        Fraction add(const  Fraction &other);
        Fraction mult(const Fraction &other);
        Fraction sub(const  Fraction &other);
        Fraction dev(const  Fraction &other);

        Fraction operator+(const Fraction &other);
        Fraction operator-(const Fraction &other);
        Fraction operator*(const Fraction &other);
        Fraction operator/(const Fraction &other);

        Fraction operator=(const Fraction &other);

        bool operator==(const Fraction &other);
        bool operator>(const Fraction &other);
        bool operator<(const Fraction &other);

        friend ostream &operator<<(ostream &os, Fraction &fr);
        friend istream &operator>>(ostream &is, Fraction &fr);
    private:
        void normalize();
        int gcf(int,int);
        int lcm(int,int);

};

Fraction::Fraction(int n,int d){              //set constructor
    set(n,d);
}
Fraction::Fraction(int n){                    //int constructor
    num = n;
    den = 1;
}
Fraction::Fraction(){                         //default constructor
    num = 0;
    den = 1;
}
Fraction::Fraction(char *s){                  //string constructor
    int n=0;
    int d=0;
    int i;
    for(i=0; s[i]!='/' && s[i]!='\0'; ++i){
        n*=10;
        n+= s[i]-'0';
    }
    if(s[i]=='/'){
        for(i+=1; s[i]!='\0';++i){
            d*=10;
            d+= s[i]-'0';
        }
    }   
    set(n,( d==0 ? 1 : d));
    /*int n = 0;
    int d = 1;
    char *p1 = strtok(s, "/, ");
    char *p2 = strtok(NULL, "/, ");
    if (p1 != NULL)
    n = atoi(p1);
    if (p2 != NULL)Fraction operator+(constFraction &other);
    d = atoi(p2);
    set(n, d);*/
}
Fraction::Fraction(Fraction const &other){    //copy constructor
    num = other.get_num();
    den = other.get_den();
}

void Fraction::normalize(){
    if (den == 0 || num == 0) {
        num = 0;
        den = 1;
    }
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
    int n = gcf(num, den);
    num /= n;
    den /= n;
}
int Fraction::gcf(int a, int b){
    if(b==0)
        return (a>=0 ? a : -a);
    else
        return gcf(b, a%b);
}
int Fraction::lcm(int a, int b){
    int n = gcf(a, b);
    return a / n * b;
}

Fraction Fraction::add(const  Fraction &other){
    int lcd   = lcm(den, other.get_den());
    int quot1 = lcd/den;
    int quot2 = lcd/other.get_den();

    return Fraction( (num * quot1) + (other.get_num() * quot2) , lcd);
}
Fraction Fraction::mult(const  Fraction &other){
    return Fraction(num * other.get_num(), den*other.get_den());
}
Fraction Fraction::sub(const  Fraction &other){
    int lcd   = lcm(den, other.get_den());
    int quot1 = lcd/den;
    int quot2 = lcd/other.get_den();

    return Fraction( (num * quot1) - (other.get_num() * quot2) , lcd);
}
Fraction Fraction::dev(const  Fraction &other){
    return Fraction(num * other.get_den(), den*other.get_num());
}

Fraction Fraction::operator+(const Fraction &other){
    return add(other);
}
Fraction Fraction::operator-(const Fraction &other){
    return sub(other);
}
Fraction Fraction::operator*(const Fraction &other){
    return mult(other);
}
Fraction Fraction::operator/(const Fraction &other){
    return dev(other);
}
Fraction Fraction::operator=(const Fraction &other){
    set(other.get_num(), other.get_den());
    return *this;
}

bool Fraction::operator==(const Fraction &other){
    return (( num==other.get_num() )
            &&
            ( den==other.get_den() ));
}
bool Fraction::operator>(const Fraction &other){
    return (num * other.get_den() > den * other.get_num());
}
bool Fraction::operator<(const Fraction &other){
    return (num * other.get_den() < den * other.get_num());
}
ostream &operator<<(ostream &os, Fraction &fr){
    os << fr.num << "/" << fr.den;
    return os;
}

istream &operator>>(istream &is, Fraction &fr){
    char *str;
    is>>str;
    fr=Fraction(str);
    return is;
}