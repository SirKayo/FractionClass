#include <iostream>
#include <string>


//#include"FractionClass.h"
#include"floatFract.h"
using namespace std;
int main(){
    int a, b;
    char str;
    FloatFraction fract;
    while (true) {
        /*cout << "Enter numerator for the first number: ";
        cin >> a;
        cout << "Enter denominator for the first number: ";
        cin >> b;
        fract1.set(a,b);


        cout << "Enter numerator for the second number: ";
        cin >> a;
        cout << "Enter denominator for the second number: ";    
        cin >> b;
        fract2.set(a,b);

        cout<< "Normalized form for the first number is "  << fract1.get_num() <<'/'<<fract1.get_den()<< endl;
        cout<< "Normalized form for the second number is " << fract2.get_num() <<'/'<<fract2.get_den()<< endl;


        cout<< "Their sum is: "<< fract1.add(fract2).get_num()<<"/"<< fract1.add(fract2).get_den()<<endl;
        cout<< "Their product is: "<< fract1.mult(fract2).get_num()<<"/"<< fract1.mult(fract2).get_den()<<endl;

        cout<< "Their difference is: "<< fract1.sub(fract2).get_num()<<"/"<< fract1.sub(fract2).get_den()<<endl;
        cout<< "Their division product is: "<< fract1.dev(fract2).get_num()<<"/"<< fract1.dev(fract2).get_den()<<endl;
        */
        /*Fraction fract1="1/2";
        Fraction fract2="1/3";
        Fraction fract3=fract1+fract2;
        */
        /*
        cout<<fract1.get_num()<<"/"<<fract1.get_den()
        <<" + "
        //<<"1"
        //<<fract2.get_num()<<"/"<<fract2.get_den()
        <<" = "
        //<<(fract1+fract2).get_num()<<"/"<<(fract1+fract2).get_den()
        //<<(fract1+1).get_num()<<"/"<<(fract1+1).get_den()
        <<fract3
        <<endl;
*/
        //cout<<fract1<<" + "<<fract2<<" = "<<fract3<<endl;

        
        cin>>fract;
        cout<<fract.get_float()<<endl;

        cout << "Do again? (Y or N) ";
        cin >> str;
        if (!(str == 'Y' || str == 'y'))
        break;
    }
return 0;
}