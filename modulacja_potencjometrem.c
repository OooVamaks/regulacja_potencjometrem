#include <reg52.h>
#include <instrins.h>
#include <lcd.h>
#include <mkd51sim.h>

unsigned char xdata PTWE _at_ 0x8008;
unsigned char xdata PTWY _at_ 0x8009;
unsigned char xdata POT0 _at_ 0x8005;
unsigned char xdata POT1 _at_ 0x8006;
unsigned char xdata tblcw[        +                       ];

int dummy, dummy2, fejk, fejk2, wynik;
void licz(int dumb);
unsigned char jednostki, dziesiatki, setki, combo,delay;

void main(void){
prglcd();

  while(1){
    POT1=0;
    for(delay=0;delay<120;delay++){
      dummy=POT1;
      fejk=(dummy*100+128)/256; //aby zmienić zakres, zmień 100 na coś innego
      licz(fejk);
      tblcw[0]='0'+setki;
      tblcw[1]='0'+dziesiatki;
      tblcw[2]='0'+jednosci;
    }
    POT0=0;
    for(delay=0;delay<120;delay++){
      dummy2=POT0;
      fejk2=(dummy*100+128)/256; //aby zmienić zakres, zmień 100 na coś innego
      licz(fejk2);
      tblcw[13]='0'+setki;
      tblcw[14]='0'+dziesiatki;
      tblcw[15]='0'+jednosci;
    }
    for(delay=0;delay<120;delay++){
      wynik=fejk+fejk2;
      licz(wynik);
      tblcw[22]='0'+setki;
      tblcw[23]='0'+dziesiatki;
      tblcw[24]='0'+jednosci;
      disptext(tblcw);
    }
  }
}

void licz(int dumb){
  jednosci=dumb%10;
  combo=dumb/10;
  dziesiatki=combo%10;
  setki=combo/10;
}
