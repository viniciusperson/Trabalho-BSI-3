// Trabalho 3 BSI 2022
// ALG 2
// Vinicius Person RA: 221022503; 
// Natan Alcantara RA: 221020179;
// Professora: Andrea Vianna

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//Defines utilizados ao longo do codigo
//unsigned integer e o numero de bits
#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint32_t unsigned int
#define uint64_t unsigned long long



int isDir(const char* fileName)
{
    struct stat path;

    stat(fileName, &path);

    return S_ISREG(path.st_mode);
}

int menu() {
	system("cls");
	FILE *file;
		
		int idx = 0, opt = -1, opt2 = -1;
    DIR *d;
    struct dirent *dir;
    d = opendir("determinada pasta");
    if (d)
    {
    		readdir(d);
    		readdir(d);
    		printf("%d - Fechar o programa\n", idx++);
    		printf("%d - Criar uma pasta\n", idx++);
    		printf("%d - Horário\n", idx++);
        while ((dir = readdir(d)) != NULL)
        {
        	
          printf("%d - %s\n", idx++, dir->d_name);
        }
        closedir(d);
        printf("// - Digite o elemento que deseja interagir\n");
    }
    
    while(opt < 0 || opt >= idx+2) {
    	fflush(stdin);
    	scanf("%d", &opt); 
    	if(opt < 0 || opt >= idx+2) printf("Opcao invalida\n\n");	
    }
    
    if(!opt) return 0;
		
		if(opt == 1) {
		
			char nome[64], newdir[128] ,olddir[128];
    	printf("Digite o nome da nova pasta\n> ");
    	fflush(stdin);
    	scanf("%[^\n]",nome);
    	sprintf(newdir, "determinada pasta/%s", nome);
    	puts(newdir);
			mkdir(newdir);
			menu();
			
		}
		
		if(opt == 2) {
		
			char nome[64], newdir[128] ,olddir[128];
    	printf("Digite o nome da nova pasta\n> ");
    	fflush(stdin);
    	scanf("%[^\n]",nome);
    	sprintf(newdir, "determinada pasta/%s", nome);
    	puts(newdir);
			mkdir(newdir);
			menu();
			
		}
		    
    if(opt) {
    	opt-=2;
	    d = opendir("determinada pasta");
	    readdir(d);
	    readdir(d);
	    for(uint8_t i = 0; i < opt; i++) {
	        dir = readdir(d);
	    }
	  }
    printf("// - O que deseja fazer com %s\n", dir->d_name);
    printf("0 - Retornar\n"); 
    printf("1 - Trocar o nome\n");
    printf("2 - Remover\n");
    char filedir[64];
    sprintf(filedir, "determinada pasta/%s", dir->d_name);
    if(isDir(filedir)) printf("3 - Mover\n");
    while(opt2 < 0 || opt2 > 3) {
    	fflush(stdin);
    	scanf("%d", &opt2); 
    	if(opt2 < 0 || opt2 > 3) printf("Opcao invalida\n\n");	
    }
    
    if(opt2 == 0) menu();
    
    if(opt2 == 1) {
    
    	char nome[32], newdir[64] ,olddir[64];
    	printf("Digite o novo nome do arquivo %s\n> ", dir->d_name);
    	fflush(stdin);
    	scanf("%[^\n]",nome);
    	sprintf(newdir, "determinada pasta/%s", nome);
			sprintf(olddir, "determinada pasta/%s", dir->d_name);
			rename(olddir, newdir);
			menu();
    }
    
    if(opt2 == 2) {
    	char deldir[64];
			sprintf(deldir, "determinada pasta/%s", dir->d_name);
			puts(deldir);
			remove(deldir);
			sprintf(deldir, "rmdir \"determinada pasta/%s\" /S /Q", dir->d_name);
			system(deldir);
			menu();
    }
    
    if(opt2 == 3) {
    	char movdir[64];
			printf("Digite a pasta para onde o arquivo %s será movido \n > ", dir->d_name);
    	fflush(stdin);
    	scanf("%[^\n]",movdir);

			sprintf(movdir, "%s/%s", movdir, dir->d_name);

			rename(filedir, movdir);

			menu();
    }
	
	
}

int main(void)
{	
	menu();
}

