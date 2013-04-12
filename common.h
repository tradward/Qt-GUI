#ifndef COMMON_H
#define COMMON_H

#include <iostream> 
#include <string>
#include <stdio.h> 
#include <stdlib.h>  
#include <unistd.h> 
#include <string.h>   
#include <sys/types.h>  
#include <sys/stat.h>  
#include <sys/socket.h>  
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <fstream> 
#include <vector>
#include <assert.h>
      
#define PORT 6000  
#define LISTENQ 20  
#define BUFFSIZE 4096  
#define FILE_NAME_MAX_SIZE 512
#define WORD_MAX_SIZE 256 

struct MovieData {
    char name[100];
    char year[10];
    char length[10];
    char director[30];
    char cast[500];
    char pic[200];
    char number[20];
    char content[10000];
    char wiki[10000];
};

using namespace std;

class client {
public:
    static vector<string> split(string str, string seperators);
    static int Clie_SockEstablish();
    static void Clie_ClientConnect(int clientfd, char* addr);
    static void Clie_SaveContent(int clientfd, char* addr, string filename);
    static struct MovieData* Clie_SaveStruct(int clientfd);
    static void Clie_SendCommand(int clientfd, string command);
    static string Clie_GetResponse(int clientfd);
    static void Clie_close(int clientfd);

};

#endif