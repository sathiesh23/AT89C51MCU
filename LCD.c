// Lcd module connections
sbit LCD_RS at P2_2_bit;
sbit LCD_EN at P2_3_bit;

sbit LCD_D4 at P2_4_bit;
sbit LCD_D5 at P2_5_bit;
sbit LCD_D6 at P2_6_bit;
sbit LCD_D7 at P2_7_bit;
// End Lcd module connections

char txt1[] = "AT89C51";
char txt2[] = "Programming";
char txt3[] = "Lcd-4bit Mode";
char txt4[] = "Example";

char i;                              // Loop variable

void main(){

  Lcd_Init();                        // Initialize Lcd

  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Out(1,3,txt3);                 // Write text in first row

  Lcd_Out(2,6,txt4);                 // Write text in second row
  Delay_ms(2000);
  Lcd_Cmd(_LCD_CLEAR);               // Clear display

  Lcd_Out(1,6,txt1);                 // Write text in first row
  Lcd_Out(2,4,txt2);                 // Write text in second row

  Delay_ms(2000);

  while(1) {                         // Endless loop
    for(i=0; i<8; i++) {             // Move text to the left 8 times
      Lcd_Cmd(_LCD_SHIFT_LEFT);
      delay_ms(1000);
    }

    for(i=0; i<8; i++) {             // Move text to the right 8 times
      Lcd_Cmd(_LCD_SHIFT_RIGHT);
      delay_ms(1000);
    }
  }
}
