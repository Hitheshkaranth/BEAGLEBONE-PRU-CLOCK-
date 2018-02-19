# BEAGLEBONE-PRU-CLOCK-
The follwowing repository consists of code for generating clock pulses using Programmable Real-time unit of Beaglebone black Rev C

Proceedure for running the code on PRU-

0.Check wheater the kernel version is 3.8.x and pasm (PRU-ASSEMBLER) is installed:
for the kernel version use- uname -r
for the pasm version use - pasm --version

1.Generate .dtbo or device tree boolean for the provided .dts or device tree source this can be acheived using the command 
dtc -O dtb -o BB-WAVE-GEN:00A0.dtbo -b 0 -@ BB-WAVE-GEN:00A0.dts
dtc -O dtb -o BB-WAVE-GEN1:00A0.dtbo -b 0 -@ BB-WAVE-GEN1:00A0.dts

2.Copy the generated.dtbo file to firmware directory 
cp BB-WAVE-GEN:00A0.dtbo
cp BB-WAVE-GEN1:00A0.dtbo

this should be done being super user : su followed on by password
3.Load the .dtbo or device tree boolean files to slots of the beaglebone black this is perforemed using the command
sudo echo BB-WAVE-GEN:00A0.dtbo > /sys/devices/bone_capemgr.9/slots
sudo echo BB-WAVE-GEN1:00A0.dtbo > /sys/devices/bone_capemgr.9/slots

4.Generate .bin file or binaries for the PRU of BEaglebone black using this command
pasm -b SIGNAL.p

5.Compile the PRU binary loader .c file output file (The functionality being it loads .bin file to PRU)
gcc EXEC.c -lprussdrv -lpthread -o EXEC

6.execute the generated output file using the command 
sudo ./EXEC
if the above command failes to respond then use chomd +x EXEC
follwoed on by the above commad.

____________________________________________________________________________________________________________________________________
