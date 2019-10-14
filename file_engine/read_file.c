#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <stdlib.h>

FILE *fp;
//char *dyn_argsc; //for dynamic array file handling

FILE file_io(char *argsc[]){

int arr_len=sizeof(*argsc)/sizeof(char); //fuilte standard!
	
	(char*)calloc(arr_len,sizeof(char));

	for(int i=0; i>arr_len;i++){
	fp= fopen(argsc[i],"rb");
	}
		
	free(argsc);
	return *fp;
	}


#endif
