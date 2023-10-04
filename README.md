# PCB_Design
PCB design files from ECE 315(Altium)
This project contains design files for a two layer board
In addition to c files needed to program the board
  Function of the board
    A simple 4 alphanumeric LED being driven by an I2C chip(powered by a step down designed using the altium
      schematic capture tool)
    The board houses two 20 pin connectors that interfaces with an MSP432 Launchpad 
      essentially borrowing its ARM processor to run computations
    The board also houses capacitive touch sensitive pads to adjust time and alarm setting
      between countdown to zero with varying levels of noise
    The board also contains a buzzer that was programmed to play certain tunes set by the 
    cap touch sensitive pads
