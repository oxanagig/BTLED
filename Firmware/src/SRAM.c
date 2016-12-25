#include "SRAM.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/mcc.h"
#include "LED.h"

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
    SRAMWriteByte(READ_COMMAND);    
    SRAMWriteByte((uint8_t)addr>>8);             /* Address MSB */   
    SRAMWriteByte((uint8_t)addr&0xFF);           /* Address LSB */
}


void SRAMWriteSingleByte(uint16_t addr,uint8_t data)
{
    SRAMStarWrite(addr);
    SRAMWriteByte(data);
    deselectSRAM();
}

bool SRAM_Test(void)
{
    uint16_t i;
    uint8_t receivedBtye;
    SRAMStarWrite(0x00);
    for(i=0;i<NUMBER_OF_LED*3;i++)
        SRAMWriteByte((uint8_t)i+1);
    deselectSRAM();
    
    __delay_ms(500);
    SRAMStartRead(0x00);
    receivedBtye = SPI_Exchange8bit(0x00);
    for(i=1;i<NUMBER_OF_LED*3;i++)
    {
        receivedBtye = SPI_Exchange8bit((uint8_t)receivedBtye);
        if((receivedBtye+1) != (uint8_t)i)
        {
            deselectSRAM();
            return false;
        }
    }
 
    return true;
}

inline uint8_t SRAMWriteByte(uint8_t data)
{
    return SPI_Exchange8bit(data);
}
