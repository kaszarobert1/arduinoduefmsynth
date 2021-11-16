//------------------------LCD------------------------------------

String savestring = "NO";
byte saveprog = 0;
byte menu = 1;
byte oldal = 0;
byte menupos = 0;
const byte lcdsizex = 16;
const byte lcdsizey = 2;
const byte lcdcaractersize = (lcdsizex * lcdsizey) - 1;
char lcdarray [lcdsizey][lcdsizex];
bool lcdchanged[lcdsizey][lcdsizex];
byte lcdmutato = 0;
bool lcdposemode = true;
bool valtozas = false;
String wavestring = "";


void lcdarrayinit() {
  for (byte i = 0; i < lcdsizex; i++) {
    for (byte j = 0; j < lcdsizey; j++) {
      lcdarray[j][i] = ' ';
      lcdchanged[j][i] = false;
    }
  }
  byte lcdmutato = 0;
  bool lcdposemode = true;
}

void lcdrefreesh() {

  byte fi = lcdmutato / lcdsizex;
  byte si = lcdmutato % lcdsizex;
  if (lcdchanged[fi][si]) {
    if (lcdposemode) {
      //  starttime = micros();
      lcd.setCursor(si, fi);
      // stoptime = micros();
      // eltelttime = stoptime - starttime;
      lcdposemode = false;
    } else {
      // starttime = micros();
      lcd.print(lcdarray[fi][si]);
      //stoptime = micros();
      // eltelttime2 = stoptime - starttime;
      lcdposemode = true;
      lcdchanged[fi][si] = false;
    }
  }
  if (lcdposemode) {
    if (lcdmutato < lcdcaractersize) {
      lcdmutato++;
    } else {
      lcdmutato = 0;
    }
  }

}

void lcdkiirtomb(String szoveg, byte sor, byte oszlop) {
  if (sor < lcdsizey) {
    for (byte i = 0; i < szoveg.length(); i++) {
      if (oszlop + i < lcdsizex) {
        if (lcdarray [sor][oszlop + i] != szoveg[i]) {
          lcdarray [sor][oszlop + i] = szoveg[i];
          lcdchanged[sor][oszlop + i] = true;
        }
      }
    }
  }
}



void lcdkiir (String szoveg, String szoveg2) {

  lcdkiirtomb(szoveg, 0, 0);
  lcdkiirtomb(szoveg2, 1, 0);
  lcdmutato = 0;
  lcdposemode = true;

}

void lcdkiirpage() {
  lcd.setCursor(0, 0);
  lcd.print(menuoldal);
  audiorestart();
}

//A teljes menürendszer
void menukiir() {
  switch (menuoldal) {
    case 1:
      lcdkiir (pachname, "Algorithm:" + String(lcdprint3(alg)) + "  ");
      //lcdkiir("PCH: 1   >  2     ", "     " + String(lcdprint3( eltelttime)) + "  " + String(lcdprint3( eltelttime2)) + "    ");
      break;
    case 2:
      switch (opmenuoldal) {
        case 1:
          //op1ar
          if (inc) {
            if (op1ar < 127) {
              op1ar++;
            } else {
              op1ar = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1ar > 0) {
              op1ar--;
            } else {
              op1ar = 127;
            }
            dec = false;
          }
          lcdkiir("Op1: AR < AL     ", "     " + String(lcdprint3(op1ar)) + "  " + String(lcdprint3(op1al)) + "    ");

          break;
        case 2:
          //op2ar
          if (inc) {
            if (op2ar < 127) {
              op2ar++;
            } else {
              op2ar = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2ar > 0) {
              op2ar--;
            } else {
              op2ar = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: AR < AL     ", "     " + String(lcdprint3(op2ar)) + "  " + String(lcdprint3(op2al)) + "    ");

          break;
        case 3:
          //op3ar
          if (inc) {
            if (op3ar < 127) {
              op3ar++;
            } else {
              op3ar = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3ar > 0) {
              op3ar--;
            } else {
              op3ar = 127;
            }
            dec = false;
          }
          lcdkiir("Op3: AR < AL     ", "     " + String(lcdprint3(op3ar)) + "  " + String(lcdprint3(op3al)) + "    ");

          break;
        case 4:
          //op4ar
          if (inc) {
            if (op4ar < 127) {
              op4ar++;
            } else {
              op4ar = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4ar > 0) {
              op4ar--;
            } else {
              op4ar = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: AR < AL     ", "     " + String(lcdprint3(op4ar)) + "  " + String(lcdprint3(op4al)) + "    ");

          break;
        case 5:
          //op5ar
          if (inc) {
            if (op5ar < 127) {
              op5ar++;
            } else {
              op5ar = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5ar > 0) {
              op5ar--;
            } else {
              op5ar = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: AR < AL     ", "     " + String(lcdprint3(op5ar)) + "  " + String(lcdprint3(op5al)) + "    ");

          break;
        case 6:
          //op6ar
          if (inc) {
            if (op6ar < 127) {
              op6ar++;
            } else {
              op6ar = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6ar > 0) {
              op6ar--;
            } else {
              op6ar = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: AR < AL     ", "     " + String(lcdprint3(op6ar)) + "  " + String(lcdprint3(op6al)) + "    ");


          break;
        case 7:
          //pichar
          if (inc) {
            if (pichar < 127) {
              pichar++;
            } else {
              pichar = 0;
            }
            inc = false;
          }
          if (dec) {
            if (pichar > 0) {
              pichar--;
            } else {
              pichar = 127;
            }
            dec = false;
          }
          lcdkiir("PCH: AR < AL    ", "     " + String(lcdprint3(pichar)) + "  " + String(lcdprint3(pichal)) + "    ");

          break;
      }
      break;

    case 3:
      switch (opmenuoldal) {
        case 1:
          //op1al

          if (inc) {
            if (op1al < 127) {
              op1al++;
            } else {
              op1al = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1al > 0) {
              op1al--;
            } else {
              op1al = 127;
            }
            dec = false;
          }
          lcdkiir("Op1: AR  >AL     ", "     " + String(lcdprint3(op1ar)) + "  " + String(lcdprint3(op1al)) + "    ");

          break;
        case 2:
          //op2ar

          if (inc) {
            if (op2al < 127) {
              op2al++;
            } else {
              op2al = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2al > 0) {
              op2al--;
            } else {
              op2al = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: AR  >AL     ", "     " + String(lcdprint3(op2ar)) + "  " + String(lcdprint3(op2al)) + "    ");

          break;
        case 3:
          //op3ar

          if (inc) {
            if (op3al < 127) {
              op3al++;
            } else {
              op3al = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3al > 0) {
              op3al--;
            } else {
              op3al = 127;
            }
            dec = false;
          }
          lcdkiir("Op3: AR  >AL     ", "     " + String(lcdprint3(op3ar)) + "  " + String(lcdprint3(op3al)) + "    ");

          break;
        case 4:
          //op4ar

          if (inc) {
            if (op4al < 127) {
              op4al++;
            } else {
              op4al = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4al > 0) {
              op4al--;
            } else {
              op4al = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: AR  >AL     ", "     " + String(lcdprint3(op4ar)) + "  " + String(lcdprint3(op4al)) + "    ");

          break;
        case 5:
          //op5ar

          if (inc) {
            if (op5al < 127) {
              op5al++;
            } else {
              op5al = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5al > 0) {
              op5al--;
            } else {
              op5al = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: AR  >AL     ", "     " + String(lcdprint3(op5ar)) + "  " + String(lcdprint3(op5al)) + "    ");

          break;
        case 6:
          //op6ar

          if (inc) {
            if (op6al < 127) {
              op6al++;
            } else {
              op6al = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6al > 0) {
              op6al--;
            } else {
              op6al = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: AR  >AL     ", "     " + String(lcdprint3(op6ar)) + "  " + String(lcdprint3(op6al)) + "    ");

          break;
        case 7:
          //pichar

          if (inc) {
            if (pichal < 127) {
              pichal++;
            } else {
              pichal = 0;
            }
            inc = false;
          }
          if (dec) {
            if (pichal > 0) {
              pichal--;
            } else {
              pichal = 127;
            }
            dec = false;
          }
          lcdkiir("PCH: AR  >AL     ", "     " + String(lcdprint3(pichar)) + "  " + String(lcdprint3(pichal)) + "    ");

          break;
      }
      break;
    case 4:
      switch (opmenuoldal) {
        case 1: //op1d1l
          if (inc) {
            if (op1d1l < 127) {
              op1d1l++;
            } else {
              op1d1l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1d1l > 0) {
              op1d1l--;
            } else {
              op1d1l = 127;
            }
            dec = false;
          }
          lcdkiir("Op1: D1L< D1R    ", "     " + String(lcdprint3(op1d1l)) + "  " + String(lcdprint3(op1d1r)) + "    ");

          break;
        case 2: //op2d1l
          if (inc) {
            if (op2d1l < 127) {
              op2d1l++;
            } else {
              op2d1l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2d1l > 0) {
              op2d1l--;
            } else {
              op2d1l = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: D1L< D1R    ", "     " + String(lcdprint3(op2d1l)) + "  " + String(lcdprint3(op2d1r)) + "    ");

          break;
        case 3: //op3d1l
          if (inc) {
            if (op3d1l < 127) {
              op3d1l++;
            } else {
              op3d1l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3d1l > 0) {
              op3d1l--;
            } else {
              op3d1l = 127;
            }
            dec = false;
          }
          lcdkiir("Op3: D1L< D1R    ", "     " + String(lcdprint3(op3d1l)) + "  " + String(lcdprint3(op3d1r)) + "    ");

          break;
        case 4: //op4d1l
          if (inc) {
            if (op4d1l < 127) {
              op4d1l++;
            } else {
              op4d1l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4d1l > 0) {
              op4d1l--;
            } else {
              op4d1l = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: D1L< D1R    ", "     " + String(lcdprint3(op4d1l)) + "  " + String(lcdprint3(op4d1r)) + "    ");

          break;
        case 5: //op5d1l
          if (inc) {
            if (op5d1l < 127) {
              op5d1l++;
            } else {
              op5d1l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5d1l > 0) {
              op5d1l--;
            } else {
              op5d1l = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: D1L< D1R    ", "     " + String(lcdprint3(op5d1l)) + "  " + String(lcdprint3(op5d1r)) + "    ");

          break;
        case 6: //op6d1l
          if (inc) {
            if (op6d1l < 127) {
              op6d1l++;
            } else {
              op6d1l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6d1l > 0) {
              op6d1l--;
            } else {
              op6d1l = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: D1L< D1R    ", "     " + String(lcdprint3(op6d1l)) + "  " + String(lcdprint3(op6d1r)) + "    ");

          break;
        case 7: //op6d1l
          if (inc) {
            if (pichd1l < 127) {
              pichd1l++;
            } else {
              pichd1l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (pichd1l > 0) {
              pichd1l--;
            } else {
              pichd1l = 127;
            }
            dec = false;
          }
          lcdkiir("PCH: D1L< D1R    ", "     " + String(lcdprint3(pichd1l)) + "  " + String(lcdprint3(pichd1r)) + "    ");

          break;
      }
      break;
    case 5:
      switch (opmenuoldal) {
        case 1:
          //op1d1r
          if (inc) {
            if (op1d1r < 127) {
              op1d1r++;
            } else {
              op1d1r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1d1r > 0) {
              op1d1r--;
            } else {
              op1d1r = 127;
            }
            dec = false;
          }
          lcdkiir("Op1: D1L >D1R    ", "     " + String(lcdprint3(op1d1l)) + "  " + String(lcdprint3(op1d1r)) + "    ");

          break;
        case 2:
          //op2d1r
          if (inc) {
            if (op2d1r < 127) {
              op2d1r++;
            } else {
              op2d1r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2d1r > 0) {
              op2d1r--;
            } else {
              op2d1r = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: D1L >D1R    ", "     " + String(lcdprint3(op2d1l)) + "  " + String(lcdprint3(op2d1r)) + "    ");

          break;
        case 3:
          //op3d1r
          if (inc) {
            if (op3d1r < 127) {
              op3d1r++;
            } else {
              op3d1r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3d1r > 0) {
              op3d1r--;
            } else {
              op3d1r = 127;
            }
            dec = false;
          }
          lcdkiir("Op3: D1L >D1R    ", "     " + String(lcdprint3(op3d1l)) + "  " + String(lcdprint3(op3d1r)) + "    ");

          break;
        case 4:
          //op4d1r
          if (inc) {
            if (op4d1r < 127) {
              op4d1r++;
            } else {
              op4d1r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4d1r > 0) {
              op4d1r--;
            } else {
              op4d1r = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: D1L >D1R    ", "     " + String(lcdprint3(op4d1l)) + "  " + String(lcdprint3(op4d1r)) + "    ");

          break;
        case 5:
          //op5d1r
          if (inc) {
            if (op5d1r < 127) {
              op5d1r++;
            } else {
              op5d1r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5d1r > 0) {
              op5d1r--;
            } else {
              op5d1r = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: D1L >D1R    ", "     " + String(lcdprint3(op5d1l)) + "  " + String(lcdprint3(op5d1r)) + "    ");

          break;
        case 6:
          //op6d1r
          if (inc) {
            if (op6d1r < 127) {
              op6d1r++;
            } else {
              op6d1r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6d1r > 0) {
              op6d1r--;
            } else {
              op6d1r = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: D1L >D1R    ", "     " + String(lcdprint3(op6d1l)) + "  " + String(lcdprint3(op6d1r)) + "    ");

          break;
        case 7:
          //pichd1r
          if (inc) {
            if (pichd1r < 127) {
              pichd1r++;
            } else {
              pichd1r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (pichd1r > 0) {
              pichd1r--;
            } else {
              pichd1r = 127;
            }
            dec = false;
          }
          lcdkiir("PCH: D1L >D1R    ", "     " + String(lcdprint3(pichd1l)) + "  " + String(lcdprint3(pichd1r)) + "    ");

          break;
      }
      break;
    case 6:
      switch (opmenuoldal)
      {
        case 1:
          //op1d2l

          if (inc) {
            if (op1d2l < 127) {
              op1d2l++;
            } else {
              op1d2l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1d2l > 0) {
              op1d2l--;
            } else {
              op1d2l = 127;
            }
            dec = false;
          }
          lcdkiir("Op1: D2L< D2R     ", "     " + String(lcdprint3(op1d2l)) + "  " + String(lcdprint3(op1d2r)) + "    ");

          break;
        case 2:
          //op2d2l

          if (inc) {
            if (op2d2l < 127) {
              op2d2l++;
            } else {
              op2d2l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2d2l > 0) {
              op2d2l--;
            } else {
              op2d2l = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: D2L< D2R     ", "     " + String(lcdprint3(op2d2l)) + "  " + String(lcdprint3(op2d2r)) + "    ");

          break;
        case 3:
          //op3d2l

          if (inc) {
            if (op3d2l < 127) {
              op3d2l++;
            } else {
              op3d2l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3d2l > 0) {
              op3d2l--;
            } else {
              op3d2l = 127;
            }
            dec = false;
          }


          lcdkiir("Op3: D2L< D2R     ", "     " + String(lcdprint3(op3d2l)) + "  " + String(lcdprint3(op3d2r)) + "    ");

          break;
        case 4:
          //op2d2l

          if (inc) {
            if (op4d2l < 127) {
              op4d2l++;
            } else {
              op4d2l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4d2l > 0) {
              op4d2l--;
            } else {
              op4d2l = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: D2L< D2R     ", "     " + String(lcdprint3(op4d2l)) + "  " + String(lcdprint3(op4d2r)) + "    ");

          break;
        case 5:
          //op2d2l

          if (inc) {
            if (op5d2l < 127) {
              op5d2l++;
            } else {
              op5d2l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5d2l > 0) {
              op5d2l--;
            } else {
              op5d2l = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: D2L< D2R     ", "     " + String(lcdprint3(op5d2l)) + "  " + String(lcdprint3(op5d2r)) + "    ");

          break;
        case 6:
          //op6d2l

          if (inc) {
            if (op6d2l < 127) {
              op6d2l++;
            } else {
              op6d2l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6d2l > 0) {
              op6d2l--;
            } else {
              op6d2l = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: D2L< D2R     ", "     " + String(lcdprint3(op6d2l)) + "  " + String(lcdprint3(op6d2r)) + "    ");

          break;
        case 7:
          //pichd2l

          if (inc) {
            if (pichd2l < 127) {
              pichd2l++;
            } else {
              pichd2l = 0;
            }
            inc = false;
          }
          if (dec) {
            if (pichd2l > 0) {
              pichd2l--;
            } else {
              pichd2l = 127;
            }
            dec = false;
          }
          lcdkiir("PCH: D2L< D2R     ", "     " + String(lcdprint3(pichd2l)) + "  " + String(lcdprint3(pichd2r)) + "    ");

          break;
      }
      break;
    case 7:
      switch (opmenuoldal) {
        case 1:
          //op1d2r
          if (inc) {
            if (op1d2r < 127) {
              op1d2r++;
            } else {
              op1d2r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1d2r > 0) {
              op1d2r--;
            } else {
              op1d2r = 127;
            }
            dec = false;
          }
          lcdkiir("Op1: D2L >D2R     ", "     " + String(lcdprint3(op1d2l)) + "  " + String(lcdprint3(op1d2r)) + "    ");

          break;
        case 2:
          //op2d2r
          if (inc) {
            if (op2d2r < 127) {
              op2d2r++;
            } else {
              op2d2r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2d2r > 0) {
              op2d2r--;
            } else {
              op2d2r = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: D2L >D2R     ", "     " + String(lcdprint3(op2d2l)) + "  " + String(lcdprint3(op2d2r)) + "    ");

          break;
        case 3:
          //op3d2r
          if (inc) {
            if (op3d2r < 127) {
              op3d2r++;
            } else {
              op3d2r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3d2r > 0) {
              op3d2r--;
            } else {
              op3d2r = 127;
            }
            dec = false;
          }
          lcdkiir("Op3: D2L >D2R     ", "     " + String(lcdprint3(op3d2l)) + "  " + String(lcdprint3(op3d2r)) + "    ");

          break;
        case 4:
          //op4d2r
          if (inc) {
            if (op4d2r < 127) {
              op4d2r++;
            } else {
              op4d2r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4d2r > 0) {
              op4d2r--;
            } else {
              op4d2r = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: D2L >D2R     ", "     " + String(lcdprint3(op4d2l)) + "  " + String(lcdprint3(op4d2r)) + "    ");

          break;
        case 5:
          //op5d2r
          if (inc) {
            if (op5d2r < 127) {
              op5d2r++;
            } else {
              op5d2r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5d2r > 0) {
              op5d2r--;
            } else {
              op5d2r = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: D2L >D2R     ", "     " + String(lcdprint3(op5d2l)) + "  " + String(lcdprint3(op5d2r)) + "    ");

          break;
        case 6:
          //op6d2r
          if (inc) {
            if (op6d2r < 127) {
              op6d2r++;
            } else {
              op6d2r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6d2r > 0) {
              op6d2r--;
            } else {
              op6d2r = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: D2L >D2R     ", "     " + String(lcdprint3(op6d2l)) + "  " + String(lcdprint3(op6d2r)) + "    ");

          break;
        case 7:
          //pichd2r
          if (inc) {
            if (pichd2r < 127) {
              pichd2r++;
            } else {
              pichd2r = 0;
            }
            inc = false;
          }
          if (dec) {
            if (pichd2r > 0) {
              pichd2r--;
            } else {
              pichd2r = 127;
            }
            dec = false;
          }
          lcdkiir("PCH: D2L >D2R     ", "     " + String(lcdprint3(pichd2l)) + "  " + String(lcdprint3(pichd2r)) + "    ");

          break;
      }

      break;
    case 8:
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (op1rl < 127) {
              op1rl++;
            } else {
              op1rl = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1rl > 0) {
              op1rl--;
            } else {
              op1rl = 127;
            }
            dec = false;
          }
          lcdkiir("Op1: RL< RR     ", "     " + String(lcdprint3(op1rl)) + "  " + String(lcdprint3(op1rr)) + "    ");

          break;
        case 2:
          if (inc) {
            if (op2rl < 127) {
              op2rl++;
            } else {
              op2rl = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2rl > 0) {
              op2rl--;
            } else {
              op2rl = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: RL<  RR     ", "     " + String(lcdprint3(op2rl)) + "  " + String(lcdprint3(op2rr)) + "    ");

          break;
        case 3:
          if (inc) {
            if (op3rl < 127) {
              op3rl++;
            } else {
              op3rl = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3rl > 0) {
              op3rl--;
            } else {
              op3rl = 127;
            }
            dec = false;
          }
          lcdkiir("Op3: RL<  RR     ", "     " + String(lcdprint3(op3rl)) + "  " + String(lcdprint3(op3rr)) + "    ");

          break;
        case 4:
          if (inc) {
            if (op4rl < 127) {
              op4rl++;
            } else {
              op4rl = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4rl > 0) {
              op4rl--;
            } else {
              op4rl = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: RL<  RR     ", "     " + String(lcdprint3(op4rl)) + "  " + String(lcdprint3(op4rr)) + "    ");

          break;
        case 5:
          if (inc) {
            if (op5rl < 127) {
              op5rl++;
            } else {
              op5rl = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5rl > 0) {
              op5rl--;
            } else {
              op5rl = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: RL<  RR     ", "     " + String(lcdprint3(op5rl)) + "  " + String(lcdprint3(op5rr)) + "    ");

          break;
        case 6:
          if (inc) {
            if (op6rl < 127) {
              op6rl++;
            } else {
              op6rl = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6rl > 0) {
              op6rl--;
            } else {
              op6rl = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: RL<  RR     ", "     " + String(lcdprint3(op6rl)) + "  " + String(lcdprint3(op6rr)) + "    ");


          break;
        case 7:
          //pichrl
          if (inc) {
            if (pichrl < 127) {
              pichrl++;
            } else {
              pichrl = 0;
            }
            inc = false;
          }
          if (dec) {
            if (pichrl > 0) {
              pichrl--;
            } else {
              pichrl = 127;
            }
            dec = false;
          }
          lcdkiir("PCH: RL<  RR     ", "     " + String(lcdprint3(pichrl)) + "  " + String(lcdprint3(pichrr)) + "    ");

          break;
      }
      break;
    case 9:
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (op1rr < 127) {
              op1rr++;
            } else {
              op1rr = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1rr > 0) {
              op1rr--;
            } else {
              op1rr = 127;
            }
            dec = false;
          }
          lcdkiir("Op1: RL  >RR     ", "     " + String(lcdprint3(op1rl)) + "  " + String(lcdprint3(op1rr)) + "    ");

          break;
        case 2:
          if (inc) {
            if (op2rr < 127) {
              op2rr++;
            } else {
              op2rr = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2rr > 0) {
              op2rr--;
            } else {
              op2rr = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: RL  >RR     ", "     " + String(lcdprint3(op2rl)) + "  " + String(lcdprint3(op2rr)) + "    ");


          break;
        case 3:
          if (inc) {
            if (op3rr < 127) {
              op3rr++;
            } else {
              op3rr = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3rr > 0) {
              op3rr--;
            } else {
              op3rr = 127;
            }
            dec = false;
          }
          lcdkiir("Op3: RL  >RR     ", "     " + String(lcdprint3(op3rl)) + "  " + String(lcdprint3(op3rr)) + "    ");

          break;
        case 4:
          if (inc) {
            if (op4rr < 127) {
              op4rr++;
            } else {
              op4rr = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4rr > 0) {
              op4rr--;
            } else {
              op4rr = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: RL  >RR     ", "     " + String(lcdprint3(op4rl)) + "  " + String(lcdprint3(op4rr)) + "    ");

          break;
        case 5:
          if (inc) {
            if (op5rr < 127) {
              op5rr++;
            } else {
              op5rr = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5rr > 0) {
              op5rr--;
            } else {
              op5rr = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: RL  >RR     ", "     " + String(lcdprint3(op5rl)) + "  " + String(lcdprint3(op5rr)) + "    ");

          break;
        case 6:
          if (inc) {
            if (op6rr < 127) {
              op6rr++;
            } else {
              op6rr = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6rr > 0) {
              op6rr--;
            } else {
              op6rr = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: RL  >RR     ", "     " + String(lcdprint3(op6rl)) + "  " + String(lcdprint3(op6rr)) + "    ");

          break;
        case 7:
          //pichrr
          if (inc) {
            if (pichrr < 127) {
              pichrr++;
            } else {
              pichrr = 0;
            }
            inc = false;
          }
          if (dec) {
            if (pichrr > 0) {
              pichrr--;
            } else {
              pichrr = 127;
            }
            dec = false;
          }
          lcdkiir("PCH: RL  >RR     ", "     " + String(lcdprint3(pichrl)) + "  " + String(lcdprint3(pichrr)) + "    ");

          break;
      }
      break;
    case 10:
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (op1veloc < 127) {
              op1veloc++;
            } else {
              op1veloc = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1veloc > 0) {
              op1veloc--;
            } else {
              op1veloc = 127;
            }
            dec = false;
          }
          lcdkiir("Op1: VEL< VOL    6", "     " + String(lcdprint3(op1veloc)) + "  " + String(lcdprint3(op1volume)) + "    ");
          break;
        case 2:
          if (inc) {
            if (op2veloc < 127) {
              op2veloc++;
            } else {
              op2veloc = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2veloc > 0) {
              op2veloc--;
            } else {
              op2veloc = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: VEL< VOL    6", "     " + String(lcdprint3(op2veloc)) + "  " + String(lcdprint3(op2volume)) + "    ");
          break;
        case 3:
          if (inc) {
            if (op3veloc < 127) {
              op3veloc++;
            } else {
              op3veloc = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3veloc > 0) {
              op3veloc--;
            } else {
              op3veloc = 127;
            }
            dec = false;
          }
          lcdkiir("Op3: VEL< VOL    6", "     " + String(lcdprint3(op3veloc)) + "  " + String(lcdprint3(op3volume)) + "    ");
          break;
        case 4:
          if (inc) {
            if (op4veloc < 127) {
              op4veloc++;
            } else {
              op4veloc = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4veloc > 0) {
              op4veloc--;
            } else {
              op4veloc = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: VEL< VOL    6", "     " + String(lcdprint3(op4veloc)) + "  " + String(lcdprint3(op4volume)) + "    ");
          break;
        case 5:
          if (inc) {
            if (op5veloc < 127) {
              op5veloc++;
            } else {
              op5veloc = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5veloc > 0) {
              op5veloc--;
            } else {
              op5veloc = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: VEL< VOL    6", "     " + String(lcdprint3(op5veloc)) + "  " + String(lcdprint3(op5volume)) + "    ");
          break;
        case 6:
          if (inc) {
            if (op6veloc < 127) {
              op6veloc++;
            } else {
              op6veloc = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6veloc > 0) {
              op6veloc--;
            } else {
              op6veloc = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: VEL< VOL    6", "     " + String(lcdprint3(op6veloc)) + "  " + String(lcdprint3(op6volume)) + "    ");
          break;
        case 7:
          if (inc) {
            if ( pichop1 < 2) {
              pichop1++;
            } else {
              pichop1 = 0;
            }
            inc = false;
          }
          if (dec) {
            if ( pichop1 > 0) {
              pichop1--;
            } else {
              pichop1 = 2;
            }
            dec = false;
          }
          lcdkiir("PCH: PC1< PC2     ", "     " + String(lcdprint3( pichop1)) + "  " + String(lcdprint3( pichop2)) + "    ");
          pichgorbeinit();
          break;
      }
      break;
    case 11:
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (op1volumeorig < 127) {
              op1volumeorig++;
            } else {
              op1volumeorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1volumeorig > 0) {
              op1volumeorig--;
            } else {
              op1volumeorig = 127;
            }
            dec = false;
          }
          op1volume=op1volumeorig;
          lcdkiir("Op1: VEL >VOL    ", "     " + String(lcdprint3(op1veloc)) + "  " + String(lcdprint3(op1volume)) + "    ");
          
          break;
        case 2:
          if (inc) {
            if (op2volume < 127) {
              op2volume++;
            } else {
              op2volume = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2volume > 0) {
              op2volume--;
            } else {
              op2volume = 127;
            }
            dec = false;
          }

          lcdkiir("Op2: VEL >VOL    ", "     " + String(lcdprint3(op2veloc)) + "  " + String(lcdprint3(op2volume)) + "    ");
          break;
        case 3:
          if (inc) {
            if (op3volume < 127) {
              op3volume++;
            } else {
              op3volume = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3volume > 0) {
              op3volume--;
            } else {
              op3volume = 127;
            }
            dec = false;
          }

          lcdkiir("Op3: VEL >VOL    ", "     " + String(lcdprint3(op3veloc)) + "  " + String(lcdprint3(op3volume)) + "    ");
          break;
        case 4:
          if (inc) {
            if (op4volume < 127) {
              op4volume++;
            } else {
              op4volume = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4volume > 0) {
              op4volume--;
            } else {
              op4volume = 127;
            }
            dec = false;
          }

          lcdkiir("Op4: VEL >VOL    ", "     " + String(lcdprint3(op4veloc)) + "  " + String(lcdprint3(op4volume)) + "    ");

          break;
        case 5:
          if (inc) {
            if (op5volume < 127) {
              op5volume++;
            } else {
              op5volume = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5volume > 0) {
              op5volume--;
            } else {
              op5volume = 127;
            }
            dec = false;
          }

          lcdkiir("Op5: VEL >VOL    ", "     " + String(lcdprint3(op5veloc)) + "  " + String(lcdprint3(op5volume)) + "    ");
          break;
        case 6:
          if (inc) {
            if (op6volume < 127) {
              op6volume++;
            } else {
              op6volume = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6volume > 0) {
              op6volume--;
            } else {
              op6volume = 127;
            }
            dec = false;
          }

          lcdkiir("Op6: VEL >VOL    ", "     " + String(lcdprint3(op6veloc)) + "  " + String(lcdprint3(op6volume)) + "    ");
          break;
        case 7:
          if (inc) {
            if ( pichop2 < 2) {
              pichop2++;
            } else {
              pichop2 = 0;
            }
            inc = false;
          }
          if (dec) {
            if ( pichop2 > 0) {
              pichop2--;
            } else {
              pichop2 = 2;
            }
            dec = false;
          }
          lcdkiir("PCH: PC1 >PC2     ", "     " + String(lcdprint3( pichop1)) + "  " + String(lcdprint3( pichop2)) + "    ");
          pichgorbeinit();
          break;
      }
      break;

    case 12:
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (op1generatorfreqorig < 127) {
              op1generatorfreqorig++;
            } else {
              op1generatorfreqorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1generatorfreqorig > 0) {
              op1generatorfreqorig--;
            } else {
              op1generatorfreqorig = 127;
            }
            dec = false;
          }
          op1generatorfreq=op1generatorfreqorig;
          lcdkiir("Op1: FRQ< FIX    ", "     " + String(lcdprint3(op1generatorfreq)) + "  " + String(lcdprint3(notefixedop1)) + "    ");
          break;
        case 2:
          if (inc) {
            if (op2generatorfreq < 127) {
              op2generatorfreq++;
            } else {
              op2generatorfreq = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2generatorfreq > 0) {
              op2generatorfreq--;
            } else {
              op2generatorfreq = 127;
            }
            dec = false;
          }
          lcdkiir("Op2: FRQ< FIX    ", "     " + String(lcdprint3(op2generatorfreq)) + "  " + String(lcdprint3(notefixedop2)) + "    ");
          break;
        case 3:
          if (inc) {
            if (op3generatorfreq < 127) {
              op3generatorfreq++;
            } else {
              op3generatorfreq = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3generatorfreq > 0) {
              op3generatorfreq--;
            } else {
              op3generatorfreq = 127;
            }
            dec = false;
          }
          lcdkiir("Op3: FRQ< FIX    ", "     " + String(lcdprint3(op3generatorfreq)) + "  " + String(lcdprint3(notefixedop3)) + "    ");
          break;
        case 4:
          if (inc) {
            if (op4generatorfreq < 127) {
              op4generatorfreq++;
            } else {
              op4generatorfreq = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4generatorfreq > 0) {
              op4generatorfreq--;
            } else {
              op4generatorfreq = 127;
            }
            dec = false;
          }
          lcdkiir("Op4: FRQ< FIX    ", "     " + String(lcdprint3(op4generatorfreq)) + "  " + String(lcdprint3(notefixedop4)) + "    ");
          break;
        case 5:
          if (inc) {
            if (op5generatorfreq < 127) {
              op5generatorfreq++;
            } else {
              op5generatorfreq = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5generatorfreq > 0) {
              op5generatorfreq--;
            } else {
              op5generatorfreq = 127;
            }
            dec = false;
          }
          lcdkiir("Op5: FRQ< FIX    ", "     " + String(lcdprint3(op5generatorfreq)) + "  " + String(lcdprint3(notefixedop5)) + "    ");
          break;
        case 6:
          if (inc) {
            if (op6generatorfreq < 127) {
              op6generatorfreq++;
            } else {
              op6generatorfreq = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6generatorfreq > 0) {
              op6generatorfreq--;
            } else {
              op6generatorfreq = 127;
            }
            dec = false;
          }
          lcdkiir("Op6: FRQ< FIX    ", "     " + String(lcdprint3(op6generatorfreq)) + "  " + String(lcdprint3(notefixedop6)) + "    ");
          break;
        case 7:
          if (inc) {
            if ( pichop3 < 2) {
              pichop3++;
            } else {
              pichop3 = 0;
            }
            inc = false;
          }
          if (dec) {
            if ( pichop3 > 0) {
              pichop3--;
            } else {
              pichop3 = 2;
            }
            dec = false;
          }
          lcdkiir("PCH: PC3< PC4     ", "     " + String(lcdprint3( pichop3)) + "  " + String(lcdprint3( pichop4)) + "    ");
          pichgorbeinit();
          break;
      }
      break;


    case 13:
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (notefixedop1) {
              notefixedop1 = false;
            } else {
              notefixedop1 = true;
            }
            inc = false;
          }
          if (dec) {
            if (notefixedop1) {
              notefixedop1 = false;
            } else {
              notefixedop1 = true;
            }
            dec = false;
          }
          lcdkiir("Op1: FRQ >FIX     ", "     " + String(lcdprint3(op1generatorfreq)) + "  " + String(lcdprint3(notefixedop1)) + "    ");
          break;
        case 2:
          if (inc) {
            if (notefixedop2) {
              notefixedop2 = false;
            } else {
              notefixedop2 = true;
            }
            inc = false;
          }
          if (dec) {
            if (notefixedop2) {
              notefixedop2 = false;
            } else {
              notefixedop2 = true;
            }
            dec = false;
          }
          lcdkiir("Op2: FRQ >FIX     ", "     " + String(lcdprint3(op2generatorfreq)) + "  " + String(lcdprint3(notefixedop2)) + "    ");
          break;
        case 3:
          if (inc) {
            if (notefixedop3) {
              notefixedop3 = false;
            } else {
              notefixedop3 = true;
            }
            inc = false;
          }
          if (dec) {
            if (notefixedop3) {
              notefixedop3 = false;
            } else {
              notefixedop3 = true;
            }
            dec = false;
          }
          lcdkiir("Op3: FRQ >FIX     ", "     " + String(lcdprint3(op3generatorfreq)) + "  " + String(lcdprint3(notefixedop3)) + "    ");
          break;
        case 4:
          if (inc) {
            if (notefixedop4) {
              notefixedop4 = false;
            } else {
              notefixedop4 = true;
            }
            inc = false;
          }
          if (dec) {
            if (notefixedop4) {
              notefixedop4 = false;
            } else {
              notefixedop4 = true;
            }
            dec = false;
          }
          lcdkiir("Op4: FRQ >FIX     ", "     " + String(lcdprint3(op4generatorfreq)) + "  " + String(lcdprint3(notefixedop4)) + "    ");
          break;
        case 5:
          if (inc) {
            if (notefixedop5) {
              notefixedop5 = false;
            } else {
              notefixedop5 = true;
            }
            inc = false;
          }
          if (dec) {
            if (notefixedop5) {
              notefixedop5 = false;
            } else {
              notefixedop5 = true;
            }
            dec = false;
          }
          lcdkiir("Op5: FRQ >FIX     ", "     " + String(lcdprint3(op5generatorfreq)) + "  " + String(lcdprint3(notefixedop5)) + "    ");
          break;
        case 6:
          if (inc) {
            if (notefixedop6) {
              notefixedop6 = false;
            } else {
              notefixedop6 = true;
            }
            inc = false;
          }
          if (dec) {
            if (notefixedop6) {
              notefixedop6 = false;
            } else {
              notefixedop6 = true;
            }
            dec = false;
          }
          lcdkiir("Op6: FRQ >FIX     ", "     " + String(lcdprint3(op6generatorfreq)) + "  " + String(lcdprint3(notefixedop6)) + "    ");
          break;
        case 7:
          if (inc) {
            if ( pichop4 < 2) {
              pichop4++;
            } else {
              pichop4 = 0;
            }
            inc = false;
          }
          if (dec) {
            if ( pichop4 > 0) {
              pichop4--;
            } else {
              pichop4 = 2;
            }
            dec = false;
          }
          lcdkiir("PCH: PC3 >PC4     ", "     " + String(lcdprint3( pichop3)) + "  " + String(lcdprint3( pichop4)) + "    ");
          pichgorbeinit();
          break;
      }
      break;
    case 14:
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (op1waveform < 16) {
              op1waveform++;
            } else {
              op1waveform = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1waveform > 0) {
              op1waveform--;
            } else {
              op1waveform = 16;
            }
            dec = false;
          }
          
          switch (op1waveform)
          {
            case 0: wavestring = "NONE        "; break;
            case 1: wavestring = "SINE HIGH   "; break;
            case 2: wavestring = "SINE LOW    "; break;
            case 3: wavestring = "TRIA HIGH   "; break;
            case 4: wavestring = "TRIAL LOW   "; break;
            case 5: wavestring = "SAWHT HIGH  "; break;
            case 6: wavestring = "SAWHT LOW   "; break;
            case 7: wavestring = "SQUARE HIGH "; break;
            case 8: wavestring = "SQUARE LOW  "; break;
            case 9: wavestring = "NOISE 1     "; break;
            case 10: wavestring ="NOISE 2     "; break;
            case 11: wavestring ="DOUBLE SINE "; break;
            case 12: wavestring ="TRIPLE SINE "; break;
            case 13: wavestring ="USER WAVE 1 "; break;
            case 14: wavestring ="USER WAVE 2 "; break;
            case 15: wavestring ="USER WAVE 3 "; break;
            case 16: wavestring ="USER WAVE 4 "; break;
          }
          lcdkiir("Op1: Wav ", "    " + wavestring);
           generatorinitone(op1waveform, generator1);
          break;
        case 2:
          if (inc) {
            if (op2waveform < 16) {
              op2waveform++;
            } else {
              op2waveform = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2waveform > 0) {
              op2waveform--;
            } else {
              op2waveform = 16;
            }
            dec = false;
          }
          lcdkiir("Op2: Wav< FRQFix ", "     " + String(lcdprint3(op2waveform)) + "  " + String(lcdprint3(op2generatorfreqfix >> 9)) + "    ");
         switch (op2waveform)
          {
            case 0: wavestring = "NONE        "; break;
            case 1: wavestring = "SINE HIGH   "; break;
            case 2: wavestring = "SINE LOW    "; break;
            case 3: wavestring = "TRIA HIGH   "; break;
            case 4: wavestring = "TRIAL LOW   "; break;
            case 5: wavestring = "SAWHT HIGH  "; break;
            case 6: wavestring = "SAWHT LOW   "; break;
            case 7: wavestring = "SQUARE HIGH "; break;
            case 8: wavestring = "SQUARE LOW  "; break;
            case 9: wavestring = "NOISE 1     "; break;
            case 10: wavestring ="NOISE 2     "; break;
            case 11: wavestring ="DOUBLE SINE "; break;
            case 12: wavestring ="TRIPLE SINE "; break;
            case 13: wavestring ="USER WAVE 1 "; break;
            case 14: wavestring ="USER WAVE 2 "; break;
            case 15: wavestring ="USER WAVE 3 "; break;
            case 16: wavestring ="USER WAVE 4 "; break;
          }
          lcdkiir("Op2: Wav ", "    " + wavestring);
          generatorinitone(op2waveform, generator2);
          break;
        case 3:
          if (inc) {
            if (op3waveform < 16) {
              op3waveform++;
            } else {
              op3waveform = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3waveform > 0) {
              op3waveform--;
            } else {
              op3waveform = 16;
            }
            dec = false;
          }
          switch (op3waveform)
          {
            case 0: wavestring = "NONE        "; break;
            case 1: wavestring = "SINE HIGH   "; break;
            case 2: wavestring = "SINE LOW    "; break;
            case 3: wavestring = "TRIA HIGH   "; break;
            case 4: wavestring = "TRIAL LOW   "; break;
            case 5: wavestring = "SAWHT HIGH  "; break;
            case 6: wavestring = "SAWHT LOW   "; break;
            case 7: wavestring = "SQUARE HIGH "; break;
            case 8: wavestring = "SQUARE LOW  "; break;
            case 9: wavestring = "NOISE 1     "; break;
            case 10: wavestring ="NOISE 2     "; break;
            case 11: wavestring ="DOUBLE SINE "; break;
            case 12: wavestring ="TRIPLE SINE "; break;
            case 13: wavestring ="USER WAVE 1 "; break;
            case 14: wavestring ="USER WAVE 2 "; break;
            case 15: wavestring ="USER WAVE 3 "; break;
            case 16: wavestring ="USER WAVE 4 "; break;
          }
          lcdkiir("Op3: Wav ", "    " + wavestring);
           generatorinitone(op3waveform, generator3);
          break;
        case 4:
          if (inc) {
            if (op4waveform < 16) {
              op4waveform++;
            } else {
              op4waveform = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4waveform > 0) {
              op4waveform--;
            } else {
              op4waveform = 16;
            }
            dec = false;
          }
           switch (op4waveform)
          {
            case 0: wavestring = "NONE        "; break;
            case 1: wavestring = "SINE HIGH   "; break;
            case 2: wavestring = "SINE LOW    "; break;
            case 3: wavestring = "TRIA HIGH   "; break;
            case 4: wavestring = "TRIAL LOW   "; break;
            case 5: wavestring = "SAWHT HIGH  "; break;
            case 6: wavestring = "SAWHT LOW   "; break;
            case 7: wavestring = "SQUARE HIGH "; break;
            case 8: wavestring = "SQUARE LOW  "; break;
            case 9: wavestring = "NOISE 1     "; break;
            case 10: wavestring ="NOISE 2     "; break;
            case 11: wavestring ="DOUBLE SINE "; break;
            case 12: wavestring ="TRIPLE SINE "; break;
            case 13: wavestring ="USER WAVE 1 "; break;
            case 14: wavestring ="USER WAVE 2 "; break;
            case 15: wavestring ="USER WAVE 3 "; break;
            case 16: wavestring ="USER WAVE 4 "; break;
          }
          lcdkiir("Op4: Wav ", "    " + wavestring);
          generatorinitone(op4waveform, generator4);
          break;
        case 5:
          if (inc) {
            if (op5waveform < 16) {
              op5waveform++;
            } else {
              op5waveform = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5waveform > 0) {
              op5waveform--;
            } else {
              op5waveform = 16;
            }
            dec = false;
          }
        switch (op5waveform)
          {
            case 0: wavestring = "NONE        "; break;
            case 1: wavestring = "SINE HIGH   "; break;
            case 2: wavestring = "SINE LOW    "; break;
            case 3: wavestring = "TRIA HIGH   "; break;
            case 4: wavestring = "TRIAL LOW   "; break;
            case 5: wavestring = "SAWHT HIGH  "; break;
            case 6: wavestring = "SAWHT LOW   "; break;
            case 7: wavestring = "SQUARE HIGH "; break;
            case 8: wavestring = "SQUARE LOW  "; break;
            case 9: wavestring = "NOISE 1     "; break;
            case 10: wavestring ="NOISE 2     "; break;
            case 11: wavestring ="DOUBLE SINE "; break;
            case 12: wavestring ="TRIPLE SINE "; break;
            case 13: wavestring ="USER WAVE 1 "; break;
            case 14: wavestring ="USER WAVE 2 "; break;
            case 15: wavestring ="USER WAVE 3 "; break;
            case 16: wavestring ="USER WAVE 4 "; break;
          }
          lcdkiir("Op5: Wav ", "    " + wavestring);
          generatorinitone(op5waveform, generator5);
          break;
        case 6:
          if (inc) {
            if (op6waveform < 16) {
              op6waveform++;
            } else {
              op6waveform = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6waveform > 0) {
              op6waveform--;
            } else {
              op6waveform = 16;
            }
            dec = false;
          }
          switch (op6waveform)
          {
            case 0: wavestring = "NONE        "; break;
            case 1: wavestring = "SINE HIGH   "; break;
            case 2: wavestring = "SINE LOW    "; break;
            case 3: wavestring = "TRIA HIGH   "; break;
            case 4: wavestring = "TRIAL LOW   "; break;
            case 5: wavestring = "SAWHT HIGH  "; break;
            case 6: wavestring = "SAWHT LOW   "; break;
            case 7: wavestring = "SQUARE HIGH "; break;
            case 8: wavestring = "SQUARE LOW  "; break;
            case 9: wavestring = "NOISE 1     "; break;
            case 10: wavestring ="NOISE 2     "; break;
            case 11: wavestring ="DOUBLE SINE "; break;
            case 12: wavestring ="TRIPLE SINE "; break;
            case 13: wavestring ="USER WAVE 1 "; break;
            case 14: wavestring ="USER WAVE 2 "; break;
            case 15: wavestring ="USER WAVE 3 "; break;
            case 16: wavestring ="USER WAVE 4 "; break;
          }
          lcdkiir("Op6: Wav ", "    " + wavestring);
           generatorinitone(op6waveform, generator6);
          break;
        case 7:
          if (inc) {
            if ( pichop5 < 2) {
              pichop5++;
            } else {
              pichop5 = 0;
            }
            inc = false;
          }
          if (dec) {
            if ( pichop5 > 0) {
              pichop5--;
            } else {
              pichop5 = 2;
            }
            dec = false;
          }
          lcdkiir("PCH: PC5< PC6     ", "     " + String(lcdprint3( pichop5)) + "  " + String(lcdprint3( pichop6)) + "    ");
          pichgorbeinit();
          break;

      }


      break;
    case 15:
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (op1generatorfreqfix < 4161536) {
              op1generatorfreqfix += fixfreqstep << 15;
            } else {
              op1generatorfreqfix = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1generatorfreqfix > 327677) {
              op1generatorfreqfix -= fixfreqstep << 15;
            } else {
              op1generatorfreqfix = 4161536;
            }
            dec = false;
          }
          lcdkiir("Op1: Wav >FRQFix ", "     " + String(lcdprint3(op1waveform)) + "  " + String(lcdprint3(op1generatorfreqfix >> 9)) + "    ");
          break;
        case 2:
          if (inc) {
            if (op2generatorfreqfix < 5080000) {
              op2generatorfreqfix += fixfreqstep * 800;
            } else {
              op2generatorfreqfix = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2generatorfreqfix > 0) {
              op2generatorfreqfix -= fixfreqstep * 800;
            } else {
              op2generatorfreqfix = 5080000;
            }
            dec = false;
          }
          lcdkiir("Op2: Wav >FRQFix ", "     " + String(lcdprint3(op2waveform)) + "  " + String(lcdprint3(op2generatorfreqfix >> 9)) + "    ");
          break;
        case 3:
          if (inc) {
            if (op3generatorfreqfix < 5080000) {
              op3generatorfreqfix += fixfreqstep * 800;
            } else {
              op3generatorfreqfix = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3generatorfreqfix > 0) {
              op3generatorfreqfix -= fixfreqstep * 800;
            } else {
              op3generatorfreqfix = 5080000;
            }
            dec = false;
          }
          lcdkiir("Op3: Wav >FRQFix ", "     " + String(lcdprint3(op3waveform)) + "  " + String(lcdprint3(op3generatorfreqfix >> 9)) + "    ");
          break;
        case 4:
          if (inc) {
            if (op4generatorfreqfix < 5080000) {
              op4generatorfreqfix += fixfreqstep * 800;
            } else {
              op4generatorfreqfix = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4generatorfreqfix > 0) {
              op4generatorfreqfix -= fixfreqstep * 800;
            } else {
              op4generatorfreqfix = 5080000;
            }
            dec = false;
          }
          lcdkiir("Op4: Wav >FRQFix ", "     " + String(lcdprint3(op4waveform)) + "  " + String(lcdprint3(op4generatorfreqfix >> 9)) + "    ");
          break;
        case 5:
          if (inc) {
            if (op5generatorfreqfix < 5080000) {
              op5generatorfreqfix += fixfreqstep * 800;
            } else {
              op5generatorfreqfix = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5generatorfreqfix > 0) {
              op5generatorfreqfix -= fixfreqstep * 800;
            } else {
              op5generatorfreqfix = 5080000;
            }
            dec = false;
          }
          lcdkiir("Op5: Wav >FRQFix ", "     " + String(lcdprint3(op5waveform)) + "  " + String(lcdprint3(op5generatorfreqfix >> 9)) + "    ");
          break;

        case 6:
          if (inc) {
            if (op6generatorfreqfix < 5080000) {
              op6generatorfreqfix += fixfreqstep * 800;
            } else {
              op6generatorfreqfix = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6generatorfreqfix > 0) {
              op6generatorfreqfix -= fixfreqstep * 800;
            } else {
              op6generatorfreqfix = 5080000;
            }
            dec = false;
          }
          lcdkiir("Op6: Wav >FRQFix ", "     " + String(lcdprint3(op6waveform)) + "  " + String(lcdprint3(op6generatorfreqfix >> 9)) + "    ");
          break;
        case 7:
          if (inc) {
            if ( pichop6 < 2) {
              pichop6++;
            } else {
              pichop6 = 0;
            }
            inc = false;
          }
          if (dec) {
            if ( pichop6 > 0) {
              pichop6--;
            } else {
              pichop6 = 2;
            }
            dec = false;
          }
          lcdkiir("PCH: PC5 >PC6     ", "     " + String(lcdprint3( pichop5)) + "  " + String(lcdprint3( pichop6)) + "    ");
          break;
      }
      break;

    case 16:
      if (inc) {
        if (frame < 127) {
          frame++;
        } else {
          frame = 1;
        }
        inc = false;
      }
      if (dec) {
        if (frame > 0) {
          frame--;
        } else {
          frame = 127;
        }
        dec = false;
      }

      lcdkiir("GLO: FRM< DIV     ", "     " + String(lcdprint3(frame)) + "  " + String(lcdprint3(szorzo)) + "    "); break;
    case 17:
      if (inc) {
        if (szorzo < 127) {
          szorzo++;
        } else {
          szorzo = 1;
        }
        inc = false;
      }
      if (dec) {
        if (szorzo > 0) {
          szorzo--;
        } else {
          szorzo = 127;
        }
        dec = false;
      }

      lcdkiir("GLO: FRM >DIV     ", "     " + String(lcdprint3(frame)) + "  " + String(lcdprint3(szorzo)) + "    ");
      hangokinit();
      break;


    case 18:
      if (inc) {
        if (alg < 6) {
          alg++;
        } else {
          alg = 0;
        }
        inc = false;
      }
      if (dec) {
        if (alg > 0) {
          alg--;
        } else {
          alg = 6;
        }
        dec = false;
      }
      switch (alg) {
        case 1:
          lcdkiir("A" + String(lcdprint2(alg)) + ": [4]-(5)-(6)", "     [1]-(2)-(3)");
          break;
        case 2:
          lcdkiir("A" + String(lcdprint2(alg)) + ":     [5]-(6)", " [1]-(2) [3]-(4)");
          break;
        case 3:
          lcdkiir("A" + String(lcdprint2(alg)) + ": [4] [5] [6]", "     [1] [2] [3]    ");
          break;
        case 4:
          lcdkiir("A" + String(lcdprint2(alg)) + ":     [5]-(6)", " [1]-(2)-(3)-(4)");
          break;
        case 5:
          lcdkiir("A" + String(lcdprint2(alg)) + "  <<5>>-{{6}}   ", "     <PWM OP1>  ");
          break;
        case 6:
          lcdkiir("A" + String(lcdprint2(alg)) + "      <5>-{6}", " <1>-{2} <3>-{4}  ");
          break;
      }
      break;
    case 19:
      if (inc) {
        if (level < 127) {
          level++;
        } else {
          level = 1;
        }
        inc = false;
      }
      if (dec) {
        if (level > 0) {
          level--;
        } else {
          level = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: ALG >LEV     ", "     " + String(lcdprint3(alg)) + "  " + String(lcdprint3(level)) + "    ");
      break;
    case 20:
      if (inc) {
        if (pichkezd < 127) {
          pichkezd++;
        } else {
          pichkezd = 1;
        }
        inc = false;
      }
      if (dec) {
        if (pichkezd > 0) {
          pichkezd--;
        } else {
          pichkezd = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: PCH0< PEG     ", "     " + String(lcdprint3(pichkezd)) + "   " + String(lcdprint3(picheglevel / 500)) + "    ");
      pichgorbeinit();
      break;
    case 21:
      if (inc) {
        if (picheglevel < 127 * 8192) {
          picheglevel += 8192;
        } else {
          picheglevel = 0;
        }
        inc = false;
      }
      if (dec) {
        if (picheglevel > 8191) {
          picheglevel -= 8192;
        } else {
          picheglevel = 127 * 8192;
        }
        dec = false;
      }
      lcdkiir("GLO: PCH0 >PEG     ", "     " + String(lcdprint3(pichkezd)) + "   " + String(lcdprint3(picheglevel / 8192)) + "    ");
      pichgorbeinit();
      break;
    case 22:
      if (inc) {
        if (oplfo < 16) {
          oplfo++;
        } else {
          oplfo = 0;
        }
        inc = false;
      }
      if (dec) {
        if (oplfo > 0) {
          oplfo--;
        } else {
          oplfo = 16;
        }
        dec = false;
      }
      lcdkiir("GLO: LFO< MX2     ", "     " + String(lcdprint3(oplfo)) + "  " + String(lcdprint3( oplfo2max)) + "    ");
      break;
    case 23:
      if (inc) {
        if (oplfo2max < 127) {
          oplfo2max++;
        } else {
          oplfo2max = 0;
        }
        inc = false;
      }
      if (dec) {
        if (oplfo2max > 0) {
          oplfo2max--;
        } else {
          oplfo2max = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: LFO >MX2     ", "     " + String(lcdprint3(oplfo)) + "  " + String(lcdprint3( oplfo2max)) + "    ");
      break;
    case 24:
      if (inc) {
        if (oplfo4max < 127) {
          oplfo4max++;
        } else {
          oplfo4max = 0;
        }
        inc = false;
      }
      if (dec) {
        if (oplfo4max > 0) {
          oplfo4max--;
        } else {
          oplfo4max = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: MX4< MX6     ", "     " + String(lcdprint3(oplfo4max)) + "  " + String(lcdprint3( oplfo6max)) + "    ");
      break;
    case 25:
      if (inc) {
        if (oplfo6max < 127) {
          oplfo6max++;
        } else {
          oplfo6max = 0;
        }
        inc = false;
      }
      if (dec) {
        if (oplfo6max > 0) {
          oplfo6max--;
        } else {
          oplfo6max = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: MX4 >MX6     ", "     " + String(lcdprint3(oplfo4max)) + "  " + String(lcdprint3( oplfo6max)) + "    ");
      break;
    case 26:
      if (inc) {
        if (lfo2step < 32) {
          lfo2step++;
        } else {
          lfo2step = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo2step > 0) {
          lfo2step--;
        } else {
          lfo2step = 32;
        }
        dec = false;
      }
      lcdkiir("GLO: LS2< LS4     ", "     " + String(lcdprint3(lfo2step)) + "  " + String(lcdprint3( lfo4step)) + "    ");
      break;
    case 27:
      if (inc) {
        if (lfo4step < 32) {
          lfo4step++;
        } else {
          lfo4step = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo4step > 0) {
          lfo4step--;
        } else {
          lfo4step = 32;
        }
        dec = false;
      }
      lcdkiir("GLO: LS2 >LS4     ", "     " + String(lcdprint3(lfo2step)) + "  " + String(lcdprint3( lfo4step)) + "    ");
      break;
    case 28:
      if (inc) {
        if (lfo6step < 127) {
          lfo6step++;
        } else {
          lfo6step = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo6step > 0) {
          lfo6step--;
        } else {
          lfo6step = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: LS6< LS1     ", "     " + String(lcdprint3(lfo6step)) + "  " + String(lcdprint3(lfo1step)) + "    ");
      break;
    case 29:
      if (inc) {
        if (lfo1step < 127) {
          lfo1step++;
        } else {
          lfo1step = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo1step > 0) {
          lfo1step--;
        } else {
          lfo1step = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: LS6 >LS1     ", "     " + String(lcdprint3(lfo6step)) + "  " + String(lcdprint3(lfo1step)) + "    ");
      break;
    case 30:
      if (inc) {
        if (lfo1max < 127) {
          lfo1max++;
        } else {
          lfo1max = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo1max > 0) {
          lfo1max--;
        } else {
          lfo1max = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: MX1< MI1     ", "     " + String(lcdprint3(lfo1max)) + "  " + String(lcdprint3(lfo1min)) + "    ");
      break;
    case 31:
      if (inc) {
        if (lfo1min < 127) {
          lfo1min++;
        } else {
          lfo1min = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo1min > 0) {
          lfo1min--;
        } else {
          lfo1min = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: MX1 >MI1     ", "     " + String(lcdprint3(lfo1max)) + "  " + String(lcdprint3(lfo1min)) + "    ");
      break;
    case 32:
      if (inc) {
        if (eqvalue < 12192) {
          eqvalue += 96;
        } else {
          eqvalue = 0;
        }
        inc = false;
      }
      if (dec) {
        if (eqvalue > 0) {
          eqvalue -= 96;
        } else {
          eqvalue = 12192;
        }

        dec = false;
      }
      freq1 = (eqvalue / 123) * 100;
      freq2 = (127 - eqvalue / 99) * 100;
      lcdkiir("GLO:     EQ     ", "     " + String(lcdprint3(freq1 / 100)) + "  " + String(lcdprint3( freq2 / 100)) + "    ");
      break;
    case 33:
      if (inc) {
        if (reverblevel < 127) {
          reverblevel++;
        } else {
          reverblevel = 0;
        }
        inc = false;
      }
      if (dec) {
        if (reverblevel > 0) {
          reverblevel--;
        } else {
          reverblevel = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: CHRL< CHRT     ", "     " + String(lcdprint3(reverblevel)) + "  " + String(lcdprint3( reverbtime)) + "    ");
      break;
    case 34:
      if (inc) {
        if (choruslevel < 127) {
          choruslevel ++;
        } else {
          choruslevel = 0;
        }
        inc = false;
      }
      if (dec) {
        if (choruslevel > 0) {
          choruslevel --;
        } else {
          choruslevel = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: CHRL >CHRT     ", "     " + String(lcdprint3(reverblevel)) + "  " + String(lcdprint3( choruslevel)) + "    ");
      break;
    case 35:
      if (inc) {
        if (reverblevel2 < 127) {
          reverblevel2++;
        } else {
          reverblevel2 = 0;
        }
        inc = false;
      }
      if (dec) {
        if (reverblevel2 > 0) {
          reverblevel2--;
        } else {
          reverblevel2 = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: RLV2< RTM2     ", "     " + String(lcdprint3(reverblevel2)) + "   " + String(lcdprint3( reverbtime2)) + "    ");
      break;
    case 36:
      if (inc) {
        if (reverbtime2 < 3000) {
          reverbtime2 += 23;
        } else {
          reverbtime2 = 0;
        }
        inc = false;
      }
      if (dec) {
        if (reverbtime2 > 0) {
          reverbtime2 -= 23;
        } else {
          reverbtime2 = 3000;
        }
        dec = false;
      }
      lcdkiir("GLO: RLV2 >RTM2     ", "     " + String(lcdprint3(reverblevel2)) + "   " + String(lcdprint3( reverbtime2)) + "    ");
      break;

    case 37:
      if (inc) {
        if (lfo2freq < 127) {
          lfo2freq++;
        } else {
          lfo2freq = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo2freq > 0) {
          lfo2freq --;
        } else {
          lfo2freq = 127;
        }
        dec = false;
      }
      lcdkiir("GLO: LFQ2<       ", "     " + String(lcdprint3(lfo2freq)) + "      "  + "    ");
      break;


    case 38:
      if (inc) {
        if (gorbeszorzo < 127) {
          gorbeszorzo ++;
        } else {
          gorbeszorzo = 1;
        }
        inc = false;
      }
      if (dec) {
        if (gorbeszorzo > 1) {
          gorbeszorzo --;
        } else {
          gorbeszorzo = 127;
        }
        dec = false;
      }

      lcdkiir("GLO: TVA< LFO2     ", "     " + String(lcdprint3(gorbeszorzo)) + "   " + String(lcdprint3( lfo2volume)) + "    ");
      //tvainit();
      stepprogchanged = 17;
      break;

    case 39:
      if (inc) {
        if (lfo2volume < 127) {
          lfo2volume++;
        } else {
          lfo2volume = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo2volume > 0) {
          lfo2volume --;
        } else {
          lfo2volume = 127;
        }
        dec = false;
      }


      lcdkiir("GLO: TVA >LFO2       ", "     " + String(lcdprint3(gorbeszorzo)) + "   " + String(lcdprint3( lfo2volume)) + "    ");

      break;



    case 40:

      if (inc) {
        if (modulation < 10) {
          modulation++;
        } else {
          modulation = 1;
        }
        inc = false;
      }
      if (dec) {
        if (modulation > 0) {
          modulation--;
        } else {
          modulation = 10;
        }
        dec = false;
      }
      lcdkiir("MOD<       ", "      " + String(lcdprint3(modulation)) + "   " + String(lcdprint3(modulation)) + "    ");

      break;
    case 41:
 switch (opmenuoldal) {
  case 1:
      if (inc) {
        if (lep1  < 127) {
          lep1 ++;
        } else {
          lep1  = 13;
        }
        inc = false;
      }
      if (dec) {
        if (lep1  > 13) {
          lep1  --;
        } else {
          lep1  = 127;
        }
        dec = false;
      }
      lcdkiir("OP1: lep1<       ", "     " + String(lcdprint3(lep1 )) + "      "  + "    ");
      break;
       case 2:
      if (inc) {
        if (lep2  < 127) {
          lep2 ++;
        } else {
          lep2  = 13;
        }
        inc = false;
      }
      if (dec) {
        if (lep2  > 13) {
          lep2  --;
        } else {
          lep2  = 127;
        }
        dec = false;
      }
      lcdkiir("OP2: lep2<       ", "     " + String(lcdprint3(lep2 )) + "      "  + "    ");
      break;
       case 3:
      if (inc) {
        if (lep3  < 127) {
          lep3 ++;
        } else {
          lep3  = 13;
        }
        inc = false;
      }
      if (dec) {
        if (lep3  > 13) {
          lep3  --;
        } else {
          lep3  = 127;
        }
        dec = false;
      }
      lcdkiir("OP3: lep3<       ", "     " + String(lcdprint3(lep3 )) + "      "  + "    ");
      break;
       case 4:
      if (inc) {
        if (lep4  < 127) {
          lep4 ++;
        } else {
          lep4  = 13;
        }
        inc = false;
      }
      if (dec) {
        if (lep4  > 13) {
          lep4  --;
        } else {
          lep4  = 127;
        }
        dec = false;
      }
      lcdkiir("OP4: lep4<       ", "     " + String(lcdprint3(lep4 )) + "      "  + "    ");     
      break;
       case 5:
      if (inc) {
        if (lep5  < 127) {
          lep5 ++;
        } else {
          lep5  = 13;
        }
        inc = false;
      }
      if (dec) {
        if (lep5  > 13) {
          lep5  --;
        } else {
          lep5  = 127;
        }
        dec = false;
      }
      lcdkiir("OP5: lep5<       ", "     " + String(lcdprint3(lep5 )) + "      "  + "    ");
      break;
       case 6:
      if (inc) {
        if (lep6  < 127) {
          lep6 ++;
        } else {
          lep6  = 13;
        }
        inc = false;
      }
      if (dec) {
        if (lep6  > 13) {
          lep6  --;
        } else {
          lep6  = 127;
        }
        dec = false;
      }
      lcdkiir("OP6: lep6<       ", "     " + String(lcdprint3(lep6 )) + "      "  + "    ");
      break;
 }
      break;
    case 42:
      if (inc) {
        if (saveprog < 10) {
          saveprog++;
        } else {
          saveprog = 1;
        }
        inc = false;
      }
      if (dec) {
        if (saveprog > 0) {
          saveprog--;
        } else {
          saveprog = 10;
        }
        dec = false;
      }
      lcdkiir("Save: PRG<       ", "      " + String(lcdprint3(saveprog)) + "  " + savestring + "    ");
      break;

    case 43:
      if (inc) {
        if (savestring == "YES") {
          save();
          //programmentesfuggveny
          savestring = "NO";
        } else {
          savestring = "YES";
        }
        inc = false;
      }
      if (dec) {
        savestring = "NO";
        dec = false;
      }
      lcdkiir("Save: PRG >      ", "      " + String(lcdprint3(saveprog)) + "  " + savestring + "  ");
      break;


  }
}


void lcdkiirold(String szoveg, String Szoveg2) {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print(szoveg);
  lcd.setCursor(0, 1);
  lcd.print(Szoveg2);

}


String lcdprint2(int cc)
{
  String eredmeny = "";
  eredmeny += (cc % 100) / 10;
  eredmeny += cc % 10;
  return eredmeny;
}


/*
  void lcdprint4(int cc)
  {
  lcd.print(cc / 1000);
  lcd.print((cc % 1000) / 100);

  lcd.print((cc % 100) / 10);
  lcd.print(cc % 10);
  }
*/
String lcdprint3(int cc)
{
  String eredmeny = "";
  eredmeny += cc / 100;
  eredmeny += (cc % 100) / 10;
  eredmeny += cc % 10;
  return eredmeny;
}


String generatorkiir() {
  String szoveg2 = "w:";
  szoveg2 +=  String(op1waveform, HEX);
  szoveg2 +=  String(op2waveform, HEX);
  szoveg2 +=  String(op3waveform, HEX);
  szoveg2 +=  String(op4waveform, HEX);
  szoveg2 +=  String(op5waveform, HEX);
  szoveg2 +=  String(op6waveform, HEX);
  szoveg2 += "f:";
  if ( notefixedop1)
  {
    szoveg2 += 1;
  } else {
    szoveg2 += 0;
  }
  if ( notefixedop2)
  {
    szoveg2 += 1;
  } else {
    szoveg2 += 0;
  }
  if ( notefixedop3)
  {
    szoveg2 += 1;
  } else {
    szoveg2 += 0;
  }
  if ( notefixedop4)
  {
    szoveg2 += 1;
  } else {
    szoveg2 += 0;
  }
  if ( notefixedop5)
  {
    szoveg2 += 1;
  } else {
    szoveg2 += 0;
  }
  if ( notefixedop6)
  {
    szoveg2 += 1;
  } else {
    szoveg2 += 0;
  }
  return szoveg2;
}

String op1kiir() {
  String szoveg2 = "op1:";
  szoveg2 +=  String(op1ar, HEX);
  szoveg2 += " ";
  szoveg2 +=  String(op1al, HEX);
  szoveg2 += " ";
  szoveg2 +=  String(op1d1l, HEX);
  szoveg2 += " ";
  szoveg2 +=  String(op1d1r, HEX);
  szoveg2 += " ";
  szoveg2 +=  String(op1d2l, HEX);
  szoveg2 += " ";
  szoveg2 +=  String(op1d2r, HEX);
  szoveg2 += " ";
  szoveg2 +=  String(op1rl, HEX);
  szoveg2 += " ";
  szoveg2 +=  String(op1rr, HEX);
  return szoveg2;
}
