#include <Task.h>
#include<SoftwareSerial.h>
TaskManager taskManager;
SoftwareSerial toHq(6,7);

#include "./modules/Sensors/water.h"
#include "./modules/Sensors/ec.h"
#include "./modules/Sensors/ph.h"
#include "./modules/Sensors/Sensors.h"

#include "./modules/debuger.h"
#include "./modules/Helper/Puppet.h"


void setup(){
    toHq.begin(9600);
    Serial.begin(115200);
    Puppet::instance();
    taskManager.StartTask(Sensors::instance());
    taskManager.StartTask(ECSensor::instance());
    taskManager.StartTask(pHSensor::instance());
    taskManager.StartTask(WaterSensor::instance());

    // taskManager.StartTask(Debugger::instance());
}

void loop(){
    taskManager.Loop();
}
