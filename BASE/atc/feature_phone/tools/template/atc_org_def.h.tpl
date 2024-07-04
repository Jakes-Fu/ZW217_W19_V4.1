/*******************************************************************************
 ** File Name:     atc_org_def.h                                                   *
 ** Author:        Steven.Yao                                                  *
 ** DATE:          04/11/2002                                                  *
 ** Copyright:     2001 Spreadtrum, Incoporated. All Rights Reserved.          *
 ** Description:   This file defines the AT commands, including basic commands *
 **                a extend commands.                                          *
 *******************************************************************************
                                                                               *
 *******************************************************************************
 **                         Edit History                                       *
 **----------------------------------------------------------------------------*
 ** DATE           NAME             DESCRIPTION                                *
 ** 04/11/2002     Steven.Yao       Create.                                    *
 ******************************************************************************/
#ifndef _ATC_DEF_H
#define _ATC_DEF_H

/* Define AT command index */
###atcbegin
#define AT_CMD_##atcnamenoplus    ##atcindex###atcend

#endif /* End of #ifndef _ATC_DEF_H */