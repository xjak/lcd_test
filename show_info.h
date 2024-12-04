struct PC_INFO
{
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
