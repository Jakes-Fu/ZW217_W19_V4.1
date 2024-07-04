
MCFLAG_OPT   	= -Otime


######################################################################################################
#                                MACRO DEFINITION
######################################################################################################

#-----------------------------------------------------------------------------------------------------
ifeq ($(strip $(MODEM_VT_SUPPORT)),TRUE)
MCFLAG_OPT	+= -D_H324_ADP_AVAILABLE_
endif
#-----------------------------------------------------------------------------------------------------





######################################################################################################
#                                INCLUDE PATH and SOURCE FILE
######################################################################################################

#-----------------------------------------------------------------------------------------------------

ifeq ($(strip $(PLATFORM)),	SC8800G)
MINCPATH +=  Third-party/Mplapi/include \
						 

MSRCPATH  =  MS_Ref/source/h324_adp/src

SOURCES	  =  h324_adp.c

endif
#-----------------------------------------------------------------------------------------------------