#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include "structs.h"


int add_last(void **arr, int *len, data_structure *data)
{   
	    int lungime = *len;
	
	    if(*len == 0){
			*arr = malloc(data->header->len + sizeof(head));
			memcpy(*arr,data->header,sizeof(head));
			memcpy(*arr + sizeof(head),data->data,data->header->len);
		}
		else {
			int dimensiune = 0;
			while(lungime){
                 head h;
				 memcpy(&h,*arr + dimensiune,sizeof(head));
				 dimensiune = dimensiune + h.len + sizeof(head);
				 lungime--;
			}
			*arr = realloc(*arr,dimensiune + data->header->len + sizeof(head));
			memcpy(*arr + dimensiune,data->header,sizeof(head));
			memcpy(*arr + dimensiune + sizeof(head),data->data,data->header->len);
		}
		*len = *len + 1;       
		return 0;
}

int add_at(void **arr, int *len, data_structure *data, int index)
{
   if(index < 0)return -1;
   else if(index > *len){
   add_last(arr,len,data);
   }
   else {
	   int x = index - 1,dimensiune1 = 0;
	   while(x >= 0){
           head h;
		   memcpy(&h,*arr + dimensiune1,sizeof(head));
		   dimensiune1 = dimensiune1 + h.len + sizeof(head);
		   x--;
	   }
      int dimensiune2 = dimensiune1;
	  x = *len;
	  while(x != index){
		   head h;
		   memcpy(&h,*arr + dimensiune2,sizeof(head));
		   dimensiune2 =dimensiune2 + h.len + sizeof(head);
		   x--;
	  }
	  
	  *arr = realloc(*arr,dimensiune2 + data->header->len +sizeof(head));
	  memcpy(*arr + dimensiune1 + sizeof(head) + data->header->len,*arr + dimensiune1,dimensiune2 - dimensiune1);
	  memcpy(*arr + dimensiune1,data->header,sizeof(head));
	  memcpy(*arr + dimensiune1 + sizeof(head),data->data,data->header->len);
   }
   (*len)++;
   return 0;
}
void print(void *arr,int len){
	int dimensiune = 0;
	while(len != 0){
		head h;
		memcpy(&h,arr + dimensiune,sizeof(head));
		if(h.type == '1'){
			
			char *dedicator = malloc(h.len);
			char *dedicator1 = malloc(h.len);
			int8_t bancnota1,bancnota2;
			memcpy(dedicator,arr + dimensiune + sizeof(head),h.len);
			
			memcpy(&bancnota1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1,sizeof(int8_t));
			
			memcpy(&bancnota2,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int8_t),sizeof(int8_t));
			int x = strlen(dedicator) + 1 + sizeof(int8_t) * 2;
			memcpy(dedicator1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int8_t) * 2,h.len - x);
			
            printf("Tipul %c\n%s pentru %s\n%d\n%d\n\n",h.type,dedicator,dedicator1,bancnota1,bancnota2);
			
			free(dedicator);
			free(dedicator1);
		}
		else if(h.type == '2'){
			char *dedicator = malloc(h.len + 1);
			char *dedicator1 = malloc(h.len + 1);
			int16_t bancnota1;
			int32_t bancnota2;
			memcpy(dedicator,arr + dimensiune + sizeof(head),h.len);
			memcpy(&bancnota1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1,sizeof(int16_t));
			memcpy(&bancnota2,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int16_t),sizeof(int32_t));
			int x = strlen(dedicator) + 1 + sizeof(int16_t) + sizeof(int32_t);
			memcpy(dedicator1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int16_t) + sizeof(int32_t),h.len - x);
			printf("Tipul %c\n%s pentru %s\n%d\n%d\n\n",h.type,dedicator,dedicator1,bancnota1,bancnota2);
			free(dedicator);
			free(dedicator1);
		}
		else {
			char *dedicator = malloc(h.len + 1);
			char *dedicator1 = malloc(h.len + 1);
			int32_t bancnota1,bancnota2;
			memcpy(dedicator,arr + dimensiune + sizeof(head),h.len);
			memcpy(&bancnota1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1,sizeof(int32_t));
			memcpy(&bancnota2,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int32_t),sizeof(int32_t));
			int x = strlen(dedicator) + 1 + sizeof(int32_t) + sizeof(int32_t);
			memcpy(dedicator1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int32_t) * 2,h.len-x);
			printf("Tipul %c\n%s pentru %s\n%d\n%d\n\n",h.type,dedicator,dedicator1,bancnota1,bancnota2);
			free(dedicator);
			free(dedicator1);
		}
		dimensiune = dimensiune + h.len + sizeof(head);
	
		len --;
	}
}
void printelem(void *arr,int dimensiune)
{
	   head h;
		memcpy(&h,arr + dimensiune,sizeof(head));
       if(h.type == '1'){
			char *dedicator = malloc(h.len);
			char *dedicator1 = malloc(h.len);
			int8_t bancnota1,bancnota2;
			memcpy(dedicator,arr + dimensiune + sizeof(head),h.len);
			
			memcpy(&bancnota1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1,sizeof(int8_t));
			
			memcpy(&bancnota2,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int8_t),sizeof(int8_t));
			int x = strlen(dedicator) + 1 + sizeof(int8_t) * 2;
			memcpy(dedicator1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int8_t) * 2,h.len - x);
			
            printf("Tipul %c\n%s pentru %s\n%d\n%d\n\n",h.type,dedicator,dedicator1,bancnota1,bancnota2);
			
			free(dedicator);
			free(dedicator1);
		}
		else if(h.type == '2'){
			char *dedicator = malloc(h.len + 1);
			char *dedicator1 = malloc(h.len + 1);
			int16_t bancnota1;
			int32_t bancnota2;
			memcpy(dedicator,arr + dimensiune + sizeof(head),h.len);
			memcpy(&bancnota1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1,sizeof(int16_t));
			memcpy(&bancnota2,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int16_t),sizeof(int32_t));
			int x = strlen(dedicator) + 1 + sizeof(int16_t) + sizeof(int32_t);
			memcpy(dedicator1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int16_t) + sizeof(int32_t),h.len - x);
			printf("Tipul %c\n%s pentru %s\n%d\n%d\n\n",h.type,dedicator,dedicator1,bancnota1,bancnota2);
			free(dedicator);
			free(dedicator1);
		}
		else {
			char *dedicator = malloc(h.len + 1);
			char *dedicator1 = malloc(h.len + 1);
			int32_t bancnota1,bancnota2;
			memcpy(dedicator,arr + dimensiune + sizeof(head),h.len);
			memcpy(&bancnota1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1,sizeof(int32_t));
			memcpy(&bancnota2,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int32_t),sizeof(int32_t));
			int x = strlen(dedicator) + 1 + sizeof(int32_t) + sizeof(int32_t);
			memcpy(dedicator1,arr + dimensiune + sizeof(head) + strlen(dedicator) + 1 + sizeof(int32_t) * 2,h.len-x);
			printf("Tipul %c\n%s pentru %s\n%d\n%d\n\n",h.type,dedicator,dedicator1,bancnota1,bancnota2);
			free(dedicator);
			free(dedicator1);
		}
}
void find(void *data_block, int len, int index) 
{
	    int dimensiune = 0;
     if(index > len)return ;
	    if(index < 0)return ;
     for(int i = 0;i < index;i++){
        head h;
		memcpy(&h,data_block + dimensiune,sizeof(head));
        dimensiune = dimensiune + h.len + sizeof(head);
	 }
	 printelem(data_block,dimensiune);

}

int delete_at(void **arr, int *len, int index)
{
         if(index < 0)return -1;
	   int x = index - 1,dimensiune1 = 0;
	   while(x >= 0){
           head h;
		   memcpy(&h,*arr + dimensiune1,sizeof(head));
		   dimensiune1 = dimensiune1 +h.len + sizeof(head);
		   x--;
	   }
           
           int dimensiune3 = 0;
           head h;
		   memcpy(&h,*arr + dimensiune1,sizeof(head));
		   dimensiune3 = h.len + sizeof(head);
		   int dimensiune2 = dimensiune1 + dimensiune3; 
	       x = index + 1;
	       while(x < *len){
		   head h;
		   memcpy(&h,*arr + dimensiune2,sizeof(head));
		   dimensiune2 = dimensiune2 + h.len + sizeof(head);
		   x++;
	  }
	   
	   memcpy(*arr + dimensiune1,*arr + dimensiune1 + dimensiune3,dimensiune2 - dimensiune3 - dimensiune1);
	   *arr = realloc(*arr,dimensiune2 -dimensiune3);
      (*len) = (*len) - 1;
	  return 0;
}
void citeste(char *p,void **arr,int *len2,int index,int cerinta)
{   
	if(p[0] == '1')
	{
		p = strtok(NULL," ");
    char *dedicator = malloc(strlen(p) + 1);
	memcpy(dedicator,p,strlen(p) + 1);
	
	p = strtok(NULL," ");
	int8_t bancnota1 = atoi(p);

	p = strtok(NULL," ");
	int8_t bancnota2 = atoi(p);
	p = strtok(NULL," ");

	if(p[strlen(p) - 1] =='\n')p[strlen(p) - 1] = '\0';
	char *dedicator1 = malloc(strlen(p) + 1);
	memcpy(dedicator1,p,strlen(p) + 1);

	data_structure *data1 = malloc(sizeof(data_structure));
	if(!data1)return ;
	data1->header = malloc(sizeof(head));
	if(!data1->header)return ;
	data1->header->type = '1';
    data1->header->len = strlen(dedicator) + 1 + strlen(dedicator1) + 1 +sizeof(int8_t) * 2;
	
	data1->data = malloc(data1->header->len);
	char *datum = malloc(data1->header->len);
	if(!datum)return ;
	memcpy(datum, dedicator,strlen(dedicator) + 1);
	memcpy(datum + strlen(dedicator) + 1, &bancnota1,sizeof(int8_t));	
	memcpy(datum + strlen(dedicator) + 1 + sizeof(int8_t),&bancnota2 ,sizeof(int8_t));
	memcpy(datum + strlen(dedicator) + 1 + sizeof(int8_t) * 2, dedicator1, strlen(dedicator1) + 1);
    memcpy(data1->data,datum,data1->header->len);
	if(cerinta == 0)add_last(arr,len2,data1);
	else add_at(arr,len2,data1,index);
	
	 free(datum);
    free(dedicator);
	free(dedicator1);
	free(data1->header);
	free(data1->data);
	free(data1);
	}
	else if(p[0] == '2')
	{
		p = strtok(NULL," ");
	
		char *dedicator = malloc(strlen(p) + 1);
	memcpy(dedicator,p,strlen(p) + 1);
	
	p = strtok(NULL," ");
	int16_t bancnota1 = atoi(p);

	p = strtok(NULL," ");
	int32_t bancnota2 = atoi(p);
	p = strtok(NULL," ");
	
	if(p[strlen(p) - 1] =='\n')p[strlen(p) - 1] = '\0';
	char *dedicator1 = malloc(strlen(p) + 1);
	memcpy(dedicator1,p,strlen(p) + 1);
	
	data_structure *data1 = malloc(sizeof(data_structure));
	if(!data1)return ;
	data1->header = malloc(sizeof(head));
	if(!data1->header)return ;
	data1->header->type = '2';
    data1->header->len = strlen(dedicator) + 1 + strlen(dedicator1) + 1 +sizeof(int16_t) + sizeof(int32_t);
	data1->data = malloc(data1->header->len);
	char *datum = malloc(data1->header->len);
	if(!datum)return ;
	memcpy(datum, dedicator,strlen(dedicator) + 1);
	memcpy(datum + strlen(dedicator) + 1, &bancnota1,sizeof(int16_t));	
	memcpy(datum + strlen(dedicator) + 1 + sizeof(int16_t),&bancnota2 ,sizeof(int32_t));
	memcpy(datum + strlen(dedicator) + 1 + sizeof(int16_t) + sizeof(int32_t), dedicator1, strlen(dedicator1) + 1);
    memcpy(data1->data,datum,data1->header->len);
	if(cerinta == 0)add_last(arr,len2,data1);
	else add_at(arr,len2,data1,index);
	
	 free(datum);
    free(dedicator);
	free(dedicator1);
	free(data1->header);
	free(data1->data);
	free(data1);
	}
	else
	{
		p = strtok(NULL," ");
    char *dedicator = malloc(strlen(p) + 1);
	memcpy(dedicator,p,strlen(p) + 1);
	
	p = strtok(NULL," ");
	int32_t bancnota1 = atoi(p);

	p = strtok(NULL," ");
	int32_t bancnota2 = atoi(p);
	p = strtok(NULL," ");
	
	if(p[strlen(p) - 1] =='\n')p[strlen(p) - 1] = '\0';
	char *dedicator1 = malloc(strlen(p) + 1);
	memcpy(dedicator1,p,strlen(p) + 1);

	data_structure *data1 = malloc(sizeof(data_structure));
	if(!data1)return ;
	data1->header = malloc(sizeof(head));
	if(!data1->header)return ;
	data1->header->type = '3';
    data1->header->len = strlen(dedicator) + 1 + strlen(dedicator1) + 1 +sizeof(int32_t) * 2;
	data1->data = malloc(data1->header->len);
	char *datum = malloc(data1->header->len);
	if(!datum)return ;
	memcpy(datum, dedicator,strlen(dedicator) + 1);
	memcpy(datum + strlen(dedicator) + 1, &bancnota1,sizeof(int32_t));	
	memcpy(datum + strlen(dedicator) + 1 + sizeof(int32_t),&bancnota2 ,sizeof(int32_t));
	memcpy(datum + strlen(dedicator) + 1 + sizeof(int32_t) * 2, dedicator1, strlen(dedicator1) + 1);
    memcpy(data1->data,datum,data1->header->len);
	
	if(cerinta == 0)add_last(arr,len2,data1);
	else add_at(arr,len2,data1,index);
	
	 free(datum);
    free(dedicator);
	free(dedicator1);
	free(data1->header);
	free(data1->data);
	free(data1);
	}
}

int main(int argc,char *input[]) {
	//the vector of bytes u have to work with
	//good luck :)
	void *arr = NULL;
	int len2 = 0;
	size_t len1 = 0;
	// FILE *f = fopen("INPUTS/test6","rt");
	char *line = NULL;
	 while(getline(&line,&len1,stdin) != -1){
		 char *p = NULL;
        p = strtok(line," ");
		if(p[strlen(p) - 1] == '\n')p[strlen(p) - 1] = '\0';
		  if(strcmp(p,"insert") == 0){
		 	          p = strtok(NULL," ");
					   int cerinta = 0,index = 0;
					  citeste(p,&arr,&len2,index,cerinta);
					 
	 	 		 }
		 else if(strcmp(p,"insert_at") == 0){
                       p = strtok(NULL," ");
					   int cerinta = 1,index = p[0] - '0';
					   p = strtok(NULL," ");
					   citeste(p,&arr,&len2,index,cerinta);
					   
		 	
		 }
		 if(strcmp(p,"find") == 0){
              p = strtok(NULL," ");
			  int x = atoi(p);
			  find(arr,len2,x);
		 }
		 if(strcmp(p,"delete_at") == 0){
               p = strtok(NULL," ");
			   int x = atoi(p);
			 
			   delete_at(&arr,&len2,x);
		 } 
	     else if(strcmp(p,"print") == 0){
			 print(arr,len2);
		 }
		 else if(strcmp(p,"exit") == 0)free(arr);
	 }
	free(line);
	// fclose(f);
	return 0;
}
