// LCD module connections
sbit LCD_RS at P2_2_bit;
sbit LCD_EN at P2_3_bit;
sbit LCD_D4 at P2_4_bit;
sbit LCD_D5 at P2_5_bit;
sbit LCD_D6 at P2_6_bit;
sbit LCD_D7 at P2_7_bit;
// End LCD module connections

// Keypad Mapping
char keypad[4][4] = { {'7', '8', '9', '/'},
                      {'4', '5', '6', '*'},
                      {'1', '2', '3', '-'},
                      {'.', '0', '=', '+'} };

// Function to scan keypad
char keypad_scan() {
    char row, col;
    P3 = 0xFF;                                          // Configure Port 3 as input

    for (row = 0; row < 4; row++) {
        P3 = ~(1 << row);                               // Ground one row at a time
        for (col = 0; col < 4; col++) {
            if (!(P3 & (1 << (col + 4)))) {             // Check column
                while (!(P3 & (1 << (col + 4))));       // Wait for key release
                return keypad[row][col];                // Return key pressed
            }
        }
    }
    return 0;                                           // No key pressed
}

// Delay Function
void delay_ms(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 1275; j++);
}

void main() {
  char key;
  Lcd_Init();                              // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);                     // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);                // Cursor off
  Lcd_Out(1, 1, "Keypad Interface");
  delay_ms(1000);
  Lcd_Cmd(_LCD_CLEAR);

  while(1)
  {
        key = keypad_scan();
        if (key != 0) {
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Out(1, 1, "Key Pressed:");
            Lcd_Chr(2, 6, key);
        }
  }
}