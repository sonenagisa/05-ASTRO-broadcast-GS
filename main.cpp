#include "mbed.h"
#include "HEPTA_COM.h"

HEPTA_COM com(PA_9,PA_10,9600);
Serial pc(USBTX,USBRX,9600);

int main(){
    int rcmd=0,cmdflag=0;
    int i;
    while(1){
        char msg[256];
        i=0;
        com.xbee_receive(&rcmd,&cmdflag);
        pc.printf("GS\r\n");
        wait(1);
        if (cmdflag == 1) {
           pc.printf("Command Get %d\r\n",rcmd);
        }
    }
    /*
    int rcmd=0,cmdflag=0;
    int i;
    while(1){
        char msg[256];
        i=0;
        com.xbee_receive(&rcmd,&cmdflag);
        pc.printf("GS\r\n");
        wait(1);
        if (cmdflag == 1) {
            while(msg[i]=='\r'){
                msg[i]=com.getc();
                pc.printf("%c",msg[i]);
                i++;
            }
            
            if((msg[0]=='a')&(msg[i]=='b')){
                //pc.printf("%d",i);
                for(int k = 0; k < i; k++) {
                    pc.printf("%c",msg[k]);                
                }
            
            }else{
                com.initialize();
                break;
            }
            
            
        }
    }
    */
}

