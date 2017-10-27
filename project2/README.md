# Fall 2017 ECEN 5813 Project 2

Brian Kelly & Rhea Cooper's project 2 for the ECEN 5813 class at University of Colorado Boulder

To set up the connection to the KL25Z board from Linux Virtual Box,
do these steps:

1. Download and install the USB drivers for both host Windows and Linux on Virtual Box

   The USB drivers can be seen at this link:

		http://www.pemicro.com/opensda/index.cfm

2.  Install the OpenSDA Firmware to the KL25z.  
    The firmware can be downloaded from the above link.
	Follow the instructions in that downloaded file.
	Make sure that you install this file in the bootloader:

		MSD-DEBUG-FRDM-KL25Z_Pemicro_v118.SDA

3.  On VirtualBox, click on the "Devices" menu at the top toolbar.
	Hover your mouse over to the "USB" section and click on this item:

		PE Microcomputer Systems Inc. OpenSDA Hardware [0800]

	Make sure that this item is checked on the menu box. 

4.  Plug in the KL25Z board to the USB Port. 
    You will see the Ubuntu make an automatic mount of the kl25z board.
	Check the difference when you see in this directory:  /dev/*

	When the kl25z is not plugged, sdb or sdb1 files are not there.
	If the board is plugged in, those sdb files appears automatically.

5.  Check "ttyACM0" file in the /dev/ directory to be sure
    that the USB is connected.  You can see the status of the peripherals
 	being plugged to Linux VM's USB ports by doing this command:

	lsusb

	Also enter this command:  

			dmesg  

	to see how Linux VM registers and assigns those USB peripherals. 

5.  Once you have the sdb1 file all set up in the /dev/ directory,
	do this command to mount your local directory to that "sdb" storage device.

		mkdir mount_kl25z; sudo mount /dev/sdb mount_kl25z;

6.  Build the project 2 files to generate project2.elf executable
		
7.  Open up a new terminal window and start a screen session:

		sudo screen /dev/ttyACM0 115200

	If you want to exit the screen, do this key:  ctrl-a + ctrl-d

8.  Copy the project2.elf executable to the "mount_kl25z" directory.
	
		sudo cp project2.elf /mount_kl25z/.

9.  You'll see the board starts to run the program and you can see activities
    on the screen session. 

 
