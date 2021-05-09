/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:7/5/2021***********************************/
/***********version:1***************************************/
/***********************************************************/
        /*save new Data vlues to compare with old values*/
static Srlf_SeatControlDataType Global_NewHeightData ;
static Srlf_SeatControlDataType Global_NewSlideData ;
static Srlf_SeatControlDataType Global_NewInclineData ;
        /*save old Data vlues to compare with new values*/
static Srlf_SeatControlDataType Global_OldHeightData ;
static Srlf_SeatControlDataType Global_OldSlideData ;
static Srlf_SeatControlDataType Global_OldInclineData ;
 

void Main_Function (void)
{
	
   Std_ReturnType status ;
                            /*************Read height data********************* */
   status = RTE_READ_HEIGHT_CTRL_DATA(&Global_NewHeightData) ;
       /* Check if there is an error during read operation */
		if (E_OK == status)
		{                  /*check for 3 conditions Time , update and Value*/
			if( TIME_OUT || (Global_OldHeightData == Global_NewHeightData ) || ( Global_NewHeightData == 0) )
			{ 
			            /*init button state*/
			status = RTE_WRITE_HEIGHT_CTRL_DATA(MULTI_STATE_BTN_INIT);	
			           /*dont update received data flag Event*/
			status = RTE_WRITE_HEIGHT_CTRL_DATA_UPDATE_FLAG(NOT_UPDATED);	
				
			}
			else if(  Global_NewHeightData == 1 )
			{ 
			            /*minus button state*/
			status = RTE_WRITE_HEIGHT_CTRL_DATA(MULTI_STATE_BTN_MINUS);	
			       /* update received data flag to trriger read flagEvent at other SWCs*/
			status = RTE_WRITE_HEIGHT_CTRL_DATA_UPDATE_FLAG(UPDATED);	
				
			}
			else if( Global_NewHeightData == 2 )
			{ 
			            /*plus button state*/
			status = RTE_WRITE_HEIGHT_CTRL_DATA(MULTI_STATE_BTN_PLUS);	
			       /* update received data flag to trriger read flag Event at other SWCs*/			
			status = RTE_WRITE_HEIGHT_CTRL_DATA_UPDATE_FLAG(UPDATED);	
				
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
		
		               /*************Read slide data ******************/
        status = RTE_READ_SLIDE_CTRL_DATA(&Global_NewSlideData) ;
             /* Check if there is an error during read operation */
		if (E_OK == status)
		{                  /*check for 3 conditions Time , update and Value*/
			if( TIME_OUT || (Global_OldSlideData == Global_NewSlideData ) || ( Global_NewSlideData == 0) )
			{ 
			            /*init button state*/
			status = RTE_WRITE_SLIDE_CTRL_DATA(MULTI_STATE_BTN_INIT);	
			           /*dont update received data flag Event*/
			status = RTE_WRITE_SLIDE_CTRL_DATA_UPDATE_FLAG(NOT_UPDATED);	
				
			}
			else if(  Global_NewSlideData == 1 )
			{ 
			            /*minus button state*/
			status = RTE_WRITE_SLIDE_CTRL_DATA(MULTI_STATE_BTN_MINUS);	
			       /* update received data flag Event to trriger read flag at other SWCs*/
			status = RTE_WRITE_SLIDE_CTRL_DATA_UPDATE_FLAG(UPDATED);	
				
			}
			else if( Global_NewSlideData == 2 )
			{ 
			            /*plus button state*/
			status = RTE_WRITE_SLIDE_CTRL_DATA(MULTI_STATE_BTN_PLUS);	
			       /* update received data flag Event to trriger read flag at other SWCs*/
			status = RTE_WRITE_SLIDE_CTRL_DATA_UPDATE_FLAG(UPDATED);	
				
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
         
                          /**********Read Incline data ************/
        status = RTE_READ_INCLINE_CTRL_DATA(&Global_NewInclineData) ;
             /* Check if there is an error during read operation */
		if (E_OK == status)
		{                  /*check for 3 conditions Time , update and Value*/
			if( TIME_OUT || (Global_OldInclineData == Global_NewInclineData ) || ( Global_NewInclineData == 0) )
			{ 
			            /*init button state*/
			status = RTE_WRITE_INCLINE_CTRL_DATA(MULTI_STATE_BTN_INIT);	
			           /*dont update received data flag Event*/
			status = RTE_WRITE_INCLINE_CTRL_DATA_UPDATE_FLAG(NOT_UPDATED);	
			}
			else if(  Global_NewInclineData == 1 )
			{ 
			            /*minus button state*/
			status = RTE_WRITE_INCLINE_CTRL_DATA(MULTI_STATE_BTN_MINUS);
			       /* update received data flag Event to trriger read flag at other SWCs*/
			status = RTE_WRITE_INCLINE_CTRL_DATA_UPDATE_FLAG(UPDATED);	
				
			}
			else if( Global_NewInclineData == 2 )
			{ 
			            /*plus button state*/
			status = RTE_WRITE_INCLINE_CTRL_DATA(MULTI_STATE_BTN_PLUS);	
			       /* update received data flag Event to trriger read flag at other SWCs*/
			status = RTE_WRITE_INCLINE_CTRL_DATA_UPDATE_FLAG(UPDATED);	
				
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