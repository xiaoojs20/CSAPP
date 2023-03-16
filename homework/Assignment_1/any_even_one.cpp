#include <iostream>
int any_even_one(unsigned x);
int main(){
    std::cout<<any_even_one(0x82);
    std::cout<<any_even_one(0x51);
    return 0;
}

int any_even_one(unsigned x){
    return (x & 0x55555555) != 0;
}