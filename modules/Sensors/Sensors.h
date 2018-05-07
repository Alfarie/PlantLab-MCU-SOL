#include <Task.h>
extern TaskManager taskManager;

class Sensors : public Task
{
  public:
    static Sensors *s_instance;
    Sensors() : Task(MsToTaskTime(500)){};
    static Sensors *instance()
    {
      if (!s_instance)
      s_instance = new Sensors;
      return s_instance;
    }

  private:
    String packet = "";
    virtual bool OnStart()
    {
        return true;
    }
    virtual void OnUpdate(uint32_t delta_time)
    {
      float ecraw = ECSensor::instance()->GetEC();
      float phraw = pHSensor::instance()->GetPH();
      float water = WaterSensor::instance()->GetWater();
      int floating = Floating::instance()->GetFloating();
      packet = "{" + String(ecraw) + "," + String(phraw) + "," + String(water) +  "," + String(floating) +"}";
      Serial.println(packet);
      toHq.println(packet);
    }
};
Sensors *Sensors::s_instance = 0;