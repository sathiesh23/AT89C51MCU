void main() {
unsigned char i=0;

while(1)
        {
         for (i=0; i<=7; i++)
             {
              P2 = ~(0x80 >> i);        //Right Shift by i positions - 0 1 1 1 1 1 1 1
              delay_ms(1000);
              if (P2 == 0xFE)           // P2 = 1 1 1 1 1 1 1 0
                 {
                  P2 = ~(0x80);         // P2 = 0 1 1 1 1 1 1 1
                 }
             }
        }
}