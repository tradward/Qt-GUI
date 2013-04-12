#include "common.h"

vector<string> client::split(string str, string seperators) {
    int n = str.length();
    int start, stop;
    vector<string> tokens;
    
    start = str.find_first_not_of(seperators);
    while (start >= 0 && start < n) {
        stop = str.find_first_of(seperators, start);
        if (stop < 0 || stop > n) {
            stop = n;
        }
        tokens.push_back(str.substr(start, stop - start));
        start = str.find_first_not_of(seperators, stop + 1);
    }
    return tokens;
}

int client::Clie_SockEstablish(){
    struct sockaddr_in clientaddr;  
    bzero(&clientaddr,sizeof(clientaddr));    
          
    clientaddr.sin_family=AF_INET;  
    clientaddr.sin_addr.s_addr=htons(INADDR_ANY);  
    clientaddr.sin_port=htons(0);

    int clientfd=socket(AF_INET,SOCK_STREAM,0);  
              
    if(clientfd<0){  
        perror("socket");  
        exit(1); 
    }  

    if(bind(clientfd,(struct sockaddr*)&clientaddr,sizeof(clientaddr))<0){  
        perror("bind");  
        exit(1);
    }  
    return clientfd;
}

void client::Clie_ClientConnect(int clientfd, char* addr){
    struct sockaddr_in svraddr;  
    bzero(&svraddr,sizeof(svraddr));  
    if(inet_aton(addr,&svraddr.sin_addr)==0){  
        perror("inet_aton");  
        exit(1);
    }  
    svraddr.sin_family=AF_INET;  
    svraddr.sin_port=htons(PORT);  
              
    socklen_t svraddrlen=sizeof(svraddr);  
    if(connect(clientfd,(struct sockaddr*)&svraddr,svraddrlen)<0){  
        perror("connect");  
        exit(1); 
    } 
}

void client::Clie_SaveContent(int clientfd, char* addr, string filename){
    //recv file imformation  
    char buff[BUFFSIZE];bzero(buff,BUFFSIZE);  
    //char filename[FILE_NAME_MAX_SIZE] = "a.jpg";    
              
    cout << *addr << filename << endl;   
              
    //recv file  
    FILE *fd=fopen(filename.c_str(),"wb+");  
    if(NULL==fd){  
        perror("open");  
        exit(1);   
    }  
            
    bzero(buff,BUFFSIZE);  
              
    int length=0;  
    while((length=recv(clientfd,buff,BUFFSIZE,0))){  
        if(length<0){  
            perror("recv");  
            exit(1);  
        }  
        int writelen=fwrite(buff,sizeof(char),length,fd);  
        if(writelen<length){  
            perror("write");  
            exit(1);   
        }  
        bzero(buff,BUFFSIZE);  
    }  
    printf("Receieved file:%s from %s finished!\n",filename.c_str(),addr);  
    fclose(fd);
}

struct MovieData* client::Clie_SaveStruct(int clientfd){
    char buffer[BUFFSIZE];bzero(buffer,BUFFSIZE);
    struct MovieData* recvMovie = (struct MovieData*)malloc(sizeof(*recvMovie));

    //int count;
    recv(clientfd, buffer, sizeof(buffer), 0);
    memcpy(recvMovie, buffer, sizeof(buffer));

    cout << "Title is " << recvMovie->name << endl;
    cout << "Year is " << recvMovie->year << endl;
    cout << "Length is " << recvMovie->length << endl;
    cout << "Director is " << recvMovie->director << endl;
    cout << "Cast is " <<recvMovie->cast << endl;
    cout << "Content is " << recvMovie->content << endl;
    cout << "Wiki is " << recvMovie->wiki << endl;
    cout << "Pic is " << recvMovie->pic << endl;
    cout << "Number is " << recvMovie->number << endl;
    return recvMovie;
}

void client::Clie_SendCommand(int clientfd, string command){
    int count2 = send(clientfd,command.c_str(),WORD_MAX_SIZE,0);
    if(count2 < 0){
        perror("connect");
        exit(1);                  
    }    
}
      
string client::Clie_GetResponse(int clientfd){
    char response[WORD_MAX_SIZE];bzero(response,WORD_MAX_SIZE);
    int count4=recv(clientfd,response,WORD_MAX_SIZE,0);  
    if(count4<0){  
        perror("recv");  
        exit(1);  
    }
    cout << response << endl;
    string re(response);
    cout << re << "1" << endl;
    bzero(response,WORD_MAX_SIZE);
    return re;
}

void client::Clie_close(int clientfd){
    close(clientfd);
}