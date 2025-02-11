void main() {
P3.F0=1;        // Configure P3.0 as input (Switch)
P3.F1=1;        // Configure P3.1 as input (Switch)
P2.F0=0;        // Configure P2.0 as output (DC Motor)
P2.F1=0;        // Configure P2.1 as output (DC Motor)
while(1)
        {
         if(P3.F0==0 && P3.F1==1) // Check P3.0 (Switch) is pressed
                     {
                      P2.F0=1;    //Clockwise Rotation
                      P2.F1=0;
                      delay_ms(100);
                     }
         else if(P3.F0==1 && P3.F1==0) // Check P3.1 (Switch) is pressed
                     {
                      P2.F0=0;    //Anticlockwise Rotation
                      P2.F1=1;
                      delay_ms(100);
                     }
         else
                     {
                      P2.F0=1;
                      P2.F1=1;
                      delay_ms(100);
                     }
        }
}