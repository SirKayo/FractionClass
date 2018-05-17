#include"FractionClass.h"

class FloatFraction : public Fraction{
    public:
        double get_float();
};
double FloatFraction::get_float(){
    return (double)this->get_num()/this->get_den();
}