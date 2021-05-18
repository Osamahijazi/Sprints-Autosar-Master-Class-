/**
 *
 * \file SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/19/2021 12:49 ص
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideMotor.h"


/**
 *
 * Runnable SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppMoveSlideMotor_SlideMotor_Move
 *
 */

void SlideMotor_Move (SepMotorStepType Step)
{
	Std_ReturnType status;

	               /* Server Call Points */	
	if(Step == MOTOR_STEP_MINUS)
	{		
	status = Rte_Call_rpSetSlideMotor_IoSetSlideReverse();
	{
		
    else if (Step == MOTOR_STEP_PLUS) 
	{
	status = Rte_Call_rpSetSlideMotor_IoSetSlideForward();
	}
	
	else
	{
	           /* wrong input by client operation*/	
	}
	
}

