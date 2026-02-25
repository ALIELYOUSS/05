#include "stdexcept"
#include <iostream>

class obj{
    private:
        int val ;
    public :
        obj(int i) : val(i){}
        int check(){
            if (val > 10)
                throw new std::range_error("error");
            return 0;
        }
};

int main(){
    obj g(11);
    try
    {
        g.check();
        
    }
    catch(std::range_error * e)
    {
        std::cout<<e->what() << "\n";
    }
    
}