#ifndef ENCRYPT_HEADER_H
#define ENCRYPT_HEADER_H

#include "file_engine/read_file.c"
#include <openssl/rsa.h>
//#include <openssl/env.h>
#include <openssl/ssl.h>
#include <openssl/pem.h>
#include <crypt.h>
//#include "zlib.h"

	int ret=0;
	RSA *r=NULL;
	BIGNUM *bne=NULL;
	BIO *bne_public=NULL, *bne_private=NULL;
	int bits=2048;
	unsigned long e=RSA_F4;
	char *files[];


void encrypte_file(char
 *argsc[], char crypt_args[]){

	files=file_io(argsc);	
		int arr_length=sizeof(files)/sizeof(char);
		if(files>1){
			//zip file  before encrypting 		

	}
	
}
/*
	this function #key_gen generates two private and public key for encryption 
	using the precision arthemetics and RSA key generator
	@params NULL
	@return void
*/


void key_gen(){
	
	//rsa key generator;
	bne=BN_new();
	ret=BN_set_word(bne,e);
	
		if(ret!=1){
			goto freeall;
		}

	
	r=RSA_new();
	ret=RSA_generate_key_ex(r,bits,bne,NULL);
	
		if(ret!=1){
			goto freeall;
		}
	
	//public key generator 
	bne_public=BIO_new_file("p_key.pem","+w");
	ret=PEM_write_bio_RSAPublicKey(bne_public,r);
	
	//private key generator
	bne_private=BIO_new_file("pr_key.pem","+w");
	ret=PEM_write_bio_RSAPrivateKey(bne_public,r,NULL,NULL,0,NULL,NULL);	
	
		freeall:
	
	BIO_free_all(bne_public);
	BIO_free_all(bne_private);
	RSA_free(r);
	BN_free(bne);
	
	}


#endif
