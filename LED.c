void main() {
  while(1)
   {
    P0 = 0x00;        // Turn ON LEDs in PORT0 - 0 0 0 0 0 0 0 0
    P2 = 0x55;        // Turn ON/OFF alternate LEDs in PORT1 - 0 1 0 1 0 1 0 1
    Delay_ms(1000);   // 1 second delay

    P0 = 0xFF;        // Turn OFF LEDs in PORT0 - 1 1 1 1 1 1 1 1
    P2 = 0xAA;        // Turn OFF/ON alternate LEDs in PORT1 - 1 0 1 0 1 0 1 0
    Delay_ms(1000);   // 1 second delay
   }
}