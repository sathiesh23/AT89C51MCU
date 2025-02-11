void Stepper_Clock()
{
   P3=0x06;                   //0   - 0000 0110
   delay_ms(1000);
   P3=0x03;                  //90   - 0000 0011
   delay_ms(1000);
   P3=0x09;                  //180  - 0000 1001
   delay_ms(1000);
   P3=0x0C;                 //270   - 0000 1100
   delay_ms(1000);
   P3=0x06;                  //0    - 0000 0110
   delay_ms(1000);
}
void Stepper_AntiClock()
{
   P3=0x06;               //0       - 0000 0110
   delay_ms(1000);
   P3=0x0C;                //270    - 0000 1100
   delay_ms(1000);
   P3=0x09;               //180     - 0000 1001
   delay_ms(1000);
   P3=0x03;               //90      - 0000 0011
   delay_ms(1000);
   P3=0x06;                //0      - 0000 0110
   delay_ms(1000);
}

void main() {
 P3=0x00;
 while(1)
 {
  Stepper_Clock();
  delay_ms(2000);
  Stepper_AntiClock();
  delay_ms(2000);
 }
}