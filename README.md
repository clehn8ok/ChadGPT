# README - ChadGPT - Digispark ATtiny85 Arduino Setup

## Overview
This guide provides step-by-step instructions on how to set up the Arduino IDE for programming a Digispark ATtiny85 board. It covers installing necessary software, setting up drivers, configuring the Arduino environment, and uploading code to the microcontroller.

## Features
- **Arduino IDE Installation**: Instructions to install and configure the IDE.
- **Driver Installation**: Guides Windows users on how to install Digistump drivers.
- **Board Manager Setup**: Adds ATTinyCore to the Arduino IDE for Digispark compatibility.
- **Library Installation**: Steps to install the DigisparkKeyboard library.
- **Sketch Compilation and Upload**: Detailed process for compiling and uploading sketches.

## Files Included
- **ATTinyCore_BOARDLIBRARY.zip**: Contains the ATTinyCore board package for manual installation.
- **DigisparkKeyboard-master_LIBRARY.zip**: Library required for Digispark keyboard functionality.
- **Digistump_DRIVER.zip**: Windows drivers needed for Digispark ATtiny85 board recognition.
- **HowTo_ChadGPT.pdf**: A step-by-step guide for setting up and programming the Digispark ATtiny85.
- **README.md**: This document providing an overview and instructions.
- **chadGPT_attiny85.ino**: The Arduino sketch file to be uploaded to the Digispark ATtiny85.

## Requirements
- Digispark ATtiny85 board
- USB connection (with appropriate drivers installed) --> make sure you use a DATA micro USB cable, most of them only charge, you need to try different ones, if it doesnt work.
- Arduino IDE (latest version)
- Internet connection for downloading required software (alternative manual methods provided)

## How to Use
1. Follow the installation steps in the main setup document.
2. Copy and configure the `chadGPT_attiny85.ino` sketch.
3. Install the required board manager and libraries.
4. Compile and upload the sketch to your Digispark ATtiny85.
5. Verify successful upload by checking for the **Device Ready** message in the Arduino IDE.

For any issues, refer to the troubleshooting notes included in the full guide.

