void main() {
unsigned char dice_value = 0;
P1.F7 = 1;                   // Configure the P1.7 pin as an input pin
P2 = 0x00;                   //Configure P2 as Output port
while(1)
        {
         if (P1.F7==0)       //Check whether the switch is pressed
            {
              dice_value = rand()% 7;
              if (dice_value == 0)
                 {
                  dice_value = rand()% 7;
                 }
              if (dice_value>0)
                 {
                 switch (dice_value)
                  {
                  case 1: P2=0xFE;              //1 1 1 1 1 1 1 0
                          delay_ms(1000);
                          break;
                  case 2: P2=0xFC;              //1 1 1 1 1 1 0 0
                          delay_ms(1000);
                          break;
                  case 3: P2=0xF8;              //1 1 1 1 1 0 0 0
                          delay_ms(1000);
                          break;
                  case 4: P2=0xF0;              //1 1 1 1 0 0 0 0
                          delay_ms(1000);
                          break;
                  case 5: P2=0xE0;              //1 1 1 0 0 0 0 0
                          delay_ms(1000);
                          break;
                  case 6: P2=0xC0;              //1 1 0 0 0 0 0 0
                          delay_ms(1000);
                          break;
                  }
                 }
            }
         else
         {
          P2=0xFF;              //1 1 1 1 1 1 1 1
          delay_ms(1000);
         }
        }
}