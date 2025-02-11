unsigned char r[20];
unsigned char i=0;
unsigned char data_rcd=0;

void send(unsigned char *s)
{
    while(*s) {
        SBUF=*s++;
        while(SCON.TI==0);
        SCON.TI=0;
    }
}

void receive()
{
     while(SCON.RI==0);
        r[i]=SBUF;           //Received data is stored into the a variable
        i=i+1;
        SCON.RI=0;
        if (SBUF==13)
           {
            data_rcd=1;
           }
        else
            {
             data_rcd=0;
            }
}

void init_r()
{
 for (i=0; i<20; i++)
     {
      r[i]=0;
     }
 i=0;
}

void main()
{
    SCON=0x50;
    TMOD=0x20;
    TH1=TL1=0xFD;
    TCON.TR1=1;
    
    send("AT89C51 - UART... ");

    while(1) {
        if (data_rcd==1)
        {
         send(r);
         init_r();
         data_rcd=0;
         }
        else
        {
         receive();
        }
    }
}