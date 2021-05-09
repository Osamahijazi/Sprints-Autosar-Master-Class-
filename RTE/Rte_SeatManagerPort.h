/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:7/5/2021***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef RTE_SEATMANAGER_PORT_H
#define RTE_SEATMANAGER_PORT_H

#include "Rte.h"

              /*private Macros*/
typedef     uint8    Srlf_SeatControlBtnType ;
 

/**************************************************************************/
/*                          Received Ports                                 */
/**************************************************************************/
#define     RTE_READ_HEIGHT_CTRL_DATA_UPDATE_FLAG      Rte_ReadHeightCtrlDataUpdateflag
#define     RTE_READ_SLIDE_CTRL_DATA_UPDATE_FLAG       Rte_ReadSlideCtrlDataUpdateflag
#define     RTE_READ_INCLINE_CTRL_DATA_UPDATE_FLAG     Rte_ReadInclineCtrlDataUpdateflag
#define     RTE_READ_HEIGHT_BTN_STATE                  Rte_ReadHeightBtnState
#define     RTE_READ_SLIDE_BTN_STATE                   Rte_ReadSlideBtnState
#define     RTE_READ_INCLINE_BTN_STATE                 Rte_ReadInclineBtnState
/**************************************************************************/
/*                         Provided Ports                                 */
/**************************************************************************/
#define     RTE_CALL_RP_HEIGHT_MOTOR_MOVE              Rte_Call_rp_HeightMotor_Move
#define     RTE_CALL_RP_SLIDE_MOTOR_MOVE               Rte_Call_rp_SlideMotor_Move
#define     RTE_CALL_RP_INCLINE_MOTOR_MOVE             Rte_Call_rp_InclineMotor_Move


#endif
