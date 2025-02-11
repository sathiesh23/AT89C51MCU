unsigned char pot_value=0;
unsigned int t=255;

void software_pwm(char);
void conf_delay(char);

void main() {
P2=0x00;               //PORT2 is configured as Output Port
P3=0xC0;               //P3.0 - P3.5 -> Output; P3.6, P3.7 -> Input
P1=0xFF;               //P1 -> Input

P3.F0=0;               //To Select IN0 of ADC0808 ; A = 0
P3.F1=0;               //To Select IN0 of ADC0808 ; B = 0
P3.F2=0;               //To Select IN0 of ADC0808 ; C = 0

P3.F3=1;               //ALE = 1
P3.F4=0;               //SOC = 0 -> Stop ADC Conversion
P3.F5=0;               //OE = 0 -> Output Enable is Disabled
while(1)
        {
         if(P3.F6==0)       // Switch is pressed
         {
          P3.F4=1;          //Start the ADC Conversion Process
          delay_ms(10);
          P3.F4=0;          //Stop the ADC Conversion Process
          delay_ms(10);
          if (P3.F7==0)     //Check whether EOC is active
             {
              P3.F5=1;      //OE = 1 -> Output Enable is Enabled
              pot_value = P1;
              P2.F0 = 1;    //DC Motor Connection - Clockwise
              P2.F1 = 0;
              software_pwm(pot_value);
              P3.F6=1;
              }
          }
         else               //P3.F6 == 1 (Switch is not pressed)
          {
           P2.F0=0;     //Stop the DC motor
           P2.F1=0;
          }
        }
}

void software_pwm(char duty)
{
 P2.F2=1;             // PWM signal generation - E line
 conf_delay(duty);
 P2.F2=0;
 conf_delay((t-duty));
}

void conf_delay(char duty)
{
 unsigned int i;
 for (i=0; i<=duty; i++)
     {
      delay_ms(1);
      delay_ms(1);
      delay_ms(1);
      delay_ms(1);
     }
}