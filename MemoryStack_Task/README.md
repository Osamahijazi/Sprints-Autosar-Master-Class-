# Memory Stack Task
## This Sequence for Write All Sequence
<p align="center">
  <img width="600" src="Images/Sequence.png ">
</p>

## Comments 

* NVM user is ECuM Module 
* NvM_WriteAll() must be called by EcuM as one step of Activities in the OffPreOS Sequence
* Job processing (writing NVRAM) is done asynchronously
* Writing of Block completed Call Job End Notification
* 