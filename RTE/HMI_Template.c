/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/15/2021 10:47 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */
  

void HMI_MainFunction (void)
{
	
	Std_ReturnType status;
	/*Buttons provides States*/
	SeatControlBtnImpType HeightBtnState;
	SeatControlBtnImpType InclineBtnState;
	SeatControlBtnImpType SlideBtnState;
    /*Ctrl Data recieved States*/
	SeatControlDataImpType HeightCtrlData;
	SeatControlDataImpType InclineCtrlData;
	SeatControlDataImpType SlideCtrlData;
	                             /* Data Receive Points */
                            /*************Read height data********************* */
	status = Rte_Read_rpSeatControlData_HeightCtrlData(&HeightCtrlData);
       /* Check if there is an error during read operation */
		if (E_OK == status)
		{                 /*check for 3 conditions Time , update and Value*/
			if( TIME_OUT || (UPDATE) || ( HeightCtrlData == 0) )
			{ 
			                /*init button state*/
			HeightBtnState = MULTI_STATE_BTN_INIT ;			
			status = Rte_Write_ppSeatControlBtnState_HeightBtnState(HeightBtnState);
			        
			}
			else if(  HeightCtrlData == 1 )
			{ 
			            /*minus button state*/
			HeightBtnState = MULTI_STATE_BTN_MINUS ;									
			status = Rte_Write_ppSeatControlBtnState_HeightBtnState(HeightBtnState);	
			     
			}
			else if( HeightCtrlData == 2 )
			{ 
			            /*plus button state*/
			HeightBtnState = MULTI_STATE_BTN_PLUS ;															
			status = Rte_Write_ppSeatControlBtnState_HeightBtnState(HeightBtnState);	
			      
			}
			else
			{	
				/*wrong read data you shouldnt be here*/
			}
					
	    }
		else
		{
			
			/*Error during read operation*/
		}   
		
		               /*************Read Incline data ******************/
	status = Rte_Read_rpSeatControlData_InclineCtrlData(&InclineCtrlData);
             /* Check if there is an error during read operation */
		if (E_OK == status)
		{                  /*check for 3 conditions Time , update and Value*/
			if( TIME_OUT || ( UPDATE ) || (InclineCtrlData == 0) )
			{ 
			            /*init button state*/
			InclineCtrlData = MULTI_STATE_BTN_INIT ;			
			status = Rte_Write_ppSeatControlBtnState_InclineBtnState(InclineCtrlData);	
			           
			}
			else if(InclineCtrlData == 1 )
			{ 
			            /*minus button state*/
			InclineCtrlData = MULTI_STATE_BTN_MINUS ;									
			status = Rte_Write_ppSeatControlBtnState_InclineBtnState(InclineCtrlData);	
			       
			}
			else if( Global_NewSlideData == 2 )
			{ 
			            /*plus button state*/
			InclineCtrlData = MULTI_STATE_BTN_PLUS ;															
			status = Rte_Write_ppSeatControlBtnState_InclineBtnState(InclineCtrlData);	
			      
			}
			else
			{	
				/*wrong read data you shouldnt be here*/
			}
					
	    }
		else
		{
			
			/*Error during read operation*/
		}
         
                          /**********Read slide data ************/
        status = Rte_Read_rpSeatControlData_SlideCtrlData(&SlideCtrlData) ;
             /* Check if there is an error during read operation */
		if (E_OK == status)
		{                  /*check for 3 conditions Time , update and Value*/
			if( TIME_OUT || ( UPDATE ) || ( SlideCtrlData == 0) )
			{ 
			            /*init button state*/
			SlideCtrlData = MULTI_STATE_BTN_INIT ;			
			status = Rte_Write_ppSeatControlBtnState_SlideBtnState(SlideCtrlData);	
			           
			}
			else if(  SlideCtrlData == 1 )
			{ 
			            /*minus button state*/
			SlideCtrlData = MULTI_STATE_BTN_MINUS ;									
			status = Rte_Write_ppSeatControlBtnState_SlideBtnState(SlideCtrlData);
			       
			}
			else if( SlideCtrlData == 2 )
			{ 
			            /*plus button state*/
			SlideCtrlData = MULTI_STATE_BTN_PLUS ;															
			status = Rte_Write_ppSeatControlBtnState_SlideBtnState(SlideCtrlData);	
			       
			}
			else
			{	
				/*wrong read data you shouldnt be here*/
			}
					
	    }
		else
		{
			
			/*Error during read operation*/
		} 		
}