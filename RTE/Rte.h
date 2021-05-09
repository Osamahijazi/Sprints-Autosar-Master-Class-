/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:7/5/2021***********************************/
/***********version:1***************************************/
/***********************************************************/
#ifndef RTE_H
#define RTE_H

/* Header files Includes */
#include "Std_Types.h"
#include "Rte_DataTypes.h"

                       /* Functions Prototypes */
/**************************************************************************/
/*                         HeightData Port                                */
/**************************************************************************/
Std_ReturnType Rte_ReadHeightCtrlData (Srlf_SeatControlData *CtrlData);
/**************************************************************************/
/*                         Slide Data Port                                */
/**************************************************************************/
Std_ReturnType Rte_ReadSlideCtrlData (Srlf_SeatControlData *CtrlData);
/**************************************************************************/
/*                         Incline Data Port                             */
/**************************************************************************/
Std_ReturnType Rte_ReadInclineCtrlData (Srlf_SeatControlData *CtrlData);
/**************************************************************************/
/*                         Height BtnState Port                           */
/**************************************************************************/
Std_ReturnType Rte_WriteHeightBtnState(Srlf_SeatControlBtns BtnState);
Std_ReturnType Rte_ReadHeightBtnState (Srlf_SeatControlBtns *BtnState);
/**************************************************************************/
/*                         Slide BtnState Port                            */
/**************************************************************************/
Std_ReturnType Rte_WriteSlideBtnState (Srlf_SeatControlBtns BtnState);
Std_ReturnType Rte_ReadSlideBtnState  (Srlf_SeatControlBtns *BtnState);

/**************************************************************************/
/*                         Incline BtnState Port                          */
/**************************************************************************/
Std_ReturnType Rte_WriteInclineBtnState (Srlf_SeatControlBtns BtnState);
Std_ReturnType Rte_ReadInclineBtnState  (Srlf_SeatControlBtns *BtnState);
/**************************************************************************/
/*                         Height Data  Update flag Port                  */
/**************************************************************************/
Std_ReturnType Rte_WriteHeightCtrlDataUpdateflag (Flag_Update  CtrlDataFalg);
Std_ReturnType Rte_ReadHeightCtrlDataUpdateflag  (Flag_Update *CtrlDataFalg);
/**************************************************************************/
/*                         Slide Data Update flag Port                     */
/**************************************************************************/
Std_ReturnType Rte_WriteSlideCtrlDataUpdateflag (Flag_Update  CtrlDataFalg);
Std_ReturnType Rte_ReadSlideCtrlDataUpdateflag  (Flag_Update *CtrlDataFalg);
/**************************************************************************/
/*                       Incline Data Update flag Port                    */
/**************************************************************************/
Std_ReturnType Rte_WriteInclineCtrlDataUpdateflag (Flag_Update  CtrlData);
Std_ReturnType Rte_ReadInclineCtrlDataUpdateflag  (Flag_Update *CtrlData);
/**************************************************************************/
/*                       Height Motor Move Port                          */
/**************************************************************************/
Std_ReturnType Rte_Call_rp_HeightMotor_Move (sint8 step);
/**************************************************************************/
/*                       Slide Motor Move Port                          */
/**************************************************************************/
Std_ReturnType Rte_Call_rp_SlideMotor_Move  (sint step);
/**************************************************************************/
/*                       Incline Motor Move Port                          */
/**************************************************************************/
Std_ReturnType Rte_Call_rp_InclineMotor_Move(sint step);




#endif
