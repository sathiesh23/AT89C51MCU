// LCD module connections
sbit LCD_RS at P3_2_bit;
sbit LCD_EN at P3_3_bit;
sbit LCD_D4 at P3_4_bit;
sbit LCD_D5 at P3_5_bit;
sbit LCD_D6 at P3_6_bit;
sbit LCD_D7 at P3_7_bit;
// End LCD module connections

unsigned int adc_rd;                 // Declare variables
char *text, *text1;                  //
char temperature[6];
long temp;

void main() {
P1 = 0xFF;           //Configure P1 as an input port
P3 = 0x00;           //Configure P3 as an output port
P2.F0 = 0;           //ADD A as an output pin
P2.F1 = 0;           //ADD B as an output pin
P2.F2 = 0;           //ADD C as an output pin
P2.F3 = 0;           //ALE as an output pin
P2.F6 = 0;           //SOC - Start of conversion  - as an output pin
P2.F7 = 1;           //EOC - End of conversion  - as an input pin

P2.F0 = 0;           //ADD A <- 0
P2.F1 = 0;           //ADD B <- 0
P2.F2 = 0;           //ADD C <- 0
P2.F3 = 1;           //ALE <- 1 : To latch the address

Lcd_Init();                      // LCD display initialization
Lcd_Cmd(_LCD_CURSOR_OFF);        // LCD command (cursor off)
Lcd_Cmd(_LCD_CLEAR);             // LCD command (clear LCD)

text = "LM35-Temperature";       // Define the first message
text1 = "Sensor Interface";      // Define the second message
Lcd_Out(1,1,text);               // Write the first message in the first line
Lcd_Out(2,1,text1);              // Write the second message in the second line
delay_ms(2000);

while(1)
        {
         adc_rd=0;
         P2.F6 = 1;                             //Start the conversion process
         delay_ms(1000);
         P2.F6 = 0;                             //Stop the conversion process
         delay_ms(1000);
         if (P2.F7==1)                          //Check whether EOC is high
            {
             adc_rd = P1;                           //Read P1
             temp = adc_rd*19.61;               // Convert it into Voltage value
             temp = temp/10;                    // Convert Voltage into Temperature (10 mV = 1 C)
             IntToStr(temp, temperature);       // Convert the Temperature value to string
             Lcd_Cmd(_LCD_CLEAR);               // LCD command (clear LCD)
             Lcd_Out(1,1,"Temperature:");       // Write result in LCD
             Lcd_Out(2,1,"In C=");
             Lcd_Out_CP(temperature);
             Lcd_Out(2,14,"C");
             delay_ms(2000);
            }
        }
}