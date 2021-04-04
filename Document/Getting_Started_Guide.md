# 准备

1. 下载 [Releases](https://github.com/KCORES/KCORES-CSPS-to-ATX-Converter/releases) 中最新发布版的 Gerber 文件包与 BOM 表格.  
    - Gerber 文件: 用于发送给 PCB 工厂生产 PCB
    - BOM 表格: 购买元器件

## BOM 说明

1. 钽电容选配, 不焊接钽电容不影响转接板性能
2. 5566 连接器 (ATX 插座) 分实心针与空心针两种，互不兼容, 本项目全部使用实心针
3. Mini560 模块上没有电压标注, 保留包装，切勿弄混
4. 支持两种 CSPS 连接器
    - FCI 10053363-200LF: 进口连接器, 价格较贵, 允许通过较大电流, 插拔手感较好
    - WingTAT S-64M-2.54-5: 廉价连接器, 仅建议搭配 460W 与 750W 电源时使用
5. U4 监控芯片有多种替换件, 建议选择 TPS3510P

## 安全注意

- 不要随意拆开 CSPS 外壳, 即使断电后 PFC 电容内可能仍有高压
- 禁止带电插拔 CSPS 与转接板, 必须先断开市电, 待 CSPS 风扇停转后再插拔转接板

# 焊接

## 焊接一

![](\Image\Getting_Started_Guide\Solid1.png)

- CSPS 连接器
- 所有降压模块
- R1 识别电阻

完成焊接后, 插入电源并通电, 短接橙色线画出的 GND 与 ~ON 引脚开机, CSPS 尾部电源指示灯变绿, 使用万用表测量各输出口电压是否正常

- 若无 12V 输出, 请检查主输出是否短路, R1 识别电阻是否焊接错误
- 若无 5V/3.3V 输出, 请检查对应的 DCDC 模块

## 焊接二

![](\Image\Getting_Started_Guide\Solid2.png)

- ATX 控制电路
- 测试 ATX 控制 IC
- 焊接 ATX 控制 IC

⚠注意: ATX 控制 IC 极易受静电损坏, 插上检测工作正常再焊接, 或直接焊接 DIP-8 插座以便更换 IC

完成后, 短接红圈处 ATX 开机引脚, 电源应启动且各路输出电压正常

## 焊接三

完成其它接口焊接, 注意封装方向,

# Enjoy Yourself