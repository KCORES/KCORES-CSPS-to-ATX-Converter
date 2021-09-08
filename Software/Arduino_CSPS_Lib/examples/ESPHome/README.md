# ESPHome 集成

在 ESPHome 的 yaml 中增加

```yaml
esphome:
  # 原先内容
  includes:
    - CSPS/main.hpp
    - CSPS/KCORES_CSPS.h
    - CSPS/KCORES_CSPS.cpp
```

创建文件夹 `CSPS` 将 `main.hpp`, `KCORES_CSPS.h` 以及 `KCORES_CSPS.cpp` 丢进去

## 增加传感器

使用自定义传感器获取数据

```yaml
sensor:
  - platform: custom
    lambda: |-
      auto power = new CSPSPower();
      App.register_component(power);
      return {power->fan_speed, power->temp1, power->temp2, power->power_out, power->power_in, power->current_out, power->current_in, power->voltage_out, power->voltage_in};

    sensors:
    - name: "Fan Speed"
      accuracy_decimals: 0
      unit_of_measurement: RPM
    - name: "Temp 1"
      accuracy_decimals: 1
      unit_of_measurement: °C
    - name: "Temp 2"
      accuracy_decimals: 1
      unit_of_measurement: °C
    - name: "Power Out"
      accuracy_decimals: 0
      unit_of_measurement: W
    - name: "Power In"
      accuracy_decimals: 0
      unit_of_measurement: W
    - name: "Current Out"
      accuracy_decimals: 1
      unit_of_measurement: A
    - name: "Current In"
      accuracy_decimals: 1
      unit_of_measurement: A
    - name: "Voltage Out"
      accuracy_decimals: 1
      unit_of_measurement: V
    - name: "Voltage In"
      accuracy_decimals: 1
      unit_of_measurement: V
```
