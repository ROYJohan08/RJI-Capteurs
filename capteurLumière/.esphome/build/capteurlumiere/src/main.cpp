// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
wifi::WiFiComponent *wifi_wificomponent;
mdns::MDNSComponent *mdns_mdnscomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
using namespace sensor;
StartupTrigger *startuptrigger;
Automation<> *automation;
DelayAction<> *delayaction;
using namespace i2c;
i2c::ArduinoI2CBus *i2c_arduinoi2cbus;
preferences::IntervalSyncer *preferences_intervalsyncer;
deep_sleep::DeepSleepComponent *deep_sleep_1;
bh1750::BH1750Sensor *bh1750_bh1750sensor;
adc::ADCSensor *adc_adcsensor;
sensor::MultiplyFilter *sensor_multiplyfilter;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin;
deep_sleep::EnterDeepSleepAction<> *deep_sleep_enterdeepsleepaction;
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_MODE[16] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_LEVEL[16] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esp8266:
  //   board: nodemcuv2
  //   framework:
  //     version: 3.0.2
  //     source: ~3.30002.0
  //     platform_version: platformio/espressif8266@3.2.0
  //   restore_from_flash: false
  //   early_pin_init: true
  //   board_flash_mode: dout
  esphome::esp8266::setup_preferences();
  // esphome:
  //   name: capteurlumiere
  //   on_boot:
  //   - priority: -10.0
  //     then:
  //     - delay: 30s
  //       type_id: delayaction
  //     - deep_sleep.enter:
  //         id: deep_sleep_1
  //       type_id: deep_sleep_enterdeepsleepaction
  //     automation_id: automation
  //     trigger_id: startuptrigger
  //   build_path: build/capteurlumiere
  //   friendly_name: ''
  //   area: ''
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  //   min_version: 2024.2.2
  App.pre_setup("capteurlumiere", "", "", "", __DATE__ ", " __TIME__, false);
  // wifi:
  //   networks:
  //   - ssid: !secret 'wifi_exterieur'
  //     password: !secret 'low_password'
  //     id: wifi_wifiap
  //     priority: 0.0
  //   manual_ip:
  //     static_ip: 192.168.1.84
  //     gateway: 192.168.1.1
  //     subnet: 255.255.255.0
  //     dns1: 0.0.0.0
  //     dns2: 0.0.0.0
  //   fast_connect: true
  //   ap:
  //     ssid: Alarme Fallback Hotspot
  //     password: !secret 'low_password'
  //     id: wifi_wifiap_2
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   output_power: 20.0
  //   passive_scan: false
  //   enable_on_boot: true
  //   use_address: 192.168.1.84
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("192.168.1.84");
  {
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("ROY_WIFI_EXTERIEUR");
  wifi_wifiap.set_password("0100101001");
  wifi_wifiap.set_manual_ip(wifi::ManualIP{
      .static_ip = network::IPAddress(192, 168, 1, 84),
      .gateway = network::IPAddress(192, 168, 1, 1),
      .subnet = network::IPAddress(255, 255, 255, 0),
      .dns1 = network::IPAddress(0, 0, 0, 0),
      .dns2 = network::IPAddress(0, 0, 0, 0),
  });
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  }
  {
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("Alarme Fallback Hotspot");
  wifi_wifiap_2.set_password("0100101001");
  wifi_wificomponent->set_ap(wifi_wifiap_2);
  }
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(true);
  wifi_wificomponent->set_passive_scan(false);
  wifi_wificomponent->set_output_power(20.0f);
  wifi_wificomponent->set_enable_on_boot(true);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  //   services: []
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // ota:
  //   password: !secret 'high_password'
  //   id: ota_otacomponent
  //   safe_mode: true
  //   version: 2
  //   port: 8266
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("Leostingher*1");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   password: !secret 'high_password'
  //   id: api_apiserver
  //   port: 6053
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("Leostingher*1");
  api_apiserver->set_reboot_timeout(900000);
  // sensor:
  startuptrigger = new StartupTrigger(-10.0f);
  startuptrigger->set_component_source("esphome.coroutine");
  App.register_component(startuptrigger);
  automation = new Automation<>(startuptrigger);
  delayaction = new DelayAction<>();
  delayaction->set_component_source("esphome.coroutine");
  App.register_component(delayaction);
  delayaction->set_delay(30000);
  // i2c:
  //   sda: 5
  //   scl: 4
  //   scan: true
  //   id: i2c_arduinoi2cbus
  //   frequency: 50000.0
  i2c_arduinoi2cbus = new i2c::ArduinoI2CBus();
  i2c_arduinoi2cbus->set_component_source("i2c");
  App.register_component(i2c_arduinoi2cbus);
  i2c_arduinoi2cbus->set_sda_pin(5);
  i2c_arduinoi2cbus->set_scl_pin(4);
  i2c_arduinoi2cbus->set_frequency(50000);
  i2c_arduinoi2cbus->set_scan(true);
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // deep_sleep:
  //   id: deep_sleep_1
  //   sleep_duration: 60s
  deep_sleep_1 = new deep_sleep::DeepSleepComponent();
  deep_sleep_1->set_component_source("deep_sleep");
  App.register_component(deep_sleep_1);
  deep_sleep_1->set_sleep_duration(60000);
  // sensor.bh1750:
  //   platform: bh1750
  //   name: light
  //   address: 0x23
  //   update_interval: 1s
  //   unit_of_measurement: lx
  //   disabled_by_default: false
  //   force_update: false
  //   id: bh1750_bh1750sensor
  //   accuracy_decimals: 1
  //   device_class: illuminance
  //   state_class: measurement
  //   i2c_id: i2c_arduinoi2cbus
  bh1750_bh1750sensor = new bh1750::BH1750Sensor();
  App.register_sensor(bh1750_bh1750sensor);
  bh1750_bh1750sensor->set_name("light");
  bh1750_bh1750sensor->set_object_id("light");
  bh1750_bh1750sensor->set_disabled_by_default(false);
  bh1750_bh1750sensor->set_device_class("illuminance");
  bh1750_bh1750sensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  bh1750_bh1750sensor->set_unit_of_measurement("lx");
  bh1750_bh1750sensor->set_accuracy_decimals(1);
  bh1750_bh1750sensor->set_force_update(false);
  bh1750_bh1750sensor->set_update_interval(1000);
  bh1750_bh1750sensor->set_component_source("bh1750.sensor");
  App.register_component(bh1750_bh1750sensor);
  bh1750_bh1750sensor->set_i2c_bus(i2c_arduinoi2cbus);
  bh1750_bh1750sensor->set_i2c_address(0x23);
  // sensor.adc:
  //   platform: adc
  //   pin:
  //     number: 17
  //     mode:
  //       analog: true
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esphome_esp8266_esp8266gpiopin
  //     inverted: false
  //   name: battery
  //   update_interval: 1s
  //   unit_of_measurement: V
  //   filters:
  //   - multiply: 10.2
  //     type_id: sensor_multiplyfilter
  //   icon: mdi:battery
  //   disabled_by_default: false
  //   force_update: false
  //   id: adc_adcsensor
  //   accuracy_decimals: 2
  //   device_class: voltage
  //   state_class: measurement
  //   raw: false
  adc_adcsensor = new adc::ADCSensor();
  adc_adcsensor->set_update_interval(1000);
  adc_adcsensor->set_component_source("adc.sensor");
  App.register_component(adc_adcsensor);
  App.register_sensor(adc_adcsensor);
  adc_adcsensor->set_name("battery");
  adc_adcsensor->set_object_id("battery");
  adc_adcsensor->set_disabled_by_default(false);
  adc_adcsensor->set_icon("mdi:battery");
  adc_adcsensor->set_device_class("voltage");
  adc_adcsensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  adc_adcsensor->set_unit_of_measurement("V");
  adc_adcsensor->set_accuracy_decimals(2);
  adc_adcsensor->set_force_update(false);
  sensor_multiplyfilter = new sensor::MultiplyFilter(10.2f);
  adc_adcsensor->set_filters({sensor_multiplyfilter});
  esphome_esp8266_esp8266gpiopin = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin->set_pin(17);
  esphome_esp8266_esp8266gpiopin->set_inverted(false);
  esphome_esp8266_esp8266gpiopin->set_flags(gpio::Flags::FLAG_INPUT);
  adc_adcsensor->set_pin(esphome_esp8266_esp8266gpiopin);
  adc_adcsensor->set_output_raw(false);
  // socket:
  //   implementation: lwip_tcp
  // network:
  //   enable_ipv6: false
  deep_sleep_enterdeepsleepaction = new deep_sleep::EnterDeepSleepAction<>(deep_sleep_1);
  automation->add_actions({delayaction, deep_sleep_enterdeepsleepaction});
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
