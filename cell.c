#include  <xc.h>
#include "pins.h"
#include "types.h"

uint32 curCellReading = 0;   // weight

void initCell(void) {
  CELL_CLK_LAT   = 0;    // clk is nornmally low
  CELL_CLK_TRIS  = 0;
  CELL_DATA_TRIS = 1;
}

void checkCell(void) {
  if(!CELL_DATA_PIN) {
    uint32 bufIn = 0;
    for (int i=0; i<24; i++) {
      CELL_CLK_LAT = 1;
      bufIn <<= 1;;  // a little delay
      CELL_CLK_LAT = 0;
      
      if(CELL_DATA_PIN) {
        CELL_DATA_TRIS = 1; // dummy for DEBUG
      }
      
      bufIn |= CELL_DATA_PIN;
    }
    GIE=0;
    curCellReading = bufIn;
    // 25th pulse sets data return to default high
    // and signals using chan A with gain 128
    CELL_CLK_LAT = 1; 
    GIE=1;
    CELL_CLK_LAT = 0;
  }
}
