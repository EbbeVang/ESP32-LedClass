#include <string>
using namespace std;

class LedLight
{
    public:
        LedLight(int pin, int channel); 
        void on();
        void off();
        void setPulse(bool state);
        void loop();
        void setPulseDelay();
    private:
};