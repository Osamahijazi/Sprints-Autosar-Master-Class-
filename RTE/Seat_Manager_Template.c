/**
 *
 * \file Seat_Manager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: Seat_Manager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/16/2021 12:31 ص
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_Seat_Manager.h"


static boolean IsMotorAdjustNeeded( SensorPositionType Position , SensorWeightType Weight , SepMotorStepType* Step) 
{
	Boolean AdjustMotor = FALSE ;
	
	switch (Position)
	{
		  case SENSOR_POSITION_STEP_0
		       if ( Weight > 60) 
			    {
				
				(*Step) = MOTOR_STEP_PLUS ;
				AdjustMotor = TRUE ;			
					
				}
				 break ;
		
		  case SENSOR_POSITION_STEP_1
		       if ( Weight > 80)  /*Greater than 80 then plus motor move*/
			    {
				
				(*Step) = MOTOR_STEP_PLUS ;
				AdjustMotor = TRUE ;			
					
				}
				
			   else if( (Weight <= 80) && (Weight >= 60)) 
			   {
				   
				  /*No need to Move motor*/ 
				   
			   }	

               else /*weight is less than 60*/
			   {
				   
				(*Step) = MOTOR_STEP_MINUS ;   
				AdjustMotor = TRUE ;		   				  			   
				   
			   }	
			   
				 break ; 
		  
		  case SENSOR_POSITION_STEP_2
		      if ( Weight > 100)  /*Greater than 100 then plus motor move*/
			    {
				
				  (*Step) = MOTOR_STEP_PLUS ;
				    AdjustMotor = TRUE ;			
					
				}
				
			   else if( (Weight <= 100) && (Weight >= 80)) 
			   {
				   
				  /*No need to Move motor*/ 
				   
			   }	

               else /*weight is less than 80*/
			   {
				   
				  (*Step) = MOTOR_STEP_MINUS ;   
				    AdjustMotor = TRUE ;		   				  			   
				   
			   }	
			   
			     break ; 
			   
		  case SENSOR_POSITION_STEP_3
		       if ( Weight < 100)  /*Greater than 100 then plus motor move*/
			    {
				
				  (*Step) = MOTOR_STEP_MINUS ;
			    	AdjustMotor = TRUE ;			
					
				}
				  break ;
				
	}
		
}                                 

/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	SepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean AdjustMotor ;

	                  /* Server Call Points */
	
	status = Rte_Call_rpPositionSensor_GetHeightPosition(&Position);	
	status = Rte_Call_rpWieghtSensor_GetWeight(&Weight);
	

    AdjustMotor = IsMotorAdjustNeeded( Position , Weight , &Step ) ;
	
	if(AdjustMotor)
	{
		
      status = Rte_Call_rpMoveMotor_HeightMotor_Move(Step);
		
		
	}
	
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	SepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean AdjustMotor ;

	/* Server Call Points */
	status = Rte_Call_rpWieghtSensor_GetWeight(&Weight);
	status = Rte_Call_rpPositionSensor_GetInclinePosition(&Position);
	
	
    AdjustMotor = IsMotorAdjustNeeded( Position , Weight , &Step ) ;
	
	if(AdjustMotor)
	{
		
	status = Rte_Call_rpMoveMotor_InclineMotor_Move(Step);
				
	}
	
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	SepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean AdjustMotor ;

	/* Server Call Points */
	status = Rte_Call_rpPositionSensor_GetSlidePosition(&Position);
	status = Rte_Call_rpWieghtSensor_GetWeight(&Weight);
	
		
    AdjustMotor = IsMotorAdjustNeeded( Position , Weight , &Step ) ;
	
	if(AdjustMotor)
	{
		
	status = Rte_Call_rpMoveMotor_SlideMotor_Move(Step);
				
	}
	
}



/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatControlBtnState_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	SeatControlBtnImpType HeightBtnState;

	              /* Data Receive Points */
	status = Rte_Read_rpSeatControlBtnState_HeightBtnState(&HeightBtnState);
	       /* Check if there is an error during read operation */
    if ( E_OK == status)
      {        /* drive the motor according to read value */
        if (HeightBtnState == MULTI_STATE_BTN_MINUS )   
          {
	              /*decrease motor*/
		    status = Rte_Call_rpMoveMotor_HeightMotor_Move(MOTOR_STEP_MINUS);	  
	     
          }
        else if ( HeightBtnState == MULTI_STATE_BTN_PLUS ) 
               {
	                        /*increase motor*/
		         status = Rte_Call_rpMoveMotor_HeightMotor_Move(MOTOR_STEP_PLUS);	  

	   	   
                } 
        else
            {

                  /* Wrong read operation */		

	        }    
	   }	
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatControlBtnState_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	SeatControlBtnImpType InclineBtnState;

	                    /* Data Receive Points */
	status = Rte_Read_rpSeatControlBtnState_InclineBtnState(&InclineBtnState);
	      /* Check if there is an error during read operation */
    if ( E_OK == status)
      {        /* drive the motor according to read value */
        if (InclineBtnState == MULTI_STATE_BTN_MINUS )   
          {
	              /*decrease motor*/
		    status = Rte_Call_rpMoveMotor_InclineMotor_Move(MOTOR_STEP_MINUS);
     
          }
        else if (InclineBtnState == MULTI_STATE_BTN_PLUS ) 
            {
	                       /*increase motor*/
		        status = Rte_Call_rpMoveMotor_InclineMotor_Move(MOTOR_STEP_PLUS);
	   	   
            } 
        else
           {

                  /* Wrong read operation */		

	        }    
	   }
        		
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatControlBtnState_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	SeatControlBtnImpType SlideBtnState;

	              /* Data Receive Points */
	status = Rte_Read_rpSeatControlBtnState_SlideBtnState(&SlideBtnState);
	
	  /* Check if there is an error during read operation */
    if ( E_OK == status)
      {        /* drive the motor according to read value */
        if (SlideBtnState == MULTI_STATE_BTN_MINUS )   
          {
	              /*decrease motor*/
	    	status = Rte_Call_rpMoveMotor_SlideMotor_Move(MOTOR_STEP_MINUS);
 
          }
        else if (SlideBtnState == MULTI_STATE_BTN_PLUS ) 
            {
	                       /*increase motor*/
	            status = Rte_Call_rpMoveMotor_SlideMotor_Move(MOTOR_STEP_PLUS);
   	   
            } 
        else
           {

                  /* Wrong read operation */		

	        }    
	  }
		
}

