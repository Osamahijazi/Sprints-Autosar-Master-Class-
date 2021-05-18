/**
 *
 * \file HeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/19/2021 12:50 ص
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HeightSensor.h"


/**
 *
 * Runnable HeightSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightSensorPosition_GetHeightPosition
 *
 */

void HeightSensor_GetPosition (SensorPositionType* Position)
{
	Std_ReturnType status;
	IopositionSensorReadingType position;

	                 /* Server Call Points */
	status = Rte_Call_rpIoGetHeightSensorPosition_IoGetHeight(&position);
	
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

