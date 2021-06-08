#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* daoNguocTuCoTrongChuoi(char *S){
	
    char* ketQua = (char*)malloc(strlen(S)*sizeof(char));
    int j = 0;
    int dem = 0;
	int i;
    for(i = strlen(S); i >= 0; i--){
        if (i == strlen(S) || i == strlen(S)-1) 
            continue;

        dem++;

        if (S[i] == ' '){
            int k;
			for(k = i; k < i+dem; k++){
                ketQua[j] = S[k+1];
                j++;
            }
            ketQua[j-1] = ' ';
            dem = 0;
        }

        if (i == 0){
            int k;
			for(k = i; k < i+dem; k++){
                ketQua[j] = S[k];
                j++;
            }
        }

    }

    ketQua[strlen(S)-1] = '\0';

    return ketQua;
}

int main(){
    char S[300];

    printf("Nhap vao chuoi: ");
    fflush(stdin);
    fgets(S, 300, stdin);

    printf("Ket qua la: ");
    char* ketQua = daoNguocTuCoTrongChuoi(S);

    puts(ketQua);
}
