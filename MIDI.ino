//----------------------------MIDI-----------------------------------------------------------------

void serialEvent() {
  if (MIDI2.read(midichan)) {
    switch (MIDI2.getType())     // Get the type of the message we caught
    {
      case midi::NoteOn:
        noteByte = MIDI2.getData1();
        // velocityByte = MIDI2.getData2();
        if (generatornumber == 6) {
          generatornumber = 0;
        }
        gorbetime[generatornumber] = 0;
        ptrnullaz(generatornumber);
        wavefreq[generatornumber] = noteertek[noteByte];
        waveveloc[generatornumber]  = MIDI2.getData2();
        oldnoteByte[generatornumber] = noteByte;
        generatornumber++;
        break;
      case midi::NoteOff:
        noteByte = MIDI2.getData1();
        //  velocityByte = MIDI2.getData2();
        if (noteByte == oldnoteByte[0]) {
          gorbetime[0] = maxrelease;
           oldnoteByte[0]=0;
        //   generatornumber=0;
        
        
         
           
        }
        if (noteByte == oldnoteByte[1]) {
          gorbetime[1] = maxrelease;
           oldnoteByte[1]=0;
         //  generatornumber=1;
         
           
         
           
        }
        if (noteByte == oldnoteByte[2]) {
          gorbetime[2] = maxrelease;
          oldnoteByte[2]=0;
        //  generatornumber=2;
          
       
         
          
        }
        if (noteByte == oldnoteByte[3]) {
          gorbetime[3] = maxrelease;
          oldnoteByte[3]=0;
        //  generatornumber=3;
        
         
          
        }
        if (noteByte == oldnoteByte[4]) {
          gorbetime[4] = maxrelease;
          oldnoteByte[4]=0;
       //   generatornumber=4;
         
          
         
          
        }
        if (noteByte == oldnoteByte[5]) {
          gorbetime[5] = maxrelease;
          oldnoteByte[5]=0;
       //   generatornumber=5;
          
      
         
          
        }
         
        /*
          switch (noteByte)
          {
          case  oldnoteByte1: gorbetime[0] = maxrelease; break;
          case  oldnoteByte2: gorbetime[1] = maxrelease; break;
          case  oldnoteByte3: gorbetime[2] = maxrelease; break;
          case  oldnoteByte4: gorbetime[3] = maxrelease; break;
          case  oldnoteByte5: gorbetime[4] = maxrelease; break;
          case  oldnoteByte6: gorbetime[5] = maxrelease; break;
          }
        */
        break;
      case midi:: ProgramChange:
        noteByte = MIDI2.getData1();
        velocityByte = MIDI2.getData2();
        programchange(noteByte);
        break;
      case midi:: AfterTouchPoly:

        break;
      case midi:: ControlChange:
        noteByte = MIDI2.getData1();
        velocityByte = MIDI2.getData2();
        //pichband(44, noteByte);
        parameterchange2(noteByte, velocityByte);
       /*
        Serial.print(noteByte);
        Serial.print(" ");
        Serial.print(velocityByte);
        Serial.print("\n");
        */
        break;
      case midi:: Clock:
        sendmidiclock();
        break;
    }
  }

}

void serialEventUSB() {
  /*   midiEventPacket_t rx;
     /*
    do {
     rx = MidiUSB.read();
     if (rx.header != 0) {
       Serial.print("Received: ");
       Serial.print(rx.header, HEX);
       Serial.print("-");
       Serial.print(rx.byte1, HEX);
       Serial.print("-");
       Serial.print(rx.byte2, HEX);
       Serial.print("-");
       Serial.println(rx.byte3, HEX);
     }
    } while (rx.header != 0);

    /*

    //not tested
    midiEventPacket_t rx;
    rx = MidiUSB.read();

    if (rx.header != 0) {
    switch ( rx.header)     // Get the type of the message we caught
       {
         case 0x09:
           noteByte = rx.byte2;
          // velocityByte = MIDI2.getData2();
           gorbetime[generatornumber] = 0;
           wavefreq[generatornumber] = noteertek[noteByte];
           waveveloc[generatornumber]  = rx.byte3;
           oldnoteByte[generatornumber] = noteByte;
           generatornumber++;
           if (generatornumber == 6) {
             generatornumber = 0;
           }
           break;
         case 0x08:
           noteByte = rx.byte1;
           //  velocityByte = MIDI2.getData2();
           if (noteByte == oldnoteByte[0]) {
             gorbetime[0] = maxrelease0;
           }
           if (noteByte == oldnoteByte[1]) {
             gorbetime[1] = maxrelease1;
           }
           if (noteByte == oldnoteByte[2]) {
             gorbetime[2] = maxrelease2;
           }
           if (noteByte == oldnoteByte[3]) {
             gorbetime[3] = maxrelease3;
           }
           if (noteByte == oldnoteByte[4]) {
             gorbetime[4] = maxrelease4;
           }
           if (noteByte == oldnoteByte[5]) {
             gorbetime[5] = maxrelease5;
           }
       }
    }
  */
}


void pichband( byte value) {
  switch (modulation) {
    case 1:  op1volume = op1volumeorig + value;  break;
    case 2:  op2volume = op2volumeorig + value;  break;
    case 3:  op3volume = op3volumeorig + value;  break;
    case 4:  op4volume = op4volumeorig + value;  break;
    case 5:  op5volume = op5volumeorig + value;  break;
    case 6:  op6volume = op6volumeorig + value;  break;
    case 7:  op1volume = op1volumeorig + value; op2volume = op2volumeorig + value;  break;
    case 8:  op1volume = op1volumeorig + value; op2volume = op2volumeorig - value;  break;
    case 9:  op1volume = op1volumeorig + value; op3volume = op3volumeorig + value;  break;
    case 10: op1volume = op1volumeorig + value; op3volume = op3volumeorig - value;  break;
    case 11: op1volume = op1volumeorig + value; op4volume = op4volumeorig + value;  break;
    case 12: op1volume = op1volumeorig + value; op4volume = op4volumeorig - value;  break;
    case 13: op1volume = op1volumeorig + value; op5volume = op5volumeorig + value;  break;
    case 14: op1volume = op1volumeorig + value; op5volume = op5volumeorig + value;  break;
    case 15: op1volume = op1volumeorig + value; op2volume = op2volumeorig + value; op3volume = op3volumeorig + value; break;
    case 16: op1volume = op1volumeorig + value; op2volume = op2volumeorig - value; op3volume = op3volumeorig + value; break;
    case 17: op2volume = op2volumeorig + value; op4volume = op4volumeorig + value; op6volume = op6volumeorig + value; break;
    case 18: op2volume = op2volumeorig + value; op4volume = op4volumeorig - value; op6volume = op6volumeorig + value; break;
    case 19: op2volume = op2volumeorig + value; op3volume = op3volumeorig + value; op5volume = op5volumeorig + value; break;
    case 20: op2volume = op2volumeorig + value; op3volume = op3volumeorig - value; op5volume = op5volumeorig + value; break;
    case 21: op1generatorfreq = op1generatorfreqorig + value; break;
    case 22: op2generatorfreq = op2generatorfreqorig + value; break;
    case 23: op3generatorfreq = op3generatorfreqorig + value; break;
    case 24: op4generatorfreq = op4generatorfreqorig + value; break;
    case 25: op5generatorfreq = op5generatorfreqorig + value; break;
    case 26: op6generatorfreq = op6generatorfreqorig + value; break;
    case 27: op1generatorfreq = op1generatorfreqorig + value; op2generatorfreq = op2generatorfreqorig + value; break;
    case 28: op1generatorfreq = op1generatorfreqorig + value; op2generatorfreq = op2generatorfreqorig - value; break;
    case 29: op1generatorfreq = op1generatorfreqorig + value; op3generatorfreq = op3generatorfreqorig + value; break;
    case 30: op1generatorfreq = op1generatorfreqorig + value; op3generatorfreq = op3generatorfreqorig - value; break;
    case 31: op1generatorfreq = op1generatorfreqorig + value; op4generatorfreq = op4generatorfreqorig + value; break;
    case 32: op1generatorfreq = op1generatorfreqorig + value; op4generatorfreq = op4generatorfreqorig - value; break;
    case 33: op1generatorfreq = op1generatorfreqorig + value; op4generatorfreq = op4generatorfreqorig + value; op3generatorfreq = op3generatorfreqorig + value; break;
    case 34: op1generatorfreq = op1generatorfreqorig + value; op4generatorfreq = op4generatorfreqorig - value; op3generatorfreq = op3generatorfreqorig + value; break;
      /*

        case 7: op1volume = value; op3volume = value; break;
        case 8: op2volume = value; op4volume = value; break;
        case 9: op3volume = value; op5volume = value; break;
        case 10: op4volume = value; op6volume = value; break;
        case 11: op1volume = value; op5volume = value; break;
        case 12: op3volume = value; op6volume = value; break;
        case 13: op2volume = value; op5volume = value; break;
        case 14: op2volume = value; op6volume = value; break;
        case 15: op1volume = value; op3volume = value; op5volume = value; break;
        case 16: op2volume = value; op4volume = value; op6volume = value; break;
        case 17: op2volume = value; op3volume = value; op5volume = value; break;
        case 18: op2volume = value; op3volume = value; op5volume = value; op6volume = value; break;
        case 19: op1volume = value; op2volume = value; op3volume = value; op4volume = value; op5volume = value; op6volume = value; break;
        case 20: szorzo = value;  break;
      */

      /*
        case 22: op2generatorfreq = value; break;
        case 23: op3generatorfreq = value; break;
        case 24: op4generatorfreq = value; break;
        case 25: op5generatorfreq = value; break;
        case 26: op6generatorfreq = value; break;
        case 27: op1generatorfreq = value; op2generatorfreq = value; break;
        case 28: op1generatorfreq = value; op2generatorfreq = value;  op3generatorfreq = value; break;
        case 29: op1generatorfreq = value;  op4generatorfreq = value; break;
        case 30: op2generatorfreq = value;  op4generatorfreq = value; op6generatorfreq = value; break;
        case 31: op1generatorfreq = value; op2generatorfreq = 127 - value; break;
        case 32:  op1generatorfreq = value; op3generatorfreq = 127 - value; break;
      */
  }
  //hangokinit();
}
/*
  void parameterchange(byte parameter, byte value) {
  switch (parameter) {
    case 0: op1waveform = value; lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart(); break;
    case 1: op2waveform = value; lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart(); break;
    case 2: op3waveform = value; lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart(); break;
    case 3: op4waveform = value; lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart(); break;
    case 4: op1al = value;  lcdkiir(pachname, op1kiir()); op1gorbeinit(); audiorestart(); break;
    case 5: op1ar = value; lcdkiir(pachname, op1kiir()); op1gorbeinit(); audiorestart(); break;
    case 6: op1d1l = value; lcdkiir(pachname, op1kiir()); op1gorbeinit(); audiorestart(); break;
    case 7: op1d1r = value; lcdkiir(pachname, op1kiir()); op1gorbeinit(); audiorestart(); break;
    case 8: op1d2l = value; lcdkiir(pachname, op1kiir()); op1gorbeinit(); audiorestart(); break;
    case 9: op1d2r = value; lcdkiir(pachname, op1kiir()); op1gorbeinit(); audiorestart(); break;
    case 10: op1rl = value; lcdkiir(pachname, op1kiir()); op1gorbeinit(); audiorestart(); break;
    case 11: op1rr = value; lcdkiir(pachname, op1kiir()); op1gorbeinit(); audiorestart(); break;
    case 12: op2al = value; op2gorbeinit(); break;
    case 13: op2ar = value; op2gorbeinit(); break;
    case 14: op2d1l = value; op2gorbeinit(); break;
    case 15: op2d1r = value; op2gorbeinit(); break;
    case 16: op2d2l = value; op2gorbeinit(); break;
    case 17: op2d2r = value; op2gorbeinit(); break;
    case 18: op2rl = value; op2gorbeinit(); break;
    case 19: op2rr = value; op2gorbeinit(); break;
    case 20: op3al = value; op3gorbeinit(); break;
    case 21: op3ar = value; op3gorbeinit(); break;
    case 22: op3d1l = value; op3gorbeinit(); break;
    case 23: op3d1r = value; op3gorbeinit(); break;
    case 24: op3d2l = value; op3gorbeinit(); break;
    case 25: op3d2r = value; op3gorbeinit(); break;
    case 26: op3rl = value; op3gorbeinit(); break;
    case 27: op3rr = value; op3gorbeinit(); break;
    case 28: op4al = value; op4gorbeinit(); break;
    case 29: op4ar = value; op4gorbeinit(); break;
    case 30: op4d1l = value; op4gorbeinit(); break;
    case 31: op4d1r = value; op4gorbeinit(); break;
    case 32: op4d2l = value; op4gorbeinit(); break;
    case 33: op4d2r = value; op4gorbeinit(); break;
    case 34: op4rl = value; op4gorbeinit(); break;
    case 35: op4rr = value; op4gorbeinit(); break;
    case 36: pichkezd = value; pichgorbeinit(); break;
    case 37: pichal = value; pichgorbeinit(); break;
    case 38: pichar = value; pichgorbeinit(); break;
    case 39: pichd1l = value; pichgorbeinit(); break;
    case 40: pichd1r = value; pichgorbeinit(); break;
    case 41: pichd2l = value; pichgorbeinit(); break;
    case 42: pichd2r = value; pichgorbeinit(); break;
    case 43: pichrl = value; pichgorbeinit(); break;
    case 44: pichrr = value; pichgorbeinit(); break;
    case 45: op1volume = value; break;
    case 46: op2volume = value; break;
    case 47: op3volume = value; break;
    case 48: op4volume = value; break;
    case 49: frame = value; break;
    case 50: picheglevel = value * 200; break;
    case 51: fixfreqstep = value * 40; break;
    case 52: modulation = value; break;
    case 53: op1generatorfreq = value; break;
    case 54: op2generatorfreq = value; break;
    case 55: op3generatorfreq = value; break;
    case 56: op4generatorfreq = value;  break;
    case 57: szorzo = value; hangokinit();  break;
    case 58: pichop1 = value; break;
    case 59: pichop2 = value; break;
    case 60: pichop3 = value;  break;
    case 61: pichop4 = value;  break;
    case 62: if (value == 1) {
        notefixedop1 = true;
      } else {
        notefixedop1 = false;
      }
      lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart();
      break;
    case 63: if (value == 1) {
        notefixedop2 = true;
      } else {
        notefixedop2 = false;
      }
      lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart();
      break;
    case 64: if (value == 1) {
        notefixedop3 = true;
      } else {
        notefixedop3 = false;
      }
      lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart();
      break;
    case 65: if (value == 1) {
        notefixedop4 = true;
      } else {
        notefixedop4 = false;
      }
      lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart(); break;
    case 66: if (value == 1) {
        notefixedop5 = true;
      } else {
        notefixedop5 = false;
      }
      lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart();
      break;
    case 67: if (value == 1) {
        notefixedop6 = true;
      } else {
        notefixedop6 = false;
      }
      lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart();
      break;

    case 68: op1generatorfreqfix = value * 40000; break;
    case 69: op2generatorfreqfix = value * 40000; break;
    case 70: op3generatorfreqfix = value * 40000; break;
    case 71: op4generatorfreqfix = value * 40000;  break;
    case 72: pichop5 = value;  break;
    case 73: pichop6 = value;  break;
    case 74: op5generatorfreq = value; break;
    case 75: op6generatorfreq = value;  break;
    case 76: op5volume = value; break;
    case 77: op6volume = value; break;
    case 78: op5al = value; op5gorbeinit(); break;
    case 79: op5ar = value; op5gorbeinit(); break;
    case 80: op5d1l = value; op5gorbeinit(); break;
    case 81: op5d1r = value; op5gorbeinit(); break;
    case 82: op5d2l = value; op5gorbeinit(); break;
    case 83: op5d2r = value; op5gorbeinit(); break;
    case 84: op5rl = value; op5gorbeinit(); break;
    case 85: op5rr = value; op5gorbeinit(); break;
    case 86: op6al = value; op6gorbeinit(); break;
    case 87: op6ar = value; op6gorbeinit(); break;
    case 88: op6d1l = value; op6gorbeinit(); break;
    case 89: op6d1r = value; op6gorbeinit(); break;
    case 90: op6d2l = value; op6gorbeinit(); break;
    case 91: op6d2r = value; op6gorbeinit(); break;
    case 92: op6rl = value; op6gorbeinit(); break;
    case 93: op6rr = value; op6gorbeinit(); break;
    case 94: op5waveform = value; lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart(); break;
    case 95: op6waveform = value; lcdkiir(pachname, generatorkiir()); generatorinit(op1waveform, op2waveform, op3waveform, op4waveform, op5waveform, op6waveform); audiorestart(); break;
    case 96: op5generatorfreqfix = value * 40000; break;
    case 97: op6generatorfreqfix = value * 40000;  break;
    case 98: op5volume = value; break;
    case 99: op6volume = value; break;
    case 100: op1veloc = value; break;
    case 101: op2veloc = value; break;
    case 102: op3veloc = value; break;
    case 103: op4veloc = value; break;
    case 104: op5veloc = value; break;
    case 105: op6veloc = value; break;
    case 106: if (value == 1) {
        pachname = "";
      } else {
        char myChar = value;
        pachname += myChar;


      }
      lcdkiir(pachname, generatorkiir());
      audiorestart();
      break;
    case 107: reverbtime = value * 26; break;
    case 108: reverblevel = value; break;
    case 109: level = value; break;
    case 110: volume = value * 9; break;
    case 111: alg = value; break;
    case 112: revalg = value; break;
    case 113: choruslevel = value; break;
    case 114: chorusalg = value; break;
    case 115: chorustime = value; break;
    case 116:  break;
    case 117: break;
    //    case 118: oplfo = value; break;
    case 119: oplfo2max = value; break;
    case 120: oplfo4max = value; break;
    case 121: oplfo6max = value; break;
    case 122: lfo2freq = value; break;
    case 123: freq1 = value * 100;  break;
    case 124: freq2 = value * 100;  break;
    case 125: break;
    case 126:
      if (value == 1) {
        sendparameter();
      }
      break;
    case 127: break;
      //MIDI!!!
  }
  }
*/
//----------------------------------------------------------------------
//X-Novation Xstation 25 Controller
//----------------------------------------------------------------------
/*
  MIDI Command Novation X-Station 25
  B0-6C Attack Dec: 108
  B0-6D Decay Dec:109
  B0-6E Sustain Dec: 110
  B0-6F Release Dec: 111
  B0-72 Attack2  Dec: 114
  B0-73 Decay2   Dec: 115
  B0-74 Sustain2 Dec: 116
  B0-75 Release2 Dec: 117
  B0-70 Velocity Dec: 112
  B0-05 Portamento Dec: 05
  B0-28 Semitone Dec: 40
  B0-29 Detune Dec: 29
  B0-48 Level Dec: 72
  B0-2B LFO Depth Dec: 43
  B0-2c Env Depth Dec: 44
  B0-2D PWM Dec: 45
  B0-69 Frequency Dec: 105
  B0-6A Resonance Dec: 106
  B0-6b ENV Depth Dec: 107
  B0-xx Key track:  006
  B0-66 LFO Depth Dec: 102
  B0-68 Overdrive Dec: 104
  B0-50 Speed Dec: 80
  B0-52 Delay Amount LFO Dec: 82
  B0-09 Tempo Dec: 09
  B0-07 Effect Level Dec: 07



*/
void parameterchange2(byte parameter, byte value) {
  switch (parameter) {
    case 0:
      switch (opmenuoldal) {
        case 1: op1generatorfreqfix = value << 15; break;
        case 2: op2generatorfreqfix = value << 15; break;
        case 3: op3generatorfreqfix = value << 15; break;
        case 4: op4generatorfreqfix = value << 15; break;
        case 5: op5generatorfreqfix = value << 15; break;
        case 6: op6generatorfreqfix = value << 15; break;
      }
      menuoldal = 15;
      menukiir();
      break;

    case 5:
      switch (opmenuoldal) {
        case 1: op1volumeorig = value;  break;
        case 2: op2volumeorig = value; break;
        case 3: op3volumeorig = value; break;
        case 4: op4volumeorig = value; break;
        case 5: op5volumeorig = value; break;
        case 6: op6volumeorig = value; break;
      }
      menuoldal = 11;
      menukiir();
      break;
    case 6:
      if (value < 17) {
        switch (opmenuoldal)
        {
          case 1: op1waveform = value; generatorinitone(op1waveform, generator1); break;
          case 2: op2waveform = value; generatorinitone(op2waveform, generator2); break;
          case 3: op3waveform = value; generatorinitone(op3waveform, generator3); break;
          case 4: op4waveform = value; generatorinitone(op4waveform, generator4); break;
          case 5: op5waveform = value; generatorinitone(op5waveform, generator5); break;
          case 6: op6waveform = value; generatorinitone(op6waveform, generator6); break;
        }
        menuoldal = 14;
      }
      else
      {
        if (value == 28)
        {
          switch (opmenuoldal)
          {
            case 1: notefixedop1 = true; break;
            case 2: notefixedop2 = true; break;
            case 3: notefixedop3 = true; break;
            case 4: notefixedop4 = true; break;
            case 5: notefixedop5 = true; break;
            case 6: notefixedop6 = true; break;
          }
          menuoldal = 13;
        }
        if (value == 29)
        {
          switch (opmenuoldal)
          {
            case 1: notefixedop1 = false; break;
            case 2: notefixedop2 = false; break;
            case 3: notefixedop3 = false; break;
            case 4: notefixedop4 = false; break;
            case 5: notefixedop5 = false; break;
            case 6: notefixedop6 = false; break;
          }
          menuoldal = 13;
        }
        if (value == 32)
        {
          switch (opmenuoldal)
          {
            case 1: pichop1 = 1;  break;
            case 2: pichop2 = 1; break;
            case 3: pichop3 = 1; break;
            case 4: pichop4 = 1; break;
            case 5: pichop5 = 1; break;
            case 6: pichop6 = 1; break;
          }
         // menuoldal = 13;
        }
        if (value == 33)
        {
          switch (opmenuoldal)
          {
            case 1: pichop1 = 2; break;
            case 2: pichop2 = 2; break;
            case 3: pichop3 = 2; break;
            case 4: pichop4 = 2; break;
            case 5: pichop5 = 2; break;
            case 6: pichop6 = 2; break;
          }
          //menuoldal = 13;
        }
        



        
        if (value == 52)
        {
          if (opmenuoldal < 7)
          {
            opmenuoldal++;
          } else
          {
            opmenuoldal = 1;
          }
        }

      }
      menukiir();
      break;
    case 7:
      reverblevel = value;
      menuoldal = 33;
      menukiir();
      break;
    case  9:
      choruslevel = value;
      menuoldal = 34;
      menukiir();
      break;
    case 25:


      break;
    case 35:
      //button rew
      break;
    case 36:
      //button forward
      break;
    case 37:
      //button stop
      //free( buffer);
      fagy = false;
      /*for (int i = 0; i < buffermeret; i++) {
        buffer[i] = 0;
        }
        bufferindex=0;
        delaybufferindex=0;
        //Audio.end();
      */
      break;
    case 38:
      //button play
      // bufferindex = 0;
      // szamlalo = 0;
      //gorbetime[0] = -1;
      // gorbetime[1] = -1;
      //gorbetime[2] = -1;
      //gorbetime[3] = -1;
      // gorbetime[4] = -1;
      // gorbetime[5] = -1;
      //Audio.begin(mintavetelifreqstereo, buffermeret);
      fagy = true;
      break;
    case 39:
      //button rec
      break;
    case 40:
      alg = (value - 56) % 6 + 1;
      alg2 = (value - 56) / 6 + 1;
      menuoldal = 18;
      menukiir();
      break;
    case 41:
      szorzo = value;
      menuoldal = 17;
      menukiir();
      break;
    case 43:
      released = value / 8;
      menuoldal = 39;
      menukiir();
      break;
    case 44:
      switch (opmenuoldal) {
        case 1: op1generatorfreqorig = value;  break;
        case 2: op2generatorfreqorig = value; break;
        case 3: op3generatorfreqorig = value; break;
        case 4: op4generatorfreqorig = value; break;
        case 5: op5generatorfreqorig = value; break;
        case 6: op6generatorfreqorig = value; break;
      }
      menuoldal = 12;
      menukiir();
      break;
    case 45:
      gorbeszorzo = value / 2 + 1;
      menuoldal = 38;
      menukiir();
      break;
    case 72:
      level = value / 2;
      menuoldal = 19;
      menukiir();
      break;
    case 80:
      feedback_level = value/4-16;
      menuoldal = 16;
      menukiir();
      break;
    case 82:
      switch (opmenuoldal) {
        case 1: lep1 = value / 8 + 13; break;
        case 2:  lep2 = value / 8 + 13; break;
        case 3: lep3 = value / 8 + 13; break;
        case 4:  lep4 = value / 8 + 13; break;
        case 5:  lep5 = value / 8 + 13; break;
        case 6:  lep6 = value / 8 + 13; break;
      }
      menuoldal = 41;
      menukiir();
      break;
    case 102:
      modulation = value / 4;
      menuoldal = 40;
      menukiir();
      break;
    case 104:
      lfo2freq = value;
      menuoldal = 37;
      menukiir();
      break;
    case 105:
      eqvalue = value * 96;
      menuoldal = 32;
      menukiir();
      break;
    case 106:
      picheglevel = value * 4096;
      menuoldal = 21;
      menukiir();
      break;
    case 107:
      lfo2volume = value / 4;
      menuoldal = 39;
      menukiir();
      break;
    case 108:
      switch (opmenuoldal) {
        case 1: op1al = value; break;
        case 2: op2al = value; break;
        case 3: op3al = value; break;
        case 4: op4al = value; break;
        case 5: op5al = value; break;
        case 6: op6al = value; break;
        case 7: pichal = value; break;

      }
      menuoldal = 2;
      opgorbeinittry();
      break;
    case 109:
      switch (opmenuoldal) {
        case 1: op1d1l = value;  break;
        case 2: op2d1l = value; break;
        case 3: op3d1l = value;  break;
        case 4: op4d1l = value;  break;
        case 5: op5d1l = value;  break;
        case 6: op6d1l = value; break;
        case 7: pichd1l = value; break;
      }
      menuoldal = 4;
      opgorbeinittry();
      break;
    case 110:
      switch (opmenuoldal) {
        case 1: op1d2l = value; break;
        case 2: op2d2l = value; break;
        case 3: op3d2l = value; break;
        case 4: op4d2l = value; break;
        case 5: op5d2l = value; break;
        case 6: op6d2l = value; break;
        case 7: pichd2l = value; break;
      }
      menuoldal = 6;
      opgorbeinittry();
      break;
    case 111:
      switch (opmenuoldal) {
        case 1: op1rl = value; break;
        case 2: op2rl = value; break;
        case 3: op3rl = value; break;
        case 4: op4rl = value; break;
        case 5: op5rl = value; break;
        case 6: op6rl = value; break;
        case 7: pichrl = value; break;
      }
      menuoldal = 8;
      opgorbeinittry();
      break;
    case 112:
      switch (opmenuoldal) {
        case 1: op1veloc = value>>2+1; menuoldal = 10; break;
        case 2: op2veloc = value>>2+1; menuoldal = 10; break;
        case 3: op3veloc = value>>2+1; menuoldal = 10; break;
        case 4: op4veloc = value>>2+1; menuoldal = 10; break;
        case 5: op5veloc = value>>2+1; menuoldal = 10; break;
        case 6: op6veloc = value>>2+1; menuoldal = 10; break;
        case 7: pichkezd = value;  menuoldal = 20; break;
      }
      menukiir();
      break;
    case 114:
      switch (opmenuoldal) {
        case 1: op1ar = value * 4; break;
        case 2: op2ar = value * 4; break;
        case 3: op3ar = value * 4; break;
        case 4: op4ar = value * 4; break;
        case 5: op5ar = value * 4; break;
        case 6: op6ar = value * 4; break;
        case 7: pichar = value * 4; break;
      }
      menuoldal = 3;
      opgorbeinittry();
      break;
    case 115:
      switch (opmenuoldal) {
        case 1: op1d1r = value * 4; break;
        case 2: op2d1r = value * 4; break;
        case 3: op3d1r = value * 4; break;
        case 4: op4d1r = value * 4; break;
        case 5: op5d1r = value * 4; break;
        case 6: op6d1r = value * 4; break;
        case 7: pichd1r = value * 4; break;
      }
      menuoldal = 5;
      opgorbeinittry();
      break;
    case 116:
      switch (opmenuoldal) {
        case 1: op1d2r = value * 4; break;
        case 2: op2d2r = value * 4; break;
        case 3: op3d2r = value * 4; break;
        case 4: op4d2r = value * 4; break;
        case 5: op5d2r = value * 4; break;
        case 6: op6d2r = value * 4; break;
        case 7: pichd2r = value * 4; break;
      }
      menuoldal = 7;
      opgorbeinittry();
      break;
    case 117:
      switch (opmenuoldal) {
        case 1:  op1rr = value * 4; break;
        case 2:  op2rr = value * 4; break;
        case 3: op3rr = value * 4; break;
        case 4:  op4rr = value * 4; break;
        case 5:  op5rr = value * 4; break;
        case 6: op6rr = value * 4; break;
        case 7: pichrr = value * 4; break;
      }
      menuoldal = 9;
      opgorbeinittry();
      break;
    case 126:
      if (value == 1) {
        sendparameter();
      }
      break;
    case 127: break;

  }
}

void opgorbeinittry() {
  if (ido - elozoinit > 1000) {
    switch (opmenuoldal) {
      case 1: op1gorbeinit(); break;
      case 2: op2gorbeinit(); break;
      case 3: op3gorbeinit(); break;
      case 4: op4gorbeinit(); break;
      case 5: op5gorbeinit(); break;
      case 6: op6gorbeinit(); break;
      case 7: pichgorbeinit(); break;
    }
    maxreleaseset();
    menukiir();
    elozoinit = ido;

  }
}

void sendmidiclock() {
  /*
    byte midi_clock = 0xf8; //Declare the hex value of a midi clock message
    byte midi_start = 0xfa; //Declare the hex value of a midi clock start message
    byte midi_stop = 0xfc; //Declare the hex value of a midi clock stop message

  */


  Serial2.write(0xF8);
}


void sendparameter() {
  // lcdkiir("mukodj!", "JEE!");
  MIDI2.sendPolyPressure (0, op1waveform, 1);
  MIDI2.sendPolyPressure (1, op2waveform, 1);
  MIDI2.sendPolyPressure (2, op3waveform, 1);
  MIDI2.sendPolyPressure (3, op4waveform, 1);
  MIDI2.sendPolyPressure (4, op1al, 1);
  MIDI2.sendPolyPressure (5, op1ar, 1);
  MIDI2.sendPolyPressure (6, op1d1l, 1);
  MIDI2.sendPolyPressure (7, op1d1r, 1);
  MIDI2.sendPolyPressure (8, op1d2l, 1);
  MIDI2.sendPolyPressure (9, op1d2r, 1);
  MIDI2.sendPolyPressure (10, op1rl, 1);
  MIDI2.sendPolyPressure (11, op1rr, 1);
  MIDI2.sendPolyPressure (12, op2al, 1);
  MIDI2.sendPolyPressure (13, op2ar, 1);
  MIDI2.sendPolyPressure (14, op2d1l, 1);
  MIDI2.sendPolyPressure (15, op2d1r, 1);
  MIDI2.sendPolyPressure (16, op2d2l, 1);
  MIDI2.sendPolyPressure (17, op2d2r, 1);
  MIDI2.sendPolyPressure (18, op2rl, 1);
  MIDI2.sendPolyPressure (19, op2rr, 1);
  MIDI2.sendPolyPressure (20, op3al, 1);
  MIDI2.sendPolyPressure (21, op3ar, 1);
  MIDI2.sendPolyPressure (22, op3d1l, 1);
  MIDI2.sendPolyPressure (23, op3d1r, 1);
  MIDI2.sendPolyPressure (24, op3d2l, 1);
  MIDI2.sendPolyPressure (25, op3d2r, 1);
  MIDI2.sendPolyPressure (26, op3rl, 1);
  MIDI2.sendPolyPressure (27, op3rr, 1);
  MIDI2.sendPolyPressure (28, op4al, 1);
  MIDI2.sendPolyPressure (29, op4ar, 1);
  MIDI2.sendPolyPressure (30, op4d1l, 1);
  MIDI2.sendPolyPressure (31, op4d1r, 1);
  MIDI2.sendPolyPressure (32, op4d2l, 1);
  MIDI2.sendPolyPressure (33, op4d2r, 1);
  MIDI2.sendPolyPressure (34, op4rl, 1);
  MIDI2.sendPolyPressure (35, op4rr, 1);
  MIDI2.sendPolyPressure (36, pichkezd, 1);
  MIDI2.sendPolyPressure (37, pichal, 1);
  MIDI2.sendPolyPressure (38, pichar, 1);
  MIDI2.sendPolyPressure (39, pichd1l, 1);
  MIDI2.sendPolyPressure (40, pichd1r, 1);
  MIDI2.sendPolyPressure (41, pichd2l, 1);
  MIDI2.sendPolyPressure (42, pichd2r, 1);
  MIDI2.sendPolyPressure (43, pichrl, 1);
  MIDI2.sendPolyPressure (44, pichrr, 1);
  MIDI2.sendPolyPressure (45, op1volume, 1);
  MIDI2.sendPolyPressure (46, op2volume, 1);
  MIDI2.sendPolyPressure (47, op3volume, 1);
  MIDI2.sendPolyPressure (48, op4volume, 1);
  MIDI2.sendPolyPressure (49, frame, 1);
  MIDI2.sendPolyPressure (50, picheglevel / 200, 1);
  MIDI2.sendPolyPressure (51, fixfreqstep / 40, 1);
  MIDI2.sendPolyPressure (52, 0, 1);
  MIDI2.sendPolyPressure (53, op1generatorfreq, 1);
  MIDI2.sendPolyPressure (54, op2generatorfreq, 1);
  MIDI2.sendPolyPressure (55, op3generatorfreq, 1);
  MIDI2.sendPolyPressure (56, op4generatorfreq, 1);
  MIDI2.sendPolyPressure (57, szorzo, 1);
  MIDI2.sendPolyPressure (58, pichop1, 1);
  MIDI2.sendPolyPressure (59, pichop2, 1);
  MIDI2.sendPolyPressure (60, pichop3, 1);
  MIDI2.sendPolyPressure (61, pichop4, 1);
  if (notefixedop1) {
    MIDI2.sendPolyPressure (62, 1, 1);
  } else {
    MIDI2.sendPolyPressure (62, 0, 1);
  }
  if (notefixedop2) {
    MIDI2.sendPolyPressure (63, 1, 1);
  } else {
    MIDI2.sendPolyPressure (63, 0, 1);
  }
  if (notefixedop3) {
    MIDI2.sendPolyPressure (64, 1, 1);
  } else {
    MIDI2.sendPolyPressure (64, 0, 1);
  }
  if (notefixedop4) {
    MIDI2.sendPolyPressure (65, 1, 1);
  } else {
    MIDI2.sendPolyPressure (65, 0, 1);
  }
  if (notefixedop5) {
    MIDI2.sendPolyPressure (66, 1, 1);
  } else {
    MIDI2.sendPolyPressure (66, 0, 1);
  }
  if (notefixedop6) {
    MIDI2.sendPolyPressure (67, 1, 1);
  } else {
    MIDI2.sendPolyPressure (67, 0, 1);
  }
  MIDI2.sendPolyPressure (68, op1generatorfreqfix / 40000, 1);
  MIDI2.sendPolyPressure (69, op2generatorfreqfix / 40000, 1);
  MIDI2.sendPolyPressure (70, op3generatorfreqfix / 40000, 1);
  MIDI2.sendPolyPressure (71, op4generatorfreqfix / 40000, 1);
  MIDI2.sendPolyPressure (72, pichop5, 1);
  MIDI2.sendPolyPressure (73, pichop6, 1);
  MIDI2.sendPolyPressure (74, op5generatorfreq, 1);
  MIDI2.sendPolyPressure (75, op6generatorfreq, 1);
  MIDI2.sendPolyPressure (76, op5volume, 1);
  MIDI2.sendPolyPressure (77, op6volume, 1);
  MIDI2.sendPolyPressure (78,  op5al, 1);
  MIDI2.sendPolyPressure (79,  op5ar, 1);
  MIDI2.sendPolyPressure (80, op5d1l, 1);
  MIDI2.sendPolyPressure (81, op5d1r, 1);
  MIDI2.sendPolyPressure (82, op5d2l, 1);
  MIDI2.sendPolyPressure (83, op5d2r, 1);
  MIDI2.sendPolyPressure (84, op5rl, 1);
  MIDI2.sendPolyPressure (85, op5rr, 1);
  MIDI2.sendPolyPressure (86,  op6al, 1);
  MIDI2.sendPolyPressure (87,  op6ar, 1);
  MIDI2.sendPolyPressure (88, op6d1l, 1);
  MIDI2.sendPolyPressure (89, op6d1r, 1);
  MIDI2.sendPolyPressure (90, op6d2l, 1);
  MIDI2.sendPolyPressure (91, op6d2r, 1);
  MIDI2.sendPolyPressure (92, op6rl, 1);
  MIDI2.sendPolyPressure (93, op6rr, 1);
  MIDI2.sendPolyPressure (94, op5waveform, 1);
  MIDI2.sendPolyPressure (95, op6waveform, 1);
  MIDI2.sendPolyPressure (96,  op5generatorfreqfix / 40000, 1);
  MIDI2.sendPolyPressure (97,  op6generatorfreqfix / 40000, 1);
  MIDI2.sendPolyPressure (98, op5volume, 1);
  MIDI2.sendPolyPressure (99, op6volume, 1);
  MIDI2.sendPolyPressure (100, op1veloc, 1);
  MIDI2.sendPolyPressure (101, op2veloc, 1);
  MIDI2.sendPolyPressure (102, op3veloc, 1);
  MIDI2.sendPolyPressure (103, op4veloc, 1);
  MIDI2.sendPolyPressure (104, op5veloc, 1);
  MIDI2.sendPolyPressure (105, op6veloc, 1);
  MIDI2.sendPolyPressure (107,  reverbtime, 1);
  MIDI2.sendPolyPressure (108, reverblevel, 1);
  MIDI2.sendPolyPressure (109, level, 1);
  MIDI2.sendPolyPressure (110, volume / 9, 1);
  MIDI2.sendPolyPressure (111, alg, 1);
  MIDI2.sendPolyPressure (112, revalg, 1);
  MIDI2.sendPolyPressure (113, choruslevel, 1);
  MIDI2.sendPolyPressure (114, chorusalg, 1);
  MIDI2.sendPolyPressure (115, chorustime / 26, 1);
  MIDI2.sendPolyPressure (116, 0, 1);
  MIDI2.sendPolyPressure (117, 0, 1);
  //  MIDI2.sendPolyPressure (118, oplfo, 1);
  MIDI2.sendPolyPressure (119, oplfo2max, 1);
  MIDI2.sendPolyPressure (120, oplfo4max, 1);
  MIDI2.sendPolyPressure (121, oplfo6max, 1);
  MIDI2.sendPolyPressure (122, lfo2freq, 1);
  MIDI2.sendPolyPressure (123, freq1 / 100, 1);
  MIDI2.sendPolyPressure (124, freq2 / 100, 1);
  MIDI2.sendPolyPressure (125, 0, 1);
  MIDI2.sendPolyPressure (126, 0, 1);
  MIDI2.sendPolyPressure (127, 0, 1);
  //lcdkiir("Transmite","ok" ) ;
}

void programchange(byte program) {
  // Audio.end();
  if (program < 11) {
    switch (program) {
      case 0:
        program0();
        break;
      case 1:
        program1();
        break;
      case 2:
        program2();
        break;
      case 3:
        program3();
        break;
      case 4:
        program4();
        break;
      case 5:
        program5();
        break;
      case 6:
        program6();
        break;
      case 7:
        program7();
        break;
      case 8:
        program8();
        break;
      case 9:
        program9();
        break;
      case 10:
        program10();
        break;
    }
  } else {
    if (program < 20) {
      byte loadprog = program - 11;
      load(loadprog);
      stepprogchanged = 1;
      pachname = "         ";
      lcdkiir( String(lcdprint3(program)) + pachname, "User Preset");
    }
  }
  /*
    for (int i = 0; i < 6; i++) {
      gorbetime[i] = -1;
    }
    bufferindex = 0;
    delaybufferindex = 0;
  */
  // Audio.begin(mintavetelifreqstereo, buffermeret);
}

void initprog() {
  //slow program cahanged !!!! default set lcd refresh (stepprogchanged=45)
  switch (stepprogchanged) {
    case 1:  generatorinitone(op1waveform, generator1); stepprogchanged++; break;
    case 2:  stepprogchanged++; break;
    case 3:  generatorinitone(op2waveform, generator2); stepprogchanged++; break;
    case 4:  stepprogchanged++; break;
    case 5:  generatorinitone(op3waveform, generator3); stepprogchanged++; break;
    case 6:  stepprogchanged++; break;
    case 7:  generatorinitone(op4waveform, generator4); stepprogchanged++; break;
    case 8:  stepprogchanged++; break;
    case 9:  generatorinitone(op5waveform, generator5); stepprogchanged++; break;
    case 10: stepprogchanged++; break;
    case 11: generatorinitone(op6waveform, generator6); stepprogchanged++; break;
    case 12: stepprogchanged++; break;
    case 13: pichgorbeinit(); stepprogchanged++; break;
    case 14: stepprogchanged++; break;
    case 15: hangokinit(); stepprogchanged++; break;
    case 16: stepprogchanged++; break;
    case 17: op1gorbeinit(); stepprogchanged++; break;
    case 18: stepprogchanged++; break;
    case 19: op2gorbeinit(); stepprogchanged++; break;
    case 20: stepprogchanged++; break;
    case 21: op3gorbeinit(); stepprogchanged++; break;
    case 22: stepprogchanged++; break;
    case 23: stepprogchanged++; break;
    case 24: stepprogchanged++; break;
    case 25: op4gorbeinit(); stepprogchanged++; break;
    case 26: stepprogchanged++; break;
    case 27: stepprogchanged++; break;
    case 28: stepprogchanged++; break;
    case 29: op5gorbeinit(); stepprogchanged++; break;
    case 30: stepprogchanged++; break;
    case 31: stepprogchanged++; break;
    case 32: stepprogchanged++; break;
    case 33: op6gorbeinit(); stepprogchanged++; break;
    case 34: stepprogchanged++; break;
    case 35: stepprogchanged++; break;
    case 36: stepprogchanged++; break;
    case 37: stepprogchanged++; break;
    case 38: stepprogchanged++; break;
    case 39: stepprogchanged++; break;
    case 40: stepprogchanged++; break;
    case 41: maxreleaseset(); stepprogchanged++; break;
    case 42: stepprogchanged++; break;
    case 43: stepprogchanged++; break;
    case 44: stepprogchanged++; break;
    case 45: lcdrefreesh(); break;


      Audio.begin(mintavetelifreqstereo, buffermeret);

  }
}
