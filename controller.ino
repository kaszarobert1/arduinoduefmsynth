bool elozogomb1val = true;
bool elozogomb2val = true;
bool elozogomb3val = true;
bool elozogomb4val = true;
bool elozogomb5val = true;
bool elozogomb6val = true;
bool elozogomb7val = true;
bool elozogomb8val = true;


void vezerlok() {
  //potik sorrendje: 4 3 2 1 5
  volume = analogRead(analogPin0) << 4; 
  lfofreq = analogRead(analogPin2) >> 6;
  // op1generatorfreq = analogRead(analogPin1);
 // pichband( 0, analogRead(analogPin1)>>7);
  //gorbeszorzo = analogRead(analogPin3) >> 7;
  eqvalue = analogRead(analogPin4) * 12;
  reverblevel = analogRead(analogPin3) >>3;
  reverblevel2 = analogRead(analogPin5) >>3;
  freq1 = (eqvalue / 123) * 100;
  freq2 = (127 - eqvalue / 99) * 100;

  
    // controller-ben digitalRead(gomb1);gyorsítása:
    // Be olvassa a GPIO regisztert és kimaskolja a megfelelő bitet
    uint8_t  gomb1val = ((uint32_t)PIOB->PIO_PDSR & 1u << 25)>> 25  ;// D2 = B.25
    uint32_t  PioC = PIOC->PIO_PDSR ;
    uint8_t  gomb2val = (PioC & 1u << 28)>> 28  ;// D3 = C.28
    uint8_t  gomb3val = (PioC & 1u << 26)>> 26  ;// D4 = C.26
    uint8_t  gomb4val = (PioC & 1u << 25)>> 25  ;// D5 = C.25
    uint8_t  gomb5val = (PioC & 1u << 24)>> 24  ;// D6 = C.24
    uint8_t  gomb6val = (PioC & 1u << 23)>> 23  ;// D7 = C.23
    uint8_t  gomb7val = (PioC & 1u << 22)>> 22  ;// D8 = C.22
    uint8_t  gomb8val = (PioC & 1u << 21)>> 21  ;// D9 = C.21
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
      if (menuoldal < 41)
      {
        menuoldal++;
      } else {
        menuoldal = 1;
      }
      menukiir();
    }

    elozogomb1val = gomb1val;
  }

  //menule
  if (elozogomb2val != gomb2val) {
    if (gomb2val == false) {
      if (menuoldal > 1)
      {
        menuoldal--;
      } else {
        menuoldal = 41;
      }
      menukiir();
    }
    elozogomb2val = gomb2val;
  }

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
