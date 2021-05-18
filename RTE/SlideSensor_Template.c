/**
 *
 * \file SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/19/2021 12:49 ص
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideSensor.h"


/**
 *
 * Runnable SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensorPosition_GetSlidePosition
 *
 */

void SlideSensor_GetPosition (SensorPositionType* Position)
{
	Std_ReturnType status;
	IopositionSensorReadingType position;

	            /* Server Call Points */
	status = Rte_Call_rpIoGetSlideSensorPosition_IoGetSlide(&position);
	
	if( position == 0 )
	{
        (*Position) = SENSOR_POSITION_STEP_0 ;
	}
	
	else if( position > 0 && position <= 64 )
	{
        (*Position) = SENSOR_POSITION_STEP_1 ;
	}
	
	else if( position > 64 && position <= 192)
	{
        (*Position) = SENSOR_POSITION_STEP_2 ;
	}
   else /*position should be 3*/
    {
        (*Position) = SENSOR_POSITION_STEP_3 ;
	}
		
	
}

