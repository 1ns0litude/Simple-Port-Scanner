#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>




int main(){


    //variables as neeeded
    
    const char* host_ip = "127.0.0.1"; //change IP

    struct sockaddr_in socketaddr;
    
    
    

    for(int ports = 0; ports <= 65535; ++ports){
        int sock = socket(AF_INET, SOCK_STREAM, 0);    
        memset(&socketaddr, 0, sizeof(socketaddr));  // zero out space in memory
        socketaddr.sin_family = AF_INET;
        //socketaddr.sin_addr.s_addr = inet_addr(INADDR_ANY);
        socketaddr.sin_port = htons(ports);
        inet_pton(AF_INET, host_ip, &socketaddr.sin_addr);

        
        if (connect(sock, (struct sockaddr*)&socketaddr, sizeof(socketaddr)) == 0){
            std::cout << "\e[38;5;212mport: " << ports << " is open!" << std::endl;
        }
        close(sock);
    }

  
    



    return 0;
}