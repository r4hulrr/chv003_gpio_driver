# TESTING IMPORTANT INFO
There are three types of testing done to verify functionality:
1. **Hardware Testing** 
2. **Interrupt Testing (monitored through SWDIO)**
3. **UART Testing** 

## Points to note
- Hardware testing - configures PC1 to toggle its output so would require an led / such device to be connected to PC1
- Interrupt testing - uses SWDIO so would need the board to be connected to the system in this setup
- UART testing - uses UART setup with PD5 as Rx and PD6 as Tx, so would need to be set up that way unless code is modified
- All tests are commented out in the beginning and if you want to run any certain test just search for "@TEST_NAME" in main.c and remove the code associated with that @. 