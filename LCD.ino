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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP1", "AR = " + String(lcdprint3(op1ar)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP2", "AR = " + String(lcdprint3(op2ar)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP3", "AR = " + String(lcdprint3(op3ar)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP4", "AR = " + String(lcdprint3(op4ar)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP5", "AR = " + String(lcdprint3(op5ar)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP6", "AR = " + String(lcdprint3(op6ar)) + "        ");


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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " PCH", "PICHAR = " + String(lcdprint3(pichar)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP1", "AL = " + String(lcdprint3(op1al)) + "        ");

          break;
        case 2:
          //op2al

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP2", "AL = " + String(lcdprint3(op2al)) + "        ");

          break;
        case 3:
          //op3al

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP3", "AL = " + String(lcdprint3(op3al)) + "        ");

          break;
        case 4:
          //op4al

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP4", "AL = " + String(lcdprint3(op4al)) + "        ");

          break;
        case 5:
          //op5al

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP5", "AL = " + String(lcdprint3(op5al)) + "        ");

          break;
        case 6:
          //op6al

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP6", "PICHAL = " + String(lcdprint3(op6al)) + "        ");

          break;
        case 7:
          //pichal

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " PCH", "AL = " + String(lcdprint3(pichal)) + "        ");
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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP1", "D1L = " + String(lcdprint3(op1d1l)) + "        ");


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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP2", "D1L = " + String(lcdprint3(op2d1l)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP3", "D1L = " + String(lcdprint3(op3d1l)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP4", "D1L = " + String(lcdprint3(op4d1l)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP5", "D1L = " + String(lcdprint3(op5d1l)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP6", "D1L = " + String(lcdprint3(op6d1l)));

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " PCH", "PICHD1L = " + String(lcdprint3(pichd1l)));

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP1", "D1R = " + String(lcdprint3(op1d1r)) + "        ");


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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP2", "D1R = " + String(lcdprint3(op2d1r)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP3", "D1R = " + String(lcdprint3(op3d1r)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP4", "D1R = " + String(lcdprint3(op4d1r)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP5", "D1R = " + String(lcdprint3(op5d1r)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP6", "D1R = " + String(lcdprint3(op6d1r)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " PCH", "PICHD1R = " + String(lcdprint3(pichd1r)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP1", "D2L = " + String(lcdprint3(op1d2l)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP2", "D2L = " + String(lcdprint3(op2d2l)) + "        ");

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


          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP3", "D2L = " + String(lcdprint3(op3d2l)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP4", "D2L = " + String(lcdprint3(op4d2l)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP5", "D2L = " + String(lcdprint3(op5d2l)) + "        ");
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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP6", "D2L = " + String(lcdprint3(op6d2l)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " PCH", "PICHD2L = " + String(lcdprint3(pichd2l)) + "        ");
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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP1", "D2R = " + String(lcdprint3(op1d2r)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP2", "D2R = " + String(lcdprint3(op2d2r)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP3", "D2R = " + String(lcdprint3(op3d2r)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP4", "D2R = " + String(lcdprint3(op4d2r)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP5", "D2R = " + String(lcdprint3(op5d2r)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP6", "D2R = " + String(lcdprint3(op6d2r)) + "        ");
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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " PCH", "PICHD2R = " + String(lcdprint3(pichd2r)) + "        ");

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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP1", "RR = " + String(lcdprint3(op1rr)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP2", "RR = " + String(lcdprint3(op2rr)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP3", "RR = " + String(lcdprint3(op3rr)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP4", "RR = " + String(lcdprint3(op4rr)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP5", "RR = " + String(lcdprint3(op5rr)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP6", "RR = " + String(lcdprint3(op6rr)));


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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " PCH", "PICHRR = " + String(lcdprint3(pichrr)));

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP1", "RL = " + String(lcdprint3(op1rl)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP2", "RL = " + String(lcdprint3(op2rl)) + "        ");


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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP3", "RL = " + String(lcdprint3(op3rl)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP4", "RL = " + String(lcdprint3(op4rl)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP5", "RL = " + String(lcdprint3(op5rl)) + "        ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP6", "RL = " + String(lcdprint3(op6rl)) + "        ");

          break;
        case 7:
          //pichrr
          if (inc) {
            if (pichrr < 127) {
              pichrr++;
            } else {
              pichrr = 1;
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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " PCH", "PICHRL = " + String(lcdprint3(pichrl)) + "        ");

          break;
      }
      break;
    case 10:
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (op1veloc < 32) {
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
              op1veloc = 32;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP1", "VELOCITY = " + lcdprint3(op1veloc) + "  ");
          break;
        case 2:
          if (inc) {
            if (op2veloc < 32) {
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
              op2veloc = 32;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP2", "VELOCITY = " + lcdprint3(op2veloc) + "  ");
          break;
        case 3:
          if (inc) {
            if (op3veloc < 32) {
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
              op3veloc = 32;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP3", "VELOCITY = " + lcdprint3(op3veloc) + "  ");
          break;
        case 4:
          if (inc) {
            if (op4veloc < 32) {
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
              op4veloc = 32;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP4", "VELOCITY = " + lcdprint3(op4veloc) + "  ");
          break;
        case 5:
          if (inc) {
            if (op5veloc < 32) {
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
              op5veloc = 32;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP5", "VELOCITY = " + lcdprint3(op5veloc) + "  ");
          break;
        case 6:
          if (inc) {
            if (op6veloc < 32) {
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
              op6veloc = 32;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "VELOCITY = " + lcdprint3(op6veloc) + "  ");
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "VELOCITY = " + lcdprint3(op1veloc) + "  ");
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
          op1volume = op1volumeorig;
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP1", "OPVOLUME = " + lcdprint3(op1volume) + "        ");

          break;
        case 2:
          if (inc) {
            if (op2volumeorig < 127) {
              op2volumeorig++;
            } else {
              op2volumeorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2volumeorig > 0) {
              op2volume--;
            } else {
              op2volumeorig = 127;
            }
            dec = false;
          }
          op2volume = op2volumeorig;
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP2", "OPVOLUME = " + lcdprint3(op2volume) + "        ");

          break;
        case 3:
          if (inc) {
            if (op3volumeorig < 127) {
              op3volumeorig++;
            } else {
              op3volumeorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3volumeorig > 0) {
              op3volumeorig--;
            } else {
              op3volumeorig = 127;
            }
            dec = false;
          }
          op3volume = op3volumeorig;

          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP3", "OPVOLUME = " + lcdprint3(op3volume) + "        ");

          break;
        case 4:
          if (inc) {
            if (op4volumeorig < 127) {
              op4volumeorig++;
            } else {
              op4volumeorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4volumeorig > 0) {
              op4volumeorig--;
            } else {
              op4volumeorig = 127;
            }
            dec = false;
          }
          op4volume = op4volumeorig;

          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP4", "OPVOLUME = " + lcdprint3(op4volume) + "        ");


          break;
        case 5:
          if (inc) {
            if (op5volumeorig < 127) {
              op5volumeorig++;
            } else {
              op5volumeorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5volumeorig > 0) {
              op5volumeorig--;
            } else {
              op5volumeorig = 127;
            }
            dec = false;
          }
          op5volume = op5volumeorig;
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP5", "OPVOLUME = " + lcdprint3(op5volume) + "        ");

          break;
        case 6:
          if (inc) {
            if (op6volumeorig < 127) {
              op6volumeorig++;
            } else {
              op6volumeorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6volumeorig > 0) {
              op6volumeorig--;
            } else {
              op6volumeorig = 127;
            }
            dec = false;
          }
          op6volume = op6volumeorig;
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "OPVOLUME = " + lcdprint3(op6volume) + "        ");

          break;
        case 7:

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
          op1generatorfreq = op1generatorfreqorig;

          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP1", "FREQ = " + lcdprint3(op1generatorfreqorig) + "      ");
          break;
        case 2:
          if (inc) {
            if (op2generatorfreqorig < 127) {
              op2generatorfreqorig++;
            } else {
              op2generatorfreqorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2generatorfreqorig > 0) {
              op2generatorfreqorig--;
            } else {
              op2generatorfreqorig = 127;
            }
            dec = false;
          }
          op2generatorfreq = op2generatorfreqorig;
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP2", "FREQ = " + lcdprint3(op2generatorfreqorig) + "      ");
          break;
        case 3:
          if (inc) {
            if (op3generatorfreqorig < 127) {
              op3generatorfreqorig++;
            } else {
              op3generatorfreqorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3generatorfreqorig > 0) {
              op3generatorfreqorig--;
            } else {
              op3generatorfreqorig = 127;
            }
            dec = false;
          }
          op3generatorfreq = op3generatorfreqorig;
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP3", "FREQ = " + lcdprint3(op3generatorfreqorig) + "      ");
          break;
        case 4:
          if (inc) {
            if (op4generatorfreqorig < 127) {
              op4generatorfreqorig++;
            } else {
              op4generatorfreqorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4generatorfreqorig > 0) {
              op4generatorfreqorig--;
            } else {
              op4generatorfreqorig = 127;
            }
            dec = false;
          }
          op4generatorfreq = op4generatorfreqorig;
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP4", "FREQ = " + lcdprint3(op4generatorfreqorig) + "      ");
          break;
        case 5:
          if (inc) {
            if (op5generatorfreqorig < 127) {
              op5generatorfreqorig++;
            } else {
              op5generatorfreqorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5generatorfreqorig > 0) {
              op5generatorfreqorig--;
            } else {
              op5generatorfreqorig = 127;
            }
            dec = false;
          }
          op5generatorfreq = op5generatorfreqorig;
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP5", "FREQ = " + lcdprint3(op5generatorfreqorig) + "      ");
          break;
        case 6:
          if (inc) {
            if (op6generatorfreqorig < 127) {
              op6generatorfreqorig++;
            } else {
              op6generatorfreqorig = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6generatorfreqorig > 0) {
              op6generatorfreqorig--;
            } else {
              op6generatorfreqorig = 127;
            }
            dec = false;
          }
          op6generatorfreq = op6generatorfreqorig;
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "FREQ = " + lcdprint3(op6generatorfreqorig) + "      ");
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP1", "NOTESET = " + lcdprint3(0) + "      ");
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
            case 10: wavestring = "NOISE 2     "; break;
            case 11: wavestring = "DOUBLE SINE "; break;
            case 12: wavestring = "TRIPLE SINE "; break;
            case 13: wavestring = "USER WAVE 1 "; break;
            case 14: wavestring = "USER WAVE 2 "; break;
            case 15: wavestring = "USER WAVE 3 "; break;
            case 16: wavestring = "USER WAVE 4 "; break;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP1", "    " + wavestring);

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
            case 10: wavestring = "NOISE 2     "; break;
            case 11: wavestring = "DOUBLE SINE "; break;
            case 12: wavestring = "TRIPLE SINE "; break;
            case 13: wavestring = "USER WAVE 1 "; break;
            case 14: wavestring = "USER WAVE 2 "; break;
            case 15: wavestring = "USER WAVE 3 "; break;
            case 16: wavestring = "USER WAVE 4 "; break;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP2", "    " + wavestring);
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
            case 10: wavestring = "NOISE 2     "; break;
            case 11: wavestring = "DOUBLE SINE "; break;
            case 12: wavestring = "TRIPLE SINE "; break;
            case 13: wavestring = "USER WAVE 1 "; break;
            case 14: wavestring = "USER WAVE 2 "; break;
            case 15: wavestring = "USER WAVE 3 "; break;
            case 16: wavestring = "USER WAVE 4 "; break;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP3", "    " + wavestring);
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
            case 10: wavestring = "NOISE 2     "; break;
            case 11: wavestring = "DOUBLE SINE "; break;
            case 12: wavestring = "TRIPLE SINE "; break;
            case 13: wavestring = "USER WAVE 1 "; break;
            case 14: wavestring = "USER WAVE 2 "; break;
            case 15: wavestring = "USER WAVE 3 "; break;
            case 16: wavestring = "USER WAVE 4 "; break;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP4", "    " + wavestring);
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
            case 10: wavestring = "NOISE 2     "; break;
            case 11: wavestring = "DOUBLE SINE "; break;
            case 12: wavestring = "TRIPLE SINE "; break;
            case 13: wavestring = "USER WAVE 1 "; break;
            case 14: wavestring = "USER WAVE 2 "; break;
            case 15: wavestring = "USER WAVE 3 "; break;
            case 16: wavestring = "USER WAVE 4 "; break;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP5", "    " + wavestring);
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
            case 10: wavestring = "NOISE 2     "; break;
            case 11: wavestring = "DOUBLE SINE "; break;
            case 12: wavestring = "TRIPLE SINE "; break;
            case 13: wavestring = "USER WAVE 1 "; break;
            case 14: wavestring = "USER WAVE 2 "; break;
            case 15: wavestring = "USER WAVE 3 "; break;
            case 16: wavestring = "USER WAVE 4 "; break;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "    " + wavestring);
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "                ");
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

          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP1", "FREQFIX = " + lcdprint3(op1generatorfreqfix >> 4) + "      ");
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP2", "FREQFIX = " + lcdprint3(op2generatorfreqfix >> 4) + "      ");
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP3", "FREQFIX = " + lcdprint3(op3generatorfreqfix >> 4) + "      ");
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP4", "FREQFIX = " + lcdprint3(op4generatorfreqfix >> 4) + "      ");
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP5", "FREQFIX = " + lcdprint3(op5generatorfreqfix >> 4) + "      ");
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "FREQFIX = " + lcdprint3(op6generatorfreqfix >> 4) + "      ");
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "PICHOP = " + lcdprint3(pichop6) + "    ");

          pichgorbeinit();
          break;
      }
      break;

    case 16:
      if (inc) {
        if (feedback_level < 127) {
          feedback_level++;
        } else {
          feedback_level = 0;
        }
        inc = false;
      }
      if (dec) {
        if (feedback_level >= 0) {
          feedback_level--;
        } else {
          feedback_level = 127;
        }
        dec = false;
      }
      lcdkiir("FEEDBACK LEVEL  ", lcdprint3(feedback_level + 10) + "             ");
      break;

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
      lcdkiir("Alg" + String("FREQ DIV        "), String(lcdprint3(szorzo)) + "             ");
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
          lcdkiir(String(lcdprint2(alg)) + "       [5]-(6)", " [1]-(2)-(3)-(4)");
          break;
        case 2:
          lcdkiir(String(lcdprint2(alg)) + "       [5]-(6)", " [1]-(2) [3]-(4)");
          break;
        case 3:
          lcdkiir(String(lcdprint2(alg)) + "   [4]-(5)-(6)", "     [1]-(2)-(3)");
          break;
        case 4:
          lcdkiir(String(lcdprint2(alg)) + "  /(2)    /(5)", " [1]-(3) [4]-(6)");
          break;
        case 5:
          lcdkiir(String(lcdprint2(alg)) + "   <<5>>-{{6}}   ", "     <PWM OP1>  ");
          break;
        case 6:
          lcdkiir(String(lcdprint2(alg)) + "   [4] [5] [6]", "     [1] [2] [3]    ");
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
      lcdkiir("OUTPUT LEVEL", lcdprint3(level) + "             ");
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
      //detune
      switch (opmenuoldal) {
        case 1:
          if (inc) {
            if (op1detune < 127) {
              op1detune++;
            } else {
              op1detune = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op1detune > 0) {
              op1detune--;
            } else {
              op1detune = 127;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP1", "DETUNE = " + lcdprint3(op1detune >> 12)+ "    ");

          break;
        case 2:
          if (inc) {
            if (op2detune < 127) {
              op2detune++;
            } else {
              op2detune = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op2detune > 0) {
              op2detune--;
            } else {
              op2detune = 127;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP2", "DETUNE = " + lcdprint3(op2detune >> 12)+ "    ");

          break;
        case 3:
          if (inc) {
            if (op3detune < 127) {
              op3detune++;
            } else {
              op3detune = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op3detune > 0) {
              op3detune--;
            } else {
              op3detune = 127;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP3", "DETUNE = " + lcdprint3(op3detune >> 12)+ "    ");


          break;
        case 4:
          if (inc) {
            if (op4detune < 127) {
              op4detune++;
            } else {
              op4detune = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op4detune > 0) {
              op4detune--;
            } else {
              op4detune = 127;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP4", "DETUNE = " + lcdprint3(op4detune >> 12)+ "    ");

          break;
        case 5:
          if (inc) {
            if (op5detune < 127) {
              op5detune++;
            } else {
              op5detune = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op5detune > 0) {
              op5detune--;
            } else {
              op5detune = 127;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP5", "DETUNE = " + lcdprint3(op5detune >> 12)+ "    ");

          break;
        case 6:
          if (inc) {
            if (op6detune < 127) {
              op6detune++;
            } else {
              op6detune = 0;
            }
            inc = false;
          }
          if (dec) {
            if (op6detune > 0) {
              op6detune--;
            } else {
              op6detune = 127;
            }
            dec = false;
          }
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "DETUNE = " + lcdprint3(op6detune >> 12) + "    ");
          break;
        case 7:
          //notset
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " PICH", "NOTSET = " + String(lcdprint3(0)));

          break;
      }
      break;
    case 23:
      switch (opmenuoldal) {
        case 1:
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP1", "PICHOP = " + lcdprint3(pichop1) + "    ");
          break;
        case 2:
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP2", "PICHOP = " + lcdprint3(pichop2) + "    ");
          break;
        case 3:
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP3", "PICHOP = " + lcdprint3(pichop3) + "    ");
          break;
        case 4:
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP4", "PICHOP = " + lcdprint3(pichop4) + "    ");
          break;
        case 5:
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP5", "PICHOP = " + lcdprint3(pichop5) + "    ");
          break;
        case 6:
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
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "PICHOP = " + lcdprint3(pichop6) + "    ");
          break;
      }
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

      lcdkiir(String("REVERB DIFFUSION"), String(lcdprint3(eqvalue)) + "             ");
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

      lcdkiir(String("REVERB LEVEL    "), String(lcdprint3(reverblevel)) + "             ");
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
      lcdkiir(String("CHORUS LEVEL   "), String(lcdprint3(choruslevel)) + "             ");
      break;
    case 35:
      if (inc) {
        if (chorusfreq < 127) {
          chorusfreq++;
        } else {
          chorusfreq = 0;
        }
        inc = false;
      }
      if (dec) {
        if (chorusfreq > 0) {
          chorusfreq--;
        } else {
          chorusfreq = 127;
        }
        dec = false;
      }
      lcdkiir(String("CHORUS FREQ     "), String(lcdprint3(chorusfreq)) + "             ");

      break;
    case 36:
      if (inc) {
        if (pichkezd < 3000) {
          pichkezd += 23;
        } else {
          pichkezd = 0;
        }
        inc = false;
      }
      if (dec) {
        if (pichkezd > 0) {
          pichkezd -= 23;
        } else {
          pichkezd = 3000;
        }
        dec = false;
      }
      lcdkiir(String("PICH BEGIN      "), String(lcdprint3(pichkezd)) + "             ");
      pichgorbeinit();
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
      lcdkiir(String("OP LEVEL        "), lcdprint3(gorbeszorzo) + "        (007)");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP1", "STEP BIT = " + String(lcdprint3(lep1)) + "  ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP2", "STEP BIT = " + String(lcdprint3(lep2)) + "  ");

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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP3", "STEP BIT = " + String(lcdprint3(lep3)) + "  ");
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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP4", "STEP BIT = " + String(lcdprint3(lep4)) + "  ");
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
          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP5", "STEP BIT = " + String(lcdprint3(lep5)) + "  ");
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

          lcdkiir("Alg" + String(lcdprint2(alg)) + " " + ops + " OP6", "STEP BIT = " + String(lcdprint3(lep6)) + "  ");
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
