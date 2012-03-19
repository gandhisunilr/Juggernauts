https://my.st.com/public/STe2ecommunities/mcu/Lists/cortex_mx_stm32/DispForm.aspx?ID=16973&RootFolder=%2Fpublic%2FSTe2ecommunities%2Fmcu%2FLists%2Fcortex_mx_stm32%2FUSB%20to%20transmit%20real-time%20data%20in%20the%20least%20time%20possible



walid.farid > Are there any STM32 USB & USB tutorials that will facilitate my understanding ?

ST distributes this USB device library on their web site.

STM32F10x and STM32L1xx USB full-speed device library
http://www.st.com/internet/com/SOFTWARE_RESOURCES/SW_COMPONENT/FIRMWARE/um0424.zip

STM32 USB-FS-Device development kit
http://www.st.com/internet/com/TECHNICAL_RESOURCES/TECHNICAL_LITERATURE/USER_MANUAL/CD00158241.pdf

You may find another USB libraries/examples made by compiler vendors like Keil, IAR.

As of ST library, I recommend you to start with \Project\Virtual_COM_Port example. This example transfer data from on-chip UART to PC over USB. Also, in the other direction. On the PC side, the chip is exposed as a COM port. Therefore, you don't need to change your PC code so much.

You'll modify this example so that it picks up data from GPIO instead of the UART. As this example gives full source code, you may be lost in the forest of the source code. These functions are ones you have to focus on,

1) EP1_IN_Callback() in \Project\Virtual_COM_Port\src\usb_endp.c
2) Handle_USBAsynchXfer() in \Project\Virtual_COM_Port\src\hw_config.c

Both of these functions moves packetized data from the UART RX buffer to USB endpoint buffer using USB_SIL_Write() (or equivalent). Handle_USBAsynchXfer() is periodically called by USB SOF (Start Of Frame) interrupt, ie. every 1ms. It moves the first packet to the endpoint buffer after interval. EP1_IN_Callback() is called by the endpoint interrupt, which occurs just when the last transaction (a packet transfer) finishes. This routine pushes the second and latter packets into the endpoint, if the RX buffer still holds data more than the packet size.

As you see, most of the complicated USB details are hidden by the library. Your code focuses on just exchanging packets with endpoints.

I recommend you to read this short explanation, to get clear understanding on USB transfer.

Transfer - transaction - packet
http://www.cygnal.org/ubb/Forum9/HTML/001627.html



PICguy > At least you recognize you need assistance.  I recommend that if you plan to use USB and have the budget you should get a USB expert to assist.

I agree that USB beginner needs some assistance, to know the place where they should focus in the example source code. But I don't think paid consulting is required for startup on USB library. If it were, I could be a millionaire, now :-)

Tsuneo
