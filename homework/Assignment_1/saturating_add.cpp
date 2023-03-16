#include<iostream>
#include<climits>
int saturating_add(int x, int y);
int main(){
    std::cout<<saturating_add(999,-10000)<<std::endl;
    std::cout<<saturating_add(INT_MAX-200,55)<<std::endl;
    std::cout<<saturating_add(INT_MAX,10000)<<std::endl;
    std::cout<<saturating_add(INT_MIN,10000)<<std::endl;
    std::cout<<saturating_add(INT_MIN,-100)<<std::endl;
    std::cout<<saturating_add(INT_MAX-100,45)<<std::endl;
}

int saturating_add(int x, int y){
    int PosOverflow = (x > 0 && y > 0 && x + y <= 0);
    int NegOverflow =  (x < 0 && y < 0 && x + y > 0);
    int Overflow = PosOverflow | NegOverflow;
    int sum = PosOverflow & INT_MAX |
            NegOverflow & INT_MIN |
            ~Overflow & (x + y);

    return sum;
}
