/*===================================================================*/
/*                                                                   */
/*                     Mapper 11 (Color Dreams)                      */
/*                                                                   */
/*===================================================================*/

/*-------------------------------------------------------------------*/
/*  Initialize Mapper 11                                             */
/*-------------------------------------------------------------------*/
void Map11_Init(Nes_Global_T *pGData)
{
  int nPage;

  /* Initialize Mapper */
  MapperInit = Map11_Init;

  /* Write to Mapper */
  MapperWrite = Map11_Write;

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

  /* Name Table Mirroring */
  InfoNES_Mirroring(pGData, 1 );

  /* Set up wiring of the interrupt pin */
  K6502_Set_Int_Wiring( 1, 1 ); 
}

/*-------------------------------------------------------------------*/
/*  Mapper 11 Write Function                                         */
/*-------------------------------------------------------------------*/
void Map11_Write(Nes_Global_T *pGData, WORD wAddr, BYTE byData )
{
  BYTE byPrgBank = ( byData & 0x01 ) << 2;
  BYTE byChrBank = ( ( byData & 0x70 ) >> 4 ) << 3;

  /* Set ROM Banks */
  pGData->ROMBANK0 = ROMPAGE( ( byPrgBank + 0 ) % ( NesHeader.byRomSize << 1 ) );
  pGData->ROMBANK1 = ROMPAGE( ( byPrgBank + 1 ) % ( NesHeader.byRomSize << 1 ) );
  pGData->ROMBANK2 = ROMPAGE( ( byPrgBank + 2 ) % ( NesHeader.byRomSize << 1 ) );
  pGData->ROMBANK3 = ROMPAGE( ( byPrgBank + 3 ) % ( NesHeader.byRomSize << 1 ) );

  /* Set PPU Banks */
  pGData->PPUBANK[ 0 ] = VROMPAGE( ( byChrBank + 0 ) % ( NesHeader.byVRomSize << 3 ) );
  pGData->PPUBANK[ 1 ] = VROMPAGE( ( byChrBank + 1 ) % ( NesHeader.byVRomSize << 3 ) );
  pGData->PPUBANK[ 2 ] = VROMPAGE( ( byChrBank + 2 ) % ( NesHeader.byVRomSize << 3 ) );
  pGData->PPUBANK[ 3 ] = VROMPAGE( ( byChrBank + 3 ) % ( NesHeader.byVRomSize << 3 ) );
  pGData->PPUBANK[ 4 ] = VROMPAGE( ( byChrBank + 4 ) % ( NesHeader.byVRomSize << 3 ) );
  pGData->PPUBANK[ 5 ] = VROMPAGE( ( byChrBank + 5 ) % ( NesHeader.byVRomSize << 3 ) );
  pGData->PPUBANK[ 6 ] = VROMPAGE( ( byChrBank + 6 ) % ( NesHeader.byVRomSize << 3 ) );
  pGData->PPUBANK[ 7 ] = VROMPAGE( ( byChrBank + 7 ) % ( NesHeader.byVRomSize << 3 ) );
  InfoNES_SetupChr(pGData);
}