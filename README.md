# SmokeyENES OTV

AI Disclosure:
 - AI line completion was used in the making of this project.

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

## Arduino Resources

- [Quick Reference](https://cdn.sparkfun.com/assets/2/5/4/1/8/NewArduinoCheatsheet_1.pdf)
