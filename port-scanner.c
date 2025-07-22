#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>




int main(){


    



    //variables as needed
    
    const char* host_ip = "127.0.0.1"; //change IP

    struct sockaddr_in socketaddr;
    
    
    

    for(int ports = 0; ports <= 65535; ++ports){
        int sock = socket(AF_INET, SOCK_STREAM, 0);    
        memset(&socketaddr, 0, sizeof(socketaddr));  // 0 out space in memory
        socketaddr.sin_family = AF_INET;
        //socketaddr.sin_addr.s_addr = inet_addr(INADDR_ANY);
        socketaddr.sin_port = htons(ports);
        inet_pton(AF_INET, host_ip, &socketaddr.sin_addr);

        
        if (connect(sock, (struct sockaddr*)&socketaddr, sizeof(socketaddr)) == 0){
             printf("\e[38;5;212mport %d is open!\n", ports);
        }
        close(sock);
    }

    
    



    return 0;
}
