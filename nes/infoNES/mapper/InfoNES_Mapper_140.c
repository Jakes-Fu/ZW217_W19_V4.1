/*===================================================================*/
/*                                                                   */
/*                          Mapper 140                               */
/*                                                                   */
/*===================================================================*/

/*-------------------------------------------------------------------*/
/*  Initialize Mapper 140                                            */
/*-------------------------------------------------------------------*/
void Map140_Init(Nes_Global_T *pGData)
{
  /* Initialize Mapper */
  MapperInit = Map0_Init;

  /* Write to Mapper */
  MapperWrite = Map0_Write;

  /* Write to SRAM */
  MapperSram = Map140_Sram;

  /* Write to APU */
  MapperApu = Map140_Apu;

  /* Read from APU */
  MapperReadApu = Map0_ReadApu;

  /* Callback at VSync */
  MapperVSync = Map0_VSync;

  /* Callback at HSync */
  MapperHSync = Map0_HSync;

  /* Callback at PPU */
  MapperPPU = Map0_PPU;

  /* Callback at Rendering Screen ( 1:BG, 0:Sprite ) */
  MapperRenderScreen = Map0_RenderScreen;

  /* Set SRAM Banks */
  pGData->SRAMBANK = pGData->SRAM;


  /* Set ROM Banks */
  pGData->ROMBANK0 = ROMPAGE( 0 );
  pGData->ROMBANK1 = ROMPAGE( 1 );
  pGData->ROMBANK2 = ROMPAGE( 2 );
  pGData->ROMBANK3 = ROMPAGE( 3 );

  /* Set PPU Banks */
  if ( NesHeader.byVRomSize > 0 ) {
    int nPage; for( nPage = 0; nPage < 8; ++nPage )
      pGData->PPUBANK[ nPage ] = VROMPAGE( nPage );
    InfoNES_SetupChr(pGData);
  }

  /* Set up wiring of the interrupt pin */
  K6502_Set_Int_Wiring( 1, 1 ); 
}

/*-------------------------------------------------------------------*/
/*  Mapper 140 Write to SRAM Function                                */
/*-------------------------------------------------------------------*/
void Map140_Sram(Nes_Global_T *pGData, WORD wAddr, BYTE byData )
{
  Map140_Apu(pGData, wAddr, byData );
}

/*-------------------------------------------------------------------*/
/*  Mapper 140 Write to APU Function                                 */
/*-------------------------------------------------------------------*/
void Map140_Apu(Nes_Global_T *pGData, WORD wAddr, BYTE byData )
{
  /* Set ROM Banks */
  pGData->ROMBANK0 = ROMPAGE( (((byData&0xF0)>>2) + 0 ) % (NesHeader.byRomSize << 1) );
  pGData->ROMBANK1 = ROMPAGE( (((byData%0xF0)>>2) + 1 ) % (NesHeader.byRomSize << 1) );
  pGData->ROMBANK2 = ROMPAGE( (((byData%0xF0)>>2) + 2 ) % (NesHeader.byRomSize << 1) );
  pGData->ROMBANK3 = ROMPAGE( (((byData%0xF0)>>2) + 3 ) % (NesHeader.byRomSize << 1) );

  /* Set PPU Banks */
  pGData->PPUBANK[ 0 ] = VROMPAGE( (((byData&0x0F)<<3) + 0) % (NesHeader.byVRomSize << 3) );
  pGData->PPUBANK[ 1 ] = VROMPAGE( (((byData&0x0F)<<3) + 1) % (NesHeader.byVRomSize << 3) );
  pGData->PPUBANK[ 2 ] = VROMPAGE( (((byData&0x0F)<<3) + 2) % (NesHeader.byVRomSize << 3) );
  pGData->PPUBANK[ 3 ] = VROMPAGE( (((byData&0x0F)<<3) + 3) % (NesHeader.byVRomSize << 3) );
  pGData->PPUBANK[ 4 ] = VROMPAGE( (((byData&0x0F)<<3) + 4) % (NesHeader.byVRomSize << 3) );
  pGData->PPUBANK[ 5 ] = VROMPAGE( (((byData&0x0F)<<3) + 5) % (NesHeader.byVRomSize << 3) );
  pGData->PPUBANK[ 6 ] = VROMPAGE( (((byData&0x0F)<<3) + 6) % (NesHeader.byVRomSize << 3) );
  pGData->PPUBANK[ 7 ] = VROMPAGE( (((byData&0x0F)<<3) + 7) % (NesHeader.byVRomSize << 3) );
  InfoNES_SetupChr(pGData);
}