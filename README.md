# RISC-V

## Course Details
<details>

<summary><b> DAY 1 - Introduction to RISC-V ISA and GNU compiler toolchain </b></summary>

+ Introduction to RISC-V basic keywords
  - Introduction
  - From apps to hardware
  - Description of content
+ Labwork for RISC-V software toolchain
  - C program to compute sum from 1 to n
  - RISC-V GCC compiles and disassembles
  - Spike simulation and debug
+ Integer number representation
  - 64-bit number system for unsigned numbers
  - 64-bit number system for signed numbers
  - Labwork for signed and unsigned numbers
  
</details>

<details>

<summary><b> DAY 2 - Introduction to ABI and basic verification flow </b></summary>

+ Application binary interface
  - Introduction to application binary interface
  - Memory allocation for double words
  - Load, add, and store instructions with examples
  - Concluding 32 registers and their respective ABI names
+ Labwork using ABI function calls
  - New algorithm for sum 1 to n using ASM
  - Review ASM function call
  - Simulate new C program with function cell
+ Basic verification flow using iverilog
  - Lab to run C program on RISC-V CPU

</details>

<details>

<summary><b> DAY 3 - Digital Logic with TL-verilog and Makerchip </b></summary>

+ Combinational logic in TL-Verilog using Makerchip
  - Welcome
  - Introduction To Logic Gates
  - Basic Mux Implementation And Introduction To Makerchip
  - Labs For Combinational Logic
+ Sequential logic
  - Introduction To Sequential Logic And Counter Lab
  - Sequential Calculator Lab
+ Pipelined logic
  - Pipelined Logic And Re-Timing
  - Pipeline Logic Advantages And Demo In Platform
  - Lab On Error Conditions Within Computation Pipeline
  - Lab On 2-Cycle Calculator
+ Validity
  - Introduction To Validity And Its Advantages
  - Lab On Validity And Valid When Condition
  - Lab To Compute Total Distance
  - Lab on 2-cycle Calculator with Validity
  - Calulator Single Value Memory Lab
+ Wrap-up
  - Introduction To Hierarchy Concept

</details>

<details>

<summary><b> DAY 4 - Basic RISC-V CPU micro-architecture </b></summary>

+ Introduction to Simple RISC-V Micro-architecture
  - Micro-architecture of Single Cycle RISC-V CPU
  - Starting Point Code for RISC-V Labs Part-1
  - Starting Point Code for RISC-V Labs Part-2
+ Fetch and decode
  - Implementation Plan and Lab for PC
  - Lab For Instruction Fetch Logic
  - Lab For RV Instruction Types IRSBJU Decode Logic
  - Lab For Instruction Immediate Decode Logic For RV-ISBUJ
  - Lab To Decode other Fields of Instructions For RV-ISBUJ
  - Lab To Decode Instruction Field Based on Instr Type RV-ISBUJ
  - Lab To Decode Individual Instruction
+ RISC-V control logic
  - Lab For Register File Read Part-1
  - Lab For Register File Read Part-2
  - Lab For ALU Operations For add/addi
  - Lab For Register File Write
  - Concept of Array And Register File Details
  - Lab For Implementing Branch Instructions
  - Lab For Completing Branch Instruction Implementation
  - Lab To Create Simple Testbench

</details>

<details>

<summary><b> DAY 5 - Complete Pipelined RISC-V CPU micro-architecture </b></summary>

+ Pipelining the CPU
  - Introduction To Control Flow Hazard And Read After Write Hazard
  - Lab To Create 3-Cycle Valid Signal
  - Lab To Code 3-Cycle RISC-V To Take Care Of Invalid Cycles
  - Lab To Modify 3-Cycle RISC-V To Distribute Logic
+ Solutions to Pipeline Hazards
  - Lab For Register File Bypass To Address Rd-After-Wr Hazard
  - Lab For Branches To Correct The Branch Target Path
  - Lab To Complete Instruction Decode Except Fence, Ecall, Ebreak
  - Lab To Code Complete ALU
+ Load/Store Instructions and Completing RISC-V CPU
  - Introduction To Load Store Instructions And Lab To Redirect Loads
  - Lab To Load Data From Memory To Register File
  - Lab To Instantiate Data Memory To The CPU
  - Lab To Add Stores And Loads To The Test Program
  - Lab To Add Control Logic For Jump Instructions
  - Wrap Up

</details>

## Course Work
<details>

<summary><b> DAY 1 </b></summary>

### Introduction to RISC-V basic keywords
The OS handles IO operations, allocates memory, and does low-level system functions. The compiler converts HLL programs into instructions based on the hardware. The assembler converts the instructions to binary. The instruction set architecture is the interface between C/C++ and the hardware.

### Labwork for RISC-V software toolchain
+ The below is the C code for calculating sum of numbers from 1 to n
```c
#include <stdio.h>

int main(){
	int i;
	int sum=0;
	int n=5;
	for(i=0;i<=n;++i){
		sum += i;
	}
	printf("sum of numbers from 1 to %d is %d \n",n,sum);
	return 0;
}
```
Once we compile with gcc, we compile it using the RISC-V compiler using O1 and Ofast
![image](https://github.com/ks-vandana/RISC-V/blob/main/DAY%201/O1.png)
![image](https://github.com/ks-vandana/RISC-V/blob/main/DAY%201/Ofast.png)

### Integer number representation
+ The below is the C code for finding max unsigned number
```c
#include <stdio.h>
#include <math.h>

int main(){
	unsigned long long int max = (unsigned long long int)(pow(2,10)*-1);
	printf("highest number represented by unsigned long long int is %llu \n",max);
	return 0;
}
```
![image](https://github.com/ks-vandana/RISC-V/blob/main/DAY%201/unsigned.png)

+ The below is the C code for finding range of signed numbers
```c
#include <stdio.h>
#include <math.h>

int main(){
	long long int max = (long long int)(pow(2,63)-1);
	long long int min = (long long int)(pow(2,63)*(-1));
	printf("highest number represented by long long int is %lld \n",max);
	printf("lowest number represented by long long int is %lld \n",min);
	return 0;
}
```
![image](https://github.com/ks-vandana/RISC-V/blob/main/DAY%201/signed.png)

</details>

<details>

<summary><b> DAY 2 </b></summary> 

### Application binary interface
ABI is a set of rules that tell us how binary code interacts with another binary code. 64 bit value can be loaded into the memory by 2 methods - little-endian and big-endian. Load instruction is used to transfer data from memory to a register. Store instruction is used to transfer data from register to memory. Add instruction performs addition operation on two registers. In RISC-V 64, we have 32 registers and their ABI names play a role in maintaining compatibility and facilitating communication between different software components

### Labwork using ABI function calls
+ The below is the C code for adding numbers from 1 to 9
```c
#include <stdio.h>

extern int load(int x, int y);

int main(){
	int result = 0;
	int count = 9;
	result = load(0x0,count+1);
	printf("sum of numbers from 1 to 9 is %d \n",result);
}
```
+ The below is the C code in the form of RISC-V instructions
```
.section .text
.global load
.type load, @function

load:
	add a4,a0,zero //initialize a4 with value 0x0
	add a2,a0,a1   //store value as 10 in a2, a1 has value 0xa from main function
	add a3,a0,zero //initialize a3 with value 0 
loop:   add a4,a3,a4   //incremental addition
	addi a3,a3,1   //increment a3 by 1
	blt a3,a2,loop //if a3 is lesser than a2 then pass through the loop again
	add a0,a4,zero //store final answer in a0
	ret
```
+ Attached below is the disassembled code and the output when we use the spike simulator
![image](https://github.com/ks-vandana/RISC-V/blob/main/DAY%202/ASM_d.png)
![image](https://github.com/ks-vandana/RISC-V/blob/main/DAY%202/ASM.png)

</details>

<details>

<summary><b> DAY 3 </b></summary> 

### Combinational logic in TL-Verilog using Makerchip
Refer to the github repository ![https://github.com/stevehoover/RISC-V_MYTH_Workshop](https://github.com/stevehoover/RISC-V_MYTH_Workshop) for the preceding labs.

The basic logic gates are NOT, AND, OR, XOR, NAND, NOR and XNOR. These can be used to make all combinational logic circuits. 
![image](https://github.com/ks-vandana/RISC-V/assets/116361300/37430ef0-271d-40cf-919c-e1fb0945ec56)

Let us take for example a mulitplexer or a mux. We can implement it using a ternary operator in verilog.
Head to ![makerchip.com](https://myth.makerchip.com/) and launch the makerchip ide.

### Sequential logic


### Pipelined logic


### Validity


### Wrap-up



</details>

<details>

<summary><b> DAY 4 </b></summary> 

### Introduction to Simple RISC-V Micro-architecture


### Fetch and decode


### RISC-V control logic



</details>



<details>

<summary><b> DAY 5 </b></summary> 

### Pipelining the CPU


### Solutions to Pipeline Hazards


### Load/Store Instructions and Completing RISC-V CPU



</details>
