/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:7/5/2021***********************************/
/***********version:1***************************************/
/***********************************************************/

/* Module includes */
#include "Rte.h"

                   /* Local Data Types */
typedef    uint8   PortStateType  ; 
typedef    uint8   PortDataType  ;
typedef    uint8   PortBtnstateType   ;
typedef    uint8   PortFlagType   ;

                    /* Local Macros */
#define INIT_VALUE    0X00
#define IDLE          0X00
#define BUSY          0X01


                          /* Rte Golable Variables */ 
						  
						  /* Btn Data Global variables */
static PortDataType Global_HeightData                       = INIT_VALUE ;
static PortDataType Global_SlideData                        = INIT_VALUE ;
static PortDataType Global_InclineData                      = INIT_VALUE ;
						  /* Btn state Global variables */
static PortBtnStateType Global_HeightBtnState                      = INIT_VALUE ;
static PortBtnStateType Global_SlideBtnState                        = INIT_VALUE ;
static PortBtnStateType Global_InclineBtnState                      = INIT_VALUE ;
						 /* data update flag Global variables */
static PortFlagType Global_HeightDataUpdateflag             = INIT_VALUE ;
static PortFlagType Global_SlideDataUpdateflag              = INIT_VALUE ;
static PortFlagType Global_InclineDataUpdateflag            = INIT_VALUE ;
                          /* Rte protection flag */
static PortStateType Global_HeightDataPortState                 = IDLE;
static PortStateType Global_SlideDataPortState                  = IDLE;
static PortStateType Global_InclineDataPortState                = IDLE;
static PortStateType Global_HeightBtnstatePortState             = IDLE;
static PortStateType Global_SlideBtnstatePortState              = IDLE;
static PortStateType Global_InclineBtnstatePortState            = IDLE;
static PortStateType Global_HeightDataFlagPortState             = IDLE;
static PortStateType Global_SlideDataFlagPortState              = IDLE;
static PortStateType Global_InclineDataFlagPortState            = IDLE;


/**************************************************************************/
/*                         HeightData Port                                */
/**************************************************************************/
Std_ReturnType Rte_ReadHeightData (uint8 *CtrlData)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
	if ( (Global_HeightDataPortState == IDLE) && (CtrlData != NULL_PTR))
	{
		/* Lock the port to write */
		Global_HeightDataPortState = BUSY ;
		/* Write the data to the port */
		 (*CtrlData) = Global_HeightData ; 
		/* Unlock the port after done writing */
		Global_HeightDataPortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
}
/**************************************************************************/
/*                         SlideData Port                                */
/**************************************************************************/
Std_ReturnType Rte_ReadSlideData (uint8 *CtrlData)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
	if ( (Global_SlideDataPortState == IDLE) && (CtrlData != NULL_PTR))
	{
		/* Lock the port to write */
		Global_SlideDataPortState = BUSY ;
		/* Write the data to the port */
		 (*CtrlData) = Global_SlideData ; 
		/* Unlock the port after done writing */
		Global_SlideDataPortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
}
/**************************************************************************/
/*                         Incline Data Port                                */
/**************************************************************************/
Std_ReturnType Rte_ReadSlideData (uint8 *CtrlData)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
	if ( (Global_InclineDataPortState == IDLE) && (CtrlData != NULL_PTR))
	{
		/* Lock the port to write */
		Global_InclineDataPortState = BUSY ;
		/* Write the data to the port */
		 (*CtrlData) = Global_InclineData ; 
		/* Unlock the port after done writing */
		Global_InclineDataPortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
}
/**************************************************************************/
/*                         Height Btn State Port                           */
/**************************************************************************/
Std_ReturnType Rte_WriteHeightBtnState(Srlf_SeatControlBtns BtnState)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
            	 /*protection process*/
	if (Global_HeightBtnstatePortState == IDLE)
	{
		   /* Lock the port to write */
		Global_HeightBtnstatePortState = BUSY ;
		/* Write the data to the port */
		Global_HeightBtnState = BtnState ; 
		/* Unlock the port after done writing */
		Global_HeightBtnstatePortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
	
}
/**************************End Of Function************************/
Std_ReturnType Rte_ReadHeightBtnState (Srlf_SeatControlBtns *BtnState)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
	if ( (Global_HeightBtnstatePortState == IDLE) && (BtnState != NULL_PTR))
	{
		/* Lock the port to write */
		Global_HeightBtnstatePortState = BUSY ;
		/* Write the data to the port */
		 (*BtnState) = Global_HeightBtnState ; 
		/* Unlock the port after done writing */
		Global_HeightBtnstatePortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
}
/**************************************************************************/
/*                         Slide BtnState Port                            */
/**************************************************************************/
Std_ReturnType Rte_WriteSlideBtnState (Srlf_SeatControlBtns BtnState)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
            	 /*protection process*/
	if (Global_SlideBtnstatePortState == IDLE)
	{
		   /* Lock the port to write */
		Global_SlideBtnstatePortState = BUSY ;
		/* Write the data to the port */
		Global_SlideBtnState = BtnState ; 
		/* Unlock the port after done writing */
		Global_SlideBtnstatePortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
	
	
}
/**************************End Of Function************************/
Std_ReturnType Rte_ReadSlideBtnState  (Srlf_SeatControlBtns *BtnState)
{
	
	Std_ReturnType Local_ReturnError = E_OK ;
	
	if ( (Global_SlideBtnstatePortState == IDLE) && (BtnState != NULL_PTR))
	{
		/* Lock the port to write */
		Global_SlideBtnstatePortState = BUSY ;
		/* Write the data to the port */
		 (*BtnState) = Global_SlideBtnState ; 
		/* Unlock the port after done writing */
		Global_SlideBtnstatePortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;	
}
/**************************************************************************/
/*                         Incline BtnState Port                           */
/**************************************************************************/
Std_ReturnType Rte_WriteInclineBtnState (Srlf_SeatControlBtns BtnState)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
            	 /*protection process*/
	if (Global_InclineBtnstatePortState == IDLE)
	{
		   /* Lock the port to write */
		Global_InclineBtnstatePortState = BUSY ;
		/* Write the data to the port */
		Global_InclineBtnState = BtnState ; 
		/* Unlock the port after done writing */
		Global_InclineBtnstatePortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
	
	
}
/**************************End Of Function************************/
Std_ReturnType Rte_ReadInclineBtnState  (Srlf_SeatControlBtns *BtnState)
{
	 
	Std_ReturnType Local_ReturnError = E_OK ;
	
	if ( (Global_InclineBtnstatePortState == IDLE) && (BtnState != NULL_PTR))
	{
		/* Lock the port to write */
		Global_InclineBtnstatePortState = BUSY ;
		/* Write the data to the port */
		 (*BtnState) = Global_InclineBtnState ; 
		/* Unlock the port after done writing */
		Global_InclineBtnstatePortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;	
		
}
/**************************************************************************/
/*                     HeightData Update flag Port                        */
/**************************************************************************/
Std_ReturnType Rte_WriteHeightCtrlDataUpdateflag (Flag_Update  CtrlDataFalg)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
            	 /*protection process*/
	if (Global_HeightDataFlagPortState == IDLE)
	{
		   /* Lock the port to write */
		Global_HeightDataFlagPortState = BUSY ;
		/* Write the data to the port */
		Global_HeightDataUpdateflag = CtrlDataFalg ; 
		/* Unlock the port after done writing */
		Global_HeightDataFlagPortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
	
	
}
/**************************End Of Function************************/
Std_ReturnType Rte_ReadHeightCtrlDataUpdateflag (Flag_Update *CtrlDataFalg);
{
	
	Std_ReturnType Local_ReturnError = E_OK ;
	
	if ( (Global_HeightDataFlagPortState == IDLE) && (CtrlDataFalg != NULL_PTR))
	{
		/* Lock the port to write */
		Global_HeightDataFlagPortState = BUSY ;
		/* Write the data to the port */
		 (*CtrlDataFalg) = Global_HeightDataUpdateflag ; 
		/* Unlock the port after done writing */
		Global_HeightDataFlagPortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
	
}
/**************************************************************************/
/*                         Slide Update flag Port                         */
/**************************************************************************/
Std_ReturnType Rte_WriteSlideCtrlDataUpdateflag (Flag_Update  CtrlDataFalg)
{
  Std_ReturnType Local_ReturnError = E_OK ;
	
            	 /*protection process*/
	if (Global_SlideDataFlagPortState == IDLE)
	{
		    /* Lock the port to write */
		Global_SlideDataFlagPortState = BUSY ;
		/* Write the data to the port */
		Global_SlideDataUpdateflag = CtrlDataFalg ; 
		/* Unlock the port after done writing */
		Global_SlideDataFlagPortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;	
	
}
/**************************End Of Function************************/
Std_ReturnType Rte_ReadSlideCtrlDataUpdateflag  (Flag_Update *CtrlData)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
	if ( (Global_SlideDataFlagPortState == IDLE) && (CtrlData != NULL_PTR))
	{
		/* Lock the port to write */
		Global_SlideDataFlagPortState = BUSY ;
		/* Write the data to the port */
		 (*CtrlDataFalg) = Global_SlideDataUpdateflag ; 
		/* Unlock the port after done writing */
		Global_SlideDataFlagPortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
			
}
/**************************************************************************/
/*                       Incline Data Update flag Port                  */
/**************************************************************************/
Std_ReturnType Rte_WriteInclineCtrlDataUpdateflag (Flag_Update  CtrlDataFalg)
{
Std_ReturnType Local_ReturnError = E_OK ;
	
            	 /*protection process*/
	if (Global_InclineDataFlagPortState == IDLE)
	{
		   /* Lock the port to write */
		Global_InclineDataFlagPortState = BUSY ;
		/* Write the data to the port */
		Global_InclineDataUpdateflag = CtrlDataFalg ; 
		/* Unlock the port after done writing */
		Global_InclineDataFlagPortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;	
		
	
}
/**************************End Of Function************************/
Std_ReturnType Rte_ReadInclineCtrlDataUpdateflag  (Flag_Update *CtrlDataFalg)
{
	Std_ReturnType Local_ReturnError = E_OK ;
	
	if ( (Global_InclineDataFlagPortState == IDLE) && (CtrlDataFalg != NULL_PTR))
	{
		/* Lock the port to write */
		Global_InclineDataFlagPortState = BUSY ;
		/* Write the data to the port */
		 (*CtrlDataFalg) = Global_InclineDataUpdateflag ; 
		/* Unlock the port after done writing */
		Global_InclineDataFlagPortState = IDLE ;
	}
	else
	{
		Local_ReturnError = E_NOT_OK ;
	}
	return Local_ReturnError ;
}
/**************************************************************************/


		