void ext_int0() iv IVT_ADDR_EX0 ilevel 0 ics ICS_AUTO 
{
 IE.EA=0;       //Disable all the interrupts
 P2=0xAA;       //Alternate LEDs are ON -> 10101010
 delay_ms(1000);
 P2=0x55;       //Alternate LEDs are ON -> 01010101
 delay_ms(1000);
 IE.EA=1;       //Enable all the interrupts
}

void main() {
P2=0X00;     //P2 is configured as Output
P3.F2=1;     //P3.2/INT0' pin is configured as Input
TCON.IT0=1;  //Interrupt triggering using Falling Edge
IE.EX0=1;    //Enable INT0' interrupt
IE.EA=1;     //Enable all the interrupts

while(1)
        {
         P2=0xFF;         //LEDs are OFF
         delay_ms(1000);
         P2=0x00;         //LEDs are ON
         delay_ms(1000);
        }
}