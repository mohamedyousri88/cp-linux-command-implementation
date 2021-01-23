#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[]){

      if(argc<3)       {return 1; }   //if the number of arguments of the input is less than 3
                                    //return error message with value 1
      
      int fdSrcFile = open(argv[1], O_RDONLY);  //storing the file descriptor value of target file in a variable using open systemcall

      if(fdSrcFile==-1) {return 2; }  //if the return value of open systemcall equal -1 (indcating the target file is not correct)
                                    //return error message with value 2

      int fdDestFile = open(argv[2], O_CREAT | O_WRONLY,S_IRUSR ) ; //storing the file descriptor value of destination file in a variable
                                                                    //also change the state of the inode so the owner has read permission

      if(fdDestFile==-1) {return 3; } //if the return value of open systemcall equal -1 (indcating the destination path is not correct)
                                    //return error message with value 3

      char buffer[2];               //an array to store the read chars while looping over the srcFile
      ssize_t charCount;
      
      while((charCount = read(fdSrcFile,buffer,sizeof(buffer))) != 0){

       write(fdDestFile,buffer,charCount);             //write in destiFile what is read from srcFile

      }
      
    return 0;
           
}
