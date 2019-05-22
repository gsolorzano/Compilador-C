int *a;
void cleanCode(){
    getcwd(direccion, sizeof(direccion)) ;
    strcat( direccion,"/OUTPUT.txt");
    fileImput = fopen(direccion, "r");
    fileOutput = fopen("OUTPUT2.txt","w");

    char in_char;
    in_char = fgetc(fileImput);
    int band = 0;
    while( != EOF && (in_char == '\n')){
        in_char = fgetc(fileImput);
    }
    while(in_char != EOF){
        if(in_char == '\n'){
            if(band == 0){
                fputc(in_char, fileOutput)
                band = 1;
                in_char = fgetc(fileImput);
            }
            else{
                in_char = fgetc(fileImput);
            }
        }
        else{
            band = 0;
            fputc(in_char, fileOutput);
            in_char = fgetc(fileImput);
        }
    }
    return;
}
