/**
 *
 * \file HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/19/2021 12:50 ص
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HeightMotor.h"


/**
 *
 * Runnable HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppMoveHeightMotor_HeightMotor_Move
 *
 */

void HeightMotor_Move (SepMotorStepType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(Step == MOTOR_STEP_MINUS)
	{
		
	status = Rte_Call_rpSetHeightMotor_IoSetHeightReverse();

	{
		
    else if (Step == MOTOR_STEP_PLUS) 
	{
	status = Rte_Call_rpSetHeightMotor_IoSetHeightForward();
	}
	
	else
	{
	           /* wrong input by client operation*/	
	}
	
	
}

