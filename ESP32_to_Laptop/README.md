# ESP32_WiFi_Monitor
Storing measurement data from ESP32

1. Open new project with PlatformIO in vscode, choosing this directory.
2. Out of the box it can't find the Arduino library. Simply restarting VSCode fixed it - build runs fine.
3. Added WebServer - no issue. Then added our own header file for our credentials to keep wifi credential secure. I think it's best to open the project with how PlatformIO wants it (with the .ini) and then open the repo in vs code after.
4. Remember to change the monitor_speed in platformio.ini. With this all done you can upload the task and monitor task using top right Serial Monitor (crt alt s)