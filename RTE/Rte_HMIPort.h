/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:7/5/2021***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef RTE_HMI_PORT_H
#define RTE_HMI_PORT_H

#include "Rte.h"

                          /*private Macros*/
typedef     uint8    Srlf_SeatControlDataType ;
					 
typedef     TIME_OUT     (uint8)(0X01) ;



/**************************************************************************/
/*                         Provided Ports                                 */
/**************************************************************************/
#define     RTE_WRITE_HEIGHT_BTN_STATE                  Rte_WriteHeightBtnState
#define     RTE_WRITE_SLIDE_BTN_STATE                   Rte_WriteSlideBtnState
#define     RTE_WRITE_INCLINE_BTN_STATE                 Rte_WriteInclineBtnState
#define     RTE_WRITE_HEIGHT_CTRL_DATA_UPDATE_FLAG      Rte_WriteHeightCtrlDataUpdateflag
#define     RTE_WRITE_SLIDE_CTRL_DATA_UPDATE_FLAG       Rte_WriteSlideCtrlDataUpdateflag
#define     RTE_WRITE_INCLINE_CTRL_DATA_UPDATE_FLAG     Rte_WriteInclineCtrlDataUpdateflag

/**************************************************************************/
/*                          Received Ports                                 */
/**************************************************************************/
#define    RTE_READ_HEIGHT_CTRL_DATA                   Rte_ReadHeightCtrlData
#define    RTE_READ_SLIDE_CTRL_DATA                    Rte_ReadSlideCtrlData
#define    RTE_READ_INCLINE_CTRL_DATA                  Rte_ReadInclineCtrlData


#endif
