#include <Arduino.h>
// #include <string.h>

#define DATA_LENGTH 20

String info[DATA_LENGTH];

void analysisData (String data) {
    // data.toInt()
    // data.toFloat()
    // String(d, 3) // 保留三位小数

  int index = 0;
  int lastIndex = 0;
  for (int i = 0; i < DATA_LENGTH; i++){
    index = data.indexOf("{|}", index);
    lastIndex = data.indexOf("{|}", index + 1);
    String str = data.substring(index + 3, lastIndex - index - 3);
    info[i] = str.substring(str.indexOf(" ") + 1);
    index = lastIndex + 3;
  }
  
  PC_INFO.cpu_rate = info[2];
  PC_INFO.cpu_hz = String(info[3].toInt() / 1000, 2) + "G";
  PC_INFO.cpu_power = info[4];
  PC_INFO.cpu_temperature = info[5];

  PC_INFO.ram_rate = info[6];
  PC_INFO.ram_used = String(info[7].toFloat() / 1024, 1) + "G/" + String(info[7].toFloat() / 1024, 1) + "G";

  PC_INFO.gpu_rate = info[6];
  PC_INFO.gpu_core_hz = info[6];
  PC_INFO.gpu_ram_hz = info[6];
  PC_INFO.gpu_power = info[6];
  PC_INFO.gpu_temperature = info[6];

  float network_up = info[10].toFloat();
  PC_INFO.network_up = network_up > 100 ? String(network_up / 1024, 3) + "Kb/s" : String(network_up, 2) + "Mb/s"
  float network_down = info[10].toFloat();
  PC_INFO.network_down = network_down > 100 ? String(network_down / 1024, 3) + "Kb/s" : String(network_down, 2) + "Mb/s"


  PC_INFO.ssd_temperature = info[6];
};

struct PC_INFO {
  // cpu
  String cpu_rate;
  String cpu_hz;
  String cpu_power;
  String cpu_temperature;
  
  // ram
  String ram_rate;
  String ram_used;
  String ram_unused;

  // gpu
  String gpu_rate;
  String gpu_core_hz;
  String gpu_ram_hz;
  String gpu_power;
  String gpu_temperature;

  // network
  String network_up;
  String network_down;

  // ssd
  String ssd_temperature;
};
