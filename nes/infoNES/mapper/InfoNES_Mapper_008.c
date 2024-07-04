/*===================================================================*/
/*                                                                   */
/*                     Mapper 8 (FFE F3xxx)                          */
/*                                                                   */
/*===================================================================*/

/*-------------------------------------------------------------------*/
/*  Initialize Mapper 8                                              */
/*-------------------------------------------------------------------*/
void Map8_Init(Nes_Global_T *pGData)
{
  int nPage;

  /* Initialize Mapper */
  MapperInit = Map8_Init;

  /* Write to Mapper */
  MapperWrite = Map8_Write;

  /* Write to SRAM */
  MapperSram = Map0_Sram;

  /* Write to APU */
  MapperApu = Map0_Apu;

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
  if ( NesHeader.byVRomSize > 0 )
  {
    for ( nPage = 0; nPage < 8; ++nPage )
      pGData->PPUBANK[ nPage ] = VROMPAGE( nPage );
    InfoNES_SetupChr(pGData);
  }

  /* Set up wiring of the interrupt pin */
  K6502_Set_Int_Wiring( 1, 1 ); 
}

/*-------------------------------------------------------------------*/
/*  Mapper 8 Write Function                                          */
/*-------------------------------------------------------------------*/
void Map8_Write(Nes_Global_T *pGData, WORD wAddr, BYTE byData )
{
  BYTE byPrgBank = ( byData & 0xf8 ) >> 3;
  BYTE byChrBank = byData & 0x07;

  /* Set ROM Banks */
  byPrgBank <<= 1;
  byPrgBank %= ( NesHeader.byRomSize << 1 );

  pGData->ROMBANK0 = ROMPAGE( byPrgBank + 0 );
  pGData->ROMBANK1 = ROMPAGE( byPrgBank + 1 );

  /* Set PPU Banks */
  byChrBank <<= 3;
  byChrBank %= ( NesHeader.byVRomSize << 3 );

  pGData->PPUBANK[ 0 ] = VROMPAGE( byChrBank + 0 );
  pGData->PPUBANK[ 1 ] = VROMPAGE( byChrBank + 1 );
  pGData->PPUBANK[ 2 ] = VROMPAGE( byChrBank + 2 );
  pGData->PPUBANK[ 3 ] = VROMPAGE( byChrBank + 3 );
  pGData->PPUBANK[ 4 ] = VROMPAGE( byChrBank + 4 );
  pGData->PPUBANK[ 5 ] = VROMPAGE( byChrBank + 5 );
  pGData->PPUBANK[ 6 ] = VROMPAGE( byChrBank + 6 );
  pGData->PPUBANK[ 7 ] = VROMPAGE( byChrBank + 7 );
  InfoNES_SetupChr(pGData);
}
