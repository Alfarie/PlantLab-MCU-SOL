#include <Task.h>
extern TaskManager taskManager;
class Puppet : public Task
{
  public:
    static Puppet *s_instance;
    Puppet() : Task(MsToTaskTime(100)){
      pinMode(8,OUTPUT);
      pinMode(9,OUTPUT);

      digitalWrite(8,HIGH);
      digitalWrite(9,HIGH);

    };
    static Puppet *instance()
    {
      if (!s_instance)
      s_instance = new Puppet;
      return s_instance;
    }

  private:
    virtual bool OnStart()
    {
        return true;
    }
    virtual void OnUpdate(uint32_t delta_time)
    {
    
    }
};
Puppet *Puppet::s_instance = 0;