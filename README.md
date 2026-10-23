# SmokeyENES OTV

## Global AI Disclosure:
 - Zed's AI line completion was used in the making of this project.
 - Google's Gemini frequently assisted with code examples, explanations, and debugging.

## Steps for Carmyn

1. Download the zip file from GitHub (Code Dropdown, or github desktop)
2. Extra/Unzip the file 
3. Open the new folder
4. Inside there will be another 'SmokeyENES-main' folder
5. Rename that inner folder to 'SmokeyENES'
6. Open in arduino IDE (Drag over Arduino IDE if on windows)
7. Should be good to go!

## To Compile & Flash Board (For Tyler):

- Make sure to change COM paramter to the correct port.

```
arduino-cli board list
arduino-cli upload -p COM12 --fqbn arduino:renesas_uno:unor4wifi . --verbose
arduino-cli monitor -p COM12 -c baudrate=115200
```

## Build/Flash & Serial Monitor Hotkeys

```
Ctrl+Alt+B # Build & Flash
Ctrl+Alt+M # Open Serial Monitor
```

## Arduino Resources & Libraries

- [Quick Reference](https://cdn.sparkfun.com/assets/2/5/4/1/8/NewArduinoCheatsheet_1.pdf)
- [Omron Flame Sensor](https://github.com/omron-devhub/d6t-2jcieev01-arduino)
