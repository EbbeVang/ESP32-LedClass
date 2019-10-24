#include <string>
using namespace std;

class LedLight
{
    public:
        int pinNumber;
        LedLight(int pin); 
        void on();
        void off();
    private:
        
};