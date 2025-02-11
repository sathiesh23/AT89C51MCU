void main()
{
        P1.F7 = 1 ;                     // Configure P1.7 pin as an input pin
        while (1)
        {
                 if (P1.F7==0)          //if switch is pressed- Logic Low
                  {
                   P2.F7=0;             //Switch the lamp on
                   delay_ms(2000);
                  }
                  else
                  {
                   P2.F7=1;
                   delay_ms(2000);
                  }
        }
}