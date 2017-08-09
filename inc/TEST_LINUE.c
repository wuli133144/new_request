//#include "http_types.h"


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFSIZE 200

#define LINE_NUM 10
/*http contains*/
typedef struct __head__{
            char name[BUFSIZE];
            char value[BUFSIZE];
              
}http_head_contain;

/*http header*/
typedef struct __http_header{
    char method[BUFSIZE];
    char url[BUFSIZE];
    char version[BUFSIZE];
    http_head_contain contain[LINE_NUM];/*http contain head*/
}http_request;




int readline_buf(char **buf,char *usr,size_t maxlen){
           int i=0,len1,len2;

           if(*buf==NULL||(usr)==NULL){
               return (-1);
            }
            len1=strlen(*buf);
            len2=maxlen;
           
           
            maxlen=len2<len1?len2:len1;
           
            
            for(i=0;i<maxlen;i++){
               if(i<(maxlen-2)&&*(*buf+i+2)!='\r'&&( *(*buf+i)=='\r')&&*(*buf+i+1)=='\n'){
                   
                    usr[i]=0;
                    break;
               }else if(i<(maxlen-3)&&*(*buf+i)=='\r'&&( *(*buf+i+1)=='\n')&&
                        *(*buf+i+2)=='\r'&&*(*buf+i+3)=='\n'){
                    
                       usr[i]=0;
                       *buf=NULL;
                        return 0;
               }
               usr[i]=*(*buf+i);  
               
            }
            usr[i]=0;
            *buf+=(i);
            return (i);
            
}

void * analasy(char *buffer){
             
             char buf[BUFSIZE];
             bzero(buf,BUFSIZE);
             
             
             if(strstr(buffer,"\r\n\r\n")==NULL){/*If null buf is nut full*/
                 return NULL;
             }
             char *cpstr=strdup(buffer); 
            
             http_request *req=(http_request *)malloc(sizeof(http_request));
            
              readline_buf(&cpstr,buf,BUFSIZE);
             // printf("%s",buf);
                   //strcpy(req->method,strtok(buf," "));
                    // printf("%s ",req->method);
                  //         strcpy(req->url,strtok(NULL," "));
                  //          printf("%s ",req->url);
                  //         strcpy(req->version,strtok(NULL," "));
                  //          printf("%s ",req->version);
             
             bzero(buf,BUFSIZE);
            //   while((readline_buf(&cpstr,buf,BUFSIZE))!=0){
            //          strcpy(req->contain[i].name,strtok(buf,":"));
            //          strcpy(req->contain[i].value,strtok(NULL,":"));
            //          i++;
            //  }
           
             return NULL ;
}

char *mystrncpy(char *dest,char *src,size_t len){
        char *temp=dest;
        char *tempstr=src;
        while(*temp!=0)temp++;
        while((*temp=*tempstr)&&len--){
               temp++;
               tempstr++;
        }
        *temp=0;
        return dest;
}

int main(){
         
         char m[100]="234\r\n";
         char s[]="12345\r\n\r\n";
         //printf("%s",mystrncpy(m,s,strlen(s)-2));
         
         strncat(m,s,strlen(s));
         printf(m);
         
           
   //analasy(m);

    return 0;
}