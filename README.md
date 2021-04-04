# KCORES-CSPS-to-ATX-Converter

![KCORES CSPS to ATX Converter](Document\Image\Cover\Cover1.png)

- 项目视频: [1元10瓦 垃圾佬的超级ATX电源-Bilibili](https://www.bilibili.com/video/BV12A411N7AG/)
- KCORES 交流群: [826702309](https://jq.qq.com/?_wv=1027&k=jcr07ZYG)
- KCORES 官方网站: [KCORES.com](https://kcores.com/)
- 从零开始制作: [入门指南](Document\Getting_Started_Guide.md)

# Specification

| 12V   | 5V    | 3.3V  | 5VSB  |
|-------|-------|-------|-------|
|取决于CSPS| 5A | 5A    | 5A    |
|       | 25W   | 16.5W | 25W   |

⚠: 5V 与 3.3V 不建议长期超过 4A 使用

## 模组接口
- 1x 24Pin 主板接口 (巨龙线序)
- 1x 4Pin IDE/SATA 硬盘接口 (联想线序)
- 5x 8Pin CPU/GPU 接口 (巨龙线序)
- 1x I2C PMBUS 控制接口

# Document

## Distinguish CSPS

KCORES CSPS to ATX Converter 可以用于引脚特征如下图所示的电源

![辨别 CSPS 电源](Document\Image\Cover\Distinguish_CSPS.jpg)

目前已知 Hewlett Packard Enterprise 与 Huawei 大量生产过 CSPS.  
不同厂家生产的 CSPS 可能外形略有不同, 但金手指必须与图示一致才可使用.  

## Getting Started Guide

- [入门指南](Document\Getting_Started_Guide.md)

# LICENSE

![KCORES 许可证](https://github.com/KCORES/kcores-license/raw/main/bandge/kcores-open-source-license-bandge.png)

# Contributor

- [@AlphaArea](https://github.com/alphaarea)
- @Ubiq
- [@karminski-牙医](https://github.com/karminski)
- [@MistyMoonR](https://github.com/MistyMoonR)
