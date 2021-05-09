/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:7/5/2021***********************************/
/***********version:1***************************************/
/***********************************************************/
            /*Global Variable to read tn states*/
static Srlf_SeatControlBtnType  Global_HeightBtnState ;
static Srlf_SeatControlBtnType  Global_SlideBtnState ;
static Srlf_SeatControlBtnType  Global_InclineBtnState ;
            /*Global Variable to data update states*/
static FlagType Global_HeightDataUpdateFlag; 
static FlagType Global_SlideDataUpdateFlag; 
static FlagType Global_InclineDataUpdateFlag; 


void SeatManager_MainFunction(void)
{
	Std_ReturnType status ;
	                /*check for Height Data update*/	
    status = RTE_READ_HEIGHT_CTRL_DATA_UPDATE_FLAG(&Global_HeightDataUpdateFlag) ;
	       /* Check if there is an error during read operation */
    if (E_OK == status)
    {        
        if(Global_HeightDataUpdateFlag == UPDATED)
		{
		   status = SeatManager_SetHeight() ; 	
		}	
	}
	
	                /*check for Slide Data update*/	
    status = RTE_READ_SLIDE_CTRL_DATA_UPDATE_FLAG(&Global_SlideDataUpdateFlag) ;
	       /* Check if there is an error during read operation */
    if (E_OK == status)
    {        
        if(Global_SlideDataUpdateFlag == UPDATED)
		{
		   status = SeatManager_SetSlide() ; 	
		}	
	}
	                /*check for Incline Data update*/	
    status = RTE_READ_INCLINE_CTRL_DATA_UPDATE_FLAG(&Global_InclineDataUpdateFlag) ;
	       /* Check if there is an error during read operation */
    if (E_OK == status)
    {        
        if(Global_InclineDataUpdateFlag == UPDATED)
		{
		   status = SeatManager_SetIncline() ; 	
		}	
	}
	
}
static Std_ReturnType SeatManager_SetHeight(void)
{

	Std_ReturnType status ;
	                /*check for Height btn state*/	
    status = RTE_READ_HEIGHT_BTN_STATE(&Global_HeightBtnState) ;
       /* Check if there is an error during read operation */
 if (E_OK == status)
   {        /* drive the motor according to read value */
     if (Global_HeightBtnState == MULTI_STATE_BTN_MINUS )   
       {
	              /*decrease motor*/
	     RTE_CALL_RP_HEIGHT_MOTOR_MOVE(MOTOR_STEP_MINUS);
	     
       }
     else if (Global_HeightBtnState == MULTI_STATE_BTN_PLUS ) 
       {
	               /*increase motor*/
	   	   RTE_CALL_RP_HEIGHT_MOTOR_MOVE(MOTOR_STEP_PLUS);

	   	   
        } 
     else
       {

                  /* Wrong read operation */		

	   }    
	}

 return status ;	
}

static Std_ReturnType SeatManager_SetSlide(void)
{
	
	Std_ReturnType status ;
	                /*check for Height btn state*/	
   status = RTE_READ_SLIDE_BTN_STATE(&Global_SlideBtnState) ;
      /* Check if there is an error during read operation */
    if (E_OK == status)
    {
        /* drive the motor according to read value */
        if (Global_SlideBtnState == MULTI_STATE_BTN_MINUS )   
        {
			               /*decrease motor*/
	        RTE_CALL_RP_HEIGHT_MOTOR_MOVE(MOTOR_STEP_MINUS);	 
	     
        }
        else if (Global_SlideBtnState == MULTI_STATE_BTN_PLUS ) 
        {
	   
	                  /*increase motor*/
	        RTE_CALL_RP_HEIGHT_MOTOR_MOVE(MOTOR_STEP_PLUS);
	   	    
	    } 
        else
        {

                     /* Wrong read operation */		

        }		
	
	}
	 return status ;	

}
static Std_ReturnType SeatManager_SetIncline(void)
{
	
	Std_ReturnType status ;
	                /*check for Height btn state*/	
   status = RTE_READ_INCLINE_BTN_STATE(&Global_InclineBtnState) ;
        /* Check if there is an error during read operation */
    if (E_OK == status)
    {
        /* drive the motor according to read value */
        if (Global_InclineBtnState == MULTI_STATE_BTN_MINUS )   
        {
		
	                 /*decrease motor*/
	        RTE_CALL_RP_HEIGHT_MOTOR_MOVE(MOTOR_STEP_MINUS);	 
	     
        }
        else if (Global_InclineBtnState == MULTI_STATE_BTN_PLUS ) 
        {
	   
	                /*increase motor*/
            RTE_CALL_RP_HEIGHT_MOTOR_MOVE(MOTOR_STEP_PLUS);
	   	   
        } 
        else
        {

                             /* Wrong read operation */		

        }	
	
	
	}
	 return status ;	

}
