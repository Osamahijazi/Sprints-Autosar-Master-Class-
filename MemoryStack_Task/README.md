# Memory Stack Task
## This Sequence for Write All Sequence
<p align="center">
  <img width="1200" src="Images/Sequence.png ">
</p>

## Comments 

* NVM user is ECuM Module. 
* NvM_WriteAll() must be called by EcuM as a step of Activities in the OffPreOS Sequence.
* Job processing (writing NVRAM) is done asynchronously and repeat until writing of block is completed.
* Writing of Block completed Call Job End Notification.
