bool elozogomb1val = true;
bool elozogomb2val = true;
bool elozogomb3val = true;
bool elozogomb4val = true;
bool elozogomb5val = true;
bool elozogomb6val = true;
bool elozogomb7val = true;
bool elozogomb8val = true;
uint8_t  gomb1val;
uint8_t  gomb2val;
uint8_t  gomb3val;
uint8_t  gomb4val;
uint8_t  gomb5val;
uint8_t  gomb6val;
uint8_t  gomb7val;
uint8_t  gomb8val;
uint32_t  PioC;
bool hangon=false;
void vezerlok() {
 //potik sorrendje: 4 3 2 1 5
 //int hang=analogRead(10);
 // volume = analogRead(analogPin0) << 4; 
 // lfo2freq = analogRead(analogPin2) >> 5; 
 //  chorusfreq = analogRead(analogPin1)>>5;
 // op1generatorfreq = analogRead(analogPin1);
 // pichband( 0, analogRead(analogPin1)>>7);
 //gorbeszorzo = analogRead(analogPin3) >> 7;  
 // eqvalue = analogRead(analogPin4) * 12;
 // reverblevel = analogRead(analogPin3) >>3;
 // reverblevel2 = analogRead(analogPin5) >>3;
 // freq1 = (eqvalue / 123) * 100;
 // freq2 = (127 - eqvalue / 99) * 100;     
   
  // controller-ben digitalRead(gomb1);gyorsítása:
   // Be olvassa a GPIO regisztert és kimaskolja a megfelelő bitet
    gomb1val = ((uint32_t)PIOB->PIO_PDSR & 1u << 25)>> 25  ;// D2 = B.25
    PioC = PIOC->PIO_PDSR ;
    gomb2val = (PioC & 1u << 28)>> 28  ;// D3 = C.28
    gomb3val = (PioC & 1u << 26)>> 26  ;// D4 = C.26
    gomb4val = (PioC & 1u << 25)>> 25  ;// D5 = C.25
    gomb5val = (PioC & 1u << 24)>> 24  ;// D6 = C.24
    gomb6val = (PioC & 1u << 23)>> 23  ;// D7 = C.23
    gomb7val = (PioC & 1u << 22)>> 22  ;// D8 = C.22
    gomb8val = (PioC & 1u << 21)>> 21  ;// D9 = C.21
    // A kapott értéket eltoljuk jobb szélre bit.0-ba
/*
    int gomb1val = digitalRead(gomb1);
    int gomb2val = digitalRead(gomb2);
    int gomb3val = digitalRead(gomb3);
    int gomb4val = digitalRead(gomb4);
    int gomb5val = digitalRead(gomb6);
    int gomb6val = digitalRead(gomb5);
    int gomb7val = digitalRead(gomb7);
    int gomb8val = digitalRead(gomb8);
*/
  
  //menufel
  if (elozogomb1val != gomb1val) {
    if (gomb1val == false) {
      if (menuoldal < 50)
      {
        menuoldal++;
      } else {
        menuoldal = 1;
      }
      menukiir();
    }
    elozogomb1val = gomb1val;
  }


  //key
  if (elozogomb2val != gomb2val) {
    if (gomb2val == false) {
      keyon(64);
    }
    if (gomb2val == true) {
     keyoff(64);      
      }
     elozogomb2val = gomb2val;  
  }



  

/*
  //menule
  if (elozogomb2val != gomb2val) {
    if (gomb2val == false) {
      if (menuoldal > 1)
      {
        menuoldal--;
      } else {
        menuoldal = 50;
      }
      menukiir();
    }
    elozogomb2val = gomb2val;
  }
*/

 //key
  if (elozogomb3val != gomb3val) {
    if (gomb3val == false) {
      keyon(65);
    }
    if (gomb3val == true) {
     keyoff(65);      
      }
     elozogomb3val = gomb3val;  
  }

/*
  //programfel
  if (elozogomb3val != gomb3val) {
    if (gomb3val == false) {
      if (program < 10)
      {
        program++;
        programchange(program);
      } else {
        program = 0;
        programchange(program);
      }
    }
    elozogomb3val = gomb3val;
  }
  */

  //programle
  if (elozogomb4val != gomb4val) {
    if (gomb4val == false) {
      if (program > 0)
      {
        program--;
        programchange(program);
      } else {
        program = 10;
        programchange(program);
      }
    }
    elozogomb4val = gomb4val;
  }


 //key
  if (elozogomb5val != gomb5val) {
    if (gomb5val == false) {
      keyon(67);
    }
    if (gomb5val == true) {
     keyoff(67);      
      }
     elozogomb5val = gomb5val;  
  }
/*
  //incrementvalue
  if (elozogomb5val != gomb5val) {
    if (gomb5val == false) {

      if (inc == false)
      {
        inc = true;
        menukiir();
      }

    }
    elozogomb5val = gomb5val;
  }

  */
  //decrementvalue
  if (elozogomb6val != gomb6val) {
    if (gomb6val == false) {

      if (dec == false)
      {
        dec = true;
        menukiir();
      }

    }
    elozogomb6val = gomb6val;
  }



 //key
  if (elozogomb7val != gomb7val) {
    if (gomb7val == false) {
      keyon(69);
    }
    if (gomb7val == true) {
     keyoff(69);      
      }
     elozogomb7val = gomb7val;  
  }

/*
  //opmenufel
  if (elozogomb7val != gomb7val) {
    if (gomb7val == false) {
      if (opmenuoldal < 7)
      {
        opmenuoldal++;
      } else {
        opmenuoldal = 1;
      }
      menukiir();
    }
    elozogomb7val = gomb7val;
  }
*/


  //opmenule
  if (elozogomb8val != gomb8val) {
    if (gomb8val == false) {
      if (opmenuoldal > 1)
      {
        opmenuoldal--;
      } else {
        opmenuoldal = 7;
      }
      menukiir();
    }
    elozogomb8val = gomb8val;
  }
  
}


void keyon(byte noteByte){
   // velocityByte = MIDI2.getData2();
        if (generatornumber == 6) {
          generatornumber = 0;
        }
        gorbetime[generatornumber] = 0;
        ptrnullaz();
        wavefreq[generatornumber] = noteertek[noteByte];
        waveveloc[generatornumber]  = 127;
        oldnoteByte[generatornumber] = noteByte;
        generatornumber++;
  }

  void keyoff(byte noteByte){
    
     if (noteByte == oldnoteByte[0]) {
          gorbetime[0] = maxrelease;
          oldnoteByte[0] = 0;
          //   generatornumber=0;
        }
        if (noteByte == oldnoteByte[1]) {
          gorbetime[1] = maxrelease;
          oldnoteByte[1] = 0;
          //  generatornumber=1;
        }
        if (noteByte == oldnoteByte[2]) {
          gorbetime[2] = maxrelease;
          oldnoteByte[2] = 0;
          //  generatornumber=2;
        }
        if (noteByte == oldnoteByte[3]) {
          gorbetime[3] = maxrelease;
          oldnoteByte[3] = 0;
          //  generatornumber=3;
        }
        if (noteByte == oldnoteByte[4]) {
          gorbetime[4] = maxrelease;
          oldnoteByte[4] = 0;
          //   generatornumber=4;
        }
        if (noteByte == oldnoteByte[5]) {
          gorbetime[5] = maxrelease;
          oldnoteByte[5] = 0;
          //   generatornumber=5;
        }
        
    
    }
