#include <Task.h>
extern TaskManager taskManager;
class Debugger : public Task
{
  public:
    static Debugger *s_instance;
    Debugger() : Task(MsToTaskTime(1)){
        Serial.begin(115200);
        Serial1.begin(115200);
    };
    static Debugger *instance()
    {
        if (!s_instance)
            s_instance = new Debugger;
        return s_instance;
    }

  private:
    float ec, ph, water;
    String cmdStr;
    String sensorStr = "0.00,0.00,0.0,0,0";
    char res[100];
    int size, cmdNumber, cmdSize;
    virtual bool OnStart()
    {
        return true;
    }
    virtual void OnUpdate(uint32_t delta_time)
    {
        while (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
            Serial.write(Serial1.read());   // read it and send it out Serial (USB)
        }
    }
};
Debugger *Debugger::s_instance = 0;