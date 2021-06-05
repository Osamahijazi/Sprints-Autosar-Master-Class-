/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 5/16/2021 08:16 م
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"

static SeatControlBtnImpType btnValueToState(uint8 value)
{
	SeatControlBtnImpType btnState;

	if (value == 1)
	{
		btnState = MULTI_STATE_BTN_MINUS;
	}
	else if (value == 2)
	{
		btnState = MULTI_STATE_BTN_PLUS;
	}
	else
	{
		btnState = MULTI_STATE_BTN_INIT;
	}

	return btnState;
}

/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction(void)
{
	Std_ReturnType status;
	SeatControlBtnImpType HeightBtnState;
	SeatControlBtnImpType InclineBtnState;
	SeatControlBtnImpType SlideBtnState;
	SeatControlDataImpType HeightCtrlData;
	SeatControlDataImpType InclineCtrlData;
	SeatControlDataImpType SlideCtrlData;
	boolean IsUpdated;

	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Height();
	status = Rte_Read_rpSeatControlData_HeightCtrlData(&HeightCtrlData);
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{

		HeightBtnState = btnValueToState(HeightCtrlData);
		(void)Rte_Write_ppSeatControlBtnState_HeightBtnState(HeightBtnState);
	}

	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Incline();
	status = Rte_Read_rpSeatControlData_InclineCtrlData(&InclineCtrlData);
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{
		InclineBtnState = btnValueToState(InclineCtrlData);
		(void)Rte_Write_ppSeatControlBtnState_InclineBtnState(InclineBtnState);
	}

	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Slide();
	status = Rte_Read_rpSeatControlData_SlideCtrlData(&SlideCtrlData);
	if (status == RTE_E_OK && IsUpdated == TRUE)
	{
		SlideBtnState = btnValueToState(SlideCtrlData);
		(void)Rte_Write_ppSeatControlBtnState_SlideBtnState(SlideBtnState);
	}

	/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

	void HMI_SeatModeChanged(void)
	{
		SeatModeBtnType SeatModeBtn;
		uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

		(void)Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);

              /*specify mode*/
			  
		if (SeatModeBtn == SEAT_MODE_BTN_MANUAL)
		{
			SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
		}
		else if (SeatModeBtn == SEAT_MODE_BTN_AUTO)
		{
			SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
		}
		else
		{
			/* Save Init Mode */
		}

		(void)Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
	}
