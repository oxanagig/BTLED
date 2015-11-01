#include "SRAM.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/mcc.h"

static inline void SRAMSetStartAddress(uint16_t);

void SRAM_Initialization(void)
{   
    deselectSRAM();
}

void SRAMStarWrite(uint16_t addr)
{
    selectSRAM();
    SRAMWriteByte(WRITE_COMMAND);    
    SRAMWriteByte((uint8_t)addr>>8);             /* Address MSB */   
    SRAMWriteByte((uint8_t)addr&0xFF);           /* Address LSB */
}

void SRAMStartRead(uint16_t addr)
{
    selectSRAM();
    SRAMWriteByte(WRITE_COMMAND);    
    SRAMWriteByte((uint8_t)addr>>8);             /* Address MSB */   
    SRAMWriteByte((uint8_t)addr&0xFF);           /* Address LSB */
}


void SRAMWriteSingleByte(uint16_t addr,uint8_t data)
{
    SRAMStarWrite(addr);
    SRAMWriteByte(data);
    deselectSRAM();
}

inline void SRAMWriteByte(uint8_t data)
{
    SPI_Exchange8bit(data);
}
