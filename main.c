#include <18F4620.h>
#include<stdlib.h>
#include<stdio.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O
#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
   #use fast_io(c)
#endif
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_a(0xFF);
   set_tris_b(0xF0);
   set_tris_c(0x3F);
   set_tris_d(0xFF);
   set_tris_e(0x08);
int DataOne =0;
int DataTwo =0;
int Operation =0;
int NumberOne =0;
int NumbreTwo =0;
signed long Result =0; 
   while(TRUE){
   
   if(input(PIN_B4)==0)
   {
       Result = (long)input_d()+(long)input_c();
   }
   if(input(PIN_B5)==0)
   {
      Result = (long)input_d()-(long)input_c();
   }
   if(input(PIN_B6)==0)
   {
      Result = (long)input_d()*(long)input_c();
   }
   if(input(PIN_B7)==0)
   {
      Result = (long)input_d()/(long)input_c();
   }
   output_a(Result);
   output_b(Result>>6);
   output_c(Result>>10);

}
}