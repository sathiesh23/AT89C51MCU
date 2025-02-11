void main() {
P1 = 0xFF;   //Configure P1 as an input port
P3 = 0x00;   //Configure P3 as an output port
P2.F0 = 0;   //ADD A as an output pin
P2.F1 = 0;   //ADD B as an output pin
P2.F2 = 0;   //ADD C as an output pin
P2.F3 = 0;   //ALE as an output pin
P2.F6 = 0;   //SOC - Start of conversion  - as an output pin
P2.F7 = 1;   //EOC - End of conversion  - as an input pin

P2.F0 = 0;   //ADD A <- 0
P2.F1 = 0;   //ADD B <- 0
P2.F2 = 0;   //ADD C <- 0
P2.F3 = 1;   //ALE <- 1 : To latch the address
while(1)
        {
         P2.F6 = 1;     //Start the conversion process
         delay_ms(1000);
         P2.F6 = 0;     //Stop the conversion process
         delay_ms(1000);
         if (P2.F7==1)  //Check whether EOC is high
            {
             P3 = P1;   //Read P1 and send it to P3
             delay_ms(1000);
            }
        }
}