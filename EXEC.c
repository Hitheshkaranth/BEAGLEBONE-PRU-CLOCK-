/* 
* This overlay is based on the BB-PRU-01 overlay
* Written by HITHESH KARANTH for BEAGLE-BONE-PRU-CLOCK
*/

#include <stdio.h>
#include <prussdrv.h>
#include <pruss_intc_mapping.h>

static int cleanUp(void)
{
        // Disable PRU 0
	prussdrv_pru_disable(0);
	prussdrv_exit ();

	return 0;
}

int main (void)
{
	// Initialize structure used by prussdrv_pruintc_intc
	// PRUSS_INTC_INITDATA is found in pruss_intc_mapping.h
	tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
	
        // Initialize the PRU Interrupt System
	prussdrv_init ();
	prussdrv_open (PRU_EVTOUT_0);
	prussdrv_pruintc_init(&pruss_intc_initdata);
	
	// Load and execute the PRU program on the PRU (PRU 0)
        // For PRU 1 write a 1 instead of the 0 as the first
        // parameter
	prussdrv_exec_program (0, "./SIGNAL.bin");//ADD any of the .bin file to be loaded to PRU here

        // Now wait here until the PRU messages the host
        // That it finished executing the program
	int n = prussdrv_pru_wait_event (PRU_EVTOUT_0);
	printf("Pru ended. Event: %i\n", n);
	
	// Disable PRU
	return cleanUp();
}
