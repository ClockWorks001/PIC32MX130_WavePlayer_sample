EESchema Schematic File Version 2
LIBS:PIC32MX130_Sample20161223
LIBS:mylib20161223
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:analog_devices
LIBS:regul
LIBS:adc-dac
LIBS:microcontrollers
LIBS:microchip
LIBS:contrib
LIBS:microchip_pic32mcu
LIBS:microchip_dspic33dsc
LIBS:microchip_pic16mcu
LIBS:audio
LIBS:linear
LIBS:PIC32MX130_Sample20161223-cache
EELAYER 25 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Crystal Y?
U 1 1 585DA038
P 6350 4700
F 0 "Y?" H 6350 4850 50  0000 C CNN
F 1 "32.768Khz" V 6150 4700 50  0000 C CNN
F 2 "" H 6350 4700 50  0000 C CNN
F 3 "" H 6350 4700 50  0000 C CNN
	1    6350 4700
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 585DA0A3
P 5900 4550
F 0 "C?" H 5900 4650 40  0000 L CNN
F 1 "33pF" H 5906 4465 40  0000 L CNN
F 2 "" H 5938 4400 30  0000 C CNN
F 3 "" H 5900 4550 60  0000 C CNN
	1    5900 4550
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 585DA0FE
P 5900 4850
F 0 "C?" H 5900 4950 40  0000 L CNN
F 1 "33pF" H 5906 4765 40  0000 L CNN
F 2 "" H 5938 4700 30  0000 C CNN
F 3 "" H 5900 4850 60  0000 C CNN
	1    5900 4850
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 585DA131
P 5950 2800
F 0 "R?" V 6030 2800 40  0000 C CNN
F 1 "10K" V 5957 2801 40  0000 C CNN
F 2 "" V 5880 2800 30  0000 C CNN
F 3 "" H 5950 2800 30  0000 C CNN
	1    5950 2800
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 585DA345
P 10250 4800
F 0 "C?" H 10250 4900 40  0000 L CNN
F 1 "10uF" H 10256 4715 40  0000 L CNN
F 2 "" H 10288 4650 30  0000 C CNN
F 3 "" H 10250 4800 60  0000 C CNN
	1    10250 4800
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 585DA829
P 10250 3200
F 0 "C?" H 10250 3300 40  0000 L CNN
F 1 "0.1uF" H 10256 3115 40  0000 L CNN
F 2 "" H 10288 3050 30  0000 C CNN
F 3 "" H 10250 3200 60  0000 C CNN
	1    10250 3200
	1    0    0    -1  
$EndComp
$Comp
L PIC32MX130F064B U?
U 1 1 585DAB37
P 8350 4350
F 0 "U?" H 8350 5800 60  0000 C CNN
F 1 "PIC32MX130F064B" H 8300 5650 60  0000 C CNN
F 2 "" H 8350 4750 60  0000 C CNN
F 3 "" H 8350 4750 60  0000 C CNN
	1    8350 4350
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 585DB004
P 6350 5300
F 0 "C?" H 6350 5400 40  0000 L CNN
F 1 "0.1uF" H 6356 5215 40  0000 L CNN
F 2 "" H 6388 5150 30  0000 C CNN
F 3 "" H 6350 5300 60  0000 C CNN
	1    6350 5300
	-1   0    0    1   
$EndComp
$Comp
L CN-ICSP CN?
U 1 1 585DB113
P 5300 2800
F 0 "CN?" H 5150 3250 60  0000 C CNN
F 1 "CN-ICSP" H 5150 2200 60  0000 C CNN
F 2 "" H 5300 2650 60  0000 C CNN
F 3 "" H 5300 2650 60  0000 C CNN
	1    5300 2800
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 585DB21D
P 5950 2400
F 0 "#PWR?" H 5950 2360 30  0001 C CNN
F 1 "+3.3V" H 5950 2510 30  0000 C CNN
F 2 "" H 5950 2400 60  0000 C CNN
F 3 "" H 5950 2400 60  0000 C CNN
	1    5950 2400
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 585DB399
P 6350 5150
F 0 "#PWR?" H 6350 5110 30  0001 C CNN
F 1 "+3.3V" H 6350 5260 30  0000 C CNN
F 2 "" H 6350 5150 60  0000 C CNN
F 3 "" H 6350 5150 60  0000 C CNN
	1    6350 5150
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 585DB4C4
P 10250 3000
F 0 "#PWR?" H 10250 2960 30  0001 C CNN
F 1 "+3.3V" H 10250 3110 30  0000 C CNN
F 2 "" H 10250 3000 60  0000 C CNN
F 3 "" H 10250 3000 60  0000 C CNN
	1    10250 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 585DB8DA
P 5750 5150
F 0 "#PWR?" H 5750 5150 30  0001 C CNN
F 1 "GND" H 5750 5080 30  0001 C CNN
F 2 "" H 5750 5150 60  0000 C CNN
F 3 "" H 5750 5150 60  0000 C CNN
	1    5750 5150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 585DBAA7
P 5300 3100
F 0 "#PWR?" H 5300 3100 30  0001 C CNN
F 1 "GND" H 5300 3030 30  0001 C CNN
F 2 "" H 5300 3100 60  0000 C CNN
F 3 "" H 5300 3100 60  0000 C CNN
	1    5300 3100
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 585DBACD
P 5450 3050
F 0 "#PWR?" H 5450 3010 30  0001 C CNN
F 1 "+3.3V" H 5450 3160 30  0000 C CNN
F 2 "" H 5450 3050 60  0000 C CNN
F 3 "" H 5450 3050 60  0000 C CNN
	1    5450 3050
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 585DBD91
P 10250 5000
F 0 "#PWR?" H 10250 5000 30  0001 C CNN
F 1 "GND" H 10250 4930 30  0001 C CNN
F 2 "" H 10250 5000 60  0000 C CNN
F 3 "" H 10250 5000 60  0000 C CNN
	1    10250 5000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 585DBEBD
P 10250 3400
F 0 "#PWR?" H 10250 3400 30  0001 C CNN
F 1 "GND" H 10250 3330 30  0001 C CNN
F 2 "" H 10250 3400 60  0000 C CNN
F 3 "" H 10250 3400 60  0000 C CNN
	1    10250 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 585DC148
P 6450 4000
F 0 "#PWR?" H 6450 4000 30  0001 C CNN
F 1 "GND" H 6450 3930 30  0001 C CNN
F 2 "" H 6450 4000 60  0000 C CNN
F 3 "" H 6450 4000 60  0000 C CNN
	1    6450 4000
	1    0    0    -1  
$EndComp
$Comp
L LED D?
U 1 1 585E3D37
P 10250 6300
F 0 "D?" H 10250 6400 50  0000 C CNN
F 1 "LED" H 10250 6200 50  0000 C CNN
F 2 "" H 10250 6300 60  0000 C CNN
F 3 "" H 10250 6300 60  0000 C CNN
	1    10250 6300
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 585E3D94
P 10250 6550
F 0 "#PWR?" H 10250 6550 30  0001 C CNN
F 1 "GND" H 10250 6480 30  0001 C CNN
F 2 "" H 10250 6550 60  0000 C CNN
F 3 "" H 10250 6550 60  0000 C CNN
	1    10250 6550
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 585E40AD
P 10250 5800
F 0 "R?" V 10330 5800 40  0000 C CNN
F 1 "220" V 10257 5801 40  0000 C CNN
F 2 "" V 10180 5800 30  0000 C CNN
F 3 "" H 10250 5800 30  0000 C CNN
	1    10250 5800
	-1   0    0    1   
$EndComp
$Comp
L AE-MICRO-SD-DIP SDC?
U 1 1 586C8DF7
P 13250 4150
F 0 "SDC?" H 13250 4950 60  0000 C CNN
F 1 "AE-MICRO-SD-DIP" H 13250 4750 60  0000 C CNN
F 2 "" H 13250 4150 60  0000 C CNN
F 3 "" H 13250 4150 60  0000 C CNN
	1    13250 4150
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 586CAF84
P 14150 4100
F 0 "C?" H 14150 4200 40  0000 L CNN
F 1 "0.1uF" H 14156 4015 40  0000 L CNN
F 2 "" H 14188 3950 30  0000 C CNN
F 3 "" H 14150 4100 60  0000 C CNN
	1    14150 4100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 586CB02F
P 14150 4350
F 0 "#PWR?" H 14150 4350 30  0001 C CNN
F 1 "GND" H 14150 4280 30  0001 C CNN
F 2 "" H 14150 4350 60  0000 C CNN
F 3 "" H 14150 4350 60  0000 C CNN
	1    14150 4350
	1    0    0    -1  
$EndComp
$Comp
L CN-UART-601 CN?
U 1 1 586CCC7B
P 13050 5250
F 0 "CN?" H 13050 5750 60  0000 C CNN
F 1 "CN-UART-601" H 13050 4850 60  0000 C CNN
F 2 "" H 12750 5100 60  0000 C CNN
F 3 "" H 12750 5100 60  0000 C CNN
	1    13050 5250
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 586CCCE4
P 14150 5100
F 0 "C?" H 14150 5200 40  0000 L CNN
F 1 "0.1uF" H 14156 5015 40  0000 L CNN
F 2 "" H 14188 4950 30  0000 C CNN
F 3 "" H 14150 5100 60  0000 C CNN
	1    14150 5100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 586CCD41
P 14150 5350
F 0 "#PWR?" H 14150 5350 30  0001 C CNN
F 1 "GND" H 14150 5280 30  0001 C CNN
F 2 "" H 14150 5350 60  0000 C CNN
F 3 "" H 14150 5350 60  0000 C CNN
	1    14150 5350
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 586CCD79
P 14150 4850
F 0 "#PWR?" H 14150 4810 30  0001 C CNN
F 1 "+3.3V" H 14150 4960 30  0000 C CNN
F 2 "" H 14150 4850 60  0000 C CNN
F 3 "" H 14150 4850 60  0000 C CNN
	1    14150 4850
	1    0    0    -1  
$EndComp
$Comp
L NJM2863F U?
U 1 1 586D00C9
P 3300 8100
F 0 "U?" H 3300 8550 60  0000 C CNN
F 1 "NJM2863F" H 3300 8200 60  0000 C CNN
F 2 "" H 3300 8100 60  0000 C CNN
F 3 "" H 3300 8100 60  0000 C CNN
	1    3300 8100
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 586D044E
P 2500 8050
F 0 "R?" V 2580 8050 40  0000 C CNN
F 1 "220" V 2507 8051 40  0000 C CNN
F 2 "" V 2430 8050 30  0000 C CNN
F 3 "" H 2500 8050 30  0000 C CNN
	1    2500 8050
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 586D052B
P 2200 7950
F 0 "C?" H 2200 8050 40  0000 L CNN
F 1 "0.1uF" H 2206 7865 40  0000 L CNN
F 2 "" H 2238 7800 30  0000 C CNN
F 3 "" H 2200 7950 60  0000 C CNN
	1    2200 7950
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 586D064B
P 4100 8450
F 0 "C?" H 4100 8550 40  0000 L CNN
F 1 "0.1uF" H 4106 8365 40  0000 L CNN
F 2 "" H 4138 8300 30  0000 C CNN
F 3 "" H 4100 8450 60  0000 C CNN
	1    4100 8450
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 586D087C
P 4300 7950
F 0 "C?" H 4300 8050 40  0000 L CNN
F 1 "1uF" H 4306 7865 40  0000 L CNN
F 2 "" H 4338 7800 30  0000 C CNN
F 3 "" H 4300 7950 60  0000 C CNN
	1    4300 7950
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 586D08F6
P 3300 8800
F 0 "#PWR?" H 3300 8800 30  0001 C CNN
F 1 "GND" H 3300 8730 30  0001 C CNN
F 2 "" H 3300 8800 60  0000 C CNN
F 3 "" H 3300 8800 60  0000 C CNN
	1    3300 8800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 586D093D
P 4100 8800
F 0 "#PWR?" H 4100 8800 30  0001 C CNN
F 1 "GND" H 4100 8730 30  0001 C CNN
F 2 "" H 4100 8800 60  0000 C CNN
F 3 "" H 4100 8800 60  0000 C CNN
	1    4100 8800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 586D0984
P 4300 8800
F 0 "#PWR?" H 4300 8800 30  0001 C CNN
F 1 "GND" H 4300 8730 30  0001 C CNN
F 2 "" H 4300 8800 60  0000 C CNN
F 3 "" H 4300 8800 60  0000 C CNN
	1    4300 8800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 586D09CB
P 2200 8800
F 0 "#PWR?" H 2200 8800 30  0001 C CNN
F 1 "GND" H 2200 8730 30  0001 C CNN
F 2 "" H 2200 8800 60  0000 C CNN
F 3 "" H 2200 8800 60  0000 C CNN
	1    2200 8800
	1    0    0    -1  
$EndComp
$Comp
L CN-POWER CN?
U 1 1 586D1C1F
P 1300 7800
F 0 "CN?" H 1150 7950 60  0000 C CNN
F 1 "CN-POWER" H 1150 7500 60  0000 C CNN
F 2 "" H 1300 7800 60  0000 C CNN
F 3 "" H 1300 7800 60  0000 C CNN
	1    1300 7800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 586D1D7D
P 1500 8100
F 0 "#PWR?" H 1500 8100 30  0001 C CNN
F 1 "GND" H 1500 8030 30  0001 C CNN
F 2 "" H 1500 8100 60  0000 C CNN
F 3 "" H 1500 8100 60  0000 C CNN
	1    1500 8100
	1    0    0    -1  
$EndComp
$Comp
L NJM2863F U?
U 1 1 586D24AD
P 3300 9700
F 0 "U?" H 3300 10150 60  0000 C CNN
F 1 "NJM2863F" H 3300 9800 60  0000 C CNN
F 2 "" H 3300 9700 60  0000 C CNN
F 3 "" H 3300 9700 60  0000 C CNN
	1    3300 9700
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 586D24B3
P 2500 9650
F 0 "R?" V 2580 9650 40  0000 C CNN
F 1 "220" V 2507 9651 40  0000 C CNN
F 2 "" V 2430 9650 30  0000 C CNN
F 3 "" H 2500 9650 30  0000 C CNN
	1    2500 9650
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 586D24B9
P 2200 9550
F 0 "C?" H 2200 9650 40  0000 L CNN
F 1 "0.1uF" H 2206 9465 40  0000 L CNN
F 2 "" H 2238 9400 30  0000 C CNN
F 3 "" H 2200 9550 60  0000 C CNN
	1    2200 9550
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 586D24BF
P 4100 10050
F 0 "C?" H 4100 10150 40  0000 L CNN
F 1 "0.1uF" H 4106 9965 40  0000 L CNN
F 2 "" H 4138 9900 30  0000 C CNN
F 3 "" H 4100 10050 60  0000 C CNN
	1    4100 10050
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 586D24C5
P 4300 9550
F 0 "C?" H 4300 9650 40  0000 L CNN
F 1 "1uF" H 4306 9465 40  0000 L CNN
F 2 "" H 4338 9400 30  0000 C CNN
F 3 "" H 4300 9550 60  0000 C CNN
	1    4300 9550
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 586D24CB
P 3300 10400
F 0 "#PWR?" H 3300 10400 30  0001 C CNN
F 1 "GND" H 3300 10330 30  0001 C CNN
F 2 "" H 3300 10400 60  0000 C CNN
F 3 "" H 3300 10400 60  0000 C CNN
	1    3300 10400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 586D24D1
P 4100 10400
F 0 "#PWR?" H 4100 10400 30  0001 C CNN
F 1 "GND" H 4100 10330 30  0001 C CNN
F 2 "" H 4100 10400 60  0000 C CNN
F 3 "" H 4100 10400 60  0000 C CNN
	1    4100 10400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 586D24D7
P 4300 10400
F 0 "#PWR?" H 4300 10400 30  0001 C CNN
F 1 "GND" H 4300 10330 30  0001 C CNN
F 2 "" H 4300 10400 60  0000 C CNN
F 3 "" H 4300 10400 60  0000 C CNN
	1    4300 10400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 586D24DD
P 2200 10400
F 0 "#PWR?" H 2200 10400 30  0001 C CNN
F 1 "GND" H 2200 10330 30  0001 C CNN
F 2 "" H 2200 10400 60  0000 C CNN
F 3 "" H 2200 10400 60  0000 C CNN
	1    2200 10400
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 586D24E3
P 4300 9300
F 0 "#PWR?" H 4300 9260 30  0001 C CNN
F 1 "+3.3V" H 4300 9410 30  0000 C CNN
F 2 "" H 4300 9300 60  0000 C CNN
F 3 "" H 4300 9300 60  0000 C CNN
	1    4300 9300
	1    0    0    -1  
$EndComp
$Comp
L +3.3V_No2 #SD_PWR?
U 1 1 586D4E50
P 14150 3850
F 0 "#SD_PWR?" H 14150 3810 30  0001 C CNN
F 1 "+3.3V_No2" H 14150 3960 30  0000 C CNN
F 2 "" H 14150 3850 60  0000 C CNN
F 3 "" H 14150 3850 60  0000 C CNN
	1    14150 3850
	1    0    0    -1  
$EndComp
$Comp
L +3.3V_No2 #SD_PWR?
U 1 1 586D68E9
P 4300 7700
F 0 "#SD_PWR?" H 4300 7660 30  0001 C CNN
F 1 "+3.3V_No2" H 4300 7810 30  0000 C CNN
F 2 "" H 4300 7700 60  0000 C CNN
F 3 "" H 4300 7700 60  0000 C CNN
	1    4300 7700
	1    0    0    -1  
$EndComp
Text Notes 3550 7650 0    60   ~ 0
for SD card
$Comp
L LM358N U?
U 1 1 589C6FA1
P 11100 7700
F 0 "U?" H 11050 7900 50  0000 L CNN
F 1 "LM358N" H 11050 7450 50  0000 L CNN
F 2 "" H 11100 7700 50  0000 C CNN
F 3 "" H 11100 7700 50  0000 C CNN
	1    11100 7700
	1    0    0    -1  
$EndComp
$Comp
L LM358N U?
U 2 1 589C701E
P 10000 9200
F 0 "U?" H 9950 9400 50  0000 L CNN
F 1 "LM358N" H 9950 8950 50  0000 L CNN
F 2 "" H 10000 9200 50  0000 C CNN
F 3 "" H 10000 9200 50  0000 C CNN
	2    10000 9200
	1    0    0    -1  
$EndComp
$Comp
L C 100pF
U 1 1 589C779D
P 9450 7700
F 0 "100pF" H 9450 7800 40  0000 L CNN
F 1 "C" H 9456 7615 40  0000 L CNN
F 2 "" H 9488 7550 30  0000 C CNN
F 3 "" H 9450 7700 60  0000 C CNN
	1    9450 7700
	1    0    0    -1  
$EndComp
$Comp
L R 100K
U 1 1 589CAF80
P 10300 7850
F 0 "100K" V 10380 7850 40  0000 C CNN
F 1 "R" V 10307 7851 40  0000 C CNN
F 2 "" V 10230 7850 30  0000 C CNN
F 3 "" H 10300 7850 30  0000 C CNN
	1    10300 7850
	0    1    1    0   
$EndComp
$Comp
L C 100pF
U 1 1 589CB648
P 10650 8000
F 0 "100pF" H 10650 8100 40  0000 L CNN
F 1 "C" H 10656 7915 40  0000 L CNN
F 2 "" H 10688 7850 30  0000 C CNN
F 3 "" H 10650 8000 60  0000 C CNN
	1    10650 8000
	1    0    0    -1  
$EndComp
$Comp
L C 100pF
U 1 1 589CB765
P 9750 7700
F 0 "100pF" H 9750 7800 40  0000 L CNN
F 1 "C" H 9756 7615 40  0000 L CNN
F 2 "" H 9788 7550 30  0000 C CNN
F 3 "" H 9750 7700 60  0000 C CNN
	1    9750 7700
	1    0    0    -1  
$EndComp
$Comp
L R 100K
U 1 1 589CB811
P 8300 7850
F 0 "100K" V 8380 7850 40  0000 C CNN
F 1 "R" V 8307 7851 40  0000 C CNN
F 2 "" V 8230 7850 30  0000 C CNN
F 3 "" H 8300 7850 30  0000 C CNN
	1    8300 7850
	0    1    1    0   
$EndComp
$Comp
L C 100pF
U 1 1 589CB817
P 8650 8000
F 0 "100pF" H 8650 8100 40  0000 L CNN
F 1 "C" H 8656 7915 40  0000 L CNN
F 2 "" H 8688 7850 30  0000 C CNN
F 3 "" H 8650 8000 60  0000 C CNN
	1    8650 8000
	1    0    0    -1  
$EndComp
$Comp
L R 100K
U 1 1 589CB8B6
P 9100 7850
F 0 "100K" V 9180 7850 40  0000 C CNN
F 1 "R" V 9107 7851 40  0000 C CNN
F 2 "" V 9030 7850 30  0000 C CNN
F 3 "" H 9100 7850 30  0000 C CNN
	1    9100 7850
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 589CC15C
P 10650 8300
F 0 "#PWR?" H 10650 8300 30  0001 C CNN
F 1 "GND" H 10650 8230 30  0001 C CNN
F 2 "" H 10650 8300 60  0000 C CNN
F 3 "" H 10650 8300 60  0000 C CNN
	1    10650 8300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589CC1B6
P 8650 8300
F 0 "#PWR?" H 8650 8300 30  0001 C CNN
F 1 "GND" H 8650 8230 30  0001 C CNN
F 2 "" H 8650 8300 60  0000 C CNN
F 3 "" H 8650 8300 60  0000 C CNN
	1    8650 8300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589CC210
P 11950 8300
F 0 "#PWR?" H 11950 8300 30  0001 C CNN
F 1 "GND" H 11950 8230 30  0001 C CNN
F 2 "" H 11950 8300 60  0000 C CNN
F 3 "" H 11950 8300 60  0000 C CNN
	1    11950 8300
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 589CFB19
P 10650 9200
F 0 "C?" H 10650 9300 40  0000 L CNN
F 1 "0.1uF" H 10656 9115 40  0000 L CNN
F 2 "" H 10688 9050 30  0000 C CNN
F 3 "" H 10650 9200 60  0000 C CNN
	1    10650 9200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589CFB25
P 10650 9650
F 0 "#PWR?" H 10650 9650 30  0001 C CNN
F 1 "GND" H 10650 9580 30  0001 C CNN
F 2 "" H 10650 9650 60  0000 C CNN
F 3 "" H 10650 9650 60  0000 C CNN
	1    10650 9650
	1    0    0    -1  
$EndComp
$Comp
L SPEAKER SP?
U 1 1 589D1EA3
P 14500 7850
F 0 "SP?" H 14400 8100 70  0000 C CNN
F 1 "SPEAKER" H 14400 7600 70  0000 C CNN
F 2 "" H 14500 7850 60  0000 C CNN
F 3 "" H 14500 7850 60  0000 C CNN
	1    14500 7850
	1    0    0    -1  
$EndComp
$Comp
L HT82V739 U?
U 1 1 589EEB5A
P 13250 8050
F 0 "U?" H 13250 8450 60  0000 C CNN
F 1 "HT82V739" H 13250 7650 60  0000 C CNN
F 2 "" H 13250 8050 60  0000 C CNN
F 3 "" H 13250 8050 60  0000 C CNN
	1    13250 8050
	1    0    0    -1  
$EndComp
$Comp
L C 1uF
U 1 1 589EF26D
P 12500 7950
F 0 "1uF" H 12500 8050 40  0000 L CNN
F 1 "C" H 12506 7865 40  0000 L CNN
F 2 "" H 12538 7800 30  0000 C CNN
F 3 "" H 12500 7950 60  0000 C CNN
	1    12500 7950
	0    1    1    0   
$EndComp
$Comp
L C 1uF
U 1 1 589EF326
P 12550 8300
F 0 "1uF" H 12550 8400 40  0000 L CNN
F 1 "C" H 12556 8215 40  0000 L CNN
F 2 "" H 12588 8150 30  0000 C CNN
F 3 "" H 12550 8300 60  0000 C CNN
	1    12550 8300
	1    0    0    -1  
$EndComp
$Comp
L C 10uF
U 1 1 589EF3BD
P 13850 8200
F 0 "10uF" H 13850 8300 40  0000 L CNN
F 1 "C" H 13856 8115 40  0000 L CNN
F 2 "" H 13888 8050 30  0000 C CNN
F 3 "" H 13850 8200 60  0000 C CNN
	1    13850 8200
	1    0    0    -1  
$EndComp
$Comp
L RVR 10K
U 1 1 589EF5A5
P 11950 7950
F 0 "10K" V 11850 7850 50  0000 C CNN
F 1 "RVR" V 11850 8050 50  0000 C CNN
F 2 "" H 11950 7950 50  0000 C CNN
F 3 "" H 11950 7950 50  0000 C CNN
	1    11950 7950
	1    0    0    -1  
$EndComp
$Comp
L +5.0V #PWR?
U 1 1 589EFA9A
P 13850 8000
F 0 "#PWR?" H 13850 7960 30  0001 C CNN
F 1 "+5.0V" H 13850 8110 30  0000 C CNN
F 2 "" H 13850 8000 60  0000 C CNN
F 3 "" H 13850 8000 60  0000 C CNN
	1    13850 8000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589EFB56
P 12550 8500
F 0 "#PWR?" H 12550 8500 30  0001 C CNN
F 1 "GND" H 12550 8430 30  0001 C CNN
F 2 "" H 12550 8500 60  0000 C CNN
F 3 "" H 12550 8500 60  0000 C CNN
	1    12550 8500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589EFBBE
P 13850 8500
F 0 "#PWR?" H 13850 8500 30  0001 C CNN
F 1 "GND" H 13850 8430 30  0001 C CNN
F 2 "" H 13850 8500 60  0000 C CNN
F 3 "" H 13850 8500 60  0000 C CNN
	1    13850 8500
	1    0    0    -1  
$EndComp
$Comp
L +5.0V #PWR?
U 1 1 589F3F30
P 10650 8700
F 0 "#PWR?" H 10650 8660 30  0001 C CNN
F 1 "+5.0V" H 10650 8810 30  0000 C CNN
F 2 "" H 10650 8700 60  0000 C CNN
F 3 "" H 10650 8700 60  0000 C CNN
	1    10650 8700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2400 5950 2550
Wire Wire Line
	5600 3050 6550 3050
Wire Wire Line
	5600 3050 5600 2900
Wire Wire Line
	5300 2900 5300 3100
Wire Wire Line
	5450 2900 5450 3050
Wire Wire Line
	6050 4550 6550 4550
Connection ~ 6350 4550
Wire Wire Line
	6050 4850 6550 4850
Connection ~ 6350 4850
Connection ~ 6350 5150
Connection ~ 5750 4850
Wire Wire Line
	10150 4950 10250 4950
Wire Wire Line
	10250 4950 10250 5000
Wire Wire Line
	10150 4650 10250 4650
Wire Wire Line
	10150 3050 10250 3050
Wire Wire Line
	10250 3050 10250 3000
Wire Wire Line
	10150 3350 10250 3350
Wire Wire Line
	10250 3350 10250 3400
Wire Wire Line
	6550 3450 5150 3450
Wire Wire Line
	5150 3450 5150 2900
Wire Wire Line
	5000 2900 5000 3550
Wire Wire Line
	5000 3550 6550 3550
Wire Wire Line
	6550 3950 6450 3950
Wire Wire Line
	6450 3950 6450 4000
Wire Wire Line
	10150 3950 12450 3950
Wire Wire Line
	10150 4050 11950 4050
Wire Wire Line
	11950 4050 11950 3750
Wire Wire Line
	11950 3750 12450 3750
Wire Wire Line
	10150 4150 12150 4150
Wire Wire Line
	12150 4150 12150 4050
Wire Wire Line
	12150 4050 12450 4050
Connection ~ 5950 3050
Wire Wire Line
	6550 3350 6250 3350
Wire Wire Line
	6250 3350 6250 2650
Wire Wire Line
	6250 2650 12150 2650
Wire Wire Line
	12150 2650 12150 3850
Wire Wire Line
	12150 3850 12450 3850
Wire Wire Line
	14050 3950 14150 3950
Wire Wire Line
	14050 4250 14150 4250
Wire Wire Line
	14150 4250 14150 4350
Wire Wire Line
	10250 6050 10250 6100
Wire Wire Line
	10250 6500 10250 6550
Wire Wire Line
	10150 5550 10250 5550
Wire Wire Line
	13650 4950 14150 4950
Wire Wire Line
	14150 4950 14150 4850
Wire Wire Line
	14150 5350 14150 5250
Wire Wire Line
	14150 5250 13650 5250
Wire Wire Line
	10150 4350 12150 4350
Wire Wire Line
	12150 4350 12150 5350
Wire Wire Line
	12150 5350 12450 5350
Wire Wire Line
	10150 4450 11950 4450
Wire Wire Line
	11950 4450 11950 5250
Wire Wire Line
	11950 5250 12450 5250
Wire Wire Line
	4000 7800 4300 7800
Wire Wire Line
	4300 8100 4300 8800
Wire Wire Line
	4100 8600 4100 8800
Wire Wire Line
	4000 8300 4100 8300
Wire Wire Line
	3300 8700 3300 8800
Wire Wire Line
	2600 8300 2500 8300
Wire Wire Line
	1400 7800 2600 7800
Connection ~ 2500 7800
Wire Wire Line
	2200 8100 2200 8800
Connection ~ 2200 7800
Wire Wire Line
	1400 7950 1500 7950
Wire Wire Line
	1500 7950 1500 8100
Wire Wire Line
	4000 9400 4300 9400
Wire Wire Line
	4300 9400 4300 9300
Wire Wire Line
	4300 9700 4300 10400
Wire Wire Line
	4100 10200 4100 10400
Wire Wire Line
	4000 9900 4100 9900
Wire Wire Line
	3300 10300 3300 10400
Wire Wire Line
	2600 9900 2500 9900
Connection ~ 2500 9400
Wire Wire Line
	2200 9700 2200 10400
Connection ~ 2200 9400
Wire Wire Line
	1900 7800 1900 9400
Wire Wire Line
	1900 9400 2600 9400
Connection ~ 1900 7800
Wire Wire Line
	14150 3950 14150 3850
Wire Wire Line
	4300 7800 4300 7700
Wire Wire Line
	10550 7850 10800 7850
Connection ~ 10650 7850
Wire Wire Line
	9350 7850 10050 7850
Connection ~ 9450 7850
Connection ~ 9750 7850
Wire Wire Line
	8550 7850 8850 7850
Connection ~ 8650 7850
Wire Wire Line
	9450 7550 9450 7200
Wire Wire Line
	9450 7200 11650 7200
Wire Wire Line
	11650 7200 11650 7700
Wire Wire Line
	11450 7700 11950 7700
Wire Wire Line
	9750 7550 9750 7200
Connection ~ 9750 7200
Wire Wire Line
	10800 7550 10650 7550
Wire Wire Line
	10650 7550 10650 7200
Connection ~ 10650 7200
Wire Wire Line
	10650 8150 10650 8300
Wire Wire Line
	8650 8300 8650 8150
Wire Wire Line
	10350 9200 10350 8750
Wire Wire Line
	10350 8750 9700 8750
Wire Wire Line
	9700 8750 9700 9050
Wire Wire Line
	10650 8700 10650 9050
Wire Wire Line
	10650 9350 10650 9650
Wire Wire Line
	10000 9500 10650 9500
Connection ~ 10650 9500
Wire Wire Line
	10000 8900 10650 8900
Connection ~ 10650 8900
Connection ~ 11650 7700
Wire Wire Line
	11950 8200 11950 8300
Wire Wire Line
	12550 8450 12550 8500
Wire Wire Line
	12550 8150 12750 8150
Wire Wire Line
	12650 7950 12750 7950
Wire Wire Line
	12350 7950 12250 7950
Wire Wire Line
	13750 8350 13850 8350
Wire Wire Line
	13750 8050 13850 8050
Wire Wire Line
	13850 8050 13850 8000
Wire Wire Line
	13850 8350 13850 8500
Wire Wire Line
	13750 7750 14200 7750
Wire Wire Line
	13750 7850 14200 7850
Wire Wire Line
	14200 7850 14200 7950
Wire Wire Line
	10150 5450 10650 5450
Wire Wire Line
	10650 5450 10650 6950
Wire Wire Line
	10650 6950 8050 6950
Wire Wire Line
	8050 6950 8050 7850
Wire Wire Line
	6550 5550 6550 6850
Wire Wire Line
	6550 6850 12750 6850
Wire Wire Line
	12750 6850 12750 7750
Wire Wire Line
	6350 5150 6550 5150
$Comp
L GND #PWR?
U 1 1 589FE7D0
P 6350 5450
F 0 "#PWR?" H 6350 5450 30  0001 C CNN
F 1 "GND" H 6350 5380 30  0001 C CNN
F 2 "" H 6350 5450 60  0000 C CNN
F 3 "" H 6350 5450 60  0000 C CNN
	1    6350 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4550 5750 5150
$EndSCHEMATC
