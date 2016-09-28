/*
 * convertNums.hpp
 *
 *  Created on: Sep 19, 2016
 *      Author: otto
 */

#ifndef CONVERTNUMS_HPP_
#define CONVERTNUMS_HPP_
#include <string>
using std::string;

class ConvertNums {
  public:
    ConvertNums(){};
    int convert_toArabic(string& romanNumeral_String);
    int getRomanEquivalentValue(char  romanString);

  private:
    int VERIFY_ifFour(string & String_toVerify);
    int VERIFY_ifTwo(string & String_toVerify);
    int VERIFY_Subtraction(string & String_toVerify);
};

/***************************************************************************
* Função: Converte numerais romanos em arabicos
* Descrição
*   Recebe uma string de tamanho maximo 30 characteres(29 numerais)
*   e retorna um valor inteiro equivalente.
*   Função cliente de todas as outras.
*   Verifica regras de formação de numerais romanos.
*   De acordo com tais regras, soma ou subtrai cada valor equivalente.
*   ao caracter corrente. Executa do fim para o inicio da string.
*
* Parâmetros
*   romanNumeral_String - String a ser convertida.
* Valor retornado
*   Total do somatorio(ou subtracao) de todos os numerais romanos.
* Assertiva de entrada
*   romanNumeral_String != NULL
*   dimensao( romanNumeral_String ) < 30
* Assertiva de saida
*
***************************************************************************/
int ConvertNums::convert_toArabic(string & romanNumeral_String);

/***************************************************************************
* Função: Converter long para ASCII
* Descrição
*
 Converte um inteiro long para um string ASCII.
*
 O string resultado estará alinhado à esquerda no buffer de dimASCII
*
 caracteres fornecido
* Parâmetros
*
 dimASCII - número máximo de caracteres do string inclusive
*
 o caractere zero terminal.
*
 pNumASCII - ponteiro para o espaço que receberá o string.
*
 Será truncado à direita caso o string convertido
*
 exceda a dimensão limite. O primeiro caractere
*
 será ‘-‘ se e somente se número < 0
*
 Numero
 - inteiro a ser convertido para string
* Valor retornado
*
 veja as declarações das condições de retorno
* Assertiva de entrada
*
 pNumASCII != NULL
*
 dimensao( *pNumASCII ) >= dimASCII
*
 dimASCII >= max( 3 , 2 + log10( abs( Numero ))
 que tal 12?
***************************************************************************/
int ConvertNums::getRomanEquivalentValue(char  romanString);

#endif /* CONVERTNUMS_HPP_ */
