// IRVitek.h Written by Igor Ovchinnikov 17/07/2016
// Команды 48 кнопочного пульта DVD Vitek

// #include <IRremote.h> //В заголовок основного файла

//int RECV_PIN = 12;        //В заголовок основного файла
//IRrecv irrecv(RECV_PIN);  //В заголовок основного файла
//decode_results results;   //В заголовок основного файла

//irrecv.enableIRIn(); // Это в Setup

unsigned int AskVitekIR(void)
{
 unsigned int ulRetVal=0;
 if (irrecv.decode(&results))
  { 
    switch(results.value)
     {
      case 16742535: {ulRetVal=47; break;} // "On/Off"
      case 16726725: {ulRetVal=48; break;} // "Open/Close");
      case 16734375: {ulRetVal= 1; break;} // "1"
      case 16775175: {ulRetVal= 2; break;} // "2"
      case 16718565: {ulRetVal= 3; break;} // "3"
      case 16738455: {ulRetVal= 4; break;} // "4"
      case 16767015: {ulRetVal= 5; break;} // "5"
      case 16722645: {ulRetVal= 6; break;} // "6"
      case 16730295: {ulRetVal= 7; break;} // "7"
      case 16771095: {ulRetVal= 8; break;} // "8"
      case 16714485: {ulRetVal= 9; break;} // "9"
      case 16740495: {ulRetVal=10; break;} // "10/0"
      case 16762935: {ulRetVal=11; break;} // "10+"
      case 16724685: {ulRetVal=12; break;} // "GOTO"
      case 16732335: {ulRetVal=13; break;} // "<<"
      case 16773135: {ulRetVal=14; break;} // "||"
      case 16764975: {ulRetVal=15; break;} // "Stop"
      case 16716525: {ulRetVal=16; break;} // ">>"
      case 16736415: {ulRetVal=17; break;} // "|<<"
      case 16769055: {ulRetVal=18; break;} // "Play"
      case 16720605: {ulRetVal=19; break;} // ">>|"
      case 16760895: {ulRetVal=20; break;} // "^"
      case 16728255: {ulRetVal=21; break;} // "<"
      case 16775685: {ulRetVal=22; break;} // "Enter"
      case 16712445: {ulRetVal=23; break;} // ">"
      case 16743045: {ulRetVal=24; break;} // "v"
      case 16759365: {ulRetVal=25; break;} // "Setup"
      case 16726215: {ulRetVal=26; break;} // "Zoom"
      case 16751205: {ulRetVal=27; break;} // "Language"
      case 16734885: {ulRetVal=28; break;} // "Subtitle"
      case 16767525: {ulRetVal=29; break;} // "Angle"
      case 16718055: {ulRetVal=30; break;} // "N/P"
      case 16755285: {ulRetVal=31; break;} // "Return"
      case 16738965: {ulRetVal=32; break;} // "MUTE"
      case 16771605: {ulRetVal=33; break;} // "-"
      case 16722135: {ulRetVal=34; break;} // "+"
      case 16747125: {ulRetVal=35; break;} // "MENU"
      case 16730805: {ulRetVal=36; break;} // "Title"
      case 16763445: {ulRetVal=37; break;} // "PBC"
      case 16713975: {ulRetVal=38; break;} // "Display"
      case 16757325: {ulRetVal=39; break;} // "Slow"
      case 16741005: {ulRetVal=40; break;} // "L/R"
      case 16773645: {ulRetVal=41; break;} // "Repeat"
      case 16724175: {ulRetVal=42; break;} // "A-B"
      case 16749165: {ulRetVal=43; break;} // "Step"
      case 16732845: {ulRetVal=44; break;} // "Video"
      case 16765485: {ulRetVal=45; break;} // "PROG"
      case 16716015: {ulRetVal=46; break;} // "RAN"
      case 4294967295: {ulRetVal=50; break;} // "Cycle"
     }
//    ulRetVal=results.value;
    irrecv.resume();
  }
 return ulRetVal;
}
