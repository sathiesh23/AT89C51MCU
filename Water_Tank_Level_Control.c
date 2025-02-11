void water_inlet()
{
P2.F0=1;
P2.F1=0;
}

void water_outlet()
{
P2.F2=1;
P2.F3=0;
}

void inlet_stop()
{
P2.F0=1;
P2.F1=1;
}

void outlet_stop()
{
P2.F2=1;
P2.F3=1;
}

unsigned char in=0, out=0;

void main() {
 P1.F0=1;           //P1.0 is configured as an Input port
 P1.F1=1;           //P1.1 is configured as an Input port
 P2=0x00;           //P2 is configured as an Output port

 while(1)
 {
  while(P1.F0==1 && P1.F1==1 && in==0 && out==0)
     {
       water_inlet();
       outlet_stop();
       if(P1.F0==0 && P1.F1==1 && in==0 && out==0)
         {
          in=1;
         }
     }
  while(P1.F0==0 && P1.F1==1 && in==1 && out==0)
     {
      water_inlet();
      outlet_stop();
      if(P1.F0==0 && P1.F1==0 && in==1 && out==0)
         {
          in=0;
         }
     }
  while(P1.F0==0 && P1.F1==0 && in==0 && out==0)
     {
      water_outlet();
      inlet_stop();
      if(P1.F0==0 && P1.F1==1 && in==0 && out==0)
         {
          out=1;
         }
     }
  while(P1.F0==0 && P1.F1==1 && in==0 && out==1)
     {
      water_outlet();
      inlet_stop();
      if(P1.F0==1 && P1.F1==1 && in==0 && out==1)
         {
          out=0;
         }
     }
 }
}