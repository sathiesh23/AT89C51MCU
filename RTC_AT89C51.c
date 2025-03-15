// Lcd module connections
sbit LCD_RS at P3_0_bit;
sbit LCD_EN at P3_1_bit;

sbit LCD_D4 at P3_4_bit;
sbit LCD_D5 at P3_5_bit;
sbit LCD_D6 at P3_6_bit;
sbit LCD_D7 at P3_7_bit;
// End Lcd module connections

// RTC Interfacing with AT89C51 in MikroC

sbit SDA at P2_0_bit;  // Define SDA pin
sbit SCL at P2_1_bit;  // Define SCL pin

// Function to generate delay for I2C
void I2C_Delay() {
    delay_us(5);
}

// I2C Start Condition
void I2C_Start() {
    SDA = 1; SCL = 1;
    I2C_Delay();
    SDA = 0;
    I2C_Delay();
    SCL = 0;
}

// I2C Stop Condition
void I2C_Stop() {
    SDA = 0; SCL = 1;
    I2C_Delay();
    SDA = 1;
}

// I2C Write Function
void I2C_Write(unsigned char dat) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        SDA = (dat & 0x80) ? 1 : 0;
        SCL = 1;
        I2C_Delay();
        SCL = 0;
        dat <<= 1;
    }
    SDA = 1; // Release SDA
    SCL = 1; // Wait for ACK
    I2C_Delay();
    SCL = 0;
}

// I2C Read Function
unsigned char I2C_Read(unsigned char ack) {
    unsigned char i, dat = 0;
    SDA = 1; // Release SDA
    for (i = 0; i < 8; i++) {
        SCL = 1;
        I2C_Delay();
        dat = (dat << 1) | SDA;
        SCL = 0;
    }
    SDA = ack ? 0 : 1; // ACK/NACK
    SCL = 1;
    I2C_Delay();
    SCL = 0;
    return dat;
}

// Convert BCD to Decimal
unsigned char BCD_To_Decimal(unsigned char bcd) {
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

// Read Time from DS1307
void Read_RTC() {
    unsigned char sec, min, hour;

    I2C_Start();
    I2C_Write(0xD0); // DS1307 Write Address
    I2C_Write(0x00); // Set Register Pointer to 0x00
    I2C_Start();
    I2C_Write(0xD1); // DS1307 Read Address

    sec = I2C_Read(1);
    min = I2C_Read(1);
    hour = I2C_Read(0);

    I2C_Stop();

    // Convert BCD to Decimal
    sec = BCD_To_Decimal(sec);
    min = BCD_To_Decimal(min);
    hour = BCD_To_Decimal(hour);

    // Display on LCD
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Out(1, 1, "Time: ");
    Lcd_Chr_Cp(hour / 10 + '0');
    Lcd_Chr_Cp(hour % 10 + '0');
    Lcd_Chr_Cp(':');
    Lcd_Chr_Cp(min / 10 + '0');
    Lcd_Chr_Cp(min % 10 + '0');
    Lcd_Chr_Cp(':');
    Lcd_Chr_Cp(sec / 10 + '0');
    Lcd_Chr_Cp(sec % 10 + '0');
}

// Main Function
void main() {
    Lcd_Init();   // Initialize LCD
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);

    while (1) {
        Lcd_Out(1,1,"Real Time Clock");                 // Write text in second row
        Delay_ms(2000);
        Lcd_Cmd(_LCD_CLEAR);               // Clear display
        Read_RTC();
        delay_ms(1000); // Update every second
    }
}