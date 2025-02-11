void Servo_Clk();
void Servo_AntiClk();
void Servo_Stop();

void main() {
P2.F0=0;                //Configure P2.0 as an Output Port Pin
P3.F0=1;                //Configure P3.0 as an Input Port Pin
P3.F1=1;                //Configure P3.1 as an Input Port Pin
while(1)
        {
        P2.F0=0;
        if (P3.F0==0 && P3.F1==1)
           {
            Servo_Clk();
           }
        else if (P3.F0==1 && P3.F1==0)
           {
            Servo_AntiClk();
           }
        else
            {
             Servo_Stop();
            }
        }
}

void Servo_Clk()
{
 P2.F0=1;
 delay_us(600);
 P2.F0=0;
 delay_us(19400);
 
 delay_ms(1000);
 
 P2.F0=1;
 delay_us(1500);
 P2.F0=0;
 delay_us(18500);
 
 delay_ms(1000);
 
 P2.F0=1;
 delay_us(2400);
 P2.F0=0;
 delay_us(17600);
 
 delay_ms(1000);
}

void Servo_AntiClk()
{
 P2.F0=1;
 delay_us(2400);
 P2.F0=0;
 delay_us(17600);

 delay_ms(1000);
 
 P2.F0=1;
 delay_us(1500);
 P2.F0=0;
 delay_us(18500);

 delay_ms(1000);
 
 P2.F0=1;
 delay_us(600);
 P2.F0=0;
 delay_us(19400);

 delay_ms(1000);
}

void Servo_Stop()
{
 P2.F0=0;
}