#include "SerialPort.h"   

#include<stdio.h>      /*标准输入输出定义*/  
#include<string.h>  
  
int main(int argc, char **argv)  
{  
    int fd;                            //文件描述符  
    int err;                           //返回调用函数的状态  
    int len;                          
    int i;  
    char rcv_buf[100];         
    char send_buf[10]="0123456789";
    fd = UART_Open(fd,"/dev/ttyUSB0");
    if(fd < 0)
    {
        printf("[%s]:serial port open error",argv[0]);
	    return -1;
    }

    err = UART_Init(fd,115200,0,8,1,'N');
	if(err)
	{
	    printf("[%s]:serial port init error",argv[1]); 
	}

    for(int i = 0; i < 10; i++)
	{
	    printf("[%s]:======================start========================\n",argv[0]);
	    err = UART_Send(fd, send_buf, sizeof(send_buf));
		if(err)
		{
		    printf("send data sucess index: %d \n", i);
		}else{
		    printf("send data failed index: %d \n", i);
		}
        len = UART_Recv(fd, rcv_buf,99);  
  		if(len > 0)  
		{  
			rcv_buf[len] = '\0';  
			printf("receive data is %s\n",rcv_buf);  
			printf("len = %d\n",len);  
		}  
		else  
		{  
			printf("cannot receive data\n");  
		} 
	    printf("[%s]:======================end========================\n",argv[0]);
        sleep(1);
	}
    UART_Close(fd);
	printf("[%s]:serial port close\n",argv[0]);
	return 0;
    /*if(argc != 3)  
	{  
		printf("Usage: %s /dev/ttySn 0(send data)/1 (receive data) \n",argv[0]);  
		return FALSE;  
	}  
    fd = UART_Open(fd,argv[1]); //打开串口，返回文件描述符  
    do
	{  
		err = UART_Init(fd,19200,0,8,1,'N');  
		printf("Set Port Exactly!\n");  
	}while(FALSE == err || FALSE == fd);  
     
    if(0 == strcmp(argv[2],"0"))  
	{  
		for(i = 0;i < 10;i++)  
		{  
 			len = UART_Send(fd,send_buf,10);  
			if(len > 0)  
				printf(" %d time send %d data successful\n",i,len);  
			else  
				printf("send data failed!\n");  
                            
			sleep(2);  
		}  
		UART_Close(fd);               
	}  
    else  
	{                                        
		while (1) //循环读取数据  
		{    
			len = UART_Recv(fd, rcv_buf,99);  
  			if(len > 0)  
			{  
				rcv_buf[len] = '\0';  
				printf("receive data is %s\n",rcv_buf);  
				printf("len = %d\n",len);  
			}  
			else  
			{  
				printf("cannot receive data\n");  
			}  
			sleep(2);  
		}              
		UART_Close(fd);   
	}*/  
}
