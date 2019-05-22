//MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

//varaibles globales
//entonces a muchas cosas
// hay que agregarles la direccion del archivo.



#define MAXCHAR 900000
    FILE *fp;  //codigo Gabo
    FILE *plantilla; //plantilla de beamer
    FILE *fo; //salida


    //para los histogramas
    int cantidadTokens[7] = {0, 0 , 0 , 0 , 0, 0, 0};
    // cantidades luego se eliminan -solo prueba


    float porcentajeCantidad[7]= {0.0,0.0,0.0,0.0,0.0,0.0, 0.0};
    int totalTokens;
    char direccion[500];


void prepararPorcentajes(){
  int total = 0;
  for (int i  = 0 ;  i< 7 ; i++){
    total = total + cantidadTokens[i];
  }
  for (int j  = 0 ;  j< 7 ; j++){
    porcentajeCantidad[j] =  (((float)cantidadTokens[j] / (float)total) * 100.0);
  }
}


void crearHistogramas(){

  // Histograma
  fprintf(fo, "  \\begin{frame} \\frametitle{Histograma de la cantidad de tokens}  \n \\begin{tikzpicture}  \n \\begin{axis}[legend columns=3, \n   	x tick label style={ \n /pgf/number format/1000 sep=}, \n ylabel=Tokens,\n 	enlargelimits=0.05, \n");
   fprintf(fo, "legend style={at={(0.5,-0.04)}, \n  	anchor=north,legend columns=-1},  \n 	ybar interval=0.7,   \n  ] \n ");
  for (int i = 0 ; i<7; i++){
        fprintf(fo, " \\addplot coordinates {(0,%d) (5,5)}; \n", cantidadTokens[i]);
  }
  fprintf(fo, "  \\legend{Palabras reservadas,Identificadores,Strings, Constantes, Símbolos Especiales, Operadores, Errores Léxicos } \n  \\end{axis} \n \\end{tikzpicture} \n \\end{frame}  \n");

  // Grafico circular
  fprintf(fo, "  \\begin{frame}  \\frametitle{Gráfico circular del porcentaje de uso de tokens } \n  \\begin{tikzpicture}[scale=0.9]  \n  " );
  fprintf(fo, "  \\pie[text=legend]{%.2f / Palabras reservadas: %.2f \\%, %.2f / Identificadores: %.2f \\%, %.2f / Strings: %.2f \\%, %.2f / Constantes: %.2f \\%, %.2f / Símbolos especiales: %.2f \\%, %.2f / Operadores: %.2f \\%, %.2f / Errores Léxicos: %.2f \\%}  \n  \\end{tikzpicture} \n \\end{frame}  \n", porcentajeCantidad[0],porcentajeCantidad[0],porcentajeCantidad[1],porcentajeCantidad[1], porcentajeCantidad[2],porcentajeCantidad[2], porcentajeCantidad[3],porcentajeCantidad[3],porcentajeCantidad[4],porcentajeCantidad[4], porcentajeCantidad[5],porcentajeCantidad[5], porcentajeCantidad[6],porcentajeCantidad[6]);
}


void crearCodeSlides(){
  int lineas = 0 ;
  //Variable para los declares
  char str[MAXCHAR];
  strcpy(str, "");
  char declares [MAXCHAR];
  strcpy(declares, "");
  char formatoSlide [MAXCHAR];
  strcpy(formatoSlide, "");
  while (fgets(str, MAXCHAR, fp) != NULL){
      strcat(declares, str);
      if (lineas == 7 ){
          strcat(formatoSlide, "\\begin{frame}{Análisis de código} \n");
          strcat(formatoSlide, declares);
          strcat(formatoSlide, "\\end{frame}\n");
          lineas = 0;
          memset(declares, 0, sizeof declares);
      }
      lineas++;
  }
  if ((int) sizeof(declares)!=0){
    strcat(formatoSlide, "\\begin{frame}{Análisis de código} \n");
    strcat(formatoSlide, declares);
    strcat(formatoSlide, "\\end{frame}\n");
  }
  fputs(formatoSlide,fo);
}


void ejecutarArchivo(){
  char str[200] = "pdflatex ";
  char str2[200] = "evince -s ";
  getcwd(direccion, sizeof(direccion))  ; //direccion del archivo en cuestion  tambien en la plantilla de nasm
  strcat( direccion,"/output.tex");
  strcat( str,direccion);
  printf("%s\n", str);
  system(str);
  getcwd(direccion, sizeof(direccion))  ; //direccion del archivo en cuestion  tambien en la plantilla de nasm
  strcat( direccion,"/output.pdf");
  strcat( str2,direccion);
  system(str2);
}

void deleteFiles(){
  remove("output.aux");
  remove("output.log");
  remove("output.nav");
  remove("output.out");
  remove("output.snm");
  remove("output.tex");
  remove("FINAL.txt");
  remove("OUTPUT2.txt");
  remove("OUTPUT.txt");
}

int createBeamer(int n[]){
    //Manejo de archivos
        getcwd(direccion, sizeof(direccion))  ; //direccion del archivo en cuestion  tambien en la plantilla de nasm
        strcat( direccion,"/FINAL.txt");
        fp = fopen(direccion, "r");
        plantilla= fopen("/home/gabriel/Music/Lat/plantilla.txt", "r");
        fo = fopen("output.tex","w");
        if(fp == NULL){
            fprintf(stderr,"Error al encontrar el archivo");
            exit(1);
        }
        if(plantilla== NULL){
            fprintf(stderr,"Error al encontrar el archivo");
            exit(1);
        }
        for(int i = 0; i<7;i++){
          cantidadTokens[i] = n[i];
        }

    //Insercion de plantilla
        char lines[MAXCHAR];
        while (fgets(lines, MAXCHAR, plantilla) != NULL){
            fputs(lines,fo);
        }

    //Insercion de codigo
        crearCodeSlides();
        fprintf(fo, "  \\section{Histogramas del análisis}" );
        //funciones del histograma
        prepararPorcentajes();
        crearHistogramas();
        fputs("  \\section{Referencias }\\begin{frame}{Referencias}Levine, J. (2009). \\textit{Flex \\& Bison: Text Processing Tools.} O'Reilly Media, Inc.\\end{frame}\\end{document}",fo);

    //Manejo de archivos again
        fclose(fp);
        fclose(fo);
        fclose(plantilla);

    //Ejecucion del archivo en fullscreen
        ejecutarArchivo();
        deleteFiles();
        return 0;
}
