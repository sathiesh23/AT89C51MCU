// LCD module connections
sbit LCD_RS at P2_2_bit;
sbit LCD_EN at P2_3_bit;
sbit LCD_D4 at P2_4_bit;
sbit LCD_D5 at P2_5_bit;
sbit LCD_D6 at P2_6_bit;
sbit LCD_D7 at P2_7_bit;
// End LCD module connections

unsigned int adc_rd;                 // Declare variables
char temperature[6];
long temp;

void send(unsigned char *s)
{
    while(*s) {
        SBUF=*s++;
        while(SCON.TI==0);
        SCON.TI=0;
    }
}

void main() {
SCON=0x50;
TMOD=0x20;
TH1=TL1=0xFD;
TCON.TR1=1;

P1 = 0xFF;           //Configure P1 as an input port
P3.F2 = 0;           //A = Output
P3.F3 = 0;           //B = Output
P3.F4 = 0;           //C = Output
P3.F5 = 0;           //ALE = Output
P3.F6 = 0;           //OE = Output
P3.F7 = 0;           //SoC = Output
P2.F0 = 1;           //EOC - End of conversion  - as an input pin

P3.F2 = 0;           //ADD A <- 0
P3.F3 = 0;           //ADD B <- 0
P3.F4 = 0;           //ADD C <- 0
P3.F5 = 1;           //ALE <- 1 : To latch the address

send("Temperature =");
delay_ms(500);

Lcd_Init();                      // LCD display initialization
Lcd_Cmd(_LCD_CURSOR_OFF);        // LCD command (cursor off)
Lcd_Cmd(_LCD_CLEAR);             // LCD command (clear LCD)

while(1)
        {
         adc_rd=0;
         P3.F7 = 1;                             //Start the conversion process
         delay_ms(1000);
         P3.F7 = 0;                             //Stop the conversion process
         delay_ms(1000);
         if (P2.F0==0)                          //Check whether EOC is high
            {
             P3.F6 = 1;
             adc_rd = P1;                           //Read P1
             temp = adc_rd*19.61;               // Convert it into Voltage value
             temp = temp/10;                    // Convert Voltage into Temperature (10 mV = 1 C)
             IntToStr(temp, temperature);       // Convert the Temperature value to string
             Lcd_Cmd(_LCD_CLEAR);               // LCD command (clear LCD)
             Lcd_Out(1,1,"Temperature:");       // Write result in LCD
             Lcd_Out(2,1,"In C=");
             Lcd_Out_CP(temperature);
             //Lcd_Out(2,14,"C");
             send(temperature);
             send("C");
             //send(0x0a);
             delay_ms(2000);
            }
        }
}