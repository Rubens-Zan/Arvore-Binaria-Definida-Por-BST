# Makefile compilacao programa arvore binaria analisadora de expressoes aritmeticas
# Para efetuar a compilação digite make all
# Para remover os arquivos temporários digite make clean
# Para remover os arquivos temporários e o arquivo executável digite make purge

CFLAGS = -Wall -g

MODULOS = biblioteca \
	arvorePrincipal \
	arvoreSecundaria

OBJETOS = busca.o $(addsuffix .o,$(MODULOS)) 

.PHONY : all clean

all : busca

busca : $(OBJETOS)

clean : 
	$(RM) $(OBJETOS)

purge: 
	$(RM) $(OBJETOS) busca
