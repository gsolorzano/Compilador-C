☼
int *a;
void cleanCode(){
getcwd(direccion, sizeof(direccion)) ;
int g;
strcat( direccion,"/OUTPUT.txt")
fileImput = fopen(direccion, "r");
fileOutput = fopen("OUTPUT2.txt","w");

char in_char;
in_char = fgetc(fileImput);
int band = 0;
while (in_char!= EOF && (in_char == '\n')){
in_char = fgetc(fileImput);
}
for ( i = 0; i < count; i++) {
i = 8;
}
while(in_char != EOF){
if(in_char == '\n'){
if(band == 0){
fputc(in_char, fileOutput);
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
 