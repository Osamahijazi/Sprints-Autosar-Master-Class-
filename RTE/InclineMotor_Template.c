/**
 *
 * \file InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/19/2021 12:50 ص
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppMoveInclineMotor_InclineMotor_Move
 *
 */

void InclineMotor_Move (SepMotorStepType Step)
{
	Std_ReturnType status;

	              /* Server Call Points */	
	if(Step == MOTOR_STEP_MINUS)
	{
		
	status = Rte_Call_rpSetInclineMotor_IoSetInclineReverse();

	{
		
    else if (Step == MOTOR_STEP_PLUS) 
	{
	status = Rte_Call_rpSetInclineMotor_IoSetInclineForward();
	}
	
	else
	{
	           /* wrong input by client operation*/	
	}
	
}

