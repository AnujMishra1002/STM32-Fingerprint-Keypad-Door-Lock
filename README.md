Admin & Enrollment Flow (example)

Admin presses * for 3 seconds → enters admin mode

Prompt: 1:Enroll 2:Delete 3:List on OLED or keypad prompts

For Enroll: system asks for new PIN (if using), then asks to place finger twice. System assigns next available template ID and stores mapping

Testing Plan

Unit test keypad scanning with debouncing

Test UART comms with fingerprint module monitor

Verify actuator control for 5s unlock

Stress test enrollment and deletion

Power-cycle test for storage persistence

What to commit to GitHub

firmware/ code with clear README describing build steps

hardware/schematic.png (hand-drawn or Eagle/KiCad screenshot)

docs/user-guide.md describing how to enroll and operate

LICENSE (MIT recommended)

Designed and implemented an STM32-based fingerprint + keypad door lock using UART-interfaced fingerprint module, 4×4 keypad, and relay actuator; implemented user enroll/delete, secure PIN fallback, and persistent storage of templates in flash.

Implemented non-blocking keypad scanning, UART fingerprint parsing, and actuator control using HAL drivers; integrated optional SD logging and RTC timestamping.


Provide a full main.c + driver files implemented to compile in STM32CubeIDE for a chosen MCU (I'll pick STM32F103C8 if you want).

Create a ready-to-paste STM32CubeMX configuration (pinout + peripheral settings) as text guidance.

Write hardware/schematic.png as an ASCII wiring diagram or provide KiCad/Eagle snippets.
