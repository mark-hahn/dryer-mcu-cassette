
#ifndef COMMAND_H
#define	COMMAND_H
 
#define NUM_OPT_BYTES_IO 30  // arduino buffer is only 32 bytes

// first byte is packet length
// commands (second byte))
#define CMD_CLR_ERR       1  // 2 bytes
#define CMD_RESET_BOARD   2  // 2 bytes
//#define CMD_SET_HTR     3  // 4 bytes -- 0 to 1023
//#define CMD_SET_FAN     4  // 4 bytes -- 0 to 1023
//#define CMD_SET_FLAP    5  // 3 bytes -- 0: beads to 255: filament
//#define CMD_BEEP        6  // 4 bytes -- ms

#define CMD_SET_OPTIONS0  10 // 32 bytes 
#define CMD_SET_OPTIONS1  11
#define CMD_SET_OPTIONS2  12
#define CMD_SET_OPTIONS3  13

#define CMD_CLR_ADDRS     15  // 2 bytes (sent to pseudo-broadcast addr)
#define CMD_SET_ADDR      16  // 3 bytes (assign addrs via daisy-chain)
                              //         (also sent to pseudo-broadcast addr)

// register (first byte returned)
#define REG_CHIPID        20  // 10 bytes
#define REG_ERROR         21  // 2 bytes
//#define REG_SENS        22  // 5 bytes: temp sensors on power boARD
#define REG_WEIGHT        23  // 4 bytes: cell load reading on cassette (24-bit))
#define REG_SWITCHES      24  // 2 bytes: run-out and jam switches on cassette

#define REG_OPTIONS0      30  // 31 bytes
#define REG_OPTIONS1      31
#define REG_OPTIONS2      32
#define REG_OPTIONS3      33
 
// error codes 
#define OVERFLOW_ERROR     1
#define RECV_BUF_ERROR     2
#define SEND_BUF_ERROR     3
#define REG_MISSING_ERROR  4
#define CMD_LEN_ERROR      5
#define WCOL_ERROR         6
#define INTERNAL_ERROR     7

extern volatile bool  haveCommand;
extern volatile uint8 curError;

void cmdInit(void);
void eventLoop (void);
void setError(uint8 err);
void setErrorInt(uint8 err);

#endif	/* COMMAND_H */

