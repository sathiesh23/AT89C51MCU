void main() {
P1.F7 = 1;                      //Set PORT1 to be an input port
while(1)
        {
         if (P1.F7 == 0)        //To check whether switch is pressed do the following action
            {
             P2 = 0x00;         // P2 = 0 0 0 0 0 0 0 0
             delay_ms(1000);
             P2 = 0xFF;         // P2 = 1 1 1 1 1 1 1 1
             delay_ms(1000);
            }
         else                   //If switch is not pressed do the following action
             {
              P2 = 0x55;        // P2 = 0 1 0 1 0 1 0 1
              delay_ms(1000);
              P2 = 0xAA;        // P2 = 1 0 1 0 1 0 1 0
              delay_ms(1000);
             }
        }
}