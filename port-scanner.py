#!/usr/bin/python3
import socket




def scan():  
    host = "127.0.0.1"   # change IP
    for ports in range(0, 65535):
        
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.settimeout(0.5)
            if s.connect_ex((host, ports)) == 0:
                print(f"\033[35mPort {ports} is open!\033[0m")

            else:
                continue
        #error handling    
        except socket.gaierror as e:
            print(f"\033[31mInvalid Hostname: {e}")
            break
        
        except socket.error as e:
            print(f"\033[31mInvalid Socket: {e}")
            break
            
              
        
        
if __name__ == "__main__":
    scan()
