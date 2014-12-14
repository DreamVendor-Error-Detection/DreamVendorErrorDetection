3D-Printer-Vision-Error-Correction-System
=========================================

A project for Virginia Tech Mechatronics Lab started in Fall of 2014. The goal of this project is to assist in the detection of printing errors for Virginia Tech DREAMS Lab's DreamVendor 2.0. The idea is to use both a real and virtual image capture-comparison system to detect (and potentially correct) errors that commonly occur with 3D printers. 

This system can be broken into three parts:
1. - Virtual Image-Capture
2. - Real Image-Capture
3. - Image Comparison

Part 1 - Virtual Image-Capture
==============================
In order to know that an error has occurred, the actual part being printed needs to be compared to an ideal (i.e. perfect, no errors) part. Commands for a 3D printer are written in machine code (G-Code). Using 3D simulation software, these commands - along with the conditions of an actual printer - can be simulated and the result can be observed. Repetier is a program that has these capabilities. Though the source code is not readily available to modify, it is equipped to use plugins that can be provided in the form of .dll's that allow for customization of the interface and capabilities of the program. We are using Repetier in tandem with our own plugin (a modified version of the demo-plugin provided by Repetier on their website, which was not functioning at first, by the way) to manipulate camera angles, processing, lighting, and other settings to emulate the real-world cameras we have in place. These provide idea models for the real images to be compared to. Currently the plugin is still being developed. The features implemented already and the ones that will be implemented in the future are shown below:
  Features Implemented:
  
  ..1. Creation of operational plugin
  ..2. Button test interface
  ..3. Camera angle manipulation
  Features to be Implemented
