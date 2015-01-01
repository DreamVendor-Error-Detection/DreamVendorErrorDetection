3D-Printer-Vision-Error-Correction-System
=========================================

A project for Virginia Tech Mechatronics Lab started in Fall of 2014. The goal of this project is to assist in the detection of printing errors for Virginia Tech DREAMS Lab's DreamVendor 2.0. The idea is to use both a real and virtual image capture-comparison system to detect (and potentially correct) errors that commonly occur with 3D printers. 

This system can be broken into three parts:
  1. Virtual Image-Capture
  2. Real Image-Capture
  3. Image Comparison

Part 1 - Virtual Image-Capture
==============================
In order to know that an error has occurred, the actual part being printed needs to be compared to an ideal (i.e. perfect, no errors) part. Commands for a 3D printer are written in machine code (G-Code). Using 3D simulation software, these commands - along with the conditions of an actual printer - can be simulated and the result can be observed. Repetier is a program that has these capabilities. Though the source code is not readily available to modify, it is equipped to use plugins that can be provided in the form of .dll's that allow for customization of the interface and capabilities of the program. We are using Repetier in tandem with our own plugin (a modified version of the demo-plugin provided by Repetier on their website, which was not functioning at first, by the way) to manipulate camera angles, processing, lighting, and other settings to emulate the real-world cameras we have in place. These provide ideal models to compare to the real images. Currently the plugin is still being developed. The features implemented already and the ones that will be implemented in the future are shown below:  
Features Implemented:
  * Creation of operational plugin
  * Button test interface
  * Camera angle manipulation  

Features to be Implemented:
  * Full plugin functionality
    * Cameras oriented the same as real cameras
    * Lighting set up to provide clearest image possible
    * Modification of 3D modeling environment/Screenshot export in order to improve export image resolution
    * Specification of real 3D printer settings to best replicate conditions
  * Image capture and storage
    * Automatically increment through layers of virtual print and capture images at each stage
    * Take file input from 3D printing software and load into Repetier to be analyzed
    * Make place and name convention for picture storage
    * Clear stored images after each run
  
Part 2 - Real Image-Capture
==============================
To determine if an error has a occured, the progress of the actual printing process needs to be captured. This comes with several difficult factors. Several different angles need to be captured because errors can occur on any part of a print. The printer we are working with has a resolution of 0.05". We determined that 8MP cameras would be enough to satisfy thi resoltion differentation requirement. Currently we have 3 cameras that will be set up along three different locations in the printer. These will provide a start on the images we need to capture the errors. Reflectoins and lighting will prove a difficult factor to deal with in the image capture process. We will need to isolate the print itself for analysis. The printer head will also get in the way of the cameras' views of the print. We will need a way to discount the presence of the printer head and isolate the print itself. Hardware of some sort will be needed to execute the image capture process. THis could be a microcontroller, miniatuare ARM-based 32-bit platform, or a full blown computer. These needs have yet to be determined. In summation:

Features Implemented:
  * Cameras
    * Camera brackets designed and printed
    * Camera placement determined (subject to change)
    * Cameras selected and bought

Features to be Implemented:
  * Cameras & other hardware
    * Cameras need to be placed in 3D printer enclosure
    * Computing platform needs to be determined
  * Image Capture program
    * Take inputs from 3D printing software regarding estimated print time (or potentially print stage cues)
    * 
  
